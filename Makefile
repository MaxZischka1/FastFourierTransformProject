MODULE=TopLevel
SRCS = $(MODULE).sv MUX2.sv SDFCell.sv dataAdder.sv DelayLine.sv SBM16.sv SDFCell0.sv Cell1BFU.sv 
ICE40_CELLS = /opt/homebrew/share/yosys/ice40/cells_sim.v
# UNDRIVEN: allow module outputs/signals that are not driven yet
WARN_FLAGS = -Wall -Wno-UNDRIVEN -Wno-PINCONNECTEMPTY -Wno-UNUSEDSIGNAL -Wno-EOFNEWLINE


.PHONY:sim
sim: waveform_TopLevel.vcd

.PHONY: verilate
verilate: .stamp.verilate

.PHONY: build
build: obj_dir_TopLevel/VTopLevel

.PHONY: waves
waves_TopLevel: waveform_TopLevel.vcd
	@echo
	@echo "## WAVES ##"
	gtkwave waveform_TopLevel.vcd

sim_TopLevel: waveform_TopLevel.vcd

waveform_TopLevel.vcd: ./obj_dir_TopLevel/VTopLevel
	@./obj_dir_TopLevel/VTopLevel

./obj_dir_TopLevel/VTopLevel: .stamp.verilate_TopLevel
	@make -C obj_dir_TopLevel -f VTopLevel.mk VTopLevel

.stamp.verilate_TopLevel: $(SRCS) tb_TopLevel.cpp
	verilator $(WARN_FLAGS) -Wno-UNUSED --trace -cc $(SRCS) --top-module TopLevel --exe tb_TopLevel.cpp verilatorTB.cpp --Mdir obj_dir_TopLevel -CFLAGS "-DVERILATOR -std=c++17"
	@touch .stamp.verilate_TopLevel
	

.PHONY:lint
lint: $(SRCS)
	verilator --lint-only -Wall -Wno-EOFNEWLINE -sv $(SRCS) --top-module TopLevel

.PHONY: clean
clean:
	rm -rf .stamp.*;
	rm -rf ./obj_dir_TL
	rm -rf ./obj_dir_bram
	rm -rf waveform_TopLevel.vcd
	rm -rf waveform_bram.vcd
	rm -f top.json top.asc synth.log pnr.log pnr.json report.json


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
	verilator $(WARN_FLAGS) --trace -cc BRAM.sv --top-module BRAM --exe tb_BRAM.cpp verilatorTB.cpp --Mdir obj_dir_bram -CFLAGS "-std=c++17"
	@touch .stamp.verilate_bram

waves_SBM16: waveform_SBM16.vcd
	@echo
	@echo "## WAVES ##"
	gtkwave waveform_SBM16.vcd

sim_SBM16: waveform_SBM16.vcd

waveform_SBM16.vcd: ./obj_dir_SBM16/VSBM16
	@./obj_dir_SBM16/VSBM16

./obj_dir_SBM16/VSBM16: .stamp.verilate_SBM16
	@make -C obj_dir_SBM16 -f VSBM16.mk VSBM16

.stamp.verilate_SBM16: SBM16.sv tb_SBM16.cpp
	verilator $(WARN_FLAGS) --trace -cc SBM16.sv --top-module SBM16 --exe tb_SBM16.cpp verilatorTB.cpp --Mdir obj_dir_SBM16 -CFLAGS "-DVERILATOR -std=c++17"
	@touch .stamp.verilate_SBM16

waves_SDFCell: waveform_SDFCell.vcd
	@echo
	@echo "## WAVES ##"
	gtkwave waveform_SDFCell.vcd

sim_SDFCell: waveform_SDFCell.vcd

waveform_SDFCell.vcd: ./obj_dir_SDFCell/VSDFCell
	@./obj_dir_SDFCell/VSDFCell

./obj_dir_SDFCell/VSDFCell: .stamp.verilate_SDFCell
	@make -C obj_dir_SDFCell -f VSDFCell.mk VSDFCell

.stamp.verilate_SDFCell: $(SRCS) tb_SDFCell.cpp
	verilator $(WARN_FLAGS) -Wno-UNUSED --trace -cc $(SRCS) --top-module SDFCell --exe tb_SDFCell.cpp verilatorTB.cpp --Mdir obj_dir_SDFCell -CFLAGS "-DVERILATOR -std=c++17"
	@touch .stamp.verilate_SDFCell

# ---------------- Synthesis / place & route / reports ----------------
# DEVICE/PACKAGE pick the iCE40 part, FREQ is the clock target nextpnr reports against.
# Set PCF=pins.pcf once pin constraints exist; until then IO is left unconstrained.
DEVICE  = up5k
PACKAGE = sg48
FREQ    = 24
PCF     =
PCF_ARG = $(if $(PCF),--pcf $(PCF),--pcf-allow-unconstrained)


yosys_sta:
	yosys -p "read_verilog -sv $(SRCS); synth_ice40 -top top -abc9 -device u; sta"
yosys_synthesize: top.json

top.json: $(SRCS)
	yosys -l synth.log -p "read_verilog -sv $(SRCS); synth_ice40 -top top -json top.json"

nextpnr: top.asc

top.asc: top.json
	nextpnr-ice40 --$(DEVICE) --package $(PACKAGE) --json top.json --asc top.asc \
		--freq $(FREQ) $(PCF_ARG) --report report.json -l pnr.log

.PHONY: lint_top
lint_top: $(SRCS)
	verilator --lint-only $(WARN_FLAGS) -Wno-DECLFILENAME -Wno-CASEINCOMPLETE -sv $(SRCS) --top-module top

.PHONY: report_top
report_top: top.asc
	@echo
	@echo "## UTILISATION ##"
	@grep -A16 "Device utilisation" pnr.log
	@echo
	@echo "## TIMING ##"
	@grep "Max frequency" pnr.log | tail -2