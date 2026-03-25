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
    VL_OUT8(doneSigOut,0,0);
    VL_OUT8(addyOut,7,0);
    CData/*7:0*/ TopLevel__DOT__addressOutIn;
    CData/*0:0*/ TopLevel__DOT__doneSig;
    CData/*0:0*/ TopLevel__DOT__testInBridge__DOT__trans;
    CData/*2:0*/ TopLevel__DOT__testInBridge__DOT__totCount;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    VL_OUT16(ram1Output,15,0);
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
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
