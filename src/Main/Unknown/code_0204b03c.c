#include "Main/Unknown/code_0204b03c.h"
#include "Main/Unknown/code_0202f14c.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/unk_02154000.h"
#include "code_0200cd1c.h"
#include "code_0200f5ac.h"
#include "code_0214578c.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_0204984c.h"

#pragma thumb on

void savc_unlockCardBackup(void) {
    s32 lockId;
    lockId = gSaveCore->mLockId;
    if (lockId != -3) {
        CARD_UnlockBackup(lockId);
        OS_ReleaseLockID(gSaveCore->mLockId);
        gSaveCore->mLockId = -3;
    }
}

BOOL savc_lockCardBackup(void) {
    s32 lockId;
    gSaveCore->mLockId = OS_GetLockID();
    lockId = gSaveCore->mLockId;
    if (lockId == -3) {
        return 0;
    }
    CARD_LockBackup(lockId);
    return 1;
}

void savc_handleError(s32 errorCode) {
    BOOL f;
    f = TRUE;
    switch (gSaveCore->mUnk_00) {
        case 1:
        case 2:
            f = FALSE;
    }
    gSaveCore->mUnk_00 = 4;
    gSaveCore->mErrorCode = errorCode;
    switch (gSaveCore->mErrorCode) {
        case 0:
            break;
        case 1:
        case 2:
            if (f != FALSE) {
                scene_reportError(1);
            } else {
                scene_reportError(2);
            }
            break;
        case 3:
        case 4:
            break;
    }
}

u16 savc_calculateChecksum(u8 *cursor, u32 byteCount) {
    u16 crc;
    u16 byteIndex;
    u16 unused;
    u8 byte;
    s32 bitIndex;
    byteIndex = 0;
    crc = 0;
    if (byteIndex < byteCount) {
        do {
            byte = *cursor;
            for (bitIndex = 0; bitIndex < 8; bitIndex++) {
                if (crc & 0x8000) {
                    crc <<= 1;
                    crc ^= savc_sCrcPolynomial;
                } else {
                    crc <<= 1;
                }
                if (byte & 0x80) {
                    crc ^= 1;
                }
                byte = byte << 1;
            }
            cursor++;
            byteIndex++;
        } while (byteIndex < byteCount);
    }
    return crc;
}

void savc_generateBlockFooter(u8 *bytes, u32 byteCount, u32 skipTickBytes) {
    u8 *tail;
    u16 crc;
    tail = bytes + byteCount - 4;
    if (skipTickBytes == 0) {
        tail[0] = 0;
        tail[1] = 0;
    }
    tail[2] = 0;
    tail[3] = 0;
    crc = savc_calculateChecksum(bytes, byteCount);
    if (skipTickBytes == 0) {
        tail[0] = (OS_GetTick() >> 16) & 0xff;
        tail[1] = (OS_GetTick() >> 32) & 0xff;
    }
    tail[2] = crc >> 8;
    tail[3] = crc;
}

BOOL savc_handleBlockFooter(u8 *bytes, u32 byteCount, u32 skipTickBytes) {
    u8 *tail;
    tail = bytes + byteCount - 4;
    if (skipTickBytes == 0) {
        tail[0] = 0;
        tail[1] = 0;
    }
    if (savc_calculateChecksum(bytes, byteCount) == 0) {
        return 1;
    }
    return 0;
}

s32 savc_findEncryptionSeed(u32 value, u32 expected) {
    u16 index;
    s32 foundIndex;
    index = 0;
    foundIndex = -1;
    for (; index < 0x1d; index++) {
        if (expected == (value ^ (savc_sEncTable0[index] +
                                  (savc_sEncTable1[0] + (savc_sEncTable2[0] + savc_sEncTable3[0]))))) {
            foundIndex = index;
            break;
        }
    }
    return foundIndex;
}

void savc_encryptBlock(u32 *cursor, u32 byteCount) {
    u16 i;
    u16 j;
    u16 k;
    u16 l;
    u32 *end;
    u32 tableSum;
    j = 0;
    l = 0;
    k = 0;
    i = (OS_GetTick() >> 16) % 0x1d;
    tableSum = savc_sEncTable0[i] + (savc_sEncTable1[0] + (savc_sEncTable2[0] + savc_sEncTable3[0]));
    i = savc_findEncryptionSeed(tableSum ^ *cursor, *cursor);
    end = OFFSET_PTR(u32, cursor, byteCount);
    do {
        *cursor ^= savc_sEncTable0[i] + (savc_sEncTable1[j] + (savc_sEncTable2[k] + savc_sEncTable3[l]));
        cursor++;
        k++;
        if (k >= 0xb) {
            k = 0;
            l++;
            if (l >= 0x11) {
                l = 0;
                j++;
                if (j >= 0x13) {
                    j = 0;
                    i++;
                    if (i >= 0x1d) {
                        i = 0;
                    }
                }
            }
        }
    } while (cursor < end);
}

BOOL savc_decryptBlock(u32 *cursor, u32 byteCount, u32 expectedFirstWord) {
    u16 i;
    u16 j;
    u16 k;
    u16 l;
    s32 foundIndex;
    u32 *end;
    j = 0;
    l = 0;
    k = 0;
    foundIndex = savc_findEncryptionSeed(*cursor, expectedFirstWord);
    if (foundIndex == -1) {
        return 0;
    }
    i = foundIndex;
    end = OFFSET_PTR(u32, cursor, byteCount);
    do {
        *cursor ^= savc_sEncTable0[i] + (savc_sEncTable1[j] + (savc_sEncTable2[k] + savc_sEncTable3[l]));
        cursor++;
        k++;
        if (k >= 0xb) {
            k = 0;
            l++;
            if (l >= 0x11) {
                l = 0;
                j++;
                if (j >= 0x13) {
                    j = 0;
                    i++;
                    if (i >= 0x1d) {
                        i = 0;
                    }
                }
            }
        }
    } while (cursor < end);
    return 1;
}

#pragma thumb off

void wlmenu_init(void) {
    if (gSystemData->mUnk_20 == 3) {
        overlay_unload();
        overlay_beginLoad(0);
        overlay_finishLoad();
    }
    InitWLMenuScene(proc_getHeap(proc_getCurrent()));
}
