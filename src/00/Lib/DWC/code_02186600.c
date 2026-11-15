#include "00/Lib/DWC/code_02186600.h"
#include "00/code_02186d04.h"
#include "00/unk_021b1000.h"
#include "03/Net/essid_packet_steps.h"
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
#include "Main/Net/data_0216f000.h"
#include "mb_data.h"
#include "code_0200edc0.h"
#include "code_0200e77c.h"
#include "00/code_02187484.h"
#include "00/unk_021b4000.h"
#include "code_0200fc8c.h"
#include "dwc_backup.h"
#include "code_02134008.h"
#include "00/Lib/DWC/code_02188008.h"
#include "string.h"
#include "code_02134398.h"
#include "code_021519d4.h"
#include "00/Lib/NitroWiFi/util.h"
#include "00/Lib/DWC/code_0218a67c.h"
#include "00/Lib/NitroWiFi/cpsif.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "00/Menu/wi_fi_connection_lost.h"
#include "Main/System/heap.h"
#include "00/code_02187000.h"
#include "00/code_021a6000.h"
#include "code_0214d93c.h"
#include "Main/Save/nvram_new_wifi_info.h"

u32 DWChttpignoreca;

CPSCaInfo *gCaInfoTable[11] = {
    &gVeriSignClass3G3CaInfo, &gVeriSignClass3G2CaInfo,    &gVeriSignClass3CaInfo, &gRsaSecureServerCaInfo,
    &gGlobalSignRootCaInfo,   &gGteGlobalRootCaInfo,       &gGteRootCaInfo,        &gBaltimoreRootCaInfo,
    &gThawteServerCaInfo,     &gThawtePremiumServerCaInfo, &gNintendoCaInfo};

s32 DWC_Http_Create(Http *http, const DWCHttpParam *param) {
    MI_CpuFill8(http, 0, 0x1a60);
    http->mContentLength = -1;
    http->mParam = *param;
    http->mLowReceiveBuffer = http->mParam.mAlloc("http->lowrecvbuf", 0xb68);
    if (http->mLowReceiveBuffer == NULL) {
        http->mResult = HTTP_RESULT_NO_MEMORY;
        return 1;
    }
    http->mLowSendBuffer = http->mParam.mAlloc("http->lowsendbuf", 0x5ea);
    if (http->mLowSendBuffer == NULL) {
        http->mResult = HTTP_RESULT_NO_MEMORY;
        return 1;
    }
    DWCi_Http_SetHostinfo(http, param->mUrl);
    http->mResult = DWCi_Http_WriteBasicHeader(http);
    if (http->mResult == HTTP_RESULT_OK) {
        http->mInitFlag = 0xff;
    }
    return http->mResult;
}

