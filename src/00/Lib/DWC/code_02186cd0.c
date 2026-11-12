#include "00/code_02186d04.h"
#include "00/unk_021b1000.h"
#include "03/Net/essid_wcm.h"
#include "00/Lib/CPS/code_021ad734.h"
#include "00/Lib/CPS/network.h"
#include "00/Lib/DWC/code_02186a9c.h"
#include "00/code_02186000.h"
#include "00/Lib/DWC/code_02185954.h"
#include "00/Lib/CPS/code_021a9200.h"
#include "00/Lib/CPS/code_021a9228.h"
#include "os_printf.h"
#include "os_thread.h"
#include "os_tick.h"
#include "code_0200fe74.h"
#include "code_0213a460.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200edc0.h"
#include "code_0200e77c.h"
#include "00/code_02187484.h"
#include "00/unk_021b4000.h"
#include "code_0200fc8c.h"
#include "dwc_backup.h"

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

s32 DWC_Http_Create(Http *http, const DWCHttpParam *param) {
    MI_CpuFill8(http, 0, 0x1a60);
    http->mContentLength = -1;
    http->mParam = *param;
    http->mLowReceiveBuffer = http->mParam.mAlloc(gHttpLowReceiveBufferName, 0xb68);
    if (http->mLowReceiveBuffer == NULL) {
        http->mResult = 1;
        return 1;
    }
    http->mLowSendBuffer = http->mParam.mAlloc(gHttpLowSendBufferName, 0x5ea);
    if (http->mLowSendBuffer == NULL) {
        http->mResult = 1;
        return 1;
    }
    DWCi_Http_SetHostinfo(http, param->mUrl);
    http->mResult = DWCi_Http_WriteBasicHeader(http);
    if (http->mResult == 0) {
        http->mInitFlag = 0xff;
    }
    return http->mResult;
}

u32 DWC_Http_FinishHeader(Http *http) {
    char contentLengthText[8];
    u32 contentLength;
    if (DWC_Http_Add_HeaderItem(http, gConnectionHeaderName, gConnectionCloseValue) != FALSE) {
        return 1;
    }
    contentLength = strlen(strstr(http->mSendBuffer.mStart, gHttpHeaderEndMarker) + 4);
    if (contentLength != 0) {
        OS_SNPrintf(contentLengthText, 7, gContentLengthFormat, contentLength);
        if (DWC_Http_Add_HeaderItem(http, gContentLengthHeaderName, contentLengthText) != FALSE) {
            return 1;
        }
    }
    return 0;
}

void DWC_Http_StartThread(Http *http) {
    u32 priority;
    priority = OS_GetThreadPriority(OSi_ThreadInfo.mCurrentThread);
    http->mAbort = FALSE;
    OS_InitMutex(&http->mAbortMutex);
    OS_InitMutex(&http->mReceiveMutex);
    if (http->mParam.mIgnoreCa == 1) {
        DWChttpignoreca = 1;
    } else {
        DWChttpignoreca = 0;
    }
    if (http->mThread.mId == 0 || OS_IsThreadTerminated(&http->mThread) != 0) {
        OS_CreateThread(&http->mThread, DWCi_Http_Thread, http, http->mThreadStackBottom, 0x1000, priority - 1);
        OS_WakeupThreadDirect(&http->mThread);
    }
}

void DWC_Http_Abort(Http *http) {
    if (http->mInitFlag == 0xff) {
        OS_LockMutex(&http->mAbortMutex);
        http->mAbort = TRUE;
        OS_UnlockMutex(&http->mAbortMutex);
        if (http->mThread.mId != 0) {
            OS_JoinThread(&http->mThread);
        }
    }
}

u32 SleepUnlessHttpAborted(Http *http) {
    OS_LockMutex(&http->mAbortMutex);
    if (http->mAbort == TRUE) {
        OS_UnlockMutex(&http->mAbortMutex);
        return 0;
    }
    OS_UnlockMutex(&http->mAbortMutex);
    OS_Sleep(10);
    return 1;
}

