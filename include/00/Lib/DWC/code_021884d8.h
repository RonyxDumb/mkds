#pragma once

#include "types.h"
#include "00/Lib/DWC/code_0218a064.h"

// Object behind gAcHold.
typedef struct ACHOLD {
    /* 00 */ SocketAllocFn mAlloc;
    /* 04 */ SocketFreeFn mFree;
    /* 08 */ u8 mAllocState;
    /* 09 */ u8 mPhase;
    /* 0a */ u8 mErrorPhase;
    /* 0b */ u8 mBeaconReceived;
    /* 0c */ u32 mError;
    /* 10 */ s32 mErrorTest;
    /* 14 */ u8 mEndState;
    /* 15 */ u8 mEndType;
    /* 16 */ u8 mEndSequence;
    /* 17 */ u8 mApType;
} ACHOLD;

u8 DWCi_ConvConnectAPType(u8 apType);
void SetAcHoldApType(u8 apType);
u32 DWCi_AC_GetError(void);
void DWCi_AC_SetError(u32 error);
u8 DWCi_AC_GetPhase(void);
void DWCi_AC_SetPhase(u8 phase);
void *DWCi_AC_GetMemPtr(u32 name);
void DWCi_AC_FreeAll(void);
