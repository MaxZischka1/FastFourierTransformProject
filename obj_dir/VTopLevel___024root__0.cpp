// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTopLevel.h for the primary calling header

#include "VTopLevel__pch.h"

void VTopLevel___024root___eval_triggers_vec__act(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval_triggers_vec__act\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((IData)(vlSelfRef.clk) 
                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
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

extern const VlUnpacked<SData/*15:0*/, 256> VTopLevel__ConstPool__TABLE_hbd63c053_0;

void VTopLevel___024root___nba_sequent__TOP__0(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___nba_sequent__TOP__0\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*0:0*/ __Vdly__TopLevel__DOT__testInBridge__DOT__trans;
    __Vdly__TopLevel__DOT__testInBridge__DOT__trans = 0;
    CData/*2:0*/ __Vdly__TopLevel__DOT__testInBridge__DOT__totCount;
    __Vdly__TopLevel__DOT__testInBridge__DOT__totCount = 0;
    // Body
    __Vdly__TopLevel__DOT__testInBridge__DOT__totCount 
        = vlSelfRef.TopLevel__DOT__testInBridge__DOT__totCount;
    if (vlSelfRef.TopLevel__DOT__testInBridge__DOT__trans) {
        __Vdly__TopLevel__DOT__testInBridge__DOT__trans = 1U;
        if ((7U != (IData)(vlSelfRef.TopLevel__DOT__addressOutIn))) {
            vlSelfRef.TopLevel__DOT__addressOutIn = 
                (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.TopLevel__DOT__addressOutIn)));
        } else {
            __Vdly__TopLevel__DOT__testInBridge__DOT__totCount 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.TopLevel__DOT__testInBridge__DOT__totCount)));
            vlSelfRef.TopLevel__DOT__addressOutIn = 0U;
        }
    } else {
        __Vdly__TopLevel__DOT__testInBridge__DOT__trans = 0U;
    }
    if ((1U == (IData)(vlSelfRef.TopLevel__DOT__testInBridge__DOT__totCount))) {
        __Vdly__TopLevel__DOT__testInBridge__DOT__trans = 0U;
    }
    if (((IData)(vlSelfRef.startSig) & (~ (IData)(vlSelfRef.TopLevel__DOT__testInBridge__DOT__trans)))) {
        __Vdly__TopLevel__DOT__testInBridge__DOT__trans = 1U;
        vlSelfRef.TopLevel__DOT__doneSig = 0U;
    }
    vlSelfRef.TopLevel__DOT__testInBridge__DOT__totCount 
        = __Vdly__TopLevel__DOT__testInBridge__DOT__totCount;
    vlSelfRef.TopLevel__DOT__testInBridge__DOT__trans 
        = __Vdly__TopLevel__DOT__testInBridge__DOT__trans;
    vlSelfRef.addyOut = vlSelfRef.TopLevel__DOT__addressOutIn;
    __Vtableidx1 = vlSelfRef.TopLevel__DOT__addressOutIn;
    vlSelfRef.ram1Output = VTopLevel__ConstPool__TABLE_hbd63c053_0
        [__Vtableidx1];
    vlSelfRef.doneSigOut = vlSelfRef.TopLevel__DOT__doneSig;
}

void VTopLevel___024root___eval_nba(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval_nba\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        VTopLevel___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

void VTopLevel___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTopLevel___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool VTopLevel___024root___eval_phase__act(VTopLevel___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root___eval_phase__act\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VTopLevel___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTopLevel___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    VTopLevel___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
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
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VTopLevel___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("TopLevel.sv", 1, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VTopLevel___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("TopLevel.sv", 1, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = VTopLevel___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = VTopLevel___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
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
