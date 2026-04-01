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
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.TopLevel__DOT__change));
        bufp->chgSData(oldp+1,(vlSelfRef.TopLevel__DOT__BFUoutRE),16);
        bufp->chgSData(oldp+2,(vlSelfRef.TopLevel__DOT__BFUoutIM),16);
        bufp->chgSData(oldp+3,(vlSelfRef.TopLevel__DOT__rdata1RE),16);
        bufp->chgSData(oldp+4,(vlSelfRef.TopLevel__DOT__rdata1IM),16);
        bufp->chgSData(oldp+5,(vlSelfRef.TopLevel__DOT__rdata2RE),16);
        bufp->chgSData(oldp+6,(vlSelfRef.TopLevel__DOT__rdata2IM),16);
        bufp->chgBit(oldp+7,(vlSelfRef.TopLevel__DOT__weADDRen1));
        bufp->chgBit(oldp+8,(vlSelfRef.TopLevel__DOT__weADDRen2));
        bufp->chgCData(oldp+9,(vlSelfRef.TopLevel__DOT__addressOutIn),8);
        bufp->chgCData(oldp+10,(vlSelfRef.TopLevel__DOT__waddr1),8);
        bufp->chgCData(oldp+11,(vlSelfRef.TopLevel__DOT__PP1__DOT__waddr1Buf),8);
        bufp->chgCData(oldp+12,(vlSelfRef.TopLevel__DOT__PP1__DOT__waddr2Buf),8);
        bufp->chgCData(oldp+13,(vlSelfRef.TopLevel__DOT__PP1__DOT__raddr1Buf),8);
        bufp->chgCData(oldp+14,(vlSelfRef.TopLevel__DOT__PP1__DOT__raddr2Buf),8);
        bufp->chgSData(oldp+15,(vlSelfRef.TopLevel__DOT__wdata1RE),16);
        bufp->chgCData(oldp+16,(vlSelfRef.TopLevel__DOT__PP1__DOT__state),2);
        bufp->chgBit(oldp+17,((7U == (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__raddr1Buf))));
        bufp->chgBit(oldp+18,((7U == (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__waddr1Buf))));
        bufp->chgBit(oldp+19,((IData)((3U == (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__state)))));
        bufp->chgCData(oldp+20,(vlSelfRef.TopLevel__DOT__PP1__DOT__iteratStep),8);
        bufp->chgIData(oldp+21,(vlSelfRef.TopLevel__DOT__bram1IM__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+22,(vlSelfRef.TopLevel__DOT__bram1RE__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+23,(vlSelfRef.TopLevel__DOT__bram2IM__DOT__unnamedblk1__DOT__i),32);
        bufp->chgIData(oldp+24,(vlSelfRef.TopLevel__DOT__bram2RE__DOT__unnamedblk1__DOT__i),32);
        bufp->chgCData(oldp+25,(vlSelfRef.TopLevel__DOT__testInBridge__DOT__state),2);
        bufp->chgCData(oldp+26,(vlSelfRef.TopLevel__DOT__testInBridge__DOT__totCount),3);
    }
    bufp->chgBit(oldp+27,(vlSelfRef.clk));
    bufp->chgBit(oldp+28,(vlSelfRef.startSig));
    bufp->chgSData(oldp+29,(vlSelfRef.ram1Output),16);
    bufp->chgSData(oldp+30,(vlSelfRef.rdata1REO),16);
    bufp->chgSData(oldp+31,(vlSelfRef.rdata1IMO),16);
    bufp->chgSData(oldp+32,(vlSelfRef.rdata2REO),16);
    bufp->chgSData(oldp+33,(vlSelfRef.rdata2IMO),16);
    bufp->chgCData(oldp+34,(vlSelfRef.waddr1Out),8);
    bufp->chgCData(oldp+35,(vlSelfRef.waddr2Out),8);
    bufp->chgBit(oldp+36,(vlSelfRef.TopLevel__DOT__doneSigIB));
    bufp->chgCData(oldp+37,(((2U & (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__state))
                              ? ((1U & (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__state))
                                  ? 0U : ((7U == (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__waddr1Buf))
                                           ? ((IData)(
                                                      (3U 
                                                       == (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__state)))
                                               ? 3U
                                               : 1U)
                                           : 2U)) : 
                             ((1U & (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__state))
                               ? ((7U == (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__raddr1Buf))
                                   ? 2U : 1U) : ((IData)(vlSelfRef.TopLevel__DOT__doneSigIB)
                                                  ? 1U
                                                  : 0U)))),2);
    bufp->chgCData(oldp+38,(vlSelfRef.TopLevel__DOT__testInBridge__DOT__next_state),2);
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
