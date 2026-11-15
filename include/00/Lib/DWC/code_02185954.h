#pragma once

#include "types.h"

typedef struct DWCHttpLabelValue {
    /* 00 */ void *mFirst;
    /* 04 */ void *mSecond;
} DWCHttpLabelValue;

typedef struct DWCHttpParseResult {
    /* 00 */ DWCHttpLabelValue *mEntries;
    /* 04 */ s32 mCapacity;
    /* 08 */ s32 mCount;
} DWCHttpParseResult;

#include "os_thread.h"
#include "00/unk_021b1000.h"
#include "dwc_backup.h"
#include "00/code_021a88a8.h"
#include "00/types_021a998c.h"

// Growing buffer: mStart is its start, mCursor the write position, mEnd the end and mSize the size.
typedef struct HttpBuffer {
    /* 00 */ char *mStart;
    /* 04 */ char *mCursor;
    /* 08 */ char *mEnd;
    /* 0c */ s32 mSize;
} HttpBuffer;

// Values of Http.mResult, set by the thread that sends the request and reads the reply.
typedef enum HttpResult {
    HTTP_RESULT_OK,
    HTTP_RESULT_NO_MEMORY,
    HTTP_RESULT_RESOLVE_FAILED,
    HTTP_RESULT_CONNECT_FAILED,
    HTTP_RESULT_SEND_TIMEOUT,
    HTTP_RESULT_SEND_FAILED,
    HTTP_RESULT_RECEIVE_TIMEOUT,
    HTTP_RESULT_ABORTED,
    HTTP_RESULT_DONE
} HttpResult;

// 0x1a60 bytes; the stack of its thread ends at mThreadStackBottom. mUnk_04 holds the setup it was created with; its
// allocate and free functions allocate and release the memory of the buffers.
typedef struct Http {
    /* 000 */ u8 mInitFlag;
    /* 004 */ DWCHttpParam mParam;
    /* 024 */ s32 mResult;
    /* 028 */ char mUrl[0x80];
    /* 0a8 */ char *mHost;
    /* 0ac */ char *mPath;
    /* 0b0 */ BOOL mUseHttps;
    /* 0b4 */ CPSSoc mSoc;
    /* 118 */ HttpsState mHttpsState;
    /* 91c */ void *mLowReceiveBuffer;
    /* 920 */ void *mLowSendBuffer;
    /* 924 */ s32 mPairCount;
    /* 928 */ HttpBuffer mSendBuffer;
    /* 938 */ HttpBuffer mReceiveBuffer;
    /* 948 */ OSMutex mReceiveMutex;
    /* 960 */ s32 mContentLength;
    /* 964 */ const char *mBodyStart;
    /* 968 */ OSThread mThread;
    /* a28 */ OSMutex mAbortMutex;
    /* a40 */ BOOL mAbort;
    /* a44 */ u8 pad_a44[0x101c];
    /* 1a60 */ u8 mThreadStackBottom[];
} Http;

u32 GrowHttpBuffer(Http *http, HttpBuffer *httpBuffer, int addedSize);
void FreeHttpBuffer(Http *http, HttpBuffer *httpBuffer);
u32 InitHttpBuffer(Http *http, HttpBuffer *httpBuffer, int size);

#include "00/code_02186d04.h"

// Written into DWCAuth at 0x1cc; mUnk_24 and mUnk_28 allocate and release the 0x13e0 bytes of the object and the
// buffers.
typedef struct AuthCreateParams {
    /* 00 */ char mIngamesn[0x15];
    /* 15 */ char mGsbrcd[0xc];
    /* 21 */ u8 pad_21[3];
    /* 24 */ void *(*mAlloc)(const void *, u32);
    /* 28 */ void (*mFree)(const void *, void *, u32);
} AuthCreateParams;

