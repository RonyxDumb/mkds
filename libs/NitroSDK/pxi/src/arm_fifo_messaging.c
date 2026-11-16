#include "arm_fifo_messaging.h"
#include "reset_interrupts_halt.h"
#include "interrupt_control.h"
#include "registers.h"

PXIFifoCallback g_FifoCallbackTable[32];
u16 g_FifoInit;

// Runs once: clears the handle checker word of the ARM9 and the callback table, sets up the receive interrupt for
// FIFONotEmptyIRQHandler, then handshakes with the other processor through the PXI interrupt flags.
void Fifo_Initialize(void) {
    u32 enabled;
    s32 index;
    s32 retriesLeft;
    u32 received;
    s32 count;
    OSSystemWork *systemWork;

    enabled = Os_DisableIrq();
    if (g_FifoInit == 0) {
        g_FifoInit = 1;
        systemWork = SYSTEM_WORK;
        systemWork->mPxiHandleChecker[0] = 0;
        for (index = 0; index < 32; index++) {
            g_FifoCallbackTable[index] = 0;
        }
        reg_PXI_SUBP_FIFO_CNT = 0xc408;
        SetIF(0x40000);
        Os_SetIrqHandler(0x40000, FIFONotEmptyIRQHandler);
        Os_EnableIrqHandler(0x40000);
        count = 0;
        for (;;) {
            received = reg_PXI_SUBPINTF & 0xf;
            reg_PXI_SUBPINTF = received << 8;
            if (received == 0 && count > 4) {
                break;
            }
            retriesLeft = 1000;
            while ((reg_PXI_SUBPINTF & 0xf) == received) {
                if (retriesLeft <= 0) {
                    count = 0;
                    break;
                }
                retriesLeft--;
            }
            count++;
        }
    }
    Os_RestoreIrq(enabled);
}

// Stores callback for fifotag and sets or clears its bit in the ARM9 handle checker word.
void Fifo_RegisterHandler(s32 fifotag, PXIFifoCallback callback) {
    u32 enabled;
    OSSystemWork *systemWork;

    enabled = Os_DisableIrq();
    g_FifoCallbackTable[fifotag] = callback;
    systemWork = SYSTEM_WORK;
    if (callback != 0) {
        BIT_SET(systemWork->mPxiHandleChecker[0], fifotag);
    } else {
        BIT_CLEAR(systemWork->mPxiHandleChecker[0], fifotag);
    }
    Os_RestoreIrq(enabled);
}

// Returns whether the handle checker word of processor proc has the bit of fifotag set.
s32 Fifo_IsHandlerReady(s32 fifotag, s32 proc) {
    OSSystemWork *systemWork;

    systemWork = SYSTEM_WORK;
    return BIT_IS_SET(systemWork->mPxiHandleChecker[proc], fifotag);
}

// Packs fifotag (5 bits), err (1 bit) and data (26 bits) into one word and writes it to the send FIFO.
// Returns -1 when the FIFO error flag is set (cleared here), -2 when the send FIFO is full, 0 on success.
s32 Fifo_SendWord(s32 fifotag, u32 data, s32 err) {
    PxiWord message;
    u32 enabled;

    message.mTag = fifotag;
    message.mErr = err;
    message.mData = data;
    if (reg_PXI_SUBP_FIFO_CNT & 0x4000) {
        reg_PXI_SUBP_FIFO_CNT |= 0xc000;
        return -1;
    }
    enabled = Os_DisableIrq();
    if (reg_PXI_SUBP_FIFO_CNT & 2) {
        Os_RestoreIrq(enabled);
        return -2;
    }
    reg_PXI_SEND_FIFO = message.mWhole;
    Os_RestoreIrq(enabled);
    return 0;
}

// Receive interrupt handler: reads words from the receive FIFO until it is empty and calls the callback of each
// word's tag; a word with no callback and err clear is sent back with err set.
void FIFONotEmptyIRQHandler(void) {
    PxiWord message;
    s32 result;
    u32 enabled;
    PXIFifoCallback callback;

    for (;;) {
        if (reg_PXI_SUBP_FIFO_CNT & 0x4000) {
            reg_PXI_SUBP_FIFO_CNT |= 0xc000;
            result = -3;
        } else {
            enabled = Os_DisableIrq();
            if (reg_PXI_SUBP_FIFO_CNT & 0x100) {
                Os_RestoreIrq(enabled);
                result = -4;
            } else {
                message.mWhole = reg_PXI_RECV_FIFO;
                Os_RestoreIrq(enabled);
                result = 0;
            }
        }
        if (result == -4) {
            return;
        }
        if (result == -3) {
            continue;
        }
        if (message.mTag == 0) {
            continue;
        }
        callback = g_FifoCallbackTable[message.mTag];
        if (callback != 0) {
            callback(message.mTag, message.mData, message.mErr);
            continue;
        }
        if (message.mErr == 0) {
            message.mErr = 1;
            if (reg_PXI_SUBP_FIFO_CNT & 0x4000) {
                reg_PXI_SUBP_FIFO_CNT |= 0xc000;
                continue;
            }
            enabled = Os_DisableIrq();
            if (reg_PXI_SUBP_FIFO_CNT & 2) {
                Os_RestoreIrq(enabled);
            } else {
                reg_PXI_SEND_FIFO = message.mWhole;
                Os_RestoreIrq(enabled);
            }
        }
    }
}

// Calls Fifo_Initialize.
void j_Fifo_Initialize(void) {
    Fifo_Initialize();
}
