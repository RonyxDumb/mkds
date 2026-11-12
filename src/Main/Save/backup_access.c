#include "Main/Save/backup_access.h"
#include "Main/Menu/wl_menu_scene.h"
#include "Main/System/heap_call.h"
#include "Main/Net/slot_result_sync.h"
#include "Main/MapObjects/data_02154000.h"
#include "os_spinLock.h"
#include "os_tick.h"
#include "card_common.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "Main/Scene/scene_connection.h"
#include "Main/Save/backup_write_copies.h"

const u32 gBackupXorKeys11[11] = {0xc0a2cfb9, 0xfca4f59a, 0xd87e2588, 0xb615dd30, 0xeacc91ee, 0xb6a8f95d, 0x7bd8b080, 0xcec11555, 0x59cef8ce, 0xfff88db3, 0xa867f2a3};
const u32 gBackupXorKeys17[17] = {0x54e85ea2, 0xde7ce656, 0xd25261b4, 0x401d1ec4, 0x220dece2, 0x1f0cf6f4, 0x7176b2a6, 0x58d602ec, 0x859d5b49, 0xe5258b0c, 0xb31a2910, 0x2dde04b1, 0xeeefa031, 0x5b852490, 0x44ad6965, 0x8e3206a5, 0x5e22b868};
const u32 gBackupXorKeys19[19] = {0x83f3e485, 0x1f854511, 0x33fae87b, 0xa6949a1e, 0xdb1da3c5, 0xd5986a2f, 0xaf6cc662, 0xfb04bd0f, 0x573f3084, 0xdfb9a74f, 0xf60a05b6, 0xdf57e7c7, 0x11723659, 0x8eae9859, 0xe08eb664, 0xd310802a, 0x498b2fa5, 0x555452f1, 0xe5575c26};
const u32 gBackupXorKeys29[29] = {0xb6f2ba0c, 0x1a88bef7, 0xddc276b, 0xb000f810, 0x6d254a35, 0x4c69572c, 0xe49cfc2, 0xa4391d94, 0x98e199e1, 0x10f88349, 0xa7cce380, 0xf4287c11, 0x93857987, 0xf1f1171f, 0x3487b1fa, 0x65b88727, 0xa1711a9c, 0x2338b1fe, 0xf742b4df, 0xa33235ec, 0x5350d303, 0xc9c1be55, 0xc4fd2e1d, 0x8039e1db, 0xb6386f71, 0x34cbb389, 0x1224001a, 0x59cdea11, 0x5371f238};

#pragma thumb on

void UnlockBackup(void) {
    s32 lockId;
    lockId = gBackupAccess->mLockId;
    if (lockId != -3) {
        CARD_UnlockBackup(lockId);
        OS_ReleaseLockID(gBackupAccess->mLockId);
        gBackupAccess->mLockId = -3;
    }
}

BOOL TryLockBackup(void) {
    s32 lockId;
    gBackupAccess->mLockId = OS_GetLockID();
    lockId = gBackupAccess->mLockId;
    if (lockId == -3) {
        return 0;
    }
    CARD_LockBackup(lockId);
    return 1;
}

void EndBackupAccessWithError(s32 errorCode) {
    BOOL notWriteStatus;
    notWriteStatus = TRUE;
    switch (gBackupAccess->mStatus) {
        case 1:
        case 2:
            notWriteStatus = FALSE;
    }
    gBackupAccess->mStatus = 4;
    gBackupAccess->mErrorCode = errorCode;
    switch (gBackupAccess->mErrorCode) {
        case 0:
            break;
        case 1:
        case 2:
            if (notWriteStatus != FALSE) {
                RunMessageScreenOfKindWrapper(1);
            } else {
                RunMessageScreenOfKindWrapper(2);
            }
            break;
        case 3:
        case 4:
            break;
    }
}

