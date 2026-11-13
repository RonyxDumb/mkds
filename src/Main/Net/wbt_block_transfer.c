#include "Main/Net/wbt_block_transfer.h"
#include "Main/Net/append_bytes.h"
#include "Main/Net/mark_chunk_received.h"
#include "Main/Net/wbt_requests.h"
#include "Main/Net/request_id.h"
#include "code_02133048.h"
#include "code_0214d018.h"
#include "Main/Net/data_0216f000.h"

u32 wbt_initialize_flag;

#pragma thumb on

// Returns the index of the next chunk whose bit is still clear after the last received one, or -1 when all have
// arrived.
s32 WBTi_FindBitmapIndex(WBTPacketBitmap *bitmap) {
    s32 index;
    s32 startIndex;
    s32 bitPosition;
    u32 *wordPtr;
    s32 total;
    u32 *bitmapBase;
    index = bitmap->mCurrent + 1;
    total = bitmap->mTotal;
    if (index >= total) {
        index = 0;
    }
    startIndex = index;
    bitmapBase = bitmap->mBitmap;
    wordPtr = bitmapBase + (index >> 5);
    bitPosition = index & 0x1f;
    do {
        if ((*wordPtr & (1 << bitPosition)) == 0) {
            goto found;
        }
        index = index + 1;
        if (index < total) {
            bitPosition = bitPosition + 1;
            if (bitPosition > 0x1f) {
                bitPosition = 0;
                wordPtr = wordPtr + 1;
            }
        } else {
            index = 0;
            bitPosition = index;
            wordPtr = bitmapBase;
        }
    } while (index != startIndex);
    goto fail;
found:
    bitmap->mPickedChunkIndex = index;
    return index;
fail:
    return -1;
}

// Copies chunk b into the buffer; FALSE when b is past the last chunk.
BOOL StoreReceivedChunk(WBTPacketBitmap *bitmap, s32 chunkIndex, const u8 *chunkData) {
    u32 chunkSize;
    u8 *buffer;
    u32 lastChunkSize;
    chunkSize = WBT_GetPeerPacketLength();
    buffer = bitmap->mBuffer;
    if (chunkIndex < bitmap->mTotal) {
        if (chunkIndex == bitmap->mTotal - 1) {
            lastChunkSize = _s32_div_f(bitmap->mLength, chunkSize) >> 32;
            if (lastChunkSize != 0) {
                MI_CpuCopy8(chunkData, buffer + chunkIndex * chunkSize, lastChunkSize);
            } else {
                MI_CpuCopy8(chunkData, buffer + chunkIndex * chunkSize, chunkSize);
            }
        } else {
            MI_CpuCopy8(chunkData, buffer + chunkIndex * chunkSize, chunkSize);
        }
    } else {
        return FALSE;
    }
    return TRUE;
}

// Fills the shared record and calls the transfer's callback once per request id (code 13 always).
void WBTi_NotifySystemCallback(BlockTransfer *transfer, s32 event, s32 entryIndex, u32 result) {
    BlockTransferEntry *entry;
    WBTCommand *callbackRecord;
    callbackRecord = &transfer->mCallbackRecord;
    entry = &transfer->mEntries[entryIndex];
    if (event == 13 || entry->mRequestId != entry->mLastCallbackId) {
        callbackRecord->mCommand = 12;
        callbackRecord->mPeerBmp = 1 << entryIndex;
        entry->mLastCallbackId = entry->mRequestId;
        callbackRecord->mPeerCmdCounter = entry->mRequestId;
        callbackRecord->mResult = result;
        switch (event) {
            case 8:
                callbackRecord->mData.mBlockDone.mBlockId = entry->mBlockId;
                break;
            case 2:
                callbackRecord->mData.mSync.mNumOfList = entry->mBlockCount;
                callbackRecord->mData.mSync.mPeerPacketSize = entry->mPacketSendChunkSize;
                callbackRecord->mData.mSync.mMyPacketSize = entry->mPacketReceiveChunkSize;
                break;
            case 10:
                if (entry->mByteCount > 9) {
                    callbackRecord->mData.mUserData.mSize = 0;
                } else {
                    callbackRecord->mData.mUserData.mSize = entry->mByteCount;
                    MI_CpuCopy8(entry->mPayload, callbackRecord->mData.mUserData.mData,
                                callbackRecord->mData.mUserData.mSize);
                }
                break;
            case 12:
            case 14:
                break;
        }
        callbackRecord->mEvent = event;
        if (callbackRecord->mCallback != NULL) {
            callbackRecord->mCallback(callbackRecord);
        }
    }
}

