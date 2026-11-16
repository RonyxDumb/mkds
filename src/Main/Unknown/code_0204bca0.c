#include "Main/Unknown/code_0204bca0.h"

#include "03/code_021b94b8.h"
#include "os_thread.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02176000.h"
#include "Main/Unknown/unk_02179000.h"
#include "Main/Unknown/code_0204b714.h"
#include "Main/Unknown/code_0204c000.h"
#include "Main/Unknown/code_02006380.h"
#include "Main/Unknown/code_02006954.h"
#include "code_02003be0.h"
#include "code_02142eac.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0204b000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0200692c.h"
#include "Main/Unknown/unk_02154000.h"
#include "fs_file.h"
#include "code_02004dc0.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0204db40.h"
#include "Main/Unknown/code_0204db48.h"
#include "Main/Unknown/unk_02165000.h"

typedef struct RomTableHeader {
    u8 field0[0x40];
    u32 mFntOffset;
    u32 mFntSize;
    u32 mFatOffset;
    u32 mFatSize;
    u32 mOverlayTable0Offset;
    u32 mOverlayTable0Size;
    u32 mOverlayTable1Offset;
    u32 mOverlayTable1Size;
} RomTableHeader;

s32 WFSi_RomArchiveProc(FSFile *file, u32 command) {
    switch (command) {
        case 0:
            if (gRomArchiveTransfer.mState != 2) {
                return 5;
            }
            if (file->mArg.p.field8 == 0) {
                return 0;
            }
            WFSi_ReadRequest(file);
            return 6;
        case 1:
            return 4;
        default:
            return 8;
    }
}

void WFSi_LoadTables(FSFile *file, s32 appendOverlays) {
    RomTableHeader fileHeader;
    FSFile romFile;
    Unk02005704 tables[4];
    u32 paddedSizes[4];
    u32 *tablePointers[4];
    u32 *block;
    u32 blockSize;
    enum { K0 } appendOverlayEntries;
    u32 imageOffset;
    u32 positionOffset;
    RomTableHeader *header;
    u32 origin;
    u32 pairSize;
    u32 v13;
    BOOL noFile;
    s32 i;
    BOOL k;

    blockSize = 0;
    noFile = file == NULL;
    appendOverlayEntries = 0;
    appendOverlayEntries = (s32) appendOverlayEntries;
    if (noFile == FALSE) {
        if (appendOverlays != 0) {
            appendOverlayEntries = 1;
        }
    }
    FS_InitFile(&romFile);
    FS_OpenFileDirect(&romFile, FS_FindArchive(aRom_1, 3), 0, 0x7fffffff, -1);
    if (noFile != FALSE) {
        imageOffset = 0;
        positionOffset = 0;
        header = (RomTableHeader *) 0x027ffe00;
    } else {
        i = file->field2C - file->mProp.w.field4;
        imageOffset = i + file->mProp.w.field4;
        header = &fileHeader;
        positionOffset = imageOffset;
        FS_ReadFile(file, header, 0x60);
        FS_SeekFile(file, i, 0);
    }
    if (appendOverlayEntries == 0) {
        tables[0] = *(Unk02005704 *) &header->mFatOffset;
        tables[1] = *(Unk02005704 *) &header->mFntOffset;
        tables[2] = *(Unk02005704 *) &header->mOverlayTable0Offset;
        tables[3] = *(Unk02005704 *) &header->mOverlayTable1Offset;
    } else {
        tables[0] = *(Unk02005704 *) 0x027ffe48;
        tables[1] = *(Unk02005704 *) 0x027ffe40;
        positionOffset = 0;
        tables[2].field0 = (u8 *) (header->mOverlayTable0Offset + imageOffset);
        tables[2].field4 = header->mOverlayTable0Size;
        tables[3].field0 = (u8 *) (header->mOverlayTable1Offset + imageOffset);
        tables[3].field4 = header->mOverlayTable1Size;
    }
    blockSize = blockSize + 4;
    for (i = 0; i < 4; i++) {
        paddedSizes[i] = (tables[i].field4 + 0x1f) & ~0x1f;
        blockSize = blockSize + (paddedSizes[i] + 4);
    }
    if (appendOverlayEntries != 0) {
        for (i = 2; i < 4; i++) {
            v13 = (((tables[i].field4 >> 5) << 3) + 0x1f) & ~0x1f;
            paddedSizes[0] = paddedSizes[0] + v13;
            blockSize = blockSize + v13;
        }
    }
    v13 = OS_DisableInterrupts();
    block = gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, blockSize, NULL);
    OS_RestoreInterrupts(v13);
    *block = positionOffset;
    origin = 0;
    k = FALSE;
    {
        u32 *cursor = block + 1;
        u32 *q;
        s32 j;
        for (j = 0; j < 4; j++) {
            tablePointers[j] = cursor;
            q = tablePointers[j];
            *q = tables[j].field4;
            FS_SeekFile(&romFile, positionOffset + (u32) tables[j].field0, origin);
            FS_ReadFile(&romFile, q + 1, *q);
            cursor = OFFSET_PTR(u32, cursor, (paddedSizes[j] + 4));
        }
    }
    if (appendOverlayEntries != 0) {
        u32 *fatBlock = tablePointers[0];
        u8 *fatEntries = (u8 *) (fatBlock + 1);
        s32 entryCount = *fatBlock >> 3;
        OverlayTableEntry *q;
        s32 l;
        u32 *appendCursor = (u32 *) (fatEntries + (entryCount << 3));
        u32 fatPosition = imageOffset + header->mFatOffset;
        pairSize = 8;
        for (i = 2; i < 4; i++) {
            u32 *overlayTable = tablePointers[i];
            s32 overlayCount;
            q = (OverlayTableEntry *) (overlayTable + 1);
            overlayCount = *overlayTable >> 5;
            for (l = 0; l < overlayCount; l++) {
                FS_SeekFile(&romFile, fatPosition + (q[l].mFileId << 3), origin);
                FS_ReadFile(&romFile, appendCursor, pairSize);
                *(u32 *) (fatEntries + ((u32) entryCount * 8)) =
                    *(u32 *) (fatEntries + ((u32) entryCount * 8)) + imageOffset;
                ((u32 *) (fatEntries + ((u32) entryCount * 8)))[1] =
                    ((u32 *) (fatEntries + ((u32) entryCount * 8)))[1] + imageOffset;
                q[l].mFileId = entryCount;
                entryCount++;
                appendCursor += 2;
            }
        }
        *tablePointers[0] = entryCount << 3;
    }
    DC_FlushRange(block, blockSize);
    DC_WaitWriteBufferEmpty();
    FS_CloseFile(&romFile);
    gRomArchiveTransfer.mArchiveBlock = block;
    gRomArchiveTransfer.mArchiveBlockSize = blockSize;
}

