#include "Main/Net/disconnect.h"
#include "Main/Net/mp_link.h"

#include "Main/Net/scan_slot.h"
#include "thread_scheduler.h"
#include "Main/Net/rom_archive.h"
#include "Main/Net/multiboot_connect.h"
#include "Main/Net/packet_port.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Net/block.h"
#include "Main/Net/scan_ghost_info.h"
#include "Main/Net/connection.h"
#include "Main/Net/connection_sharing.h"
#include "Main/Graphics/disp_cap.h"
#include "Main/Net/mp_states.h"
#include "Main/Net/mp.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Kart/kart_name_tags.h"
#include "arena_cache_init.h"
#include "wireless_link_control.h"
#include "wireless_key_data_sharing.h"
#include "cpu_copy_fill.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Net/mp_chunk_state_machine.h"

QueueMPDataToPortParams gMPDataToPortParams = {QueueMPDataToPortCallback, 0, {0, 0}, 0xf, 2, {0, 0}};

static inline u32 DisconnectGetConnectionMode(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

void DisconnectChildren(u32 aidBitmap) {
    gConnectionWork->mStep = CONNECTION_STEP_DROPPING_CHILDREN;
    gConnectionWork->mRequestPending = 1;
    if (WM_DisconnectChildren(DisconnectChildrenCallback, aidBitmap) != 7) {
        return;
    }
    if (gConnectionWork->mState == CONNECTION_STATE_SYNCED_RACE) {
        if (DisconnectGetConnectionMode() == CONNECTION_MODE_PARENT) {
            gConnectionWork->mRemovedChildMask = 0;
        }
    }
    gConnectionWork->mRequestPending = 0;
}

void DisconnectChildrenCallback(WirelessMessage *event) {
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode != WIRELESS_RESULT_SUCCEEDED && event->mResultCode != WIRELESS_RESULT_NO_REMOTE) {
        return;
    }
    if (DisconnectGetConnectionMode() == CONNECTION_MODE_PARENT) {
        switch (gConnectionWork->mState) {
            case CONNECTION_STATE_SYNCED:
            case CONNECTION_STATE_SYNCED_RACE:
                gConnectionWork->mLeftParticipantMask[0] =
                    gConnectionWork->mLeftParticipantMask[0] | gConnectionWork->mRemovedChildMask;
                break;
        }
    }
    gConnectionWork->mRemovedChildMask = 0;
}

void EndDataSharing(void) {
    s32 result;

    gConnectionWork->mStep = CONNECTION_STEP_STOPPING_SHARING;
    gConnectionWork->mRequestPending = 1;
    result = WM_EndDataSharing(gConnectionWork->mSharingInfo);
    gConnectionWork->mRequestPending = 0;
    if (result == 0) {
        return;
    }
    StopConnection();
}

void EndMP(void) {
    gConnectionWork->mStep = CONNECTION_STEP_STOPPING_EXCHANGE;
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
    if (event->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
        StopConnection();
        return;
    }
    connection = gConnectionWork;
    if (connection->mState == CONNECTION_STATE_GATHERING) {
        connection->mState = CONNECTION_STATE_MP_ENDING;
    }
}

void EndParent(void) {
    gConnectionWork->mStep = CONNECTION_STEP_CLOSING_HOST;
    gConnectionWork->mRequestPending = 1;
    if (WM_EndParent(EndParentCallback) == 2) {
        return;
    }
    StopConnection();
}

