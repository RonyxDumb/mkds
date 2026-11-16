#include "Main/Net/connection.h"
#include "Main/System/heap.h"
#include "Main/Menu/title_scene.h"
#include "Main/System/touch_mic_input.h"
#include "Main/Net/participant_get_connection.h"
#include "tick_counter.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Scene/scene_frames.h"
#include "Main/Net/connection_sharing.h"
#include "Main/Graphics/disp_cap.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Net/rom_archive.h"
#include "Main/Net/multiboot_connect.h"
#include "Main/Net/packet_port.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Net/block.h"
#include "Main/Net/scan_ghost_info.h"
#include "Main/Net/pending_files.h"
#include "Main/Net/disconnect.h"
#include "Main/Net/mp_chunk_state_machine.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "reset_interrupts_halt.h"
#include "wireless_link_control.h"
#include "wireless_key_data_sharing.h"
#include "wireless_beacon_wep_settings.h"
#include "cpu_copy_fill.h"
#include "Main/Race/race_progress_rank.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/Net/mp_link.h"

void ResetConnection(void) {
    ScanParam *scanParams;
    ScanExParam *scanExParams;
    BlockTransferView *blocks;
    BlockEntry *blockEntry;
    s32 index;

    if (gConnectionWork == NULL) {
        return;
    }
    gConnectionWork->mConnectionMode = CONNECTION_MODE_NONE;
    gConnectionWork->mState = CONNECTION_STATE_IDLE;
    gConnectionWork->mErrorCode = CONNECTION_ERROR_NONE;
    gConnectionWork->mStep = CONNECTION_STEP_NOTHING;
    gConnectionWork->mRequestPending = 0;
    gConnectionWork->mFlags = 0;
    scanParams = gConnectionWork->mScanParams;
    scanParams->mScanBuf = gConnectionWork->mScanBssDescBuffer;
    scanParams->mChannel = 0;
    scanParams->mMaxChannelTime = 0;
    for (index = 0; index < 6; index++) {
        scanParams->mBssid[index] = CONNECTION_BSSID_ANY_BYTE;
    }
    scanExParams = gConnectionWork->mScanExParams;
    scanExParams->mScanBuf = gConnectionWork->mScanExBuffer;
    scanExParams->mScanBufSize = CONNECTION_SCAN_BUFFER_SIZE;
    scanExParams->mChannelList = 0;
    scanExParams->mMaxChannelTime = 0;
    scanExParams->mScanType = 1;
    scanExParams->mSsidLength = 0;
    for (index = 0; index < 6; index++) {
        scanExParams->mBssid[index] = CONNECTION_BSSID_ANY_BYTE;
    }
    ResetConnectionData();
    blocks = &gConnectionWork->mBlockTransfer;
    blockEntry = &blocks->mBlockEntries[0];
    for (index = 0; index < 0xc; index++) {
        blockEntry->mPath[0] = 0;
        blockEntry->mBuffer = NULL;
        blockEntry++;
    }
    blocks->mUnk_6b4 = 0;
    blocks->mMode = 0;
    blocks->mZeroWordReceived = FALSE;
    blocks->mMPSetupActive = FALSE;
    ResetConnectionBuffers(&gConnectionWork->mMultiBootState);
    InitMPStateMachine();
    FillParentParameter(1);
}

