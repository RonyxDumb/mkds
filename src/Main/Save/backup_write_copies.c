#include "Main/Save/backup_write_copies.h"
#include "Main/Unknown/code_0204b458.h"
#include "Main/Save/backup_access.h"
#include "Main/Unknown/code_0204b714.h"
#include "code_0200eddc.h"
#include "card_common.h"
#include "01/code_021956dc.h"

#pragma thumb on

void FinishBackupWrite(void (*callback)(u32 *, u32)) {
    u32 *buffer;
    u32 byteCount;
    s32 result;
    BOOL finished;
    u32 resultCode;
    finished = TRUE;
    resultCode = CARD_GetResultCode();
    UnlockBackup();
    result = 0;
    gBackupAccess->mCommandRunning = 0;
    switch (resultCode) {
        case 0:
            result = 0;
            break;
        case 1:
        case 4:
        case 6:
            result = 2;
            break;
        case 2:
        case 3:
        case 5:
        case 7:
        default:
            result = 1;
            break;
    }
    buffer = gBackupAccess->mWriteSource;
    byteCount = gBackupAccess->mWriteSize;
    switch (gBackupAccess->mCopyPass) {
        case 0:
            finished = TRUE;
            break;
        case 1:
            gBackupAccess->mFirstPassResult = result;
            gBackupAccess->mFirstPassBuffer = gBackupAccess->mWriteSource;
            gBackupAccess->mFirstPassTailHalfword = 0;
            StartBackupWrite(gBackupAccess->mSecondPassAddress, gBackupAccess->mWriteSource, gBackupAccess->mWriteSize,
                             callback, 2, gBackupAccess->mWriteHasPrefix);
            finished = FALSE;
            break;
        case 2:
            if (result != 0) {
                if (gBackupAccess->mFirstPassResult == 0) {
                    buffer = gBackupAccess->mFirstPassBuffer;
                    result = 0;
                } else if (result == 2 || gBackupAccess->mFirstPassResult == 2) {
                    result = 2;
                } else if (result != 1 && gBackupAccess->mFirstPassResult != 1) {
                    result = 3;
                } else {
                    result = 1;
                }
            }
            break;
    }
    if (finished != FALSE) {
        if (result == 0) {
            if (callback != NULL) {
                callback(buffer, byteCount);
            }
            ClearBackupAccessStatus();
            return;
        }
        if (result == 2) {
            gBackupAccess->mBackupEnabled = 0;
        }
        EndBackupAccessWithError(result);
    }
}

void FinishBackupOneByteRead(void) {
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
    gBackupAccess->mErrorCode = 0;
    gBackupAccess->mCommandRunning = 1;
    gBackupAccess->mStatus = 1;
    gBackupAccess->mWriteAddress = address;
    gBackupAccess->mWriteSource = source;
    gBackupAccess->mWriteSize = byteCount;
    gBackupAccess->mWriteHasPrefix = hasPrefix;
    gBackupAccess->mWriteCallback = callback;
    gBackupAccess->mCopyPass = copyPass;
    if (copyPass != 2) {
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

#pragma thumb off

#pragma thumb on

void StartBackupWriteTwoCopies(u32 firstAddress, u32 secondAddress, u32 *source, u32 byteCount,
                               void (*callback)(u32 *, u32), s32 hasPrefix) {
    gBackupAccess->mSecondPassAddress = secondAddress;
    StartBackupWrite(firstAddress, source, byteCount, callback, 1, hasPrefix);
}

void StartBackupWriteOneCopy(u32 address, void *source, u32 byteCount, void (*callback)(u32 *, u32)) {
    u32 started = StartBackupWrite(address, source, byteCount, callback, 0x0u, 0x0u);
}

#pragma thumb off