void DWCi_Http_Thread(void *argument) {
    Http *http = argument;
    HttpB4 *socketBuffers;
    Http118 *sslInfo;
    HttpBuffer *receiveBuffer;
    const u8 *receivedData;
    s32 timeoutMillis;
    int hostAddress;
    u64 startTick;
    u64 entropyTick;
    u8 headerReceived;
    int port;
    u32 copyLength;
    s32 bufferSpace;
    u64 nowTick;
    s8 *lengthEnd;
    s8 savedByte;
    s32 n;
    LowEntropyData entropyData;
    char *s;
    const char *contentLengthText;

    headerReceived = 0;
    socketBuffers = &http->mSoc;
    sslInfo = &http->mHttpsState;
    receiveBuffer = &http->mReceiveBuffer;
    timeoutMillis = http->mParam.mTimeoutMillis;
    if (timeoutMillis <= 0) {
        timeoutMillis = 60000;
    }
    MI_CpuFill8(socketBuffers, 0, 0x64);
    socketBuffers->mReceiveBufferSize = 0xb68;
    socketBuffers->mReceiveBuffer = http->mLowReceiveBuffer;
    socketBuffers->mSendBufferSize = 0x5ea;
    socketBuffers->mSendBuffer = http->mLowSendBuffer;
    CPS_SocRegister(socketBuffers);
    hostAddress = CPS_Resolve(http->mHost);
    if (hostAddress == 0) {
        http->mResult = 2;
        return;
    }
    CPS_SocUse();
    if (http->mUseHttps == 1) {
        MI_CpuFill8(sslInfo, 0, 0x804);
        sslInfo->mUnk_7e4 = DWCi_Http_CPSCallback;
        sslInfo->mUnk_7d4 = http->mHost;
        socketBuffers->mUnk_0c = sslInfo;
        SetAuthorityTable((u32) gCaInfoTable, 0xb);
        CPS_SetSsl(1);
        port = 0x1bb;
    } else {
        port = 0x50;
    }
    CPS_SocBind(0, port, hostAddress);
    startTick = OS_GetTick();
    if (http->mUseHttps == 1) {
        OS_GetLowEntropyData(&entropyData);
        MixBytesIntoRandomState(&entropyData, 0x20);
        entropyTick = startTick;
    }
    if (CPS_TcpConnect() != 0) {
        http->mResult = 3;
        CPS_SocRelease();
        CPS_SocUnRegister();
        return;
    }
    http->mSendBuffer.mCursor = http->mSendBuffer.mStart;
    s = http->mSendBuffer.mStart;
    http->mSendBuffer.mEnd = s + strlen(s);
    while (http->mSendBuffer.mCursor < http->mSendBuffer.mEnd) {
        if (CPSMyIp == 0) {
            http->mResult = 5;
            goto fail;
        }
        n = http->mSendBuffer.mEnd - http->mSendBuffer.mCursor;
        if (n > 0x238) {
            n = 0x238;
        }
        n = CPS_SocWrite((const u8 *) http->mSendBuffer.mCursor, n);
        if (n <= 0) {
            http->mResult = 5;
            goto fail;
        }
        CPS_SocFlush();
        nowTick = OS_GetTick();
        if ((u64) timeoutMillis < (nowTick - startTick) * 64 / 0x82ea) {
            http->mResult = 4;
            goto fail;
        }
        if (http->mUseHttps == 1) {
            if (1000 < (nowTick - entropyTick) * 64 / 0x82ea) {
                OS_GetLowEntropyData(&entropyData);
                MixBytesIntoRandomState(&entropyData, 0x20);
                entropyTick = nowTick;
            }
        }
        http->mSendBuffer.mCursor += n;
        if (SleepUnlessHttpAborted(http) == 0) {
            http->mResult = 7;
            goto fail;
        }
    }
    FreeHttpBuffer(http, &http->mSendBuffer);
    OS_LockMutex(&http->mReceiveMutex);
    if (http->mParam.mReceiveBufferStart == NULL) {
        if (InitHttpBuffer(http, &http->mReceiveBuffer, http->mParam.mReceiveBufferSize) == 0) {
            http->mResult = 1;
            OS_UnlockMutex(&http->mReceiveMutex);
            goto fail;
        }
    } else {
        http->mReceiveBuffer.mStart = http->mParam.mReceiveBufferStart;
        http->mReceiveBuffer.mCursor = http->mReceiveBuffer.mStart;
        http->mReceiveBuffer.mEnd = http->mReceiveBuffer.mStart + http->mParam.mReceiveBufferSize;
        http->mReceiveBuffer.mSize = http->mParam.mReceiveBufferSize;
    }
    receiveBuffer->mCursor = receiveBuffer->mStart;
    receiveBuffer->mEnd = receiveBuffer->mStart + receiveBuffer->mSize;
    OS_UnlockMutex(&http->mReceiveMutex);
    while (1) {
        if (CPSMyIp == 0) {
            http->mResult = 5;
            goto fail;
        }
        OS_LockMutex(&http->mReceiveMutex);
        if (receiveBuffer->mCursor >= receiveBuffer->mEnd - 1) {
            OS_UnlockMutex(&http->mReceiveMutex);
            break;
        }
        n = CPS_SocGetLength();
        if (n > 0) {
            receivedData = CPS_SocRead((u32 *) &n);
            if (receivedData == NULL) {
                OS_UnlockMutex(&http->mReceiveMutex);
                break;
            }
            bufferSpace = receiveBuffer->mEnd - 1 - receiveBuffer->mCursor;
            copyLength = n;
            if ((s32) copyLength >= bufferSpace) {
                copyLength = bufferSpace;
            }
            MI_CpuCopy8(receivedData, receiveBuffer->mCursor, copyLength);
            receiveBuffer->mCursor += copyLength;
            *receiveBuffer->mCursor = 0;
            if (headerReceived != 1) {
                s = receiveBuffer->mStart;
                if (strstr(s, gHttpHeaderEndMarker) != NULL) {
                    headerReceived = 1;
                    http->mBodyStart = strstr(s, gHttpHeaderEndMarker) + 4;
                    contentLengthText = strstr(receiveBuffer->mStart, gContentLengthHeaderText);
                    if (contentLengthText != NULL) {
                        contentLengthText = contentLengthText + strlen(gContentLengthHeaderText);
                        lengthEnd = (s8 *) strstr(contentLengthText, gHttpLineEndMarker);
                        savedByte = *lengthEnd;
                        *lengthEnd = 0;
                        http->mContentLength = StrtolBase10(contentLengthText);
                        *lengthEnd = savedByte;
                    }
                }
            }
            if (n > copyLength) {
                CPS_SocConsume(n);
                OS_UnlockMutex(&http->mReceiveMutex);
                break;
            }
            CPS_SocConsume(copyLength);
        }
        if (n < 0) {
            OS_UnlockMutex(&http->mReceiveMutex);
            break;
        }
        if (http->mContentLength > 0 && n > 0 && http->mBodyStart + http->mContentLength <= receiveBuffer->mCursor) {
            OS_UnlockMutex(&http->mReceiveMutex);
            break;
        }
        nowTick = OS_GetTick();
        if ((u64) timeoutMillis < (nowTick - startTick) * 64 / 0x82ea) {
            http->mResult = 6;
            OS_UnlockMutex(&http->mReceiveMutex);
            goto fail;
        }
        if (http->mUseHttps == 1) {
            if (1000 < (nowTick - entropyTick) * 64 / 0x82ea) {
                OS_GetLowEntropyData(&entropyData);
                MixBytesIntoRandomState(&entropyData, 0x20);
                entropyTick = nowTick;
            }
        }
        OS_UnlockMutex(&http->mReceiveMutex);
        if (SleepUnlessHttpAborted(http) == 0) {
            http->mResult = 7;
            goto fail;
        }
    }
    CPS_TcpShutdown();
    CPS_TcpClose();
    CPS_SocRelease();
    CPS_SocUnRegister();
    http->mResult = 8;
    return;
fail:
    CPS_TcpShutdown();
    CPS_TcpClose();
    CPS_SocRelease();
    CPS_SocUnRegister();
}

void ReleaseHttp(Http *a) {
    if (a != NULL) {
        if (a->mParam.mReceiveBufferStart == NULL) {
            FreeHttpBuffer(a, &a->mReceiveBuffer);
        }
        FreeHttpBuffer(a, &a->mSendBuffer);
        if (a->mLowReceiveBuffer != NULL) {
            a->mParam.mFree(gHttpLowReceiveBufferName, a->mLowReceiveBuffer, 0);
            a->mLowReceiveBuffer = NULL;
        }
        if (a->mLowSendBuffer != NULL) {
            a->mParam.mFree(gHttpLowSendBufferName, a->mLowSendBuffer, 0);
            a->mLowSendBuffer = NULL;
        }
        MI_CpuFill8(a, 0, 0x1a60);
    }
}
