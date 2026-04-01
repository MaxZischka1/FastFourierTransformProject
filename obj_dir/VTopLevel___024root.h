// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTopLevel.h for the primary calling header

#ifndef VERILATED_VTOPLEVEL___024ROOT_H_
#define VERILATED_VTOPLEVEL___024ROOT_H_  // guard

#include "verilated.h"


class VTopLevel__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTopLevel___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(startSig,0,0);
    VL_OUT8(waddr1Out,7,0);
    CData/*0:0*/ TopLevel__DOT__doneSigIB;
    CData/*0:0*/ TopLevel__DOT__change;
    CData/*0:0*/ TopLevel__DOT__weADDRen1;
    CData/*0:0*/ TopLevel__DOT__weADDRen2;
    CData/*7:0*/ TopLevel__DOT__addressOutIn;
    CData/*7:0*/ TopLevel__DOT__waddr1;
    CData/*1:0*/ TopLevel__DOT__testInBridge__DOT__state;
    CData/*1:0*/ TopLevel__DOT__testInBridge__DOT__next_state;
    CData/*2:0*/ TopLevel__DOT__testInBridge__DOT__totCount;
    CData/*1:0*/ TopLevel__DOT__PP1__DOT__state;
    CData/*1:0*/ TopLevel__DOT__PP1__DOT__next_state;
    CData/*7:0*/ TopLevel__DOT__PP1__DOT__waddr1Buf;
    CData/*7:0*/ TopLevel__DOT__PP1__DOT__waddr2Buf;
    CData/*7:0*/ TopLevel__DOT__PP1__DOT__raddr1Buf;
    CData/*7:0*/ TopLevel__DOT__PP1__DOT__raddr2Buf;
    CData/*7:0*/ TopLevel__DOT__PP1__DOT__iteratStep;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    VL_OUT16(ram1Output,15,0);
    VL_OUT16(rdata1REO,15,0);
    VL_OUT16(rdata1IMO,15,0);
    VL_OUT16(rdata2REO,15,0);
    VL_OUT16(rdata2IMO,15,0);
    SData/*15:0*/ TopLevel__DOT__BFUoutRE;
    SData/*15:0*/ TopLevel__DOT__BFUoutIM;
    SData/*15:0*/ TopLevel__DOT__rdata1RE;
    SData/*15:0*/ TopLevel__DOT__rdata1IM;
    SData/*15:0*/ TopLevel__DOT__rdata2RE;
    SData/*15:0*/ TopLevel__DOT__rdata2IM;
    SData/*15:0*/ TopLevel__DOT__wdata1RE;
    IData/*31:0*/ TopLevel__DOT__bram1RE__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ TopLevel__DOT__bram1IM__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ TopLevel__DOT__bram2RE__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ TopLevel__DOT__bram2IM__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<SData/*15:0*/, 256> TopLevel__DOT__bram1RE__DOT__internal;
    VlUnpacked<SData/*15:0*/, 256> TopLevel__DOT__bram1IM__DOT__internal;
    VlUnpacked<SData/*15:0*/, 256> TopLevel__DOT__bram2RE__DOT__internal;
    VlUnpacked<SData/*15:0*/, 256> TopLevel__DOT__bram2IM__DOT__internal;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    VTopLevel__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VTopLevel___024root(VTopLevel__Syms* symsp, const char* namep);
    ~VTopLevel___024root();
    VL_UNCOPYABLE(VTopLevel___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
