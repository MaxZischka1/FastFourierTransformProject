// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "VSBM16__Syms.h"


void VSBM16___024root__trace_chg_0_sub_0(VSBM16___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VSBM16___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root__trace_chg_0\n"); );
    // Body
    VSBM16___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSBM16___024root*>(voidSelf);
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    VSBM16___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VSBM16___024root__trace_chg_0_sub_0(VSBM16___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root__trace_chg_0_sub_0\n"); );
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgSData(oldp+1,(vlSelfRef.d1InRE),16);
    bufp->chgSData(oldp+2,(vlSelfRef.d1InIM),16);
    bufp->chgSData(oldp+3,(vlSelfRef.WInRE),16);
    bufp->chgSData(oldp+4,(vlSelfRef.WInIM),16);
    bufp->chgSData(oldp+5,(vlSelfRef.d2InRE),16);
    bufp->chgSData(oldp+6,(vlSelfRef.d2InIM),16);
    bufp->chgIData(oldp+7,(vlSelfRef.dataOutRE32),32);
    bufp->chgIData(oldp+8,(vlSelfRef.dataOutIM32),32);
    bufp->chgSData(oldp+9,((0x0000ffffU & ((VL_EXTENDS_II(17,16, 
                                                          (0x0000ffffU 
                                                           & (IData)(
                                                                     (0x000000000000ffffULL 
                                                                      & ((VL_MULS_QQQ(33, 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InRE))), 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInRE)))) 
                                                                          - 
                                                                          VL_MULS_QQQ(33, 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InIM))), 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInIM))))) 
                                                                         >> 0x00000011U))))) 
                                            + VL_EXTENDS_II(17,16, (IData)(vlSelfRef.d2InRE))) 
                                           >> 1U))),16);
    bufp->chgSData(oldp+10,((0x0000ffffU & ((VL_EXTENDS_II(17,16, 
                                                           (0x0000ffffU 
                                                            & (IData)(
                                                                      (0x000000000000ffffULL 
                                                                       & ((VL_MULS_QQQ(33, 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InRE))), 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInIM)))) 
                                                                           + 
                                                                           VL_MULS_QQQ(33, 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InIM))), 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInRE))))) 
                                                                          >> 0x00000011U))))) 
                                             + VL_EXTENDS_II(17,16, (IData)(vlSelfRef.d2InIM))) 
                                            >> 1U))),16);
    bufp->chgQData(oldp+11,((0x00000001ffffffffULL 
                             & (VL_MULS_QQQ(33, (0x00000001ffffffffULL 
                                                 & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InRE))), 
                                            (0x00000001ffffffffULL 
                                             & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInRE)))) 
                                - VL_MULS_QQQ(33, (0x00000001ffffffffULL 
                                                   & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InIM))), 
                                              (0x00000001ffffffffULL 
                                               & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInIM))))))),33);
    bufp->chgQData(oldp+13,((0x00000001ffffffffULL 
                             & (VL_MULS_QQQ(33, (0x00000001ffffffffULL 
                                                 & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InRE))), 
                                            (0x00000001ffffffffULL 
                                             & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInIM)))) 
                                + VL_MULS_QQQ(33, (0x00000001ffffffffULL 
                                                   & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InIM))), 
                                              (0x00000001ffffffffULL 
                                               & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInRE))))))),33);
    bufp->chgIData(oldp+15,((0x0001ffffU & (VL_EXTENDS_II(17,16, 
                                                          (0x0000ffffU 
                                                           & (IData)(
                                                                     (0x000000000000ffffULL 
                                                                      & ((VL_MULS_QQQ(33, 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InRE))), 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInRE)))) 
                                                                          - 
                                                                          VL_MULS_QQQ(33, 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InIM))), 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInIM))))) 
                                                                         >> 0x00000011U))))) 
                                            + VL_EXTENDS_II(17,16, (IData)(vlSelfRef.d2InRE))))),17);
    bufp->chgIData(oldp+16,((0x0001ffffU & (VL_EXTENDS_II(17,16, 
                                                          (0x0000ffffU 
                                                           & (IData)(
                                                                     (0x000000000000ffffULL 
                                                                      & ((VL_MULS_QQQ(33, 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InRE))), 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInIM)))) 
                                                                          + 
                                                                          VL_MULS_QQQ(33, 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InIM))), 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInRE))))) 
                                                                         >> 0x00000011U))))) 
                                            + VL_EXTENDS_II(17,16, (IData)(vlSelfRef.d2InIM))))),17);
}

void VSBM16___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root__trace_cleanup\n"); );
    // Locals
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    VSBM16___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSBM16___024root*>(voidSelf);
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
