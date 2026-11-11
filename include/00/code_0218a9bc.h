#pragma once

#include "types.h"

struct SBQueryEngine;

// 0x24 bytes allocated by SBAllocServer.
typedef struct SbServer {
    /* 00 */ u32 mPublicIp;
    /* 04 */ u16 mPublicPort;
    /* 08 */ u32 mPrivateIp;
    /* 0c */ u16 mPrivatePort;
    /* 10 */ u32 mIcmpIp;
    /* 14 */ u8 mStateFlags;
    /* 15 */ u8 mFlags;
    /* 18 */ struct Hashtable *mKeyValues;
    /* 1c */ u32 mPing;
    /* 20 */ struct SbServer *mNext;
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

void TimeoutOldQueries(SBQueryEngine *engine);
void ProcessIncomingReplies(SBQueryEngine *engine, s32 probeSocket);
