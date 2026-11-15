#include "00/Lib/DWC/code_02185954.h"
#include "code_0200fc8c.h"
#include "00/Lib/DWC/dwc_auth_http_params.h"
#include "dwc_backup.h"
#include "code_021519d4.h"
#include "00/Lib/DWC/code_02186a9c.h"
#include "00/Lib/CPS/network.h"
#include "00/Lib/NitroWiFi/util.h"
#include "00/Lib/DWC/code_0218a67c.h"
#include "00/Lib/NitroWiFi/cpsif.h"

#include "00/Menu/wi_fi_vs_setting.h"
#include "code_0200e77c.h"
#include "00/Menu/wi_fi_connection_lost.h"
#include "Main/System/heap.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/DWC/code_02186d04.h"
#include "00/Lib/DWC/code_02188008.h"
#include "os_printf.h"
#include "os_thread.h"
#include "os_tick.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "code_0214d018.h"
#include "code_0214d93c.h"
#include "code_0200edc0.h"
#include "Main/Save/nvram_new_wifi_info.h"
#include "code_02134008.h"

char gLangPairValue03[] = "03";
char gLangPairValue04[] = "04";
char gLangPairValue02[] = "02";
char gLangPairValue01[] = "01";
char gLangPairValue06[] = "06";
char gLangPairValue00[] = "00";
char gLangPairValue05[] = "05";

char *gLangPairValues[7] = {gLangPairValue00, gLangPairValue01, gLangPairValue02,
                            gLangPairValue03, gLangPairValue04, gLangPairValue05,
                            gLangPairValue06};
DWCHttpParam DWCauthhttpparam = {gNasAuthUrl, 0, NULL, 0x1000, NULL, NULL, 0, 0x4e20};
char gNasAuthUrl[32] = "https://nas.nintendowifi.net/ac";
DWCAuth *gAuth;
DWCWiFiInfo gAuthWiFiInfo;

void DWC_Auth_SetCustomNas(const void *nasAddress) {
    DWCauthhttpparam.mUrl = nasAddress;
}

s32 DWC_Auth_Create(AuthCreateParams *createParams, Http *http) {
    void *authBlock;
    if (gAuth != NULL) {
        return 2;
    }
    authBlock = createParams->mAlloc("DWCAuth", sizeof(DWCAuth));
    if (authBlock == NULL) {
        return 2;
    }
    gAuth = authBlock;
    MI_CpuFill8(authBlock, 0, sizeof(DWCAuth));
    gAuth->mHttp = http;
    MI_CpuFill8(&gAuth->mReturncode, 0, AUTH_RESULT_BYTES);
    gAuth->mReturncode = -1;
    gAuth->mCreateParams = *createParams;
    gAuth->mCreateParams.mIngamesn[0x14] = 0;
    gAuth->mCreateParams.mGsbrcd[0xb] = 0;
    DWCauthhttpparam.mAlloc = createParams->mAlloc;
    DWCauthhttpparam.mFree = createParams->mFree;
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
        gAuth->mCreateParams.mFree("DWCauth", gAuth, 0);
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
        MI_CpuFill8(result, 0, AUTH_RESULT_BYTES);
    }
    MI_CpuCopy8(&gAuth->mReturncode, result, AUTH_RESULT_BYTES);
    returnCode = *result;
    if (returnCode >= 0) {
        if (returnCode < AUTH_RETURN_SERVER_BASE || returnCode >= AUTH_RETURN_SERVER_LIMIT) {
            *result = -AUTH_RETURN_OUT_OF_RANGE;
        }
    } else if (returnCode > -AUTH_RETURN_SERVER_BASE || returnCode <= -AUTH_RETURN_SERVER_LIMIT) {
        *result = -AUTH_RETURN_OUT_OF_RANGE;
    }
}

