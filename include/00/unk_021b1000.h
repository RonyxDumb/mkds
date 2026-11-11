#pragma once

#include "types.h"

typedef struct DWCHttpParam {
    /* 00 */ char *mUnk_00;
    /* 04 */ BOOL mUnk_04;
    /* 08 */ char *mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ void *(*mUnk_10)();
    /* 14 */ void (*mUnk_14)();
    /* 18 */ BOOL mUnk_18;
    /* 1c */ s32 mUnk_1c;
} DWCHttpParam;

// Objects whose layout isn't known yet.
extern char *gLangPairValues[];
extern DWCHttpParam DWCauthhttpparam;
extern u8 gHttpBufferName[];
extern u8 gHttpLowReceiveBufferName[];
extern u8 gHttpLowSendBufferName[];

// Strings.
extern char data_ov000_021b1020[];
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
extern char gStringFormat[];
extern char gPostFirstPairFormat[];
extern char gPostNextPairFormat[];
extern char gHeaderItemFormat[];
extern char gHttpPostRequestFormat[];
extern char gHttpGetRequestFormat[];
extern char gNetcheckBody302Name[];
extern char gNetcheckBodyWayportName[];
