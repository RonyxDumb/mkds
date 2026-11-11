#pragma once

#include "types.h"
#include "code_0200fc8c.h"
#include "00/unk_021b1000.h"
#include "code_02151868.h"
#include "code_021519d4.h"
#include "00/code_02186a9c.h"
#include "00/code_021acef8.h"
#include "00/code_021a6c08.h"
#include "00/code_0218a67c.h"
#include "00/code_021a6934.h"
#include "00/code_02185954.h"
#include "00/code_02188008.h"

typedef struct OSThread OSThread;

// Object behind gNetcheck.
typedef struct DWCNetcheck {
    /* 000 */ u32 mError;
    /* 004 */ s32 mReturnCode;
    /* 008 */ DWCHttpLabelValue mHttpLabelvalue[0x20];
    /* 108 */ DWCNetcheckParam mParam;
    /* 114 */ void *mBody302;
    /* 118 */ void *mBodyWayport;
    /* 11c */ OSThread mThread;
    /* 1d4 */ u8 pad_1d4[8];
    /* 1dc */ OSMutex mMutex;
    /* 1f4 */ u8 pad_1f4[0x100c];
    /* 1200 */ u8 mThreadStack[0x1000];
} DWCNetcheck;

// Object filled by DWC_Auth_GetResult.
typedef struct DWCAuthResult {
    /* 000 */ s32 mReturnCode;
    /* 004 */ u8 mUnk_004[0x46];
    /* 04a */ char mToken[0x12d];
    /* 177 */ char mChallenge[0x4d];
} DWCAuthResult;

#include "os_thread.h"

extern char *gConnTestUrl;
extern char gUrlPairName[];
extern char gDataPairName[];
extern char gWaitPairName[];
extern char gHttpresultPairName3[];
extern char data_ov000_021b1400[];
extern char data_ov000_021b1420[];
extern char gActionPairName2[];
extern char gMessagePairValue[];
extern char gSsidPairName[];
extern char gHotSpotResponsePairName[];
extern char gHttpbodyPairName2[];
extern char gParsePairValue[];
extern char gHtmlPairName[];
extern char gReturncdPairName2[];
extern DWCHttpParam gHttpParam;
extern AuthCreateParams gAuthParam;

u32 DWC_Netcheck_GetReturnCode(void);
void DWCi_Netcheck_SetError(u32 error);
u32 DWC_Netcheck_GetError(void);
void DWCi_Netcheck_Thread(void);
void DWC_Netcheck_Abort(void);
