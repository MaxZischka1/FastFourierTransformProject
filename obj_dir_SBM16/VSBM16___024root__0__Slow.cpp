// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSBM16.h for the primary calling header

#include "VSBM16__pch.h"

VL_ATTR_COLD void VSBM16___024root___eval_static(VSBM16___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___eval_static\n"); );
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void VSBM16___024root___eval_initial(VSBM16___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___eval_initial\n"); );
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VSBM16___024root___eval_final(VSBM16___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___eval_final\n"); );
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VSBM16___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VSBM16___024root___eval_phase__stl(VSBM16___024root* vlSelf);

VL_ATTR_COLD void VSBM16___024root___eval_settle(VSBM16___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___eval_settle\n"); );
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            VSBM16___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("SBM16.sv", 1, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (VSBM16___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void VSBM16___024root___eval_triggers__stl(VSBM16___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___eval_triggers__stl\n"); );
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VSBM16___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool VSBM16___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VSBM16___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(VSBM16___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool VSBM16___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void VSBM16___024root___ico_sequent__TOP__0(VSBM16___024root* vlSelf);

VL_ATTR_COLD void VSBM16___024root___eval_stl(VSBM16___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___eval_stl\n"); );
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        VSBM16___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool VSBM16___024root___eval_phase__stl(VSBM16___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___eval_phase__stl\n"); );
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    VSBM16___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = VSBM16___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        VSBM16___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool VSBM16___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VSBM16___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(VSBM16___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool VSBM16___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VSBM16___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(VSBM16___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VSBM16___024root___ctor_var_reset(VSBM16___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___ctor_var_reset\n"); );
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->d1InRE = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7162598630660266929ull);
    vlSelf->d1InIM = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4496050480434060108ull);
    vlSelf->WInRE = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11347288233001696677ull);
    vlSelf->WInIM = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 615623189748249843ull);
    vlSelf->d2InRE = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1465868360269702402ull);
    vlSelf->d2InIM = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6021060780541280614ull);
    vlSelf->dataOutIM = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8582329364871988122ull);
    vlSelf->dataOutRE = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16008428910837689854ull);
    vlSelf->SBM16__DOT__sumRE = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 12851734692319214019ull);
    vlSelf->SBM16__DOT__sumIM = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 2205185768415461019ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