u16 ComputeBytesCrc(u8 *cursor, u32 byteCount) {
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
                    crc ^= gCrcXorValue;
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

void WriteBlockTail(u8 *bytes, u32 byteCount, u32 skipTickBytes) {
    u8 *tail;
    u16 crc;
    tail = bytes + byteCount - 4;
    if (skipTickBytes == 0) {
        tail[0] = 0;
        tail[1] = 0;
    }
    tail[2] = 0;
    tail[3] = 0;
    crc = ComputeBytesCrc(bytes, byteCount);
    if (skipTickBytes == 0) {
        tail[0] = (OS_GetTick() >> 16) & 0xff;
        tail[1] = (OS_GetTick() >> 32) & 0xff;
    }
    tail[2] = crc >> 8;
    tail[3] = crc;
}

BOOL ClearTickBytesAndCheckBlockCrc(u8 *bytes, u32 byteCount, u32 skipTickBytes) {
    u8 *tail;
    tail = bytes + byteCount - 4;
    if (skipTickBytes == 0) {
        tail[0] = 0;
        tail[1] = 0;
    }
    if (ComputeBytesCrc(bytes, byteCount) == 0) {
        return 1;
    }
    return 0;
}

s32 FindBackupXorIndex(u32 value, u32 expected) {
    u16 index;
    s32 foundIndex;
    index = 0;
    foundIndex = -1;
    for (; index < 0x1d; index++) {
        if (expected == (value ^ (gBackupXorKeys29[index] +
                                  (gBackupXorKeys19[0] + (gBackupXorKeys11[0] + gBackupXorKeys17[0]))))) {
            foundIndex = index;
            break;
        }
    }
    return foundIndex;
}

void XorBackupWordsAtTickIndex(u32 *cursor, u32 byteCount) {
    u16 firstIndex;
    u16 secondIndex;
    u16 thirdIndex;
    u16 fourthIndex;
    u32 *end;
    u32 tableSum;
    secondIndex = 0;
    fourthIndex = 0;
    thirdIndex = 0;
    firstIndex = (OS_GetTick() >> 16) % 0x1d;
    tableSum = gBackupXorKeys29[firstIndex] + (gBackupXorKeys19[0] + (gBackupXorKeys11[0] + gBackupXorKeys17[0]));
    firstIndex = FindBackupXorIndex(tableSum ^ *cursor, *cursor);
    end = OFFSET_PTR(u32, cursor, byteCount);
    do {
        *cursor ^= gBackupXorKeys29[firstIndex] +
                   (gBackupXorKeys19[secondIndex] + (gBackupXorKeys11[thirdIndex] + gBackupXorKeys17[fourthIndex]));
        cursor++;
        thirdIndex++;
        if (thirdIndex >= 0xb) {
            thirdIndex = 0;
            fourthIndex++;
            if (fourthIndex >= 0x11) {
                fourthIndex = 0;
                secondIndex++;
                if (secondIndex >= 0x13) {
                    secondIndex = 0;
                    firstIndex++;
                    if (firstIndex >= 0x1d) {
                        firstIndex = 0;
                    }
                }
            }
        }
    } while (cursor < end);
}

BOOL TryXorBackupWordsAtFoundIndex(u32 *cursor, u32 byteCount, u32 expectedFirstWord) {
    u16 firstIndex;
    u16 secondIndex;
    u16 thirdIndex;
    u16 fourthIndex;
    s32 foundIndex;
    u32 *end;
    secondIndex = 0;
    fourthIndex = 0;
    thirdIndex = 0;
    foundIndex = FindBackupXorIndex(*cursor, expectedFirstWord);
    if (foundIndex == -1) {
        return 0;
    }
    firstIndex = foundIndex;
    end = OFFSET_PTR(u32, cursor, byteCount);
    do {
        *cursor ^= gBackupXorKeys29[firstIndex] +
                   (gBackupXorKeys19[secondIndex] + (gBackupXorKeys11[thirdIndex] + gBackupXorKeys17[fourthIndex]));
        cursor++;
        thirdIndex++;
        if (thirdIndex >= 0xb) {
            thirdIndex = 0;
            fourthIndex++;
            if (fourthIndex >= 0x11) {
                fourthIndex = 0;
                secondIndex++;
                if (secondIndex >= 0x13) {
                    secondIndex = 0;
                    firstIndex++;
                    if (firstIndex >= 0x1d) {
                        firstIndex = 0;
                    }
                }
            }
        }
    } while (cursor < end);
    return 1;
}

#pragma thumb off

void InitWLMenuSceneCallback(void) {
    if (gStartupWork->mConnectionKind == 3) {
        ReleaseCurrentOverlay();
        StartLoadOverlay(0);
        FinishOverlayLoad();
    }
    InitWLMenuScene(GetHeap(GetCurrentHeapCall()));
}