// A reply from an entry: clears its bit in the current request, calls the request's callback and ends the request when
// no index is left.
void WBTi_NotifyCompletionCallback(BlockTransfer *transfer, s32 event, s32 entryIndex) {
    u16 entryBit;
    u8 requestId;
    BlockTransferEntry *entry;
    entry = &transfer->mEntries[entryIndex];
    entryBit = 1 << entryIndex;
    transfer->mCurrentRequest.mPeerBmp = entryBit;
    requestId = entry->mRequestId;
    if (transfer->mCurrentRequest.mMyCmdCounter == requestId) {
        transfer->mCurrentRequest.mPeerCmdCounter = requestId;
        if ((transfer->mCurrentRequest.mTargetBmp & entryBit) != 0) {
            transfer->mCurrentRequest.mTargetBmp &= ~entryBit;
            switch (event) {
                case 3:
                    transfer->mCurrentRequest.mData.mSync.mNumOfList = entry->mBlockCount;
                    transfer->mCurrentRequest.mData.mSync.mPeerPacketSize = entry->mPacketSendChunkSize;
                    transfer->mCurrentRequest.mData.mSync.mMyPacketSize = entry->mPacketReceiveChunkSize;
                    break;
                case 0:
                case 1:
                case 2:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                    break;
            }
            transfer->mCurrentRequest.mEvent = event;
            if (transfer->mCurrentRequest.mCallback != NULL) {
                transfer->mCurrentRequest.mCallback(&transfer->mCurrentRequest);
            }
        }
        if (transfer->mCurrentRequest.mTargetBmp == 0) {
            transfer->mCurrentRequest.mCommand = 0;
        }
    }
}

