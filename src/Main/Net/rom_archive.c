#include "Main/Net/rom_archive.h"
#include "03/Net/essid_packet_steps.h"
#include "thread_scheduler.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "file_command_handlers.h"
#include "Main/Save/backup_read_copies.h"
#include "Main/Net/append_bytes.h"
#include "Main/Net/wbt_requests.h"
#include "file_open_read.h"
#include "wireless_power_mp.h"
#include "reset_interrupt_enable.h"
#include "Main/Net/wbt_mp_parent_recv.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "file_handle_setup.h"
#include "overlay_loader.h"
#include "arena_cache_init.h"
#include "cpu_copy_fill.h"
#include "Main/Net/multiboot_parent.h"
#include "Main/Net/packet_port.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Kart/kart_name_tags.h"
#include "rom_card_read.h"

s32 gRomArchiveUnusedWord;
s32 gRomArchiveStarted;
u8 gRomArchiveUnusedPad[0x18];
RomArchiveTransfer gRomArchiveTransfer;

const u8 gEmptyBlockInfo[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

s32 RomArchiveWriteCallback(FSArchive *archive, const void *src, u32 dst, u32 length) {
    return 1;
}

s32 RomArchiveChildProc(FSFile *file, u32 command) {
    switch (command) {
        case 0:
            if (gRomArchiveTransfer.mState != ROM_ARCHIVE_READY) {
                return 5;
            }
            if (file->mArg.p.mUnk_08 == 0) {
                return 0;
            }
            RequestRomArchiveBytes(file);
            return 6;
        case 1:
            return 4;
        default:
            return 8;
    }
}

void CreateRomArchiveBlock(FSFile *file, s32 appendOverlays) {
    RomHeaderStart fileHeader;
    FSFile romFile;
    CARDRomRegion tables[4];
    u32 paddedSizes[4];
    u32 *tablePointers[4];
    u32 *block;
    u32 blockSize;
    enum { APPEND_OVERLAY_ENTRIES_NO } appendOverlayEntries;
    u32 imageOffset;
    u32 positionOffset;
    RomHeaderStart *header;
    u32 origin;
    u32 pairSize;
    u32 alignedSize;
    BOOL noFile;
    s32 value;
    BOOL unusedValue;

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
    FS_OpenFileDirect(&romFile, FS_FindArchive((const u8 *) "rom", 3), 0, 0x7fffffff, -1);
    if (noFile != FALSE) {
        imageOffset = 0;
        positionOffset = 0;
        header = &SYSTEM_WORK->mRomHeader.mHead;
    } else {
        value = file->mPosition - file->mProp.w.mUnk_04;
        imageOffset = value + file->mProp.w.mUnk_04;
        header = &fileHeader;
        positionOffset = imageOffset;
        FS_ReadFile(file, header, 0x60);
        FS_SeekFile(file, value, FILE_SEEK_START);
    }
    if (appendOverlayEntries == 0) {
        tables[0] = header->mFatTable;
        tables[1] = header->mFntTable;
        tables[2] = header->mOverlayTable0;
        tables[3] = header->mOverlayTable1;
    } else {
        tables[0] = SYSTEM_WORK->mRomHeader.mHead.mFatTable;
        tables[1] = SYSTEM_WORK->mRomHeader.mHead.mFntTable;
        positionOffset = 0;
        tables[2].mOffset = (u8 *) (header->mOverlayTable0Offset + imageOffset);
        tables[2].mLength = header->mOverlayTable0Size;
        tables[3].mOffset = (u8 *) (header->mOverlayTable1Offset + imageOffset);
        tables[3].mLength = header->mOverlayTable1Size;
    }
    blockSize = blockSize + 4;
    for (value = 0; value < 4; value++) {
        paddedSizes[value] = (tables[value].mLength + 0x1f) & ~0x1f;
        blockSize = blockSize + (paddedSizes[value] + 4);
    }
    if (appendOverlayEntries != 0) {
        for (value = 2; value < 4; value++) {
            alignedSize = (((tables[value].mLength >> 5) << 3) + 0x1f) & ~0x1f;
            paddedSizes[0] = paddedSizes[0] + alignedSize;
            blockSize = blockSize + alignedSize;
        }
    }
    alignedSize = OS_DisableInterrupts();
    block = gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, blockSize, NULL);
    OS_RestoreInterrupts(alignedSize);
    *block = positionOffset;
    origin = 0;
    unusedValue = FALSE;
    {
        u32 *cursor = block + 1;
        u32 *tableData;
        s32 tableIndex;
        for (tableIndex = 0; tableIndex < 4; tableIndex++) {
            tablePointers[tableIndex] = cursor;
            tableData = tablePointers[tableIndex];
            *tableData = tables[tableIndex].mLength;
            FS_SeekFile(&romFile, positionOffset + (u32) tables[tableIndex].mOffset, origin);
            FS_ReadFile(&romFile, tableData + 1, *tableData);
            cursor = OFFSET_PTR(u32, cursor, (paddedSizes[tableIndex] + 4));
        }
    }
    if (appendOverlayEntries != 0) {
        u32 *fatBlock = tablePointers[0];
        u8 *fatEntries = (u8 *) (fatBlock + 1);
        s32 entryCount = *fatBlock >> 3;
        OverlayTableEntry *overlayEntries;
        s32 overlayIndex;
        u32 *appendCursor = (u32 *) (fatEntries + (entryCount << 3));
        u32 fatPosition = imageOffset + header->mFatOffset;
        pairSize = 8;
        for (value = 2; value < 4; value++) {
            u32 *overlayTable = tablePointers[value];
            s32 overlayCount;
            overlayEntries = (OverlayTableEntry *) (overlayTable + 1);
            overlayCount = *overlayTable >> 5;
            for (overlayIndex = 0; overlayIndex < overlayCount; overlayIndex++) {
                FS_SeekFile(&romFile, fatPosition + (overlayEntries[overlayIndex].mFileId << 3), origin);
                FS_ReadFile(&romFile, appendCursor, pairSize);
                *(u32 *) (fatEntries + ((u32) entryCount * 8)) =
                    *(u32 *) (fatEntries + ((u32) entryCount * 8)) + imageOffset;
                ((u32 *) (fatEntries + ((u32) entryCount * 8)))[1] =
                    ((u32 *) (fatEntries + ((u32) entryCount * 8)))[1] + imageOffset;
                overlayEntries[overlayIndex].mFileId = entryCount;
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

u32 ReloadRomArchiveFromBlock(u32 *block) {
    CARDRomRegion tables[4];
    u32 positionOffset;
    FSArchive *archive;
    s32 tableIndex;

    archive = FS_FindArchive((const u8 *) "rom", 3);
    FS_UnloadArchive(archive);
    FS_SetArchiveProc(archive, RomArchiveChildProc, -1);
    positionOffset = *block++;
    for (tableIndex = 0; tableIndex < 4; tableIndex++) {
        tables[tableIndex].mOffset = (u8 *) (block + 1);
        tables[tableIndex].mLength = *block;
        block = (u32 *) (tables[tableIndex].mOffset + ((tables[tableIndex].mLength + 0x1f) & ~0x1f));
    }
    FS_LoadArchive(archive, NULL, (u32) tables[0].mOffset, tables[0].mLength, (u32) tables[1].mOffset,
                   tables[1].mLength, RomArchiveReadCallback, RomArchiveWriteCallback);
    FS_AttachOverlayTable(0, tables[2].mOffset, tables[2].mLength);
    FS_AttachOverlayTable(1, tables[3].mOffset, tables[3].mLength);
    return positionOffset;
}

void RomArchiveSendCallback(WBTCommand *record) {
    RomArchiveTransfer *transfer = &gRomArchiveTransfer;

    if (transfer->mState == ROM_ARCHIVE_STOPPED) {
        return;
    }
    if (transfer->mIsParent == 0) {
        return;
    }
    transfer->mParentView.mMessageSendPending = FALSE;
    SendRomArchiveMessage();
}

void SendRomArchiveMessage(void) {
    RomArchiveMessage sizeMessage;
    RomArchiveMessage replyMessage;
    BOOL isGroupSend;
    RomArchiveParentViewEntry *firstEntry;
    s32 sendMask;
    s32 bitIndex;
    s32 groupMask;
    s32 bit;
    RomArchiveParentViewEntry *entry;
    u32 childPacketSize;
    s32 value;
    RomArchiveTransfer *transfer = &gRomArchiveTransfer;
    RomArchiveParentView *view = OFFSET_PTR(RomArchiveParentView, transfer, 0x440);
    s32 blockId;

    if (transfer->mIsParent == 0) {
        return;
    }
    if (view->mMessageSendPending != FALSE) {
        return;
    }
    view->mReplySendMask = view->mReplySendMask & view->mActiveMask;
    view->mGroupSendMask = view->mGroupSendMask & view->mActiveMask;
    view->mRequestMask = view->mRequestMask & view->mActiveMask;
    view->mPacketSizeMessageMask = view->mPacketSizeMessageMask & view->mActiveMask;
    if (view->mPacketSizeChangePending != FALSE && view->mQueuedNodeCount == 0) {
        value = view->mNewParentPacketSize;
        childPacketSize = gRomArchiveTransfer.mChildPacketSize;
        view->mPacketSizeChangePending = FALSE;
        gRomArchiveTransfer.mParentPacketSize = value;
        WBT_SetPacketSize(value, childPacketSize);
        value = view->mPacketSizeMessageMask;
        if (value == 0) {
            return;
        }
        sizeMessage.mKind = ROM_ARCHIVE_MESSAGE_REPLY;
        sizeMessage.mValue24 = 0;
        sizeMessage.mWord04 = 0;
        sizeMessage.mPacketSizeHigh = (gRomArchiveTransfer.mParentPacketSize >> 8) & 0xff;
        sizeMessage.mPacketSizeLow = gRomArchiveTransfer.mParentPacketSize;
        if (WBT_PutUserData(value, &sizeMessage, 9, RomArchiveSendCallback) == 0) {
            return;
        }
        view->mMessageSendPending = TRUE;
        view->mPacketSizeMessageMask = 0;
        return;
    }
    sendMask = view->mReplySendMask;
    if (sendMask == 0) {
        return;
    }
    groupMask = view->mGroupSendMask;
    firstEntry = NULL;
    if (groupMask != 0 && groupMask == (groupMask & sendMask)) {
        isGroupSend = TRUE;
    } else {
        isGroupSend = FALSE;
    }
    if (isGroupSend != FALSE) {
        sendMask = groupMask;
    } else {
        sendMask = sendMask & ~groupMask;
    }
    entry = view->mEntries;
    for (bitIndex = 0;; entry++, bitIndex++) {
        bit = 1 << bitIndex;
        if (bit > sendMask) {
            break;
        }
        if ((bit & sendMask) != 0) {
            if (firstEntry == NULL) {
                firstEntry = entry;
            } else if (firstEntry->mKind != entry->mKind || firstEntry->mBlockId != entry->mBlockId) {
                sendMask = sendMask & ~bit;
            }
        }
    }
    if (isGroupSend != FALSE) {
        if (sendMask != groupMask) {
            view->mGroupSendMask = 0;
        }
    }
    if (firstEntry == NULL) {
        return;
    }
    switch (firstEntry->mKind) {
        case ROM_ARCHIVE_MESSAGE_REQUEST:
            firstEntry->mKind = ROM_ARCHIVE_MESSAGE_REPLY;
            break;
        case ROM_ARCHIVE_MESSAGE_RELEASE:
            firstEntry->mKind = ROM_ARCHIVE_MESSAGE_RELEASE_REPLY;
            view->mRequestMask = view->mRequestMask & ~sendMask;
            break;
    }
    blockId = firstEntry->mBlockId;
    replyMessage.mKind = (u8) firstEntry->mKind;
    replyMessage.mWord04 = blockId;
    replyMessage.mValue24 = 1;
    replyMessage.mPacketSizeHigh = (gRomArchiveTransfer.mParentPacketSize >> 8) & 0xff;
    replyMessage.mPacketSizeLow = gRomArchiveTransfer.mParentPacketSize;
    if (WBT_PutUserData(sendMask, &replyMessage, 9, RomArchiveSendCallback) == 0) {
        return;
    }
    view->mMessageSendPending = TRUE;
    view->mReplySendMask = view->mReplySendMask & ~sendMask;
}

void ActivateRomArchiveNode(RomArchiveParentView *view, RomArchiveFileNode *node, s32 unused) {
    u32 savedInterrupts;
    s32 pendingMask;
    s32 blockId;
    s32 index;
    s32 length;
    RomArchiveParentViewEntry *entry;

    savedInterrupts = OS_DisableInterrupts();
    if (gRomArchiveTransfer.mState != ROM_ARCHIVE_STOPPED) {
        pendingMask = node->mPendingChildMask;
        node->mPendingChildMask = 0;
        view->mReplySendMask = view->mReplySendMask | pendingMask;
        if (node->mChildCount <= 0) {
            length = node->mFile.mProp.w.mUnk_08 - node->mFile.mProp.w.mUnk_04;
            blockId = node->mBlockId;
            WBT_RegisterBlock(&node->mBlockNode, blockId, gEmptyBlockInfo, length <= 0x400u ? node->mBuffers[0] : 0,
                              length, 0);
            MoveRomArchiveNodeToList(&view->mPendingHead, &view->mActiveHead, node);
            node->mState = ROM_ARCHIVE_NODE_ACTIVE;
        }
        entry = view->mEntries;
        for (index = 0;; index++) {
            if ((1 << index) > pendingMask) {
                break;
            }
            if (((1 << index) & pendingMask) != 0) {
                node->mChildCount = node->mChildCount + 1;
                entry->mBlockId = node->mBlockId;
            }
            entry++;
        }
    }
    OS_RestoreInterrupts(savedInterrupts);
}

// Moves the node to the head of the target list when it is in the source list; does nothing otherwise.
void MoveRomArchiveNodeToList(RomArchiveFileNode **fromHead, RomArchiveFileNode **toHead, RomArchiveFileNode *node) {
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

void FreeRomArchiveNode(RomArchiveParentView *view, RomArchiveFileNode *node) {
    MoveRomArchiveNodeToList(&view->mPendingHead, &view->mFreeHead, node);
    node->mState = ROM_ARCHIVE_NODE_FREE;
    view->mQueuedNodeCount = view->mQueuedNodeCount - 1;
}

void RequestRomArchiveBytes(FSFile *file) {
    RomArchiveMessage message;
    s32 readLength;
    u32 bufferSize;
    void *oldBuffer;
    u32 freeInterrupts;
    RomArchiveChildView *childView;
    void *newBuffer;
    u32 allocInterrupts;
    s32 requestedLength;

    readLength = file->mArg.p.mUnk_08;
    childView = (RomArchiveChildView *) &gRomArchiveTransfer.mParentView;
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
        bufferSize = (childView->mMaxReadSize + (gRomArchiveTransfer.mParentPacketSize - 0xe) - 1) /
                     (gRomArchiveTransfer.mParentPacketSize - 0xe);
        bufferSize = ((bufferSize + 0x1f) >> 2) << 4;
        allocInterrupts = OS_DisableInterrupts();
        newBuffer = gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, bufferSize, NULL);
        OS_RestoreInterrupts(allocInterrupts);
        childView->mChunkBitmapBuffer = newBuffer;
        childView->mChunkBitmaps[0] = childView->mChunkBitmapBuffer;
    }
    gRomArchiveTransfer.mPendingFile = file;
    requestedLength = file->mArg.p.mUnk_08;
    message.mWord04 = childView->mPositionOffset + file->mPosition;
    message.mKind = ROM_ARCHIVE_MESSAGE_REQUEST;
    message.mValue24 = requestedLength;
    message.mPacketSizeHigh = (gRomArchiveTransfer.mParentPacketSize >> 8) & 0xff;
    message.mPacketSizeLow = gRomArchiveTransfer.mParentPacketSize;
    if (WBT_PutUserData(1, &message, 9, RomArchiveSendCallback) != 0) {
        return;
    }
    OS_Terminate();
}

void SendRomArchivePacket(void) {
    RomArchiveTransfer *transfer;
    s32 isParent;
    u16 packetSize;
    u16 builtSize;
    u8 *buffer;

    transfer = &gRomArchiveTransfer;
    if (transfer->mState == ROM_ARCHIVE_STOPPED) {
        return;
    }
    transfer->mSendAllowed = TRUE;
    SendRomArchiveMessage();
    transfer = &gRomArchiveTransfer;
    isParent = transfer->mIsParent;
    if (isParent != 0) {
        packetSize = transfer->mParentPacketSize;
    } else {
        packetSize = transfer->mChildPacketSize;
    }
    if (transfer->mSendAllowed == FALSE) {
        return;
    }
    buffer = transfer->mPacketBuffer;
    if (isParent != 0) {
        builtSize = WBT_MpParentSendHook(buffer, packetSize);
    } else {
        builtSize = WBT_MpChildSendHook(buffer, packetSize);
    }
    transfer->mSendPending =
        WM_SetMPDataToPortEx(SendRomArchivePacket, NULL, buffer, builtSize, 0xffff, transfer->mPort, 3) == 2;
    transfer->mSendAllowed = gRomArchiveTransfer.mSendPending == FALSE;
}

void RomArchivePortCallback(void *portMessage) {
    RomArchivePortMessage *message = portMessage;
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
    if (transfer->mState == ROM_ARCHIVE_STOPPED) {
        return;
    }
    switch (message->mKind) {
        case WIRELESS_STATE_LINKED:
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
            if (transfer->mSendAllowed == FALSE) {
                return;
            }
            buffer = transfer->mPacketBuffer;
            if (isParent != 0) {
                builtSize = WBT_MpParentSendHook(buffer, packetSize);
            } else {
                builtSize = WBT_MpChildSendHook(buffer, packetSize);
            }
            transfer->mSendPending =
                WM_SetMPDataToPortEx(SendRomArchivePacket, NULL, buffer, builtSize, 0xffff, transfer->mPort, 3) == 2;
            transfer->mSendAllowed = gRomArchiveTransfer.mSendPending == FALSE;
            return;
        case WIRELESS_STATE_UNLINKED:
            if (transfer->mIsParent == 0) {
                return;
            }
            view->mActiveMask = view->mActiveMask & ~(1 << message->mFromIndex);
            return;
        case WIRELESS_STATE_PORT_DATA_ARRIVED:
            data = message->mData;
            dataLength = message->mDataLength;
            if (transfer->mIsParent != 0) {
                fromIndex = message->mFromIndex;
                view->mActiveMask = view->mActiveMask | (1 << fromIndex);
                WBT_MpParentRecvHook(data, dataLength, fromIndex);
            } else {
                WBT_MpChildRecvHook(data, dataLength);
            }
            return;
    }
}

void RomArchiveParentCallback(WBTCommand *record) {
    s32 fromIndex;
    WBTCommandData *payload;
    s32 value;
    u32 fileLength;
    RomArchiveParentView *view;
    RomArchiveFileNode *queuedNode;
    u32 savedInterrupts;
    RomArchiveFileNode *activeNode;
    RomArchiveFileNode *foundNode;
    u32 identifier;
    WBTCommandData *commandData;
    s32 bufferIndex;
    s32 newBufferIndex;
    RomArchiveFileNode *node;
    s32 ownPacketSize;
    s32 oldValue;
    s32 requestedBlockId;
    s32 byteOffset;
    s32 activeBufferIndex;
    s32 bufferDelta;
    FSFile *file;
    s32 blockId;
    s32 statFlag;

    fromIndex = WBT_AidbitmapToAid(record->mPeerBmp);
    if (record->mCommand != XFER_COMMAND_HOOK_RECORD) {
        return;
    }
    switch (record->mEvent) {
        case XFER_EVENT_HANDSHAKE_ASKED:
            break;
        case XFER_EVENT_ALL_CHUNKS_HELD:
            break;
        case XFER_EVENT_CUSTOM_ARRIVED:
            view = &gRomArchiveTransfer.mParentView;
            payload = &record->mData;
            view->mEntries[fromIndex] = payload->mArchiveParentViewEntry;
            switch (record->mData.mArchiveMessage.mKind) {
                case ROM_ARCHIVE_MESSAGE_REQUEST:
                    fileLength = record->mData.mArchiveMessage.mValue24;
                    identifier =
                        (record->mData.mArchiveMessage.mPacketSizeHigh << 8) | payload->mArchiveMessage.mPacketSizeLow;
                    value = payload->mArchiveMessage.mWord04;
                    if (view->mPacketSizeChangePending != FALSE ||
                        identifier != gRomArchiveTransfer.mParentPacketSize) {
                        view->mPacketSizeChangePending = TRUE;
                        view->mPacketSizeMessageMask = view->mPacketSizeMessageMask | (1 << fromIndex);
                        view->mRequestMask = view->mRequestMask | (1 << fromIndex);
                        return;
                    }
                    for (foundNode = view->mActiveHead; foundNode != NULL; foundNode = foundNode->mNext) {
                        if (foundNode->mState == ROM_ARCHIVE_NODE_ACTIVE && value == foundNode->mFile.mProp.w.mUnk_04) {
                            file = &foundNode->mFile;
                            if (fileLength == file->mProp.w.mUnk_08 - file->mProp.w.mUnk_04) {
                                break;
                            }
                        }
                    }
                    if (foundNode != NULL) {
                        view->mReplySendMask = view->mReplySendMask | (1 << fromIndex);
                        view->mEntries[fromIndex].mBlockId = foundNode->mBlockId;
                        foundNode->mChildCount = foundNode->mChildCount + 1;
                    } else {
                        for (queuedNode = view->mPendingHead; queuedNode != NULL; queuedNode = queuedNode->mNext) {
                            if (queuedNode->mState == ROM_ARCHIVE_NODE_QUEUED && queuedNode->mFileStart == value &&
                                queuedNode->mFileLength == fileLength) {
                                break;
                            }
                        }
                        if (queuedNode == NULL) {
                            queuedNode = view->mFreeHead;
                            MoveRomArchiveNodeToList(&view->mFreeHead, &view->mPendingHead, queuedNode);
                            queuedNode->mState = ROM_ARCHIVE_NODE_QUEUED;
                            view->mQueuedNodeCount = view->mQueuedNodeCount + 1;
                            queuedNode->mChildCount = 0;
                            queuedNode->mFileStart = value;
                            queuedNode->mFileLength = fileLength;
                            WakeRomArchiveThread();
                        }
                        queuedNode->mPendingChildMask = queuedNode->mPendingChildMask | (1 << fromIndex);
                    }
                    view->mRequestMask = view->mRequestMask | (1 << fromIndex);
                    return;
                case ROM_ARCHIVE_MESSAGE_RELEASE:
                    savedInterrupts = OS_DisableInterrupts();
                    view->mReplySendMask = view->mReplySendMask | (1 << fromIndex);
                    blockId = payload->mArchiveMessage.mWord04;
                    for (activeNode = view->mActiveHead; activeNode != NULL; activeNode = activeNode->mNext) {
                        if (activeNode->mState == ROM_ARCHIVE_NODE_ACTIVE &&
                            activeNode->mBlockNode.mDataInfo.mId == blockId) {
                            break;
                        }
                    }
                    if (activeNode != NULL) {
                        activeNode->mChildCount = activeNode->mChildCount - 1;
                        if (activeNode->mChildCount <= 0) {
                            activeNode->mPendingChildMask = 0;
                            WBT_UnregisterBlock(payload->mArchiveMessage.mWord04);
                            MoveRomArchiveNodeToList(&view->mActiveHead, &view->mPendingHead, activeNode);
                            activeNode->mState = ROM_ARCHIVE_NODE_FINISHED;
                            WakeRomArchiveThread();
                        }
                    }
                    OS_RestoreInterrupts(savedInterrupts);
                    return;
            }
            return;
        case XFER_EVENT_BEFORE_SEND:
            commandData = &record->mData;
            identifier = commandData->mPrepareSendData.mBlockId;
            commandData->mArchiveParentViewEntry.mBlockData = 0;
            for (node = gRomArchiveTransfer.mParentView.mActiveHead; node != NULL; node = node->mNext) {
                if (node->mState == ROM_ARCHIVE_NODE_ACTIVE && node->mBlockNode.mDataInfo.mId == identifier) {
                    break;
                }
            }
            if (node == NULL) {
                return;
            }
            ownPacketSize = commandData->mPrepareSendData.mOwnPacketSize;
            oldValue = node->mLastBlockId;
            requestedBlockId = commandData->mArchiveParentViewEntry.mBlockId;
            if (node->mLoadingBufferIndex != ROM_ARCHIVE_NODE_NO_BUFFER) {
                statFlag = (node->mFile.mStat & 1) != 0 ? 1 : 0;
                if (statFlag == 0) {
                    node->mLoadingBufferIndex = ROM_ARCHIVE_NODE_NO_BUFFER;
                }
            }
            byteOffset = ownPacketSize * oldValue;
            node->mLastBlockId = requestedBlockId;
            activeBufferIndex = node->mLoadingBufferIndex;
            for (value = 0; value < 2; value++) {
                if (value == activeBufferIndex) {
                    continue;
                }
                bufferDelta = byteOffset - node->mBufferOffsets[value];
                if (bufferDelta < 0) {
                    continue;
                }
                if (bufferDelta + ownPacketSize > 0x400) {
                    continue;
                }
                commandData->mArchiveParentViewEntry.mBlockId = oldValue;
                commandData->mArchiveParentViewEntry.mBlockData = (node->mBuffers[value] + bufferDelta);
                break;
            }
            if (node->mLoadingBufferIndex != ROM_ARCHIVE_NODE_NO_BUFFER) {
                return;
            }
            byteOffset = ownPacketSize * requestedBlockId;
            for (bufferIndex = 0; bufferIndex < 2; bufferIndex++) {
                bufferDelta = byteOffset - node->mBufferOffsets[bufferIndex];
                if (bufferDelta < 0) {
                    continue;
                }
                if (bufferDelta + ownPacketSize <= 0x400) {
                    break;
                }
            }
            if (bufferIndex < 2) {
                return;
            }
            newBufferIndex = node->mLastLoadedBufferIndex;
            do {
                newBufferIndex++;
                if (newBufferIndex >= 2) {
                    newBufferIndex = 0;
                }
            } while (newBufferIndex == value);
            node->mLastLoadedBufferIndex = newBufferIndex;
            node->mLoadingBufferIndex = newBufferIndex;
            node->mBufferOffsets[newBufferIndex] = byteOffset & -0x200;
            FS_SeekFile(&node->mFile, byteOffset & -0x200, FILE_SEEK_START);
            FS_ReadFileAsync(&node->mFile, node->mBuffers[newBufferIndex], 0x400);
            break;
    }
}

void RomArchiveChildCallback(WBTCommand *record) {
    RomArchiveChildView *childView;
    s32 fromIndex;
    u32 previousMaxSize;
    s32 blockSize;
    u32 bufferSize;
    void *buffer;
    u32 savedInterrupts;
    RomArchiveMessage message;
    FSFile *file;
    RomArchiveMessage *received;
    FSArchive *archive;
    u32 allocInterrupts;
    void *newBuffer;

    fromIndex = WBT_AidbitmapToAid(record->mPeerBmp);
    childView = (RomArchiveChildView *) &gRomArchiveTransfer.mParentView;
    switch (record->mCommand) {
        case XFER_COMMAND_HANDSHAKE:
            if (record->mTargetBmp != 0) {
                return;
            }
            gRomArchiveTransfer.mParentPacketSize = record->mData.mSync.mPeerPacketSize + 0xe;
            gRomArchiveTransfer.mChildPacketSize = record->mData.mSync.mMyPacketSize + 0xe;
            if (gRomArchiveTransfer.mArchiveBlock == NULL) {
                WBT_GetBlockInfo(1, 0, childView, RomArchiveChildCallback);
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
                bufferSize = (childView->mMaxReadSize + (gRomArchiveTransfer.mParentPacketSize - 0xe) - 1) /
                             (gRomArchiveTransfer.mParentPacketSize - 0xe);
                bufferSize = ((bufferSize + 0x1f) >> 2) << 4;
                allocInterrupts = OS_DisableInterrupts();
                newBuffer = gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, bufferSize, NULL);
                OS_RestoreInterrupts(allocInterrupts);
                childView->mChunkBitmapBuffer = newBuffer;
                childView->mChunkBitmaps[0] = childView->mChunkBitmapBuffer;
            }
            RequestRomArchiveBytes(gRomArchiveTransfer.mPendingFile);
            return;
        case XFER_COMMAND_FETCH_DETAILS:
            blockSize = childView->mNodeBuffers[fromIndex]->mBlockSize;
            gRomArchiveTransfer.mArchiveBlockSize = blockSize;
            savedInterrupts = OS_DisableInterrupts();
            buffer = gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, blockSize, NULL);
            OS_RestoreInterrupts(savedInterrupts);
            gRomArchiveTransfer.mArchiveBlock = buffer;
            blockSize = gRomArchiveTransfer.mArchiveBlockSize;
            if (blockSize < 0) {
                blockSize = childView->mMaxReadSize;
                childView->mMaxReadSize = 0;
            }
            if (childView->mMaxReadSize < blockSize) {
                childView->mMaxReadSize = blockSize;
                buffer = childView->mChunkBitmapBuffer;
                if (buffer != NULL) {
                    savedInterrupts = OS_DisableInterrupts();
                    gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, 0, buffer);
                    OS_RestoreInterrupts(savedInterrupts);
                }
                bufferSize = (childView->mMaxReadSize + (gRomArchiveTransfer.mParentPacketSize - 0xe) - 1) /
                             (gRomArchiveTransfer.mParentPacketSize - 0xe);
                bufferSize = ((bufferSize + 0x1f) >> 2) << 4;
                allocInterrupts = OS_DisableInterrupts();
                newBuffer = gRomArchiveTransfer.mAllocFunc(gRomArchiveTransfer.mAllocFuncArg, bufferSize, NULL);
                OS_RestoreInterrupts(allocInterrupts);
                childView->mChunkBitmapBuffer = newBuffer;
                childView->mChunkBitmaps[0] = childView->mChunkBitmapBuffer;
            }
            childView->mBlockBuffers[fromIndex] = (u32) gRomArchiveTransfer.mArchiveBlock;
            WBT_GetBlock(1, 0x20000, childView->mBlockBuffers, gRomArchiveTransfer.mArchiveBlockSize,
                         childView->mChunkBitmaps, RomArchiveChildCallback);
            return;
        case XFER_COMMAND_FETCH_DATA:
            if (record->mTargetBmp != 0) {
                return;
            }
            if (gRomArchiveTransfer.mState != ROM_ARCHIVE_READY) {
                DC_FlushRange(gRomArchiveTransfer.mArchiveBlock, gRomArchiveTransfer.mArchiveBlockSize);
                childView->mPositionOffset = ReloadRomArchiveFromBlock(gRomArchiveTransfer.mArchiveBlock);
                gRomArchiveTransfer.mState = ROM_ARCHIVE_READY;
                if (gRomArchiveTransfer.mStateCallback == NULL) {
                    return;
                }
                gRomArchiveTransfer.mStateCallback(0);
                return;
            }
            message.mWord04 = childView->mFileBlockId;
            message.mKind = ROM_ARCHIVE_MESSAGE_RELEASE;
            message.mValue24 = 1;
            message.mPacketSizeHigh = (gRomArchiveTransfer.mParentPacketSize >> 8) & 0xff;
            message.mPacketSizeLow = gRomArchiveTransfer.mParentPacketSize;
            if (WBT_PutUserData(1, &message, 9, RomArchiveSendCallback) != 0) {
                return;
            }
            OS_Terminate();
            return;
        case XFER_COMMAND_HOOK_RECORD:
            if (record->mEvent != XFER_EVENT_CUSTOM_ARRIVED) {
                return;
            }
            received = &record->mData.mArchiveMessage;
            switch (received->mKind) {
                case ROM_ARCHIVE_MESSAGE_REPLY:
                    if (received->mValue24 == 0) {
                        WBT_RequestSync(1, RomArchiveChildCallback);
                        return;
                    }
                    childView->mFileBlockId = received->mWord04;
                    childView->mBlockBuffers[fromIndex] = gRomArchiveTransfer.mPendingFile->mArg.w.mUnk_00;
                    WBT_GetBlock(1, childView->mFileBlockId, childView->mBlockBuffers,
                                 gRomArchiveTransfer.mPendingFile->mArg.w.mUnk_08, childView->mChunkBitmaps,
                                 RomArchiveChildCallback);
                    return;
                case ROM_ARCHIVE_MESSAGE_RELEASE_REPLY:
                    file = gRomArchiveTransfer.mPendingFile;
                    archive = file->mArc;
                    gRomArchiveTransfer.mPendingFile = NULL;
                    file->mPosition = file->mPosition + file->mArg.w.mUnk_08;
                    FS_NotifyArchiveAsyncEnd(archive, 0);
                    return;
            }
            return;
    }
}

