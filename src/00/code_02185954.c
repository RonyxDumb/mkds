#include "00/code_02185954.h"
#include "code_0200fc8c.h"
#include "00/unk_021b1000.h"
#include "code_02151868.h"
#include "code_021519d4.h"
#include "00/code_02186a9c.h"
#include "00/code_021acef8.h"
#include "00/code_021a6c08.h"
#include "00/code_0218a67c.h"
#include "00/code_021a6934.h"

#include "00/code_02181f98.h"
#include "code_0200e77c.h"
#include "00/code_021857b8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "00/code_021ad734.h"
#include "03/code_021b94b8.h"
#include "00/code_02186d04.h"
#include "00/code_02188008.h"
#include "00/code_02187000.h"
#include "00/code_021a6000.h"
#include "os_printf.h"
#include "os_thread.h"
#include "code_0200f5ac.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "code_0214d018.h"
#include "code_0214d93c.h"
#include "code_0200edc0.h"
#include "Main/Unknown/code_02151f88.h"

u32 DWCi_Http_CPSCallback(u32 flags) {
    if (flags & 0x8000) {
        flags &= 0xffff7fff;
    }
    return flags;
}

u32 InitHttpBuffer(Http *http, HttpBuffer *httpBuffer, int size) {
    if (size == 0) {
        return 0;
    }
    httpBuffer->mStart = http->mUnk_04.mUnk_10(gHttpBufferName, size);
    if (httpBuffer->mStart == NULL) {
        return 0;
    }
    httpBuffer->mCursor = httpBuffer->mStart;
    httpBuffer->mSize = size;
    httpBuffer->mEnd = httpBuffer->mStart + httpBuffer->mSize;
    return 1;
}

void FreeHttpBuffer(Http *http, HttpBuffer *httpBuffer) {
    if (httpBuffer->mStart != NULL) {
        http->mUnk_04.mUnk_14(gHttpBufferName, httpBuffer->mStart, 0);
    }
    MI_CpuFill8(httpBuffer, 0, 0x10);
}

u32 GrowHttpBuffer(Http *http, HttpBuffer *httpBuffer, int addedSize) {
    char *newBlock;
    if (addedSize <= 0) {
        return 0;
    }
    newBlock = http->mUnk_04.mUnk_10(NULL, httpBuffer->mSize + addedSize);
    if (newBlock == NULL) {
        return 0;
    }
    MI_CpuCopy8(httpBuffer->mStart, newBlock, httpBuffer->mSize);
    http->mUnk_04.mUnk_14(NULL, httpBuffer->mStart, 0);
    if (newBlock == NULL) {
        return 0;
    }
    httpBuffer->mCursor = httpBuffer->mCursor + (newBlock - httpBuffer->mStart);
    httpBuffer->mSize = httpBuffer->mSize + addedSize;
    httpBuffer->mStart = newBlock;
    httpBuffer->mEnd = newBlock + httpBuffer->mSize;
    return 1;
}

BOOL DWCi_Http_SetHostinfo(Http *http, const char *url) {
    char *found;
    if (strlen(url) >= 0x80) {
        return FALSE;
    }
    strncpy(http->mUnk_028, url, 0x80);
    if (strlen(url) != strlen(http->mUnk_028)) {
        return FALSE;
    }
    found = strstr(http->mUnk_028, data_ov000_021b1268);
    if (found != NULL) {
        http->mHost = http->mUnk_028 + 7;
        http->mUseHttps = FALSE;
    } else {
        found = strstr(http->mUnk_028, data_ov000_021b1270);
        if (found == NULL) {
            return FALSE;
        }
        http->mHost = found + 8;
        http->mUseHttps = TRUE;
    }
    found = strstr(http->mHost, data_ov000_021b127c);
    if (found == NULL) {
        http->mPath = NULL;
    } else {
        *found = 0;
        http->mPath = found + 1;
    }
    return TRUE;
}

