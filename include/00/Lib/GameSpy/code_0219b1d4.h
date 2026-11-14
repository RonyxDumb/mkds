#pragma once

#include "types.h"

// Values of NatTraversalEntry.mState: sending the init packets until the acks arrive, waiting for the connect packet of
// the other side, pinging it until it answers, the ping answered (the entry is cancelled after a delay), and cancelled
// (removed by the next think). The progress callback is called with WAIT_CONNECT and PING.
enum {
    NAT_NEGOTIATION_SEND_INIT = 0,
    NAT_NEGOTIATION_WAIT_CONNECT = 1,
    NAT_NEGOTIATION_PING = 2,
    NAT_NEGOTIATION_PINGED = 3,
    NAT_NEGOTIATION_CANCELED = 4,
};

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
