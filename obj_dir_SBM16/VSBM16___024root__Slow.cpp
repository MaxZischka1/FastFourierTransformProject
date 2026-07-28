// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSBM16.h for the primary calling header

#include "VSBM16__pch.h"

void VSBM16___024root___ctor_var_reset(VSBM16___024root* vlSelf);

VSBM16___024root::VSBM16___024root(VSBM16__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    VSBM16___024root___ctor_var_reset(this);
}

void VSBM16___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VSBM16___024root::~VSBM16___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
