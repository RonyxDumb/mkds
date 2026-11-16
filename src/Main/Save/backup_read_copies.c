#include "Main/Save/backup_read_copies.h"
#include "Main/System/heap.h"
#include "Main/Save/backup_access.h"
#include "thread_scheduler.h"
#include "Main/Net/rom_archive.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "file_command_handlers.h"
#include "file_archive_access.h"
#include "arena_cache_init.h"
#include "reset_interrupts_halt.h"
#include "shift_right_64.h"
#include "card_enable_and_lock.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"

u8 gRomArchiveName[] = "rom";
FileReadThread gFileReadThread;

void RunFileReadThread(void *unused) {
    FSArchive *archive;
    RomArchiveTransfer *romArchiveTransfer;
    RomArchiveParentView *parentView;
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
        parentView = &gRomArchiveTransfer.mParentOrChildView;
        node = parentView->mPendingHead;
        if (node == NULL) {
            do {
                if (romArchiveTransfer->mState == 0) {
                    OS_RestoreInterrupts(waitIrqState);
                    return;
                }
                OS_SleepThread(NULL);
                node = parentView->mPendingHead;
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
            node->mLoadingBufferIndex = ROM_ARCHIVE_NODE_NO_BUFFER;
            updateIrqState = OS_DisableInterrupts();
            ActivateRomArchiveNode(&gRomArchiveTransfer.mParentOrChildView, node, 1);
            OS_RestoreInterrupts(updateIrqState);
        } else {
            FS_CloseFile(&node->mFile);
            updateIrqState = OS_DisableInterrupts();
            FreeRomArchiveNode(&gRomArchiveTransfer.mParentOrChildView, node);
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
    gBackupAccess->mStatus = BACKUP_STATUS_CLEARED;
}

void CreateBackupAccess(void *heap) {
    gBackupAccess = HeapAlloc(heap, sizeof(*gBackupAccess));
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        gBackupAccess->mBuffer = HeapAllocAligned(heap, 0x2c00, HEAP_ALIGN_CACHE_LINE);
        gBackupAccess->mOneByteReadBuffer = HeapAllocAligned(heap, 1, HEAP_ALIGN_CACHE_LINE);
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
    gBackupAccess->mStatus = BACKUP_STATUS_CLEARED;
    gBackupAccess->mErrorCode = BACKUP_ERROR_NONE;
    gBackupAccess->mLockId = -3;
    gBackupAccess->mCommandRunning = 0;
    gBackupAccess->mCopyPass = BACKUP_COPY_PASS_SINGLE;
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

void FinishBackupRead(void *arg) {
    void (*callback)(u32 *, u32) = arg;
    u32 *readWords;
    u32 xorByteCount;
    s32 result;
    BOOL finished;
    u32 resultCode;
    u16 tailHalfword;
    u16 firstPassTailHalfword;
    result = BACKUP_ERROR_NONE;
    finished = TRUE;
    resultCode = CARD_GetResultCode();
    UnlockBackup();
    gBackupAccess->mCommandRunning = 0;
    switch (resultCode) {
        case BACKUP_RESULT_OK:
            DC_StoreRange(gBackupAccess->mReadDestination, gBackupAccess->mReadSize);
            if (gBackupAccess->mReadHasPrefix != 0) {
                readWords = gBackupAccess->mReadDestination + 2;
                xorByteCount = gBackupAccess->mReadSize - 8;
                if (CheckBackupBlockPrefix((u8 *) gBackupAccess->mReadDestination) == 0) {
                    result = BACKUP_ERROR_BAD_PREFIX;
                }
            } else {
                readWords = gBackupAccess->mReadDestination;
                xorByteCount = gBackupAccess->mReadSize;
            }
            if (result == BACKUP_ERROR_NONE) {
                if (TryXorBackupWordsAtFoundIndex(readWords, xorByteCount, gBackupAccess->mExpectedFirstWord) == 0) {
                    result = BACKUP_ERROR_BAD_DATA;
                } else if (ClearTickBytesAndCheckBlockCrc((u8 *) gBackupAccess->mReadDestination,
                                                          gBackupAccess->mReadSize, 0) == 0) {
                    result = BACKUP_ERROR_BAD_DATA;
                } else if (gBackupAccess->mExpectedFirstWord != 0 && *readWords != gBackupAccess->mExpectedFirstWord) {
                    result = BACKUP_ERROR_BAD_DATA;
                }
            }
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
    readWords = gBackupAccess->mReadDestination;
    tailHalfword = *(u16 *) ((u8 *) readWords + gBackupAccess->mReadSize - 4);
    switch (gBackupAccess->mCopyPass) {
        case BACKUP_COPY_PASS_SINGLE:
            break;
        case BACKUP_COPY_PASS_FIRST:
            if (result != BACKUP_ERROR_UNAVAILABLE) {
                gBackupAccess->mFirstPassResult = result;
                gBackupAccess->mFirstPassBuffer = gBackupAccess->mReadDestination;
                gBackupAccess->mFirstPassTailHalfword = tailHalfword;
                readWords = OFFSET_PTR(u32, gBackupAccess->mReadDestination, gBackupAccess->mReadSize);
                StartBackupRead(gBackupAccess->mSecondPassAddress, readWords, gBackupAccess->mReadSize, callback,
                                BACKUP_COPY_PASS_SECOND, gBackupAccess->mExpectedFirstWord,
                                gBackupAccess->mReadHasPrefix);
                finished = FALSE;
            } else {
                finished = TRUE;
            }
            break;
        case BACKUP_COPY_PASS_SECOND:
            if (result == BACKUP_ERROR_NONE) {
                if (gBackupAccess->mFirstPassResult == BACKUP_ERROR_NONE) {
                    firstPassTailHalfword = gBackupAccess->mFirstPassTailHalfword;
                    if ((firstPassTailHalfword == 0 && tailHalfword == 0xffff) ||
                        firstPassTailHalfword >= tailHalfword) {
                        readWords = gBackupAccess->mFirstPassBuffer;
                    }
                }
            } else {
                if (gBackupAccess->mFirstPassResult == BACKUP_ERROR_NONE) {
                    result = BACKUP_ERROR_NONE;
                    readWords = gBackupAccess->mFirstPassBuffer;
                } else if (result == BACKUP_ERROR_UNAVAILABLE ||
                           gBackupAccess->mFirstPassResult == BACKUP_ERROR_UNAVAILABLE) {
                    result = BACKUP_ERROR_UNAVAILABLE;
                } else if (result != BACKUP_ERROR_ACCESS_FAILED &&
                           gBackupAccess->mFirstPassResult != BACKUP_ERROR_ACCESS_FAILED) {
                    if (result == BACKUP_ERROR_BAD_PREFIX &&
                        gBackupAccess->mFirstPassResult == BACKUP_ERROR_BAD_PREFIX) {
                        result = BACKUP_ERROR_BAD_PREFIX;
                    } else {
                        result = BACKUP_ERROR_BAD_DATA;
                    }
                } else {
                    result = BACKUP_ERROR_ACCESS_FAILED;
                }
            }
            break;
    }
    if (finished != FALSE) {
        if (result == BACKUP_ERROR_NONE) {
            if (callback != NULL) {
                callback(readWords, gBackupAccess->mReadSize);
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

u32 StartBackupRead(u32 address, u32 *destination, u32 byteCount, void (*callback)(u32 *, u32), s32 copyPass,
                    u32 expectedFirstWord, s32 hasPrefix) {
    if (gBackupAccess->mBackupEnabled == 0 || CARD_TryWaitBackupAsync() == 0) {
        return 0;
    }
    if (TryLockBackup() == 0) {
        return 0;
    }
    gBackupAccess->mErrorCode = BACKUP_ERROR_NONE;
    gBackupAccess->mCommandRunning = 1;
    gBackupAccess->mStatus = BACKUP_STATUS_READING;
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
    u32 expectedWord = expectedFirstWord;
    u32 started =
        StartBackupRead(address, destination, byteCount, callback, BACKUP_COPY_PASS_SINGLE, expectedWord, 0x0u);
}

void StartBackupReadTwoCopies(u32 firstAddress, u32 secondAddress, u32 *destination, u32 byteCount,
                              void (*callback)(u32 *, u32), u32 expectedFirstWord, s32 hasPrefix) {
    gBackupAccess->mSecondPassAddress = secondAddress;
    StartBackupRead(firstAddress, destination, byteCount, callback, BACKUP_COPY_PASS_FIRST, expectedFirstWord,
                    hasPrefix);
}

#pragma thumb off
