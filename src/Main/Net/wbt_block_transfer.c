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
    if (event == XFER_EVENT_BEFORE_SEND || entry->mRequestId != entry->mLastCallbackId) {
        callbackRecord->mCommand = XFER_COMMAND_HOOK_RECORD;
        callbackRecord->mPeerBmp = 1 << entryIndex;
        entry->mLastCallbackId = entry->mRequestId;
        callbackRecord->mPeerCmdCounter = entry->mRequestId;
        callbackRecord->mResult = result;
        switch (event) {
            case XFER_EVENT_ALL_CHUNKS_HELD:
                callbackRecord->mData.mBlockDone.mBlockId = entry->mBlockId;
                break;
            case XFER_EVENT_HANDSHAKE_ASKED:
                callbackRecord->mData.mSync.mNumOfList = entry->mBlockCount;
                callbackRecord->mData.mSync.mPeerPacketSize = entry->mPacketSendChunkSize;
                callbackRecord->mData.mSync.mMyPacketSize = entry->mPacketReceiveChunkSize;
                break;
            case XFER_EVENT_CUSTOM_ARRIVED:
                if (entry->mByteCount > 9) {
                    callbackRecord->mData.mUserData.mSize = 0;
                } else {
                    callbackRecord->mData.mUserData.mSize = entry->mByteCount;
                    MI_CpuCopy8(entry->mPayload, callbackRecord->mData.mUserData.mData,
                                callbackRecord->mData.mUserData.mSize);
                }
                break;
            case XFER_EVENT_UNUSED_12:
            case XFER_EVENT_UNUSED_14:
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
                case XFER_EVENT_HANDSHAKE_ENDED:
                    transfer->mCurrentRequest.mData.mSync.mNumOfList = entry->mBlockCount;
                    transfer->mCurrentRequest.mData.mSync.mPeerPacketSize = entry->mPacketSendChunkSize;
                    transfer->mCurrentRequest.mData.mSync.mMyPacketSize = entry->mPacketReceiveChunkSize;
                    break;
                case XFER_EVENT_NOTHING:
                case XFER_EVENT_QUIET:
                case XFER_EVENT_HANDSHAKE_ASKED:
                case XFER_EVENT_DATA_ASKED:
                case XFER_EVENT_DATA_ENDED:
                case XFER_EVENT_LAYOUT_ASKED:
                case XFER_EVENT_LAYOUT_ENDED:
                case XFER_EVENT_ALL_CHUNKS_HELD:
                case XFER_EVENT_ALL_CHUNKS_ANSWER:
                case XFER_EVENT_CUSTOM_ARRIVED:
                case XFER_EVENT_CUSTOM_ENDED:
                    break;
            }
            transfer->mCurrentRequest.mEvent = event;
            if (transfer->mCurrentRequest.mCallback != NULL) {
                transfer->mCurrentRequest.mCallback(&transfer->mCurrentRequest);
            }
        }
        if (transfer->mCurrentRequest.mTargetBmp == 0) {
            transfer->mCurrentRequest.mCommand = XFER_COMMAND_UNUSED;
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
    parseState = XFER_PARSE_KIND_FIELD;
    entry = &transfer->mEntries[entryIndex];
    receiveBitmap = &transfer->mEntries[entryIndex].mReceive;
    entry->mState = XFER_ENTRY_FREE;
    if (packetSize == 0) {
        return 0;
    }
    if (packetSize > 0) {
        do {
            switch (parseState) {
                case XFER_PARSE_KIND_FIELD:
                    MI_CpuCopy8(cursor, &entry->mPacketKind, 1);
                    cursor = cursor + 1;
                    consumedBytes = consumedBytes + 1;
                    parseState = XFER_PARSE_MASK_FIELD;
                    continue;
                case XFER_PARSE_MASK_FIELD:
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
                    parseState = XFER_PARSE_ASK_NUMBER;
                    continue;
                case XFER_PARSE_ASK_NUMBER:
                    MI_CpuCopy8(cursor, &entry->mRequestId, 1);
                    cursor = cursor + 1;
                    consumedBytes = consumedBytes + 1;
                    switch (entry->mPacketKind) {
                        case XFER_PACKET_FILLER:
                            return consumedBytes;
                        case XFER_PACKET_HANDSHAKE_ASK:
                            parseState = XFER_PARSE_SIZE_LIST;
                            continue;
                        case XFER_PACKET_HANDSHAKE_ANSWER:
                            parseState = XFER_PARSE_TOTAL_FIELD;
                            continue;
                        case XFER_PACKET_CUSTOM_ANSWER:
                            if (transfer->mCurrentRequest.mCommand == XFER_COMMAND_SEND_CUSTOM) {
                                WBTi_NotifyCompletionCallback(transfer, entry->mPacketKind, entryIndex);
                            }
                            return consumedBytes;
                        case XFER_PACKET_CUSTOM:
                            parseState = XFER_PARSE_LENGTH_FIELD;
                            continue;
                        default:
                            parseState = XFER_PARSE_TARGET_FIELD;
                            continue;
                    }
                case XFER_PARSE_LENGTH_FIELD:
                    MI_CpuCopy8(cursor, &entry->mByteCount, 1);
                    cursor = cursor + 1;
                    consumedBytes = consumedBytes + 1;
                    parseState = XFER_PARSE_BODY;
                    continue;
                case XFER_PARSE_BODY:
                    entry->mPayload = (u8 *) cursor;
                    WBTi_NotifySystemCallback(transfer, entry->mPacketKind, entryIndex, 0);
                    entry->mState = XFER_ENTRY_AWAITING_ANSWER;
                    consumedBytes = consumedBytes + 9;
                    return consumedBytes;
                case XFER_PARSE_TOTAL_FIELD:
                    MI_CpuCopy8(cursor, &entry->mBlockCount, 2);
                    cursor = cursor + 2;
                    consumedBytes = consumedBytes + 2;
                    if (entry->mPacketKind == XFER_PACKET_HANDSHAKE_ANSWER) {
                        parseState = XFER_PARSE_SIZE_LIST;
                    }
                    continue;
                case XFER_PARSE_SIZE_LIST:
                    MI_CpuCopy8(cursor, &entry->mPacketSendChunkSize, 2);
                    MI_CpuCopy8(cursor + 2, &entry->mPacketReceiveChunkSize, 2);
                    if (WBT_GetOwnAid() != 0) {
                        SetSendChunkSize(entry->mPacketReceiveChunkSize);
                        SetReceiveChunkSize(entry->mPacketSendChunkSize);
                    }
                    packetKind = entry->mPacketKind;
                    switch (packetKind) {
                        case XFER_PACKET_HANDSHAKE_ASK:
                            WBTi_NotifySystemCallback(transfer, packetKind, entryIndex, XFER_RESULT_OK);
                            entry->mState = XFER_ENTRY_AWAITING_ANSWER;
                            return consumedBytes + 4;
                        case XFER_PACKET_HANDSHAKE_ANSWER:
                            if (transfer->mCurrentRequest.mCommand == XFER_COMMAND_HANDSHAKE) {
                                WBTi_NotifyCompletionCallback(transfer, packetKind, entryIndex);
                            }
                            return consumedBytes + 4;
                        default:
                            WBTi_NotifySystemCallback(transfer, XFER_EVENT_FAILED, entryIndex,
                                                      XFER_RESULT_KIND_REJECTED);
                            return consumedBytes + 4;
                    }
                case XFER_PARSE_TARGET_FIELD:
                    MI_CpuCopy8(cursor, &entry->mBlockId, 4);
                    cursor = cursor + 4;
                    consumedBytes = consumedBytes + 4;
                    packetKind = entry->mPacketKind;
                    switch (packetKind) {
                        case XFER_PACKET_ALL_HELD:
                            WBTi_NotifySystemCallback(transfer, packetKind, entryIndex, XFER_RESULT_OK);
                            entry->mState = XFER_ENTRY_AWAITING_ANSWER;
                            return consumedBytes;
                        case XFER_PACKET_ALL_HELD_ANSWER:
                            if (transfer->mCurrentRequest.mCommand == XFER_COMMAND_FETCH_DATA) {
                                if (transfer->mCurrentRequest.mData.mGet.mBlockId == entry->mBlockId) {
                                    WBTi_NotifyCompletionCallback(transfer, XFER_EVENT_DATA_ENDED, entryIndex);
                                }
                            } else if (transfer->mCurrentRequest.mCommand == XFER_COMMAND_FETCH_DETAILS) {
                                if (transfer->mCurrentRequest.mData.mGet.mBlockId == entry->mBlockId) {
                                    WBTi_NotifyCompletionCallback(transfer, XFER_EVENT_LAYOUT_ENDED, entryIndex);
                                }
                            }
                            return consumedBytes;
                        case XFER_PACKET_DATA_ASK:
                        case XFER_PACKET_DATA_CHUNK:
                        case XFER_PACKET_LAYOUT_ASK:
                        case XFER_PACKET_LAYOUT_ANSWER:
                            parseState = XFER_PARSE_SLICE_NUMBER;
                            continue;
                        default:
                            WBTi_NotifySystemCallback(transfer, XFER_EVENT_FAILED, entryIndex,
                                                      XFER_RESULT_KIND_REJECTED);
                            continue;
                    }
                case XFER_PARSE_SLICE_NUMBER:
                    MI_CpuCopy8(cursor, &entry->mChunkIndex, 4);
                    cursor = cursor + 4;
                    consumedBytes = consumedBytes + 4;
                    packetKind = entry->mPacketKind;
                    switch (packetKind) {
                        case XFER_PACKET_DATA_ASK:
                        case XFER_PACKET_LAYOUT_ASK:
                            entry->mState = XFER_ENTRY_AWAITING_ANSWER;
                            return consumedBytes;
                        case XFER_PACKET_DATA_CHUNK:
                        case XFER_PACKET_LAYOUT_ANSWER:
                            entry->mPayload = (u8 *) cursor;
                            if (transfer->mCurrentRequest.mCommand == XFER_COMMAND_FETCH_DATA ||
                                transfer->mCurrentRequest.mCommand == XFER_COMMAND_FETCH_DETAILS) {
                                if (entry->mBlockId == transfer->mCurrentRequest.mData.mGet.mBlockId) {
                                    if ((transfer->mCurrentRequest.mTargetBmp & (u16) (1 << entryIndex)) != 0) {
                                        if (IsChunkReceived(receiveBitmap, entry->mChunkIndex) == FALSE) {
                                            if (StoreReceivedChunk(receiveBitmap, entry->mChunkIndex,
                                                                   entry->mPayload) == TRUE) {
                                                MarkChunkReceived(receiveBitmap, entry->mChunkIndex);
                                            } else {
                                                WBTi_NotifySystemCallback(transfer, XFER_EVENT_FAILED, entryIndex,
                                                                          XFER_RESULT_CHUNK_BEYOND_END);
                                            }
                                        }
                                    }
                                }
                            }
                            return consumedBytes;
                        default:
                            WBTi_NotifySystemCallback(transfer, XFER_EVENT_FAILED, entryIndex,
                                                      XFER_RESULT_KIND_REJECTED);
                            continue;
                    }
                default:
                    WBTi_NotifySystemCallback(transfer, XFER_EVENT_FAILED, entryIndex, XFER_RESULT_STEP_REJECTED);
                    continue;
            }
        } while (consumedBytes < packetSize);
    }
    WBTi_NotifySystemCallback(transfer, XFER_EVENT_FAILED, entryIndex, XFER_RESULT_CUT_SHORT);
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
    if (entry->mState == XFER_ENTRY_AWAITING_ANSWER) {
        if (entry->mPacketKind == XFER_PACKET_HANDSHAKE_ASK) {
            blockCount = WBT_NumOfRegisteredBlock();
            ownPacketLength = WBT_GetOwnPacketLength();
            packetSize = WriteBlockCountReplyPacket(buffer, targetMask, entry->mRequestId, blockCount, ownPacketLength,
                                                    WBT_GetPeerPacketLength());
            entry->mState = XFER_ENTRY_FREE;
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
    if (entry->mState == XFER_ENTRY_AWAITING_ANSWER) {
        if (entry->mPacketKind == XFER_PACKET_ALL_HELD) {
            packetSize = WriteNoMissingChunkReplyPacket(buffer, targetMask, entry->mRequestId, entry->mBlockId);
            entry->mState = XFER_ENTRY_FREE;
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
    if (entry->mState == XFER_ENTRY_AWAITING_ANSWER) {
        if (entry->mPacketKind == XFER_PACKET_CUSTOM) {
            packetSize = WriteBytesReplyPacket(buffer, targetMask, entry->mRequestId);
            entry->mState = XFER_ENTRY_FREE;
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
    if (entry->mState == XFER_ENTRY_AWAITING_ANSWER) {
        if (WBT_GetOwnAid() == 0) {
            indexMask = 0xfffe;
        } else {
            indexMask = 1;
        }
        if (entry->mPacketKind == XFER_PACKET_DATA_ASK) {
            block = FindBlockById(entry->mBlockId);
            if (block != NULL) {
                chunkIndex = PickSendChunkIndex(entry->mBlockId, entry->mChunkIndex);
                if (chunkIndex != -1) {
                    if (block->mBlockType == XFER_BLOCK_TYPE_MEMORY) {
                        chunkAddress = WBTi_GetPacketBuffer(entry->mBlockId, chunkIndex);
                        packetSize = WriteBlockDataPacket(buffer, indexMask, entry->mRequestId, entry->mBlockId,
                                                          chunkIndex, chunkAddress, WBT_GetOwnPacketLength());
                    } else if (block->mBlockType == XFER_BLOCK_TYPE_SUPPLIED) {
                        callbackRecord->mData.mPrepareSendData.mBlockId = entry->mBlockId;
                        callbackRecord->mData.mPrepareSendData.mBlockSeqNo = chunkIndex;
                        callbackRecord->mData.mPrepareSendData.mOwnPacketSize = WBT_GetOwnPacketLength();
                        callbackRecord->mData.mPrepareSendData.mDataPtr = 0;
                        WBTi_NotifySystemCallback(transfer, XFER_EVENT_BEFORE_SEND, entryIndex, XFER_RESULT_OK);
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
            entry->mState = XFER_ENTRY_FREE;
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
    if (entry->mState == XFER_ENTRY_AWAITING_ANSWER) {
        if (WBT_GetOwnAid() == 0) {
            targetMask = 0xffff;
        } else {
            targetMask = 1;
        }
        if (entry->mPacketKind == XFER_PACKET_LAYOUT_ASK) {
            chunkBuffer = WBTi_GetPacketBuffer(entry->mBlockId, entry->mChunkIndex);
            if (chunkBuffer != 0) {
                packetSize = WriteBlockNodePacket(buffer, targetMask, entry->mRequestId, entry->mBlockId,
                                                  entry->mChunkIndex, chunkBuffer, WBT_GetOwnPacketLength());
                entry->mState = XFER_ENTRY_FREE;
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
    if (entry->mState == XFER_ENTRY_AWAITING_ANSWER) {
        if (WBT_GetOwnAid() == 0) {
            targetMask = 0xffff;
        } else {
            targetMask = 1;
        }
        if (entry->mPacketKind == XFER_PACKET_LAYOUT_ASK) {
            chunkBuffer = WBTi_GetPacketBuffer(entry->mBlockId, entry->mChunkIndex);
            packetSize = WriteBlockNodePacket(buffer, targetMask, entry->mRequestId, entry->mBlockId,
                                              entry->mChunkIndex, chunkBuffer, WBT_GetOwnPacketLength());
            entry->mState = XFER_ENTRY_FREE;
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
        case XFER_COMMAND_HANDSHAKE:
            value = WBT_GetOwnPacketLength();
            return WriteBlockCountRequestPacket(buffer, transfer->mCurrentRequest.mTargetBmp,
                                                transfer->mCurrentRequest.mMyCmdCounter, value,
                                                WBT_GetPeerPacketLength());
        case XFER_COMMAND_FETCH_DATA:
        case XFER_COMMAND_FETCH_DETAILS:
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
                        if (transfer->mCurrentRequest.mCommand == XFER_COMMAND_FETCH_DATA) {
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
        case XFER_COMMAND_SEND_CUSTOM:
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
    if (transfer->mCurrentRequest.mCommand != XFER_COMMAND_UNUSED) {
        return 0;
    }
    if (nextRequest->mCommand == XFER_COMMAND_UNUSED) {
        return 0;
    }
    AdvanceRequestId();
    value = GetRequestId();
    switch (nextRequest->mCommand) {
        case XFER_COMMAND_HANDSHAKE:
            MIi_CpuCopy32(nextRequest, transfer, 0x9c);
            transfer->mCurrentRequest.mMyCmdCounter = value;
            value = WBT_GetOwnPacketLength();
            packetSize =
                WriteBlockCountRequestPacket(buffer, transfer->mCurrentRequest.mTargetBmp,
                                             transfer->mCurrentRequest.mMyCmdCounter, value, WBT_GetPeerPacketLength());
            break;
        case XFER_COMMAND_FETCH_DETAILS:
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
            if (nextRequest->mCommand == XFER_COMMAND_FETCH_DATA) {
                packetSize = WriteBlockDataRequestPacket(buffer, transfer->mCurrentRequest.mTargetBmp,
                                                         transfer->mCurrentRequest.mMyCmdCounter,
                                                         transfer->mCurrentRequest.mData.mGet.mBlockId, 0);
            } else {
                packetSize = WriteBlockNodeRequestPacket(buffer, transfer->mCurrentRequest.mTargetBmp,
                                                         transfer->mCurrentRequest.mMyCmdCounter,
                                                         transfer->mCurrentRequest.mData.mGet.mBlockId, 0);
            }
            break;
        case XFER_COMMAND_FETCH_DATA:
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
            if (nextRequest->mCommand == XFER_COMMAND_FETCH_DATA) {
                packetSize = WriteBlockDataRequestPacket(buffer, transfer->mCurrentRequest.mTargetBmp,
                                                         transfer->mCurrentRequest.mMyCmdCounter,
                                                         transfer->mCurrentRequest.mData.mGet.mBlockId, 0);
            } else {
                packetSize = WriteBlockNodeRequestPacket(buffer, transfer->mCurrentRequest.mTargetBmp,
                                                         transfer->mCurrentRequest.mMyCmdCounter,
                                                         transfer->mCurrentRequest.mData.mGet.mBlockId, 0);
            }
            break;
        case XFER_COMMAND_SEND_CUSTOM:
            MIi_CpuCopy32(nextRequest, transfer, 0x9c);
            transfer->mCurrentRequest.mMyCmdCounter = value;
            packetSize = WriteBytesPacket(
                buffer, transfer->mCurrentRequest.mTargetBmp, transfer->mCurrentRequest.mMyCmdCounter,
                &transfer->mCurrentRequest.mData.mUserDataWord, transfer->mCurrentRequest.mData.mUserData.mSize);
            break;
    }
    nextRequest->mCommand = XFER_COMMAND_UNUSED;
    return packetSize;
}

#pragma thumb off
