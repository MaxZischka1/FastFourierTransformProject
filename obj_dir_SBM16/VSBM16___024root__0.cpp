// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSBM16.h for the primary calling header

#include "VSBM16__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VSBM16___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void VSBM16___024root___eval_triggers__act(VSBM16___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___eval_triggers__act\n"); );
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((IData)(vlSelfRef.clk) 
                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VSBM16___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool VSBM16___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___trigger_anySet__act\n"); );
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

void VSBM16___024root___nba_sequent__TOP__0(VSBM16___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___nba_sequent__TOP__0\n"); );
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.dOutEvRE = (((- (IData)((1U & (vlSelfRef.SBM16__DOT__sumEvREP 
                                             >> 0x10U)))) 
                           << 0x00000010U) | (0x0000ffffU 
                                              & (vlSelfRef.SBM16__DOT__sumEvREP 
                                                 >> 1U)));
    vlSelfRef.dOutEvIM = (((- (IData)((1U & (vlSelfRef.SBM16__DOT__sumEvIMP 
                                             >> 0x10U)))) 
                           << 0x00000010U) | (0x0000ffffU 
                                              & (vlSelfRef.SBM16__DOT__sumEvIMP 
                                                 >> 1U)));
    vlSelfRef.SBM16__DOT__interOdd3MRE = (vlSelfRef.SBM16__DOT__interOdd2MRE 
                                          - VL_MULS_III(32, 
                                                        VL_EXTENDS_II(32,17, vlSelfRef.SBM16__DOT__interIM1), 
                                                        VL_EXTENDS_II(32,16, (IData)(vlSelfRef.WInIM))));
    vlSelfRef.SBM16__DOT__interOdd3MIM = (vlSelfRef.SBM16__DOT__interOdd2MIM 
                                          + VL_MULS_III(32, 
                                                        VL_EXTENDS_II(32,17, vlSelfRef.SBM16__DOT__interIM1), 
                                                        VL_EXTENDS_II(32,16, (IData)(vlSelfRef.WInRE))));
    vlSelfRef.SBM16__DOT__sumEvREP = vlSelfRef.SBM16__DOT__sumEvRE;
    vlSelfRef.SBM16__DOT__sumEvIMP = vlSelfRef.SBM16__DOT__sumEvIM;
    vlSelfRef.dOutOddRE = (((- (IData)((vlSelfRef.SBM16__DOT__interOdd3MRE 
                                        >> 0x0000001fU))) 
                            << 0x00000010U) | (vlSelfRef.SBM16__DOT__interOdd3MRE 
                                               >> 0x00000010U));
    vlSelfRef.dOutOddIM = (((- (IData)((vlSelfRef.SBM16__DOT__interOdd3MIM 
                                        >> 0x0000001fU))) 
                            << 0x00000010U) | (vlSelfRef.SBM16__DOT__interOdd3MIM 
                                               >> 0x00000010U));
    vlSelfRef.SBM16__DOT__interIM1 = (0x0001ffffU & 
                                      (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.d1InIM)) 
                                       - VL_EXTENDS_II(17,16, (IData)(vlSelfRef.d2InIM))));
    vlSelfRef.SBM16__DOT__interOdd2MRE = VL_MULS_III(32, 
                                                     VL_EXTENDS_II(32,17, vlSelfRef.SBM16__DOT__interRE1), 
                                                     VL_EXTENDS_II(32,16, (IData)(vlSelfRef.WInRE)));
    vlSelfRef.SBM16__DOT__interOdd2MIM = VL_MULS_III(32, 
                                                     VL_EXTENDS_II(32,17, vlSelfRef.SBM16__DOT__interRE1), 
                                                     VL_EXTENDS_II(32,16, (IData)(vlSelfRef.WInIM)));
    vlSelfRef.SBM16__DOT__sumEvRE = (0x0001ffffU & 
                                     (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.d1InRE)) 
                                      + VL_EXTENDS_II(17,16, (IData)(vlSelfRef.d2InRE))));
    vlSelfRef.SBM16__DOT__sumEvIM = (0x0001ffffU & 
                                     (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.d1InIM)) 
                                      + VL_EXTENDS_II(17,16, (IData)(vlSelfRef.d2InIM))));
    vlSelfRef.SBM16__DOT__interRE1 = (0x0001ffffU & 
                                      (VL_EXTENDS_II(17,16, (IData)(vlSelfRef.d1InRE)) 
                                       - VL_EXTENDS_II(17,16, (IData)(vlSelfRef.d2InRE))));
}

void VSBM16___024root___eval_nba(VSBM16___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___eval_nba\n"); );
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        VSBM16___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

void VSBM16___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool VSBM16___024root___eval_phase__act(VSBM16___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___eval_phase__act\n"); );
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VSBM16___024root___eval_triggers__act(vlSelf);
    VSBM16___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void VSBM16___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool VSBM16___024root___eval_phase__nba(VSBM16___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___eval_phase__nba\n"); );
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = VSBM16___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        VSBM16___024root___eval_nba(vlSelf);
        VSBM16___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void VSBM16___024root___eval(VSBM16___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___eval\n"); );
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VSBM16___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("SBM16.sv", 6, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VSBM16___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("SBM16.sv", 6, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (VSBM16___024root___eval_phase__act(vlSelf));
    } while (VSBM16___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void VSBM16___024root___eval_debug_assertions(VSBM16___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root___eval_debug_assertions\n"); );
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
}
#endif  // VL_DEBUG
