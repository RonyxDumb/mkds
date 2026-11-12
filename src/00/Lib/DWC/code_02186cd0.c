#include "00/Lib/DWC/code_02188008.h"
#include "00/code_02186000.h"
#include "00/unk_021b1000.h"
#include "03/Net/essid_packet_steps.h"
#include "00/code_02186d04.h"
#include "00/Lib/DWC/code_02188694.h"
#include "00/unk_021b4000.h"
#include "os_thread.h"
#include "code_02133048.h"
#include "code_02133274.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "code_0200edc0.h"
#include "00/Lib/CPS/network.h"
#include "00/Lib/DWC/code_02186a9c.h"
#include "00/Lib/DWC/code_02185954.h"
#include "00/Lib/CPS/code_021a9200.h"
#include "00/Lib/CPS/code_021a9228.h"
#include "os_printf.h"
#include "os_tick.h"
#include "code_0200fe74.h"
#include "code_0213a460.h"
#include "Main/Net/data_0216f000.h"
#include "mb_data.h"
#include "code_0200e77c.h"
#include "00/code_02187484.h"
#include "code_0200fc8c.h"
#include "dwc_backup.h"
#include "code_02134008.h"

u32 DWC_Netcheck_Create(DWCNetcheckParam *param) {
    if (gNetcheck != NULL) {
        return 4;
    }
    gNetcheck = param->mAlloc(gNetcheckName, 0x1200);
    if (gNetcheck == NULL) {
        return 4;
    }
    MI_CpuFill8(gNetcheck, 0, 0x1200);
    gNetcheck->mReturnCode = -99999;
    gNetcheck->mParam = *param;
    if (gHttp != NULL) {
        return 4;
    }
    gHttp = gNetcheck->mParam.mAlloc(gHttpName, 0x1a60);
    if (gHttp == NULL) {
        return 4;
    }
    OS_InitMutex(&gNetcheck->mMutex);
    DWCi_Netcheck_StartThread();
    return 0;
}

void DWC_Netcheck_Destroy(void) {
    if (gHttp != NULL) {
        ReleaseHttp((Http *) gHttp);
        gNetcheck->mParam.mFree(gHttpName, gHttp, 0);
        gHttp = NULL;
    }
    DWC_Auth_Destroy();
    if (gNetcheck != NULL) {
        if (gNetcheck->mBody302 != NULL) {
            gNetcheck->mParam.mFree(gNetcheckBody302Name, gNetcheck->mBody302, 0);
            gNetcheck->mBody302 = NULL;
        }
        if (gNetcheck->mBodyWayport != NULL) {
            gNetcheck->mParam.mFree(gNetcheckBodyWayportName, gNetcheck->mBodyWayport, 0);
            gNetcheck->mBodyWayport = NULL;
        }
        gNetcheck->mParam.mFree(gNetcheckName, gNetcheck, 0);
        gNetcheck = NULL;
    }
}

void DWCi_Netcheck_StartThread(void) {
    if (gNetcheck->mThread.mId == 0 || OS_IsThreadTerminated(&gNetcheck->mThread) != 0) {
        OS_CreateThread(&gNetcheck->mThread, (void (*)(void *)) DWCi_Netcheck_Thread, gNetcheck,
                        gNetcheck->mThreadStack, 0x1000, 0x10);
        OS_WakeupThreadDirect(&gNetcheck->mThread);
    }
}

void DWC_Netcheck_Abort(void) {
    if (gNetcheck != NULL) {
        if (gHttp != NULL) {
            DWC_Http_Abort(gHttp);
        }
        DWC_Auth_Abort();
        if (gNetcheck->mThread.mId != 0) {
            OS_JoinThread(&gNetcheck->mThread);
        }
        gNetcheck->mReturnCode = 0xfffffff9;
    }
}

