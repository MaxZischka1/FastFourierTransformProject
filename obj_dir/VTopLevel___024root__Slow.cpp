// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTopLevel.h for the primary calling header

#include "VTopLevel__pch.h"

void VTopLevel___024root___ctor_var_reset(VTopLevel___024root* vlSelf);

VTopLevel___024root::VTopLevel___024root(VTopLevel__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    VTopLevel___024root___ctor_var_reset(this);
}

void VTopLevel___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VTopLevel___024root::~VTopLevel___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
