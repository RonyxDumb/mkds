#include "00/Lib/DWC/network_check_thread.h"
#include "00/Lib/DWC/network_check_control.h"
#include "00/Lib/DWC/auth_http_params.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/DWC/http_transfer.h"
#include "00/Lib/DWC/access_point_alloc.h"
#include "00/Lib/wifi_library_globals.h"
#include "thread_scheduler.h"
#include "signed_int_divide.h"
#include "unsigned_int_divide.h"
#include "narrow_string_functions.h"
#include "cpu_copy_fill.h"
#include "mutex_init_decl.h"
#include "00/Lib/CPS/tcp_ip_stack.h"
#include "00/Lib/DWC/http_header_build.h"
#include "00/Lib/DWC/server_auth.h"
#include "00/Lib/CPS/https_enable_flag.h"
#include "00/Lib/CPS/https_protocol.h"
#include "formatted_text_to_buffer.h"
#include "tick_counter.h"
#include "model_texture_bind.h"
#include "text_to_number.h"
#include "Main/Net/block_transfer_and_thread_globals.h"
#include "multiboot_piece_buffers.h"
#include "thread_mutex_types.h"
#include "00/Lib/DWC/network_check_status.h"
#include "reset_interrupts_halt.h"
#include "wifi_settings_nvram_backup.h"
#include "float_trap_dispatch.h"

Http *gNetcheckHttp;
DWCNetcheck *gNetcheck;
DWCHttpParam gHttpParam;
AuthCreateParams gAuthParam;
char *gConnTestUrl = "http://conntest.nintendowifi.net/";

u32 DWC_Netcheck_Create(DWCNetcheckParam *param) {
    if (gNetcheck != NULL) {
        return 4;
    }
    gNetcheck = param->mAlloc("DWCnetcheck", 0x1200);
    if (gNetcheck == NULL) {
        return 4;
    }
    MI_CpuFill8(gNetcheck, 0, 0x1200);
    gNetcheck->mReturnCode = -99999;
    gNetcheck->mParam = *param;
    if (gNetcheckHttp != NULL) {
        return 4;
    }
    gNetcheckHttp = gNetcheck->mParam.mAlloc("DWChttp", 0x1a60);
    if (gNetcheckHttp == NULL) {
        return 4;
    }
    OS_InitMutex(&gNetcheck->mMutex);
    DWCi_Netcheck_StartThread();
    return 0;
}

