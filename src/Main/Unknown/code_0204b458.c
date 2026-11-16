#include "Main/Unknown/code_0204b458.h"
#include "Main/Unknown/code_0204b03c.h"
#include "Main/Unknown/code_0204b714.h"
#include "code_0200eddc.h"
#include "code_021457ec.h"
#include "01/code_021956dc.h"

#pragma thumb on

void savc_writeCallback(void (*callback)(u32 *, u32)) {
    u32 *buffer;
    u32 byteCount;
    s32 result;
    BOOL finished;
    u32 resultCode;
    finished = TRUE;
    resultCode = CARD_GetResultCode();
    savc_unlockCardBackup();
    result = 0;
    gSaveCore->mCommandRunning = 0;
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
    buffer = gSaveCore->mWriteSource;
    byteCount = gSaveCore->mWriteSize;
    switch (gSaveCore->mCopyPass) {
        case 0:
            finished = TRUE;
            break;
        case 1:
            gSaveCore->mFirstPassResult = result;
            gSaveCore->mFirstPassBuffer = gSaveCore->mWriteSource;
            gSaveCore->mFirstPassTailHalfword = 0;
            savc_write(gSaveCore->mSecondPassAddress, gSaveCore->mWriteSource, gSaveCore->mWriteSize,
                             callback, 2, gSaveCore->mWriteHasPrefix);
            finished = FALSE;
            break;
        case 2:
            if (result != 0) {
                if (gSaveCore->mFirstPassResult == 0) {
                    buffer = gSaveCore->mFirstPassBuffer;
                    result = 0;
                } else if (result == 2 || gSaveCore->mFirstPassResult == 2) {
                    result = 2;
                } else if (result != 1 && gSaveCore->mFirstPassResult != 1) {
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
            savc_resetStatus();
            return;
        }
        if (result == 2) {
            gSaveCore->mBackupEnabled = 0;
        }
        savc_handleError(result);
    }
}

void savc_writeReadCallback(void) {
    BOOL failed;
    failed = FALSE;
    if (CARD_GetResultCode() != 0) {
        failed = TRUE;
    }
    if (failed == FALSE) {
        savc_resetStatus();
        CARDi_RequestStreamCommand((u32) gSaveCore->mWriteSource, gSaveCore->mWriteAddress,
                                   gSaveCore->mWriteSize, (UnkFunc *) savc_writeCallback, gSaveCore->mWriteCallback,
                                   1, 7, 10, 2);
    } else {
        savc_unlockCardBackup();
        gSaveCore->mCommandRunning = 0;
        savc_handleError(failed);
    }
}

u32 savc_beginWrite(void) {
    if (gSaveCore->mBackupEnabled == 0 || CARD_TryWaitBackupAsync() == 0) {
        return 0;
    }
    if (savc_lockCardBackup() == 0) {
        return 0;
    }
    CARDi_RequestStreamCommand(0, (u32) gSaveCore->field64, 1, (UnkFunc *) savc_writeReadCallback, NULL, 1, 6, 1, 0);
    return 1;
}

u32 savc_write(u32 address, u32 *source, u32 byteCount, void (*callback)(u32 *, u32), s32 copyPass,
                     s32 hasPrefix) {
    u32 *xorStart;
    u32 xorByteCount;
    if (gSaveCore->mBackupEnabled == 0 || CARD_TryWaitBackupAsync() == 0) {
        return 0;
    }
    gSaveCore->mErrorCode = 0;
    gSaveCore->mCommandRunning = 1;
    gSaveCore->field0 = 1;
    gSaveCore->mWriteAddress = address;
    gSaveCore->mWriteSource = source;
    gSaveCore->mWriteSize = byteCount;
    gSaveCore->mWriteHasPrefix = hasPrefix;
    gSaveCore->mWriteCallback = callback;
    gSaveCore->mCopyPass = copyPass;
    if (copyPass != 2) {
        if (hasPrefix != 0) {
            xorStart = source + 2;
            xorByteCount = byteCount - 8;
        } else {
            xorStart = source;
            xorByteCount = byteCount;
        }
        savc_generateBlockFooter((u8 *) source, byteCount, 0);
        savc_encryptBlock(xorStart, xorByteCount);
        DC_StoreRange(source, byteCount);
        return savc_beginWrite();
    }
    CARDi_RequestStreamCommand((u32) source, address, byteCount, (UnkFunc *) savc_writeCallback, callback, 1, 7, 10, 2);
    return 1;
}

#pragma thumb off
