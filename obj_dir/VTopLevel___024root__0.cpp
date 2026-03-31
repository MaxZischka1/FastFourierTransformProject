// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTopLevel.h for the primary calling header

#include "VTopLevel__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VTopLevel___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void VTopLevel___024root___eval_triggers__ico(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval_triggers__ico\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTopLevel___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
}

bool VTopLevel___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___trigger_anySet__ico\n"); );
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

extern const VlUnpacked<CData/*1:0*/, 64> VTopLevel__ConstPool__TABLE_h88108318_0;
extern const VlUnpacked<CData/*1:0*/, 64> VTopLevel__ConstPool__TABLE_ha25dddc5_0;
extern const VlUnpacked<CData/*0:0*/, 64> VTopLevel__ConstPool__TABLE_h123afc4f_0;
extern const VlUnpacked<CData/*1:0*/, 64> VTopLevel__ConstPool__TABLE_hf0a19e2e_0;
extern const VlUnpacked<CData/*6:0*/, 64> VTopLevel__ConstPool__TABLE_h08d72c83_0;
extern const VlUnpacked<CData/*7:0*/, 64> VTopLevel__ConstPool__TABLE_h7df8bdbe_0;
extern const VlUnpacked<CData/*0:0*/, 64> VTopLevel__ConstPool__TABLE_hee18796d_0;

void VTopLevel___024root___ico_sequent__TOP__0(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___ico_sequent__TOP__0\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*5:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
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
    __Vtableidx2 = ((((IData)(vlSelfRef.TopLevel__DOT__doneSigIB) 
                      << 5U) | (((IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__transCompRW) 
                                 << 4U) | ((IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__fftComp) 
                                           << 3U))) 
                    | (((IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__transCompWR) 
                        << 2U) | (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__state)));
    vlSelfRef.TopLevel__DOT__PP1__DOT__next_state = 
        VTopLevel__ConstPool__TABLE_hf0a19e2e_0[__Vtableidx2];
    if ((2U & VTopLevel__ConstPool__TABLE_h08d72c83_0
         [__Vtableidx2])) {
        vlSelfRef.TopLevel__DOT__waddr1PP = VTopLevel__ConstPool__TABLE_h7df8bdbe_0
            [__Vtableidx2];
    }
    if ((4U & VTopLevel__ConstPool__TABLE_h08d72c83_0
         [__Vtableidx2])) {
        vlSelfRef.TopLevel__DOT__waddr2 = VTopLevel__ConstPool__TABLE_h7df8bdbe_0
            [__Vtableidx2];
    }
    if ((8U & VTopLevel__ConstPool__TABLE_h08d72c83_0
         [__Vtableidx2])) {
        vlSelfRef.TopLevel__DOT__raddr1 = VTopLevel__ConstPool__TABLE_h7df8bdbe_0
            [__Vtableidx2];
    }
    if ((0x10U & VTopLevel__ConstPool__TABLE_h08d72c83_0
         [__Vtableidx2])) {
        vlSelfRef.TopLevel__DOT__raddr2 = VTopLevel__ConstPool__TABLE_h7df8bdbe_0
            [__Vtableidx2];
    }
    if ((0x20U & VTopLevel__ConstPool__TABLE_h08d72c83_0
         [__Vtableidx2])) {
        vlSelfRef.TopLevel__DOT__weADDRen1 = VTopLevel__ConstPool__TABLE_hee18796d_0
            [__Vtableidx2];
    }
    if ((0x40U & VTopLevel__ConstPool__TABLE_h08d72c83_0
         [__Vtableidx2])) {
        vlSelfRef.TopLevel__DOT__weADDRen2 = VTopLevel__ConstPool__TABLE_hee18796d_0
            [__Vtableidx2];
    }
    vlSelfRef.TopLevel__DOT__waddr1 = ((IData)(vlSelfRef.TopLevel__DOT__change)
                                        ? (IData)(vlSelfRef.TopLevel__DOT__waddr1PP)
                                        : (IData)(vlSelfRef.TopLevel__DOT__addressOutIn));
}

