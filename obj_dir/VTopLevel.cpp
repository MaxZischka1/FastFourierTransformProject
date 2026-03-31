// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VTopLevel__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VTopLevel::VTopLevel(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VTopLevel__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , startSig{vlSymsp->TOP.startSig}
    , ram1Output{vlSymsp->TOP.ram1Output}
    , rdata1REO{vlSymsp->TOP.rdata1REO}
    , rdata1IMO{vlSymsp->TOP.rdata1IMO}
    , rdata2REO{vlSymsp->TOP.rdata2REO}
    , rdata2IMO{vlSymsp->TOP.rdata2IMO}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VTopLevel::VTopLevel(const char* _vcname__)
    : VTopLevel(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VTopLevel::~VTopLevel() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VTopLevel___024root___eval_debug_assertions(VTopLevel___024root* vlSelf);
#endif  // VL_DEBUG
void VTopLevel___024root___eval_static(VTopLevel___024root* vlSelf);
void VTopLevel___024root___eval_initial(VTopLevel___024root* vlSelf);
void VTopLevel___024root___eval_settle(VTopLevel___024root* vlSelf);
void VTopLevel___024root___eval(VTopLevel___024root* vlSelf);

void VTopLevel::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VTopLevel::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VTopLevel___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VTopLevel___024root___eval_static(&(vlSymsp->TOP));
        VTopLevel___024root___eval_initial(&(vlSymsp->TOP));
        VTopLevel___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VTopLevel___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VTopLevel::eventsPending() { return false; }

uint64_t VTopLevel::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VTopLevel::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VTopLevel___024root___eval_final(VTopLevel___024root* vlSelf);

VL_ATTR_COLD void VTopLevel::final() {
    VTopLevel___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VTopLevel::hierName() const { return vlSymsp->name(); }
const char* VTopLevel::modelName() const { return "VTopLevel"; }
unsigned VTopLevel::threads() const { return 1; }
void VTopLevel::prepareClone() const { contextp()->prepareClone(); }
void VTopLevel::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VTopLevel::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VTopLevel___024root__trace_decl_types(VerilatedVcd* tracep);

void VTopLevel___024root__trace_init_top(VTopLevel___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VTopLevel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTopLevel___024root*>(voidSelf);
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    VTopLevel___024root__trace_decl_types(tracep);
    VTopLevel___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VTopLevel___024root__trace_register(VTopLevel___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VTopLevel::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VTopLevel::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VTopLevel___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