u32 DWC_Http_FinishHeader(Http *http) {
    char contentLengthText[8];
    u32 contentLength;
    if (DWC_Http_Add_HeaderItem(http, "Connection", "close") != FALSE) {
        return 1;
    }
    contentLength = strlen(strstr(http->mSendBuffer.mStart, "\r\n\r\n") + 4);
    if (contentLength != 0) {
        OS_SNPrintf(contentLengthText, 7, "%d", contentLength);
        if (DWC_Http_Add_HeaderItem(http, "Content-Length", contentLengthText) != FALSE) {
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
    char *bufferText;
    CPSSoc *socketBuffers;
    HttpsState *sslInfo;
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
    s32 byteCount;
    LowEntropyData entropyData;
    const char *contentLengthText;

    headerReceived = 0;
    socketBuffers = &http->mSoc;
    sslInfo = &http->mHttpsState;
    receiveBuffer = &http->mReceiveBuffer;
    timeoutMillis = http->mParam.mTimeoutMillis;
    if (timeoutMillis <= 0) {
        timeoutMillis = 60000;
    }
    MI_CpuFill8(socketBuffers, 0, sizeof(CPSSoc));
    socketBuffers->mReceiveBufferSize = 0xb68;
    socketBuffers->mReceiveBuffer = http->mLowReceiveBuffer;
    socketBuffers->mSendBufferSize = 0x5ea;
    socketBuffers->mSendBuffer = http->mLowSendBuffer;
    CPS_SocRegister(socketBuffers);
    hostAddress = CPS_Resolve(http->mHost);
    if (hostAddress == 0) {
        http->mResult = HTTP_RESULT_RESOLVE_FAILED;
        return;
    }
    CPS_SocUse();
    if (http->mUseHttps == 1) {
        MI_CpuFill8(sslInfo, 0, sizeof(HttpsState));
        sslInfo->mCheckFlagsCallback = DWCi_Http_CPSCallback;
        sslInfo->mHost = (s8 *) http->mHost;
        socketBuffers->mHttpsState = sslInfo;
        SetAuthorityTable(gCaInfoTable, 0xb);
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
        http->mResult = HTTP_RESULT_CONNECT_FAILED;
        CPS_SocRelease();
        CPS_SocUnRegister();
        return;
    }
    http->mSendBuffer.mCursor = http->mSendBuffer.mStart;
    bufferText = http->mSendBuffer.mStart;
    http->mSendBuffer.mEnd = bufferText + strlen(bufferText);
    while (http->mSendBuffer.mCursor < http->mSendBuffer.mEnd) {
        if (CPSMyIp == 0) {
            http->mResult = HTTP_RESULT_SEND_FAILED;
            goto fail;
        }
        byteCount = http->mSendBuffer.mEnd - http->mSendBuffer.mCursor;
        if (byteCount > 0x238) {
            byteCount = 0x238;
        }
        byteCount = CPS_SocWrite((const u8 *) http->mSendBuffer.mCursor, byteCount);
        if (byteCount <= 0) {
            http->mResult = HTTP_RESULT_SEND_FAILED;
            goto fail;
        }
        CPS_SocFlush();
        nowTick = OS_GetTick();
        if ((u64) timeoutMillis < (nowTick - startTick) * 64 / 0x82ea) {
            http->mResult = HTTP_RESULT_SEND_TIMEOUT;
            goto fail;
        }
        if (http->mUseHttps == 1) {
            if (1000 < (nowTick - entropyTick) * 64 / 0x82ea) {
                OS_GetLowEntropyData(&entropyData);
                MixBytesIntoRandomState(&entropyData, 0x20);
                entropyTick = nowTick;
            }
        }
        http->mSendBuffer.mCursor += byteCount;
        if (SleepUnlessHttpAborted(http) == 0) {
            http->mResult = HTTP_RESULT_ABORTED;
            goto fail;
        }
    }
    FreeHttpBuffer(http, &http->mSendBuffer);
    OS_LockMutex(&http->mReceiveMutex);
    if (http->mParam.mReceiveBufferStart == NULL) {
        if (InitHttpBuffer(http, &http->mReceiveBuffer, http->mParam.mReceiveBufferSize) == 0) {
            http->mResult = HTTP_RESULT_NO_MEMORY;
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
            http->mResult = HTTP_RESULT_SEND_FAILED;
            goto fail;
        }
        OS_LockMutex(&http->mReceiveMutex);
        if (receiveBuffer->mCursor >= receiveBuffer->mEnd - 1) {
            OS_UnlockMutex(&http->mReceiveMutex);
            break;
        }
        byteCount = CPS_SocGetLength();
        if (byteCount > 0) {
            receivedData = CPS_SocRead((u32 *) &byteCount);
            if (receivedData == NULL) {
                OS_UnlockMutex(&http->mReceiveMutex);
                break;
            }
            bufferSpace = receiveBuffer->mEnd - 1 - receiveBuffer->mCursor;
            copyLength = byteCount;
            if ((s32) copyLength >= bufferSpace) {
                copyLength = bufferSpace;
            }
            MI_CpuCopy8(receivedData, receiveBuffer->mCursor, copyLength);
            receiveBuffer->mCursor += copyLength;
            *receiveBuffer->mCursor = 0;
            if (headerReceived != 1) {
                bufferText = receiveBuffer->mStart;
                if (strstr(bufferText, "\r\n\r\n") != NULL) {
                    headerReceived = 1;
                    http->mBodyStart = strstr(bufferText, "\r\n\r\n") + 4;
                    contentLengthText = strstr(receiveBuffer->mStart, "Content-Length: ");
                    if (contentLengthText != NULL) {
                        contentLengthText = contentLengthText + strlen("Content-Length: ");
                        lengthEnd = (s8 *) strstr(contentLengthText, "\r\n");
                        savedByte = *lengthEnd;
                        *lengthEnd = 0;
                        http->mContentLength = StrtolBase10(contentLengthText);
                        *lengthEnd = savedByte;
                    }
                }
            }
            if (byteCount > copyLength) {
                CPS_SocConsume(byteCount);
                OS_UnlockMutex(&http->mReceiveMutex);
                break;
            }
            CPS_SocConsume(copyLength);
        }
        if (byteCount < 0) {
            OS_UnlockMutex(&http->mReceiveMutex);
            break;
        }
        if (http->mContentLength > 0 && byteCount > 0 &&
            http->mBodyStart + http->mContentLength <= receiveBuffer->mCursor) {
            OS_UnlockMutex(&http->mReceiveMutex);
            break;
        }
        nowTick = OS_GetTick();
        if ((u64) timeoutMillis < (nowTick - startTick) * 64 / 0x82ea) {
            http->mResult = HTTP_RESULT_RECEIVE_TIMEOUT;
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
            http->mResult = HTTP_RESULT_ABORTED;
            goto fail;
        }
    }
    CPS_TcpShutdown();
    CPS_TcpClose();
    CPS_SocRelease();
    CPS_SocUnRegister();
    http->mResult = HTTP_RESULT_DONE;
    return;
fail:
    CPS_TcpShutdown();
    CPS_TcpClose();
    CPS_SocRelease();
    CPS_SocUnRegister();
}

void ReleaseHttp(Http *httpContext) {
    if (httpContext != NULL) {
        if (httpContext->mParam.mReceiveBufferStart == NULL) {
            FreeHttpBuffer(httpContext, &httpContext->mReceiveBuffer);
        }
        FreeHttpBuffer(httpContext, &httpContext->mSendBuffer);
        if (httpContext->mLowReceiveBuffer != NULL) {
            httpContext->mParam.mFree("http->lowrecvbuf", httpContext->mLowReceiveBuffer, 0);
            httpContext->mLowReceiveBuffer = NULL;
        }
        if (httpContext->mLowSendBuffer != NULL) {
            httpContext->mParam.mFree("http->lowsendbuf", httpContext->mLowSendBuffer, 0);
            httpContext->mLowSendBuffer = NULL;
        }
        MI_CpuFill8(httpContext, 0, 0x1a60);
    }
}

BOOL DWCi_Http_WriteBasicHeader(Http *http) {
    HttpBuffer *sendBuffer = &http->mSendBuffer;
    char *format;
    s32 hostLength;
    s32 formatLength;
    s32 totalLength;
    if (http->mParam.mAction == 0) {
        format = "POST /%s HTTP/1.0\r\nContent-type: application/x-www-form-urlencoded\r\nHost: %s\r\n\r\n";
    } else {
        format = "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n";
    }
    hostLength = strlen(http->mHost);
    formatLength = strlen(format);
    totalLength = hostLength + (formatLength - 4 + strlen(http->mPath));
    if (InitHttpBuffer(http, &http->mSendBuffer, totalLength + 0x400) != 1) {
        return TRUE;
    }
    sendBuffer->mCursor =
        sendBuffer->mCursor + OS_SNPrintf(sendBuffer->mCursor, sendBuffer->mSize, format, http->mPath, http->mHost);
    return FALSE;
}

BOOL DWC_Http_Add_HeaderItem(Http *http, const char *name, const char *value) {
    s32 itemLength;
    HttpBuffer *sendBuffer;
    s32 formatLength;
    const char *format;
    char *insertPos;
    s8 savedByte;
    s8 *headerEnd;
    s32 spaceLeft;
    sendBuffer = &http->mSendBuffer;
    itemLength = strlen(value);
    format = "%s: %s\r\n";
    formatLength = strlen(format);
    itemLength += (formatLength - 4 + strlen(name));
    spaceLeft = sendBuffer->mEnd - sendBuffer->mCursor;
    if (itemLength + 1 > spaceLeft) {
        if (GrowHttpBuffer(http, sendBuffer, itemLength - spaceLeft + 1) == 0) {
            return TRUE;
        }
    }
    headerEnd = (s8 *) strstr(sendBuffer->mStart, "\r\n\r\n");
    insertPos = (char *) headerEnd + 2;
    savedByte = headerEnd[2];
    memmove(insertPos + itemLength, insertPos, strlen(insertPos) + 1);
    spaceLeft = OS_SNPrintf(insertPos, itemLength + 1, format, name, value);
    insertPos[spaceLeft] = savedByte;
    sendBuffer->mCursor = sendBuffer->mCursor + itemLength;
    return FALSE;
}

BOOL DWC_Http_Add_PostBase64Item(Http *http, const char *name, const void *data, s32 dataSize) {
    HttpBuffer *sendBuffer = &http->mSendBuffer;
    char *format;
    s32 encodedLength;
    s32 formatLength;
    s32 neededLength;
    s32 spaceLeft;
    if (http->mPairCount == 0) {
        format = "%s=";
    } else {
        format = "&%s=";
    }
    http->mPairCount = http->mPairCount + 1;
    encodedLength = DWC_Auth_Base64Encode(data, dataSize, NULL, 0);
    formatLength = strlen(format);
    neededLength = encodedLength + (formatLength - 2 + strlen(name));
    spaceLeft = sendBuffer->mEnd - sendBuffer->mCursor;
    if (neededLength > spaceLeft) {
        if (GrowHttpBuffer(http, sendBuffer, neededLength - spaceLeft + 1) == 0) {
            return TRUE;
        }
        spaceLeft = sendBuffer->mEnd - sendBuffer->mCursor;
    }
    sendBuffer->mCursor = sendBuffer->mCursor + OS_SNPrintf(sendBuffer->mCursor, spaceLeft, format, name);
    if (DWC_Auth_Base64Encode(data, dataSize, sendBuffer->mCursor, sendBuffer->mEnd - sendBuffer->mCursor - 1) < 0) {
        return TRUE;
    }
    sendBuffer->mCursor = sendBuffer->mCursor + encodedLength;
    *sendBuffer->mCursor = 0;
    return FALSE;
}

BOOL DWC_Http_Add_Body(Http *http, const char *body) {
    s32 bodyLength;
    HttpBuffer *sendBuffer;
    s32 spaceLeft;
    s32 printed;
    sendBuffer = &http->mSendBuffer;
    bodyLength = strlen(body);
    spaceLeft = sendBuffer->mEnd - sendBuffer->mCursor;
    if (bodyLength > spaceLeft) {
        if (GrowHttpBuffer(http, sendBuffer, bodyLength - spaceLeft + 1) == 0) {
            return TRUE;
        }
        spaceLeft = sendBuffer->mEnd - sendBuffer->mCursor;
    }
    printed = OS_SNPrintf(sendBuffer->mCursor, spaceLeft, "%s", body);
    if (printed != bodyLength) {
        return TRUE;
    }
    sendBuffer->mCursor = sendBuffer->mCursor + printed;
    return FALSE;
}

u32 DWCi_Http_CPSCallback(u32 flags, HttpsState *httpsState, s32 itemIndex) {
    if (flags & 0x8000) {
        flags &= 0xffff7fff;
    }
    return flags;
}

u32 InitHttpBuffer(Http *http, HttpBuffer *httpBuffer, int size) {
    if (size == 0) {
        return 0;
    }
    httpBuffer->mStart = http->mParam.mAlloc("DWCHttpBuffer", size);
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
        http->mParam.mFree("DWCHttpBuffer", httpBuffer->mStart, 0);
    }
    MI_CpuFill8(httpBuffer, 0, 0x10);
}

u32 GrowHttpBuffer(Http *http, HttpBuffer *httpBuffer, int addedSize) {
    char *newBlock;
    if (addedSize <= 0) {
        return 0;
    }
    newBlock = http->mParam.mAlloc(NULL, httpBuffer->mSize + addedSize);
    if (newBlock == NULL) {
        return 0;
    }
    MI_CpuCopy8(httpBuffer->mStart, newBlock, httpBuffer->mSize);
    http->mParam.mFree(NULL, httpBuffer->mStart, 0);
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
    strncpy(http->mUrl, url, 0x80);
    if (strlen(url) != strlen(http->mUrl)) {
        return FALSE;
    }
    found = strstr(http->mUrl, "http://");
    if (found != NULL) {
        http->mHost = http->mUrl + 7;
        http->mUseHttps = FALSE;
    } else {
        found = strstr(http->mUrl, "https://");
        if (found == NULL) {
            return FALSE;
        }
        http->mHost = found + 8;
        http->mUseHttps = TRUE;
    }
    found = strstr(http->mHost, "/");
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
    s8 *fieldPtr;
    char *textPtr;
    s8 *delimiter;
    results.mEntries = labelValues;
    results.mCapacity = labelValueCount;
    results.mCount = 0;
    MI_CpuFill8(labelValues, 0, labelValueCount * 8);
    headerEnd = strstr(reply, "\r\n\r\n");
    if (headerEnd == NULL) {
        return FALSE;
    }
    bodyEnd = headerEnd + 4 + strlen(headerEnd + 4);
    delimiter = (s8 *) strstr(reply, " ");
    if (delimiter == NULL) {
        return FALSE;
    }
    statusText = delimiter + 1;
    statusText[3] = 0;
    if (DWCi_Http_AddResult(&results, "httpresult", statusText) != TRUE) {
        return FALSE;
    }
    if (noParseBody == 1 || strncmp((const char *) statusText, "200", 3) != 0) {
        if (DWCi_Http_AddResult(&results, "httpbody", headerEnd + 4) != TRUE) {
            return FALSE;
        }
        return TRUE;
    }
    delimiter = (s8 *) strstr((const char *) (statusText + 4), "\r\n");
    if (delimiter == NULL) {
        return FALSE;
    }
    fieldPtr = delimiter + 2;
    while (fieldPtr[0] != 0xd && fieldPtr[1] != 0xa) {
        delimiter = (s8 *) strstr((const char *) fieldPtr, ": ");
        if (delimiter == NULL) {
            break;
        }
        delimiter[0] = delimiter[1] = 0;
        textPtr = (char *) (delimiter + 2);
        delimiter = (s8 *) strstr(textPtr, "\r\n");
        if (delimiter == NULL) {
            break;
        }
        delimiter[0] = delimiter[1] = 0;
        if (DWCi_Http_AddResult(&results, fieldPtr, textPtr) != TRUE) {
            return FALSE;
        }
        fieldPtr = (s8 *) (textPtr + strlen(textPtr) + 2);
    }
    textPtr = headerEnd + 4;
    if (textPtr < bodyEnd) {
        do {
            delimiter = (s8 *) strstr(textPtr, "=");
            if (delimiter == NULL) {
                break;
            }
            delimiter[0] = 0;
            fieldPtr = delimiter + 1;
            delimiter = (s8 *) strstr((const char *) fieldPtr, "&");
            if (delimiter == NULL) {
                delimiter = (s8 *) strstr((const char *) fieldPtr, "\r\n");
            }
            if (delimiter != NULL) {
                delimiter[0] = 0;
            }
            if (DWCi_Http_AddResult(&results, textPtr, fieldPtr) != TRUE) {
                return FALSE;
            }
            textPtr = (char *) fieldPtr + strlen((const char *) fieldPtr) + 1;
        } while (textPtr < bodyEnd);
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