u32 WFSi_ReplaceRomArchive(u32 *block) {
    Unk02005704 tables[4];
    u32 positionOffset;
    FSArchive *archive;
    s32 i;

    archive = FS_FindArchive(aRom_0, 3);
    FS_UnloadArchive(archive);
    FS_SetArchiveProc(archive, WFSi_RomArchiveProc, -1);
    positionOffset = *block++;
    for (i = 0; i < 4; i++) {
        tables[i].field0 = (u8 *) (block + 1);
        tables[i].field4 = *block;
        block = (u32 *) (tables[i].field0 + ((tables[i].field4 + 0x1f) & ~0x1f));
    }
    FS_LoadArchive(archive, NULL, (u32) tables[0].field0, tables[0].field4, (u32) tables[1].field0,
                   tables[1].field4, WFSi_ReadRomCallback, WFSi_WriteRomCallback);
    FS_AttachOverlayTable(0, tables[2].field0, tables[2].field4);
    FS_AttachOverlayTable(1, tables[3].field0, tables[3].field4);
    return positionOffset;
}

void WFSi_OnSendMessageDone(void) {
    RomArchiveTransfer *transfer = &gRomArchiveTransfer;

    if (transfer->mState == 0) {
        return;
    }
    if (transfer->mIsParent == 0) {
        return;
    }
    transfer->field440.mMessageSendPending = FALSE;
    WFSi_SendAck();
}

void WFSi_SendAck(void) {
    RomArchiveMessage sizeMessage;
    RomArchiveMessage replyMessage;
    BOOL v6;
    RomArchiveParentViewEntry *firstEntry;
    s32 sendMask;
    s32 i;
    s32 v5;
    s32 v7;
    RomArchiveParentViewEntry *entry;
    u32 childPacketSize;
    s32 g;
    RomArchiveTransfer *transfer = &gRomArchiveTransfer;
    RomArchiveParentView *view = OFFSET_PTR(RomArchiveParentView, transfer, 0x440);
    s32 blockId;

    if (transfer->mIsParent == 0) {
        return;
    }
    if (view->mMessageSendPending != FALSE) {
        return;
    }
    view->field46CC = view->field46CC & view->field46D8;
    view->field46D0 = view->field46D0 & view->field46D8;
    view->field46DC = view->field46DC & view->field46D8;
    view->field46E8 = view->field46E8 & view->field46D8;
    if (view->field46E0 != FALSE && view->field46E4 == 0) {
        g = view->field46EC;
        childPacketSize = gRomArchiveTransfer.mChildPacketSize;
        view->field46E0 = FALSE;
        gRomArchiveTransfer.mParentPacketSize = g;
        TrySetChunkSizes(g, childPacketSize);
        g = view->field46E8;
        if (g == 0) {
            return;
        }
        sizeMessage.mKind = 1;
        sizeMessage.field0_8 = 0;
        sizeMessage.field4 = 0;
        sizeMessage.mPacketSizeHigh = (gRomArchiveTransfer.mParentPacketSize >> 8) & 0xff;
        sizeMessage.mPacketSizeLow = gRomArchiveTransfer.mParentPacketSize;
        if (RequestSendBytes(g, &sizeMessage, 9, WFSi_OnSendMessageDone) == 0) {
            return;
        }
        view->mMessageSendPending = TRUE;
        view->field46E8 = 0;
        return;
    }
    sendMask = view->field46CC;
    if (sendMask == 0) {
        return;
    }
    v5 = view->field46D0;
    firstEntry = NULL;
    if (v5 != 0 && v5 == (v5 & sendMask)) {
        v6 = TRUE;
    } else {
        v6 = FALSE;
    }
    if (v6 != FALSE) {
        sendMask = v5;
    } else {
        sendMask = sendMask & ~v5;
    }
    entry = view->field0;
    for (i = 0;; entry++, i++) {
        v7 = 1 << i;
        if (v7 > sendMask) {
            break;
        }
        if ((v7 & sendMask) != 0) {
            if (firstEntry == NULL) {
                firstEntry = entry;
            } else if (firstEntry->field0_0 != entry->field0_0 || firstEntry->field4 != entry->field4) {
                sendMask = sendMask & ~v7;
            }
        }
    }
    if (v6 != FALSE) {
        if (sendMask != v5) {
            view->field46D0 = 0;
        }
    }
    if (firstEntry == NULL) {
        return;
    }
    switch (firstEntry->field0_0) {
        case 0:
            firstEntry->field0_0 = 1;
            break;
        case 2:
            firstEntry->field0_0 = 3;
            view->field46DC = view->field46DC & ~sendMask;
            break;
    }
    blockId = *(volatile s32 *) &firstEntry->field4;
    replyMessage.mKind = (u8) firstEntry->field0_0;
    replyMessage.field4 = blockId;
    replyMessage.field0_8 = 1;
    replyMessage.mPacketSizeHigh = (gRomArchiveTransfer.mParentPacketSize >> 8) & 0xff;
    replyMessage.mPacketSizeLow = gRomArchiveTransfer.mParentPacketSize;
    if (RequestSendBytes(sendMask, &replyMessage, 9, WFSi_OnSendMessageDone) == 0) {
        return;
    }
    view->mMessageSendPending = TRUE;
    view->field46CC = view->field46CC & ~sendMask;
}

