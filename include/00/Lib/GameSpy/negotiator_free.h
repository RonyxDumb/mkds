#pragma once

#include "types.h"

// Values of NatTraversalEntry.mState: sending the init packets until all acks arrive; waiting up to 10 seconds for the
// connect packet that gives the address to ping; pinging that address until a ping answers with the got-data flag set;
// ping answered (the entry is cancelled after a delay); cancelled (removed by the next think). The progress callback is
// called with WAIT_CONNECT and PING.
enum {
    NAT_NEGOTIATION_SEND_INIT = 0,
    NAT_NEGOTIATION_WAIT_CONNECT = 1,
    NAT_NEGOTIATION_PING = 2,
    NAT_NEGOTIATION_PING_ANSWERED = 3,
    NAT_NEGOTIATION_CANCELED = 4,
};

// One NAT negotiation in progress: cookie, client index, state, retry counters, guessed address and callbacks.
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
    /* 34 */ void (*mProgressCallback)(s32 state, void *userdata);
    /* 38 */ void (*mCompletedCallback)(s32 result, s32 descriptor, void *address, void *userdata);
    /* 3c */ void *mUserdata;
} NatTraversalEntry;

void NegotiatorFree(NatTraversalEntry *negotiator);
