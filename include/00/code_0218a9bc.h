#pragma once

#include "types.h"

struct SBQueryEngine;

// 0x24 bytes allocated by func_ov000_0218af28.
typedef struct SbServer {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u16 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u8 mUnk_14;
    /* 15 */ u8 mUnk_15;
    /* 18 */ struct Hashtable *mKeyValues;
    /* 1c */ u32 mPing;
    /* 20 */ struct SbServer *mUnk_20;
} SbServer;

typedef struct SBServerFIFO {
    /* 00 */ SbServer *mFirst;
    /* 04 */ SbServer *mLast;
    /* 08 */ s32 mCount;
} SBServerFIFO;

typedef struct SBQueryEngine {
    /* 00 */ u32 mQueryVersion;
    /* 04 */ s32 mMaxUpdates;
    /* 08 */ SBServerFIFO mQueryList;
    /* 14 */ SBServerFIFO mPendingList;
    /* 20 */ s32 mQuerySock;
    /* 24 */ s32 mIcmpSock;
    /* 28 */ u32 mMyPublicIp;
    /* 2c */ u8 mServerKeys[0x14];
    /* 40 */ s32 mNumServerKeys;
    /* 44 */ UnkFunc *mListCallback;
    /* 48 */ void *mInstance;
} SBQueryEngine;

typedef struct Unk0218aa14 {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk0218aa14;

void TimeoutOldQueries(SBQueryEngine *engine);
void ProcessIncomingReplies(SBQueryEngine *engine, s32 probeSocket);