void VTopLevel___024root___eval_ico(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval_ico\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        VTopLevel___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

bool VTopLevel___024root___eval_phase__ico(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval_phase__ico\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    VTopLevel___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = VTopLevel___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        VTopLevel___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTopLevel___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void VTopLevel___024root___eval_triggers__act(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval_triggers__act\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((IData)(vlSelfRef.clk) 
                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTopLevel___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool VTopLevel___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___trigger_anySet__act\n"); );
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

void VTopLevel___024root___nba_sequent__TOP__0(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___nba_sequent__TOP__0\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*5:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*7:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v0;
    __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v0 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v0;
    __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v0 = 0;
    CData/*0:0*/ __VdlySet__TopLevel__DOT__bram1RE__DOT__internal__v0;
    __VdlySet__TopLevel__DOT__bram1RE__DOT__internal__v0 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v1;
    __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v1 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v1;
    __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v1 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v2;
    __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v2 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v2;
    __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v2 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v3;
    __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v3 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v3;
    __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v3 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v4;
    __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v4 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v4;
    __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v4 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v5;
    __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v5 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v5;
    __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v5 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v6;
    __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v6 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v6;
    __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v6 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v7;
    __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v7 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v7;
    __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v7 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v8;
    __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v8 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v8;
    __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v8 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v9;
    __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v9 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v9;
    __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v9 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v10;
    __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v10 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v10;
    __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v10 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v11;
    __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v11 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v11;
    __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v11 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v12;
    __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v12 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v12;
    __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v12 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v13;
    __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v13 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v13;
    __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v13 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v14;
    __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v14 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v14;
    __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v14 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v15;
    __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v15 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v15;
    __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v15 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v0;
    __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v0 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v0;
    __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v0 = 0;
    CData/*0:0*/ __VdlySet__TopLevel__DOT__bram1IM__DOT__internal__v0;
    __VdlySet__TopLevel__DOT__bram1IM__DOT__internal__v0 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v1;
    __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v1 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v1;
    __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v1 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v2;
    __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v2 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v2;
    __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v2 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v3;
    __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v3 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v3;
    __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v3 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v4;
    __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v4 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v4;
    __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v4 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v5;
    __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v5 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v5;
    __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v5 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v6;
    __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v6 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v6;
    __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v6 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v7;
    __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v7 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v7;
    __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v7 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v8;
    __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v8 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v8;
    __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v8 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v9;
    __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v9 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v9;
    __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v9 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v10;
    __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v10 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v10;
    __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v10 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v11;
    __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v11 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v11;
    __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v11 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v12;
    __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v12 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v12;
    __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v12 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v13;
    __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v13 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v13;
    __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v13 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v14;
    __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v14 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v14;
    __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v14 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v15;
    __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v15 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v15;
    __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v15 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v0;
    __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v0 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v0;
    __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v0 = 0;
    CData/*0:0*/ __VdlySet__TopLevel__DOT__bram2RE__DOT__internal__v0;
    __VdlySet__TopLevel__DOT__bram2RE__DOT__internal__v0 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v1;
    __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v1 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v1;
    __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v1 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v2;
    __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v2 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v2;
    __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v2 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v3;
    __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v3 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v3;
    __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v3 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v4;
    __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v4 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v4;
    __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v4 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v5;
    __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v5 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v5;
    __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v5 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v6;
    __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v6 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v6;
    __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v6 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v7;
    __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v7 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v7;
    __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v7 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v8;
    __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v8 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v8;
    __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v8 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v9;
    __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v9 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v9;
    __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v9 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v10;
    __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v10 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v10;
    __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v10 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v11;
    __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v11 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v11;
    __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v11 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v12;
    __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v12 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v12;
    __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v12 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v13;
    __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v13 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v13;
    __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v13 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v14;
    __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v14 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v14;
    __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v14 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v15;
    __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v15 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v15;
    __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v15 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v0;
    __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v0 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v0;
    __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v0 = 0;
    CData/*0:0*/ __VdlySet__TopLevel__DOT__bram2IM__DOT__internal__v0;
    __VdlySet__TopLevel__DOT__bram2IM__DOT__internal__v0 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v1;
    __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v1 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v1;
    __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v1 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v2;
    __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v2 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v2;
    __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v2 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v3;
    __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v3 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v3;
    __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v3 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v4;
    __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v4 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v4;
    __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v4 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v5;
    __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v5 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v5;
    __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v5 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v6;
    __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v6 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v6;
    __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v6 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v7;
    __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v7 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v7;
    __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v7 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v8;
    __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v8 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v8;
    __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v8 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v9;
    __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v9 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v9;
    __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v9 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v10;
    __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v10 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v10;
    __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v10 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v11;
    __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v11 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v11;
    __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v11 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v12;
    __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v12 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v12;
    __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v12 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v13;
    __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v13 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v13;
    __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v13 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v14;
    __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v14 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v14;
    __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v14 = 0;
    CData/*0:0*/ __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v15;
    __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v15 = 0;
    CData/*7:0*/ __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v15;
    __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v15 = 0;
    // Body
    __VdlySet__TopLevel__DOT__bram1IM__DOT__internal__v0 = 0U;
    __VdlySet__TopLevel__DOT__bram1RE__DOT__internal__v0 = 0U;
    __VdlySet__TopLevel__DOT__bram2RE__DOT__internal__v0 = 0U;
    __VdlySet__TopLevel__DOT__bram2IM__DOT__internal__v0 = 0U;
    if (vlSelfRef.TopLevel__DOT__weADDRen1) {
        vlSelfRef.TopLevel__DOT__bram1RE__DOT__unnamedblk1__DOT__i = 0x00000010U;
        vlSelfRef.TopLevel__DOT__bram1IM__DOT__unnamedblk1__DOT__i = 0x00000010U;
        __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v0 
            = (1U & (IData)(vlSelfRef.TopLevel__DOT__wdata1IM));
        __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v0 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlySet__TopLevel__DOT__bram1IM__DOT__internal__v0 = 1U;
        __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v1 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1IM) 
                     >> 1U));
        __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v1 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v2 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1IM) 
                     >> 2U));
        __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v2 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v3 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1IM) 
                     >> 3U));
        __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v3 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v4 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1IM) 
                     >> 4U));
        __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v4 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v5 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1IM) 
                     >> 5U));
        __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v5 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v6 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1IM) 
                     >> 6U));
        __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v6 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v7 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1IM) 
                     >> 7U));
        __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v7 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v8 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1IM) 
                     >> 8U));
        __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v8 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v9 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1IM) 
                     >> 9U));
        __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v9 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v10 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1IM) 
                     >> 0x0aU));
        __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v10 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v11 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1IM) 
                     >> 0x0bU));
        __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v11 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v12 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1IM) 
                     >> 0x0cU));
        __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v12 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v13 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1IM) 
                     >> 0x0dU));
        __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v13 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v14 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1IM) 
                     >> 0x0eU));
        __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v14 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v15 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1IM) 
                     >> 0x0fU));
        __VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v15 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v0 
            = (1U & (IData)(vlSelfRef.TopLevel__DOT__wdata1RE));
        __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v0 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlySet__TopLevel__DOT__bram1RE__DOT__internal__v0 = 1U;
        __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v1 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1RE) 
                     >> 1U));
        __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v1 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v2 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1RE) 
                     >> 2U));
        __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v2 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v3 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1RE) 
                     >> 3U));
        __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v3 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v4 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1RE) 
                     >> 4U));
        __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v4 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v5 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1RE) 
                     >> 5U));
        __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v5 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v6 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1RE) 
                     >> 6U));
        __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v6 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v7 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1RE) 
                     >> 7U));
        __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v7 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v8 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1RE) 
                     >> 8U));
        __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v8 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v9 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1RE) 
                     >> 9U));
        __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v9 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v10 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1RE) 
                     >> 0x0aU));
        __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v10 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v11 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1RE) 
                     >> 0x0bU));
        __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v11 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v12 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1RE) 
                     >> 0x0cU));
        __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v12 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v13 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1RE) 
                     >> 0x0dU));
        __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v13 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v14 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1RE) 
                     >> 0x0eU));
        __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v14 
            = vlSelfRef.TopLevel__DOT__waddr1;
        __VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v15 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata1RE) 
                     >> 0x0fU));
        __VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v15 
            = vlSelfRef.TopLevel__DOT__waddr1;
    }
    if (vlSelfRef.TopLevel__DOT__weADDRen2) {
        vlSelfRef.TopLevel__DOT__bram2RE__DOT__unnamedblk1__DOT__i = 0x00000010U;
        vlSelfRef.TopLevel__DOT__bram2IM__DOT__unnamedblk1__DOT__i = 0x00000010U;
        __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v0 
            = (1U & (IData)(vlSelfRef.TopLevel__DOT__wdata2RE));
        __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v0 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlySet__TopLevel__DOT__bram2RE__DOT__internal__v0 = 1U;
        __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v1 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2RE) 
                     >> 1U));
        __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v1 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v2 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2RE) 
                     >> 2U));
        __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v2 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v3 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2RE) 
                     >> 3U));
        __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v3 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v4 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2RE) 
                     >> 4U));
        __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v4 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v5 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2RE) 
                     >> 5U));
        __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v5 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v6 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2RE) 
                     >> 6U));
        __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v6 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v7 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2RE) 
                     >> 7U));
        __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v7 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v8 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2RE) 
                     >> 8U));
        __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v8 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v9 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2RE) 
                     >> 9U));
        __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v9 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v10 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2RE) 
                     >> 0x0aU));
        __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v10 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v11 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2RE) 
                     >> 0x0bU));
        __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v11 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v12 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2RE) 
                     >> 0x0cU));
        __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v12 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v13 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2RE) 
                     >> 0x0dU));
        __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v13 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v14 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2RE) 
                     >> 0x0eU));
        __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v14 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v15 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2RE) 
                     >> 0x0fU));
        __VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v15 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v0 
            = (1U & (IData)(vlSelfRef.TopLevel__DOT__wdata2IM));
        __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v0 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlySet__TopLevel__DOT__bram2IM__DOT__internal__v0 = 1U;
        __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v1 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2IM) 
                     >> 1U));
        __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v1 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v2 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2IM) 
                     >> 2U));
        __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v2 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v3 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2IM) 
                     >> 3U));
        __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v3 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v4 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2IM) 
                     >> 4U));
        __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v4 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v5 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2IM) 
                     >> 5U));
        __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v5 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v6 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2IM) 
                     >> 6U));
        __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v6 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v7 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2IM) 
                     >> 7U));
        __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v7 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v8 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2IM) 
                     >> 8U));
        __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v8 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v9 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2IM) 
                     >> 9U));
        __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v9 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v10 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2IM) 
                     >> 0x0aU));
        __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v10 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v11 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2IM) 
                     >> 0x0bU));
        __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v11 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v12 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2IM) 
                     >> 0x0cU));
        __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v12 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v13 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2IM) 
                     >> 0x0dU));
        __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v13 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v14 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2IM) 
                     >> 0x0eU));
        __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v14 
            = vlSelfRef.TopLevel__DOT__waddr2;
        __VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v15 
            = (1U & ((IData)(vlSelfRef.TopLevel__DOT__wdata2IM) 
                     >> 0x0fU));
        __VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v15 
            = vlSelfRef.TopLevel__DOT__waddr2;
    }
    if ((1U == (IData)(vlSelfRef.TopLevel__DOT__testInBridge__DOT__state))) {
        if ((7U != (IData)(vlSelfRef.TopLevel__DOT__addressOutIn))) {
            vlSelfRef.TopLevel__DOT__addressOutIn = 
                (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.TopLevel__DOT__addressOutIn)));
        } else {
            vlSelfRef.TopLevel__DOT__testInBridge__DOT__totCount 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLevel__DOT__testInBridge__DOT__totCount)));
            vlSelfRef.TopLevel__DOT__addressOutIn = 0U;
        }
    }
    if (vlSelfRef.TopLevel__DOT__doneSigIB) {
        vlSelfRef.TopLevel__DOT__change = 1U;
    }
    vlSelfRef.TopLevel__DOT__rdata1RE = vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal
        [vlSelfRef.TopLevel__DOT__raddr1];
    vlSelfRef.TopLevel__DOT__rdata1IM = vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal
        [vlSelfRef.TopLevel__DOT__raddr1];
    vlSelfRef.TopLevel__DOT__rdata2IM = vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal
        [vlSelfRef.TopLevel__DOT__raddr2];
    vlSelfRef.TopLevel__DOT__rdata2RE = vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal
        [vlSelfRef.TopLevel__DOT__raddr2];
    vlSelfRef.TopLevel__DOT__PP1__DOT__state = vlSelfRef.TopLevel__DOT__PP1__DOT__next_state;
    if (__VdlySet__TopLevel__DOT__bram1RE__DOT__internal__v0) {
        vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v0] 
            = ((0xfffeU & vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v0]) 
               | (IData)(__VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v0));
        vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v1] 
            = ((0xfffdU & vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v1]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v1) 
                  << 1U));
        vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v2] 
            = ((0xfffbU & vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v2]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v2) 
                  << 2U));
        vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v3] 
            = ((0xfff7U & vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v3]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v3) 
                  << 3U));
        vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v4] 
            = ((0xffefU & vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v4]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v4) 
                  << 4U));
        vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v5] 
            = ((0xffdfU & vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v5]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v5) 
                  << 5U));
        vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v6] 
            = ((0xffbfU & vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v6]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v6) 
                  << 6U));
        vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v7] 
            = ((0xff7fU & vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v7]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v7) 
                  << 7U));
        vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v8] 
            = ((0xfeffU & vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v8]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v8) 
                  << 8U));
        vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v9] 
            = ((0xfdffU & vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v9]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v9) 
                  << 9U));
        vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v10] 
            = ((0xfbffU & vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v10]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v10) 
                  << 0x0000000aU));
        vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v11] 
            = ((0xf7ffU & vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v11]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v11) 
                  << 0x0000000bU));
        vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v12] 
            = ((0xefffU & vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v12]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v12) 
                  << 0x0000000cU));
        vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v13] 
            = ((0xdfffU & vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v13]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v13) 
                  << 0x0000000dU));
        vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v14] 
            = ((0xbfffU & vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v14]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v14) 
                  << 0x0000000eU));
        vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v15] 
            = ((0x7fffU & vlSelfRef.TopLevel__DOT__bram1RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1RE__DOT__internal__v15]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1RE__DOT__internal__v15) 
                  << 0x0000000fU));
    }
    if (__VdlySet__TopLevel__DOT__bram1IM__DOT__internal__v0) {
        vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v0] 
            = ((0xfffeU & vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v0]) 
               | (IData)(__VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v0));
        vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v1] 
            = ((0xfffdU & vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v1]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v1) 
                  << 1U));
        vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v2] 
            = ((0xfffbU & vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v2]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v2) 
                  << 2U));
        vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v3] 
            = ((0xfff7U & vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v3]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v3) 
                  << 3U));
        vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v4] 
            = ((0xffefU & vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v4]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v4) 
                  << 4U));
        vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v5] 
            = ((0xffdfU & vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v5]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v5) 
                  << 5U));
        vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v6] 
            = ((0xffbfU & vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v6]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v6) 
                  << 6U));
        vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v7] 
            = ((0xff7fU & vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v7]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v7) 
                  << 7U));
        vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v8] 
            = ((0xfeffU & vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v8]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v8) 
                  << 8U));
        vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v9] 
            = ((0xfdffU & vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v9]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v9) 
                  << 9U));
        vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v10] 
            = ((0xfbffU & vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v10]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v10) 
                  << 0x0000000aU));
        vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v11] 
            = ((0xf7ffU & vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v11]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v11) 
                  << 0x0000000bU));
        vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v12] 
            = ((0xefffU & vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v12]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v12) 
                  << 0x0000000cU));
        vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v13] 
            = ((0xdfffU & vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v13]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v13) 
                  << 0x0000000dU));
        vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v14] 
            = ((0xbfffU & vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v14]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v14) 
                  << 0x0000000eU));
        vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v15] 
            = ((0x7fffU & vlSelfRef.TopLevel__DOT__bram1IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram1IM__DOT__internal__v15]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram1IM__DOT__internal__v15) 
                  << 0x0000000fU));
    }
    if (__VdlySet__TopLevel__DOT__bram2IM__DOT__internal__v0) {
        vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v0] 
            = ((0xfffeU & vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v0]) 
               | (IData)(__VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v0));
        vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v1] 
            = ((0xfffdU & vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v1]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v1) 
                  << 1U));
        vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v2] 
            = ((0xfffbU & vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v2]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v2) 
                  << 2U));
        vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v3] 
            = ((0xfff7U & vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v3]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v3) 
                  << 3U));
        vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v4] 
            = ((0xffefU & vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v4]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v4) 
                  << 4U));
        vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v5] 
            = ((0xffdfU & vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v5]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v5) 
                  << 5U));
        vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v6] 
            = ((0xffbfU & vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v6]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v6) 
                  << 6U));
        vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v7] 
            = ((0xff7fU & vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v7]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v7) 
                  << 7U));
        vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v8] 
            = ((0xfeffU & vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v8]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v8) 
                  << 8U));
        vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v9] 
            = ((0xfdffU & vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v9]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v9) 
                  << 9U));
        vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v10] 
            = ((0xfbffU & vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v10]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v10) 
                  << 0x0000000aU));
        vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v11] 
            = ((0xf7ffU & vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v11]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v11) 
                  << 0x0000000bU));
        vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v12] 
            = ((0xefffU & vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v12]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v12) 
                  << 0x0000000cU));
        vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v13] 
            = ((0xdfffU & vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v13]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v13) 
                  << 0x0000000dU));
        vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v14] 
            = ((0xbfffU & vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v14]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v14) 
                  << 0x0000000eU));
        vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v15] 
            = ((0x7fffU & vlSelfRef.TopLevel__DOT__bram2IM__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2IM__DOT__internal__v15]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2IM__DOT__internal__v15) 
                  << 0x0000000fU));
    }
    if (__VdlySet__TopLevel__DOT__bram2RE__DOT__internal__v0) {
        vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v0] 
            = ((0xfffeU & vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v0]) 
               | (IData)(__VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v0));
        vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v1] 
            = ((0xfffdU & vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v1]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v1) 
                  << 1U));
        vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v2] 
            = ((0xfffbU & vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v2]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v2) 
                  << 2U));
        vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v3] 
            = ((0xfff7U & vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v3]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v3) 
                  << 3U));
        vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v4] 
            = ((0xffefU & vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v4]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v4) 
                  << 4U));
        vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v5] 
            = ((0xffdfU & vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v5]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v5) 
                  << 5U));
        vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v6] 
            = ((0xffbfU & vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v6]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v6) 
                  << 6U));
        vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v7] 
            = ((0xff7fU & vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v7]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v7) 
                  << 7U));
        vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v8] 
            = ((0xfeffU & vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v8]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v8) 
                  << 8U));
        vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v9] 
            = ((0xfdffU & vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v9]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v9) 
                  << 9U));
        vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v10] 
            = ((0xfbffU & vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v10]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v10) 
                  << 0x0000000aU));
        vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v11] 
            = ((0xf7ffU & vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v11]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v11) 
                  << 0x0000000bU));
        vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v12] 
            = ((0xefffU & vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v12]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v12) 
                  << 0x0000000cU));
        vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v13] 
            = ((0xdfffU & vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v13]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v13) 
                  << 0x0000000dU));
        vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v14] 
            = ((0xbfffU & vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v14]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v14) 
                  << 0x0000000eU));
        vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal[__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v15] 
            = ((0x7fffU & vlSelfRef.TopLevel__DOT__bram2RE__DOT__internal
                [__VdlyDim0__TopLevel__DOT__bram2RE__DOT__internal__v15]) 
               | ((IData)(__VdlyVal__TopLevel__DOT__bram2RE__DOT__internal__v15) 
                  << 0x0000000fU));
    }
    __Vtableidx3 = vlSelfRef.TopLevel__DOT__addressOutIn;
    vlSelfRef.ram1Output = VTopLevel__ConstPool__TABLE_h229f39d7_0
        [__Vtableidx3];
    vlSelfRef.TopLevel__DOT__testInBridge__DOT__state 
        = vlSelfRef.TopLevel__DOT__testInBridge__DOT__next_state;
    vlSelfRef.rdata1REO = vlSelfRef.TopLevel__DOT__rdata1RE;
    vlSelfRef.rdata1IMO = vlSelfRef.TopLevel__DOT__rdata1IM;
    vlSelfRef.rdata2IMO = vlSelfRef.TopLevel__DOT__rdata2IM;
    vlSelfRef.rdata2REO = vlSelfRef.TopLevel__DOT__rdata2RE;
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
    __Vtableidx2 = ((((IData)(vlSelfRef.TopLevel__DOT__doneSigIB) 
                      << 5U) | (((IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__transCompRW) 
                                 << 4U) | ((IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__fftComp) 
                                           << 3U))) 
                    | (((IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__transCompWR) 
                        << 2U) | (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__state)));
    vlSelfRef.TopLevel__DOT__PP1__DOT__next_state = 
        VTopLevel__ConstPool__TABLE_hf0a19e2e_0[__Vtableidx2];
    if ((2U & VTopLevel__ConstPool__TABLE_h08d72c83_0
         [__Vtableidx2])) {
        vlSelfRef.TopLevel__DOT__waddr1PP = VTopLevel__ConstPool__TABLE_h7df8bdbe_0
            [__Vtableidx2];
    }
    if (vlSelfRef.TopLevel__DOT__change) {
        vlSelfRef.TopLevel__DOT__wdata1RE = vlSelfRef.TopLevel__DOT__rdata2RE;
        vlSelfRef.TopLevel__DOT__waddr1 = vlSelfRef.TopLevel__DOT__waddr1PP;
    } else {
        vlSelfRef.TopLevel__DOT__wdata1RE = vlSelfRef.ram1Output;
        vlSelfRef.TopLevel__DOT__waddr1 = vlSelfRef.TopLevel__DOT__addressOutIn;
    }
    if ((4U & VTopLevel__ConstPool__TABLE_h08d72c83_0
         [__Vtableidx2])) {
        vlSelfRef.TopLevel__DOT__waddr2 = VTopLevel__ConstPool__TABLE_h7df8bdbe_0
            [__Vtableidx2];
    }
    if ((8U & VTopLevel__ConstPool__TABLE_h08d72c83_0
         [__Vtableidx2])) {
        vlSelfRef.TopLevel__DOT__raddr1 = VTopLevel__ConstPool__TABLE_h7df8bdbe_0
            [__Vtableidx2];
    }
    if ((0x10U & VTopLevel__ConstPool__TABLE_h08d72c83_0
         [__Vtableidx2])) {
        vlSelfRef.TopLevel__DOT__raddr2 = VTopLevel__ConstPool__TABLE_h7df8bdbe_0
            [__Vtableidx2];
    }
    if ((0x20U & VTopLevel__ConstPool__TABLE_h08d72c83_0
         [__Vtableidx2])) {
        vlSelfRef.TopLevel__DOT__weADDRen1 = VTopLevel__ConstPool__TABLE_hee18796d_0
            [__Vtableidx2];
    }
    if ((0x40U & VTopLevel__ConstPool__TABLE_h08d72c83_0
         [__Vtableidx2])) {
        vlSelfRef.TopLevel__DOT__weADDRen2 = VTopLevel__ConstPool__TABLE_hee18796d_0
            [__Vtableidx2];
    }
}

void VTopLevel___024root___eval_nba(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval_nba\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        VTopLevel___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
}

void VTopLevel___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool VTopLevel___024root___eval_phase__act(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval_phase__act\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VTopLevel___024root___eval_triggers__act(vlSelf);
    VTopLevel___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void VTopLevel___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool VTopLevel___024root___eval_phase__nba(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval_phase__nba\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = VTopLevel___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        VTopLevel___024root___eval_nba(vlSelf);
        VTopLevel___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void VTopLevel___024root___eval(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            VTopLevel___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("TopLevel.sv", 1, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (VTopLevel___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VTopLevel___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("TopLevel.sv", 1, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VTopLevel___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("TopLevel.sv", 1, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (VTopLevel___024root___eval_phase__act(vlSelf));
    } while (VTopLevel___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void VTopLevel___024root___eval_debug_assertions(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval_debug_assertions\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.startSig & 0xfeU)))) {
        Verilated::overWidthError("startSig");
    }
}
#endif  // VL_DEBUG
