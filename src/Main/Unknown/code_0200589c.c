#include "Main/Unknown/code_0200589c.h"
#include "Main/Unknown/code_02006380.h"
#include "Main/Unknown/code_0200635c.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_020070f0.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02133000.h"
#include "code_02133048.h"
#include "code_0214d018.h"

#pragma thumb on

// Returns the index of the next chunk whose bit is still clear after the last received one, or -1 when all have
// arrived.
s32 WBTi_FindBitmapIndex(WBTPacketBitmap *a) {
    s32 v1;
    s32 v2;
    s32 v3;
    u32 *v4;
    s32 v6;
    u32 *v5;
    v1 = a->mCurrent + 1;
    v6 = a->mTotal;
    if (v1 >= v6) {
        v1 = 0;
    }
    v2 = v1;
    v5 = a->mBitmap;
    v4 = v5 + (v1 >> 5);
    v3 = v1 & 0x1f;
    do {
        if ((*v4 & (1 << v3)) == 0) {
            goto found;
        }
        v1 = v1 + 1;
        if (v1 < v6) {
            v3 = v3 + 1;
            if (v3 > 0x1f) {
                v3 = 0;
                v4 = v4 + 1;
            }
        } else {
            v1 = 0;
            v3 = v1;
            v4 = v5;
        }
    } while (v1 != v2);
    goto fail;
found:
    a->mPickedChunkIndex = v1;
    return v1;
fail:
    return -1;
}

// Copies chunk b into the buffer; FALSE when b is past the last chunk.
BOOL StoreReceivedChunk(WBTPacketBitmap *a, s32 b, const u8 *c) {
    u32 v1;
    u8 *v2;
    u32 v3;
    v1 = WBT_GetPeerPacketLength();
    v2 = a->mBuffer;
    if (b < a->mTotal) {
        if (b == a->mTotal - 1) {
            v3 = _s32_div_f(a->mLength, v1) >> 32;
            if (v3 != 0) {
                MI_CpuCopy8(c, v2 + b * v1, v3);
            } else {
                MI_CpuCopy8(c, v2 + b * v1, v1);
            }
        } else {
            MI_CpuCopy8(c, v2 + b * v1, v1);
        }
    } else {
        return FALSE;
    }
    return TRUE;
}

// Fills the shared record and calls the transfer's callback once per request id (code 13 always).
void WBTi_NotifySystemCallback(BlockTransfer *a, s32 b, s32 c, u32 d) {
    BlockTransferEntry *v2;
    WBTCommand *v1;
    v1 = &a->mCallbackRecord;
    v2 = &a->mEntries[c];
    if (b == 13 || v2->mRequestId != v2->mLastCallbackId) {
        v1->mCommand = 12;
        v1->mPeerBmp = 1 << c;
        v2->mLastCallbackId = v2->mRequestId;
        v1->mPeerCmdCounter = v2->mRequestId;
        v1->mResult = d;
        switch (b) {
            case 8:
                v1->mUnk_14.w.mUnk_14 = v2->mBlockId;
                break;
            case 2:
                v1->mUnk_14.h.mUnk_14 = v2->mBlockCount;
                v1->mUnk_14.h.mUnk_16 = v2->mPacketSendChunkSize;
                v1->mUnk_14.h.mUnk_18 = v2->mPacketReceiveChunkSize;
                break;
            case 10:
                if (v2->mByteCount > 9) {
                    v1->mUnk_14.b.mUnk_1d = 0;
                } else {
                    v1->mUnk_14.b.mUnk_1d = v2->mByteCount;
                    MI_CpuCopy8(v2->mPayload, &v1->mUnk_14.w.mUnk_14, v1->mUnk_14.b.mUnk_1d);
                }
                break;
            case 12:
            case 14:
                break;
        }
        v1->mEvent = b;
        if (v1->mCallback != NULL) {
            v1->mCallback(v1);
        }
    }
}

