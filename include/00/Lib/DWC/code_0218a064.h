#pragma once

#include "types.h"

typedef struct ACWORK ACWORK;
typedef struct ACHOLD ACHOLD;

typedef void *(*SocketAllocFn)(u32 name, u32 size);
typedef void (*SocketFreeFn)(u32 name, void *block, u32 size);

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
    /* 24 */ s32 mTimeWaitBuffer;
    /* 28 */ s32 mReassemblyBuffer;
    /* 2c */ s32 mMtu;
    /* 30 */ s32 mRwin;
    /* 34 */ u8 pad_34[0x14];
    /* 48 */ const char *mHostName;
    /* 4c */ s32 mRdhcp;
    /* 50 */ s32 mUdpSendBuff;
    /* 54 */ s32 mUdpRecvBuff;
} SOCConfig;

void MakeSOCConfig(const ACHOLD *hold, ACWORK *object, SOCConfig *out);

extern const SOCConfig gAcSocConfig;
