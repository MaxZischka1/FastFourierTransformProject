MODULE=TopLevel
SRCS = $(MODULE).sv inputBridge.sv testEEPROM.sv BRAM.sv pingPongU.sv BFU.sv

.PHONY:sim
sim: waveformTopLevel.vcd

.PHONY: verilate
verilate: .stamp.verilate

.PHONY: build
build: obj_dir_TL/VTopLevel

.PHONY: waves
waves: waveformTopLevel.vcd
	@echo
	@echo "## WAVES ##"
	gtkwave waveformTopLevel.vcd

waveformTopLevel.vcd: ./obj_dir_TL/V$(MODULE)
	@echo
	@echo "##SIMULATE##"
	@./obj_dir_TL/V$(MODULE)

./obj_dir_TL/V$(MODULE): .stamp.verilate
	@echo
	@echo "## BUILDSIM ##"
	@$(MAKE) -C obj_dir_TL -f V$(MODULE).mk V$(MODULE)

.stamp.verilate: $(SRCS) tb_$(MODULE).cpp
	@echo
	@echo "## VERILATING ##"
	verilator -Wall --trace -cc $(SRCS) --top-module $(MODULE) --exe tb_$(MODULE).cpp --Mdir obj_dir_TL -CFLAGS "-std=c++17"
	@touch .stamp.verilate
	

.PHONY:lint
lint: $(SRCS)
	verilator --lint