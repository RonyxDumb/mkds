#include "Main/Menu/logo_state.h"
#include "Main/Net/multiboot_parent_finish.h"
#include "Main/Menu/logo_state_8_nop.h"
#include "Main/Menu/logo_state_2.h"
#include "Main/Menu/logo_state_1_nop.h"
#include "Main/Menu/logo_scene.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/txt_system.h"

// Initialized data kept in .text between two functions.
#pragma define_section MAIN_TEXT ".text"                                                                               \
                                 ".bss" abs32 RWX
#pragma section MAIN_TEXT begin

StateCallbacks gLogoStateTable[12] = {
    {EnterLogoState0, UpdateLogoState0}, {EnterLogoState1Nop, UpdateLogoState1}, {EnterLogoState2, UpdateLogoState2},
    {EnterLogoState3, UpdateLogoState3}, {EnterLogoState4, UpdateLogoState4},    {EnterLogoState5, UpdateLogoState5},
    {EnterLogoState6, UpdateLogoState6}, {EnterLogoState7, UpdateLogoState7},    {EnterLogoState8Nop, UpdateLogoState8},
    {EnterLogoState9, UpdateLogoState9}, {EnterLogoState10, UpdateLogoState10},  {NULL, NULL},
};

#pragma section MAIN_TEXT end

void UpdateLogoState8(void) {
    StateMachine *stateMachine;
    if (data_usa_02174e54 == 3) {
        stateMachine = &gLogoScene->mStateMachine;
        stateMachine->mNextState = 9;
        stateMachine->mNextStateRequested = 1;
        return;
    }
    stateMachine = &gLogoScene->mStateMachine;
    stateMachine->mNextState = 11;
    stateMachine->mNextStateRequested = 1;
}

void EnterLogoState9(void) {
    void *message;
    message = GetBmgEntry(gLogoScene->mCommonMessages, 137);
    SetupTxtSystemSubTextButton(message, GetBmgEntry(gLogoScene->mCommonMessages, 6));
}

void UpdateLogoState9(void) {
    StateMachine *stateMachine;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    stateMachine = &gLogoScene->mStateMachine;
    stateMachine->mNextState = 10;
    stateMachine->mNextStateRequested = 1;
}

void EnterLogoState10(void) {
    void *message;
    message = GetBmgEntry(gLogoScene->mCommonMessages, 138);
    SetupTxtSystemSubTextButton(message, GetBmgEntry(gLogoScene->mCommonMessages, 4));
}

void UpdateLogoState10(void) {
    StateMachine *stateMachine;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    stateMachine = &gLogoScene->mStateMachine;
    stateMachine->mNextState = 11;
    stateMachine->mNextStateRequested = 1;
}
