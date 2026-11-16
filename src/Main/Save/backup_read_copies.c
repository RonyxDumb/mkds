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
#include "Main/Sound/sound_seq.h"
#include "file_command_handlers.h"
#include "file_archive_access.h"
#include "arena_cache_init.h"
#include "reset_interrupts_halt.h"
#include "shift_right_64.h"
#include "card_enable_and_lock.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"

u8 g_str_rom_0[] = "rom";
FileReadThread gFileReadThread;

void SomeThreadEntry2(void *unused) {
    FSArchive *archive;
    RomArchiveTransfer *romArchiveTransfer;
    RomArchiveParentView *archiveState;
    s32 chunkIndex;
    RomArchiveFileNode *node;
    u32 waitIrqState;
    u32 updateIrqState;
    s32 offset;
    u8 *chunk;
    archive = Fs_FindArchiveByMountName(g_str_rom_0, 3);
    romArchiveTransfer = &gRomArchiveTransfer;
    while (1) {
        waitIrqState = Os_DisableIrq();
        archiveState = &gRomArchiveTransfer.mParentView;
        node = archiveState->mPendingHead;
        if (node == NULL) {
            do {
                if (romArchiveTransfer->mState == 0) {
                    Os_RestoreIrq(waitIrqState);
                    return;
                }
                Os_Thread_Sleep(NULL);
                node = archiveState->mPendingHead;
            } while (node == NULL);
        }
        Os_RestoreIrq(waitIrqState);
        if (node->mState == 1) {
            Fs_File_OpenRaw(&node->mFile, archive, node->mFileStart, node->mFileStart + node->mFileLength,
                              node->mBlockId);
            chunkIndex = 0;
            offset = 0;
            chunk = node->mBuffers[0];
            for (; chunkIndex < 2; chunkIndex++) {
                node->mBufferOffsets[chunkIndex] = offset;
                Fs_File_Read(&node->mFile, chunk, 0x400);
                offset += 0x400;
                chunk += 0x400;
            }
            node->mLastBlockId = 0;
            node->mLastLoadedBufferIndex = 1;
            node->mLoadingBufferIndex = ROM_ARCHIVE_NODE_NO_BUFFER;
            updateIrqState = Os_DisableIrq();
            ActivateRomArchiveNode(&gRomArchiveTransfer.mParentView, node, 1);
            Os_RestoreIrq(updateIrqState);
        } else {
            Fs_File_Close(&node->mFile);
            updateIrqState = Os_DisableIrq();
            FreeRomArchiveNode(&gRomArchiveTransfer.mParentView, node);
            Os_RestoreIrq(updateIrqState);
        }
    }
}

void StartFileReadThread(void) {
    FileReadThread *fileReadThread;
    fileReadThread = (FileReadThread *) &gFileReadThread;
    fileReadThread->mUnk_4c4 = 0;
    fileReadThread->mUnk_4c0 = fileReadThread->mUnk_4c4;
    Os_Thread_Create(&fileReadThread->mThread, SomeThreadEntry2, fileReadThread, (u8 *) &fileReadThread->mThread, 0x400,
                    15);
    Os_Thread_WakeUpDirect(&fileReadThread->mThread);
}

void StopFileReadThread(void) {
    FileReadThread *fileReadThread;
    fileReadThread = (FileReadThread *) &gFileReadThread;
    if (Os_Thread_IsTerminated(&fileReadThread->mThread) != 0) {
        return;
    }
    do {
        Os_Thread_WakeUpDirect(&fileReadThread->mThread);
        Os_Thread_Join(&fileReadThread->mThread);
    } while (Os_Thread_IsTerminated(&fileReadThread->mThread) == 0);
}

#pragma thumb on

void SX1Zero_from_thumb(void) {
    g_SaveDataIoManager->mStatus = BACKUP_STATUS_IDLE;
}

