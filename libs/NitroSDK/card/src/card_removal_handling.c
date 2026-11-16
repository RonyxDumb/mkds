#include "card_removal_handling.h"
#include "registers.h"
#include "reset_interrupts_halt.h"
#include "arm_fifo_messaging.h"
#include "power_management_commands.h"
#include "bios_calls.h"

CARDPulledOutCallback g_Card_UserCardPulledOutCallback;
u32 g_Card_IsPulledOut;

// Installs Card_CardPulledOutHandler on tag 14 and clears the user callback.
void Card_InitializePulledOutCallback(void) {
    j_Fifo_Initialize();
    Fifo_RegisterHandler(14, Card_CardPulledOutHandler);
    g_Card_UserCardPulledOutCallback = 0;
}

// Tag 14 callback: on the pulled-out command sets g_Card_IsPulledOut, calls the user callback and ends the program when there
// is none or it returns non-zero. Any other command ends in Os_Terminate.
void Card_CardPulledOutHandler(u32 tag, u32 data) {
    u32 terminate;
    CARDPulledOutCallback callback;

    if ((data & 0x3F) == 0x11) {
        callback = g_Card_UserCardPulledOutCallback;
        g_Card_IsPulledOut = 1;
        terminate = 1;
        if (callback != 0) {
            terminate = callback();
        }
        if (terminate != 0) {
            Card_TerminateForPulledOut();
        }
    } else {
        Os_Terminate();
    }
}

// Sets the user callback.
void Card_SetUserCardPulledOutCallback(CARDPulledOutCallback callback) {
    g_Card_UserCardPulledOutCallback = callback;
}

// Returns 1 once a card removal was reported.
u32 Card_IsPulledOut(void) {
    return g_Card_IsPulledOut;
}

void Card_TerminateForPulledOut(void) {
    if (((s32) (*HW_BUTTON_XY_BUF & PAD_DETECT_FOLD_MASK)) >> 15 != 0) {
        PM_ForceToPowerOff();
    }
    Card_SendToFifo(1, 1);
    Os_Terminate();
}

// Sends the word on tag 14, waiting and trying again until it is accepted.
void Card_SendToFifo(u32 data, s32 wait) {
    while (Fifo_SendWord(14, data, 0) != 0) {
        Svc_Delay_from_thumb(wait);
    }
}