BOOL DWCi_Http_AddResult(DWCHttpParseResult *list, void *first, void *second) {
    if (list->mCount > list->mCapacity) {
        return FALSE;
    }
    list->mEntries[list->mCount].mFirst = first;
    list->mEntries[list->mCount].mSecond = second;
    list->mCount++;
    return TRUE;
}

BOOL DWC_Http_ParseResult(DWCHttpLabelValue *labelValues, s32 labelValueCount, s32 noParseBody, const char *reply) {
    char *headerEnd;
    char *bodyEnd;
    DWCHttpParseResult results;
    s8 *statusText;
    s8 *h;
    char *j;
    s8 *delimiter;
    results.mEntries = labelValues;
    results.mCapacity = labelValueCount;
    results.mCount = 0;
    MI_CpuFill8(labelValues, 0, labelValueCount * 8);
    headerEnd = strstr(reply, data_ov000_021b1230);
    if (headerEnd == NULL) {
        return FALSE;
    }
    bodyEnd = headerEnd + 4 + strlen(headerEnd + 4);
    delimiter = (s8 *) strstr(reply, data_ov000_021b1238);
    if (delimiter == NULL) {
        return FALSE;
    }
    statusText = delimiter + 1;
    statusText[3] = 0;
    if (DWCi_Http_AddResult(&results, gHttpresultPairName, statusText) != TRUE) {
        return FALSE;
    }
    if (noParseBody == 1 || strncmp((const char *) statusText, data_ov000_021b1248, 3) != 0) {
        if (DWCi_Http_AddResult(&results, gHttpbodyPairName, headerEnd + 4) != TRUE) {
            return FALSE;
        }
        return TRUE;
    }
    delimiter = (s8 *) strstr((const char *) (statusText + 4), data_ov000_021b1258);
    if (delimiter == NULL) {
        return FALSE;
    }
    h = delimiter + 2;
    while (h[0] != 0xd && h[1] != 0xa) {
        delimiter = (s8 *) strstr((const char *) h, data_ov000_021b125c);
        if (delimiter == NULL) {
            break;
        }
        delimiter[0] = delimiter[1] = 0;
        j = (char *) (delimiter + 2);
        delimiter = (s8 *) strstr(j, data_ov000_021b1258);
        if (delimiter == NULL) {
            break;
        }
        delimiter[0] = delimiter[1] = 0;
        if (DWCi_Http_AddResult(&results, h, j) != TRUE) {
            return FALSE;
        }
        h = (s8 *) (j + strlen(j) + 2);
    }
    j = headerEnd + 4;
    if (j < bodyEnd) {
        do {
            delimiter = (s8 *) strstr(j, data_ov000_021b1260);
            if (delimiter == NULL) {
                break;
            }
            delimiter[0] = 0;
            h = delimiter + 1;
            delimiter = (s8 *) strstr((const char *) h, data_ov000_021b1264);
            if (delimiter == NULL) {
                delimiter = (s8 *) strstr((const char *) h, data_ov000_021b1258);
            }
            if (delimiter != NULL) {
                delimiter[0] = 0;
            }
            if (DWCi_Http_AddResult(&results, j, h) != TRUE) {
                return FALSE;
            }
            j = (char *) h + strlen((const char *) h) + 1;
        } while (j < bodyEnd);
    }
    return TRUE;
}

void *DWC_Http_GetResult(DWCHttpLabelValue *labelValues, s32 labelValueCount, const char *label) {
    s32 index;
    for (index = 0; index < labelValueCount; index++) {
        if (labelValues[index].mFirst == NULL) {
            break;
        }
        if (strcmp(label, labelValues[index].mFirst) == 0) {
            return labelValues[index].mSecond;
        }
    }
    return NULL;
}

s32 DWC_Http_GetBase64DecodedResult(DWCHttpLabelValue *labelValues, s32 labelValueCount, const char *label,
                                    char *buffer, s32 bufferSize) {
    const char *encodedText = DWC_Http_GetResult(labelValues, labelValueCount, label);
    u32 decodedLength;
    if (encodedText == NULL) {
        return 0;
    }
    decodedLength = DWC_Auth_Base64Decode((const s8 *) encodedText, strlen(encodedText), (u8 *) buffer, bufferSize);
    if (decodedLength != -1 && decodedLength < bufferSize) {
        buffer[decodedLength] = 0;
    }
    return decodedLength;
}