// Fills the record handed to WM_StepDataSharing, steps the data sharing with it, keeps the result and, when the result
// is 0 in the synced state, clears the send byte.
void StepDataSharing(void) {
    SharingSendRecord *sendData;
    u32 role;
    s32 result;

    GetSceneFrames();
    sendData = gConnectionWork->mSharingSendRecord;
    if (gConnectionWork->mState == CONNECTION_STATE_SYNCED) {
        sendData->mSendByte = gConnectionWork->mDataSharingSendByte;
    } else {
        sendData->mSendByte = 0;
    }
    sendData->mLeftParticipantMask =
        (gConnectionWork == NULL ? CONNECTION_MODE_NONE : gConnectionWork->mConnectionMode) == CONNECTION_MODE_PARENT
            ? gConnectionWork->mLeftParticipantMask[0]
            : 0;
    sendData->mPadKeys = GetPadKeys();
    sendData->mFlags = 0;
    sendData->mUnk_07 = 0;
    role = CONNECTION_MODE_NONE;
    if (gConnectionWork->mState == CONNECTION_STATE_SYNCED_RACE) {
        if (gConnectionWork != NULL) {
            role = gConnectionWork->mConnectionMode;
        }
        if (role == CONNECTION_MODE_PARENT) {
            if (IsDispCapFadeFlagSet() != FALSE) {
                sendData->mFlags |= SHARING_RECORD_FLAG_DISP_CAP_FADE;
            } else {
                sendData->mFlags &= ~SHARING_RECORD_FLAG_DISP_CAP_FADE;
            }
        }
    }
    role = gConnectionWork == NULL ? CONNECTION_MODE_NONE : gConnectionWork->mConnectionMode;
    if (role != CONNECTION_MODE_PARENT || (gConnectionWork->mStatusFlags & CONNECTION_STATUS_SHARING_SYNCED) != 0) {
        if (gConnectionWork->mSyncToggle == 0) {
            sendData->mFlags |= SHARING_RECORD_FLAG_SYNC_TOGGLE_ZERO;
            sendData->mFlags &= ~SHARING_RECORD_FLAG_SYNC_TOGGLE_ONE;
        } else {
            sendData->mFlags |= SHARING_RECORD_FLAG_SYNC_TOGGLE_ONE;
            sendData->mFlags &= ~SHARING_RECORD_FLAG_SYNC_TOGGLE_ZERO;
        }
    }
    sendData->mMicOverThreshold = gTouchMicInput->mMicOverThreshold;
    sendData->mTouchPoint = GetPackedTouchPoint();
    result = WM_StepDataSharing(gConnectionWork->mSharingInfo, sendData, gConnectionWork->mSharingDataSet);
    if (result == 0) {
        if (gConnectionWork->mState == CONNECTION_STATE_SYNCED) {
            gConnectionWork->mDataSharingSendByte = 0;
        }
    }
    gConnectionWork->mSharingStepResult = result;
}

