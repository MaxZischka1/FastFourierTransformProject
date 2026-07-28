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

VL_ATTR_COLD void VSBM16___024root___eval_settle(VSBM16___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___eval_settle\n"); );
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

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
    vlSelf->dataOutRE = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16008428910837689854ull);
    vlSelf->dataOutIM = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8582329364871988122ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
