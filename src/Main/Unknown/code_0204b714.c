#include "Main/Unknown/code_0204b714.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_0204b03c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0204bca0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_02176000.h"
#include "code_02003be0.h"
#include "os_thread.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_02133458.h"
#include "code_021457ec.h"
#include "01/code_021956dc.h"

void WFSi_TaskThread(void *a) {
    FSArchive *archive;
    RomArchiveTransfer *g;
    Unk021762e0 *b;
    s32 i;
    RomArchiveFileNode *r;
    u32 waitIrqState;
    u32 updateIrqState;
    s32 offset;
    u8 *chunk;
    archive = FS_FindArchive(aRom, 3);
    g = &gRomArchiveTransfer;
    while (1) {
        waitIrqState = OS_DisableInterrupts();
        b = (Unk021762e0 *) &data_02176300;
        r = b->field46C8;
        if (r == NULL) {
            do {
                if (g->mState == 0) {
                    OS_RestoreInterrupts(waitIrqState);
                    return;
                }
                OS_SleepThread(NULL);
                r = b->field46C8;
            } while (r == NULL);
        }
        OS_RestoreInterrupts(waitIrqState);
        if (r->mState == 1) {
            FS_OpenFileDirect(&r->mFile, archive, r->mFileStart, r->mFileStart + r->mFileLength, r->mBlockId);
            i = 0;
            offset = 0;
            chunk = r->mBuffers[0];
            for (; i < 2; i++) {
                r->mBufferOffsets[i] = offset;
                FS_ReadFile(&r->mFile, chunk, 0x400);
                offset += 0x400;
                chunk += 0x400;
            }
            r->field98 = 0;
            r->fieldA0 = 1;
            r->field9C = 2;
            updateIrqState = OS_DisableInterrupts();
            WFSi_SendOpenAck(&data_02176300, r, 1);
            OS_RestoreInterrupts(updateIrqState);
        } else {
            FS_CloseFile(&r->mFile);
            updateIrqState = OS_DisableInterrupts();
            WFSi_FromBusyToFree(&data_02176300, r);
            OS_RestoreInterrupts(updateIrqState);
        }
    }
}

void WFSi_CreateTaskThread(void) {
    FileReadThread *fileReadThread;
    fileReadThread = (FileReadThread *) &gFileReadThread;
    fileReadThread->field4C4 = 0;
    fileReadThread->field4C0 = fileReadThread->field4C4;
    OS_CreateThread(&fileReadThread->mThread, (void (*)(void *)) WFSi_TaskThread, fileReadThread,
                    (u8 *) &fileReadThread->mThread, 0x400, 15);
    OS_WakeupThreadDirect(&fileReadThread->mThread);
}

