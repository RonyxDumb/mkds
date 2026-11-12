#include "card_pullOut.h"
#include "Main/Unknown/unk_02180000.h"
#include "code_0200fc8c.h"
#include "code_0214d5b8.h"
#include "pm.h"
#include "Main/Unknown/code_02000000.h"
#include "code_0200007e.h"

UnkWordFunc *gRemovalCallback;
u32 gRemovalSeen;

// Installs CARDi_PulledOutCallback on tag 14 and clears the user callback.
void CARD_InitPulledOutCallback(void) {
    PXI_Init();
    PXI_SetFifoRecvCallback(14, CARDi_PulledOutCallback);
    gRemovalCallback = 0;
}

// Tag 14 callback: on the pulled-out command sets gRemovalSeen, calls the user callback and ends the program when there
// is none or it returns non-zero. Any other command ends in OS_Terminate.
void CARDi_PulledOutCallback(u32 tag, u32 data) {
    u32 terminate;
    UnkWordFunc *callback;

    if ((data & 0x3F) == 0x11) {
        callback = gRemovalCallback;
        gRemovalSeen = 1;
        terminate = 1;
        if (callback != 0) {
            terminate = callback();
        }
        if (terminate != 0) {
            CARD_TerminateForPulledOut();
        }
    } else {
        OS_Terminate();
    }
}

// Sets the user callback.
void CARD_SetPulledOutCallback(void *callback) {
    gRemovalCallback = callback;
}

// Returns 1 once a card removal was reported.
u32 CARD_IsPulledOut(void) {
    return gRemovalSeen;
}

void CARD_TerminateForPulledOut(void) {
    if (((s32) (*(vu16 *) 0x027FFFA8 & 0x8000)) >> 15 != 0) {
        PM_ForceToPowerOff();
    }
    CARDi_SendtoPxi(1, 1);
    OS_Terminate();
}

// Sends the word on tag 14, waiting and trying again until it is accepted.
void CARDi_SendtoPxi(u32 data, s32 wait) {
    while (PXI_SendWordByFifo(14, data, 0) != 0) {
        WaitByLoop(wait);
    }
}