// Values of DWCAuth.mReturncode: the server's result code plus SERVER_BASE (UPDATE_ID is its code 2), the HTTP status
// plus HTTP_STATUS_BASE when the status is not 200, or one of the local results below. The code is negated once the
// retries have run out, and starts at -1. DWC_Auth_GetResult reports OUT_OF_RANGE (negated) for a code outside
// SERVER_BASE up to SERVER_LIMIT.
enum {
    AUTH_RETURN_SERVER_BASE = 0x4e20,
    AUTH_RETURN_SERVER_LIMIT = 0x7530,
    AUTH_RETURN_OUT_OF_RANGE = 0x5206,
    AUTH_RETURN_UPDATE_ID = 0x4e22,
    AUTH_RETURN_FAILED = 0x4e84,
    AUTH_RETURN_BAD_RESPONSE = 0x4e85,
    AUTH_RETURN_REMAKE_ID = 0x4e88,
    AUTH_RETURN_WRITE_NEW_ID = 0x4e8c,
    AUTH_RETURN_HTTP_STATUS_BASE = 0x59d8,
};

// 0x13e0 bytes, held in gAuth; the stack of its thread is the last 0x1000 bytes.
typedef struct DWCAuth {
    /* 000 */ u32 mUnk_000;
    /* 004 */ s32 mError;
    /* 008 */ s32 mReturncode;
    /* 00c */ char mRetcode[4];
    /* 010 */ char mDatetime[0xf];
    /* 01f */ char mLocator[0x33];
    /* 052 */ char mToken[0x12d];
    /* 17f */ char mChallenge[9];
    /* 188 */ char mCookie[0x41];
    /* 1c9 */ u8 pad_1c9[3];
    /* 1cc */ AuthCreateParams mCreateParams;
    /* 1f8 */ DWCHttpLabelValue mHttpLabelvalue[0x20];
    /* 2f8 */ Http *mHttp;
    /* 2fc */ OSThread mThread;
    /* 3bc */ OSMutex mMutex;
    /* 3d4 */ BOOL mAbort;
    /* 3d8 */ u8 pad_3d8[8];
    /* 3e0 */ u8 mStack[0x1000];
} DWCAuth;

// Some of the locals of DWCi_Auth_Prepare_FirstPost.
typedef struct AuthFirstPostValues {
    /* 00 */ u16 mEssidLength;
    /* 02 */ u8 mMacAddress[6];
    /* 08 */ u8 mBssid[6];
    /* 0e */ char mGameCode[5];
    /* 13 */ char mMakerCode[3];
    /* 16 */ char mBirthday[5];
    /* 1b */ char mPassword[4];
} AuthFirstPostValues;

#include "00/Lib/CPS/network.h"

extern DWCAuth *gAuth;
extern DWCWiFiInfo gAuthWiFiInfo;

void DWCi_Auth_SetError(s32 error);
u32 DWCi_Auth_Prepare_FirstPost(Http *http, const char *gsbrcd, const char *ingamesn, DWCHttpLabelValue *labelValues,
                                s32 labelValueCount, s32 getWiFiInfoFromFlash);
s32 DWCi_Auth_FillResult(void);
s32 ParseAuthHttpResult(void);
void DWCi_Auth_Thread(void *authAddress);
s32 DWCi_Auth_Start(s32 getWiFiInfoFromFlash);
void DWC_Auth_GetResult(s32 *result);
s32 DWC_Auth_GetError(void);
void DWC_Auth_Join(void);
void DWC_Auth_Destroy(void);
void DWC_Auth_Abort(void);
void DWCi_Auth_StartThread(void);
s32 DWC_Auth_Create(AuthCreateParams *createParams, Http *http);
void DWC_Auth_SetCustomNas(const void *nasAddress);
BOOL DWC_Http_GetRawResult(DWCHttpLabelValue *labelValues, s32 labelValueCount, const char *label, char *buffer,
                           s32 bufferSize);
s32 DWC_Http_GetBase64DecodedResult(DWCHttpLabelValue *labelValues, s32 labelValueCount, const char *label,
                                    char *buffer, s32 bufferSize);
void *DWC_Http_GetResult(DWCHttpLabelValue *labelValues, s32 labelValueCount, const char *label);
BOOL DWC_Http_ParseResult(DWCHttpLabelValue *labelValues, s32 labelValueCount, s32 noParseBody, const char *reply);
BOOL DWCi_Http_AddResult(DWCHttpParseResult *list, void *first, void *second);
BOOL DWCi_Http_SetHostinfo(Http *http, const char *url);
u32 DWCi_Http_CPSCallback(u32 flags, HttpsState *httpsState, s32 itemIndex);
