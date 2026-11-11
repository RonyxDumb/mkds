#pragma once

#include "types.h"

typedef struct ACWORK ACWORK;

// Object behind gNetCheck, 0x58 bytes.
typedef struct SOCConfig {
    /* 00 */ u8 pad_00[4];
    /* 04 */ u32 mAlloc;
    /* 08 */ u32 mFree;
    /* 0c */ u32 mFlag;
    /* 10 */ u32 mAddr;
    /* 14 */ u32 mNetmask;
    /* 18 */ u32 mRouter;
    /* 1c */ u32 mDns1;
    /* 20 */ u32 mDns2;
    /* 24 */ u8 pad_24[0x34];
} SOCConfig;

void MakeSOCConfig(const u32 *hold, ACWORK *object, SOCConfig *out);
