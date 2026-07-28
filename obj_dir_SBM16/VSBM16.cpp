// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VSBM16__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VSBM16::VSBM16(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VSBM16__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , d1InRE{vlSymsp->TOP.d1InRE}
    , d1InIM{vlSymsp->TOP.d1InIM}
    , WInRE{vlSymsp->TOP.WInRE}
    , WInIM{vlSymsp->TOP.WInIM}
    , d2InRE{vlSymsp->TOP.d2InRE}
    , d2InIM{vlSymsp->TOP.d2InIM}
    , dataOutRE{vlSymsp->TOP.dataOutRE}
    , dataOutIM{vlSymsp->TOP.dataOutIM}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VSBM16::VSBM16(const char* _vcname__)
    : VSBM16(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VSBM16::~VSBM16() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VSBM16___024root___eval_debug_assertions(VSBM16___024root* vlSelf);
#endif  // VL_DEBUG
void VSBM16___024root___eval_static(VSBM16___024root* vlSelf);
void VSBM16___024root___eval_initial(VSBM16___024root* vlSelf);
void VSBM16___024root___eval_settle(VSBM16___024root* vlSelf);
void VSBM16___024root___eval(VSBM16___024root* vlSelf);

void VSBM16::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VSBM16::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VSBM16___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VSBM16___024root___eval_static(&(vlSymsp->TOP));
        VSBM16___024root___eval_initial(&(vlSymsp->TOP));
        VSBM16___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VSBM16___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VSBM16::eventsPending() { return false; }

uint64_t VSBM16::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VSBM16::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VSBM16___024root___eval_final(VSBM16___024root* vlSelf);

VL_ATTR_COLD void VSBM16::final() {
    VSBM16___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VSBM16::hierName() const { return vlSymsp->name(); }
const char* VSBM16::modelName() const { return "VSBM16"; }
unsigned VSBM16::threads() const { return 1; }
void VSBM16::prepareClone() const { contextp()->prepareClone(); }
void VSBM16::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VSBM16::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VSBM16___024root__trace_decl_types(VerilatedVcd* tracep);

void VSBM16___024root__trace_init_top(VSBM16___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VSBM16___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSBM16___024root*>(voidSelf);
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    VSBM16___024root__trace_decl_types(tracep);
    VSBM16___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VSBM16___024root__trace_register(VSBM16___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VSBM16::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VSBM16::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VSBM16___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
