#include "Main/Save/backup_read_copies.h"
#include "Main/System/heap.h"
#include "Main/Save/backup_access.h"
#include "os_thread.h"
#include "Main/Net/rom_archive.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "code_02003024.h"
#include "code_02003be0.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_02133458.h"
#include "card_common.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"

u8 gRomArchiveName[] = "rom";
FileReadThread gFileReadThread;

void RunFileReadThread(void *unused) {
    FSArchive *archive;
    RomArchiveTransfer *romArchiveTransfer;
    RomArchiveParentView *archiveState;
    s32 chunkIndex;
    RomArchiveFileNode *node;
    u32 waitIrqState;
    u32 updateIrqState;
    s32 offset;
    u8 *chunk;
    archive = FS_FindArchive(gRomArchiveName, 3);
    romArchiveTransfer = &gRomArchiveTransfer;
    while (1) {
        waitIrqState = OS_DisableInterrupts();
        archiveState = &gRomArchiveTransfer.mParentView;
        node = archiveState->mPendingHead;
        if (node == NULL) {
            do {
                if (romArchiveTransfer->mState == 0) {
                    OS_RestoreInterrupts(waitIrqState);
                    return;
                }
                OS_SleepThread(NULL);
                node = archiveState->mPendingHead;
            } while (node == NULL);
        }
        OS_RestoreInterrupts(waitIrqState);
        if (node->mState == 1) {
            FS_OpenFileDirect(&node->mFile, archive, node->mFileStart, node->mFileStart + node->mFileLength,
                              node->mBlockId);
            chunkIndex = 0;
            offset = 0;
            chunk = node->mBuffers[0];
            for (; chunkIndex < 2; chunkIndex++) {
                node->mBufferOffsets[chunkIndex] = offset;
                FS_ReadFile(&node->mFile, chunk, 0x400);
                offset += 0x400;
                chunk += 0x400;
            }
            node->mLastBlockId = 0;
            node->mLastLoadedBufferIndex = 1;
            node->mLoadingBufferIndex = 2;
            updateIrqState = OS_DisableInterrupts();
            ActivateRomArchiveNode(&gRomArchiveTransfer.mParentView, node, 1);
            OS_RestoreInterrupts(updateIrqState);
        } else {
            FS_CloseFile(&node->mFile);
            updateIrqState = OS_DisableInterrupts();
            FreeRomArchiveNode(&gRomArchiveTransfer.mParentView, node);
            OS_RestoreInterrupts(updateIrqState);
        }
    }
}

void StartFileReadThread(void) {
    FileReadThread *fileReadThread;
    fileReadThread = (FileReadThread *) &gFileReadThread;
    fileReadThread->mUnk_4c4 = 0;
    fileReadThread->mUnk_4c0 = fileReadThread->mUnk_4c4;
    OS_CreateThread(&fileReadThread->mThread, RunFileReadThread, fileReadThread, (u8 *) &fileReadThread->mThread, 0x400,
                    15);
    OS_WakeupThreadDirect(&fileReadThread->mThread);
}

void StopFileReadThread(void) {
    FileReadThread *fileReadThread;
    fileReadThread = (FileReadThread *) &gFileReadThread;
    if (OS_IsThreadTerminated(&fileReadThread->mThread) != 0) {
        return;
    }
    do {
        OS_WakeupThreadDirect(&fileReadThread->mThread);
        OS_JoinThread(&fileReadThread->mThread);
    } while (OS_IsThreadTerminated(&fileReadThread->mThread) == 0);
}

#pragma thumb on

void ClearBackupAccessStatus(void) {
    gBackupAccess->mStatus = 0;
}

void CreateBackupAccess(void *heap) {
    gBackupAccess = HeapAlloc(heap, 0x70);
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        gBackupAccess->mBuffer = HeapAllocAligned(heap, 0x2c00, 0x20);
        gBackupAccess->mOneByteReadBuffer = HeapAllocAligned(heap, 1, 0x20);
    }
    gBackupAccess->mBackupEnabled = 0;
}

void InitBackupAccess(void) {
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT || OS_IsRunOnEmulator() != 0) {
        gBackupAccess->mBackupEnabled = 0;
        return;
    }
    gBackupAccess->mBackupEnabled = 1;
    TryLockBackup();
    CARD_IdentifyBackup(0x1202);
    UnlockBackup();
    gBackupAccess->mStatus = 0;
    gBackupAccess->mErrorCode = 0;
    gBackupAccess->mLockId = -3;
    gBackupAccess->mCommandRunning = 0;
    gBackupAccess->mCopyPass = 0;
    gBackupAccess->mReadDestination = NULL;
    gBackupAccess->mReadSize = 0;
    gBackupAccess->mWriteSource = NULL;
    gBackupAccess->mWriteSize = 0;
    gBackupAccess->mUnk_58 = -1;
    gBackupAccess->mUnk_5c = -1;
}

BOOL CheckBackupBlockPrefix(u8 *cursor) {
    BOOL allMatch;
    u8 index;
    allMatch = TRUE;
    index = 0;
    while (allMatch == TRUE && index < 8) {
        if (*cursor != (u8) (ShiftRightLogical64(0x3031565353444b4dull, index * 8) & 0xff)) {
            allMatch = FALSE;
        }
        index++;
        cursor++;
    }
    return allMatch;
}