void InitRomArchive(u32 port, void (*stateCallback)(s32 port),
                    void *(*allocFunc)(s32 port, u32 stateCallback, void *allocFunc), u32 allocFuncArg) {
    RomArchiveTransfer *const transfer = &gRomArchiveTransfer;
    u16 narrowedPort;

    FS_Init(-1);
    narrowedPort = port;
    transfer->mPort = narrowedPort;
    transfer->mSendAllowed = FALSE;
    transfer->mSendPending = FALSE;
    transfer->mState = ROM_ARCHIVE_STOPPED;
    transfer->mStateCallback = stateCallback;
    transfer->mAllocFunc = allocFunc;
    transfer->mAllocFuncArg = allocFuncArg;
    transfer->mPendingFile = NULL;
    transfer->mArchiveBlockSize = 0;
    transfer->mArchiveBlock = NULL;
    transfer->mParentPacketSize = 0;
    transfer->mChildPacketSize = PACKET_PORT_CHILD_PACKET_SIZE;
    gRomArchiveUnusedWord = 0;
    if (WM_SetPortCallback(narrowedPort, RomArchivePortCallback, NULL) != 0) {
        OS_Terminate();
    }
}

void StartRomArchiveParent(u32 port, void (*stateCallback)(s32 port),
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
    InitRomArchive(port, stateCallback, allocFunc, allocFuncArg);
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
            node->mState = ROM_ARCHIVE_NODE_FREE;
            node->mBlockId = (node + 0x10001) - OFFSET_PTR(RomArchiveFileNode, view, 0xc0);
            node++;
        } while (node + 1 < (RomArchiveFileNode *) &view->mFreeHead);
    }
    node->mNext = NULL;
    view->mGroupSendMask = 0;
    view->mReplySendMask = 0;
    view->mMessageSendPending = FALSE;
    view->mActiveHead = NULL;
    view->mPendingHead = NULL;
    transfer->mParentPacketSize = parentPacketSize;
    view->mActiveMask = 1;
    view->mRequestMask = 0;
    view->mPacketSizeChangePending = FALSE;
    view->mPacketSizeMessageMask = 0;
    view->mQueuedNodeCount = 0;
    view->mNewParentPacketSize = transfer->mParentPacketSize;
    DC_FlushRange(view, 0x46f0);
    DC_WaitWriteBufferEmpty();
    WBT_InitParent(transfer->mParentPacketSize, transfer->mChildPacketSize, RomArchiveParentCallback);
    CreateRomArchiveBlock(file, appendOverlays);
    archiveNode = view->mFreeHead;
    view->mFreeHead = archiveNode->mNext;
    archiveNode->mNext = view->mActiveHead;
    view->mActiveHead = archiveNode;
    archiveNode->mChildCount = 1;
    MI_CpuFill8(archiveNode, 0, sizeof(*archiveNode));
    WBT_RegisterBlock(&archiveNode->mBlockNode, 0x20000, gEmptyBlockInfo, transfer->mArchiveBlock,
                      gRomArchiveTransfer.mArchiveBlockSize, 0);
    transfer->mState = ROM_ARCHIVE_STARTING;
    StartFileReadThread();
}