void DWCi_Netcheck_Thread(void) {
    DWCAuthResult authResult;
    DWCWiFiInfo wiFiInfo;
    char ssidText[0x24];
    char retcodeText[4];
    u16 ssidLength;
    char *urlText;
    s32 urlLength;
    char *dataText;
    s32 dataLength;
    char *waitText;
    s32 waitMillis;
    char *t;
    char *s;
    s32 waitLength;
    s32 decodedLength;
    s32 r;
    u32 interruptState;
    Http *http;
    DWCNetcheck *netcheck;

    urlText = NULL;
    dataText = NULL;
    waitText = NULL;
    for (;;) {
        gHttpParam.mUrl = gConnTestUrl;
        gHttpParam.mAction = TRUE;
        gHttpParam.mReceiveBufferStart = NULL;
        gHttpParam.mReceiveBufferSize = 0x1000;
        gHttpParam.mAlloc = gNetcheck->mParam.mAlloc;
        gHttpParam.mFree = gNetcheck->mParam.mFree;
        gHttpParam.mTimeoutMillis = 20000;
        gNetcheck->mReturnCode = -2;
        if (DWC_Http_Create(gHttp, &gHttpParam) != 0) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(1);
            break;
        }
        if (DWC_Http_FinishHeader(gHttp) != 0) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(1);
            break;
        }
        DWC_Http_StartThread(gHttp);
        if (gHttp->mThread.mId != 0) {
            OS_JoinThread(&gHttp->mThread);
        }
        http = gHttp;
        switch (http->mResult) {
            case 2:
                gNetcheck->mReturnCode = -1;
            default:
                ReleaseHttp(gHttp);
                DWCi_Netcheck_SetError(3);
                goto end;
            case 8:
                break;
        }
        if (DWC_Http_ParseResult(gNetcheck->mHttpLabelvalue, 0x20, 0, http->mReceiveBuffer.mStart) != TRUE) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(2);
            break;
        }
        r = StrtolBase10(DWC_Http_GetResult(gNetcheck->mHttpLabelvalue, 0x20, gHttpresultPairName3));
        if (gLibErrorCode == 0x22) {
            DWCi_Netcheck_SetError(2);
            break;
        }
        if (r != 200) {
            if (r == 0x12e) {
                netcheck = gNetcheck;
                if (netcheck->mBodyWayport != NULL) {
                    netcheck->mReturnCode = -6;
                    ReleaseHttp(gHttp);
                    gHttpParam.mUrl = DWCauthhttpparam.mUrl;
                    gHttpParam.mAction = FALSE;
                    gHttpParam.mReceiveBufferStart = NULL;
                    gHttpParam.mReceiveBufferSize = 0x200;
                    gHttpParam.mAlloc = gNetcheck->mParam.mAlloc;
                    gHttpParam.mFree = gNetcheck->mParam.mFree;
                    gHttpParam.mTimeoutMillis = 20000;
                    if (strcmp(gHttpParam.mUrl, data_ov000_021b1400) != 0) {
                        gHttpParam.mIgnoreCa = TRUE;
                    }
                    if (DWC_Http_Create(gHttp, &gHttpParam) != 0) {
                        ReleaseHttp(gHttp);
                        DWCi_Netcheck_SetError(1);
                        break;
                    }
                    if (DWCi_Auth_Prepare_FirstPost(gHttp, data_ov000_021b1420, data_ov000_021b1420,
                                                    gNetcheck->mHttpLabelvalue, 0x20, 1) != 0) {
                        ReleaseHttp(gHttp);
                        DWCi_Netcheck_SetError(8);
                        break;
                    }
                    if (DWC_Http_Add_PostBase64Item(gHttp, gActionPairName2, gMessagePairValue, 7) != FALSE) {
                        ReleaseHttp(gHttp);
                        DWCi_Netcheck_SetError(8);
                        break;
                    }
                    interruptState = OS_DisableInterrupts();
                    MI_CpuFill8(ssidText, 0, 0x21);
                    WCM_GetApEssid(&ssidLength);
                    MI_CpuCopy8(WCM_GetApEssid(NULL), ssidText, ssidLength);
                    OS_RestoreInterrupts(interruptState);
                    if (DWC_Http_Add_PostBase64Item(gHttp, gSsidPairName, ssidText, strlen(ssidText)) != FALSE) {
                        ReleaseHttp(gHttp);
                        DWCi_Netcheck_SetError(8);
                        break;
                    }
                    s = gNetcheck->mBodyWayport;
                    if (DWC_Http_Add_PostBase64Item(gHttp, gHotSpotResponsePairName, s, strlen(s)) != FALSE) {
                        ReleaseHttp(gHttp);
                        DWCi_Netcheck_SetError(8);
                        break;
                    }
                    netcheck = gNetcheck;
                    netcheck->mParam.mFree(gNetcheckBodyWayportName, netcheck->mBodyWayport, 0);
                    gNetcheck->mBodyWayport = NULL;
                    if (DWC_Http_FinishHeader(gHttp) != 0) {
                        ReleaseHttp(gHttp);
                        DWCi_Netcheck_SetError(1);
                        break;
                    }
                    DWC_Http_StartThread(gHttp);
                    if (gHttp->mThread.mId != 0) {
                        OS_JoinThread(&gHttp->mThread);
                    }
                    http = gHttp;
                    switch (http->mResult) {
                        case 2:
                            gNetcheck->mReturnCode = -1;
                        default:
                            ReleaseHttp(gHttp);
                            DWCi_Netcheck_SetError(3);
                            goto end;
                        case 8:
                            ReleaseHttp(http);
                            DWCi_Netcheck_SetError(7);
                            goto end;
                    }
                }
                s = DWC_Http_GetResult(netcheck->mHttpLabelvalue, 0x20, gHttpbodyPairName2);
                if (s == NULL) {
                    ReleaseHttp(gHttp);
                    DWCi_Netcheck_SetError(2);
                    break;
                }
                gNetcheck->mBody302 = gNetcheck->mParam.mAlloc(gNetcheckBody302Name, strlen(s) + 1);
                t = gNetcheck->mBody302;
                if (t == NULL) {
                    ReleaseHttp(gHttp);
                    DWCi_Netcheck_SetError(4);
                    break;
                }
                strncpy(t, s, strlen(s));
            } else {
                ReleaseHttp(gHttp);
                DWCi_Netcheck_SetError(10);
                break;
            }
        }
        ReleaseHttp(gHttp);
        DWCi_BM_GetWiFiInfo(&wiFiInfo);
        if (wiFiInfo.mAttestedUserId == 0) {
            gNetcheck->mReturnCode = -3;
            gAuthParam.mIngamesn[0] = 0;
            gAuthParam.mGsbrcd[0] = 0;
            gAuthParam.mAlloc = gNetcheck->mParam.mAlloc;
            gAuthParam.mFree = gNetcheck->mParam.mFree;
            if (DWC_Auth_Create(&gAuthParam, gHttp) != 0) {
                DWCi_Netcheck_SetError(5);
                break;
            }
            DWC_Auth_Join();
            if (DWC_Auth_GetError() != 20) {
                if (DWC_Auth_GetError() == 9) {
                    gNetcheck->mReturnCode = -1;
                } else {
                    DWC_Auth_GetResult(&authResult.mReturnCode);
                    gNetcheck->mReturnCode = authResult.mReturnCode;
                }
                DWCi_Netcheck_SetError(6);
                break;
            }
            DWC_Auth_Destroy();
        }
        if (r == 200) {
            gNetcheck->mReturnCode = 0;
            DWCi_Netcheck_SetError(11);
            break;
        }
        gNetcheck->mReturnCode = -4;
        gHttpParam.mUrl = DWCauthhttpparam.mUrl;
        gHttpParam.mAction = FALSE;
        gHttpParam.mReceiveBufferStart = NULL;
        gHttpParam.mReceiveBufferSize = 0x1000;
        gHttpParam.mAlloc = gNetcheck->mParam.mAlloc;
        gHttpParam.mFree = gNetcheck->mParam.mFree;
        gHttpParam.mTimeoutMillis = 40000;
        if (strcmp(gHttpParam.mUrl, data_ov000_021b1400) != 0) {
            gHttpParam.mIgnoreCa = TRUE;
        }
        if (DWC_Http_Create(gHttp, &gHttpParam) != 0) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(1);
            break;
        }
        if (DWCi_Auth_Prepare_FirstPost(gHttp, data_ov000_021b1420, data_ov000_021b1420, gNetcheck->mHttpLabelvalue,
                                        0x20, 1) != 0) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(8);
            break;
        }
        if (DWC_Http_Add_PostBase64Item(gHttp, gActionPairName2, gParsePairValue, 5) != FALSE) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(8);
            break;
        }
        interruptState = OS_DisableInterrupts();
        MI_CpuFill8(ssidText, 0, 0x21);
        WCM_GetApEssid(&ssidLength);
        MI_CpuCopy8(WCM_GetApEssid(NULL), ssidText, ssidLength);
        OS_RestoreInterrupts(interruptState);
        if (DWC_Http_Add_PostBase64Item(gHttp, gSsidPairName, ssidText, strlen(ssidText)) != FALSE) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(8);
            break;
        }
        s = gNetcheck->mBody302;
        if (DWC_Http_Add_PostBase64Item(gHttp, gHtmlPairName, s, strlen(s)) != FALSE) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(8);
            break;
        }
        netcheck = gNetcheck;
        netcheck->mParam.mFree(gNetcheckBody302Name, netcheck->mBody302, 0);
        gNetcheck->mBody302 = NULL;
        if (DWC_Http_FinishHeader(gHttp) != 0) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(1);
            break;
        }
        DWC_Http_StartThread(gHttp);
        if (gHttp->mThread.mId != 0) {
            OS_JoinThread(&gHttp->mThread);
        }
        http = gHttp;
        switch (http->mResult) {
            case 2:
                gNetcheck->mReturnCode = -1;
            default:
                ReleaseHttp(gHttp);
                DWCi_Netcheck_SetError(3);
                goto end;
            case 8:
                break;
        }
        if (DWC_Http_ParseResult(gNetcheck->mHttpLabelvalue, 0x20, 0, http->mReceiveBuffer.mStart) != TRUE) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(2);
            break;
        }
        r = StrtolBase10(DWC_Http_GetResult(gNetcheck->mHttpLabelvalue, 0x20, gHttpresultPairName3));
        if (gLibErrorCode == 0x22) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(2);
            break;
        }
        if (r != 200) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(2);
            break;
        }
        if (DWC_Http_GetBase64DecodedResult(gNetcheck->mHttpLabelvalue, 0x20, gReturncdPairName2, retcodeText, 4) <=
            0) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(9);
            break;
        }
        r = StrtolBase10(retcodeText);
        if (gLibErrorCode == 0x22) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(9);
            break;
        }
        if (r >= 100) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(6);
            break;
        }
        urlLength = DWC_Http_GetBase64DecodedResult(gNetcheck->mHttpLabelvalue, 0x20, gUrlPairName, NULL, 0);
        if (urlLength <= 0) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(9);
            break;
        }
        dataLength = DWC_Http_GetBase64DecodedResult(gNetcheck->mHttpLabelvalue, 0x20, gDataPairName, NULL, 0);
        if (dataLength <= 0) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(9);
            break;
        }
        waitLength = DWC_Http_GetBase64DecodedResult(gNetcheck->mHttpLabelvalue, 0x20, gWaitPairName, NULL, 0);
        urlText = gNetcheck->mParam.mAlloc(gUrlPairName, urlLength + 1);
        if (urlText == NULL) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(4);
            break;
        }
        dataText = gNetcheck->mParam.mAlloc(gDataPairName, dataLength + 1);
        if (dataText == NULL) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(4);
            break;
        }
        if (waitLength > 0) {
            waitText = gNetcheck->mParam.mAlloc(gWaitPairName, waitLength + 1);
            if (waitText == NULL) {
                ReleaseHttp(gHttp);
                DWCi_Netcheck_SetError(4);
                break;
            }
        }
        decodedLength =
            DWC_Http_GetBase64DecodedResult(gNetcheck->mHttpLabelvalue, 0x20, gUrlPairName, urlText, urlLength + 1);
        if (decodedLength < 0) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(9);
            break;
        }
        urlText[decodedLength] = 0;
        decodedLength =
            DWC_Http_GetBase64DecodedResult(gNetcheck->mHttpLabelvalue, 0x20, gDataPairName, dataText, dataLength + 1);
        if (decodedLength < 0) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(9);
            break;
        }
        dataText[decodedLength] = 0;
        waitMillis = 0;
        if (waitLength > 0) {
            decodedLength = DWC_Http_GetBase64DecodedResult(gNetcheck->mHttpLabelvalue, 0x20, gWaitPairName, waitText,
                                                            waitLength + 1);
            if (decodedLength < 0) {
                ReleaseHttp(gHttp);
                DWCi_Netcheck_SetError(9);
                break;
            }
            waitText[decodedLength] = 0;
            waitMillis = StrtolBase10(waitText);
            if (gLibErrorCode == 0x22) {
                ReleaseHttp(gHttp);
                DWCi_Netcheck_SetError(9);
                break;
            }
            waitMillis *= 1000;
            if (waitMillis > 180000) {
                waitMillis = 180000;
            }
        }
        ReleaseHttp(gHttp);
        gNetcheck->mReturnCode = -5;
        gHttpParam.mUrl = urlText;
        gHttpParam.mAction = FALSE;
        gHttpParam.mReceiveBufferStart = NULL;
        gHttpParam.mReceiveBufferSize = 0x1000;
        gHttpParam.mAlloc = gNetcheck->mParam.mAlloc;
        gHttpParam.mFree = gNetcheck->mParam.mFree;
        gHttpParam.mTimeoutMillis = 40000;
        if (DWC_Http_Create(gHttp, &gHttpParam) != 0) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(1);
            break;
        }
        if (DWC_Http_Add_Body(gHttp, dataText) != FALSE) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(8);
            break;
        }
        if (DWC_Http_FinishHeader(gHttp) != 0) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(1);
            break;
        }
        DWC_Http_StartThread(gHttp);
        if (gHttp->mThread.mId != 0) {
            OS_JoinThread(&gHttp->mThread);
        }
        http = gHttp;
        switch (http->mResult) {
            case 2:
                gNetcheck->mReturnCode = -1;
            default:
                ReleaseHttp(gHttp);
                DWCi_Netcheck_SetError(3);
                goto end;
            case 8:
                break;
        }
        if (DWC_Http_ParseResult(gNetcheck->mHttpLabelvalue, 0x20, 1, http->mReceiveBuffer.mStart) != TRUE) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(2);
            break;
        }
        s = DWC_Http_GetResult(gNetcheck->mHttpLabelvalue, 0x20, gHttpbodyPairName2);
        if (s == NULL) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(2);
            break;
        }
        gNetcheck->mBodyWayport = gNetcheck->mParam.mAlloc(gNetcheckBodyWayportName, strlen(s) + 1);
        t = gNetcheck->mBodyWayport;
        if (t == NULL) {
            ReleaseHttp(gHttp);
            DWCi_Netcheck_SetError(4);
            break;
        }
        strncpy(t, s, strlen(s));
        ReleaseHttp(gHttp);
        OS_Sleep(waitMillis);
    }
end:
    if (urlText != NULL) {
        gNetcheck->mParam.mFree(gUrlPairName, urlText, 0);
    }
    if (dataText != NULL) {
        gNetcheck->mParam.mFree(gDataPairName, dataText, 0);
    }
    if (waitText != NULL) {
        gNetcheck->mParam.mFree(gWaitPairName, waitText, 0);
    }
}

u32 DWC_Netcheck_GetError(void) {
    u32 v1;
    OS_LockMutex(&gNetcheck->mMutex);
    v1 = gNetcheck->mError;
    OS_UnlockMutex(&gNetcheck->mMutex);
    return v1;
}

void DWCi_Netcheck_SetError(u32 error) {
    OS_LockMutex(&gNetcheck->mMutex);
    gNetcheck->mError = error;
    OS_UnlockMutex(&gNetcheck->mMutex);
}

u32 DWC_Netcheck_GetReturnCode(void) {
    return gNetcheck->mReturnCode;
}
