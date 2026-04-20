MODULE=TopLevel
SRCS = $(MODULE).sv inputBridge.sv testEEPROM.sv BRAM.sv PPU.sv BFU.sv

.PHONY:sim
sim: waveform_TopLevel.vcd

.PHONY: verilate
verilate: .stamp.verilate

.PHONY: build
build: obj_dir_TL/VTopLevel

.PHONY: waves
waves: waveform_TopLevel.vcd
	@echo
	@echo "## WAVES ##"
	gtkwave waveform_TopLevel.vcd

waveform_TopLevel.vcd: ./obj_dir_TL/V$(MODULE)
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
	verilator -Wall --trace -cc $(SRCS) --top-module $(MODULE) --exe tb_$(MODULE).cpp verilatorTB.cpp --Mdir obj_dir_TL -CFLAGS "-std=c++17"
	@touch .stamp.verilate
	

.PHONY:lint
lint: $(SRCS)
	verilator --lint-only $(SRCS)

.PHONY: clean
clean:
	rm -rf .stamp.*;
	rm -rf ./obj_dir_TL
	rm -rf ./obj_dir_bram
	rm -rf ./obj_dir_PPU
	rm -rf waveform_TopLevel.vcd
	rm -rf waveform_bram.vcd
	rm -rf waveform_PPU.vcd


waves_bram: waveform_bram.vcd
	@echo
	@echo "## WAVES ##"
	gtkwave waveform_bram.vcd

sim_bram: waveform_bram.vcd

waveform_bram.vcd: ./obj_dir_bram/VBRAM
	@./obj_dir_bram/VBRAM

./obj_dir_bram/VBRAM: .stamp.verilate_bram
	@make -C obj_dir_bram -f VBRAM.mk VBRAM

.stamp.verilate_bram: BRAM.sv tb_BRAM.cpp
	verilator -Wall --trace -cc BRAM.sv --top-module BRAM --exe tb_BRAM.cpp verilatorTB.cpp --Mdir obj_dir_bram -CFLAGS "-std=c++17"
	@touch .stamp.verilate_bram

waves_PPU: waveform_PPU.vcd
	@echo
	@echo "## WAVES ##"
	gtkwave waveform_PPU.vcd

sim_PPU: waveform_PPU.vcd

waveform_PPU.vcd: ./obj_dir_PPU/VPPU
	@./obj_dir_PPU/VPPU

./obj_dir_PPU/VPPU: .stamp.verilate_PPU
	@make -C obj_dir_PPU -f VPPU.mk VPPU

.stamp.verilate_PPU: PPU.sv tb_PPU.cpp
	verilator -Wall --trace -cc PPU.sv --top-module PPU --exe tb_PPU.cpp verilatorTB.cpp --Mdir obj_dir_PPU -CFLAGS "-std=c++17"
	@touch .stamp.verilate_PPU

waves_BFU: waveform_BFU.vcd
	@echo
	@echo "## WAVES ##"
	gtkwave waveform_BFU.vcd

sim_BFU: waveform_BFU.vcd

waveform_BFU.vcd: ./obj_dir_BFU/VBFU
	@./obj_dir_BFU/VBFU

./obj_dir_BFU/VBFU: .stamp.verilate_BFU
	@make -C obj_dir_BFU -f VBFU.mk VBFU

.stamp.verilate_BFU: BFU.sv tb_BFU.cpp
	verilator -Wall --trace -cc BFU.sv --top-module BFU --exe tb_BFU.cpp verilatorTB.cpp --Mdir obj_dir_BFU -CFLAGS "-std=c++17"
	@touch .stamp.verilate_BFU