void StartRomArchiveChild(u32 port, void (*stateCallback)(s32 port),
                          void *(*allocFunc)(s32 port, u32 stateCallback, void *allocFunc), u32 allocFuncArg) {
    u32 savedInterrupts;
    RomArchiveTransfer *transfer;
    RomArchiveChildView *view;
    s32 index;

    savedInterrupts = OS_DisableInterrupts();
    if (gRomArchiveStarted != 0) {
        return;
    }
    gRomArchiveStarted = 1;
    InitRomArchive(port, stateCallback, allocFunc, allocFuncArg);
    OS_RestoreInterrupts(savedInterrupts);
    transfer = &gRomArchiveTransfer;
    transfer->mIsParent = 0;
    view = OFFSET_PTR(RomArchiveChildView, transfer, 0x440);
    DC_FlushRange(view, 0xb0c);
    DC_WaitWriteBufferEmpty();
    for (index = 0; index < 16; index++) {
        view->mNodeBuffers[index] = &view->mNodeBufferEntries[index];
        view->mBlockBuffers[index] = 0;
        view->mChunkBitmaps[index] = NULL;
    }
    view->mChunkBitmapBuffer = NULL;
    view->mMaxReadSize = 0;
    view->mFileBlockId = 0;
    DC_FlushRange(view, 0xb0c);
    DC_WaitWriteBufferEmpty();
    WBT_InitChild(RomArchiveChildCallback);
    transfer->mState = ROM_ARCHIVE_STARTING;
}