void EndParentCallback(WirelessMessage *event) {
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
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
        case CONNECTION_MODE_PARENT:
            for (childIndex = 0, child = children->mEntries; childIndex < children->mChildCount;
                 childIndex++, child++) {
                if (child->mAid != CHILD_ENTRY_NO_AID) {
                    gConnectionWork->mChildren.mDisconnectingIndex = childIndex;
                    gConnectionWork->mStep = CONNECTION_STEP_LEAVING;
                    gConnectionWork->mRequestPending = 1;
                    result = WM_Disconnect(DisconnectCallback, child->mAid);
                    break;
                }
            }
            break;
        case CONNECTION_MODE_CHILD:
            gConnectionWork->mStep = CONNECTION_STEP_LEAVING;
            gConnectionWork->mRequestPending = 1;
            result = WM_Disconnect(DisconnectCallback, 0);
            break;
    }
    switch (result) {
        case WIRELESS_RESULT_SUCCEEDED:
        case WIRELESS_RESULT_NO_REMOTE:
            gConnectionWork->mRequestPending = 0;
            break;
        case WIRELESS_RESULT_OCCUPIED:
            if (DisconnectGetConnectionMode() == CONNECTION_MODE_CHILD) {
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
        case WIRELESS_RESULT_SUCCEEDED:
        case WIRELESS_RESULT_NO_REMOTE:
            gConnectionWork->mRequestPending = 0;
            switch (gConnectionWork->mConnectionMode) {
                case CONNECTION_MODE_PARENT:
                    aid = gConnectionWork->mChildren.mEntries[gConnectionWork->mChildren.mDisconnectingIndex].mAid;
                    RemoveChild(aid);
                    if (DisconnectGetConnectionMode() == CONNECTION_MODE_PARENT) {
                        if (gConnectionWork->mState == CONNECTION_STATE_SYNCED_RACE) {
                            BIT_SET(gConnectionWork->mLeftParticipantMask[0], aid);
                        }
                    }
                    gConnectionWork->mChildren.mDisconnectingIndex = -1;
                    break;
                case CONNECTION_MODE_CHILD:
                    gConnectionWork->mOperationFlags &= ~CONNECTION_OPERATION_DISCONNECTING;
                    ResetConnectionData();
                    break;
            }
            break;
        case WIRELESS_RESULT_REFUSED:
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
    return IsMultiBootSetupStarted() != FALSE &&
           (GetConnectionMode() == CONNECTION_MODE_PARENT || ConnectionMB_IsMultiBootChild() != FALSE);
}

BOOL ConnectionMB_IsMultiBootChild(void) {
    return gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT;
}

void SetStepAndRequestPending(s32 step) {
    gConnectionWork->mStep = step;
    gConnectionWork->mRequestPending = 1;
}

// WM_End first; when it does not return 2, the 0x100 and 0x200 flag paths or WM_Reset run instead.
void End(void) {
    ConnectionWork *connection;
    u32 flags;

    gConnectionWork->mStep = CONNECTION_STEP_SHUTTING_DOWN;
    gConnectionWork->mRequestPending = 1;
    if (WM_End(EndCallback) == 2) {
        return;
    }
    connection = gConnectionWork;
    flags = connection->mFlags;
    if ((flags & CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER) != 0) {
        connection->mStep = CONNECTION_STEP_ROM_ARCHIVE_STOP;
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
    connection->mStep = CONNECTION_STEP_RESTARTING;
    gConnectionWork->mRequestPending = 1;
    if (WM_Reset(ResetCallback) == 2) {
        return;
    }
    gConnectionWork->mStep = CONNECTION_STEP_SHUTTING_DOWN;
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
    SetStepAndRequestPending(CONNECTION_STEP_RESTARTING);
    if (WM_Reset(ResetCallback) == 2) {
        return;
    }
    End();
}

void EndCallback(WirelessMessage *event) {
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
        gConnectionWork->mErrorCode = CONNECTION_ERROR_OPERATION_FAILED;
        gConnectionWork->mRequestPending = 0;
    } else {
        gConnectionWork->mConnectionMode = CONNECTION_MODE_NONE;
    }
}

void SetRequestErrorCode(s32 errorCode) {
    gConnectionWork->mErrorCode = errorCode;
    gConnectionWork->mRequestPending = 0;
}

void AddChild(u32 aid, u8 *bytes, PlayerRecord *playerEntry) {
    ChildList *children;

    children = &gConnectionWork->mChildren;
    if (children->mChildCount >= CHILD_LIST_MAX_CHILDREN) {
        return;
    }
    children->mEntries[aid - 1].mAid = aid;
    children->mChildCount += 1;
    BIT_SET(children->mChildMask, aid);
    children->mEntries[0].mBytes[0] = bytes[0];
    children->mEntries[0].mBytes[1] = bytes[1];
    children->mEntries[0].mBytes[2] = bytes[2];
    children->mEntries[0].mBytes[3] = bytes[3];
    children->mEntries[0].mBytes[4] = bytes[4];
    children->mEntries[0].mBytes[5] = bytes[5];
    MI_CpuCopy8(playerEntry, &gConnectionWork->mPlayerRecords[aid], PLAYER_NAME_BYTES);
    gConnectionWork->mStatusFlags |= CONNECTION_STATUS_CHILDREN_CHANGED;
    if ((playerEntry->mEmblem[0] & 1) != 0) {
        BIT_SET(gConnectionWork->mGroupSendMask, aid);
    }
}

static inline void MPDataRequestMPState(u16 nextState) {
    MPStateMachine *stateMachine = &gConnectionWork->mMPStateMachine;
    stateMachine->mStateMachine.mNextState = nextState;
    stateMachine->mStateMachine.mNextStateRequested = 1;
}

static inline void SetGroupSendMaskIfMultibootSetup(u8 groupSendMask) {
    u32 shouldSend = 0;
    u32 isAllowed;

    if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
        isAllowed = 1;
        if (DisconnectGetConnectionMode() != CONNECTION_MODE_PARENT) {
            if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
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
    if (DisconnectGetConnectionMode() != CONNECTION_MODE_PARENT) {
        return;
    }
    SetRomArchiveGroupSendMask(groupSendMask);
}

static inline void RemoveChildrenInMask(u16 removeMask) {
    u16 childIndex;
    u32 isSyncedRace;

    for (childIndex = 0; childIndex < 8; childIndex++) {
        if (BIT_IS_SET(removeMask, childIndex)) {
            isSyncedRace = gConnectionWork->mState == CONNECTION_STATE_SYNCED_RACE ? 1 : 0;
            if (DisconnectGetConnectionMode() == CONNECTION_MODE_PARENT) {
                BIT_CLEAR(gConnectionWork->mChildren.mChildMask, childIndex);
                if (isSyncedRace != 0) {
                    BIT_SET(gConnectionWork->mRemovedChildMask, childIndex);
                }
            }
            BIT_CLEAR(gConnectionWork->mGroupSendMask, childIndex);
        }
    }
    if (DisconnectGetConnectionMode() != CONNECTION_MODE_PARENT) {
        return;
    }
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER) == 0) {
        return;
    }
    SetGroupSendMaskIfMultibootSetup(gConnectionWork->mGroupSendMask);
}