void DWC_Netcheck_Destroy(void) {
    if (gNetcheckHttp != NULL) {
        ReleaseHttp(gNetcheckHttp);
        gNetcheck->mParam.mFree("DWChttp", gNetcheckHttp, 0);
        gNetcheckHttp = NULL;
    }
    DWC_Auth_Destroy();
    if (gNetcheck != NULL) {
        if (gNetcheck->mBody302 != NULL) {
            gNetcheck->mParam.mFree("DWCnetcheck->body_302", gNetcheck->mBody302, 0);
            gNetcheck->mBody302 = NULL;
        }
        if (gNetcheck->mBodyWayport != NULL) {
            gNetcheck->mParam.mFree("DWCnetcheck->body_wayport", gNetcheck->mBodyWayport, 0);
            gNetcheck->mBodyWayport = NULL;
        }
        gNetcheck->mParam.mFree("DWCnetcheck", gNetcheck, 0);
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
        if (gNetcheckHttp != NULL) {
            DWC_Http_Abort(gNetcheckHttp);
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
    char *copyDest;
    char *bodyText;
    s32 waitLength;
    s32 decodedLength;
    s32 resultCode;
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
        gHttpParam.mReceiveBufferSize = NETCHECK_HTTP_RECEIVE_BUFFER_SIZE;
        gHttpParam.mAlloc = gNetcheck->mParam.mAlloc;
        gHttpParam.mFree = gNetcheck->mParam.mFree;
        gHttpParam.mTimeoutMillis = NETCHECK_HTTP_TIMEOUT_MILLIS;
        gNetcheck->mReturnCode = -2;
        if (DWC_Http_Create(gNetcheckHttp, &gHttpParam) != 0) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(1);
            break;
        }
        if (DWC_Http_FinishHeader(gNetcheckHttp) != 0) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(1);
            break;
        }
        DWC_Http_StartThread(gNetcheckHttp);
        if (gNetcheckHttp->mThread.mId != 0) {
            OS_JoinThread(&gNetcheckHttp->mThread);
        }
        http = gNetcheckHttp;
        switch (http->mResult) {
            case HTTP_RESULT_RESOLVE_FAILED:
                gNetcheck->mReturnCode = -1;
            default:
                ReleaseHttp(gNetcheckHttp);
                DWCi_Netcheck_SetError(3);
                goto end;
            case HTTP_RESULT_DONE:
                break;
        }
        if (DWC_Http_ParseResult(gNetcheck->mHttpLabelvalue, 0x20, 0, http->mReceiveBuffer.mStart) != TRUE) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(2);
            break;
        }
        resultCode = StrtolBase10(DWC_Http_GetResult(gNetcheck->mHttpLabelvalue, 0x20, "httpresult"));
        if (gLibErrorCode == 0x22) {
            DWCi_Netcheck_SetError(2);
            break;
        }
        if (resultCode != 200) {
            if (resultCode == 0x12e) {
                netcheck = gNetcheck;
                if (netcheck->mBodyWayport != NULL) {
                    netcheck->mReturnCode = -6;
                    ReleaseHttp(gNetcheckHttp);
                    gHttpParam.mUrl = DWCauthhttpparam.mUrl;
                    gHttpParam.mAction = FALSE;
                    gHttpParam.mReceiveBufferStart = NULL;
                    gHttpParam.mReceiveBufferSize = NETCHECK_HTTP_SMALL_RECEIVE_BUFFER_SIZE;
                    gHttpParam.mAlloc = gNetcheck->mParam.mAlloc;
                    gHttpParam.mFree = gNetcheck->mParam.mFree;
                    gHttpParam.mTimeoutMillis = NETCHECK_HTTP_TIMEOUT_MILLIS;
                    if (strcmp(gHttpParam.mUrl, "https://nas.nintendowifi.net/ac") != 0) {
                        gHttpParam.mIgnoreCa = TRUE;
                    }
                    if (DWC_Http_Create(gNetcheckHttp, &gHttpParam) != 0) {
                        ReleaseHttp(gNetcheckHttp);
                        DWCi_Netcheck_SetError(1);
                        break;
                    }
                    if (DWCi_Auth_Prepare_FirstPost(gNetcheckHttp, "", "", gNetcheck->mHttpLabelvalue, 0x20, 1) != 0) {
                        ReleaseHttp(gNetcheckHttp);
                        DWCi_Netcheck_SetError(8);
                        break;
                    }
                    if (DWC_Http_Add_PostBase64Item(gNetcheckHttp, "action", "message", 7) != FALSE) {
                        ReleaseHttp(gNetcheckHttp);
                        DWCi_Netcheck_SetError(8);
                        break;
                    }
                    interruptState = OS_DisableInterrupts();
                    MI_CpuFill8(ssidText, 0, 0x21);
                    WCM_GetApEssid(&ssidLength);
                    MI_CpuCopy8(WCM_GetApEssid(NULL), ssidText, ssidLength);
                    OS_RestoreInterrupts(interruptState);
                    if (DWC_Http_Add_PostBase64Item(gNetcheckHttp, "ssid", ssidText, strlen(ssidText)) != FALSE) {
                        ReleaseHttp(gNetcheckHttp);
                        DWCi_Netcheck_SetError(8);
                        break;
                    }
                    bodyText = gNetcheck->mBodyWayport;
                    if (DWC_Http_Add_PostBase64Item(gNetcheckHttp, "HotSpotResponse", bodyText, strlen(bodyText)) != FALSE) {
                        ReleaseHttp(gNetcheckHttp);
                        DWCi_Netcheck_SetError(8);
                        break;
                    }
                    netcheck = gNetcheck;
                    netcheck->mParam.mFree("DWCnetcheck->body_wayport", netcheck->mBodyWayport, 0);
                    gNetcheck->mBodyWayport = NULL;
                    if (DWC_Http_FinishHeader(gNetcheckHttp) != 0) {
                        ReleaseHttp(gNetcheckHttp);
                        DWCi_Netcheck_SetError(1);
                        break;
                    }
                    DWC_Http_StartThread(gNetcheckHttp);
                    if (gNetcheckHttp->mThread.mId != 0) {
                        OS_JoinThread(&gNetcheckHttp->mThread);
                    }
                    http = gNetcheckHttp;
                    switch (http->mResult) {
                        case HTTP_RESULT_RESOLVE_FAILED:
                            gNetcheck->mReturnCode = -1;
                        default:
                            ReleaseHttp(gNetcheckHttp);
                            DWCi_Netcheck_SetError(3);
                            goto end;
                        case HTTP_RESULT_DONE:
                            ReleaseHttp(http);
                            DWCi_Netcheck_SetError(7);
                            goto end;
                    }
                }
                bodyText = DWC_Http_GetResult(netcheck->mHttpLabelvalue, 0x20, "httpbody");
                if (bodyText == NULL) {
                    ReleaseHttp(gNetcheckHttp);
                    DWCi_Netcheck_SetError(2);
                    break;
                }
                gNetcheck->mBody302 = gNetcheck->mParam.mAlloc("DWCnetcheck->body_302", strlen(bodyText) + 1);
                copyDest = gNetcheck->mBody302;
                if (copyDest == NULL) {
                    ReleaseHttp(gNetcheckHttp);
                    DWCi_Netcheck_SetError(4);
                    break;
                }
                strncpy(copyDest, bodyText, strlen(bodyText));
            } else {
                ReleaseHttp(gNetcheckHttp);
                DWCi_Netcheck_SetError(10);
                break;
            }
        }
        ReleaseHttp(gNetcheckHttp);
        DWCi_BM_GetWiFiInfo(&wiFiInfo);
        if (wiFiInfo.mAttestedUserId == 0) {
            gNetcheck->mReturnCode = -3;
            gAuthParam.mIngamesn[0] = 0;
            gAuthParam.mGsbrcd[0] = 0;
            gAuthParam.mAlloc = gNetcheck->mParam.mAlloc;
            gAuthParam.mFree = gNetcheck->mParam.mFree;
            if (DWC_Auth_Create(&gAuthParam, gNetcheckHttp) != 0) {
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
        if (resultCode == 200) {
            gNetcheck->mReturnCode = 0;
            DWCi_Netcheck_SetError(11);
            break;
        }
        gNetcheck->mReturnCode = -4;
        gHttpParam.mUrl = DWCauthhttpparam.mUrl;
        gHttpParam.mAction = FALSE;
        gHttpParam.mReceiveBufferStart = NULL;
        gHttpParam.mReceiveBufferSize = NETCHECK_HTTP_RECEIVE_BUFFER_SIZE;
        gHttpParam.mAlloc = gNetcheck->mParam.mAlloc;
        gHttpParam.mFree = gNetcheck->mParam.mFree;
        gHttpParam.mTimeoutMillis = NETCHECK_HTTP_LONG_TIMEOUT_MILLIS;
        if (strcmp(gHttpParam.mUrl, "https://nas.nintendowifi.net/ac") != 0) {
            gHttpParam.mIgnoreCa = TRUE;
        }
        if (DWC_Http_Create(gNetcheckHttp, &gHttpParam) != 0) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(1);
            break;
        }
        if (DWCi_Auth_Prepare_FirstPost(gNetcheckHttp, "", "", gNetcheck->mHttpLabelvalue, 0x20, 1) != 0) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(8);
            break;
        }
        if (DWC_Http_Add_PostBase64Item(gNetcheckHttp, "action", "parse", 5) != FALSE) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(8);
            break;
        }
        interruptState = OS_DisableInterrupts();
        MI_CpuFill8(ssidText, 0, 0x21);
        WCM_GetApEssid(&ssidLength);
        MI_CpuCopy8(WCM_GetApEssid(NULL), ssidText, ssidLength);
        OS_RestoreInterrupts(interruptState);
        if (DWC_Http_Add_PostBase64Item(gNetcheckHttp, "ssid", ssidText, strlen(ssidText)) != FALSE) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(8);
            break;
        }
        bodyText = gNetcheck->mBody302;
        if (DWC_Http_Add_PostBase64Item(gNetcheckHttp, "HTML", bodyText, strlen(bodyText)) != FALSE) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(8);
            break;
        }
        netcheck = gNetcheck;
        netcheck->mParam.mFree("DWCnetcheck->body_302", netcheck->mBody302, 0);
        gNetcheck->mBody302 = NULL;
        if (DWC_Http_FinishHeader(gNetcheckHttp) != 0) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(1);
            break;
        }
        DWC_Http_StartThread(gNetcheckHttp);
        if (gNetcheckHttp->mThread.mId != 0) {
            OS_JoinThread(&gNetcheckHttp->mThread);
        }
        http = gNetcheckHttp;
        switch (http->mResult) {
            case HTTP_RESULT_RESOLVE_FAILED:
                gNetcheck->mReturnCode = -1;
            default:
                ReleaseHttp(gNetcheckHttp);
                DWCi_Netcheck_SetError(3);
                goto end;
            case HTTP_RESULT_DONE:
                break;
        }
        if (DWC_Http_ParseResult(gNetcheck->mHttpLabelvalue, 0x20, 0, http->mReceiveBuffer.mStart) != TRUE) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(2);
            break;
        }
        resultCode = StrtolBase10(DWC_Http_GetResult(gNetcheck->mHttpLabelvalue, 0x20, "httpresult"));
        if (gLibErrorCode == 0x22) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(2);
            break;
        }
        if (resultCode != 200) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(2);
            break;
        }
        if (DWC_Http_GetBase64DecodedResult(gNetcheck->mHttpLabelvalue, 0x20, "returncd", retcodeText, 4) <= 0) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(9);
            break;
        }
        resultCode = StrtolBase10(retcodeText);
        if (gLibErrorCode == 0x22) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(9);
            break;
        }
        if (resultCode >= 100) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(6);
            break;
        }
        urlLength = DWC_Http_GetBase64DecodedResult(gNetcheck->mHttpLabelvalue, 0x20, "url", NULL, 0);
        if (urlLength <= 0) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(9);
            break;
        }
        dataLength = DWC_Http_GetBase64DecodedResult(gNetcheck->mHttpLabelvalue, 0x20, "data", NULL, 0);
        if (dataLength <= 0) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(9);
            break;
        }
        waitLength = DWC_Http_GetBase64DecodedResult(gNetcheck->mHttpLabelvalue, 0x20, "wait", NULL, 0);
        urlText = gNetcheck->mParam.mAlloc("url", urlLength + 1);
        if (urlText == NULL) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(4);
            break;
        }
        dataText = gNetcheck->mParam.mAlloc("data", dataLength + 1);
        if (dataText == NULL) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(4);
            break;
        }
        if (waitLength > 0) {
            waitText = gNetcheck->mParam.mAlloc("wait", waitLength + 1);
            if (waitText == NULL) {
                ReleaseHttp(gNetcheckHttp);
                DWCi_Netcheck_SetError(4);
                break;
            }
        }
        decodedLength =
            DWC_Http_GetBase64DecodedResult(gNetcheck->mHttpLabelvalue, 0x20, "url", urlText, urlLength + 1);
        if (decodedLength < 0) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(9);
            break;
        }
        urlText[decodedLength] = 0;
        decodedLength =
            DWC_Http_GetBase64DecodedResult(gNetcheck->mHttpLabelvalue, 0x20, "data", dataText, dataLength + 1);
        if (decodedLength < 0) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(9);
            break;
        }
        dataText[decodedLength] = 0;
        waitMillis = 0;
        if (waitLength > 0) {
            decodedLength =
                DWC_Http_GetBase64DecodedResult(gNetcheck->mHttpLabelvalue, 0x20, "wait", waitText, waitLength + 1);
            if (decodedLength < 0) {
                ReleaseHttp(gNetcheckHttp);
                DWCi_Netcheck_SetError(9);
                break;
            }
            waitText[decodedLength] = 0;
            waitMillis = StrtolBase10(waitText);
            if (gLibErrorCode == 0x22) {
                ReleaseHttp(gNetcheckHttp);
                DWCi_Netcheck_SetError(9);
                break;
            }
            waitMillis *= 1000;
            if (waitMillis > 180000) {
                waitMillis = 180000;
            }
        }
        ReleaseHttp(gNetcheckHttp);
        gNetcheck->mReturnCode = -5;
        gHttpParam.mUrl = urlText;
        gHttpParam.mAction = FALSE;
        gHttpParam.mReceiveBufferStart = NULL;
        gHttpParam.mReceiveBufferSize = NETCHECK_HTTP_RECEIVE_BUFFER_SIZE;
        gHttpParam.mAlloc = gNetcheck->mParam.mAlloc;
        gHttpParam.mFree = gNetcheck->mParam.mFree;
        gHttpParam.mTimeoutMillis = NETCHECK_HTTP_LONG_TIMEOUT_MILLIS;
        if (DWC_Http_Create(gNetcheckHttp, &gHttpParam) != 0) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(1);
            break;
        }
        if (DWC_Http_Add_Body(gNetcheckHttp, dataText) != FALSE) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(8);
            break;
        }
        if (DWC_Http_FinishHeader(gNetcheckHttp) != 0) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(1);
            break;
        }
        DWC_Http_StartThread(gNetcheckHttp);
        if (gNetcheckHttp->mThread.mId != 0) {
            OS_JoinThread(&gNetcheckHttp->mThread);
        }
        http = gNetcheckHttp;
        switch (http->mResult) {
            case HTTP_RESULT_RESOLVE_FAILED:
                gNetcheck->mReturnCode = -1;
            default:
                ReleaseHttp(gNetcheckHttp);
                DWCi_Netcheck_SetError(3);
                goto end;
            case HTTP_RESULT_DONE:
                break;
        }
        if (DWC_Http_ParseResult(gNetcheck->mHttpLabelvalue, 0x20, 1, http->mReceiveBuffer.mStart) != TRUE) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(2);
            break;
        }
        bodyText = DWC_Http_GetResult(gNetcheck->mHttpLabelvalue, 0x20, "httpbody");
        if (bodyText == NULL) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(2);
            break;
        }
        gNetcheck->mBodyWayport = gNetcheck->mParam.mAlloc("DWCnetcheck->body_wayport", strlen(bodyText) + 1);
        copyDest = gNetcheck->mBodyWayport;
        if (copyDest == NULL) {
            ReleaseHttp(gNetcheckHttp);
            DWCi_Netcheck_SetError(4);
            break;
        }
        strncpy(copyDest, bodyText, strlen(bodyText));
        ReleaseHttp(gNetcheckHttp);
        OS_Sleep(waitMillis);
    }