BOOL DWC_Http_GetRawResult(DWCHttpLabelValue *labelValues, s32 labelValueCount, const char *label, char *buffer,
                           s32 bufferSize) {
    const char *rawText = DWC_Http_GetResult(labelValues, labelValueCount, label);
    if (rawText == NULL) {
        return FALSE;
    }
    if ((s32) strlen(rawText) >= bufferSize) {
        return FALSE;
    }
    strcpy(buffer, rawText);
    return TRUE;
}

void DWC_Auth_SetCustomNas(const void *nasAddress) {
    DWCauthhttpparam.mUnk_00 = nasAddress;
}

s32 DWC_Auth_Create(AuthCreateParams *createParams, Http *http) {
    void *authBlock;
    if (gAuth != NULL) {
        return 2;
    }
    authBlock = createParams->mAlloc(gAuthAllocName, 0x13e0);
    if (authBlock == NULL) {
        return 2;
    }
    gAuth = authBlock;
    MI_CpuFill8(authBlock, 0, 0x13e0);
    gAuth->mHttp = http;
    MI_CpuFill8(&gAuth->mUnk_008, 0, 0x1c4);
    gAuth->mUnk_008 = -1;
    gAuth->mUnk_1cc = *createParams;
    gAuth->mUnk_1cc.mIngamesn[0x14] = 0;
    gAuth->mUnk_1cc.mGsbrcd[0xb] = 0;
    DWCauthhttpparam.mUnk_10 = createParams->mAlloc;
    DWCauthhttpparam.mUnk_14 = createParams->mFree;
    gAuth->mError = DWCi_Auth_Start(1);
    if (gAuth->mError == 0) {
        DWCi_Auth_StartThread();
        return 0;
    }
    return gAuth->mError;
}

void DWCi_Auth_StartThread(void) {
    OS_InitMutex(&gAuth->mMutex);
    gAuth->mAbort = FALSE;
    if (gAuth->mThread.mId == 0 || OS_IsThreadTerminated(&gAuth->mThread) != 0) {
        OS_CreateThread(&gAuth->mThread, DWCi_Auth_Thread, &gAuth, gAuth->mStack + 0x1000, 0x1000, 0x10);
        OS_WakeupThreadDirect(&gAuth->mThread);
    }
}

void DWC_Auth_Abort(void) {
    if (gAuth != NULL) {
        OS_LockMutex(&gAuth->mMutex);
        gAuth->mAbort = TRUE;
        OS_UnlockMutex(&gAuth->mMutex);
        if (gAuth->mHttp != NULL) {
            DWC_Http_Abort(gAuth->mHttp);
        }
        if (gAuth->mThread.mId != 0) {
            OS_JoinThread(&gAuth->mThread);
        }
    }
}

void DWC_Auth_Destroy(void) {
    if (gAuth != NULL) {
        if (gAuth->mHttp != NULL) {
            ReleaseHttp(gAuth->mHttp);
        }
        gAuth->mUnk_1cc.mFree(gAuthFreeName, gAuth, 0);
        gAuth = NULL;
    }
}

void DWC_Auth_Join(void) {
    if (gAuth->mThread.mId != 0) {
        OS_JoinThread(&gAuth->mThread);
    }
}

s32 DWC_Auth_GetError(void) {
    s32 error;
    if (gAuth == NULL) {
        return 0x15;
    }
    OS_LockMutex(&gAuth->mMutex);
    error = gAuth->mError;
    OS_UnlockMutex(&gAuth->mMutex);
    return error;
}

