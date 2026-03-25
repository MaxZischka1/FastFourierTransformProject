// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTopLevel.h for the primary calling header

#include "VTopLevel__pch.h"

VL_ATTR_COLD void VTopLevel___024root___eval_static(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval_static\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void VTopLevel___024root___eval_initial(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval_initial\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VTopLevel___024root___eval_final(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval_final\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTopLevel___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VTopLevel___024root___eval_phase__stl(VTopLevel___024root* vlSelf);

VL_ATTR_COLD void VTopLevel___024root___eval_settle(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval_settle\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            VTopLevel___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("TopLevel.sv", 1, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = VTopLevel___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void VTopLevel___024root___eval_triggers_vec__stl(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval_triggers_vec__stl\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool VTopLevel___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VTopLevel___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(VTopLevel___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool VTopLevel___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___trigger_anySet__stl\n"); );
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

extern const VlUnpacked<SData/*15:0*/, 256> VTopLevel__ConstPool__TABLE_hbd63c053_0;

VL_ATTR_COLD void VTopLevel___024root___stl_sequent__TOP__0(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___stl_sequent__TOP__0\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.doneSigOut = vlSelfRef.TopLevel__DOT__doneSig;
    vlSelfRef.addyOut = vlSelfRef.TopLevel__DOT__addressOutIn;
    __Vtableidx1 = vlSelfRef.TopLevel__DOT__addressOutIn;
    vlSelfRef.ram1Output = VTopLevel__ConstPool__TABLE_hbd63c053_0
        [__Vtableidx1];
}

VL_ATTR_COLD void VTopLevel___024root___eval_stl(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval_stl\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        VTopLevel___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool VTopLevel___024root___eval_phase__stl(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval_phase__stl\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    VTopLevel___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTopLevel___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = VTopLevel___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        VTopLevel___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool VTopLevel___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VTopLevel___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(VTopLevel___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTopLevel___024root___ctor_var_reset(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___ctor_var_reset\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->startSig = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3585552680984440318ull);
    vlSelf->ram1Output = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4269501188936709378ull);
    vlSelf->doneSigOut = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14427018800967122946ull);
    vlSelf->addyOut = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6021286964983635323ull);
    vlSelf->TopLevel__DOT__addressOutIn = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5768373060309013280ull);
    vlSelf->TopLevel__DOT__doneSig = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9138192886134604057ull);
    vlSelf->TopLevel__DOT__testInBridge__DOT__trans = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5137577531782777497ull);
    vlSelf->TopLevel__DOT__testInBridge__DOT__totCount = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7057345006368643748ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
