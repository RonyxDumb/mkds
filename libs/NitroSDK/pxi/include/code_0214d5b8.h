#pragma once

#include "types.h"

// The word sent through the FIFO: tag, err flag and data.
typedef union PxiWord {
    struct {
        /* 00 */ u32 mTag : 5;
        /* 00 */ u32 mErr : 1;
        /* 00 */ u32 mData : 26;
    };
    u32 mWhole;
} PxiWord;

// Callback for a FIFO tag: called with the tag, the data and the err flag. Left unprototyped because the game's
// callbacks declare fewer or different parameter types.
typedef void (*PXIFifoCallback)();

extern PXIFifoCallback FifoRecvCallbackTable[32];
extern u16 FifoCtrlInit;

void PXI_Init(void);
void PXIi_HandlerRecvFifoNotEmpty(void);
s32 PXI_SendWordByFifo(s32 fifotag, u32 data, s32 err);
s32 PXI_IsCallbackReady(s32 fifotag, s32 proc);
void PXI_SetFifoRecvCallback(s32 fifotag, PXIFifoCallback callback);
void PXI_InitFifo(void);
