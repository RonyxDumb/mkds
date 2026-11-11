#pragma once

#include "types.h"

// Object behind gAcHold.
typedef struct ACHOLD {
    /* 00 */ void *(*mAlloc)();
    /* 04 */ void (*mFree)();
    /* 08 */ u8 mAllocState;
    /* 09 */ u8 mPhase;
    /* 0a */ u8 mUnk_0a;
    /* 0b */ u8 mUnk_0b;
    /* 0c */ u32 mError;
    /* 10 */ u8 pad_10[4];
    /* 14 */ u8 mEndState;
    /* 15 */ u8 mEndType;
    /* 16 */ u8 mEndSequence;
    /* 17 */ u8 mUnk_17;
} ACHOLD;

u8 DWCi_ConvConnectAPType(u8 apType);
void SetAcHoldApType(u8 apType);
u32 DWCi_AC_GetError(void);
void DWCi_AC_SetError(u32 error);
u8 DWCi_AC_GetPhase(void);
void DWCi_AC_SetPhase(u8 phase);
u32 DWCi_AC_GetMemPtr(u32 name);
void DWCi_AC_FreeAll(void);