// Reads one packet from index b field by field into its entry, answers or calls back as the kind needs, and returns the
// bytes used.
u32 WBT_CallPacketRecvHook(BlockTransfer *transfer, s32 entryIndex, const u8 *cursor, s32 packetSize) {
    s32 consumedBytes;
    u32 parseState;
    u32 packetKind;
    BOOL isAddressedToOwnAid;
    BlockTransferEntry *entry;
    WBTPacketBitmap *receiveBitmap;
    consumedBytes = 0;
    parseState = 1;
    entry = &transfer->mEntries[entryIndex];
    receiveBitmap = &transfer->mEntries[entryIndex].mReceive;
    entry->mUnk_00 = 1;
    if (packetSize == 0) {
        return 0;
    }
    if (packetSize > 0) {
        do {
            switch (parseState) {
                case 1:
                    MI_CpuCopy8(cursor, &entry->mPacketKind, 1);
                    cursor = cursor + 1;
                    consumedBytes = consumedBytes + 1;
                    parseState = 2;
                    continue;
                case 2:
                    MI_CpuCopy8(cursor, &entry->mIndexMask, 2);
                    cursor = cursor + 2;
                    consumedBytes = consumedBytes + 2;
                    parseState = entry->mIndexMask;
                    if (WBT_GetOwnAid() == -1) {
                        isAddressedToOwnAid = FALSE;
                    } else {
                        parseState = parseState & (1 << WBT_GetOwnAid());
                        if (parseState != 0) {
                            isAddressedToOwnAid = TRUE;
                        } else {
                            isAddressedToOwnAid = FALSE;
                        }
                    }
                    if (isAddressedToOwnAid == FALSE) {
                        return consumedBytes;
                    }
                    parseState = 3;
                    continue;
                case 3:
                    MI_CpuCopy8(cursor, &entry->mRequestId, 1);
                    cursor = cursor + 1;
                    consumedBytes = consumedBytes + 1;
                    switch (entry->mPacketKind) {
                        case 1:
                            return consumedBytes;
                        case 2:
                            parseState = 5;
                            continue;
                        case 3:
                            parseState = 4;
                            continue;
                        case 11:
                            if (transfer->mCurrentRequest.mCommand == 10) {
                                WBTi_NotifyCompletionCallback(transfer, entry->mPacketKind, entryIndex);
                            }
                            return consumedBytes;
                        case 10:
                            parseState = 10;
                            continue;
                        default:
                            parseState = 7;
                            continue;
                    }
                case 10:
                    MI_CpuCopy8(cursor, &entry->mByteCount, 1);
                    cursor = cursor + 1;
                    consumedBytes = consumedBytes + 1;
                    parseState = 9;
                    continue;
                case 9:
                    entry->mPayload = (u8 *) cursor;
                    WBTi_NotifySystemCallback(transfer, entry->mPacketKind, entryIndex, 0);
                    entry->mUnk_00 = 2;
                    consumedBytes = consumedBytes + 9;
                    return consumedBytes;
                case 4:
                    MI_CpuCopy8(cursor, &entry->mBlockCount, 2);
                    cursor = cursor + 2;
                    consumedBytes = consumedBytes + 2;
                    if (entry->mPacketKind == 3) {
                        parseState = 5;
                    }
                    continue;
                case 5:
                    MI_CpuCopy8(cursor, &entry->mPacketSendChunkSize, 2);
                    MI_CpuCopy8(cursor + 2, &entry->mPacketReceiveChunkSize, 2);
                    if (WBT_GetOwnAid() != 0) {
                        SetSendChunkSize(entry->mPacketReceiveChunkSize);
                        SetReceiveChunkSize(entry->mPacketSendChunkSize);
                    }
                    packetKind = entry->mPacketKind;
                    switch (packetKind) {
                        case 2:
                            WBTi_NotifySystemCallback(transfer, packetKind, entryIndex, 0);
                            entry->mUnk_00 = 2;
                            return consumedBytes + 4;
                        case 3:
                            if (transfer->mCurrentRequest.mCommand == 2) {
                                WBTi_NotifyCompletionCallback(transfer, packetKind, entryIndex);
                            }
                            return consumedBytes + 4;
                        default:
                            WBTi_NotifySystemCallback(transfer, 15, entryIndex, 3);
                            return consumedBytes + 4;
                    }
                case 7:
                    MI_CpuCopy8(cursor, &entry->mBlockId, 4);
                    cursor = cursor + 4;
                    consumedBytes = consumedBytes + 4;
                    packetKind = entry->mPacketKind;
                    switch (packetKind) {
                        case 8:
                            WBTi_NotifySystemCallback(transfer, packetKind, entryIndex, 0);
                            entry->mUnk_00 = 2;
                            return consumedBytes;
                        case 9:
                            if (transfer->mCurrentRequest.mCommand == 4) {
                                if (transfer->mCurrentRequest.mData.mGet.mBlockId == entry->mBlockId) {
                                    WBTi_NotifyCompletionCallback(transfer, 5, entryIndex);
                                }
                            } else if (transfer->mCurrentRequest.mCommand == 6) {
                                if (transfer->mCurrentRequest.mData.mGet.mBlockId == entry->mBlockId) {
                                    WBTi_NotifyCompletionCallback(transfer, 7, entryIndex);
                                }
                            }
                            return consumedBytes;
                        case 4:
                        case 5:
                        case 6:
                        case 7:
                            parseState = 8;
                            continue;
                        default:
                            WBTi_NotifySystemCallback(transfer, 15, entryIndex, 3);
                            continue;
                    }
                case 8:
                    MI_CpuCopy8(cursor, &entry->mChunkIndex, 4);
                    cursor = cursor + 4;
                    consumedBytes = consumedBytes + 4;
                    packetKind = entry->mPacketKind;
                    switch (packetKind) {
                        case 4:
                        case 6:
                            entry->mUnk_00 = 2;
                            return consumedBytes;
                        case 5:
                        case 7:
                            entry->mPayload = (u8 *) cursor;
                            if (transfer->mCurrentRequest.mCommand == 4 || transfer->mCurrentRequest.mCommand == 6) {
                                if (entry->mBlockId == transfer->mCurrentRequest.mData.mGet.mBlockId) {
                                    if ((transfer->mCurrentRequest.mTargetBmp & (u16) (1 << entryIndex)) != 0) {
                                        if (IsChunkReceived(receiveBitmap, entry->mChunkIndex) == FALSE) {
                                            if (StoreReceivedChunk(receiveBitmap, entry->mChunkIndex,
                                                                   entry->mPayload) == TRUE) {
                                                MarkChunkReceived(receiveBitmap, entry->mChunkIndex);
                                            } else {
                                                WBTi_NotifySystemCallback(transfer, 15, entryIndex, 6);
                                            }
                                        }
                                    }
                                }
                            }
                            return consumedBytes;
                        default:
                            WBTi_NotifySystemCallback(transfer, 15, entryIndex, 3);
                            continue;
                    }
                default:
                    WBTi_NotifySystemCallback(transfer, 15, entryIndex, 4);
                    continue;
            }
        } while (consumedBytes < packetSize);
    }
    WBTi_NotifySystemCallback(transfer, 15, entryIndex, 5);
    return consumedBytes;
}

