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
    VL_TRACE_DECL_BIT(tracep,c+6,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"startSig",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+8,0,"ram1Output",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+9,0,"doneSigOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+10,0,"bridgeaddyOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+11,0,"rdataout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+12,0,"PPaddyOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("TopLevel", VerilatedTracePrefixType::SCOPE_MODULE);
    VL_TRACE_DECL_BIT(tracep,c+6,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"startSig",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+8,0,"ram1Output",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+9,0,"doneSigOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+10,0,"bridgeaddyOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+11,0,"rdataout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+12,0,"PPaddyOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"addressOutIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+13,0,"doneSig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"raddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+2,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    tracep->pushPrefix("EEPROM", VerilatedTracePrefixType::SCOPE_MODULE);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+8,0,"sampleIn",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("PP1", VerilatedTracePrefixType::SCOPE_MODULE);
    VL_TRACE_DECL_BUS(tracep,c+17,0,"SAMPLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+6,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+13,0,"startSig",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+14,0,"next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("bram1", VerilatedTracePrefixType::SCOPE_MODULE);
    VL_TRACE_DECL_BUS(tracep,c+8,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+15,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+6,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"raddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+2,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("testInBridge", VerilatedTracePrefixType::SCOPE_MODULE);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"startSig",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+6,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"address",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+13,0,"doneSig",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+4,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+16,0,"next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+5,0,"totCount",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
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

VL_ATTR_COLD void VTopLevel___024root__trace_const_0_sub_0(VTopLevel___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTopLevel___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root__trace_const_0\n"); );
    // Body
    VTopLevel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTopLevel___024root*>(voidSelf);
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VTopLevel___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTopLevel___024root__trace_const_0_sub_0(VTopLevel___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTopLevel___024root__trace_const_0_sub_0\n"); );
    VTopLevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+17,(8U),32);
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
    bufp->fullCData(oldp+1,(vlSelfRef.TopLevel__DOT__PP1__DOT__counter),8);
    bufp->fullSData(oldp+2,(vlSelfRef.TopLevel__DOT__rdata),16);
    bufp->fullCData(oldp+3,(vlSelfRef.TopLevel__DOT__PP1__DOT__state),2);
    bufp->fullCData(oldp+4,(vlSelfRef.TopLevel__DOT__testInBridge__DOT__state),2);
    bufp->fullCData(oldp+5,(vlSelfRef.TopLevel__DOT__testInBridge__DOT__totCount),3);
    bufp->fullBit(oldp+6,(vlSelfRef.clk));
    bufp->fullBit(oldp+7,(vlSelfRef.startSig));
    bufp->fullSData(oldp+8,(vlSelfRef.ram1Output),16);
    bufp->fullBit(oldp+9,(vlSelfRef.doneSigOut));
    bufp->fullCData(oldp+10,(vlSelfRef.bridgeaddyOut),8);
    bufp->fullSData(oldp+11,(vlSelfRef.rdataout),16);
    bufp->fullCData(oldp+12,(vlSelfRef.PPaddyOut),8);
    bufp->fullBit(oldp+13,(vlSelfRef.TopLevel__DOT__doneSig));
    bufp->fullCData(oldp+14,(((0U == (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__state))
                               ? ((IData)(vlSelfRef.TopLevel__DOT__doneSig)
                                   ? 1U : 0U) : ((1U 
                                                  == (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__state))
                                                  ? 
                                                 ((7U 
                                                   == (IData)(vlSelfRef.TopLevel__DOT__PP1__DOT__counter))
                                                   ? 2U
                                                   : 1U)
                                                  : 0U))),2);
    bufp->fullBit(oldp+15,((1U & (~ (IData)(vlSelfRef.TopLevel__DOT__doneSig)))));
    bufp->fullCData(oldp+16,(vlSelfRef.TopLevel__DOT__testInBridge__DOT__next_state),2);
}
