#pragma once

#include "types.h"

typedef struct DWCHttpParam {
    /* 00 */ char *mUrl;
    /* 04 */ BOOL mAction;
    /* 08 */ char *mReceiveBufferStart;
    /* 0c */ s32 mReceiveBufferSize;
    /* 10 */ void *(*mAlloc)();
    /* 14 */ void (*mFree)();
    /* 18 */ BOOL mIgnoreCa;
    /* 1c */ s32 mTimeoutMillis;
} DWCHttpParam;

// Receive buffer sizes and timeouts the network check puts into DWCHttpParam.
#define NETCHECK_HTTP_RECEIVE_BUFFER_SIZE 0x1000
#define NETCHECK_HTTP_SMALL_RECEIVE_BUFFER_SIZE 0x200
#define NETCHECK_HTTP_TIMEOUT_MILLIS 20000
#define NETCHECK_HTTP_LONG_TIMEOUT_MILLIS 40000

extern char *gLangPairValues[7];
extern DWCHttpParam DWCauthhttpparam;

extern char gNasAuthUrl[];