void DWC_Auth_GetResult(s32 *result) {
    s32 returnCode;
    if (gAuth == NULL) {
        MI_CpuFill8(result, 0, 0x1c4);
    }
    MI_CpuCopy8(&gAuth->mUnk_008, result, 0x1c4);
    returnCode = *result;
    if (returnCode >= 0) {
        if (returnCode < 0x4e20 || returnCode >= 0x7530) {
            *result = -0x5206;
        }
    } else if (returnCode > -0x4e20 || returnCode <= -0x7530) {
        *result = -0x5206;
    }
}

s32 DWCi_Auth_Start(s32 getWiFiInfoFromFlash) {
    if (strcmp(DWCauthhttpparam.mUnk_00, data_ov000_021b1020) != 0) {
        DWCauthhttpparam.mUnk_18 = TRUE;
    }
    if (DWC_Http_Create(gAuth->mHttp, &DWCauthhttpparam) != 0) {
        return 4;
    }
    if (getWiFiInfoFromFlash == 1) {
        DWCi_BM_GetWiFiInfo(&gAuthWiFiInfo);
    }
    gAuth->mError = DWCi_Auth_Prepare_FirstPost(gAuth->mHttp, gAuth->mUnk_1cc.mGsbrcd, gAuth->mUnk_1cc.mIngamesn,
                                                gAuth->mHttpLabelvalue, 0x20, 0);
    if (gAuth->mError != 0) {
        return 4;
    }
    if (DWC_Http_FinishHeader(gAuth->mHttp) != 0) {
        return 4;
    }
    DWC_Http_StartThread(gAuth->mHttp);
    return 0;
}

void DWCi_Auth_Thread(void *authAddress) {
    s32 retryCount = 0;
    s32 getWiFiInfoFromFlash;
    BOOL c = FALSE;
    BOOL d = FALSE;
    BOOL e = FALSE;
    s32 parseResult;
    u64 startTick;
    u64 elapsedMillis;
    DWCAuth *auth;
    while (1) {
        auth = gAuth;
        if (auth->mHttp->mThread.mId != 0) {
            OS_JoinThread(&auth->mHttp->mThread);
        }
        if (gAuth->mHttp->mResult != 8) {
            gAuth->mUnk_008 = -0x4e84;
            if (gAuth->mHttp->mResult == 7) {
                DWCi_Auth_SetError(0x13);
                return;
            }
            if (retryCount > 2) {
                if (gAuth->mHttp->mResult == 2) {
                    DWCi_Auth_SetError(9);
                    return;
                }
                DWCi_Auth_SetError(0xc);
                return;
            }
            retryCount++;
            getWiFiInfoFromFlash = 1;
        } else {
            parseResult = ParseAuthHttpResult();
            switch (parseResult) {
                case 0x14:
                    DWCi_Auth_SetError(0x14);
                    return;
                case 0xf:
                    if (retryCount >= 2) {
                        DWCi_Auth_SetError(0xf);
                        gAuth->mUnk_008 = -gAuth->mUnk_008;
                        return;
                    }
                    retryCount++;
                    getWiFiInfoFromFlash = c;
                    break;
                default:
                    if (retryCount >= 2) {
                        gAuth->mUnk_008 = -gAuth->mUnk_008;
                        DWCi_Auth_SetError(parseResult);
                        return;
                    }
                    retryCount++;
                    getWiFiInfoFromFlash = 1;
                    break;
            }
        }
        startTick = OS_GetTick();
        elapsedMillis = ((OS_GetTick() - startTick) * 64) / 0x82ea;
        while (elapsedMillis < 5000) {
            OS_LockMutex(&gAuth->mMutex);
            if (gAuth->mAbort == TRUE) {
                gAuth->mUnk_008 = -0x4e84;
                OS_UnlockMutex(&gAuth->mMutex);
                DWCi_Auth_SetError(0x13);
                return;
            }
            OS_UnlockMutex(&gAuth->mMutex);
            OS_Sleep(5000);
            elapsedMillis = ((OS_GetTick() - startTick) * 64) / 0x82ea;
        }
        ReleaseHttp(gAuth->mHttp);
        OS_LockMutex(&gAuth->mMutex);
        gAuth->mError = DWCi_Auth_Start(getWiFiInfoFromFlash);
        if (gAuth->mError != 0) {
            gAuth->mUnk_008 = -0x4e84;
            OS_UnlockMutex(&gAuth->mMutex);
            return;
        }
        OS_UnlockMutex(&gAuth->mMutex);
    }
}

