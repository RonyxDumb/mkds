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

extern PXIFifoCallback g_FifoCallbackTable[32];
extern u16 g_FifoInit;

void j_Fifo_Initialize(void);
void FIFONotEmptyIRQHandler(void);
s32 Fifo_SendWord(s32 fifotag, u32 data, s32 err);
s32 Fifo_IsHandlerReady(s32 fifotag, s32 proc);
void Fifo_RegisterHandler(s32 fifotag, PXIFifoCallback callback);
void Fifo_Initialize(void);
