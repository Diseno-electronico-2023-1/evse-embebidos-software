TARGET       = colorlight_i5
TOP          = evse-embebidos
GATE_DIR     = build/gateware
SOFT_DIR     = build/software
LITEX_DIR    = /home/leodtr/Programs/litex
RTL_CPU_DIR  = ${LITEX_DIR}/pythondata-cpu-lm32/pythondata_cpu_lm32/verilog/rtl/
ZEPHYR_DIR   = /home/leodtr/Programs/zephyrproject/
WORK_DIR     = /home/leodtr/Embebidos/evse-embebidos-software/
SERIAL       = /dev/ttyACM0

all: 
	gateware firmware

gateware:
	./base.py

firmware: ${SOFT_DIR}/common.mak
	$(MAKE) -C firmware/ -f Makefile all

overlay: 
	${LITEX_DIR}/litex/litex/tools/litex_json2dts_zephyr.py --dts overlay.dts --config overlay.config csr.json
	
app_zephyr_pantalla:
	west build -b litex_vexriscv ${WORK_DIR}pantalla/ -DSHIELD=ssd1306_128x64 -DDTC_OVERLAY_FILE=${WORK_DIR}overlay.dts
	
configure:
	sudo openFPGALoader -b colorlight-i5 -m ${GATE_DIR}/${TARGET}.bit 

load_zephyr_app:
	litex_term ${SERIAL} --kernel ${WORK_DIR}build/zephyr/zephyr.bin

	
litex_term: 
	litex_term ${SERIAL} --kernel hello_world/hello_world.bin

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
	rm -rf build/zephyr build/CMakeFiles build/CMakeCache.txt 

clean: firmware-clean gateware-clean


# conda activate fpga
# source /home/leodtr/Programs/zephyrproject/zephyr/zephyr-env.sh 