s32 ReplyToBlockCountRequest(BlockTransfer *transfer, s32 entryIndex, u8 *buffer, s32 bufferSize) {
    s32 packetSize;
    s32 blockCount;
    u32 ownPacketLength;
    BlockTransferEntry *entry;
    u16 targetMask;
    packetSize = 0;
    entry = &transfer->mEntries[entryIndex];
    targetMask = 1 << entryIndex;
    if (entry->mUnk_00 == 2) {
        if (entry->mPacketKind == 2) {
            blockCount = WBT_NumOfRegisteredBlock();
            ownPacketLength = WBT_GetOwnPacketLength();
            packetSize = WriteBlockCountReplyPacket(buffer, targetMask, entry->mRequestId, blockCount, ownPacketLength,
                                                    WBT_GetPeerPacketLength());
            entry->mUnk_00 = 1;
        }
    }
    return packetSize;
}

s32 ReplyToNoMissingChunk(BlockTransfer *transfer, s32 entryIndex, u8 *buffer, s32 bufferSize) {
    s32 packetSize;
    u16 targetMask;
    BlockTransferEntry *entry;
    packetSize = 0;
    entry = &transfer->mEntries[entryIndex];
    targetMask = 1 << entryIndex;
    if (entry->mUnk_00 == 2) {
        if (entry->mPacketKind == 8) {
            packetSize = WriteNoMissingChunkReplyPacket(buffer, targetMask, entry->mRequestId, entry->mBlockId);
            entry->mUnk_00 = 1;
        }
    }
    return packetSize;
}

s32 ReplyToBytesPacket(BlockTransfer *transfer, s32 entryIndex, u8 *buffer, s32 bufferSize) {
    s32 packetSize;
    u16 targetMask;
    BlockTransferEntry *entry;
    packetSize = 0;
    entry = &transfer->mEntries[entryIndex];
    targetMask = 1 << entryIndex;
    if (entry->mUnk_00 == 2) {
        if (entry->mPacketKind == 10) {
            packetSize = WriteBytesReplyPacket(buffer, targetMask, entry->mRequestId);
            entry->mUnk_00 = 1;
        }
    }
    return packetSize;
}