void WFSi_SendOpenAck(RomArchiveParentView *view, RomArchiveFileNode *node, s32 c) {
    u32 savedInterrupts;
    s32 pendingMask;
    s32 blockId;
    s32 index;
    s32 length;
    RomArchiveParentViewEntry *entry;

    savedInterrupts = OS_DisableInterrupts();
    if (gRomArchiveTransfer.mState != 0) {
        pendingMask = node->mPendingChildMask;
        node->mPendingChildMask = 0;
        view->field46CC = view->field46CC | pendingMask;
        if (node->mChildCount <= 0) {
            length = node->mFile.mProp.w.field8 - node->mFile.mProp.w.field4;
            blockId = node->mBlockId;
            WBT_RegisterBlock(&node->mBlockNode, blockId, g_SomeNullString, length <= 0x400u ? node->mBuffers[0] : 0, length,
                     0);
            WFSi_MoveList(&view->mPendingHead, &view->mActiveHead, node);
            node->mState = 2;
        }
        entry = view->field0;
        for (index = 0;; index++) {
            if ((1 << index) > pendingMask) {
                break;
            }
            if (((1 << index) & pendingMask) != 0) {
                node->mChildCount = node->mChildCount + 1;
                entry->field4 = node->mBlockId;
            }
            entry++;
        }
    }
    OS_RestoreInterrupts(savedInterrupts);
}

// Moves node c to the head of list b when it is in list a; does nothing otherwise.
void WFSi_MoveList(RomArchiveFileNode **fromHead, RomArchiveFileNode **toHead, RomArchiveFileNode *node) {
    u32 savedInterrupts;
    RomArchiveFileNode *current;
    RomArchiveFileNode *next;

    savedInterrupts = OS_DisableInterrupts();
    current = *fromHead;
    if (current == node) {
        *fromHead = node->mNext;
        node->mNext = *toHead;
        *toHead = node;
    } else if (current != NULL) {
        do {
            next = current->mNext;
            if (next == node) {
                current->mNext = node->mNext;
                node->mNext = *toHead;
                *toHead = node;
                break;
            }
            current = next;
        } while (next != NULL);
    }
    OS_RestoreInterrupts(savedInterrupts);
}

void WFSi_FromBusyToFree(RomArchiveParentView *view, RomArchiveFileNode *node) {
    WFSi_MoveList(&view->mPendingHead, &view->mFreeHead, node);
    node->mState = 0;
    view->field46E4 = view->field46E4 - 1;
}

void WFSi_ReadRequest(FSFile *file) {
    RomArchiveMessage message;
    s32 readLength;
    u32 v3;
    void *oldBuffer;
    u32 freeInterrupts;
    RomArchiveChildView *childView;
    void *newBuffer;
    u32 allocInterrupts;
    s32 requestedLength;

    readLength = file->mArg.p.field8;
    childView = (RomArchiveChildView *) &data_02176300;
    if (readLength < 0) {
        readLength = childView->mMaxReadSize;
        childView->mMaxReadSize = 0;
    }
    if (childView->mMaxReadSize < readLength) {
        childView->mMaxReadSize = readLength;
        oldBuffer = childView->mChunkBitmapBuffer;
        if (oldBuffer != NULL) {
            freeInterrupts = OS_DisableInterrupts();
            gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, 0, oldBuffer);
            OS_RestoreInterrupts(freeInterrupts);
        }
        v3 = (childView->mMaxReadSize + (gRomArchiveTransfer.mParentPacketSize - 0xe) - 1) /
             (gRomArchiveTransfer.mParentPacketSize - 0xe);
        v3 = ((v3 + 0x1f) >> 2) << 4;
        allocInterrupts = OS_DisableInterrupts();
        newBuffer = gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, v3, NULL);
        OS_RestoreInterrupts(allocInterrupts);
        childView->mChunkBitmapBuffer = newBuffer;
        childView->mChunkBitmaps[0] = childView->mChunkBitmapBuffer;
    }
    gRomArchiveTransfer.mPendingFile = file;
    requestedLength = *(volatile s32 *) &file->mArg.p.field8;
    message.field4 = childView->mPositionOffset + file->field2C;
    message.mKind = 0;
    message.field0_8 = requestedLength;
    message.mPacketSizeHigh = (gRomArchiveTransfer.mParentPacketSize >> 8) & 0xff;
    message.mPacketSizeLow = gRomArchiveTransfer.mParentPacketSize;
    if (RequestSendBytes(1, &message, 9, WFSi_OnSendMessageDone) != 0) {
        return;
    }
    OS_Terminate();
}

