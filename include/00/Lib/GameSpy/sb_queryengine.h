#pragma once

#include "types.h"
#include "00/Lib/GameSpy/sb_internal.h"

typedef struct SbServer SbServer;
typedef struct SBQueryEngine SBQueryEngine;
typedef struct MatchingServerList MatchingServerList;

void SBQueryEngineRemoveServerFromFIFOs(MatchingServerList *matchingServerList, SbServer *server);
void SBQueryEngineAddQueryKey(SBQueryEngine *engine, u8 keyId);
void SBQueryEngineThink(MatchingServerList *matchingServerList);
void QueueNextQueries(SBQueryEngine *engine);

struct SBQueryEngine;

typedef void (*SBEngineCallback)(void *engine, s32 reason, SbServer *server, void *instance);

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
    /* 44 */ SBEngineCallback mListCallback;
    /* 48 */ void *mInstance;
} SBQueryEngine;

void TimeoutOldQueries(SBQueryEngine *engine);
void ProcessIncomingReplies(SBQueryEngine *engine, s32 probeSocket);

typedef struct SbServer SbServer;
typedef struct SBQueryEngine SBQueryEngine;

BOOL ParseSingleICMPReply(SBQueryEngine *engine, SbServer *server, s8 *buf, s32 length);

typedef struct SbServer SbServer;
typedef struct SBQueryEngine SBQueryEngine;

void ParseSingleGOAReply(SBQueryEngine *engine, SbServer *server, s8 *buf, s32 length);
void ParseSingleQR2Reply(SBQueryEngine *engine, SbServer *server, s8 *buf, s32 length);
void SBQueryEngineUpdateServer(SBQueryEngine *engine, SbServer *server, s32 atFront, s32 updateKind);

typedef struct MatchingServerList MatchingServerList;

void SBEngineCleanup(MatchingServerList *matchingServerList);
void SBEngineHaltUpdates(MatchingServerList *matchingServerList);
void SBQueryEngineSetPublicIP(MatchingServerList *matchingServerList, u32 publicIp);

typedef struct SbServer SbServer;
typedef struct SBQueryEngine SBQueryEngine;

void SBQueryEngineInit(SBQueryEngine *engine, s32 updateLimit, u32 queryVersion, s32 lanBrowse,
                       SBEngineCallback callback, void *instance);
void QEStartQuery(SBQueryEngine *engine, SbServer *server);

typedef struct SBServerFIFO SBServerFIFO;

void FIFOClear(SBServerFIFO *fifo);
void FIFOAddRear(SBServerFIFO *fifo, SbServer *server);
void FIFOAddFront(SBServerFIFO *fifo, SbServer *server);
SbServer *FIFOGetFirst(SBServerFIFO *fifo);

typedef struct SbServer SbServer;
typedef struct SBServerFIFO SBServerFIFO;

BOOL FIFORemove(SBServerFIFO *fifo, SbServer *server);
