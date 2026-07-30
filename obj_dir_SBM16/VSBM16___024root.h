// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VSBM16.h for the primary calling header

#ifndef VERILATED_VSBM16___024ROOT_H_
#define VERILATED_VSBM16___024ROOT_H_  // guard

#include "verilated.h"


class VSBM16__Syms;

class alignas(VL_CACHE_LINE_BYTES) VSBM16___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    VL_IN16(d1InRE,15,0);
    VL_IN16(d1InIM,15,0);
    VL_IN16(WInRE,15,0);
    VL_IN16(WInIM,15,0);
    VL_IN16(d2InRE,15,0);
    VL_IN16(d2InIM,15,0);
    VL_OUT(dataOutRE32,31,0);
    VL_OUT(dataOutIM32,31,0);
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VSBM16__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VSBM16___024root(VSBM16__Syms* symsp, const char* namep);
    ~VSBM16___024root();
    VL_UNCOPYABLE(VSBM16___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
