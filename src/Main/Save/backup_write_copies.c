#include "Main/Save/backup_write_copies.h"
#include "Main/Save/backup_access.h"
#include "Main/Save/backup_read_copies.h"
#include "arena_cache_init.h"
#include "card_enable_and_lock.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"

const u16 gCrcXorValue = 0x1021;

#pragma thumb on

void FinishBackupWrite(void *arg) {
    void (*callback)(u32 *, u32) = arg;
    u32 *buffer;
    u32 byteCount;
    s32 result;
    BOOL finished;
    u32 resultCode;
    finished = TRUE;
    resultCode = CARD_GetResultCode();
    UnlockBackup();
    result = BACKUP_ERROR_NONE;
    gBackupAccess->mCommandRunning = 0;
    switch (resultCode) {
        case ACCESS_RESULT_OK:
            result = BACKUP_ERROR_NONE;
            break;
        case ACCESS_RESULT_1:
        case ACCESS_RESULT_AGAIN:
        case ACCESS_RESULT_6:
            result = BACKUP_ERROR_UNAVAILABLE;
            break;
        case ACCESS_RESULT_2:
        case ROM_ACCESS_UNSUPPORTED_TYPE:
        case ACCESS_RESULT_5:
        case ACCESS_RESULT_STOPPED:
        default:
            result = BACKUP_ERROR_ACCESS_FAILED;
            break;
    }
    buffer = gBackupAccess->mWriteSource;
    byteCount = gBackupAccess->mWriteSize;
    switch (gBackupAccess->mCopyPass) {
        case BACKUP_COPY_PASS_SINGLE:
            finished = TRUE;
            break;
        case BACKUP_COPY_PASS_FIRST:
            gBackupAccess->mFirstPassResult = result;
            gBackupAccess->mFirstPassBuffer = gBackupAccess->mWriteSource;
            gBackupAccess->mFirstPassTailHalfword = 0;
            StartBackupWrite(gBackupAccess->mSecondPassAddress, gBackupAccess->mWriteSource, gBackupAccess->mWriteSize,
                             callback, BACKUP_COPY_PASS_SECOND, gBackupAccess->mWriteHasPrefix);
            finished = FALSE;
            break;
        case BACKUP_COPY_PASS_SECOND:
            if (result != BACKUP_ERROR_NONE) {
                if (gBackupAccess->mFirstPassResult == BACKUP_ERROR_NONE) {
                    buffer = gBackupAccess->mFirstPassBuffer;
                    result = BACKUP_ERROR_NONE;
                } else if (result == BACKUP_ERROR_UNAVAILABLE ||
                           gBackupAccess->mFirstPassResult == BACKUP_ERROR_UNAVAILABLE) {
                    result = BACKUP_ERROR_UNAVAILABLE;
                } else if (result != BACKUP_ERROR_ACCESS_FAILED &&
                           gBackupAccess->mFirstPassResult != BACKUP_ERROR_ACCESS_FAILED) {
                    result = BACKUP_ERROR_BAD_DATA;
                } else {
                    result = BACKUP_ERROR_ACCESS_FAILED;
                }
            }
            break;
    }
    if (finished != FALSE) {
        if (result == BACKUP_ERROR_NONE) {
            if (callback != NULL) {
                callback(buffer, byteCount);
            }
            ClearBackupAccessStatus();
            return;
        }
        if (result == BACKUP_ERROR_UNAVAILABLE) {
            gBackupAccess->mBackupEnabled = 0;
        }
        EndBackupAccessWithError(result);
    }
}

void FinishBackupOneByteRead(void *arg) {
    BOOL failed;
    failed = FALSE;
    if (CARD_GetResultCode() != 0) {
        failed = TRUE;
    }
    if (failed == FALSE) {
        ClearBackupAccessStatus();
        CARDi_RequestStreamCommand((u32) gBackupAccess->mWriteSource, gBackupAccess->mWriteAddress,
                                   gBackupAccess->mWriteSize, FinishBackupWrite, gBackupAccess->mWriteCallback, 1, 7,
                                   10, 2);
    } else {
        UnlockBackup();
        gBackupAccess->mCommandRunning = 0;
        EndBackupAccessWithError(failed);
    }
}

u32 StartBackupOneByteRead(void) {
    if (gBackupAccess->mBackupEnabled == 0 || CARD_TryWaitBackupAsync() == 0) {
        return 0;
    }
    if (TryLockBackup() == 0) {
        return 0;
    }
    CARDi_RequestStreamCommand(0, (u32) gBackupAccess->mOneByteReadBuffer, 1, FinishBackupOneByteRead, NULL, 1, 6, 1,
                               0);
    return 1;
}

u32 StartBackupWrite(u32 address, u32 *source, u32 byteCount, void (*callback)(u32 *, u32), s32 copyPass,
                     s32 hasPrefix) {
    u32 *xorStart;
    u32 xorByteCount;
    if (gBackupAccess->mBackupEnabled == 0 || CARD_TryWaitBackupAsync() == 0) {
        return 0;
    }
    gBackupAccess->mErrorCode = BACKUP_ERROR_NONE;
    gBackupAccess->mCommandRunning = 1;
    gBackupAccess->mStatus = BACKUP_STATUS_WRITING;
    gBackupAccess->mWriteAddress = address;
    gBackupAccess->mWriteSource = source;
    gBackupAccess->mWriteSize = byteCount;
    gBackupAccess->mWriteHasPrefix = hasPrefix;
    gBackupAccess->mWriteCallback = callback;
    gBackupAccess->mCopyPass = copyPass;
    if (copyPass != BACKUP_COPY_PASS_SECOND) {
        if (hasPrefix != 0) {
            xorStart = source + 2;
            xorByteCount = byteCount - 8;
        } else {
            xorStart = source;
            xorByteCount = byteCount;
        }
        WriteBlockTail((u8 *) source, byteCount, 0);
        XorBackupWordsAtTickIndex(xorStart, xorByteCount);
        DC_StoreRange(source, byteCount);
        return StartBackupOneByteRead();
    }
    CARDi_RequestStreamCommand((u32) source, address, byteCount, FinishBackupWrite, callback, 1, 7, 10, 2);
    return 1;
}

void StartBackupWriteTwoCopies(u32 firstAddress, u32 secondAddress, u32 *source, u32 byteCount,
                               void (*callback)(u32 *, u32), s32 hasPrefix) {
    gBackupAccess->mSecondPassAddress = secondAddress;
    StartBackupWrite(firstAddress, source, byteCount, callback, BACKUP_COPY_PASS_FIRST, hasPrefix);
}

void StartBackupWriteOneCopy(u32 address, void *source, u32 byteCount, void (*callback)(u32 *, u32)) {
    u32 started = StartBackupWrite(address, source, byteCount, callback, BACKUP_COPY_PASS_SINGLE, 0x0u);
}

#pragma thumb off
