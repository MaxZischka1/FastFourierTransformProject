// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "VTopLevel__Syms.h"


VL_ATTR_COLD void VTopLevel___024root__trace_init_sub__TOP__0(VTopLevel___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root__trace_init_sub__TOP__0\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    VL_TRACE_DECL_BIT(tracep,c+4,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+5,0,"startSig",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+6,0,"ram1Output",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"doneSigOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+8,0,"addyOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("TopLevel", VerilatedTracePrefixType::SCOPE_MODULE);
    VL_TRACE_DECL_BIT(tracep,c+4,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+5,0,"startSig",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+6,0,"ram1Output",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"doneSigOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+8,0,"addyOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"addressOutIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"doneSig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    tracep->pushPrefix("EEPROM", VerilatedTracePrefixType::SCOPE_MODULE);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+6,0,"sampleIn",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("testInBridge", VerilatedTracePrefixType::SCOPE_MODULE);
    VL_TRACE_DECL_BIT(tracep,c+5,0,"startSig",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+4,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"address",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"doneSig",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"trans",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"totCount",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void VTopLevel___024root__trace_init_top(VTopLevel___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root__trace_init_top\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VTopLevel___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VTopLevel___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VTopLevel___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTopLevel___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTopLevel___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VTopLevel___024root__trace_register(VTopLevel___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root__trace_register\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VTopLevel___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&VTopLevel___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&VTopLevel___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&VTopLevel___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VTopLevel___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root__trace_const_0\n"); );
    // Body
    VTopLevel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTopLevel___024root*>(voidSelf);
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void VTopLevel___024root__trace_full_0_sub_0(VTopLevel___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTopLevel___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root__trace_full_0\n"); );
    // Body
    VTopLevel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTopLevel___024root*>(voidSelf);
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VTopLevel___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTopLevel___024root__trace_full_0_sub_0(VTopLevel___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root__trace_full_0_sub_0\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullCData(oldp+0,(vlSelfRef.TopLevel__DOT__addressOutIn),8);
    bufp->fullBit(oldp+1,(vlSelfRef.TopLevel__DOT__doneSig));
    bufp->fullBit(oldp+2,(vlSelfRef.TopLevel__DOT__testInBridge__DOT__trans));
    bufp->fullCData(oldp+3,(vlSelfRef.TopLevel__DOT__testInBridge__DOT__totCount),3);
    bufp->fullBit(oldp+4,(vlSelfRef.clk));
    bufp->fullBit(oldp+5,(vlSelfRef.startSig));
    bufp->fullSData(oldp+6,(vlSelfRef.ram1Output),16);
    bufp->fullBit(oldp+7,(vlSelfRef.doneSigOut));
    bufp->fullCData(oldp+8,(vlSelfRef.addyOut),8);
}