void FinishBackupRead(void (*callback)(u32 *, u32)) {
    u32 *readWords;
    u32 xorByteCount;
    s32 result;
    BOOL finished;
    u32 resultCode;
    u16 tailHalfword;
    u16 firstPassTailHalfword;
    result = 0;
    finished = TRUE;
    resultCode = CARD_GetResultCode();
    UnlockBackup();
    gBackupAccess->mCommandRunning = 0;
    switch (resultCode) {
        case 0:
            DC_StoreRange(gBackupAccess->mReadDestination, gBackupAccess->mReadSize);
            if (gBackupAccess->mReadHasPrefix != 0) {
                readWords = gBackupAccess->mReadDestination + 2;
                xorByteCount = gBackupAccess->mReadSize - 8;
                if (CheckBackupBlockPrefix((u8 *) gBackupAccess->mReadDestination) == 0) {
                    result = 4;
                }
            } else {
                readWords = gBackupAccess->mReadDestination;
                xorByteCount = gBackupAccess->mReadSize;
            }
            if (result == 0) {
                if (TryXorBackupWordsAtFoundIndex(readWords, xorByteCount, gBackupAccess->mExpectedFirstWord) == 0) {
                    result = 3;
                } else if (ClearTickBytesAndCheckBlockCrc((u8 *) gBackupAccess->mReadDestination,
                                                          gBackupAccess->mReadSize, 0) == 0) {
                    result = 3;
                } else if (gBackupAccess->mExpectedFirstWord != 0 && *readWords != gBackupAccess->mExpectedFirstWord) {
                    result = 3;
                }
            }
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
    readWords = gBackupAccess->mReadDestination;
    tailHalfword = *(u16 *) ((u8 *) readWords + gBackupAccess->mReadSize - 4);
    switch (gBackupAccess->mCopyPass) {
        case 0:
            break;
        case 1:
            if (result != 2) {
                gBackupAccess->mFirstPassResult = result;
                gBackupAccess->mFirstPassBuffer = gBackupAccess->mReadDestination;
                gBackupAccess->mFirstPassTailHalfword = tailHalfword;
                readWords = OFFSET_PTR(u32, gBackupAccess->mReadDestination, gBackupAccess->mReadSize);
                StartBackupRead(gBackupAccess->mSecondPassAddress, readWords, gBackupAccess->mReadSize, callback, 2,
                                gBackupAccess->mExpectedFirstWord, gBackupAccess->mReadHasPrefix);
                finished = FALSE;
            } else {
                finished = TRUE;
            }
            break;
        case 2:
            if (result == 0) {
                if (gBackupAccess->mFirstPassResult == 0) {
                    firstPassTailHalfword = gBackupAccess->mFirstPassTailHalfword;
                    if ((firstPassTailHalfword == 0 && tailHalfword == 0xffff) ||
                        firstPassTailHalfword >= tailHalfword) {
                        readWords = gBackupAccess->mFirstPassBuffer;
                    }
                }
            } else {
                if (gBackupAccess->mFirstPassResult == 0) {
                    result = 0;
                    readWords = gBackupAccess->mFirstPassBuffer;
                } else if (result == 2 || gBackupAccess->mFirstPassResult == 2) {
                    result = 2;
                } else if (result != 1 && gBackupAccess->mFirstPassResult != 1) {
                    if (result == 4 && gBackupAccess->mFirstPassResult == 4) {
                        result = 4;
                    } else {
                        result = 3;
                    }
                } else {
                    result = 1;
                }
            }
            break;
    }
    if (finished != FALSE) {
        if (result == 0) {
            if (callback != NULL) {
                callback(readWords, gBackupAccess->mReadSize);
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

u32 StartBackupRead(u32 address, u32 *destination, u32 byteCount, void (*callback)(u32 *, u32), s32 copyPass,
                    u32 expectedFirstWord, s32 hasPrefix) {
    if (gBackupAccess->mBackupEnabled == 0 || CARD_TryWaitBackupAsync() == 0) {
        return 0;
    }
    if (TryLockBackup() == 0) {
        return 0;
    }
    gBackupAccess->mErrorCode = 0;
    gBackupAccess->mCommandRunning = 1;
    gBackupAccess->mStatus = 3;
    gBackupAccess->mReadAddress = address;
    gBackupAccess->mReadDestination = destination;
    gBackupAccess->mReadSize = byteCount;
    gBackupAccess->mExpectedFirstWord = expectedFirstWord;
    gBackupAccess->mReadHasPrefix = hasPrefix;
    gBackupAccess->mCopyPass = copyPass;
    DC_InvalidateRange(destination, byteCount);
    CARDi_RequestStreamCommand(address, (u32) destination, byteCount, FinishBackupRead, callback, 1, 6, 1, 0);
    return 1;
}
#pragma thumb off

#pragma thumb on

void StartBackupReadOneCopy(u32 address, void *destination, u32 byteCount, void (*callback)(u32 *, u32),
                            u32 expectedFirstWord) {
    u32 v4 = expectedFirstWord;
    u32 started = StartBackupRead(address, destination, byteCount, callback, 0x0u, v4, 0x0u);
}

void StartBackupReadTwoCopies(u32 firstAddress, u32 secondAddress, u32 *destination, u32 byteCount,
                              void (*callback)(u32 *, u32), u32 expectedFirstWord, s32 hasPrefix) {
    gBackupAccess->mSecondPassAddress = secondAddress;
    StartBackupRead(firstAddress, destination, byteCount, callback, 1, expectedFirstWord, hasPrefix);
}

#pragma thumb off