s32 ReplyToBlockDataRequest(BlockTransfer *transfer, s32 entryIndex, u8 *buffer, s32 bufferSize) {
    s32 packetSize;
    u32 indexMask;
    s32 chunkIndex;
    u32 chunkAddress;
    WBTBlockInfoList *block;
    WBTCommand *callbackRecord;
    BlockTransferEntry *entry;
    packetSize = 0;
    callbackRecord = &transfer->mCallbackRecord;
    entry = &transfer->mEntries[entryIndex];
    if (entry->mUnk_00 == 2) {
        if (WBT_GetOwnAid() == 0) {
            indexMask = 0xfffe;
        } else {
            indexMask = 1;
        }
        if (entry->mPacketKind == 4) {
            block = FindBlockById(entry->mBlockId);
            if (block != NULL) {
                chunkIndex = PickSendChunkIndex(entry->mBlockId, entry->mChunkIndex);
                if (chunkIndex != -1) {
                    if (block->mBlockType == 0) {
                        chunkAddress = WBTi_GetPacketBuffer(entry->mBlockId, chunkIndex);
                        packetSize = WriteBlockDataPacket(buffer, indexMask, entry->mRequestId, entry->mBlockId,
                                                          chunkIndex, chunkAddress, WBT_GetOwnPacketLength());
                    } else if (block->mBlockType == 1) {
                        callbackRecord->mData.mPrepareSendData.mBlockId = entry->mBlockId;
                        callbackRecord->mData.mPrepareSendData.mBlockSeqNo = chunkIndex;
                        callbackRecord->mData.mPrepareSendData.mOwnPacketSize = WBT_GetOwnPacketLength();
                        callbackRecord->mData.mPrepareSendData.mDataPtr = 0;
                        WBTi_NotifySystemCallback(transfer, 13, entryIndex, 0);
                        if (callbackRecord->mData.mPrepareSendData.mDataPtr != 0) {
                            packetSize = WriteBlockDataPacket(buffer, indexMask, entry->mRequestId,
                                                              callbackRecord->mData.mPrepareSendData.mBlockId,
                                                              callbackRecord->mData.mPrepareSendData.mBlockSeqNo,
                                                              callbackRecord->mData.mPrepareSendData.mDataPtr,
                                                              callbackRecord->mData.mPrepareSendData.mOwnPacketSize);
                        }
                    }
                }
            }
            entry->mUnk_00 = 1;
        }
    }
    return packetSize;
}

// Sends nothing while the chunk address is 0.
s32 ReplyToBlockNodeRequest(BlockTransfer *transfer, s32 entryIndex, u8 *buffer, s32 bufferSize) {
    s32 packetSize;
    u32 targetMask;
    u32 chunkBuffer;
    BlockTransferEntry *entry;
    packetSize = 0;
    entry = &transfer->mEntries[entryIndex];
    if (entry->mUnk_00 == 2) {
        if (WBT_GetOwnAid() == 0) {
            targetMask = 0xffff;
        } else {
            targetMask = 1;
        }
        if (entry->mPacketKind == 6) {
            chunkBuffer = WBTi_GetPacketBuffer(entry->mBlockId, entry->mChunkIndex);
            if (chunkBuffer != 0) {
                packetSize = WriteBlockNodePacket(buffer, targetMask, entry->mRequestId, entry->mBlockId,
                                                  entry->mChunkIndex, chunkBuffer, WBT_GetOwnPacketLength());
                entry->mUnk_00 = 1;
            }
        }
    }
    return packetSize;
}

