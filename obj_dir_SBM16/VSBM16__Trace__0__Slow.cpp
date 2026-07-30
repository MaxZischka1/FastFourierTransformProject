// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "VSBM16__Syms.h"


VL_ATTR_COLD void VSBM16___024root__trace_init_sub__TOP__0(VSBM16___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root__trace_init_sub__TOP__0\n"); );
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"d1InRE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+3,0,"d1InIM",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+4,0,"WInRE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+5,0,"WInIM",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+6,0,"d2InRE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+7,0,"d2InIM",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+8,0,"dataOutRE32",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"dataOutIM32",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("SBM16", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"d1InRE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+3,0,"d1InIM",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+4,0,"WInRE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+5,0,"WInIM",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+6,0,"d2InRE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+7,0,"d2InIM",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+8,0,"dataOutRE32",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"dataOutIM32",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"dataOutRE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+11,0,"dataOutIM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declQuad(c+12,0,"interMedRE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+14,0,"interMedIM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+16,0,"sumRE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+17,0,"sumIM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void VSBM16___024root__trace_init_top(VSBM16___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root__trace_init_top\n"); );
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VSBM16___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VSBM16___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VSBM16___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VSBM16___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VSBM16___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VSBM16___024root__trace_register(VSBM16___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root__trace_register\n"); );
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VSBM16___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&VSBM16___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&VSBM16___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&VSBM16___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VSBM16___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root__trace_const_0\n"); );
    // Body
    VSBM16___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSBM16___024root*>(voidSelf);
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void VSBM16___024root__trace_full_0_sub_0(VSBM16___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VSBM16___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root__trace_full_0\n"); );
    // Body
    VSBM16___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VSBM16___024root*>(voidSelf);
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VSBM16___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VSBM16___024root__trace_full_0_sub_0(VSBM16___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSBM16___024root__trace_full_0_sub_0\n"); );
    VSBM16__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+1,(vlSelfRef.clk));
    bufp->fullSData(oldp+2,(vlSelfRef.d1InRE),16);
    bufp->fullSData(oldp+3,(vlSelfRef.d1InIM),16);
    bufp->fullSData(oldp+4,(vlSelfRef.WInRE),16);
    bufp->fullSData(oldp+5,(vlSelfRef.WInIM),16);
    bufp->fullSData(oldp+6,(vlSelfRef.d2InRE),16);
    bufp->fullSData(oldp+7,(vlSelfRef.d2InIM),16);
    bufp->fullIData(oldp+8,(vlSelfRef.dataOutRE32),32);
    bufp->fullIData(oldp+9,(vlSelfRef.dataOutIM32),32);
    bufp->fullSData(oldp+10,((0x0000ffffU & ((VL_EXTENDS_II(17,16, 
                                                            (0x0000ffffU 
                                                             & (IData)(
                                                                       (0x000000000000ffffULL 
                                                                        & ((VL_MULS_QQQ(33, 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InRE))), 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInRE)))) 
                                                                            - 
                                                                            VL_MULS_QQQ(33, 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InIM))), 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInIM))))) 
                                                                           >> 0x00000011U))))) 
                                              + VL_EXTENDS_II(17,16, (IData)(vlSelfRef.d2InRE))) 
                                             >> 1U))),16);
    bufp->fullSData(oldp+11,((0x0000ffffU & ((VL_EXTENDS_II(17,16, 
                                                            (0x0000ffffU 
                                                             & (IData)(
                                                                       (0x000000000000ffffULL 
                                                                        & ((VL_MULS_QQQ(33, 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InRE))), 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInIM)))) 
                                                                            + 
                                                                            VL_MULS_QQQ(33, 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InIM))), 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInRE))))) 
                                                                           >> 0x00000011U))))) 
                                              + VL_EXTENDS_II(17,16, (IData)(vlSelfRef.d2InIM))) 
                                             >> 1U))),16);
    bufp->fullQData(oldp+12,((0x00000001ffffffffULL 
                              & (VL_MULS_QQQ(33, (0x00000001ffffffffULL 
                                                  & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InRE))), 
                                             (0x00000001ffffffffULL 
                                              & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInRE)))) 
                                 - VL_MULS_QQQ(33, 
                                               (0x00000001ffffffffULL 
                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InIM))), 
                                               (0x00000001ffffffffULL 
                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInIM))))))),33);
    bufp->fullQData(oldp+14,((0x00000001ffffffffULL 
                              & (VL_MULS_QQQ(33, (0x00000001ffffffffULL 
                                                  & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InRE))), 
                                             (0x00000001ffffffffULL 
                                              & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInIM)))) 
                                 + VL_MULS_QQQ(33, 
                                               (0x00000001ffffffffULL 
                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InIM))), 
                                               (0x00000001ffffffffULL 
                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInRE))))))),33);
    bufp->fullIData(oldp+16,((0x0001ffffU & (VL_EXTENDS_II(17,16, 
                                                           (0x0000ffffU 
                                                            & (IData)(
                                                                      (0x000000000000ffffULL 
                                                                       & ((VL_MULS_QQQ(33, 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InRE))), 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInRE)))) 
                                                                           - 
                                                                           VL_MULS_QQQ(33, 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InIM))), 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInIM))))) 
                                                                          >> 0x00000011U))))) 
                                             + VL_EXTENDS_II(17,16, (IData)(vlSelfRef.d2InRE))))),17);
    bufp->fullIData(oldp+17,((0x0001ffffU & (VL_EXTENDS_II(17,16, 
                                                           (0x0000ffffU 
                                                            & (IData)(
                                                                      (0x000000000000ffffULL 
                                                                       & ((VL_MULS_QQQ(33, 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InRE))), 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInIM)))) 
                                                                           + 
                                                                           VL_MULS_QQQ(33, 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.d1InIM))), 
                                                                                (0x00000001ffffffffULL 
                                                                                & VL_EXTENDS_QI(33,16, (IData)(vlSelfRef.WInRE))))) 
                                                                          >> 0x00000011U))))) 
                                             + VL_EXTENDS_II(17,16, (IData)(vlSelfRef.d2InIM))))),17);
}
