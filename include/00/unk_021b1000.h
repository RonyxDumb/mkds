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
extern char data_ov000_021b1060[];
extern char gBirthFormat[];
extern char gDevtimeFormat[];
extern char gActionPairName[];
extern char gAcctcreatePairValue[];
extern char gLoginPairValue[];
extern char gGsbrcdPairName[];
extern char gIngamesnPairName[];
extern char gSdkverPairName[];
extern char gSdkverPairValue[];
extern char gUserIdFormat[];
extern char gUseridPairName[];
extern char gPasswdFormat[];
extern char gPasswdPairName[];
extern char gBssidFormat[];
extern char gApinfoFormat[];
extern char gGamecdPairName[];
extern char gMakercdPairName[];
extern char gUnitcdPairName[];
extern char gUnitcdPairValue[];
extern char gMacadrPairName[];
extern char gLangPairName[];
extern char gBirthPairName[];
extern char gDevtimePairName[];
extern char gBssidPairName[];
extern char gApinfoPairName[];
extern char gUserAgentHeaderName[];
extern char gUserAgentHeaderValue[];
extern char gHttpXGamecdHeaderName[];
extern char gDevnamePairName[];
extern char gHttpresultPairName2[];
extern char gReturncdPairName[];
extern char gTokenPairName[];
extern char gLocatorPairName[];
extern char gChallengePairName[];
extern char gDatetimePairName[];
extern char gSetCookieHeaderName[];
extern char gBmworkName[];
extern char gAuthFreeName[];
extern char gAuthAllocName[];
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