void WFSi_SetMPData(void) {
    RomArchiveTransfer *transfer;
    s32 isParent;
    u16 packetSize;
    u16 builtSize;
    u8 *buffer;

    transfer = &gRomArchiveTransfer;
    if (transfer->mState == 0) {
        return;
    }
    transfer->field4 = TRUE;
    WFSi_SendAck();
    transfer = &gRomArchiveTransfer;
    isParent = transfer->mIsParent;
    if (isParent != 0) {
        packetSize = transfer->mParentPacketSize;
    } else {
        packetSize = transfer->mChildPacketSize;
    }
    if (transfer->field4 == FALSE) {
        return;
    }
    buffer = transfer->mPacketBuffer;
    if (isParent != 0) {
        builtSize = WBT_MpParentSendHook(buffer, packetSize);
    } else {
        builtSize = WBT_MpChildSendHook(buffer, packetSize);
    }
    transfer->mSendPending =
        WM_SetMPDataToPortEx(WFSi_SetMPData, NULL, buffer, builtSize, 0xffff, transfer->mPort, 3) == 2;
    transfer->field4 = gRomArchiveTransfer.mSendPending == FALSE;
}

void WFSi_PortCallback(RomArchivePortMessage *message) {
    RomArchiveTransfer *transfer;
    RomArchiveParentView *view;
    s32 isParent;
    u16 packetSize;
    u16 builtSize;
    u8 *buffer;
    const u8 *data;
    u16 dataLength;
    u16 fromIndex;

    transfer = &gRomArchiveTransfer;
    view = OFFSET_PTR(RomArchiveParentView, transfer, 0x440);
    if (transfer->mState == 0) {
        return;
    }
    switch (message->field4) {
        case 7:
            isParent = transfer->mIsParent;
            if (isParent == 0) {
                return;
            }
            if (transfer->mSendPending != FALSE) {
                return;
            }
            if (isParent != 0) {
                packetSize = transfer->mParentPacketSize;
            } else {
                packetSize = transfer->mChildPacketSize;
            }
            if (transfer->field4 == FALSE) {
                return;
            }
            buffer = transfer->mPacketBuffer;
            if (isParent != 0) {
                builtSize = WBT_MpParentSendHook(buffer, packetSize);
            } else {
                builtSize = WBT_MpChildSendHook(buffer, packetSize);
            }
            transfer->mSendPending =
                WM_SetMPDataToPortEx(WFSi_SetMPData, NULL, buffer, builtSize, 0xffff, transfer->mPort, 3) == 2;
            transfer->field4 = gRomArchiveTransfer.mSendPending == FALSE;
            return;
        case 9:
            if (transfer->mIsParent == 0) {
                return;
            }
            view->field46D8 = view->field46D8 & ~(1 << message->field12);
            return;
        case 21:
            data = message->fieldC;
            dataLength = message->field10;
            if (transfer->mIsParent != 0) {
                fromIndex = message->field12;
                view->field46D8 = view->field46D8 | (1 << fromIndex);
                WBT_MpParentRecvHook(data, dataLength, fromIndex);
            } else {
                WBT_MpChildRecvHook(data, dataLength);
            }
            return;
    }
}

