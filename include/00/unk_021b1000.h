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

// Objects whose layout isn't known yet.
extern char *gLangPairValues[7];
extern DWCHttpParam DWCauthhttpparam;
extern u8 gHttpBufferName[];
extern u8 gHttpLowReceiveBufferName[];
extern u8 gHttpLowSendBufferName[];

// Strings.
extern char gNasAuthUrl[];
extern char gHttpHeaderEndMarker[];
extern char gHttpStatusSeparator[];
extern char gHttpresultPairName[];
extern char gHttpOkStatusText[];
extern char gHttpbodyPairName[];
extern char gHttpLineEndMarker[];
extern char gHeaderValueSeparator[];
extern char gPairValueSeparator[];
extern char gPairSeparator[];
extern char gHttpUrlPrefix[];
extern char gHttpsUrlPrefix[];
extern char gUrlPathSeparator[];
extern char gNetcheckBody302Name[];
extern char gNetcheckBodyWayportName[];
