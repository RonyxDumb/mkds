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

CPSCaInfo *gCaInfoTable[11] = {&data_usa_ov000_021b1d28, &data_usa_ov000_021b1bfc, &data_usa_ov000_021b1edc,
                               &data_usa_ov000_021b1fb8, &data_usa_ov000_021b1494, &data_usa_ov000_021b1730,
                               &data_usa_ov000_021b1818, &data_usa_ov000_021b15e0, &data_usa_ov000_021b1ae4,
                               &data_usa_ov000_021b19c4, &data_usa_ov000_021b18dc};

s32 DWC_Http_Create(Http *http, const DWCHttpParam *param) {
    MI_CpuFill8(http, 0, 0x1a60);
    http->mContentLength = -1;
    http->mParam = *param;
    http->mLowReceiveBuffer = http->mParam.mAlloc("http->lowrecvbuf", 0xb68);
    if (http->mLowReceiveBuffer == NULL) {
        http->mResult = 1;
        return 1;
    }
    http->mLowSendBuffer = http->mParam.mAlloc("http->lowsendbuf", 0x5ea);
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
    char *s;
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
                if (strstr(s, "\r\n\r\n") != NULL) {
                    headerReceived = 1;
                    http->mBodyStart = strstr(s, "\r\n\r\n") + 4;
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
            a->mParam.mFree("http->lowrecvbuf", a->mLowReceiveBuffer, 0);
            a->mLowReceiveBuffer = NULL;
        }
        if (a->mLowSendBuffer != NULL) {
            a->mParam.mFree("http->lowsendbuf", a->mLowSendBuffer, 0);
            a->mLowSendBuffer = NULL;
        }
        MI_CpuFill8(a, 0, 0x1a60);
    }
}

BOOL DWCi_Http_WriteBasicHeader(Http *a) {
    HttpBuffer *b = &a->mSendBuffer;
    char *c;
    s32 d;
    s32 e;
    s32 f;
    if (a->mParam.mAction == 0) {
        c = "POST /%s HTTP/1.0\r\nContent-type: application/x-www-form-urlencoded\r\nHost: %s\r\n\r\n";
    } else {
        c = "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n";
    }
    d = strlen(a->mHost);
    e = strlen(c);
    f = d + (e - 4 + strlen(a->mPath));
    if (InitHttpBuffer(a, &a->mSendBuffer, f + 0x400) != 1) {
        return TRUE;
    }
    b->mCursor = b->mCursor + OS_SNPrintf(b->mCursor, b->mSize, c, a->mPath, a->mHost);
    return FALSE;
}

BOOL DWC_Http_Add_HeaderItem(Http *a, const char *b, const char *c) {
    s32 e;
    HttpBuffer *d;
    s32 f;
    const char *format;
    char *g;
    s8 h;
    s8 *p;
    s32 i;
    d = &a->mSendBuffer;
    e = strlen(c);
    format = "%s: %s\r\n";
    f = strlen(format);
    e += (f - 4 + strlen(b));
    i = d->mEnd - d->mCursor;
    if (e + 1 > i) {
        if (GrowHttpBuffer(a, d, e - i + 1) == 0) {
            return TRUE;
        }
    }
    p = (s8 *) strstr(d->mStart, "\r\n\r\n");
    g = (char *) p + 2;
    h = p[2];
    memmove(g + e, g, strlen(g) + 1);
    i = OS_SNPrintf(g, e + 1, format, b, c);
    g[i] = h;
    d->mCursor = d->mCursor + e;
    return FALSE;
}

BOOL DWC_Http_Add_PostBase64Item(Http *a, const char *b, const void *c, s32 d) {
    HttpBuffer *e = &a->mSendBuffer;
    char *f;
    s32 g;
    s32 h;
    s32 i;
    s32 j;
    if (a->mPairCount == 0) {
        f = "%s=";
    } else {
        f = "&%s=";
    }
    a->mPairCount = a->mPairCount + 1;
    g = DWC_Auth_Base64Encode(c, d, NULL, 0);
    h = strlen(f);
    i = g + (h - 2 + strlen(b));
    j = e->mEnd - e->mCursor;
    if (i > j) {
        if (GrowHttpBuffer(a, e, i - j + 1) == 0) {
            return TRUE;
        }
        j = e->mEnd - e->mCursor;
    }
    e->mCursor = e->mCursor + OS_SNPrintf(e->mCursor, j, f, b);
    if (DWC_Auth_Base64Encode(c, d, e->mCursor, e->mEnd - e->mCursor - 1) < 0) {
        return TRUE;
    }
    e->mCursor = e->mCursor + g;
    *e->mCursor = 0;
    return FALSE;
}

BOOL DWC_Http_Add_Body(Http *a, const char *b) {
    s32 d;
    HttpBuffer *c;
    s32 e;
    s32 f;
    c = &a->mSendBuffer;
    d = strlen(b);
    e = c->mEnd - c->mCursor;
    if (d > e) {
        if (GrowHttpBuffer(a, c, d - e + 1) == 0) {
            return TRUE;
        }
        e = c->mEnd - c->mCursor;
    }
    f = OS_SNPrintf(c->mCursor, e, "%s", b);
    if (f != d) {
        return TRUE;
    }
    c->mCursor = c->mCursor + f;
    return FALSE;
}

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
    s8 *h;
    char *j;
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
    h = delimiter + 2;
    while (h[0] != 0xd && h[1] != 0xa) {
        delimiter = (s8 *) strstr((const char *) h, ": ");
        if (delimiter == NULL) {
            break;
        }
        delimiter[0] = delimiter[1] = 0;
        j = (char *) (delimiter + 2);
        delimiter = (s8 *) strstr(j, "\r\n");
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
            delimiter = (s8 *) strstr(j, "=");
            if (delimiter == NULL) {
                break;
            }
            delimiter[0] = 0;
            h = delimiter + 1;
            delimiter = (s8 *) strstr((const char *) h, "&");
            if (delimiter == NULL) {
                delimiter = (s8 *) strstr((const char *) h, "\r\n");
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