// Sends the node packet even when the chunk address is 0.
s32 ReplyToBlockNodeRequestAlways(BlockTransfer *transfer, s32 entryIndex, u8 *buffer, s32 bufferSize) {
    s32 packetSize;
    u32 targetMask;
    u32 chunkBuffer;
    BlockTransferEntry *entry;
    packetSize = 0;
    entry = &transfer->mEntries[entryIndex];
    if (entry->mUnk_00 == 2) {
        if (WBT_GetOwnAid() == 0) {
            targetMask = 0xffff;
        } else {
            targetMask = 1;
        }
        if (entry->mPacketKind == 6) {
            chunkBuffer = WBTi_GetPacketBuffer(entry->mBlockId, entry->mChunkIndex);
            packetSize = WriteBlockNodePacket(buffer, targetMask, entry->mRequestId, entry->mBlockId,
                                              entry->mChunkIndex, chunkBuffer, WBT_GetOwnPacketLength());
            entry->mUnk_00 = 1;
        }
    }
    return packetSize;
}

// Writes the packet of the running request again on every call.
s32 WBTi_CheckRequest(BlockTransfer *transfer, u8 *buffer, s32 bufferSize) {
    s32 packetSize;
    s32 entryIndex;
    u32 value;
    WBTPacketBitmap *receiveBitmap;
    s32 missingChunkIndex;
    u16 targetBitmap;
    packetSize = 0;
    switch (transfer->mCurrentRequest.mCommand) {
        case 2:
            value = WBT_GetOwnPacketLength();
            return WriteBlockCountRequestPacket(buffer, transfer->mCurrentRequest.mTargetBmp,
                                                transfer->mCurrentRequest.mMyCmdCounter, value,
                                                WBT_GetPeerPacketLength());
        case 4:
        case 6:
            for (entryIndex = 0, receiveBitmap = &transfer->mEntries[0].mReceive; entryIndex < 16; entryIndex++) {
                value = 1;
                value = value << entryIndex;
                if ((transfer->mCurrentRequest.mTargetBmp & (u16) value) != 0) {
                    missingChunkIndex = WBTi_FindBitmapIndex(receiveBitmap);
                    if (missingChunkIndex == -1) {
                        packetSize = WriteNoMissingChunkPacket(buffer, value, transfer->mCurrentRequest.mMyCmdCounter,
                                                               transfer->mCurrentRequest.mData.mGet.mBlockId);
                    } else {
                        targetBitmap = transfer->mCurrentRequest.mTargetBmp;
                        if (transfer->mCurrentRequest.mCommand == 4) {
                            packetSize = WriteBlockDataRequestPacket(
                                buffer, targetBitmap, transfer->mCurrentRequest.mMyCmdCounter,
                                transfer->mCurrentRequest.mData.mGet.mBlockId, missingChunkIndex);
                        } else {
                            packetSize = WriteBlockNodeRequestPacket(
                                buffer, targetBitmap, transfer->mCurrentRequest.mMyCmdCounter,
                                transfer->mCurrentRequest.mData.mGet.mBlockId, missingChunkIndex);
                        }
                    }
                    if (packetSize != 0) {
                        return packetSize;
                    }
                }
                receiveBitmap = OFFSET_PTR(WBTPacketBitmap, receiveBitmap, sizeof(BlockTransferEntry));
            }
            return packetSize;
        case 10:
            packetSize = WriteBytesPacket(
                buffer, transfer->mCurrentRequest.mTargetBmp, transfer->mCurrentRequest.mMyCmdCounter,
                &transfer->mCurrentRequest.mData.mUserDataWord, transfer->mCurrentRequest.mData.mUserData.mSize);
            break;
    }
    return packetSize;
}

