#include "00/Lib/DWC/code_02188008.h"
#include "00/code_02186000.h"
#include "00/unk_021b1000.h"
#include "03/Net/essid_wcm.h"
#include "00/code_02186d04.h"
#include "00/Lib/DWC/code_02188694.h"
#include "00/unk_021b4000.h"
#include "os_thread.h"
#include "code_02133048.h"
#include "code_02133274.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "code_0200edc0.h"

void FreeDisused(void) {
    DWCi_AC_Free(8, gNetCheck, 0xc);
    DWCi_AC_Free(0x10, gAcWork, 0xd18);
}

s32 CheckDuplicate(void) {
    ACWORK *work;
    u8 *chosenSsid;
    u32 connectNo;
    u8 index;
    u8 findListNum;

    work = gAcWork;
    chosenSsid = work->mBssDesc[0].mBssid;
    connectNo = work->mConnectNo;
    chosenSsid += connectNo * 0xc0;
    if (work->mConnectApType >= 6) {
        return 1;
    }
    for (index = 0, findListNum = work->mFindListNum; index < findListNum; index++) {
        if (index != connectNo) {
            if (work->mFindList[index].mApType < 6) {
                if (strncmp((const char *) chosenSsid, (const char *) work->mBssDesc[index].mBssid,
                            work->mBssDesc[index].mSsidLength) == 0) {
                    return 2;
                }
            }
        }
    }
    return 1;
}

s32 DWC_Auth_Base64Encode(const u8 *src, u32 srcLength, char *dst, u32 dstLength) {
    const u8 *srcEnd;
    s32 remainingBits;
    u32 requiredSize;
    s32 outputChars;
    s32 inputBytes;
    char *dstCursor;
    u8 readBuffer[3];

    requiredSize = srcLength / 3 * 4 + (srcLength % 3 != 0 ? 4 : 0);
    if (dst == NULL) {
        return requiredSize;
    }
    if (dstLength < requiredSize) {
        return -1;
    }
    srcEnd = src + srcLength;
    dstCursor = dst;
    while (src != srcEnd) {
        inputBytes = srcEnd - src;
        remainingBits = inputBytes * 8;
        outputChars = remainingBits / 6 + (remainingBits % 6 != 0 ? 1 : 0);
        if (inputBytes >= 3) {
            inputBytes = 3;
        }
        MI_CpuFill8(readBuffer, 0, 3);
        MI_CpuCopy8(src, readBuffer, inputBytes);
        dstCursor[0] = gBase64Alphabet[readBuffer[0] >> 2];
        if (outputChars >= 2) {
            dstCursor[1] = gBase64Alphabet[(readBuffer[0] << 4 & 0x3f) | readBuffer[1] >> 4];
        } else {
            dstCursor[1] = '*';
        }
        if (outputChars >= 3) {
            dstCursor[2] = gBase64Alphabet[(readBuffer[1] << 2 & 0x3f) | readBuffer[2] >> 6];
        } else {
            dstCursor[2] = '*';
        }
        if (outputChars >= 4) {
            dstCursor[3] = gBase64Alphabet[readBuffer[2] & 0x3f];
        } else {
            dstCursor[3] = '*';
        }
        dstCursor += 4;
        src += inputBytes;
    }
    return dstCursor - dst;
}

s32 DWC_Auth_Base64Decode(const s8 *src, u32 srcLength, u8 *dst, u32 dstLength) {
    s32 decodedLength;
    s32 decodedBits;
    u32 i;
    s32 packedByte;
    u8 *dstCursor;
    s8 sextets[4];
    s8 *sextetPointer;
    s8 character;
    s32 sextetIndex;

    if ((srcLength & 3) != 0) {
        return -1;
    }
    decodedBits = 0;
    for (i = 0; i < srcLength; i++) {
        if (src[i] != '*') {
            decodedBits += 6;
        }
    }
    if (dst == NULL) {
        return decodedBits / 8;
    }
    decodedLength = decodedBits / 8;
    if (dstLength < decodedLength) {
        return -1;
    }
    if (srcLength == 0) {
        *dst = 0;
        return 0;
    }
    dstCursor = dst;
    i = 0;
    do {
        sextetIndex = i;
        sextetPointer = sextets;
        for (; sextetIndex < 4; sextetIndex++) {
            character = src[sextetIndex];
            if (character >= 'A' && character <= 'Z') {
                *sextetPointer = character - 'A';
            } else if (character >= 'a' && character <= 'z') {
                *sextetPointer = character - 0x47;
            } else if (character >= '0' && character <= '9') {
                *sextetPointer = character + 4;
            } else if (character == '.') {
                *sextetPointer = 0x3e;
            } else if (character == '-') {
                *sextetPointer = 0x3f;
            } else {
                *sextetPointer = i;
            }
            sextetPointer++;
        }
        src += 4;
        packedByte = sextets[i] * 4;
        packedByte |= sextets[1] >> 4;
        dstCursor[0] = packedByte;
        if (dstCursor + 1 - dst >= decodedLength) {
            return dstCursor + 1 - dst;
        }
        packedByte = sextets[1] * 16;
        packedByte |= sextets[2] >> 2;
        dstCursor[1] = packedByte;
        if (dstCursor + 2 - dst >= decodedLength) {
            return dstCursor + 2 - dst;
        }
        packedByte = sextets[2] * 64;
        packedByte |= sextets[3];
        dstCursor[2] = packedByte;
        dstCursor += 3;
    } while (dstCursor - dst < decodedLength);
    return dstCursor - dst;
}

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