void WFSi_EndTaskThread(void) {
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

void savc_resetStatus(void) {
    gSaveCore->field0 = 0;
}

void savc_init(void *heap) {
    gSaveCore = heap_alloc(heap, 0x70);
    if (((Unk027ffc40 *) 0x027ffc40)->field0 != 2) {
        gSaveCore->mBuffer = heap_allocEx(heap, 0x2c00, 0x20);
        gSaveCore->field64 = heap_allocEx(heap, 1, 0x20);
    }
    gSaveCore->mBackupEnabled = 0;
}

void savc_initBackup(void) {
    if (((Unk027ffc40 *) 0x027ffc40)->field0 == 2 || OS_IsRunOnEmulator() != 0) {
        gSaveCore->mBackupEnabled = 0;
        return;
    }
    gSaveCore->mBackupEnabled = 1;
    savc_lockCardBackup();
    CARD_IdentifyBackup(0x1202);
    savc_unlockCardBackup();
    gSaveCore->field0 = 0;
    gSaveCore->mErrorCode = 0;
    gSaveCore->mLockId = -3;
    gSaveCore->mCommandRunning = 0;
    gSaveCore->mCopyPass = 0;
    gSaveCore->mReadDestination = NULL;
    gSaveCore->mReadSize = 0;
    gSaveCore->mWriteSource = NULL;
    gSaveCore->mWriteSize = 0;
    gSaveCore->field58 = -1;
    gSaveCore->field5C = -1;
}

BOOL savc_checkHeaderSignature(u8 *cursor) {
    BOOL allMatch;
    u8 index;
    allMatch = TRUE;
    index = 0;
    while (allMatch == TRUE && index < 8) {
        if (*cursor != (u8) (_ll_ushr(0x3031565353444b4dull, index * 8) & 0xff)) {
            allMatch = FALSE;
        }
        index++;
        cursor++;
    }
    return allMatch;
}

void savc_readCallback(void (*callback)(u32 *, u32)) {
    u32 *p;
    u32 xorByteCount;
    s32 result;
    BOOL finished;
    u32 resultCode;
    u16 tailHalfword;
    u16 firstPassTailHalfword;
    result = 0;
    finished = TRUE;
    resultCode = CARD_GetResultCode();
    savc_unlockCardBackup();
    gSaveCore->mCommandRunning = 0;
    switch (resultCode) {
        case 0:
            DC_StoreRange(gSaveCore->mReadDestination, gSaveCore->mReadSize);
            if (gSaveCore->mReadHasPrefix != 0) {
                p = OFFSET_PTR(u32, gSaveCore->mReadDestination, 8);
                xorByteCount = gSaveCore->mReadSize - 8;
                if (savc_checkHeaderSignature((u8 *) gSaveCore->mReadDestination) == 0) {
                    result = 4;
                }
            } else {
                p = gSaveCore->mReadDestination;
                xorByteCount = gSaveCore->mReadSize;
            }
            if (result == 0) {
                if (savc_decryptBlock(p, xorByteCount, gSaveCore->mExpectedFirstWord) == 0) {
                    result = 3;
                } else if (savc_handleBlockFooter((u8 *) gSaveCore->mReadDestination,
                                                          gSaveCore->mReadSize, 0) == 0) {
                    result = 3;
                } else if (gSaveCore->mExpectedFirstWord != 0 && *p != gSaveCore->mExpectedFirstWord) {
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
    p = gSaveCore->mReadDestination;
    tailHalfword = *(u16 *) ((u8 *) p + gSaveCore->mReadSize - 4);
    switch (gSaveCore->mCopyPass) {
        case 0:
            break;
        case 1:
            if (result != 2) {
                gSaveCore->mFirstPassResult = result;
                gSaveCore->mFirstPassBuffer = gSaveCore->mReadDestination;
                gSaveCore->mFirstPassTailHalfword = tailHalfword;
                p = OFFSET_PTR(u32, gSaveCore->mReadDestination, gSaveCore->mReadSize);
                savc_read(gSaveCore->mSecondPassAddress, p, gSaveCore->mReadSize, callback, 2,
                                gSaveCore->mExpectedFirstWord, gSaveCore->mReadHasPrefix);
                finished = FALSE;
            } else {
                finished = TRUE;
            }
            break;
        case 2:
            if (result == 0) {
                if (gSaveCore->mFirstPassResult == 0) {
                    firstPassTailHalfword = gSaveCore->mFirstPassTailHalfword;
                    if ((firstPassTailHalfword == 0 && tailHalfword == 0xffff) ||
                        firstPassTailHalfword >= tailHalfword) {
                        p = gSaveCore->mFirstPassBuffer;
                    }
                }
            } else {
                if (gSaveCore->mFirstPassResult == 0) {
                    result = 0;
                    p = gSaveCore->mFirstPassBuffer;
                } else if (result == 2 || gSaveCore->mFirstPassResult == 2) {
                    result = 2;
                } else if (result != 1 && gSaveCore->mFirstPassResult != 1) {
                    if (result == 4 && gSaveCore->mFirstPassResult == 4) {
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
                callback(p, gSaveCore->mReadSize);
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

u32 savc_read(u32 address, u32 *destination, u32 byteCount, void (*callback)(u32 *, u32), s32 copyPass,
                    u32 expectedFirstWord, s32 hasPrefix) {
    if (gSaveCore->mBackupEnabled == 0 || CARD_TryWaitBackupAsync() == 0) {
        return 0;
    }
    if (savc_lockCardBackup() == 0) {
        return 0;
    }
    gSaveCore->mErrorCode = 0;
    gSaveCore->mCommandRunning = 1;
    gSaveCore->field0 = 3;
    gSaveCore->mReadAddress = address;
    gSaveCore->mReadDestination = destination;
    gSaveCore->mReadSize = byteCount;
    gSaveCore->mExpectedFirstWord = expectedFirstWord;
    gSaveCore->mReadHasPrefix = hasPrefix;
    gSaveCore->mCopyPass = copyPass;
    DC_InvalidateRange(destination, byteCount);
    CARDi_RequestStreamCommand(address, (u32) destination, byteCount, (UnkFunc *) savc_readCallback, callback, 1, 6, 1, 0);
    return 1;
}