// Starts the waiting request when none is running and writes its first packet.
s32 WBTi_SwitchNextCommand(BlockTransfer *transfer, u8 *buffer, s32 bufferSize) {
    s32 packetSize;
    u32 value;
    s32 entryIndex;
    WBTCommand *nextRequest;
    WBTPacketBitmap *nodeBitmap;
    WBTPacketBitmap *dataBitmap;
    packetSize = 0;
    nextRequest = &transfer->mNextRequest;
    if (transfer->mCurrentRequest.mCommand != 0) {
        return 0;
    }
    if (nextRequest->mCommand == 0) {
        return 0;
    }
    AdvanceRequestId();
    value = GetRequestId();
    switch (nextRequest->mCommand) {
        case 2:
            MIi_CpuCopy32(nextRequest, transfer, 0x9c);
            transfer->mCurrentRequest.mMyCmdCounter = value;
            value = WBT_GetOwnPacketLength();
            packetSize =
                WriteBlockCountRequestPacket(buffer, transfer->mCurrentRequest.mTargetBmp,
                                             transfer->mCurrentRequest.mMyCmdCounter, value, WBT_GetPeerPacketLength());
            break;
        case 6:
            MIi_CpuCopy32(nextRequest, transfer, 0x9c);
            transfer->mCurrentRequest.mMyCmdCounter = value;
            for (entryIndex = 0, nodeBitmap = &transfer->mEntries[0].mReceive; entryIndex < 16; entryIndex++) {
                if (((transfer->mCurrentRequest.mTargetBmp >> entryIndex) & 1) != 0) {
                    WBTi_InitBitmap(nodeBitmap, transfer->mCurrentRequest.mData.mGet.mRecvDataSize,
                                    nodeBitmap->mInlineChunkBitmap,
                                    transfer->mCurrentRequest.mData.mGet.mRecvBuf[entryIndex]);
                }
                nodeBitmap = OFFSET_PTR(WBTPacketBitmap, nodeBitmap, sizeof(BlockTransferEntry));
            }
            if (nextRequest->mCommand == 4) {
                packetSize = WriteBlockDataRequestPacket(buffer, transfer->mCurrentRequest.mTargetBmp,
                                                         transfer->mCurrentRequest.mMyCmdCounter,
                                                         transfer->mCurrentRequest.mData.mGet.mBlockId, 0);
            } else {
                packetSize = WriteBlockNodeRequestPacket(buffer, transfer->mCurrentRequest.mTargetBmp,
                                                         transfer->mCurrentRequest.mMyCmdCounter,
                                                         transfer->mCurrentRequest.mData.mGet.mBlockId, 0);
            }
            break;
        case 4:
            MIi_CpuCopy32(nextRequest, transfer, 0x9c);
            transfer->mCurrentRequest.mMyCmdCounter = value;
            for (entryIndex = 0, dataBitmap = &transfer->mEntries[0].mReceive; entryIndex < 16; entryIndex++) {
                if (((transfer->mCurrentRequest.mTargetBmp >> entryIndex) & 1) != 0) {
                    WBTi_InitBitmap(dataBitmap, transfer->mCurrentRequest.mData.mGet.mRecvDataSize,
                                    transfer->mCurrentRequest.mData.mGet.mPktBmp[entryIndex],
                                    transfer->mCurrentRequest.mData.mGet.mRecvBuf[entryIndex]);
                }
                dataBitmap = OFFSET_PTR(WBTPacketBitmap, dataBitmap, sizeof(BlockTransferEntry));
            }
            if (nextRequest->mCommand == 4) {
                packetSize = WriteBlockDataRequestPacket(buffer, transfer->mCurrentRequest.mTargetBmp,
                                                         transfer->mCurrentRequest.mMyCmdCounter,
                                                         transfer->mCurrentRequest.mData.mGet.mBlockId, 0);
            } else {
                packetSize = WriteBlockNodeRequestPacket(buffer, transfer->mCurrentRequest.mTargetBmp,
                                                         transfer->mCurrentRequest.mMyCmdCounter,
                                                         transfer->mCurrentRequest.mData.mGet.mBlockId, 0);
            }
            break;
        case 10:
            MIi_CpuCopy32(nextRequest, transfer, 0x9c);
            transfer->mCurrentRequest.mMyCmdCounter = value;
            packetSize = WriteBytesPacket(
                buffer, transfer->mCurrentRequest.mTargetBmp, transfer->mCurrentRequest.mMyCmdCounter,
                &transfer->mCurrentRequest.mData.mUserDataWord, transfer->mCurrentRequest.mData.mUserData.mSize);
            break;
    }
    nextRequest->mCommand = 0;
    return packetSize;
}

#pragma thumb off