void WFSi_OnParentSystemCallback(Unk0204c320 *record) {
    s32 fromIndex;
    Unk0204c320_14 *payload;
    s32 v7;
    u32 fileLength;
    RomArchiveParentView *view;
    RomArchiveFileNode *queuedNode;
    u32 savedInterrupts;
    RomArchiveFileNode *activeNode;
    RomArchiveFileNode *foundNode;
    u32 v5;
    Unk0204c320_14 *q;
    s32 j;
    s32 k;
    RomArchiveFileNode *node;
    s32 v8;
    s32 v9;
    s32 v10;
    s32 v11;
    s32 v13;
    s32 v14;
    FSFile *file;
    s32 blockId;
    s32 v17;

    fromIndex = WBT_AidbitmapToAid(record->fieldA);
    if (record->field0 != 0xc) {
        return;
    }
    switch (record->field4) {
        case 2:
            break;
        case 8:
            break;
        case 10:
            view = &data_02176300;
            payload = &record->field14;
            view->field0[fromIndex] = payload->fieldE;
            switch (record->field14.mUnk_m.mKind) {
                case 0:
                    fileLength = record->field14.mUnk_m.field0_8;
                    v5 = (record->field14.mUnk_m.mPacketSizeHigh << 8) | payload->mUnk_m.mPacketSizeLow;
                    v7 = payload->mUnk_m.field4;
                    if (view->field46E0 != FALSE || v5 != gRomArchiveTransfer.mParentPacketSize) {
                        view->field46E0 = TRUE;
                        view->field46E8 = view->field46E8 | (1 << fromIndex);
                        view->field46DC = view->field46DC | (1 << fromIndex);
                        return;
                    }
                    for (foundNode = view->mActiveHead; foundNode != NULL; foundNode = foundNode->mNext) {
                        if (foundNode->mState == 2 && v7 == foundNode->mFile.mProp.w.field4) {
                            file = &foundNode->mFile;
                            if (fileLength == file->mProp.w.field8 - file->mProp.w.field4) {
                                break;
                            }
                        }
                    }
                    if (foundNode != NULL) {
                        view->field46CC = view->field46CC | (1 << fromIndex);
                        view->field0[fromIndex].field4 = foundNode->mBlockId;
                        foundNode->mChildCount = foundNode->mChildCount + 1;
                    } else {
                        for (queuedNode = view->mPendingHead; queuedNode != NULL; queuedNode = queuedNode->mNext) {
                            if (queuedNode->mState == 1 && queuedNode->mFileStart == v7 &&
                                queuedNode->mFileLength == fileLength) {
                                break;
                            }
                        }
                        if (queuedNode == NULL) {
                            queuedNode = view->mFreeHead;
                            WFSi_MoveList(&view->mFreeHead, &view->mPendingHead, queuedNode);
                            queuedNode->mState = 1;
                            view->field46E4 = view->field46E4 + 1;
                            queuedNode->mChildCount = 0;
                            queuedNode->mFileStart = v7;
                            queuedNode->mFileLength = fileLength;
                            WFSi_NotifyBusy();
                        }
                        queuedNode->mPendingChildMask = queuedNode->mPendingChildMask | (1 << fromIndex);
                    }
                    view->field46DC = view->field46DC | (1 << fromIndex);
                    return;
                case 2:
                    savedInterrupts = OS_DisableInterrupts();
                    view->field46CC = view->field46CC | (1 << fromIndex);
                    blockId = payload->mUnk_m.field4;
                    for (activeNode = view->mActiveHead; activeNode != NULL; activeNode = activeNode->mNext) {
                        if (activeNode->mState == 2 && activeNode->mBlockNode.mId == blockId) {
                            break;
                        }
                    }
                    if (activeNode != NULL) {
                        activeNode->mChildCount = activeNode->mChildCount - 1;
                        if (activeNode->mChildCount <= 0) {
                            activeNode->mPendingChildMask = 0;
                            WBT_UnregisterBlock(payload->mUnk_m.field4);
                            WFSi_MoveList(&view->mActiveHead, &view->mPendingHead, activeNode);
                            activeNode->mState = 3;
                            WFSi_NotifyBusy();
                        }
                    }
                    OS_RestoreInterrupts(savedInterrupts);
                    return;
            }
            return;
        case 13:
            q = &record->field14;
            v5 = q->mUnk_w;
            q->fieldE.field8 = 0;
            for (node = data_02179ec0.fieldB04; node != NULL; node = node->mNext) {
                if (node->mState == 2 && node->mBlockNode.mId == v5) {
                    break;
                }
            }
            if (node == NULL) {
                return;
            }
            v8 = ((Unk0204c320 *) ((u8 *) q - 0x14))->field20;
            v9 = node->field98;
            v10 = q->fieldE.field4;
            if (node->field9C != 2) {
                v17 = (node->mFile.mStat & 1) != 0 ? 1 : 0;
                if (v17 == 0) {
                    node->field9C = 2;
                }
            }
            v11 = v8 * v9;
            node->field98 = v10;
            v13 = node->field9C;
            for (v7 = 0; v7 < 2; v7++) {
                if (v7 == v13) {
                    continue;
                }
                v14 = v11 - node->mBufferOffsets[v7];
                if (v14 < 0) {
                    continue;
                }
                if (v14 + v8 > 0x400) {
                    continue;
                }
                q->fieldE.field4 = v9;
                q->fieldE.field8 = (node->mBuffers[v7] + v14);
                break;
            }
            if (node->field9C != 2) {
                return;
            }
            v11 = v8 * v10;
            for (j = 0; j < 2; j++) {
                v14 = v11 - node->mBufferOffsets[j];
                if (v14 < 0) {
                    continue;
                }
                if (v14 + v8 <= 0x400) {
                    break;
                }
            }
            if (j < 2) {
                return;
            }
            k = node->fieldA0;
            do {
                k++;
                if (k >= 2) {
                    k = 0;
                }
            } while (k == v7);
            node->fieldA0 = k;
            node->field9C = k;
            node->mBufferOffsets[k] = v11 & -0x200;
            FS_SeekFile(&node->mFile, v11 & -0x200, 0);
            FS_ReadFileAsync(&node->mFile, node->mBuffers[k], 0x400);
            break;
    }
}

