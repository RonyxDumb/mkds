#pragma once

#include "types.h"

typedef struct ACWORK ACWORK;

typedef void *(*SocketAllocFn)(u32 a, u32 b);
typedef void (*SocketFreeFn)(u32 a, void *b, u32 c);

// The two functions MakeSOCConfig copies into SOCConfig.
typedef struct SocketAllocPair {
    /* 00 */ SocketAllocFn mAlloc;
    /* 04 */ SocketFreeFn mFree;
} SocketAllocPair;

// Object behind gNetCheck, 0x58 bytes.
typedef struct SOCConfig {
    /* 00 */ u8 pad_00[4];
    /* 04 */ SocketAllocFn mAlloc;
    /* 08 */ SocketFreeFn mFree;
    /* 0c */ s32 mFlag;
    /* 10 */ u32 mAddr;
    /* 14 */ u32 mNetmask;
    /* 18 */ u32 mRouter;
    /* 1c */ u32 mDns1;
    /* 20 */ u32 mDns2;
    /* 24 */ u8 pad_24[8];
    /* 2c */ s32 mMtu;
    /* 30 */ s32 mRwin;
    /* 34 */ u8 pad_34[0x24];
} SOCConfig;

void MakeSOCConfig(const SocketAllocPair *hold, ACWORK *object, SOCConfig *out);
