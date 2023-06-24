#!/usr/bin/env python3
import os
import argparse
import sys
import subprocess
from migen import *
from litex.build.generic_platform import IOStandard, Subsignal, Pins
from migen.genlib.resetsync import AsyncResetSynchronizer
from litex.build.io import DDROutput
from litex_boards.platforms import colorlight_i5
from litex.build.lattice.trellis import trellis_args, trellis_argdict
from litex.soc.cores.clock import *
from litex.soc.integration.soc_core import *
from litex.soc.integration.builder import *
from litedram.modules import M12L64322A # Compatible with EM638325-6H.
from litedram.phy import GENSDRPHY, HalfRateGENSDRPHY
from litespi.modules import GD25Q16
from litex.soc.cores.gpio import GPIOTristate
from litespi.opcodes import SpiNorFlashOpCodes as Codes
from liteeth.phy.ecp5rgmii import LiteEthPHYRGMII
from litex.soc.cores.bitbang import I2CMaster
from litex.soc.cores.spi import SPIMaster
from ios import Led
# IOs ------------------------------------------------------------------------
_serial = [
    ("serial", 0,
        Subsignal("tx", Pins("J17")),  # J1.1
        Subsignal("rx", Pins("H18")),  # J1.2
        IOStandard("LVCMOS33")
     )
]

_leds = [
    ("user_led", 0, Pins("U16"), IOStandard("LVCMOS33")),  # LED en la placa
    ("user_led", 1, Pins("F3"), IOStandard("LVCMOS33")),  # LED externo
]

_i2c = [("i2c", 0,
            Subsignal("sda",   Pins("J20")),
            Subsignal("scl",   Pins("G20")),
            IOStandard("LVCMOS33")
        )
]

""" _spi = [("spi", 0,
            Subsignal("cs_n", Pins("G3")),
            Subsignal("clk",  Pins("F2")),
            Subsignal("mosi", Pins("H4")),
            Subsignal("miso", Pins("F1")),
            IOStandard("LVCMOS33")
        )
] """

_gpio =   [
    ("user_gpio", 0, Pins("K20"), IOStandard("LVCMOS33")),
    ("user_gpio", 1, Pins("L18"), IOStandard("LVCMOS33")),
    ("user_gpio", 2, Pins("L20"), IOStandard("LVCMOS33")),
    ("user_gpio", 3, Pins("M18"), IOStandard("LVCMOS33")),
]
        
# BaseSoC -----------------------------------------------------------------------------------------
class _CRG(Module):
    def __init__(self, platform, sys_clk_freq, use_internal_osc=False, with_usb_pll=False, with_rst=True, sdram_rate="1:1"):
        self.rst    = Signal()
        self.clock_domains.cd_sys      = ClockDomain()
        self.clock_domains.cd_sys2x    = ClockDomain()
        self.clock_domains.cd_sys2x_ps = ClockDomain()
        clk = platform.request("clk25")
        clk_freq = 25e6
        rst_n = platform.request("cpu_reset_n", 0)
        # PLL
        self.submodules.pll = pll = ECP5PLL()
        self.comb += pll.reset.eq(~rst_n | self.rst)
        pll.register_clkin(clk, clk_freq)
        pll.create_clkout(self.cd_sys,    sys_clk_freq)
        pll.create_clkout(self.cd_sys2x,    2*sys_clk_freq)
        pll.create_clkout(self.cd_sys2x_ps, 2*sys_clk_freq, phase=180) # Idealy 90° but needs to be increased.
        # SDRAM clock
        sdram_clk = ClockSignal("sys2x_ps")
        self.specials += DDROutput(1, 0, platform.request("sdram_clock"), sdram_clk)
        
# BaseSoC --------------------------------------------------------------------
class BaseSoC(SoCCore):
    def __init__(self):
        SoCCore.mem_map = {
            "rom":          0x00000000,
            "sram":         0x10000000,
            "main_ram":     0x40000000,
            "csr":          0x82000000,
        }
        platform = colorlight_i5.Platform()
        sys_clk_freq = int(100e6)
        platform.add_extension(_serial)
        platform.add_extension(_leds)
        platform.add_extension(_i2c)
        # platform.add_extension(_spi)
        platform.add_extension(_gpio)
        
        # SoC with CPU
        SoCCore.__init__(
            self, platform,
            cpu_type                 = "vexriscv",
            clk_freq                 = sys_clk_freq,
            ident                    = "LiteX CPU cain_test", ident_version=True,
            integrated_rom_size      = 0xB000,
            integrated_sram_size     = 0x2000,
            timer_uptime             = True)
        self.submodules.crg = _CRG(
            platform         = platform, 
            sys_clk_freq     = sys_clk_freq,
            use_internal_osc = False,
            with_usb_pll     = False,
            sdram_rate       = "1:1"
        )
        
        # SDR SDRAM
        self.sdrphy = GENSDRPHY(platform.request("sdram"))
        self.add_sdram("sdram",
            phy           = self.sdrphy,
            module        = M12L64322A(sys_clk_freq,  "1:2"),
            origin        = self.mem_map["main_ram"],
            l2_cache_size = 8192,
        )
        
        # Ethernet
        self.ethphy = LiteEthPHYRGMII(
            clock_pads = self.platform.request("eth_clocks", 0),
            pads       = self.platform.request("eth", 0),
            tx_delay = 0)
        self.add_ethernet(phy=self.ethphy)
        
        # I2C
        self.i2c0 = I2CMaster(pads=platform.request("i2c"))
        
        """ # SPI
        self.submodules.spi = SPIMaster(platform.request("spi", 0), 8, self.sys_clk_freq, 8e6)
        self.spi.add_clk_divider()
        self.add_csr("spi") """

        # Led
        user_leds = Cat(*[platform.request("user_led", i) for i in range(2)])
        self.submodules.leds = Led(user_leds)
        self.add_spi_flash(mode="1x", module=GD25Q16(Codes.READ_1_1_1), with_master=True) 
        self.add_csr("leds")
        
        # GPIO
        self.user_gpio = GPIOTristate(
            pads     = [platform.request("user_gpio",i) for i in range(4)],
            with_irq = self.irq.enabled)
        
# Build -----------------------------------------------------------------------
soc = BaseSoC()
builder = Builder(soc, output_dir="build", csr_csv="csr.csv", csr_svd="csr.svd", csr_json="csr.json")
builder.build()

#https://github.com/litex-hub/litespi/issues/52


