BOOL UpdateDataSharing(void) {
    DataSharing *dataSharing;
    BOOL allRead;
    u16 participantIndex;
    u16 clearIndex;
    u8 leftMask;
    u8 *sharedData;
    u8 buf[8][8];
    u32 participantMask;
    u32 bit;
    u16 entryIndex;

    dataSharing = &gConnectionWork->mDataSharing;
    gConnectionWork->mArrivedMemberMask =
        gConnectionWork->mSharingInfo->mDs[gConnectionWork->mSharingInfo->mWriteIndex].mArrivedMembers;
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SHARING_NOT_UPDATED;
    switch (gConnectionWork == NULL ? CONNECTION_MODE_NONE : gConnectionWork->mConnectionMode) {
        case CONNECTION_MODE_PARENT:
            if (gConnectionWork->mChildren.mChildCount != 0) {
                StepDataSharing();
            } else {
                return FALSE;
            }
            break;
        case CONNECTION_MODE_CHILD:
            if (gConnectionWork->mOwnIndex != CONNECTION_OWN_INDEX_NONE) {
                StepDataSharing();
            } else {
                return FALSE;
            }
            break;
    }
    switch (gConnectionWork->mState) {
        case CONNECTION_STATE_SYNCED:
            if (dataSharing->mSharingPhase != DATA_SHARING_PHASE_INITIAL &&
                dataSharing->mSharingPhase == DATA_SHARING_PHASE_AFTER_RESET) {
                return FALSE;
            }
            break;
        case CONNECTION_STATE_SYNCED_RACE:
            if (dataSharing->mSharingPhase != DATA_SHARING_PHASE_INITIAL) {
                if (dataSharing->mSharingPhase == DATA_SHARING_PHASE_AFTER_RESET) {
                    return FALSE;
                }
            } else {
                if ((gConnectionWork == NULL ? CONNECTION_MODE_NONE : gConnectionWork->mConnectionMode) ==
                    CONNECTION_MODE_PARENT) {
                    for (clearIndex = 1; clearIndex < 8; clearIndex++) {
                        if (BIT_IS_SET(gConnectionWork->mParticipantMask, clearIndex)) {
                            gConnectionWork->mUnk_15f8[clearIndex - 1] = 0;
                        }
                    }
                }
            }
            break;
    }
    allRead = TRUE;
    sharedData = WM_GetSharedDataAddress(gConnectionWork->mSharingInfo, gConnectionWork->mSharingDataSet, 0);
    if (sharedData != NULL) {
        leftMask = sharedData[4];
        if (leftMask != 0) {
            for (participantIndex = 0; participantIndex < 8; participantIndex++) {
                bit = 1 << participantIndex;
                participantMask = gConnectionWork->mParticipantMask;
                entryIndex = gConnectionWork->mParticipantPosByIndex[participantIndex].mEntryIndex;
                if ((participantMask & bit) != 0 && (leftMask & bit) != 0) {
                    gConnectionWork->mParticipantMask = participantMask & ~bit;
                    if (gConnectionWork->mState == CONNECTION_STATE_SYNCED_RACE) {
                        RemoveRaceProgressKart(entryIndex);
                    }
                    if ((gConnectionWork == NULL ? CONNECTION_MODE_NONE : gConnectionWork->mConnectionMode) ==
                        CONNECTION_MODE_PARENT) {
                        gConnectionWork->mLeftParticipantMask[0] &= ~bit;
                    }
                }
            }
        }
        MI_CpuCopy8(sharedData, &buf[0], 8);
    } else {
        allRead = FALSE;
    }
    if (allRead != FALSE) {
        for (participantIndex = 1; participantIndex < 8; participantIndex++) {
            if (BIT_IS_SET(gConnectionWork->mParticipantMask, participantIndex)) {
                sharedData = WM_GetSharedDataAddress(gConnectionWork->mSharingInfo, gConnectionWork->mSharingDataSet,
                                                     participantIndex);
                if (sharedData != NULL) {
                    MI_CpuCopy8(sharedData, &buf[participantIndex], 8);
                } else {
                    allRead = FALSE;
                    break;
                }
            }
        }
    }
    for (participantIndex = 0; participantIndex < 8; participantIndex++) {
        if (allRead != FALSE && BIT_IS_SET(gConnectionWork->mParticipantMask, participantIndex)) {
            MI_CpuCopy8(&buf[participantIndex], &dataSharing->mReceivedRecords[participantIndex], 8);
            dataSharing->mSharedDataCopied[participantIndex] = 1;
        } else {
            dataSharing->mSharedDataCopied[participantIndex] = 0;
        }
    }
    return allRead != FALSE;
}

void Initialize(void) {
    gConnectionWork->mStep = CONNECTION_STEP_STARTING_UP;
    gConnectionWork->mRequestPending = 1;
    if (WM_Initialize(gConnectionWork->mWmWorkBuffer, InitializeCallback, 2) != 2) {
        gConnectionWork->mRequestPending = 0;
    }
}

void InitializeCallback(WirelessMessage *event) {
    s32 result;

    result = WM_SetPortCallback(0xf, MPDataPortCallback, NULL);
    gConnectionWork->mRequestPending = 0;
    if (result != 0) {
        return;
    }
    if (event->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
        return;
    }
    if (gConnectionWork->mConnectionKind != CONNECTION_KIND_NONE) {
        WM_SetPortCallback(1, PacketPortCallback, NULL);
    }
    ResetConnectionData();
}