void InitializeSaveDataIoManager_from_thumb(void *heap) {
    g_SaveDataIoManager = Mem_AllocateHeap(heap, sizeof(*g_SaveDataIoManager));
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        g_SaveDataIoManager->mBuffer = Mem_AllocateHeapAligned(heap, 0x2c00, HEAP_ALIGN_CACHE_LINE);
        g_SaveDataIoManager->mOneByteReadBuffer = Mem_AllocateHeapAligned(heap, 1, HEAP_ALIGN_CACHE_LINE);
    }
    g_SaveDataIoManager->mBackupEnabled = 0;
}

void InitializePrepareBackup_from_thumb(void) {
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT || Os_IsEmulator() != 0) {
        g_SaveDataIoManager->mBackupEnabled = 0;
        return;
    }
    g_SaveDataIoManager->mBackupEnabled = 1;
    AllocateLockCardBackupResource_from_thumb();
    MaybeInitializeBackup(0x1202);
    CleanupUnlockBackup_from_thumb();
    g_SaveDataIoManager->mStatus = BACKUP_STATUS_IDLE;
    g_SaveDataIoManager->mErrorCode = BACKUP_ERROR_NONE;
    g_SaveDataIoManager->mLockId = -3;
    g_SaveDataIoManager->mCommandRunning = 0;
    g_SaveDataIoManager->mCopyPass = BACKUP_COPY_PASS_SINGLE;
    g_SaveDataIoManager->mReadDestination = NULL;
    g_SaveDataIoManager->mReadSize = 0;
    g_SaveDataIoManager->mWriteSource = NULL;
    g_SaveDataIoManager->mWriteSize = 0;
    g_SaveDataIoManager->mUnk_58 = -1;
    g_SaveDataIoManager->mUnk_5c = -1;
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
    resultCode = Card_GetResult();
    CleanupUnlockBackup_from_thumb();
    g_SaveDataIoManager->mCommandRunning = 0;
    switch (resultCode) {
        case BACKUP_RESULT_OK:
            DC_SomeClean(g_SaveDataIoManager->mReadDestination, g_SaveDataIoManager->mReadSize);
            if (g_SaveDataIoManager->mReadHasPrefix != 0) {
                readWords = g_SaveDataIoManager->mReadDestination + 2;
                xorByteCount = g_SaveDataIoManager->mReadSize - 8;
                if (CheckBackupBlockPrefix((u8 *) g_SaveDataIoManager->mReadDestination) == 0) {
                    result = BACKUP_ERROR_BAD_PREFIX;
                }
            } else {
                readWords = g_SaveDataIoManager->mReadDestination;
                xorByteCount = g_SaveDataIoManager->mReadSize;
            }
            if (result == BACKUP_ERROR_NONE) {
                if (TryXorBackupWordsAtFoundIndex(readWords, xorByteCount, g_SaveDataIoManager->mExpectedFirstWord) == 0) {
                    result = BACKUP_ERROR_BAD_DATA;
                } else if (ClearTickBytesAndCheckBlockCrc((u8 *) g_SaveDataIoManager->mReadDestination,
                                                          g_SaveDataIoManager->mReadSize, 0) == 0) {
                    result = BACKUP_ERROR_BAD_DATA;
                } else if (g_SaveDataIoManager->mExpectedFirstWord != 0 && *readWords != g_SaveDataIoManager->mExpectedFirstWord) {
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
    readWords = g_SaveDataIoManager->mReadDestination;
    tailHalfword = *(u16 *) ((u8 *) readWords + g_SaveDataIoManager->mReadSize - 4);
    switch (g_SaveDataIoManager->mCopyPass) {
        case BACKUP_COPY_PASS_SINGLE:
            break;
        case BACKUP_COPY_PASS_FIRST:
            if (result != BACKUP_ERROR_UNAVAILABLE) {
                g_SaveDataIoManager->mFirstPassResult = result;
                g_SaveDataIoManager->mFirstPassBuffer = g_SaveDataIoManager->mReadDestination;
                g_SaveDataIoManager->mFirstPassTailHalfword = tailHalfword;
                readWords = OFFSET_PTR(u32, g_SaveDataIoManager->mReadDestination, g_SaveDataIoManager->mReadSize);
                StartBackupRead(g_SaveDataIoManager->mSecondPassAddress, readWords, g_SaveDataIoManager->mReadSize, callback,
                                BACKUP_COPY_PASS_SECOND, g_SaveDataIoManager->mExpectedFirstWord,
                                g_SaveDataIoManager->mReadHasPrefix);
                finished = FALSE;
            } else {
                finished = TRUE;
            }
            break;
        case BACKUP_COPY_PASS_SECOND:
            if (result == BACKUP_ERROR_NONE) {
                if (g_SaveDataIoManager->mFirstPassResult == BACKUP_ERROR_NONE) {
                    firstPassTailHalfword = g_SaveDataIoManager->mFirstPassTailHalfword;
                    if ((firstPassTailHalfword == 0 && tailHalfword == 0xffff) ||
                        firstPassTailHalfword >= tailHalfword) {
                        readWords = g_SaveDataIoManager->mFirstPassBuffer;
                    }
                }
            } else {
                if (g_SaveDataIoManager->mFirstPassResult == BACKUP_ERROR_NONE) {
                    result = BACKUP_ERROR_NONE;
                    readWords = g_SaveDataIoManager->mFirstPassBuffer;
                } else if (result == BACKUP_ERROR_UNAVAILABLE ||
                           g_SaveDataIoManager->mFirstPassResult == BACKUP_ERROR_UNAVAILABLE) {
                    result = BACKUP_ERROR_UNAVAILABLE;
                } else if (result != BACKUP_ERROR_ACCESS_FAILED &&
                           g_SaveDataIoManager->mFirstPassResult != BACKUP_ERROR_ACCESS_FAILED) {
                    if (result == BACKUP_ERROR_BAD_PREFIX &&
                        g_SaveDataIoManager->mFirstPassResult == BACKUP_ERROR_BAD_PREFIX) {
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
                callback(readWords, g_SaveDataIoManager->mReadSize);
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

u32 StartBackupRead(u32 address, u32 *destination, u32 byteCount, void (*callback)(u32 *, u32), s32 copyPass,
                    u32 expectedFirstWord, s32 hasPrefix) {
    if (g_SaveDataIoManager->mBackupEnabled == 0 || CardIsNotBusy() == 0) {
        return 0;
    }
    if (AllocateLockCardBackupResource_from_thumb() == 0) {
        return 0;
    }
    g_SaveDataIoManager->mErrorCode = BACKUP_ERROR_NONE;
    g_SaveDataIoManager->mCommandRunning = 1;
    g_SaveDataIoManager->mStatus = BACKUP_STATUS_READING;
    g_SaveDataIoManager->mReadAddress = address;
    g_SaveDataIoManager->mReadDestination = destination;
    g_SaveDataIoManager->mReadSize = byteCount;
    g_SaveDataIoManager->mExpectedFirstWord = expectedFirstWord;
    g_SaveDataIoManager->mReadHasPrefix = hasPrefix;
    g_SaveDataIoManager->mCopyPass = copyPass;
    DC_InvalidateRangeNoClean(destination, byteCount);
    Card_RequestStreamCommand(address, (u32) destination, byteCount, FinishBackupRead, callback, 1, 6, 1, 0);
    return 1;
}
#pragma thumb off

#pragma thumb on

void ReadSaveChunkImpl2_from_thumb(u32 address, void *destination, u32 byteCount, void (*callback)(u32 *, u32),
                            u32 expectedFirstWord) {
    u32 expectedWord = expectedFirstWord;
    u32 started =
        StartBackupRead(address, destination, byteCount, callback, BACKUP_COPY_PASS_SINGLE, expectedWord, 0x0u);
}

void ReadSaveChunkImpl_from_thumb(u32 firstAddress, u32 secondAddress, u32 *destination, u32 byteCount,
                              void (*callback)(u32 *, u32), u32 expectedFirstWord, s32 hasPrefix) {
    g_SaveDataIoManager->mSecondPassAddress = secondAddress;
    StartBackupRead(firstAddress, destination, byteCount, callback, BACKUP_COPY_PASS_FIRST, expectedFirstWord,
                    hasPrefix);
}

#pragma thumb off
