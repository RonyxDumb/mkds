#pragma once

#include "types.h"

// Object behind gAcHold.
typedef struct ACHOLD {
    /* 00 */ void *(*mUnk_00)();
    /* 04 */ void (*mUnk_04)();
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u8 mUnk_0a;
    /* 0b */ u8 mUnk_0b;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u8 pad_10[4];
    /* 14 */ u8 mUnk_14;
    /* 15 */ u8 mUnk_15;
    /* 16 */ u8 mUnk_16;
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