void RemoveChild(u32 aid) {
    ChildList *children;

    children = &gConnectionWork->mChildren;
    if (children->mEntries[aid - 1].mAid == CHILD_ENTRY_NO_AID) {
        return;
    }
    children->mEntries[aid - 1].mAid = CHILD_ENTRY_NO_AID;
    children->mChildCount -= 1;
    RemoveChildrenInMask(1 << aid);
    gConnectionWork->mStatusFlags |= CONNECTION_STATUS_CHILDREN_CHANGED;
    switch (gConnectionWork->mState) {
        case CONNECTION_STATE_SYNCED_RACE:
            if (children->mChildCount < 1) {
                gConnectionWork->mErrorCode = CONNECTION_ERROR_DISCONNECTED;
                gConnectionWork->mRequestPending = 0;
            }
            break;
        case CONNECTION_STATE_SYNC_WAIT:
        case CONNECTION_STATE_SYNCED:
            gConnectionWork->mErrorCode = CONNECTION_ERROR_DISCONNECTED;
            gConnectionWork->mRequestPending = 0;
            break;
    }
}

void ProcessMPData(u32 aid, MPMessage *message) {
    switch (message->mKind) {
        case MP_MESSAGE_SYNC_NOT_DONE:
            BIT_CLEAR(gConnectionWork->mSyncDoneChildMask, aid);
            break;
        case MP_MESSAGE_SYNC_DONE:
            BIT_SET(gConnectionWork->mSyncDoneChildMask, aid);
            if (gConnectionWork->mSyncDoneChildMask == gConnectionWork->mChildren.mChildMask) {
                gConnectionWork->mRequestPending = 0;
            }
            break;
        case MP_MESSAGE_TRANSFER_SYNC_DONE:
            gConnectionWork->mTransferFlags |= CONNECTION_TRANSFER_SYNC_DONE;
            gConnectionWork->mRequestPending = 0;
            break;
        case MP_MESSAGE_PARTICIPANT_MASK:
            gConnectionWork->mParticipantMask = message->mWord;
            RefreshParticipantTables();
            RequestMPReadyAfterCombine();
            break;
        case MP_MESSAGE_GROUP_SEND_MASK:
            if (DisconnectGetConnectionMode() == CONNECTION_MODE_CHILD) {
                gConnectionWork->mGroupSendMask = message->mWord;
            }
            MPDataRequestMPState(MP_STATE_WAIT_ROM_ARCHIVE);
            break;
        case MP_MESSAGE_PLAYER_NAME:
            switch (gConnectionWork->mState) {
                case CONNECTION_STATE_CONNECTED:
                    StoreReceivedPlayerName(message->mBitsOrName, message->mNamePlayerIndex,
                                            message->mNameConnectedMask);
                    break;
                case CONNECTION_STATE_ENTRY_EXCHANGE:
                    StoreReceivedPlayerNameByState(message->mBitsOrName, (u8) aid, message->mNamePlayerIndex,
                                                   message->mNameConnectedMask);
                    break;
            }
            break;
        case MP_MESSAGE_PLAYER_BITS:
            if ((gConnectionWork->mBitsReceivedMask & (1 << message->mBitsPlayerIndex)) != 0) {
                return;
            }
            MI_CpuCopy8(message->mBitsOrName, gConnectionWork->mPlayerRecords[message->mBitsPlayerIndex].mBits,
                        sizeof(gConnectionWork->mPlayerRecords[message->mBitsPlayerIndex].mBits));
            gConnectionWork->mBitsReceivedMask |= 1 << message->mBitsPlayerIndex;
            break;
        case MP_MESSAGE_REMOVE_CHILDREN:
            RemoveChildrenInMask(message->mWord);
            break;
        case MP_MESSAGE_RACE_SEED:
            gConnectionWork->mRaceSeed = message->mWord;
            break;
    }
}

