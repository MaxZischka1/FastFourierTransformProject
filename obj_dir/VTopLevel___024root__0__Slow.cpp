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
            VL_FATAL_MT("TopLevel.sv", 1, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (VTopLevel___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void VTopLevel___024root___eval_triggers__stl(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval_triggers__stl\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTopLevel___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
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

extern const VlUnpacked<SData/*15:0*/, 256> VTopLevel__ConstPool__TABLE_h229f39d7_0;
extern const VlUnpacked<CData/*1:0*/, 64> VTopLevel__ConstPool__TABLE_h88108318_0;
extern const VlUnpacked<CData/*1:0*/, 64> VTopLevel__ConstPool__TABLE_ha25dddc5_0;
extern const VlUnpacked<CData/*0:0*/, 64> VTopLevel__ConstPool__TABLE_h123afc4f_0;

VL_ATTR_COLD void VTopLevel___024root___stl_sequent__TOP__0(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___stl_sequent__TOP__0\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*7:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
    vlSelfRef.TopLevel__DOT__weADDRen1 = ((1U & ((IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__state) 
                                                 >> 1U)) 
                                          && (1U & 
                                              (~ (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__state))));
    vlSelfRef.TopLevel__DOT__weADDRen2 = ((1U & (~ 
                                                 ((IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__state) 
                                                  >> 1U))) 
                                          && (1U & (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__state)));
    vlSelfRef.rdata1REO = vlSelfRef.TopLevel__DOT__rdata1RE;
    vlSelfRef.rdata1IMO = vlSelfRef.TopLevel__DOT__rdata1IM;
    vlSelfRef.rdata2REO = vlSelfRef.TopLevel__DOT__rdata2RE;
    vlSelfRef.rdata2IMO = vlSelfRef.TopLevel__DOT__rdata2IM;
    vlSelfRef.waddr2Out = vlSelfRef.TopLevel__DOT__PP1__DOT__waddr2Buf;
    __Vtableidx2 = vlSelfRef.TopLevel__DOT__addressOutIn;
    vlSelfRef.ram1Output = VTopLevel__ConstPool__TABLE_h229f39d7_0
        [__Vtableidx2];
    if (vlSelfRef.TopLevel__DOT__change) {
        vlSelfRef.TopLevel__DOT__waddr1 = vlSelfRef.TopLevel__DOT__PP1__DOT__waddr1Buf;
        vlSelfRef.TopLevel__DOT__wdata1RE = vlSelfRef.TopLevel__DOT__BFUoutRE;
    } else {
        vlSelfRef.TopLevel__DOT__waddr1 = vlSelfRef.TopLevel__DOT__addressOutIn;
        vlSelfRef.TopLevel__DOT__wdata1RE = vlSelfRef.ram1Output;
    }
    __Vtableidx1 = (((IData)(vlSelfRef.TopLevel__DOT__testInBridge__DOT__totCount) 
                     << 3U) | (((IData)(vlSelfRef.startSig) 
                                << 2U) | (IData)(vlSelfRef.TopLevel__DOT__testInBridge__DOT__state)));
    vlSelfRef.TopLevel__DOT__testInBridge__DOT__next_state 
        = VTopLevel__ConstPool__TABLE_h88108318_0[__Vtableidx1];
    if ((2U & VTopLevel__ConstPool__TABLE_ha25dddc5_0
         [__Vtableidx1])) {
        vlSelfRef.TopLevel__DOT__doneSigIB = VTopLevel__ConstPool__TABLE_h123afc4f_0
            [__Vtableidx1];
    }
    vlSelfRef.waddr1Out = vlSelfRef.TopLevel__DOT__waddr1;
    vlSelfRef.TopLevel__DOT__PP1__DOT__next_state = 
        ((2U & (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__state))
          ? ((1U & (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__state))
              ? 0U : ((7U == (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__waddr1Buf))
                       ? ((IData)((3U == (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__state)))
                           ? 3U : 1U) : 2U)) : ((1U 
                                                 & (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__state))
                                                 ? 
                                                ((7U 
                                                  == (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__raddr1Buf))
                                                  ? 2U
                                                  : 1U)
                                                 : 
                                                ((IData)(vlSelfRef.TopLevel__DOT__doneSigIB)
                                                  ? 1U
                                                  : 0U)));
}

VL_ATTR_COLD void VTopLevel___024root____Vm_traceActivitySetAll(VTopLevel___024root* vlSelf);

VL_ATTR_COLD void VTopLevel___024root___eval_stl(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval_stl\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        VTopLevel___024root___stl_sequent__TOP__0(vlSelf);
        VTopLevel___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool VTopLevel___024root___eval_phase__stl(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval_phase__stl\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    VTopLevel___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = VTopLevel___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        VTopLevel___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool VTopLevel___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VTopLevel___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(VTopLevel___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

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

VL_ATTR_COLD void VTopLevel___024root____Vm_traceActivitySetAll(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root____Vm_traceActivitySetAll\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
}

VL_ATTR_COLD void VTopLevel___024root___ctor_var_reset(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___ctor_var_reset\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->startSig = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3585552680984440318ull);
    vlSelf->ram1Output = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4269501188936709378ull);
    vlSelf->rdata1REO = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15667940408273443611ull);
    vlSelf->rdata1IMO = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12297271614713520346ull);
    vlSelf->rdata2REO = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7102719076475272938ull);
    vlSelf->rdata2IMO = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1584714297638502653ull);
    vlSelf->waddr1Out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2648599052521179159ull);
    vlSelf->waddr2Out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2296014937893160085ull);
    vlSelf->TopLevel__DOT__doneSigIB = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7562141334435191444ull);
    vlSelf->TopLevel__DOT__change = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13228183638273972666ull);
    vlSelf->TopLevel__DOT__BFUoutRE = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8123094190588816566ull);
    vlSelf->TopLevel__DOT__BFUoutIM = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17420761700350735241ull);
    vlSelf->TopLevel__DOT__rdata1RE = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6527204208823310693ull);
    vlSelf->TopLevel__DOT__rdata1IM = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 283248351097862380ull);
    vlSelf->TopLevel__DOT__rdata2RE = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13633015038845557564ull);
    vlSelf->TopLevel__DOT__rdata2IM = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 942386718824133767ull);
    vlSelf->TopLevel__DOT__weADDRen1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9376893600218431097ull);
    vlSelf->TopLevel__DOT__weADDRen2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16189399209249489213ull);
    vlSelf->TopLevel__DOT__addressOutIn = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5768373060309013280ull);
    vlSelf->TopLevel__DOT__waddr1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3056408167902184171ull);
    vlSelf->TopLevel__DOT__wdata1RE = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12860342741479223858ull);
    vlSelf->TopLevel__DOT__testInBridge__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3312238860620583337ull);
    vlSelf->TopLevel__DOT__testInBridge__DOT__next_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12150993774755975189ull);
    vlSelf->TopLevel__DOT__testInBridge__DOT__totCount = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7057345006368643748ull);
    vlSelf->TopLevel__DOT__PP1__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7938241199139596502ull);
    vlSelf->TopLevel__DOT__PP1__DOT__next_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7675165078554480562ull);
    vlSelf->TopLevel__DOT__PP1__DOT__waddr1Buf = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4782107046159501421ull);
    vlSelf->TopLevel__DOT__PP1__DOT__waddr2Buf = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2065757193181924796ull);
    vlSelf->TopLevel__DOT__PP1__DOT__raddr1Buf = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17834190775895605075ull);
    vlSelf->TopLevel__DOT__PP1__DOT__raddr2Buf = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11664296523885555970ull);
    vlSelf->TopLevel__DOT__PP1__DOT__iteratStep = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6424043561797858103ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->TopLevel__DOT__bram1RE__DOT__internal[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 877583214602723823ull);
    }
    vlSelf->TopLevel__DOT__bram1RE__DOT__unnamedblk1__DOT__i = 0;
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->TopLevel__DOT__bram1IM__DOT__internal[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6010147895917160831ull);
    }
    vlSelf->TopLevel__DOT__bram1IM__DOT__unnamedblk1__DOT__i = 0;
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->TopLevel__DOT__bram2RE__DOT__internal[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11120607004997049591ull);
    }
    vlSelf->TopLevel__DOT__bram2RE__DOT__unnamedblk1__DOT__i = 0;
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->TopLevel__DOT__bram2IM__DOT__internal[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11843556738306909766ull);
    }
    vlSelf->TopLevel__DOT__bram2IM__DOT__unnamedblk1__DOT__i = 0;
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
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