void StopConnection(void) {
    u32 role;
    BOOL shouldStop;
    BOOL allowed;

    if ((gConnectionWork->mFlags & CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER) != 0) {
        gConnectionWork->mStep = CONNECTION_STEP_ROM_ARCHIVE_STOP;
        gConnectionWork->mRequestPending = 1;
        shouldStop = FALSE;
        if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
            allowed = TRUE;
            role = gConnectionWork == NULL ? CONNECTION_MODE_NONE : gConnectionWork->mConnectionMode;
            if (role != CONNECTION_MODE_PARENT && gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                allowed = FALSE;
            }
            if (allowed != FALSE) {
                shouldStop = TRUE;
            }
        }
        if (shouldStop != FALSE) {
            StopRomArchive();
            gConnectionWork->mFlags &= ~CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER;
        }
        gConnectionWork->mRequestPending = 0;
        return;
    }
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_BLOCK_TRANSFER) != 0) {
        EndWbtStep();
        return;
    }
    gConnectionWork->mStep = CONNECTION_STEP_RESETTING;
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
        gConnectionWork->mStep = CONNECTION_STEP_ROM_ARCHIVE_STOP;
        gConnectionWork->mRequestPending = 1;
        if (IsMultiBootSetupStarted() != FALSE &&
            (GetConnectionMode() == CONNECTION_MODE_PARENT || ConnectionMB_IsMultiBootChild() != FALSE)) {
            allowed = TRUE;
        } else {
            allowed = FALSE;
        }
        if (allowed != FALSE) {
            StopRomArchive();
            gConnectionWork->mFlags &= ~CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER;
        }
        gConnectionWork->mRequestPending = 0;
        return;
    }
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_BLOCK_TRANSFER) != 0) {
        EndWbtStep();
        return;
    }
    gConnectionWork->mStep = CONNECTION_STEP_RESETTING;
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
    SetStepAndRequestPending(CONNECTION_STEP_RESETTING);
    if (WM_Reset(ResetCallback) == 2) {
        return;
    }
    End();
}

void ResetCallback(WirelessMessage *event) {
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
        gConnectionWork->mErrorCode = CONNECTION_ERROR_RESET_FAILED;
        gConnectionWork->mRequestPending = 0;
    } else {
        ResetConnectionData();
    }
}

void SetLifeTime(s32 camLifeTime) {
    gConnectionWork->mStep = CONNECTION_STEP_SETTING_LIFE_TIME;
    gConnectionWork->mRequestPending = 1;
    if (WM_SetLifeTime(SetLifeTimeCallback, 0xffff, camLifeTime, 0xffff, 0xf) != 2) {
        StopConnection();
    }
}

void SetLifeTimeCallback(WirelessMessage *event) {
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
        StopConnection();
    }
}

// Measures each allowed channel 7 times in a row, in two passes over channels 1 to 14, then ends the request;
// measuredChannel is the channel just measured, 0 on the first call, which starts at channel 1.
void MeasureChannel(u16 measuredChannel) {
    u16 allowedChannels;
    u16 channel;
    s32 channelIndex;

    gConnectionWork->mStep = CONNECTION_STEP_CHECKING_CHANNELS;
    gConnectionWork->mRequestPending = 1;
    channel = measuredChannel;
    allowedChannels = WM_GetAllowedChannel();
    if (allowedChannels == 0) {
        gConnectionWork->mRequestPending = 0;
        gConnectionWork->mErrorCode = CONNECTION_ERROR_NO_CHANNEL;
        gConnectionWork->mRequestPending = 0;
    } else if (allowedChannels == 0x8000) {
        gConnectionWork->mRequestPending = 0;
        gConnectionWork->mErrorCode = CONNECTION_ERROR_OPERATION_FAILED;
        gConnectionWork->mRequestPending = 0;
    }
    if (channel == 0) {
        gConnectionWork->mMeasureCount = 1;
        gConnectionWork->mMeasurePass = 1;
        for (channelIndex = 1; channelIndex < 0xe; channelIndex++) {
            gConnectionWork->mChannelSums[channelIndex] = -1;
        }
        channel = 1;
    } else if (gConnectionWork->mMeasureCount >= CONNECTION_MEASURES_PER_CHANNEL) {
        channel = channel + 1;
        gConnectionWork->mMeasureCount = 1;
        if (((1 << (channel - 1)) & allowedChannels) == 0) {
            do {
                channel = channel + 1;
                if (channel > 0xe) {
                    if (gConnectionWork->mMeasurePass >= CONNECTION_MEASURE_PASS_COUNT) {
                        gConnectionWork->mRequestPending = 0;
                        return;
                    }
                    gConnectionWork->mMeasurePass += 1;
                    channel = 1;
                    gConnectionWork->mMeasureCount = 1;
                }
            } while (((1 << (channel - 1)) & allowedChannels) == 0);
        }
    } else {
        gConnectionWork->mMeasureCount += 1;
    }
    if (WM_MeasureChannel(MeasureChannelCallback, 3, 0x11, channel, 0x14) != 2) {
        StopConnection();
    }
}

