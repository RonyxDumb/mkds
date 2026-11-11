#pragma once

#include "types.h"
#include "00/code_02188ec0.h"
#include "00/code_021a5b3c.h"

// Four words handed to func_ov000_021a629c by DWCi_AC_Start.
typedef struct Unk02189f00 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk02189f00;


u32 SearchEndCheck(ACWORK *object, u32 phase);
u32 NextSearchCheck(ACWORK *object, u32 phase);
u32 SearchStealth(ACWORK *object);
u32 SearchDifferChannel(ACWORK *object);
u32 SearchAround2ndLap(ACWORK *object);
u32 SearchAround(ACWORK *object);
u32 SearchStart(ACWORK *object);
void DWCi_AC_SearchReStart(u32 phase);
s8 DWCi_AC_GetStealthChannel(s32 index);
void DWCi_AC_SetStealthChannel(u32 channel);
u32 DWCi_AC_SearchAP(void);
u8 DWCi_AC_Start(void);
void CheckSetDNS(ACWORK *object);
u32 ConvNetMask(s32 a);
