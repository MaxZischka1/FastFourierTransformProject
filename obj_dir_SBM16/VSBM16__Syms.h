// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSBM16__SYMS_H_
#define VERILATED_VSBM16__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VSBM16.h"

// INCLUDE MODULE CLASSES
#include "VSBM16___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) VSBM16__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VSBM16* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VSBM16___024root               TOP;

    // CONSTRUCTORS
    VSBM16__Syms(VerilatedContext* contextp, const char* namep, VSBM16* modelp);
    ~VSBM16__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