void MeasureChannelCallback(WirelessMessage *event) {
    s16 *channelSum;

    if (event->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
        StopConnection();
        return;
    }
    channelSum = &gConnectionWork->mChannelSums[event->mReplyState];
    if (*channelSum < 0) {
        *channelSum = 0;
    }
    *channelSum = *channelSum + event->mBusyRatio;
    MeasureChannel(event->mReplyState);
}

void *RomArchiveAllocFunc(s32 unusedValue, u32 size, void *block) {
    u32 savedInterrupts;
    void *allocated;

    allocated = NULL;
    savedInterrupts = OS_DisableInterrupts();
    if (block != NULL) {
        HeapFree(gConnectionWork->mHeap, block);
    } else {
        allocated = HeapAllocAligned(gConnectionWork->mHeap, size, -HEAP_ALIGN_CACHE_LINE);
    }
    OS_RestoreInterrupts(savedInterrupts);
    return allocated;
}

void StartRomArchiveTransfer(void) {
    u32 role;
    BOOL allowed;
    BOOL shouldStart;

    gConnectionWork->mStep = CONNECTION_STEP_ROM_ARCHIVE_TRANSFER;
    gConnectionWork->mRequestPending = 1;
    shouldStart = FALSE;
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
        allowed = TRUE;
        role = gConnectionWork == NULL ? CONNECTION_MODE_NONE : gConnectionWork->mConnectionMode;
        if (role != CONNECTION_MODE_PARENT && gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
            allowed = FALSE;
        }
        if (allowed != FALSE) {
            shouldStart = TRUE;
        }
    }
    if (shouldStart != FALSE) {
        role = gConnectionWork == NULL ? CONNECTION_MODE_NONE : gConnectionWork->mConnectionMode;
        StartRomArchive(role == CONNECTION_MODE_PARENT ? 1 : 0, 4, 0x154, RomArchiveStateCallback, RomArchiveAllocFunc,
                        0);
    }
    gConnectionWork->mRequestPending = 0;
    ResetPendingFiles();
}

void RomArchiveStateCallback(s32 unusedValue) {
    if (gConnectionWork->mStep == CONNECTION_STEP_ROM_ARCHIVE_TRANSFER) {
        if (GetRomArchiveState() == ROM_ARCHIVE_READY) {
            gConnectionWork->mRequestPending = 0;
            ResetPendingFiles();
        }
    } else {
        gConnectionWork->mRequestPending = 0;
    }
}

void StartRomArchiveSend(void) {
    u32 role;
    BOOL allowed;
    BOOL shouldStart;

    gConnectionWork->mStep = CONNECTION_STEP_ROM_ARCHIVE_SEND;
    gConnectionWork->mRequestPending = 1;
    shouldStart = FALSE;
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
        allowed = TRUE;
        role = gConnectionWork == NULL ? CONNECTION_MODE_NONE : gConnectionWork->mConnectionMode;
        if (role != CONNECTION_MODE_PARENT && gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
            allowed = FALSE;
        }
        if (allowed != FALSE) {
            shouldStart = TRUE;
        }
    }
    if (shouldStart != FALSE) {
        StartRomArchivePacketSend();
        gConnectionWork->mSyncState = CONNECTION_SYNC_START;
        gConnectionWork->mFlags |= CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER;
    }
    gConnectionWork->mRequestPending = 0;
}

void StopRomArchiveTransfer(void) {
    u32 role;
    BOOL allowed;
    BOOL shouldStop;

    gConnectionWork->mStep = CONNECTION_STEP_ROM_ARCHIVE_STOP;
    gConnectionWork->mRequestPending = 1;
    shouldStop = FALSE;
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
        allowed = TRUE;
        role = gConnectionWork == NULL ? CONNECTION_MODE_NONE : gConnectionWork->mConnectionMode;
        if (role != CONNECTION_MODE_PARENT && gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
            allowed = FALSE;
        }
        if (allowed != FALSE) {
            shouldStop = TRUE;
        }
    }
    if (shouldStop != FALSE) {
        StopRomArchive();
        gConnectionWork->mFlags &= ~CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER;
    }
    gConnectionWork->mRequestPending = 0;
}