s32 ParseAuthHttpResult(void) {
    DWCAuth *auth;
    const char *bmworkName;
    void *bmworkBlock;
    if (DWC_Http_ParseResult(gAuth->mHttpLabelvalue, 0x20, 0, gAuth->mHttp->mReceiveBuffer.mStart) != TRUE) {
        gAuth->mUnk_008 = 0x4e84;
        return 0xd;
    }
    if (DWCi_Auth_FillResult() != 0) {
        return 0xd;
    }
    auth = gAuth;
    if (auth->mUnk_008 < 0x4e84) {
        if (auth->mUnk_008 == 0x4e22) {
            bmworkName = gBmworkName;
            bmworkBlock = auth->mUnk_1cc.mAlloc(bmworkName, 0x71f);
            if (bmworkBlock == NULL) {
                gAuth->mUnk_008 = 0x4e84;
                return 2;
            }
            if (DWCi_AUTH_UpDateWiFiID(&gAuthWiFiInfo, (u8 *) (((u32) bmworkBlock + 0x1f) & ~0x1f)) != 1) {
                gAuth->mUnk_1cc.mFree(bmworkName, bmworkBlock, 0);
                gAuth->mUnk_008 = 0x4e84;
                return 0xe;
            }
            gAuth->mUnk_1cc.mFree(bmworkName, bmworkBlock, 0);
        }
        return 0x14;
    }
    switch (auth->mUnk_008) {
        case 0x4e88:
            if (DWCi_AUTH_RemakeWiFiID(&gAuthWiFiInfo) == 0) {
                gAuth->mUnk_008 = 0x4e88;
                return 0xe;
            }
            gAuth->mUnk_008 = 0x4e88;
            return 0xf;
        case 0x4e8c:
            bmworkName = gBmworkName;
            bmworkBlock = auth->mUnk_1cc.mAlloc(bmworkName, 0x71f);
            if (bmworkBlock == NULL) {
                gAuth->mUnk_008 = 0x4e8c;
                return 2;
            }
            if (WriteNewWiFiInfoToNvram(((u32) bmworkBlock + 0x1f) & ~0x1f) != 1) {
                gAuth->mUnk_1cc.mFree(bmworkName, bmworkBlock, 0);
                gAuth->mUnk_008 = 0x4e8c;
                return 0xe;
            }
            gAuth->mUnk_1cc.mFree(bmworkName, bmworkBlock, 0);
            gAuth->mUnk_008 = 0x4e8c;
            return 0x10;
    }
    return 0x11;
}

s32 DWCi_Auth_FillResult(void) {
    s32 returnCode;
    const char *endPointer;
    DWCAuth *auth;
    endPointer = NULL;
    returnCode = StrtolBase10(DWC_Http_GetResult(gAuth->mHttpLabelvalue, 0x20, gHttpresultPairName2));
    if (gLibErrorCode == 0x22) {
        gAuth->mUnk_008 = 0x4e85;
        return 0xb;
    }
    if (returnCode != 200) {
        gAuth->mUnk_008 = returnCode + 0x59d8;
        return 0x11;
    }
    auth = gAuth;
    if (DWC_Http_GetBase64DecodedResult(auth->mHttpLabelvalue, 0x20, gReturncdPairName, auth->mRetcode, 4) <= 0) {
        gAuth->mUnk_008 = 0x4e85;
        return 0xd;
    }
    returnCode = strtol(gAuth->mRetcode, &endPointer, 10);
    auth = gAuth;
    if (endPointer != auth->mRetcode + strlen(auth->mRetcode)) {
        auth->mUnk_008 = 0x4e85;
        return 0xb;
    }
    auth->mUnk_008 = returnCode + 0x4e20;
    if (returnCode < 100) {
        gAuth->mToken[0] = 0;
        gAuth->mLocator[0] = 0;
        gAuth->mChallenge[0] = 0;
        gAuth->mDatetime[0] = 0;
        gAuth->mCookie[0] = 0;
        DWC_Http_GetBase64DecodedResult(gAuth->mHttpLabelvalue, 0x20, gTokenPairName, gAuth->mToken, 0x12d);
        DWC_Http_GetBase64DecodedResult(gAuth->mHttpLabelvalue, 0x20, gLocatorPairName, gAuth->mLocator, 0x33);
        DWC_Http_GetBase64DecodedResult(gAuth->mHttpLabelvalue, 0x20, gChallengePairName, gAuth->mChallenge, 9);
        DWC_Http_GetBase64DecodedResult(gAuth->mHttpLabelvalue, 0x20, gDatetimePairName, gAuth->mDatetime, 0xf);
        DWC_Http_GetRawResult(gAuth->mHttpLabelvalue, 0x20, gSetCookieHeaderName, gAuth->mCookie, 0x41);
        gAuth->mCookie[0x2b] = 0;
    }
    return 0;
}

