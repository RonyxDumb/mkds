#include "Main/Unknown/code_02050300.h"

#include "Main/Unknown/code_02050080.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0204b000.h"
#include "Main/Unknown/code_0204bca0.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_02052000.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_02053000.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02055000.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02057fe4.h"
#include "Main/Unknown/code_02059000.h"
#include "Main/Unknown/code_0205928c.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200eddc.h"
#include "code_02142eac.h"
#include "code_021445e0.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0211d4a8.h"

static inline u32 func_02050650_inline(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

void DisconnectChildren(u32 aidBitmap) {
    gConnectionWork->mStep = 0x10;
    gConnectionWork->mRequestPending = 1;
    if (WM_DisconnectChildren(DisconnectChildrenCallback, aidBitmap) != 7) {
        return;
    }
    if (gConnectionWork->mState == 9) {
        if (func_02050650_inline() == 1) {
            gConnectionWork->mRemovedChildMask = 0;
        }
    }
    gConnectionWork->mRequestPending = 0;
}

void DisconnectChildrenCallback(Unk021425e8 *event) {
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode != 0 && event->mResultCode != 7) {
        return;
    }
    if (func_02050650_inline() == 1) {
        switch (gConnectionWork->mState) {
            case 8:
            case 9:
                gConnectionWork->mLeftParticipantMask[0] =
                    gConnectionWork->mLeftParticipantMask[0] | gConnectionWork->mRemovedChildMask;
                break;
        }
    }
    gConnectionWork->mRemovedChildMask = 0;
}

void EndDataSharing(void) {
    s32 result;

    gConnectionWork->mStep = 0x11;
    gConnectionWork->mRequestPending = 1;
    result = WM_EndDataSharing(gConnectionWork->mSharingInfo);
    gConnectionWork->mRequestPending = 0;
    if (result == 0) {
        return;
    }
    StopConnection();
}

void EndMP(void) {
    gConnectionWork->mStep = 0x12;
    gConnectionWork->mRequestPending = 1;
    if (WM_EndMP(EndMPCallback) == 2) {
        return;
    }
    StopConnection();
}

void EndMPCallback(Unk021425e8 *event) {
    ConnectionWork *connection;

    gConnectionWork->mRequestPending = 0;
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SEND_READY;
    if (event->mResultCode != 0) {
        StopConnection();
        return;
    }
    connection = gConnectionWork;
    if (connection->mState == 0xb) {
        connection->mState = 0xc;
    }
}

void EndParent(void) {
    gConnectionWork->mStep = 0x13;
    gConnectionWork->mRequestPending = 1;
    if (WM_EndParent(EndParentCallback) == 2) {
        return;
    }
    StopConnection();
}

void EndParentCallback(Unk021425e8 *event) {
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode != 0) {
        StopConnection();
    } else {
        ResetConnectionData();
    }
}

void Disconnect(void) {
    s32 result;
    s32 i;
    ChildList *children;
    ChildEntry *child;

    result = 7;
    children = &gConnectionWork->mChildren;
    switch (func_02050650_inline()) {
        case 1:
            for (i = 0, child = children->mEntries; i < children->mChildCount; i++, child++) {
                if (child->mAid != 0xffff) {
                    gConnectionWork->mChildren.mDisconnectingIndex = i;
                    gConnectionWork->mStep = 0x14;
                    gConnectionWork->mRequestPending = 1;
                    result = WM_Disconnect(DisconnectCallback, child->mAid);
                    break;
                }
            }
            break;
        case 2:
            gConnectionWork->mStep = 0x14;
            gConnectionWork->mRequestPending = 1;
            result = WM_Disconnect(DisconnectCallback, 0);
            break;
    }
    switch (result) {
        case 0:
        case 7:
            gConnectionWork->mRequestPending = 0;
            break;
        case 2:
            if (func_02050650_inline() == 2) {
                gConnectionWork->mOperationFlags |= CONNECTION_OPERATION_DISCONNECTING;
            }
            break;
        default:
            StopConnection();
            break;
    }
}