void StartRomArchive(int isParent, u32 port, u32 parentPacketSize, void (*stateCallback)(s32 isParent),
                     void *(*allocFunc)(s32 isParent, u32 port, void *parentPacketSize), u32 allocFuncArg) {
    if (isParent != 0) {
        StartRomArchiveParent(port, stateCallback, allocFunc, allocFuncArg, parentPacketSize, NULL, 1);
        return;
    }
    StartRomArchiveChild(port, stateCallback, allocFunc, allocFuncArg);
}

static inline void RomArchiveCallAllocFuncOnBlock(RomArchiveTransfer *transfer, void *block) {
    u32 savedInterrupts;
    if (block != NULL) {
        savedInterrupts = OS_DisableInterrupts();
        transfer->mAllocFunc(transfer->mAllocFuncArg, 0, block);
        OS_RestoreInterrupts(savedInterrupts);
    }
}

void StartRomArchivePacketSend(void) {
    RomArchiveChildView *childView;
    RomArchiveTransfer *transfer;
    u8 *buffer;
    u16 packetSize;
    u16 builtSize;
    s32 isParent;
    gRomArchiveTransfer.mSendAllowed = TRUE;
    if (gRomArchiveTransfer.mIsParent == 0) {
        childView = (RomArchiveChildView *) &gRomArchiveTransfer.mParentView;
        WM_ReadStatus(childView->mWmStatus);
        WBT_SetOwnAid(childView->mOwnAid);
        WBT_RequestSync(1, RomArchiveChildCallback);
    } else {
        gRomArchiveTransfer.mState = ROM_ARCHIVE_READY;
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
    if (transfer->mSendAllowed == FALSE) {
        return;
    }
    buffer = transfer->mPacketBuffer;
    if (isParent != 0) {
        builtSize = WBT_MpParentSendHook(buffer, packetSize);
    } else {
        builtSize = WBT_MpChildSendHook(buffer, packetSize);
    }
    transfer->mSendPending =
        WM_SetMPDataToPortEx(SendRomArchivePacket, NULL, buffer, builtSize, 0xffff, transfer->mPort, 3) == 2;
    transfer->mSendAllowed = gRomArchiveTransfer.mSendPending == FALSE;
}

void StopRomArchive(void) {
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
            RomArchiveCallAllocFuncOnBlock(&gRomArchiveTransfer, block);
            transfer->mArchiveBlock = NULL;
            transfer->mArchiveBlockSize = 0;
        }
        transfer->mState = ROM_ARCHIVE_STOPPED;
        if (gRomArchiveTransfer.mIsParent == 0) {
            view = &transfer->mParentView;
            if (transfer->mPendingFile != NULL) {
                archive = transfer->mPendingFile->mArc;
                transfer->mPendingFile = NULL;
                FS_NotifyArchiveAsyncEnd(archive, 5);
            }
            RomArchiveCallAllocFuncOnBlock(&gRomArchiveTransfer, view->mChunkBitmapBuffer);
        } else {
            StopFileReadThread();
        }
        WBT_End();
        WM_SetPortCallback(gRomArchiveTransfer.mPort, NULL, NULL);
        gRomArchiveStarted = 0;
    }
    OS_RestoreInterrupts(savedInterrupts);
}

u32 GetRomArchiveState(void) {
    u32 state;
    state = gRomArchiveTransfer.mState;
    return state;
}

u32 SetRomArchiveGroupSendMask(u32 value) {
    u32 interruptState = value;
    u32 maskWithoutParent;
    u32 savedValue;
    savedValue = interruptState;
    interruptState = OS_DisableInterrupts();
    maskWithoutParent = (savedValue) & ~(1u);
    gRomArchiveTransfer.mParentView.mGroupSendMask = maskWithoutParent;
    interruptState = OS_RestoreInterrupts(interruptState);
    return interruptState;
}

void WakeRomArchiveThread(void) {
    OS_WakeupThreadDirect(&gFileReadThread.mThread);
}
