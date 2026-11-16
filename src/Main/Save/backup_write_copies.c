#include "Main/Save/backup_write_copies.h"
#include "Main/Save/backup_access.h"
#include "Main/Save/backup_read_copies.h"
#include "arena_cache_init.h"
#include "card_enable_and_lock.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"

const u16 g_SomeCRCConst = 0x1021;

#pragma thumb on

void dma_fn_from_thumb(void *arg) {
    void (*callback)(u32 *, u32) = arg;
    u32 *buffer;
    u32 byteCount;
    s32 result;
    BOOL finished;
    u32 resultCode;
    finished = TRUE;
    resultCode = Card_GetResult();
    CleanupUnlockBackup_from_thumb();
    result = BACKUP_ERROR_NONE;
    g_SaveDataIoManager->mCommandRunning = 0;
    switch (resultCode) {
        case BACKUP_RESULT_OK:
            result = BACKUP_ERROR_NONE;
            break;
        case BACKUP_RESULT_FAILED:
        case BACKUP_RESULT_TIMED_OUT:
        case BACKUP_RESULT_NO_REPLY:
            result = BACKUP_ERROR_UNAVAILABLE;
            break;
        case BACKUP_RESULT_BAD_ARGUMENT:
        case BACKUP_RESULT_NOT_SUPPORTED:
        case BACKUP_RESULT_ERROR:
        case BACKUP_RESULT_CANCELED:
        default:
            result = BACKUP_ERROR_ACCESS_FAILED;
            break;
    }
    buffer = g_SaveDataIoManager->mWriteSource;
    byteCount = g_SaveDataIoManager->mWriteSize;
    switch (g_SaveDataIoManager->mCopyPass) {
        case BACKUP_COPY_PASS_SINGLE:
            finished = TRUE;
            break;
        case BACKUP_COPY_PASS_FIRST:
            g_SaveDataIoManager->mFirstPassResult = result;
            g_SaveDataIoManager->mFirstPassBuffer = g_SaveDataIoManager->mWriteSource;
            g_SaveDataIoManager->mFirstPassTailHalfword = 0;
            SV_MaybeCompressWriteImpl_from_thumb(g_SaveDataIoManager->mSecondPassAddress, g_SaveDataIoManager->mWriteSource, g_SaveDataIoManager->mWriteSize,
                             callback, BACKUP_COPY_PASS_SECOND, g_SaveDataIoManager->mWriteHasPrefix);
            finished = FALSE;
            break;
        case BACKUP_COPY_PASS_SECOND:
            if (result != BACKUP_ERROR_NONE) {
                if (g_SaveDataIoManager->mFirstPassResult == BACKUP_ERROR_NONE) {
                    buffer = g_SaveDataIoManager->mFirstPassBuffer;
                    result = BACKUP_ERROR_NONE;
                } else if (result == BACKUP_ERROR_UNAVAILABLE ||
                           g_SaveDataIoManager->mFirstPassResult == BACKUP_ERROR_UNAVAILABLE) {
                    result = BACKUP_ERROR_UNAVAILABLE;
                } else if (result != BACKUP_ERROR_ACCESS_FAILED &&
                           g_SaveDataIoManager->mFirstPassResult != BACKUP_ERROR_ACCESS_FAILED) {
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
            SX1Zero_from_thumb();
            return;
        }
        if (result == BACKUP_ERROR_UNAVAILABLE) {
            g_SaveDataIoManager->mBackupEnabled = 0;
        }
        EndBackupAccessWithError(result);
    }
}

void FinishBackupOneByteRead(void *arg) {
    BOOL failed;
    failed = FALSE;
    if (Card_GetResult() != 0) {
        failed = TRUE;
    }
    if (failed == FALSE) {
        SX1Zero_from_thumb();
        Card_RequestStreamCommand((u32) g_SaveDataIoManager->mWriteSource, g_SaveDataIoManager->mWriteAddress,
                                   g_SaveDataIoManager->mWriteSize, dma_fn_from_thumb, g_SaveDataIoManager->mWriteCallback, 1, 7,
                                   10, 2);
    } else {
        CleanupUnlockBackup_from_thumb();
        g_SaveDataIoManager->mCommandRunning = 0;
        EndBackupAccessWithError(failed);
    }
}

u32 StartBackupOneByteRead(void) {
    if (g_SaveDataIoManager->mBackupEnabled == 0 || CardIsNotBusy() == 0) {
        return 0;
    }
    if (AllocateLockCardBackupResource_from_thumb() == 0) {
        return 0;
    }
    Card_RequestStreamCommand(0, (u32) g_SaveDataIoManager->mOneByteReadBuffer, 1, FinishBackupOneByteRead, NULL, 1, 6, 1,
                               0);
    return 1;
}

u32 SV_MaybeCompressWriteImpl_from_thumb(u32 address, u32 *source, u32 byteCount, void (*callback)(u32 *, u32), s32 copyPass,
                     s32 hasPrefix) {
    u32 *xorStart;
    u32 xorByteCount;
    if (g_SaveDataIoManager->mBackupEnabled == 0 || CardIsNotBusy() == 0) {
        return 0;
    }
    g_SaveDataIoManager->mErrorCode = BACKUP_ERROR_NONE;
    g_SaveDataIoManager->mCommandRunning = 1;
    g_SaveDataIoManager->mStatus = BACKUP_STATUS_WRITING;
    g_SaveDataIoManager->mWriteAddress = address;
    g_SaveDataIoManager->mWriteSource = source;
    g_SaveDataIoManager->mWriteSize = byteCount;
    g_SaveDataIoManager->mWriteHasPrefix = hasPrefix;
    g_SaveDataIoManager->mWriteCallback = callback;
    g_SaveDataIoManager->mCopyPass = copyPass;
    if (copyPass != BACKUP_COPY_PASS_SECOND) {
        if (hasPrefix != 0) {
            xorStart = source + 2;
            xorByteCount = byteCount - 8;
        } else {
            xorStart = source;
            xorByteCount = byteCount;
        }
        CalculateCRCChecksum_from_thumb((u8 *) source, byteCount, 0);
        EncryptSaveData_from_thumb(xorStart, xorByteCount);
        DC_SomeClean(source, byteCount);
        return StartBackupOneByteRead();
    }
    Card_RequestStreamCommand((u32) source, address, byteCount, dma_fn_from_thumb, callback, 1, 7, 10, 2);
    return 1;
}

#pragma thumb off

#pragma thumb on

void SV_MaybeCompressWriteTwoOffsetsFlagC_from_thumb(u32 firstAddress, u32 secondAddress, u32 *source, u32 byteCount,
                               void (*callback)(u32 *, u32), s32 hasPrefix) {
    g_SaveDataIoManager->mSecondPassAddress = secondAddress;
    SV_MaybeCompressWriteImpl_from_thumb(firstAddress, source, byteCount, callback, BACKUP_COPY_PASS_FIRST, hasPrefix);
}

void SV_MaybeCompressWriteNoFlagsBC_from_thumb(u32 address, void *source, u32 byteCount, void (*callback)(u32 *, u32)) {
    u32 started = SV_MaybeCompressWriteImpl_from_thumb(address, source, byteCount, callback, BACKUP_COPY_PASS_SINGLE, 0x0u);
}

#pragma thumb off