void DisconnectCallback(Unk021425e8 *event) {
    u16 aid;

    switch (event->mResultCode) {
        case 0:
        case 7:
            gConnectionWork->mRequestPending = 0;
            switch (gConnectionWork->mConnectionMode) {
                case 1:
                    aid = gConnectionWork->mChildren.mEntries[gConnectionWork->mChildren.mDisconnectingIndex].mAid;
                    RemoveChild(aid);
                    if (func_02050650_inline() == 1) {
                        if (gConnectionWork->mState == 9) {
                            gConnectionWork->mLeftParticipantMask[0] |= 1 << aid;
                        }
                    }
                    gConnectionWork->mChildren.mDisconnectingIndex = -1;
                    break;
                case 2:
                    gConnectionWork->mOperationFlags &= ~CONNECTION_OPERATION_DISCONNECTING;
                    ResetConnectionData();
                    break;
            }
            break;
        case 1:
            if ((gConnectionWork->mOperationFlags & CONNECTION_OPERATION_DISCONNECTING) != 0) {
                gConnectionWork->mOperationFlags &= ~CONNECTION_OPERATION_DISCONNECTING;
                ResetConnectionData();
                gConnectionWork->mRequestPending = 0;
            } else {
                StopConnection();
            }
            break;
        default:
            StopConnection();
            break;
    }
}

BOOL IsMultiBootSetupStarted(void) {
    return (gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0;
}

s32 GetConnectionMode(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

static inline u32 func_02050ec0_inline(void) {
    return IsMultiBootSetupStarted() != FALSE && (GetConnectionMode() == 1 || ConnectionMB_IsMultiBootChild() != FALSE);
}

BOOL ConnectionMB_IsMultiBootChild(void) {
    return gBootInfo->mUnk_00 == 2;
}

void SetStepAndRequestPending(s32 a) {
    gConnectionWork->mStep = a;
    gConnectionWork->mRequestPending = 1;
}

// WM_End first; when it does not return 2, the 0x100 and 0x200 flag paths or WM_Reset run instead.
void End(void) {
    ConnectionWork *connection;
    u32 flags;

    gConnectionWork->mStep = 0x15;
    gConnectionWork->mRequestPending = 1;
    if (WM_End(EndCallback) == 2) {
        return;
    }
    connection = gConnectionWork;
    flags = connection->mFlags;
    if ((flags & CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER) != 0) {
        connection->mStep = 0x26;
        gConnectionWork->mRequestPending = 1;
        if (func_02050ec0_inline() != 0) {
            StopRomArchive();
            gConnectionWork->mFlags &= ~CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER;
        }
        gConnectionWork->mRequestPending = 0;
        return;
    }
    if ((flags & CONNECTION_FLAG_BLOCK_TRANSFER) != 0) {
        StopBlockTransferStep();
        return;
    }
    connection->mStep = 2;
    gConnectionWork->mRequestPending = 1;
    if (WM_Reset(ResetCallback) == 2) {
        return;
    }
    gConnectionWork->mStep = 0x15;
    gConnectionWork->mRequestPending = 1;
    if (WM_End(EndCallback) == 2) {
        return;
    }
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER) != 0) {
        StopRomArchiveTransfer();
        return;
    }
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_BLOCK_TRANSFER) != 0) {
        StopBlockTransferStep();
        return;
    }
    SetStepAndRequestPending(2);
    if (WM_Reset(ResetCallback) == 2) {
        return;
    }
    End();
}

void EndCallback(Unk021425e8 *event) {
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode != 0) {
        gConnectionWork->mErrorCode = 8;
        gConnectionWork->mRequestPending = 0;
    } else {
        gConnectionWork->mConnectionMode = 0;
    }
}

void SetRequestErrorCode(s32 errorCode) {
    gConnectionWork->mErrorCode = errorCode;
    gConnectionWork->mRequestPending = 0;
}

void AddChild(u32 aid, u8 *b, PlayerRecord *playerEntry) {
    ChildList *children;

    children = &gConnectionWork->mChildren;
    if (children->mChildCount >= 7) {
        return;
    }
    children->mEntries[aid - 1].mAid = aid;
    children->mChildCount += 1;
    children->mChildMask |= 1 << aid;
    children->mEntries[0].mUnk_00[0] = b[0];
    children->mEntries[0].mUnk_00[1] = b[1];
    children->mEntries[0].mUnk_00[2] = b[2];
    children->mEntries[0].mUnk_00[3] = b[3];
    children->mEntries[0].mUnk_00[4] = b[4];
    children->mEntries[0].mUnk_00[5] = b[5];
    MI_CpuCopy8(playerEntry, &gConnectionWork->mPlayerRecords[aid], 0x14);
    gConnectionWork->mStatusFlags |= CONNECTION_STATUS_CHILDREN_CHANGED;
    if ((playerEntry->mEmblem[0] & 1) != 0) {
        gConnectionWork->mGroupSendMask |= 1 << aid;
    }
}