s32 DWCi_Auth_Start(s32 getWiFiInfoFromFlash) {
    if (strcmp(DWCauthhttpparam.mUrl, gNasAuthUrl) != 0) {
        DWCauthhttpparam.mIgnoreCa = TRUE;
    }
    if (DWC_Http_Create(gAuth->mHttp, &DWCauthhttpparam) != 0) {
        return 4;
    }
    if (getWiFiInfoFromFlash == 1) {
        DWCi_BM_GetWiFiInfo(&gAuthWiFiInfo);
    }
    gAuth->mError = DWCi_Auth_Prepare_FirstPost(gAuth->mHttp, gAuth->mCreateParams.mGsbrcd,
                                                gAuth->mCreateParams.mIngamesn, gAuth->mHttpLabelvalue, 0x20, 0);
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
    BOOL noFlashRead = FALSE;
    BOOL unusedFlagFirst = FALSE;
    BOOL unusedFlagSecond = FALSE;
    s32 parseResult;
    u64 startTick;
    u64 elapsedMillis;
    DWCAuth *auth;
    while (1) {
        auth = gAuth;
        if (auth->mHttp->mThread.mId != 0) {
            OS_JoinThread(&auth->mHttp->mThread);
        }
        if (gAuth->mHttp->mResult != HTTP_RESULT_DONE) {
            gAuth->mReturncode = -AUTH_RETURN_FAILED;
            if (gAuth->mHttp->mResult == HTTP_RESULT_ABORTED) {
                DWCi_Auth_SetError(0x13);
                return;
            }
            if (retryCount > 2) {
                if (gAuth->mHttp->mResult == HTTP_RESULT_RESOLVE_FAILED) {
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
                        gAuth->mReturncode = -gAuth->mReturncode;
                        return;
                    }
                    retryCount++;
                    getWiFiInfoFromFlash = noFlashRead;
                    break;
                default:
                    if (retryCount >= 2) {
                        gAuth->mReturncode = -gAuth->mReturncode;
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
                gAuth->mReturncode = -AUTH_RETURN_FAILED;
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
            gAuth->mReturncode = -AUTH_RETURN_FAILED;
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
        gAuth->mReturncode = AUTH_RETURN_FAILED;
        return 0xd;
    }
    if (DWCi_Auth_FillResult() != 0) {
        return 0xd;
    }
    auth = gAuth;
    if (auth->mReturncode < AUTH_RETURN_FAILED) {
        if (auth->mReturncode == AUTH_RETURN_UPDATE_ID) {
            bmworkName = "bmwork";
            bmworkBlock = auth->mCreateParams.mAlloc(bmworkName, AUTH_BMWORK_BYTES);
            if (bmworkBlock == NULL) {
                gAuth->mReturncode = AUTH_RETURN_FAILED;
                return 2;
            }
            if (DWCi_AUTH_UpDateWiFiID(&gAuthWiFiInfo, (u8 *) (((u32) bmworkBlock + 0x1f) & ~0x1f)) != 1) {
                gAuth->mCreateParams.mFree(bmworkName, bmworkBlock, 0);
                gAuth->mReturncode = AUTH_RETURN_FAILED;
                return 0xe;
            }
            gAuth->mCreateParams.mFree(bmworkName, bmworkBlock, 0);
        }
        return 0x14;
    }
    switch (auth->mReturncode) {
        case AUTH_RETURN_REMAKE_ID:
            if (DWCi_AUTH_RemakeWiFiID(&gAuthWiFiInfo) == 0) {
                gAuth->mReturncode = AUTH_RETURN_REMAKE_ID;
                return 0xe;
            }
            gAuth->mReturncode = AUTH_RETURN_REMAKE_ID;
            return 0xf;
        case AUTH_RETURN_WRITE_NEW_ID:
            bmworkName = "bmwork";
            bmworkBlock = auth->mCreateParams.mAlloc(bmworkName, AUTH_BMWORK_BYTES);
            if (bmworkBlock == NULL) {
                gAuth->mReturncode = AUTH_RETURN_WRITE_NEW_ID;
                return 2;
            }
            if (WriteNewWiFiInfoToNvram(((u32) bmworkBlock + 0x1f) & ~0x1f) != 1) {
                gAuth->mCreateParams.mFree(bmworkName, bmworkBlock, 0);
                gAuth->mReturncode = AUTH_RETURN_WRITE_NEW_ID;
                return 0xe;
            }
            gAuth->mCreateParams.mFree(bmworkName, bmworkBlock, 0);
            gAuth->mReturncode = AUTH_RETURN_WRITE_NEW_ID;
            return 0x10;
    }
    return 0x11;
}

s32 DWCi_Auth_FillResult(void) {
    s32 returnCode;
    const char *endPointer;
    DWCAuth *auth;
    endPointer = NULL;
    returnCode = StrtolBase10(DWC_Http_GetResult(gAuth->mHttpLabelvalue, 0x20, "httpresult"));
    if (gLibErrorCode == 0x22) {
        gAuth->mReturncode = AUTH_RETURN_BAD_RESPONSE;
        return 0xb;
    }
    if (returnCode != 200) {
        gAuth->mReturncode = returnCode + AUTH_RETURN_HTTP_STATUS_BASE;
        return 0x11;
    }
    auth = gAuth;
    if (DWC_Http_GetBase64DecodedResult(auth->mHttpLabelvalue, 0x20, "returncd", auth->mRetcode, 4) <= 0) {
        gAuth->mReturncode = AUTH_RETURN_BAD_RESPONSE;
        return 0xd;
    }
    returnCode = strtol(gAuth->mRetcode, &endPointer, 10);
    auth = gAuth;
    if (endPointer != auth->mRetcode + strlen(auth->mRetcode)) {
        auth->mReturncode = AUTH_RETURN_BAD_RESPONSE;
        return 0xb;
    }
    auth->mReturncode = returnCode + AUTH_RETURN_SERVER_BASE;
    if (returnCode < 100) {
        gAuth->mToken[0] = 0;
        gAuth->mLocator[0] = 0;
        gAuth->mChallenge[0] = 0;
        gAuth->mDatetime[0] = 0;
        gAuth->mCookie[0] = 0;
        DWC_Http_GetBase64DecodedResult(gAuth->mHttpLabelvalue, 0x20, "token", gAuth->mToken, 0x12d);
        DWC_Http_GetBase64DecodedResult(gAuth->mHttpLabelvalue, 0x20, "locator", gAuth->mLocator, 0x33);
        DWC_Http_GetBase64DecodedResult(gAuth->mHttpLabelvalue, 0x20, "challenge", gAuth->mChallenge, 9);
        DWC_Http_GetBase64DecodedResult(gAuth->mHttpLabelvalue, 0x20, "datetime", gAuth->mDatetime, 0xf);
        DWC_Http_GetRawResult(gAuth->mHttpLabelvalue, 0x20, "Set-Cookie", gAuth->mCookie, 0x41);
        gAuth->mCookie[0x2b] = 0;
    }
    return 0;
}

u32 DWCi_Auth_Prepare_FirstPost(Http *http, const char *gsbrcd, const char *ingamesn, DWCHttpLabelValue *labelValues,
                                s32 labelValueCount, s32 getWiFiInfoFromFlash) {
    AuthFirstPostValues postData;
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
    OS_GetMacAddress(postData.mMacAddress);
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
    MI_CpuCopy8(bssidPointer, postData.mBssid, 6);
    MI_CpuFill8(apInfoBytes, 0, sizeof(apInfoBytes));
    apInfoPointer = WCM_GetApEssid(&postData.mEssidLength);
    if (apInfoPointer == NULL) {
        OS_RestoreInterrupts(interruptState);
        return 3;
    }
    MI_CpuCopy8(apInfoPointer, apInfoBytes, postData.mEssidLength);
    OS_RestoreInterrupts(interruptState);
    MI_CpuCopy8((const void *) 0x27ffe0c, postData.mGameCode, 4);
    postData.mGameCode[4] = 0;
    MI_CpuCopy8((const void *) 0x27ffe10, postData.mMakerCode, 2);
    postData.mMakerCode[2] = 0;
    macCursor = postData.mMacAddress;
    for (macIndex = 0; macIndex < 6; macCursor++, macIndex++) {
        OS_SPrintf(&macAddressText[macIndex * 2], "%02x", *macCursor);
    }
    macAddressText[12] = 0;
    if (ownerInfo.mLanguage > 6) {
        ownerInfo.mLanguage = 1;
    }
    OS_SNPrintf(postData.mBirthday, 5, "%02x%02x", ownerInfo.mBirthdayMonth, ownerInfo.mBirthdayDay);
    OS_SNPrintf(deviceTimeText, 0xd, "%02d%02d%02d%02d%02d%02d", date.mYear, date.mMonth, date.mDay, time.mHour,
                time.mMinute, time.mSecond);
    MI_CpuCopy8(ownerInfo.mNickName, deviceName, sizeof(ownerInfo.mNickName));
    deviceName[0x14] = 0;
    MI_CpuFill8(&results, 0, 0xc);
    results.mEntries = labelValues;
    results.mCapacity = labelValueCount;
    if (getWiFiInfoFromFlash != 1) {
        if (gAuthWiFiInfo.mAttestedUserId == 0) {
            DWCi_Http_AddResult(&results, "action", "acctcreate");
        } else {
            if (strlen(gsbrcd) == 0) {
                return 6;
            }
            DWCi_Http_AddResult(&results, "action", "login");
            DWCi_Http_AddResult(&results, "gsbrcd", gsbrcd);
            if (strlen(ingamesn) != 0) {
                DWCi_Http_AddResult(&results, "ingamesn", ingamesn);
            }
        }
    } else {
        DWCi_BM_GetWiFiInfo(&gAuthWiFiInfo);
    }
    DWCi_Http_AddResult(&results, "sdkver", "001000");
    if (gAuthWiFiInfo.mAttestedUserId != 0) {
        OS_SNPrintf(userIdText, 0xe, "%013llu", gAuthWiFiInfo.mAttestedUserId);
    } else {
        OS_SNPrintf(userIdText, 0xe, "%013llu", gAuthWiFiInfo.mNotAttestedId);
    }
    DWCi_Http_AddResult(&results, "userid", userIdText);
    OS_SNPrintf(postData.mPassword, 4, "%03u", gAuthWiFiInfo.mPass);
    DWCi_Http_AddResult(&results, "passwd", postData.mPassword);
    OS_SNPrintf(bssidText, 0xd, "%02x%02x%02x%02x%02x%02x", postData.mBssid[0], postData.mBssid[1], postData.mBssid[2],
                postData.mBssid[3], postData.mBssid[4], postData.mBssid[5]);
    OS_SNPrintf(apInfoText, 0xd, "%02d:0000000-00", 0);
    DWCi_AC_GetPostalCode(apInfoBytes, &apInfoText[3]);
    DWCi_Http_AddResult(&results, "gamecd", postData.mGameCode);
    DWCi_Http_AddResult(&results, "makercd", postData.mMakerCode);
    DWCi_Http_AddResult(&results, "unitcd", "0");
    DWCi_Http_AddResult(&results, "macadr", macAddressText);
    DWCi_Http_AddResult(&results, "lang", gLangPairValues[ownerInfo.mLanguage]);
    DWCi_Http_AddResult(&results, "birth", postData.mBirthday);
    DWCi_Http_AddResult(&results, "devtime", deviceTimeText);
    DWCi_Http_AddResult(&results, "bssid", bssidText);
    DWCi_Http_AddResult(&results, "apinfo", apInfoText);
    if (DWC_Http_Add_HeaderItem(http, "User-Agent", "Nitro WiFi SDK/1.0") != FALSE) {
        return 7;
    }
    if (DWC_Http_Add_HeaderItem(http, "HTTP_X_GAMECD", postData.mGameCode) != FALSE) {
        return 7;
    }
    for (postItemCount = 0; labelValues->mFirst != NULL; labelValues++, postItemCount++) {
        postValue = labelValues->mSecond;
        if (DWC_Http_Add_PostBase64Item(http, labelValues->mFirst, postValue, strlen(postValue)) != FALSE) {
            return 8;
        }
    }
    if (DWC_Http_Add_PostBase64Item(http, "devname", deviceName, 0x14) != FALSE) {
        return 8;
    }
    return 0;
}

void DWCi_Auth_SetError(s32 error) {
    OS_LockMutex(&gAuth->mMutex);
    gAuth->mError = error;
    OS_UnlockMutex(&gAuth->mMutex);
}
