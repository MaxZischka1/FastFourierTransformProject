MODULE=TopLevel
SRCS = $(MODULE).sv inputBridge.sv testEEPROM.sv BRAM.sv pingPongU.sv

.PHONY:sim
sim: waveform.vcd

.PHONY: verilate
verilate: .stamp.verilate

.PHONY: build
build: obj_dir/VTopLevel

.PHONY: waves
waves: waveform.vcd
	@echo
	@echo "## WAVES ##"
	gtkwave waveform.vcd

waveform.vcd: ./obj_dir/V$(MODULE)
	@echo
	@echo "##SIMULATE##"
	@./obj_dir/V$(MODULE)

./obj_dir/V$(MODULE): .stamp.verilate
	@echo
	@echo "## BUILDSIM ##"
	@make -C obj_dir -f V$(MODULE).mk V$(MODULE)

.stamp.verilate: $(SRCS) tb_$(MODULE).cpp
	@echo
	@echo "## VERILATING ##"
	verilator -Wall --trace -cc $(SRCS) --top-module $(MODULE) --exe tb_$(MODULE).cpp -CFLAGS "-std=c++17"
	

.PHONY:lint
lint: $(SRCS)
	verilator --lint-only $(SRCS)

.PHONY: clean
clean:
	rm -rf .stamp.*;
	rm -rf ./obj_dir
	rm -rf waveform.vcd