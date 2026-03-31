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
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.TopLevel__DOT__doneSigIB));
        bufp->chgBit(oldp+1,(vlSelfRef.TopLevel__DOT__weADDRen1));
        bufp->chgBit(oldp+2,(vlSelfRef.TopLevel__DOT__weADDRen2));
        bufp->chgCData(oldp+3,(vlSelfRef.TopLevel__DOT__waddr1),8);
        bufp->chgCData(oldp+4,(vlSelfRef.TopLevel__DOT__waddr1PP),8);
        bufp->chgCData(oldp+5,(vlSelfRef.TopLevel__DOT__waddr2),8);
        bufp->chgCData(oldp+6,(vlSelfRef.TopLevel__DOT__raddr1),8);
        bufp->chgCData(oldp+7,(vlSelfRef.TopLevel__DOT__raddr2),8);
        bufp->chgCData(oldp+8,(vlSelfRef.TopLevel__DOT__PP1__DOT__next_state),2);
        bufp->chgCData(oldp+9,(vlSelfRef.TopLevel__DOT__testInBridge__DOT__next_state),2);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+10,(vlSelfRef.TopLevel__DOT__change));
        bufp->chgSData(oldp+11,(vlSelfRef.TopLevel__DOT__wdata1RE),16);
        bufp->chgSData(oldp+12,(vlSelfRef.TopLevel__DOT__rdata1RE),16);
        bufp->chgSData(oldp+13,(vlSelfRef.TopLevel__DOT__rdata1IM),16);
        bufp->chgSData(oldp+14,(vlSelfRef.TopLevel__DOT__rdata2RE),16);
        bufp->chgSData(oldp+15,(vlSelfRef.TopLevel__DOT__rdata2IM),16);
        bufp->chgCData(oldp+16,(vlSelfRef.TopLevel__DOT__addressOutIn),8);
        bufp->chgCData(oldp+17,(vlSelfRef.TopLevel__DOT__PP1__DOT__state),2);
        bufp->chgIData(oldp+18,(vlSelfRef.TopLevel__DOT__bram1IM__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+19,(vlSelfRef.TopLevel__DOT__bram1RE__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+20,(vlSelfRef.TopLevel__DOT__bram2IM__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+21,(vlSelfRef.TopLevel__DOT__bram2RE__DOT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+22,(vlSelfRef.TopLevel__DOT__testInBridge__DOT__state),2);
        bufp->chgCData(oldp+23,(vlSelfRef.TopLevel__DOT__testInBridge__DOT__totCount),3);
    }
    bufp->chgBit(oldp+24,(vlSelfRef.clk));
    bufp->chgBit(oldp+25,(vlSelfRef.startSig));
    bufp->chgSData(oldp+26,(vlSelfRef.ram1Output),16);
    bufp->chgSData(oldp+27,(vlSelfRef.rdata1REO),16);
    bufp->chgSData(oldp+28,(vlSelfRef.rdata1IMO),16);
    bufp->chgSData(oldp+29,(vlSelfRef.rdata2REO),16);
    bufp->chgSData(oldp+30,(vlSelfRef.rdata2IMO),16);
}

void VTopLevel___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root__trace_cleanup\n"); );
    // Body
    VTopLevel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTopLevel___024root*>(voidSelf);
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