void WFSi_OnChildSystemCallback(Unk0204c320 *record) {
    RomArchiveChildView *childView;
    s32 fromIndex;
    u32 previousMaxSize;
    s32 v2;
    u32 v3;
    void *buffer;
    u32 savedInterrupts;
    RomArchiveMessage message;
    FSFile *file;
    RomArchiveMessage *received;
    FSArchive *archive;
    u32 allocInterrupts;
    void *newBuffer;

    fromIndex = WBT_AidbitmapToAid(record->fieldA);
    childView = (RomArchiveChildView *) &data_02176300;
    switch (record->field0) {
        case 2:
            if (record->field8 != 0) {
                return;
            }
            gRomArchiveTransfer.mParentPacketSize = record->field14.h.field16 + 0xe;
            gRomArchiveTransfer.mChildPacketSize = record->field14.h.field18 + 0xe;
            if (gRomArchiveTransfer.mArchiveBlock == NULL) {
                RequestBlockNode(1, 0, childView, (void (*)(BlockTransferRecord *)) WFSi_OnChildSystemCallback);
                return;
            }
            if (gRomArchiveTransfer.mPendingFile == NULL) {
                return;
            }
            previousMaxSize = childView->mMaxReadSize;
            childView->mMaxReadSize = 0;
            if (childView->mMaxReadSize < previousMaxSize) {
                childView->mMaxReadSize = previousMaxSize;
                buffer = childView->mChunkBitmapBuffer;
                if (buffer != NULL) {
                    savedInterrupts = OS_DisableInterrupts();
                    gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, 0, buffer);
                    OS_RestoreInterrupts(savedInterrupts);
                }
                v3 = (childView->mMaxReadSize + (gRomArchiveTransfer.mParentPacketSize - 0xe) - 1) /
                     (gRomArchiveTransfer.mParentPacketSize - 0xe);
                v3 = ((v3 + 0x1f) >> 2) << 4;
                allocInterrupts = OS_DisableInterrupts();
                newBuffer = gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, v3, NULL);
                OS_RestoreInterrupts(allocInterrupts);
                childView->mChunkBitmapBuffer = newBuffer;
                childView->mChunkBitmaps[0] = childView->mChunkBitmapBuffer;
            }
            WFSi_ReadRequest(gRomArchiveTransfer.mPendingFile);
            return;
        case 6:
            v2 = childView->mNodeBuffers[fromIndex]->field4;
            gRomArchiveTransfer.mArchiveBlockSize = v2;
            savedInterrupts = OS_DisableInterrupts();
            buffer = gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, v2, NULL);
            OS_RestoreInterrupts(savedInterrupts);
            gRomArchiveTransfer.mArchiveBlock = buffer;
            v2 = gRomArchiveTransfer.mArchiveBlockSize;
            if (v2 < 0) {
                v2 = childView->mMaxReadSize;
                childView->mMaxReadSize = 0;
            }
            if (childView->mMaxReadSize < v2) {
                childView->mMaxReadSize = v2;
                buffer = childView->mChunkBitmapBuffer;
                if (buffer != NULL) {
                    savedInterrupts = OS_DisableInterrupts();
                    gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, 0, buffer);
                    OS_RestoreInterrupts(savedInterrupts);
                }
                v3 = (childView->mMaxReadSize + (gRomArchiveTransfer.mParentPacketSize - 0xe) - 1) /
                     (gRomArchiveTransfer.mParentPacketSize - 0xe);
                v3 = ((v3 + 0x1f) >> 2) << 4;
                allocInterrupts = OS_DisableInterrupts();
                newBuffer = gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, v3, NULL);
                OS_RestoreInterrupts(allocInterrupts);
                childView->mChunkBitmapBuffer = newBuffer;
                childView->mChunkBitmaps[0] = childView->mChunkBitmapBuffer;
            }
            childView->mBlockBuffers[fromIndex] = (u32) gRomArchiveTransfer.mArchiveBlock;
            RequestBlockData(1, 0x20000, childView->mBlockBuffers, gRomArchiveTransfer.mArchiveBlockSize,
                             childView->mChunkBitmaps, (void (*)(BlockTransferRecord *)) WFSi_OnChildSystemCallback);
            return;
        case 4:
            if (record->field8 != 0) {
                return;
            }
            if (gRomArchiveTransfer.mState != 2) {
                DC_FlushRange(gRomArchiveTransfer.mArchiveBlock, gRomArchiveTransfer.mArchiveBlockSize);
                childView->mPositionOffset = WFSi_ReplaceRomArchive(gRomArchiveTransfer.mArchiveBlock);
                gRomArchiveTransfer.mState = 2;
                if (gRomArchiveTransfer.mStateCallback == NULL) {
                    return;
                }
                gRomArchiveTransfer.mStateCallback(0);
                return;
            }
            message.field4 = childView->mFileBlockId;
            message.mKind = 2;
            message.field0_8 = 1;
            message.mPacketSizeHigh = (gRomArchiveTransfer.mParentPacketSize >> 8) & 0xff;
            message.mPacketSizeLow = gRomArchiveTransfer.mParentPacketSize;
            if (RequestSendBytes(1, &message, 9, WFSi_OnSendMessageDone) != 0) {
                return;
            }
            OS_Terminate();
            return;
        case 12:
            if (record->field4 != 0xa) {
                return;
            }
            received = &record->field14.mUnk_m;
            switch (received->mKind) {
                case 1:
                    if (received->field0_8 == 0) {
                        RequestBlockCount(1, (void (*)(BlockTransferRecord *)) WFSi_OnChildSystemCallback);
                        return;
                    }
                    childView->mFileBlockId = received->field4;
                    childView->mBlockBuffers[fromIndex] = gRomArchiveTransfer.mPendingFile->mArg.w.field0;
                    RequestBlockData(1, childView->mFileBlockId, childView->mBlockBuffers,
                                     gRomArchiveTransfer.mPendingFile->mArg.w.field8, childView->mChunkBitmaps,
                                     (void (*)(BlockTransferRecord *)) WFSi_OnChildSystemCallback);
                    return;
                case 3:
                    file = gRomArchiveTransfer.mPendingFile;
                    archive = file->mArc;
                    gRomArchiveTransfer.mPendingFile = NULL;
                    file->field2C = file->field2C + file->mArg.w.field8;
                    FS_NotifyArchiveAsyncEnd(archive, 0);
                    return;
            }
            return;
    }
}

