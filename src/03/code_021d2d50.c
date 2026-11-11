#include "03/code_021d2d50.h"
#include "03/code_021d27d8.h"
#include "03/code_021d2940.h"
#include "03/code_021d3000.h"
#include "03/unk_021da000.h"
#include "code_0200c914.h"
#include "code_0200fc8c.h"
#include "tp.h"
#include "registers.h"

void EnableTaskVBlankIrq(void) {
    u16 previousIme;

    gSavedIrqMask = reg_OS_IE;
    OS_SetIrqMask(0x40018);
    OS_EnableIrqMask(1);
    gSavedIrqFunction = OS_GetIrqFunction(1);
    OS_SetIrqFunction(1, TaskVBlankIrqHandler);
    previousIme = reg_OS_IME;
    reg_OS_IME = 1;
    OS_EnableInterrupts();
}

void RestoreTaskVBlankIrq(void) {
    u16 previousIme;

    previousIme = reg_OS_IME;
    reg_OS_IME = 0;
    OS_SetIrqMask(gSavedIrqMask);
    OS_SetIrqFunction(1, gSavedIrqFunction);
}

void TaskVBlankIrqHandler(void) {
    RunTasksAndRemoveRequested(1);
    *OFFSET_PTR(u32, &gDtcmData, 0x3ff8) |= 1;
}

void InitKeyTouchInput(void) {
    TPCalibrateParam calibration;

    gKeyTouchInput = AllocZeroedExpHeapBlock(0x3a, 4);
    if (TP_GetUserInfo(&calibration) == 0) {
        OS_Terminate();
    }
    TP_SetCalibrateParam(&calibration);
    TP_RequestAutoSamplingStartAsync(0, 4, gKeyTouchInput->mTouchSamples, 5);
    TP_WaitBusy(2);
    if (TP_CheckError(2) != 0) {
        OS_Terminate();
    }
    UpdateKeyTouchInput();
}
