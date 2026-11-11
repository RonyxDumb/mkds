#pragma once

#include "types.h"

// Entry of the list at negotiateList, 0x40 bytes.
typedef struct NatTraversalEntry {
    /* 00 */ s32 mDescriptor;
    /* 04 */ s32 mGameSock;
    /* 08 */ u32 mCookie;
    /* 0c */ u32 mClientIndex;
    /* 10 */ s32 mState;
    /* 14 */ u32 mInitAckRecv[3];
    /* 20 */ s32 mRetryCount;
    /* 24 */ s32 mMaxRetryCount;
    /* 28 */ u32 mRetryTime;
    /* 2c */ u32 mGuessedIP;
    /* 30 */ u16 mGuessedPort;
    /* 32 */ u8 mGotRemoteData;
    /* 33 */ u8 mSendGotRemoteData;
    /* 34 */ void (*mProgressCallback)(s32 a, void *b);
    /* 38 */ void (*mCompletedCallback)(s32 a, s32 b, void *c, void *d);
    /* 3c */ void *mUserdata;
} NatTraversalEntry;

void NegotiatorFree(NatTraversalEntry *negotiator);