void WFSi_InitCommon(u32 port, void (*stateCallback)(s32 port),
                    void *(*allocFunc)(s32 port, u32 stateCallback, void *allocFunc), u32 allocFuncArg) {
    RomArchiveTransfer *const transfer = &gRomArchiveTransfer;
    u16 narrowedPort;

    FS_Init(-1);
    narrowedPort = port;
    transfer->mPort = narrowedPort;
    transfer->field4 = FALSE;
    transfer->mSendPending = FALSE;
    transfer->mState = 0;
    transfer->mStateCallback = stateCallback;
    transfer->mAllocFunc = allocFunc;
    transfer->mAllocFuncArg = allocFuncArg;
    transfer->mPendingFile = NULL;
    transfer->mArchiveBlockSize = 0;
    transfer->mArchiveBlock = NULL;
    transfer->mParentPacketSize = 0;
    transfer->mChildPacketSize = 0xe;
    data_02175ea0 = 0;
    if (WM_SetIndCallback(narrowedPort, WFSi_PortCallback, NULL) != 0) {
        OS_Terminate();
    }
}

void WFS_InitParent(u32 port, void (*stateCallback)(s32 port),
                           void *(*allocFunc)(s32 port, u32 stateCallback, void *allocFunc), u32 allocFuncArg,
                           u32 parentPacketSize, FSFile *file, s32 appendOverlays) {
    u32 savedInterrupts;
    RomArchiveTransfer *transfer;
    RomArchiveParentView *view;
    RomArchiveFileNode *node;
    RomArchiveFileNode *archiveNode;

    savedInterrupts = OS_DisableInterrupts();
    if (gRomArchiveStarted != 0) {
        return;
    }
    gRomArchiveStarted = 1;
    WFSi_InitCommon(port, stateCallback, allocFunc, allocFuncArg);
    OS_RestoreInterrupts(savedInterrupts);
    transfer = &gRomArchiveTransfer;
    transfer->mIsParent = 1;
    view = OFFSET_PTR(RomArchiveParentView, transfer, 0x440);
    DC_FlushRange(view, 0x46f0);
    DC_WaitWriteBufferEmpty();
    node = OFFSET_PTR(RomArchiveFileNode, view, 0xc0);
    view->mFreeHead = node;
    if (node + 1 < (RomArchiveFileNode *) &view->mFreeHead) {
        do {
            node->mNext = node + 1;
            FS_InitFile(&node->mFile);
            node->mChildCount = 0;
            node->mState = 0;
            node->mBlockId = (node + 0x10001) - OFFSET_PTR(RomArchiveFileNode, view, 0xc0);
            node++;
        } while (node + 1 < (RomArchiveFileNode *) &view->mFreeHead);
    }
    node->mNext = NULL;
    view->field46D0 = 0;
    view->field46CC = 0;
    view->mMessageSendPending = FALSE;
    view->mActiveHead = NULL;
    view->mPendingHead = NULL;
    transfer->mParentPacketSize = parentPacketSize;
    view->field46D8 = 1;
    view->field46DC = 0;
    view->field46E0 = FALSE;
    view->field46E8 = 0;
    view->field46E4 = 0;
    view->field46EC = transfer->mParentPacketSize;
    DC_FlushRange(view, 0x46f0);
    DC_WaitWriteBufferEmpty();
    StartParentBlockTransfer(transfer->mParentPacketSize, transfer->mChildPacketSize,
                             (void (*)(BlockTransferRecord *)) WFSi_OnParentSystemCallback);
    WFSi_LoadTables(file, appendOverlays);
    archiveNode = view->mFreeHead;
    view->mFreeHead = archiveNode->mNext;
    archiveNode->mNext = view->mActiveHead;
    view->mActiveHead = archiveNode;
    archiveNode->mChildCount = 1;
    MI_CpuFill8(archiveNode, 0, 0x8c0);
    WBT_RegisterBlock(&archiveNode->mBlockNode, 0x20000, g_SomeNullString, transfer->mArchiveBlock,
             gRomArchiveTransfer.mArchiveBlockSize, 0);
    transfer->mState = 1;
    WFSi_CreateTaskThread();
}