static inline void func_0205081c_inline2(u16 v) {
    MPStateMachine *p = &gConnectionWork->mMPStateMachine;
    p->mStateMachine.mNextState = v;
    p->mStateMachine.mNextStateRequested = 1;
}

static inline void func_0205081c_inline(u8 v) {
    u32 r = 0;
    u32 b;

    if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
        b = 1;
        if (func_02050650_inline() != 1) {
            if (gBootInfo->mUnk_00 != 2) {
                b = 0;
            }
        }
        if (b != 0) {
            r = 1;
        }
    }
    if (r == 0) {
        return;
    }
    if (func_02050650_inline() != 1) {
        return;
    }
    SetRomArchiveGroupSendMask(v);
}

static inline void func_02050b88_inline(u16 v1) {
    u16 i;
    u32 f;

    for (i = 0; i < 8; i++) {
        if ((v1 & (1 << i)) != 0) {
            f = gConnectionWork->mState == 9 ? 1 : 0;
            if (func_02050650_inline() == 1) {
                gConnectionWork->mChildren.mChildMask &= ~(1 << i);
                if (f != 0) {
                    gConnectionWork->mRemovedChildMask |= 1 << i;
                }
            }
            gConnectionWork->mGroupSendMask &= ~(1 << i);
        }
    }
    if (func_02050650_inline() != 1) {
        return;
    }
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER) == 0) {
        return;
    }
    func_0205081c_inline(gConnectionWork->mGroupSendMask);
}

void RemoveChild(u32 aid) {
    ChildList *children;

    children = &gConnectionWork->mChildren;
    if (children->mEntries[aid - 1].mAid == 0xffff) {
        return;
    }
    children->mEntries[aid - 1].mAid = 0xffff;
    children->mChildCount -= 1;
    func_02050b88_inline(1 << aid);
    gConnectionWork->mStatusFlags |= CONNECTION_STATUS_CHILDREN_CHANGED;
    switch (gConnectionWork->mState) {
        case 9:
            if (children->mChildCount < 1) {
                gConnectionWork->mErrorCode = 0;
                gConnectionWork->mRequestPending = 0;
            }
            break;
        case 7:
        case 8:
            gConnectionWork->mErrorCode = 0;
            gConnectionWork->mRequestPending = 0;
            break;
    }
}

void ProcessMPData(u32 aid, MPMessage *message) {
    switch (message->mKind) {
        case 3:
            gConnectionWork->mSyncDoneChildMask &= ~(1 << aid);
            break;
        case 4:
            gConnectionWork->mSyncDoneChildMask |= 1 << aid;
            if (gConnectionWork->mSyncDoneChildMask == gConnectionWork->mChildren.mChildMask) {
                gConnectionWork->mRequestPending = 0;
            }
            break;
        case 5:
            gConnectionWork->mTransferFlags |= CONNECTION_TRANSFER_SYNC_DONE;
            gConnectionWork->mRequestPending = 0;
            break;
        case 1:
            gConnectionWork->mParticipantMask = message->mUnk_04;
            RefreshParticipantTables();
            RequestMPState15AfterCombine();
            break;
        case 2:
            if (func_02050650_inline() == 2) {
                gConnectionWork->mGroupSendMask = message->mUnk_04;
            }
            func_0205081c_inline2(1);
            break;
        case 6:
            switch (gConnectionWork->mState) {
                case 6:
                    StoreReceivedPlayerName(message->mUnk_02, message->mUnk_16, message->mUnk_17);
                    break;
                case 0xa:
                    StoreReceivedPlayerNameByState(message->mUnk_02, (u8) aid, message->mUnk_16, message->mUnk_17);
                    break;
            }
            break;
        case 9:
            if ((gConnectionWork->mBitsReceivedMask & (1 << message->mUnk_0a)) != 0) {
                return;
            }
            MI_CpuCopy8(message->mUnk_02, gConnectionWork->mPlayerRecords[message->mUnk_0a].mBits, 4);
            gConnectionWork->mBitsReceivedMask |= 1 << message->mUnk_0a;
            break;
        case 7:
            func_02050b88_inline(message->mUnk_04);
            break;
        case 8:
            gConnectionWork->mRaceSeed = message->mUnk_04;
            break;
    }
}

void MPDataPortCallback(Unk021425e8 *event) {
    MPMessage message;

    if (event->mResultCode != 0) {
        return;
    }
    if (event->mUnk_0c == 0) {
        return;
    }
    if (event->mUnk_10 < 2) {
        return;
    }
    if (event->mUnk_10 > 0x18) {
        return;
    }
    DC_InvalidateRange(event->mUnk_0c, event->mUnk_10);
    MI_CpuCopy8(event->mUnk_0c, &message, event->mUnk_10);
    if (event->mUnk_04 == 7) {
        return;
    }
    if (event->mUnk_04 == 9) {
        return;
    }
    if (event->mUnk_04 != 0x15) {
        return;
    }
    ProcessMPData(event->mUnk_12, &message);
}

