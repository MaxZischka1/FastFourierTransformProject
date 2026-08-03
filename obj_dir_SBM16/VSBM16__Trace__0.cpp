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
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.SBM16__DOT__interRE1),17);
        bufp->chgIData(oldp+1,(vlSelfRef.SBM16__DOT__interIM1),17);
        bufp->chgIData(oldp+2,(vlSelfRef.SBM16__DOT__interOdd2MRE),32);
        bufp->chgIData(oldp+3,(vlSelfRef.SBM16__DOT__interOdd2MIM),32);
        bufp->chgIData(oldp+4,(vlSelfRef.SBM16__DOT__sumEvRE),17);
        bufp->chgIData(oldp+5,(vlSelfRef.SBM16__DOT__sumEvIM),17);
    }
    bufp->chgBit(oldp+6,(vlSelfRef.clk));
    bufp->chgSData(oldp+7,(vlSelfRef.d1InRE),16);
    bufp->chgSData(oldp+8,(vlSelfRef.d1InIM),16);
    bufp->chgSData(oldp+9,(vlSelfRef.WInRE),16);
    bufp->chgSData(oldp+10,(vlSelfRef.WInIM),16);
    bufp->chgSData(oldp+11,(vlSelfRef.d2InRE),16);
    bufp->chgSData(oldp+12,(vlSelfRef.d2InIM),16);
    bufp->chgIData(oldp+13,(vlSelfRef.dOutEvIM),32);
    bufp->chgIData(oldp+14,(vlSelfRef.dOutEvRE),32);
    bufp->chgIData(oldp+15,(vlSelfRef.dOutOddIM),32);
    bufp->chgIData(oldp+16,(vlSelfRef.dOutOddRE),32);
}

void VSBM16___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root__trace_cleanup\n"); );
    // Body
    VSBM16___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSBM16___024root*>(voidSelf);
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