void WFS_InitChild(u32 port, void (*stateCallback)(s32 port),
                          void *(*allocFunc)(s32 port, u32 stateCallback, void *allocFunc), u32 allocFuncArg) {
    u32 savedInterrupts;
    RomArchiveTransfer *transfer;
    RomArchiveChildView *view;
    s32 i;

    savedInterrupts = OS_DisableInterrupts();
    if (gRomArchiveStarted != 0) {
        return;
    }
    gRomArchiveStarted = 1;
    WFSi_InitCommon(port, stateCallback, allocFunc, allocFuncArg);
    OS_RestoreInterrupts(savedInterrupts);
    transfer = &gRomArchiveTransfer;
    transfer->mIsParent = 0;
    view = OFFSET_PTR(RomArchiveChildView, transfer, 0x440);
    DC_FlushRange(view, 0xb0c);
    DC_WaitWriteBufferEmpty();
    for (i = 0; i < 16; i++) {
        view->mNodeBuffers[i] = &view->fieldC0[i];
        view->mBlockBuffers[i] = 0;
        view->mChunkBitmaps[i] = NULL;
    }
    view->mChunkBitmapBuffer = NULL;
    view->mMaxReadSize = 0;
    view->mFileBlockId = 0;
    DC_FlushRange(view, 0xb0c);
    DC_WaitWriteBufferEmpty();
    WBT_InitChild((void (*)(BlockTransferRecord *)) WFSi_OnChildSystemCallback);
    transfer->mState = 1;
}

void WFS_Init(int isParent, u32 port, u32 parentPacketSize, void (*stateCallback)(s32 isParent),
                     void *(*allocFunc)(s32 isParent, u32 port, void *parentPacketSize), u32 allocFuncArg) {
    if (isParent != 0) {
        WFS_InitParent(port, stateCallback, allocFunc, allocFuncArg, parentPacketSize, NULL, 1);
        return;
    }
    WFS_InitChild(port, stateCallback, allocFunc, allocFuncArg);
}

static inline void func_0204bcec_inline(RomArchiveTransfer *a, void *p) {
    u32 t;
    if (p != NULL) {
        t = OS_DisableInterrupts();
        a->mAllocFunc(a->mAllocFuncArg, 0, p);
        OS_RestoreInterrupts(t);
    }
}

void WFS_Start(void) {
    Unk021762e0 *childView;
    RomArchiveTransfer *transfer;
    u8 *buffer;
    u16 packetSize;
    u16 builtSize;
    s32 isParent;
    gRomArchiveTransfer.field4 = TRUE;
    if (gRomArchiveTransfer.mIsParent == 0) {
        childView = (Unk021762e0 *) &data_02176300;
        WM_ReadStatus(childView->field340);
        SetOwnIndex(childView->field4C4);
        RequestBlockCount(1, (void (*)(BlockTransferRecord *)) WFSi_OnChildSystemCallback);
    } else {
        gRomArchiveTransfer.mState = 2;
        if (gRomArchiveTransfer.mStateCallback != NULL) {
            gRomArchiveTransfer.mStateCallback(0);
        }
    }
    transfer = &gRomArchiveTransfer;
    isParent = transfer->mIsParent;
    if (isParent != 0) {
        packetSize = transfer->mParentPacketSize;
    } else {
        packetSize = transfer->mChildPacketSize;
    }
    if (transfer->field4 == FALSE) {
        return;
    }
    buffer = transfer->mPacketBuffer;
    if (isParent != 0) {
        builtSize = WBT_MpParentSendHook(buffer, packetSize);
    } else {
        builtSize = WBT_MpChildSendHook(buffer, packetSize);
    }
    transfer->mSendPending =
        WM_SetMPDataToPortEx(WFSi_SetMPData, NULL, buffer, builtSize, 0xffff, transfer->mPort, 3) == 2;
    transfer->field4 = gRomArchiveTransfer.mSendPending == FALSE;
}

void WFS_End(void) {
    RomArchiveTransfer *transfer;
    RomArchiveParentView *view;
    u32 savedInterrupts;
    void *block;
    FSArchive *archive;
    transfer = &gRomArchiveTransfer;
    savedInterrupts = OS_DisableInterrupts();
    if (gRomArchiveStarted != 0) {
        block = transfer->mArchiveBlock;
        if (block != NULL) {
            func_0204bcec_inline(&gRomArchiveTransfer, block);
            transfer->mArchiveBlock = NULL;
            transfer->mArchiveBlockSize = 0;
        }
        transfer->mState = 0;
        if (gRomArchiveTransfer.mIsParent == 0) {
            view = &transfer->field440;
            if (transfer->mPendingFile != NULL) {
                archive = transfer->mPendingFile->mArc;
                transfer->mPendingFile = NULL;
                FS_NotifyArchiveAsyncEnd(archive, 5);
            }
            func_0204bcec_inline(&gRomArchiveTransfer, view->fieldAFC);
        } else {
            WFSi_EndTaskThread();
        }
        StopBlockTransfer();
        WM_SetIndCallback(gRomArchiveTransfer.mPort, NULL, NULL);
        gRomArchiveStarted = 0;
    }
    OS_RestoreInterrupts(savedInterrupts);
}

u32 WFS_GetStatus(void) {
    u32 state;
    state = gRomArchiveTransfer.mState;
    return state;
}

u32 WFS_EnableSync(u32 value) {
    u32 value0 = value;
    Unk02179ec0 *value1;
    u32 valueWithoutBit0;
    u32 savedValue;
    savedValue = value0;
    value0 = OS_DisableInterrupts();
    value1 = &data_02179ec0;
    valueWithoutBit0 = (savedValue) & ~(1u);
    data_02179ec0.fieldB10 = valueWithoutBit0;
    value0 = OS_RestoreInterrupts(value0);
    return value0;
}

void WFSi_NotifyBusy(void) {
    u32 threadAddress;
    u32 value12;
    threadAddress = (u32) &data_02175dd8;
    OS_WakeupThreadDirect((OSThread *) threadAddress);
}