BOOL QueueMPDataToPort(void *data, s32 dataSize, u16 destBitmap, void *sendBuffer, QueueMPDataToPortParams *params) {
    u16 sendSize;

    sendSize = dataSize;
    switch (func_02050650_inline()) {
        case 1:
            if (gConnectionWork->mChildren.mChildMask == 0) {
                return FALSE;
            }
            break;
        case 2:
            if (gConnectionWork->mOwnIndex == 0xffff) {
                return FALSE;
            }
            break;
    }
    if (sendSize > params->mMaxDataSize) {
        sendSize = params->mMaxDataSize;
    }
    DC_FlushRange(data, sendSize);
    if (sendBuffer == NULL) {
        sendBuffer = data;
    } else {
        MI_CpuCopy8(data, sendBuffer, sendSize);
        DC_FlushRange(sendBuffer, sendSize);
    }
    if (WM_SetMPDataToPortEx(params->mCallback, NULL, sendBuffer, sendSize, destBitmap, params->mPort,
                             params->mPriority) != 2) {
        return FALSE;
    }
    return TRUE;
}

BOOL QueueMPDataHalfword(s32 kind, u16 destBitmap) {
    u16 halfword;

    halfword = kind;
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_SEND_READY) == 0) {
        return FALSE;
    }
    data_0216523c.mMaxDataSize = 0x18;
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SEND_READY;
    if (QueueMPDataToPort(&halfword, 2, destBitmap, gConnectionWork->mMPDataBuffer, &data_0216523c) != FALSE) {
        return TRUE;
    }
    gConnectionWork->mFlags |= CONNECTION_FLAG_SEND_READY;
    return FALSE;
}

BOOL QueueMPDataPlayerName(s32 playerIndex, u16 destBitmap) {
    MPPlayerNameMessage message;

    message.mKind = 6;
    MI_CpuCopy8(&gConnectionWork->mPlayerRecords[playerIndex], message.mName, 0x14);
    message.mPlayerIndex = playerIndex;
    if (func_02050650_inline() == 1) {
        message.mConnectedMask = gConnectionWork->mChildren.mChildMask | 1;
    } else {
        message.mConnectedMask = 0;
    }
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_SEND_READY) == 0) {
        return FALSE;
    }
    data_0216523c.mMaxDataSize = 0x18;
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SEND_READY;
    if (QueueMPDataToPort(&message, 0x18, destBitmap, gConnectionWork->mMPDataBuffer, &data_0216523c) != FALSE) {
        return TRUE;
    }
    gConnectionWork->mFlags |= CONNECTION_FLAG_SEND_READY;
    return FALSE;
}

BOOL QueueMPDataPlayerBits(s32 playerIndex, u16 destBitmap) {
    MPPlayerBitsMessage message;

    message.mKind = 9;
    MI_CpuCopy8(gConnectionWork->mPlayerRecords[playerIndex].mBits, message.mBits, 4);
    message.mPlayerIndex = playerIndex;
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_SEND_READY) == 0) {
        return FALSE;
    }
    data_0216523c.mMaxDataSize = 0x18;
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SEND_READY;
    if (QueueMPDataToPort(&message, 0x12, destBitmap, gConnectionWork->mMPDataBuffer, &data_0216523c) != FALSE) {
        return TRUE;
    }
    gConnectionWork->mFlags |= CONNECTION_FLAG_SEND_READY;
    return FALSE;
}

BOOL QueueMPDataHalfwordAndWord(s32 kind, u16 destBitmap, s32 word) {
    Unk02050320 message;

    message.mUnk_00 = kind;
    message.mUnk_04 = word;
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_SEND_READY) == 0) {
        return FALSE;
    }
    data_0216523c.mMaxDataSize = 0x18;
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SEND_READY;
    if (QueueMPDataToPort(&message, 8, destBitmap, gConnectionWork->mMPDataBuffer, &data_0216523c) != FALSE) {
        return TRUE;
    }
    gConnectionWork->mFlags |= CONNECTION_FLAG_SEND_READY;
    return FALSE;
}

void QueueMPDataToPortCallback(void) {
    gConnectionWork->mFlags |= CONNECTION_FLAG_SEND_READY;
}