end:
    if (urlText != NULL) {
        gNetcheck->mParam.mFree("url", urlText, 0);
    }
    if (dataText != NULL) {
        gNetcheck->mParam.mFree("data", dataText, 0);
    }
    if (waitText != NULL) {
        gNetcheck->mParam.mFree("wait", waitText, 0);
    }
}

// Not in the ROM, but its literals are still part of this file.
void UnusedAllocLiterals(void) {
    DWCNetcheck *netcheck = gNetcheck;
    void *urlText;
    void *dataText;
    void *waitText;
    netcheck->mBody302 = netcheck->mParam.mAlloc("DWCnetcheck->body_302", 1);
    urlText = netcheck->mParam.mAlloc("url", 1);
    dataText = netcheck->mParam.mAlloc("data", 1);
    waitText = netcheck->mParam.mAlloc("wait", 1);
    netcheck->mBodyWayport = netcheck->mParam.mAlloc("DWCnetcheck->body_wayport", 1);
    netcheck->mParam.mFree("url", urlText, 0);
    netcheck->mParam.mFree("data", dataText, 0);
    netcheck->mParam.mFree("wait", waitText, 0);
}

u32 DWC_Netcheck_GetError(void) {
    u32 error;
    OS_LockMutex(&gNetcheck->mMutex);
    error = gNetcheck->mError;
    OS_UnlockMutex(&gNetcheck->mMutex);
    return error;
}

void DWCi_Netcheck_SetError(u32 error) {
    OS_LockMutex(&gNetcheck->mMutex);
    gNetcheck->mError = error;
    OS_UnlockMutex(&gNetcheck->mMutex);
}

u32 DWC_Netcheck_GetReturnCode(void) {
    return gNetcheck->mReturnCode;
}