// A reply from index c: clears its bit in the current request, calls the request's callback and ends the request when
// no index is left.
void WBTi_NotifyCompletionCallback(BlockTransfer *a, s32 b, s32 c) {
    u16 v1;
    u8 v4;
    BlockTransferEntry *v2;
    v2 = &a->mEntries[c];
    v1 = 1 << c;
    a->mCurrentRequest.mPeerBmp = v1;
    v4 = v2->mRequestId;
    if (a->mCurrentRequest.mMyCmdCounter == v4) {
        a->mCurrentRequest.mPeerCmdCounter = v4;
        if ((a->mCurrentRequest.mTargetBmp & v1) != 0) {
            a->mCurrentRequest.mTargetBmp &= ~v1;
            switch (b) {
                case 3:
                    a->mCurrentRequest.mUnk_14.h.mUnk_14 = v2->mBlockCount;
                    a->mCurrentRequest.mUnk_14.h.mUnk_16 = v2->mPacketSendChunkSize;
                    a->mCurrentRequest.mUnk_14.h.mUnk_18 = v2->mPacketReceiveChunkSize;
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
            a->mCurrentRequest.mEvent = b;
            if (a->mCurrentRequest.mCallback != NULL) {
                a->mCurrentRequest.mCallback(&a->mCurrentRequest);
            }
        }
        if (a->mCurrentRequest.mTargetBmp == 0) {
            a->mCurrentRequest.mCommand = 0;
        }
    }
}

// Reads one packet from index b field by field into its entry, answers or calls back as the kind needs, and returns the
// bytes used.
u32 WBT_CallPacketRecvHook(BlockTransfer *a, s32 b, const u8 *c, s32 d) {
    s32 v1;
    u32 v2;
    u32 v3;
    BOOL v4;
    BlockTransferEntry *v5;
    WBTPacketBitmap *v6;
    v1 = 0;
    v2 = 1;
    v5 = &a->mEntries[b];
    v6 = &a->mEntries[b].mReceive;
    v5->mUnk_00 = 1;
    if (d == 0) {
        return 0;
    }
    if (d > 0) {
        do {
            switch (v2) {
                case 1:
                    MI_CpuCopy8(c, &v5->mPacketKind, 1);
                    c = c + 1;
                    v1 = v1 + 1;
                    v2 = 2;
                    continue;
                case 2:
                    MI_CpuCopy8(c, &v5->mIndexMask, 2);
                    c = c + 2;
                    v1 = v1 + 2;
                    v2 = v5->mIndexMask;
                    if (WBT_GetOwnAid() == -1) {
                        v4 = FALSE;
                    } else {
                        v2 = v2 & (1 << WBT_GetOwnAid());
                        if (v2 != 0) {
                            v4 = TRUE;
                        } else {
                            v4 = FALSE;
                        }
                    }
                    if (v4 == FALSE) {
                        return v1;
                    }
                    v2 = 3;
                    continue;
                case 3:
                    MI_CpuCopy8(c, &v5->mRequestId, 1);
                    c = c + 1;
                    v1 = v1 + 1;
                    switch (v5->mPacketKind) {
                        case 1:
                            return v1;
                        case 2:
                            v2 = 5;
                            continue;
                        case 3:
                            v2 = 4;
                            continue;
                        case 11:
                            if (a->mCurrentRequest.mCommand == 10) {
                                WBTi_NotifyCompletionCallback(a, v5->mPacketKind, b);
                            }
                            return v1;
                        case 10:
                            v2 = 10;
                            continue;
                        default:
                            v2 = 7;
                            continue;
                    }
                case 10:
                    MI_CpuCopy8(c, &v5->mByteCount, 1);
                    c = c + 1;
                    v1 = v1 + 1;
                    v2 = 9;
                    continue;
                case 9:
                    v5->mPayload = (u8 *) c;
                    WBTi_NotifySystemCallback(a, v5->mPacketKind, b, 0);
                    v5->mUnk_00 = 2;
                    v1 = v1 + 9;
                    return v1;
                case 4:
                    MI_CpuCopy8(c, &v5->mBlockCount, 2);
                    c = c + 2;
                    v1 = v1 + 2;
                    if (v5->mPacketKind == 3) {
                        v2 = 5;
                    }
                    continue;
                case 5:
                    MI_CpuCopy8(c, &v5->mPacketSendChunkSize, 2);
                    MI_CpuCopy8(c + 2, &v5->mPacketReceiveChunkSize, 2);
                    if (WBT_GetOwnAid() != 0) {
                        SetSendChunkSize(v5->mPacketReceiveChunkSize);
                        SetReceiveChunkSize(v5->mPacketSendChunkSize);
                    }
                    v3 = v5->mPacketKind;
                    switch (v3) {
                        case 2:
                            WBTi_NotifySystemCallback(a, v3, b, 0);
                            v5->mUnk_00 = 2;
                            return v1 + 4;
                        case 3:
                            if (a->mCurrentRequest.mCommand == 2) {
                                WBTi_NotifyCompletionCallback(a, v3, b);
                            }
                            return v1 + 4;
                        default:
                            WBTi_NotifySystemCallback(a, 15, b, 3);
                            return v1 + 4;
                    }
                case 7:
                    MI_CpuCopy8(c, &v5->mBlockId, 4);
                    c = c + 4;
                    v1 = v1 + 4;
                    v3 = v5->mPacketKind;
                    switch (v3) {
                        case 8:
                            WBTi_NotifySystemCallback(a, v3, b, 0);
                            v5->mUnk_00 = 2;
                            return v1;
                        case 9:
                            if (a->mCurrentRequest.mCommand == 4) {
                                if (a->mCurrentRequest.mUnk_14.w.mUnk_14 == v5->mBlockId) {
                                    WBTi_NotifyCompletionCallback(a, 5, b);
                                }
                            } else if (a->mCurrentRequest.mCommand == 6) {
                                if (a->mCurrentRequest.mUnk_14.w.mUnk_14 == v5->mBlockId) {
                                    WBTi_NotifyCompletionCallback(a, 7, b);
                                }
                            }
                            return v1;
                        case 4:
                        case 5:
                        case 6:
                        case 7:
                            v2 = 8;
                            continue;
                        default:
                            WBTi_NotifySystemCallback(a, 15, b, 3);
                            continue;
                    }
                case 8:
                    MI_CpuCopy8(c, &v5->mChunkIndex, 4);
                    c = c + 4;
                    v1 = v1 + 4;
                    v3 = v5->mPacketKind;
                    switch (v3) {
                        case 4:
                        case 6:
                            v5->mUnk_00 = 2;
                            return v1;
                        case 5:
                        case 7:
                            v5->mPayload = (u8 *) c;
                            if (a->mCurrentRequest.mCommand == 4 || a->mCurrentRequest.mCommand == 6) {
                                if (v5->mBlockId == a->mCurrentRequest.mUnk_14.w.mUnk_14) {
                                    if ((a->mCurrentRequest.mTargetBmp & (u16) (1 << b)) != 0) {
                                        if (IsChunkReceived(v6, v5->mChunkIndex) == FALSE) {
                                            if (StoreReceivedChunk(v6, v5->mChunkIndex, v5->mPayload) == TRUE) {
                                                MarkChunkReceived(v6, v5->mChunkIndex);
                                            } else {
                                                WBTi_NotifySystemCallback(a, 15, b, 6);
                                            }
                                        }
                                    }
                                }
                            }
                            return v1;
                        default:
                            WBTi_NotifySystemCallback(a, 15, b, 3);
                            continue;
                    }
                default:
                    WBTi_NotifySystemCallback(a, 15, b, 4);
                    continue;
            }
        } while (v1 < d);
    }
    WBTi_NotifySystemCallback(a, 15, b, 5);
    return v1;
}

s32 ReplyToBlockCountRequest(BlockTransfer *a, s32 b, u8 *c, s32 d) {
    s32 v1;
    s32 v3;
    u32 v4;
    BlockTransferEntry *v5;
    u16 v2;
    v1 = 0;
    v5 = &a->mEntries[b];
    v2 = 1 << b;
    if (v5->mUnk_00 == 2) {
        if (v5->mPacketKind == 2) {
            v3 = WBT_NumOfRegisteredBlock();
            v4 = WBT_GetOwnPacketLength();
            v1 = WriteBlockCountReplyPacket(c, v2, v5->mRequestId, v3, v4, WBT_GetPeerPacketLength());
            v5->mUnk_00 = 1;
        }
    }
    return v1;
}

s32 ReplyToNoMissingChunk(BlockTransfer *a, s32 b, u8 *c, s32 d) {
    s32 v1;
    u16 v2;
    BlockTransferEntry *v3;
    v1 = 0;
    v3 = &a->mEntries[b];
    v2 = 1 << b;
    if (v3->mUnk_00 == 2) {
        if (v3->mPacketKind == 8) {
            v1 = WriteNoMissingChunkReplyPacket(c, v2, v3->mRequestId, v3->mBlockId);
            v3->mUnk_00 = 1;
        }
    }
    return v1;
}

s32 ReplyToBytesPacket(BlockTransfer *a, s32 b, u8 *c, s32 d) {
    s32 v1;
    u16 v2;
    BlockTransferEntry *v3;
    v1 = 0;
    v3 = &a->mEntries[b];
    v2 = 1 << b;
    if (v3->mUnk_00 == 2) {
        if (v3->mPacketKind == 10) {
            v1 = WriteBytesReplyPacket(c, v2, v3->mRequestId);
            v3->mUnk_00 = 1;
        }
    }
    return v1;
}

s32 ReplyToBlockDataRequest(BlockTransfer *a, s32 b, u8 *c, s32 d) {
    s32 v1;
    u32 v2;
    s32 v3;
    u32 v4;
    WBTBlockInfoList *v5;
    WBTCommand *v6;
    BlockTransferEntry *v7;
    v1 = 0;
    v6 = &a->mCallbackRecord;
    v7 = &a->mEntries[b];
    if (v7->mUnk_00 == 2) {
        if (WBT_GetOwnAid() == 0) {
            v2 = 0xfffe;
        } else {
            v2 = 1;
        }
        if (v7->mPacketKind == 4) {
            v5 = FindBlockById(v7->mBlockId);
            if (v5 != NULL) {
                v3 = PickSendChunkIndex(v7->mBlockId, v7->mChunkIndex);
                if (v3 != -1) {
                    if (v5->mBlockType == 0) {
                        v4 = WBTi_GetPacketBuffer(v7->mBlockId, v3);
                        v1 =
                            WriteBlockDataPacket(c, v2, v7->mRequestId, v7->mBlockId, v3, v4, WBT_GetOwnPacketLength());
                    } else if (v5->mBlockType == 1) {
                        v6->mUnk_14.w.mUnk_14 = v7->mBlockId;
                        v6->mUnk_14.w.mUnk_18 = v3;
                        v6->mUnk_14.b.mUnk_20 = WBT_GetOwnPacketLength();
                        v6->mUnk_14.w.mUnk_1c[0] = 0;
                        WBTi_NotifySystemCallback(a, 13, b, 0);
                        if (v6->mUnk_14.w.mUnk_1c[0] != 0) {
                            v1 = WriteBlockDataPacket(c, v2, v7->mRequestId, v6->mUnk_14.w.mUnk_14,
                                                      v6->mUnk_14.w.mUnk_18, v6->mUnk_14.w.mUnk_1c[0],
                                                      v6->mUnk_14.b.mUnk_20);
                        }
                    }
                }
            }
            v7->mUnk_00 = 1;
        }
    }
    return v1;
}

// Sends nothing while the chunk address is 0.
s32 ReplyToBlockNodeRequest(BlockTransfer *a, s32 b, u8 *c, s32 d) {
    s32 v1;
    u32 v2;
    u32 v3;
    BlockTransferEntry *v4;
    v1 = 0;
    v4 = &a->mEntries[b];
    if (v4->mUnk_00 == 2) {
        if (WBT_GetOwnAid() == 0) {
            v2 = 0xffff;
        } else {
            v2 = 1;
        }
        if (v4->mPacketKind == 6) {
            v3 = WBTi_GetPacketBuffer(v4->mBlockId, v4->mChunkIndex);
            if (v3 != 0) {
                v1 = WriteBlockNodePacket(c, v2, v4->mRequestId, v4->mBlockId, v4->mChunkIndex, v3,
                                          WBT_GetOwnPacketLength());
                v4->mUnk_00 = 1;
            }
        }
    }
    return v1;
}

// Sends the node packet even when the chunk address is 0.
s32 ReplyToBlockNodeRequestAlways(BlockTransfer *a, s32 b, u8 *c, s32 d) {
    s32 v1;
    u32 v2;
    u32 v3;
    BlockTransferEntry *v4;
    v1 = 0;
    v4 = &a->mEntries[b];
    if (v4->mUnk_00 == 2) {
        if (WBT_GetOwnAid() == 0) {
            v2 = 0xffff;
        } else {
            v2 = 1;
        }
        if (v4->mPacketKind == 6) {
            v3 = WBTi_GetPacketBuffer(v4->mBlockId, v4->mChunkIndex);
            v1 = WriteBlockNodePacket(c, v2, v4->mRequestId, v4->mBlockId, v4->mChunkIndex, v3,
                                      WBT_GetOwnPacketLength());
            v4->mUnk_00 = 1;
        }
    }
    return v1;
}

// Writes the packet of the running request again on every call.
s32 WBTi_CheckRequest(BlockTransfer *a, u8 *b, s32 c) {
    s32 v1;
    s32 i;
    u32 v2;
    WBTPacketBitmap *v3;
    s32 v4;
    u16 v5;
    v1 = 0;
    switch (a->mCurrentRequest.mCommand) {
        case 2:
            v2 = WBT_GetOwnPacketLength();
            return WriteBlockCountRequestPacket(b, a->mCurrentRequest.mTargetBmp, a->mCurrentRequest.mMyCmdCounter, v2,
                                                WBT_GetPeerPacketLength());
        case 4:
        case 6:
            for (i = 0, v3 = &a->mEntries[0].mReceive; i < 16; i++) {
                v2 = 1;
                v2 = v2 << i;
                if ((a->mCurrentRequest.mTargetBmp & (u16) v2) != 0) {
                    v4 = WBTi_FindBitmapIndex(v3);
                    if (v4 == -1) {
                        v1 = WriteNoMissingChunkPacket(b, v2, a->mCurrentRequest.mMyCmdCounter,
                                                       a->mCurrentRequest.mUnk_14.w.mUnk_14);
                    } else {
                        v5 = a->mCurrentRequest.mTargetBmp;
                        if (a->mCurrentRequest.mCommand == 4) {
                            v1 = WriteBlockDataRequestPacket(b, v5, a->mCurrentRequest.mMyCmdCounter,
                                                             a->mCurrentRequest.mUnk_14.w.mUnk_14, v4);
                        } else {
                            v1 = WriteBlockNodeRequestPacket(b, v5, a->mCurrentRequest.mMyCmdCounter,
                                                             a->mCurrentRequest.mUnk_14.w.mUnk_14, v4);
                        }
                    }
                    if (v1 != 0) {
                        return v1;
                    }
                }
                v3 = OFFSET_PTR(WBTPacketBitmap, v3, 0x68);
            }
            return v1;
        case 10:
            v1 = WriteBytesPacket(b, a->mCurrentRequest.mTargetBmp, a->mCurrentRequest.mMyCmdCounter,
                                  &a->mCurrentRequest.mUnk_14.w.mUnk_14, a->mCurrentRequest.mUnk_14.b.mUnk_1d);
            break;
    }
    return v1;
}

// Starts the waiting request when none is running and writes its first packet.
s32 WBTi_SwitchNextCommand(BlockTransfer *a, u8 *b, s32 c) {
    s32 v1;
    u32 v2;
    s32 i;
    WBTCommand *v3;
    WBTPacketBitmap *v4;
    WBTPacketBitmap *v5;
    v1 = 0;
    v3 = &a->mNextRequest;
    if (a->mCurrentRequest.mCommand != 0) {
        return 0;
    }
    if (v3->mCommand == 0) {
        return 0;
    }
    AdvanceRequestId();
    v2 = GetRequestId();
    switch (v3->mCommand) {
        case 2:
            MIi_CpuCopy32(v3, a, 0x9c);
            a->mCurrentRequest.mMyCmdCounter = v2;
            v2 = WBT_GetOwnPacketLength();
            v1 = WriteBlockCountRequestPacket(b, a->mCurrentRequest.mTargetBmp, a->mCurrentRequest.mMyCmdCounter, v2,
                                              WBT_GetPeerPacketLength());
            break;
        case 6:
            MIi_CpuCopy32(v3, a, 0x9c);
            a->mCurrentRequest.mMyCmdCounter = v2;
            for (i = 0, v4 = &a->mEntries[0].mReceive; i < 16; i++) {
                if (((a->mCurrentRequest.mTargetBmp >> i) & 1) != 0) {
                    WBTi_InitBitmap(v4, a->mCurrentRequest.mUnk_14.w.mUnk_18, v4->mInlineChunkBitmap,
                                    a->mCurrentRequest.mUnk_14.w.mUnk_1c[i]);
                }
                v4 = OFFSET_PTR(WBTPacketBitmap, v4, 0x68);
            }
            if (v3->mCommand == 4) {
                v1 = WriteBlockDataRequestPacket(b, a->mCurrentRequest.mTargetBmp, a->mCurrentRequest.mMyCmdCounter,
                                                 a->mCurrentRequest.mUnk_14.w.mUnk_14, 0);
            } else {
                v1 = WriteBlockNodeRequestPacket(b, a->mCurrentRequest.mTargetBmp, a->mCurrentRequest.mMyCmdCounter,
                                                 a->mCurrentRequest.mUnk_14.w.mUnk_14, 0);
            }
            break;
        case 4:
            MIi_CpuCopy32(v3, a, 0x9c);
            a->mCurrentRequest.mMyCmdCounter = v2;
            for (i = 0, v5 = &a->mEntries[0].mReceive; i < 16; i++) {
                if (((a->mCurrentRequest.mTargetBmp >> i) & 1) != 0) {
                    WBTi_InitBitmap(v5, a->mCurrentRequest.mUnk_14.w.mUnk_18, a->mCurrentRequest.mChunkBitmaps[i],
                                    a->mCurrentRequest.mUnk_14.w.mUnk_1c[i]);
                }
                v5 = OFFSET_PTR(WBTPacketBitmap, v5, 0x68);
            }
            if (v3->mCommand == 4) {
                v1 = WriteBlockDataRequestPacket(b, a->mCurrentRequest.mTargetBmp, a->mCurrentRequest.mMyCmdCounter,
                                                 a->mCurrentRequest.mUnk_14.w.mUnk_14, 0);
            } else {
                v1 = WriteBlockNodeRequestPacket(b, a->mCurrentRequest.mTargetBmp, a->mCurrentRequest.mMyCmdCounter,
                                                 a->mCurrentRequest.mUnk_14.w.mUnk_14, 0);
            }
            break;
        case 10:
            MIi_CpuCopy32(v3, a, 0x9c);
            a->mCurrentRequest.mMyCmdCounter = v2;
            v1 = WriteBytesPacket(b, a->mCurrentRequest.mTargetBmp, a->mCurrentRequest.mMyCmdCounter,
                                  &a->mCurrentRequest.mUnk_14.w.mUnk_14, a->mCurrentRequest.mUnk_14.b.mUnk_1d);
            break;
    }
    v3->mCommand = 0;
    return v1;
}

#pragma thumb off