u32 DWCi_Auth_Prepare_FirstPost(Http *http, const char *gsbrcd, const char *ingamesn, DWCHttpLabelValue *labelValues,
                                s32 labelValueCount, s32 getWiFiInfoFromFlash) {
    Unk02185984Data postData;
    RTCDate date;
    RTCTime time;
    DWCHttpParseResult results;
    char macAddressText[13];
    char deviceTimeText[13];
    u8 deviceName[0x15];
    char bssidText[13];
    u8 apInfoBytes[0x21];
    char apInfoText[14];
    char userIdText[0xe];
    OwnerInfo ownerInfo;
    u8 *macCursor;
    u32 interruptState;
    u8 *bssidPointer;
    u8 *apInfoPointer;
    s32 macIndex;
    s32 postItemCount;
    char *postValue;
    OS_GetMacAddress(postData.mUnk_02);
    OS_GetOwnerInfo(&ownerInfo);
    if (RTC_GetDate(&date) != 0 || RTC_GetTime(&time) != 0) {
        return 5;
    }
    interruptState = OS_DisableInterrupts();
    bssidPointer = WCM_GetApMacAddress();
    if (bssidPointer == NULL) {
        OS_RestoreInterrupts(interruptState);
        return 3;
    }
    MI_CpuCopy8(bssidPointer, postData.mUnk_08, 6);
    MI_CpuFill8(apInfoBytes, 0, 0x21);
    apInfoPointer = WCM_GetApEssid((u16 *) &postData);
    if (apInfoPointer == NULL) {
        OS_RestoreInterrupts(interruptState);
        return 3;
    }
    MI_CpuCopy8(apInfoPointer, apInfoBytes, postData.mUnk_00);
    OS_RestoreInterrupts(interruptState);
    MI_CpuCopy8((const void *) 0x27ffe0c, postData.mUnk_0e, 4);
    postData.mUnk_0e[4] = 0;
    MI_CpuCopy8((const void *) 0x27ffe10, postData.mUnk_13, 2);
    postData.mUnk_13[2] = 0;
    macCursor = postData.mUnk_02;
    for (macIndex = 0; macIndex < 6; macCursor++, macIndex++) {
        OS_SPrintf(&macAddressText[macIndex * 2], data_ov000_021b1060, *macCursor);
    }
    macAddressText[12] = 0;
    if (ownerInfo.mLanguage > 6) {
        ownerInfo.mLanguage = 1;
    }
    OS_SNPrintf(postData.mUnk_16, 5, data_ov000_021b1068, ownerInfo.mBirthdayMonth, ownerInfo.mBirthdayDay);
    OS_SNPrintf(deviceTimeText, 0xd, data_ov000_021b1074, date.mYear, date.mMonth, date.mDay, time.mHour, time.mMinute,
                time.mSecond);
    MI_CpuCopy8(ownerInfo.mNickName, deviceName, 0x14);
    deviceName[0x14] = 0;
    MI_CpuFill8(&results, 0, 0xc);
    results.mEntries = labelValues;
    results.mCapacity = labelValueCount;
    if (getWiFiInfoFromFlash != 1) {
        if (gAuthWiFiInfo.mAttestedUserId == 0) {
            DWCi_Http_AddResult(&results, gActionPairName, gAcctcreatePairValue);
        } else {
            if (strlen(gsbrcd) == 0) {
                return 6;
            }
            DWCi_Http_AddResult(&results, gActionPairName, gLoginPairValue);
            DWCi_Http_AddResult(&results, gGsbrcdPairName, gsbrcd);
            if (strlen(ingamesn) != 0) {
                DWCi_Http_AddResult(&results, gIngamesnPairName, ingamesn);
            }
        }
    } else {
        DWCi_BM_GetWiFiInfo(&gAuthWiFiInfo);
    }
    DWCi_Http_AddResult(&results, gSdkverPairName, gSdkverPairValue);
    if (gAuthWiFiInfo.mAttestedUserId != 0) {
        OS_SNPrintf(userIdText, 0xe, data_ov000_021b10d0, gAuthWiFiInfo.mAttestedUserId);
    } else {
        OS_SNPrintf(userIdText, 0xe, data_ov000_021b10d0, gAuthWiFiInfo.mNotAttestedId);
    }
    DWCi_Http_AddResult(&results, gUseridPairName, userIdText);
    OS_SNPrintf(postData.mUnk_1b, 4, data_ov000_021b10e0, gAuthWiFiInfo.mPass);
    DWCi_Http_AddResult(&results, gPasswdPairName, postData.mUnk_1b);
    OS_SNPrintf(bssidText, 0xd, data_ov000_021b10f0, postData.mUnk_08[0], postData.mUnk_08[1], postData.mUnk_08[2],
                postData.mUnk_08[3], postData.mUnk_08[4], postData.mUnk_08[5]);
    OS_SNPrintf(apInfoText, 0xd, data_ov000_021b110c, 0);
    DWCi_AC_GetPostalCode(apInfoBytes, &apInfoText[3]);
    DWCi_Http_AddResult(&results, gGamecdPairName, postData.mUnk_0e);
    DWCi_Http_AddResult(&results, gMakercdPairName, postData.mUnk_13);
    DWCi_Http_AddResult(&results, gUnitcdPairName, gUnitcdPairValue);
    DWCi_Http_AddResult(&results, gMacadrPairName, macAddressText);
    DWCi_Http_AddResult(&results, gLangPairName, data_ov000_021b1004[ownerInfo.mLanguage]);
    DWCi_Http_AddResult(&results, gBirthPairName, postData.mUnk_16);
    DWCi_Http_AddResult(&results, gDevtimePairName, deviceTimeText);
    DWCi_Http_AddResult(&results, gBssidPairName, bssidText);
    DWCi_Http_AddResult(&results, gApinfoPairName, apInfoText);
    if (DWC_Http_Add_HeaderItem(http, gUserAgentHeaderName, gUserAgentHeaderValue) != FALSE) {
        return 7;
    }
    if (DWC_Http_Add_HeaderItem(http, gHttpXGamecdHeaderName, postData.mUnk_0e) != FALSE) {
        return 7;
    }
    for (postItemCount = 0; labelValues->mFirst != NULL; labelValues++, postItemCount++) {
        postValue = labelValues->mSecond;
        if (DWC_Http_Add_PostBase64Item(http, labelValues->mFirst, postValue, strlen(postValue)) != FALSE) {
            return 8;
        }
    }
    if (DWC_Http_Add_PostBase64Item(http, gDevnamePairName, deviceName, 0x14) != FALSE) {
        return 8;
    }
    return 0;
}

void DWCi_Auth_SetError(s32 error) {
    OS_LockMutex(&gAuth->mMutex);
    gAuth->mError = error;
    OS_UnlockMutex(&gAuth->mMutex);
}
