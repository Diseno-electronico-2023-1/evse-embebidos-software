TARGET       = colorlight_i5
TOP          = cain_test
GATE_DIR     = build/gateware
SOFT_DIR     = build/software
ZEPHYR_DIR   = /home/jlopezmol/zephyr/zephyrproject/
LITEX_DIR    = /home/jlopezmol/litex
#RTL_CPU_DIR = ${LITEX_DIR}/pythondata-cpu-vexriscv/pythondata_cpu_vexriscv/verilog
RTL_CPU_DIR  = ${LITEX_DIR}/pythondata-cpu-lm32/pythondata_cpu_lm32/verilog/rtl/
WORK_DIR     = /home/jlopezmol/embebidos/server/
SERIAL       = /dev/ttyACM0

SERIAL?=/dev/ttyUSB0

all: gateware firmware

gateware:
	./base.py

firmware: ${SOFT_DIR}/common.mak
	$(MAKE) -C firmware/ -f Makefile all

overlay: 
	${LITEX_DIR}/litex/litex/tools/litex_json2dts_zephyr.py --dts overlay.dts --config overlay.config csr.json
app_zephyr:
	west build -b litex_vexriscv ${WORK_DIR}http_server/ -DDTC_OVERLAY_FILE=${WORK_DIR}overlay.dts 	

configure:
	sudo openFPGALoader -b colorlight-i5 -m ${GATE_DIR}/${TARGET}.bit 

load_zephyr_app: 
	litex_term ${SERIAL} --kernel ${WORK_DIR}build/zephyr/zephyr.bin
	
litex_term: firmware
	litex_term ${SERIAL} --kernel firmware/firmware.bin

${TARGET}.svg: 
	#yosys -p "prep -top ${TOP}; write_json ${GATE_DIR}/${TARGET}_LOGIC_svg.json" ${GATE_DIR}/${TOP}.v ${RTL_CPU_DIR}/VexRiscv.v   #TOP_LEVEL_DIAGRAM
	yosys -p "prep -top ${TOP}; write_json ${GATE_DIR}/${TARGET}_LOGIC_svg.json" ${GATE_DIR}/${TOP}.v ${RTL_CPU_DIR}/lm32_top.v
	netlistsvg ${GATE_DIR}/${TARGET}.json -o ${TARGET}.svg  #--skin default.svg
	#yosys -p "prep -top ${TOP} -flatten; write_json ${GATE_DIR}/${TARGET}_LOGIC_svg.json" ${GATE_DIR}/${TOP}.v ${RTL_CPU_DIR}/VexRiscv.v    #TOP_LEVEL_DIAGRAM
	#netlistsvg ${GATE_DIR}/${TARGET}_LOGIC_svg.json -o ${TARGET}_LOGIC.svg  #--skin default.svg	

gateware-clean:
	rm -f ${GATE_DIR}/*.svf ${GATE_DIR}/*.bit ${GATE_DIR}/*.config ${GATE_DIR}/*.json ${GATE_DIR}/*.ys *svg

firmware-clean:
	make -C firmware -f Makefile clean
	
zephyr-clean:
	rm -rf build __pycache__ overlay.* csr.* *.json 

clean: firmware-clean gateware-clean

.PHONY: clean

# conda activate fpga
# source /home/jlopezmol/zephyr/zephyrproject/zephyr/zephyr-env.sh