void MPDataPortCallback(void *portMessage) {
    WirelessMessage *event = portMessage;
    MPMessage message;

    if (event->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
        return;
    }
    if (event->mData == 0) {
        return;
    }
    if (event->mLength < MP_MESSAGE_MIN_LENGTH) {
        return;
    }
    if (event->mLength > MP_MESSAGE_MAX_LENGTH) {
        return;
    }
    DC_InvalidateRange(event->mData, event->mLength);
    MI_CpuCopy8(event->mData, &message, event->mLength);
    if (event->mState == WIRELESS_STATE_LINKED) {
        return;
    }
    if (event->mState == WIRELESS_STATE_UNLINKED) {
        return;
    }
    if (event->mState != WIRELESS_STATE_PORT_DATA_ARRIVED) {
        return;
    }
    ProcessMPData(event->mAid, &message);
}

BOOL QueueMPDataToPort(void *data, s32 dataSize, u16 destBitmap, void *sendBuffer, QueueMPDataToPortParams *params) {
    u16 sendSize;

    sendSize = dataSize;
    switch (DisconnectGetConnectionMode()) {
        case CONNECTION_MODE_PARENT:
            if (gConnectionWork->mChildren.mChildMask == 0) {
                return FALSE;
            }
            break;
        case CONNECTION_MODE_CHILD:
            if (gConnectionWork->mOwnIndex == CONNECTION_OWN_INDEX_NONE) {
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
    gMPDataToPortParams.mMaxDataSize = MP_MESSAGE_MAX_LENGTH;
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SEND_READY;
    if (QueueMPDataToPort(&halfword, 2, destBitmap, gConnectionWork->mMPDataBuffer, &gMPDataToPortParams) != FALSE) {
        return TRUE;
    }
    gConnectionWork->mFlags |= CONNECTION_FLAG_SEND_READY;
    return FALSE;
}

BOOL QueueMPDataPlayerName(s32 playerIndex, u16 destBitmap) {
    MPPlayerNameMessage message;

    message.mKind = MP_MESSAGE_PLAYER_NAME;
    MI_CpuCopy8(&gConnectionWork->mPlayerRecords[playerIndex], message.mName, sizeof(message.mName));
    message.mPlayerIndex = playerIndex;
    if (DisconnectGetConnectionMode() == CONNECTION_MODE_PARENT) {
        message.mConnectedMask = gConnectionWork->mChildren.mChildMask | 1;
    } else {
        message.mConnectedMask = 0;
    }
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_SEND_READY) == 0) {
        return FALSE;
    }
    gMPDataToPortParams.mMaxDataSize = MP_MESSAGE_MAX_LENGTH;
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SEND_READY;
    if (QueueMPDataToPort(&message, 0x18, destBitmap, gConnectionWork->mMPDataBuffer, &gMPDataToPortParams) != FALSE) {
        return TRUE;
    }
    gConnectionWork->mFlags |= CONNECTION_FLAG_SEND_READY;
    return FALSE;
}

BOOL QueueMPDataPlayerBits(u8 playerIndex, u16 destBitmap) {
    MPPlayerBitsMessage message;

    message.mKind = MP_MESSAGE_PLAYER_BITS;
    MI_CpuCopy8(gConnectionWork->mPlayerRecords[playerIndex].mBits, message.mBits, sizeof(message.mBits));
    message.mPlayerIndex = playerIndex;
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_SEND_READY) == 0) {
        return FALSE;
    }
    gMPDataToPortParams.mMaxDataSize = MP_MESSAGE_MAX_LENGTH;
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
    gMPDataToPortParams.mMaxDataSize = MP_MESSAGE_MAX_LENGTH;
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
