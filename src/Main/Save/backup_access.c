#include "Main/Save/backup_access.h"
#include "Main/Menu/wl_menu_scene.h"
#include "Main/System/heap_call.h"
#include "Main/Net/slot_result_sync.h"
#include "Main/Unknown/unk_02154000.h"
#include "os_spinLock.h"
#include "os_tick.h"
#include "card_common.h"
#include "01/Menu/record_time_attack.h"
#include "Main/Scene/scene_connection.h"

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
        if (expected == (value ^ (data_usa_02154694[index] +
                                  (data_usa_02154648[0] + (data_usa_021545d8[0] + data_usa_02154604[0]))))) {
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
    tableSum = data_usa_02154694[firstIndex] + (data_usa_02154648[0] + (data_usa_021545d8[0] + data_usa_02154604[0]));
    firstIndex = FindBackupXorIndex(tableSum ^ *cursor, *cursor);
    end = OFFSET_PTR(u32, cursor, byteCount);
    do {
        *cursor ^= data_usa_02154694[firstIndex] +
                   (data_usa_02154648[secondIndex] + (data_usa_021545d8[thirdIndex] + data_usa_02154604[fourthIndex]));
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
        *cursor ^= data_usa_02154694[firstIndex] +
                   (data_usa_02154648[secondIndex] + (data_usa_021545d8[thirdIndex] + data_usa_02154604[fourthIndex]));
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
