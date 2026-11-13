#include "Main/Net/disconnect.h"

#include "Main/Net/scan_slot.h"
#include "os_thread.h"
#include "Main/Net/rom_archive.h"
#include "Main/Net/multiboot_connect.h"
#include "Main/Net/packet_port.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Net/block.h"
#include "Main/Net/scan_ghost_info.h"
#include "Main/Net/connection.h"
#include "Main/Net/connection_sharing.h"
#include "Main/Graphics/disp_cap.h"
#include "Main/Net/mp_states.h"
#include "Main/Net/mp.h"
#include "Main/MapObjects/data_02165000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "code_0200eddc.h"
#include "code_02142eac.h"
#include "code_021445e0.h"
#include "code_0214d018.h"
#include "Main/Menu/select_race_rule_state.h"

QueueMPDataToPortParams gMPDataToPortParams = {QueueMPDataToPortCallback, 0, {0, 0}, 0xf, 2, {0, 0}};

static inline u32 DisconnectGetConnectionMode(void) {
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
        if (DisconnectGetConnectionMode() == 1) {
            gConnectionWork->mRemovedChildMask = 0;
        }
    }
    gConnectionWork->mRequestPending = 0;
}

void DisconnectChildrenCallback(WirelessMessage *event) {
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode != 0 && event->mResultCode != 7) {
        return;
    }
    if (DisconnectGetConnectionMode() == 1) {
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

void EndMPCallback(WirelessMessage *event) {
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

void EndParentCallback(WirelessMessage *event) {
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode != 0) {
        StopConnection();
    } else {
        ResetConnectionData();
    }
}

void Disconnect(void) {
    s32 result;
    s32 childIndex;
    ChildList *children;
    ChildEntry *child;

    result = 7;
    children = &gConnectionWork->mChildren;
    switch (DisconnectGetConnectionMode()) {
        case 1:
            for (childIndex = 0, child = children->mEntries; childIndex < children->mChildCount;
                 childIndex++, child++) {
                if (child->mAid != 0xffff) {
                    gConnectionWork->mChildren.mDisconnectingIndex = childIndex;
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
            if (DisconnectGetConnectionMode() == 2) {
                gConnectionWork->mOperationFlags |= CONNECTION_OPERATION_DISCONNECTING;
            }
            break;
        default:
            StopConnection();
            break;
    }
}

void DisconnectCallback(WirelessMessage *event) {
    u16 aid;

    switch (event->mResultCode) {
        case 0:
        case 7:
            gConnectionWork->mRequestPending = 0;
            switch (gConnectionWork->mConnectionMode) {
                case 1:
                    aid = gConnectionWork->mChildren.mEntries[gConnectionWork->mChildren.mDisconnectingIndex].mAid;
                    RemoveChild(aid);
                    if (DisconnectGetConnectionMode() == 1) {
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

static inline u32 IsMultiBootSetupStartedModeOneOrChild(void) {
    return IsMultiBootSetupStarted() != FALSE && (GetConnectionMode() == 1 || ConnectionMB_IsMultiBootChild() != FALSE);
}

BOOL ConnectionMB_IsMultiBootChild(void) {
    return gBootInfo->mBootType == 2;
}

void SetStepAndRequestPending(s32 step) {
    gConnectionWork->mStep = step;
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
        if (IsMultiBootSetupStartedModeOneOrChild() != 0) {
            StopRomArchive();
            gConnectionWork->mFlags &= ~CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER;
        }
        gConnectionWork->mRequestPending = 0;
        return;
    }
    if ((flags & CONNECTION_FLAG_BLOCK_TRANSFER) != 0) {
        EndWbtStep();
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
        EndWbtStep();
        return;
    }
    SetStepAndRequestPending(2);
    if (WM_Reset(ResetCallback) == 2) {
        return;
    }
    End();
}

void EndCallback(WirelessMessage *event) {
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

void AddChild(u32 aid, u8 *bytes, PlayerRecord *playerEntry) {
    ChildList *children;

    children = &gConnectionWork->mChildren;
    if (children->mChildCount >= 7) {
        return;
    }
    children->mEntries[aid - 1].mAid = aid;
    children->mChildCount += 1;
    children->mChildMask |= 1 << aid;
    children->mEntries[0].mBytes[0] = bytes[0];
    children->mEntries[0].mBytes[1] = bytes[1];
    children->mEntries[0].mBytes[2] = bytes[2];
    children->mEntries[0].mBytes[3] = bytes[3];
    children->mEntries[0].mBytes[4] = bytes[4];
    children->mEntries[0].mBytes[5] = bytes[5];
    MI_CpuCopy8(playerEntry, &gConnectionWork->mPlayerRecords[aid], 0x14);
    gConnectionWork->mStatusFlags |= CONNECTION_STATUS_CHILDREN_CHANGED;
    if ((playerEntry->mEmblem[0] & 1) != 0) {
        gConnectionWork->mGroupSendMask |= 1 << aid;
    }
}

static inline void MPDataRequestMPState(u16 nextState) {
    MPStateMachine *stateMachine = &gConnectionWork->mMPStateMachine;
    stateMachine->mStateMachine.mNextState = nextState;
    stateMachine->mStateMachine.mNextStateRequested = 1;
}

static inline void SetGroupSendMaskIfMultiBootMode1(u8 groupSendMask) {
    u32 shouldSend = 0;
    u32 isAllowed;

    if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
        isAllowed = 1;
        if (DisconnectGetConnectionMode() != 1) {
            if (gBootInfo->mBootType != 2) {
                isAllowed = 0;
            }
        }
        if (isAllowed != 0) {
            shouldSend = 1;
        }
    }
    if (shouldSend == 0) {
        return;
    }
    if (DisconnectGetConnectionMode() != 1) {
        return;
    }
    SetRomArchiveGroupSendMask(groupSendMask);
}

static inline void RemoveChildrenInMask(u16 removeMask) {
    u16 childIndex;
    u32 isInState9;

    for (childIndex = 0; childIndex < 8; childIndex++) {
        if ((removeMask & (1 << childIndex)) != 0) {
            isInState9 = gConnectionWork->mState == 9 ? 1 : 0;
            if (DisconnectGetConnectionMode() == 1) {
                gConnectionWork->mChildren.mChildMask &= ~(1 << childIndex);
                if (isInState9 != 0) {
                    gConnectionWork->mRemovedChildMask |= 1 << childIndex;
                }
            }
            gConnectionWork->mGroupSendMask &= ~(1 << childIndex);
        }
    }
    if (DisconnectGetConnectionMode() != 1) {
        return;
    }
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER) == 0) {
        return;
    }
    SetGroupSendMaskIfMultiBootMode1(gConnectionWork->mGroupSendMask);
}

void RemoveChild(u32 aid) {
    ChildList *children;

    children = &gConnectionWork->mChildren;
    if (children->mEntries[aid - 1].mAid == 0xffff) {
        return;
    }
    children->mEntries[aid - 1].mAid = 0xffff;
    children->mChildCount -= 1;
    RemoveChildrenInMask(1 << aid);
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
            if (DisconnectGetConnectionMode() == 2) {
                gConnectionWork->mGroupSendMask = message->mUnk_04;
            }
            MPDataRequestMPState(1);
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
            RemoveChildrenInMask(message->mUnk_04);
            break;
        case 8:
            gConnectionWork->mRaceSeed = message->mUnk_04;
            break;
    }
}

void MPDataPortCallback(WirelessMessage *event) {
    MPMessage message;

    if (event->mResultCode != 0) {
        return;
    }
    if (event->mData == 0) {
        return;
    }
    if (event->mLength < 2) {
        return;
    }
    if (event->mLength > 0x18) {
        return;
    }
    DC_InvalidateRange(event->mData, event->mLength);
    MI_CpuCopy8(event->mData, &message, event->mLength);
    if (event->mState == 7) {
        return;
    }
    if (event->mState == 9) {
        return;
    }
    if (event->mState != 0x15) {
        return;
    }
    ProcessMPData(event->mAid, &message);
}

BOOL QueueMPDataToPort(void *data, s32 dataSize, u16 destBitmap, void *sendBuffer, QueueMPDataToPortParams *params) {
    u16 sendSize;

    sendSize = dataSize;
    switch (DisconnectGetConnectionMode()) {
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
    gMPDataToPortParams.mMaxDataSize = 0x18;
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SEND_READY;
    if (QueueMPDataToPort(&halfword, 2, destBitmap, gConnectionWork->mMPDataBuffer, &gMPDataToPortParams) != FALSE) {
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
    if (DisconnectGetConnectionMode() == 1) {
        message.mConnectedMask = gConnectionWork->mChildren.mChildMask | 1;
    } else {
        message.mConnectedMask = 0;
    }
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_SEND_READY) == 0) {
        return FALSE;
    }
    gMPDataToPortParams.mMaxDataSize = 0x18;
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SEND_READY;
    if (QueueMPDataToPort(&message, 0x18, destBitmap, gConnectionWork->mMPDataBuffer, &gMPDataToPortParams) != FALSE) {
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
    gMPDataToPortParams.mMaxDataSize = 0x18;
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SEND_READY;
    if (QueueMPDataToPort(&message, 0x12, destBitmap, gConnectionWork->mMPDataBuffer, &gMPDataToPortParams) != FALSE) {
        return TRUE;
    }
    gConnectionWork->mFlags |= CONNECTION_FLAG_SEND_READY;
    return FALSE;
}

BOOL QueueMPDataHalfwordAndWord(s32 kind, u16 destBitmap, s32 word) {
    MPKindWordMessage message;

    message.mKind = kind;
    message.mWord = word;
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_SEND_READY) == 0) {
        return FALSE;
    }
    gMPDataToPortParams.mMaxDataSize = 0x18;
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SEND_READY;
    if (QueueMPDataToPort(&message, 8, destBitmap, gConnectionWork->mMPDataBuffer, &gMPDataToPortParams) != FALSE) {
        return TRUE;
    }
    gConnectionWork->mFlags |= CONNECTION_FLAG_SEND_READY;
    return FALSE;
}

void QueueMPDataToPortCallback(void) {
    gConnectionWork->mFlags |= CONNECTION_FLAG_SEND_READY;
}
