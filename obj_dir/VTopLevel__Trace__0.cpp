// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "VTopLevel__Syms.h"


void VTopLevel___024root__trace_chg_0_sub_0(VTopLevel___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTopLevel___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root__trace_chg_0\n"); );
    // Body
    VTopLevel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTopLevel___024root*>(voidSelf);
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    VTopLevel___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VTopLevel___024root__trace_chg_0_sub_0(VTopLevel___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root__trace_chg_0_sub_0\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgCData(oldp+0,(vlSelfRef.TopLevel__DOT__addressOutIn),8);
        bufp->chgBit(oldp+1,(vlSelfRef.TopLevel__DOT__doneSig));
        bufp->chgBit(oldp+2,(vlSelfRef.TopLevel__DOT__testInBridge__DOT__trans));
        bufp->chgCData(oldp+3,(vlSelfRef.TopLevel__DOT__testInBridge__DOT__totCount),3);
    }
    bufp->chgBit(oldp+4,(vlSelfRef.clk));
    bufp->chgBit(oldp+5,(vlSelfRef.startSig));
    bufp->chgSData(oldp+6,(vlSelfRef.ram1Output),16);
    bufp->chgBit(oldp+7,(vlSelfRef.doneSigOut));
    bufp->chgCData(oldp+8,(vlSelfRef.addyOut),8);
}

void VTopLevel___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root__trace_cleanup\n"); );
    // Body
    VTopLevel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTopLevel___024root*>(voidSelf);
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