u16 ComputeParentTgid(u32 unusedValue) {
    RTCTime time;
    u32 hour;
    u16 seconds;
    u64 generatorState;
    u64 highWord;

    GetClockTimeOrZero(&time);
    hour = time.mHour;
    if (hour >= 0x12) {
        hour -= 0x12;
    }
    seconds = (hour * 0x3c + time.mMinute) * 0x3c + time.mSecond;
    generatorState = OS_GetTickLo() | seconds << 16;
    generatorState = generatorState * RANDOM_STATE64_MULTIPLIER + RANDOM_STATE64_INCREMENT;
    highWord = generatorState >> 32;
    return (u16) (highWord * 0x10000 >> 32) | PARENT_TGID_FLAG;
}

// Sets the connection mode to parent and calls WM_SetParentParameter with the parent parameter; stops the connection if
// the call is not accepted.
void SetParentParameter(void) {
    gConnectionWork->mConnectionMode = CONNECTION_MODE_PARENT;
    gConnectionWork->mStep = CONNECTION_STEP_SETTING_PARENT_PARAMETER;
    gConnectionWork->mRequestPending = 1;
    if (WM_SetParentParameter(SetParentParameterCallback, gConnectionWork->mParentParameter) != 2) {
        StopConnection();
    }
}

void SetParentParameterCallback(WirelessMessage *event) {
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
        StopConnection();
    }
}

void StartParent(WirelessMessageCallback callback) {
    if (callback == NULL) {
        callback = StartParentCallback;
    }
    gConnectionWork->mStep = CONNECTION_STEP_STARTING_PARENT;
    gConnectionWork->mRequestPending = 1;
    if (WM_StartParent(callback) != 2) {
        StopConnection();
    }
}

// Callback of WM_StartParent: code 7 adds a child; code 9 removes one (and marks it left when a parent is in a synced
// race); code 0 copies the own name and flags into the first player record, seeds the random state and ends the
// request; any other result stops the connection.
void StartParentCallback(WirelessMessage *event) {
    RandomState64 *randomState;
    u32 role;
    u16 seed;
    u32 aid;

    if (event->mResultCode == WIRELESS_RESULT_SUCCEEDED) {
        switch (event->mReplyState) {
            case WIRELESS_STATE_LINKED:
                AddChild(event->mLength, &event->mMacAddress[0], (PlayerRecord *) event->mPeerBytes);
                break;
            case WIRELESS_STATE_SESSION_START:
                MI_CpuCopy8(&gBackupBuffers->mFirstBlock->mPlayerName, &gConnectionWork->mPlayerRecords[0],
                            PLAYER_NAME_BYTES);
                MI_CpuCopy8(&gBackupBuffers->mFirstBlock->mFlags, &gConnectionWork->mPlayerRecords[0].mBits,
                            sizeof(gConnectionWork->mPlayerRecords[0].mBits));
                seed = 0;
                role = gConnectionWork == NULL ? CONNECTION_MODE_NONE : gConnectionWork->mConnectionMode;
                switch (role) {
                    case CONNECTION_MODE_PARENT:
                        seed = gConnectionWork->mParentParameter->mTgid;
                        break;
                    case CONNECTION_MODE_CHILD:
                        seed = gConnectionWork->mParentBssDesc->mGameInfo.mTgid;
                        break;
                }
                randomState = &gConnectionWork->mRandomState;
                randomState->mValue = (u32) (seed * 3 | seed << 16);
                randomState->mMultiplier = RANDOM_STATE64_MULTIPLIER;
                randomState->mIncrement = RANDOM_STATE64_INCREMENT;
                gConnectionWork->mRequestPending = 0;
                break;
            case WIRELESS_STATE_UNLINKED:
                RemoveChild(event->mLength);
                aid = event->mLength;
                role = gConnectionWork == NULL ? CONNECTION_MODE_NONE : gConnectionWork->mConnectionMode;
                if (role == CONNECTION_MODE_PARENT && gConnectionWork->mState == CONNECTION_STATE_SYNCED_RACE) {
                    BIT_SET(gConnectionWork->mLeftParticipantMask[0], aid);
                }
                break;
        }
    } else {
        StopConnection();
    }
}
