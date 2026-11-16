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
#include "Main/Sound/sound_seq.h"
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

    if (g_GlobalZE == NULL) {
        return;
    }
    g_GlobalZE->mConnectionMode = CONNECTION_MODE_NONE;
    g_GlobalZE->mState = CONNECTION_STATE_IDLE;
    g_GlobalZE->mErrorCode = CONNECTION_ERROR_NONE;
    g_GlobalZE->mStep = CONNECTION_STEP_NOTHING;
    g_GlobalZE->mRequestPending = 0;
    g_GlobalZE->mFlags = 0;
    scanParams = g_GlobalZE->mScanParams;
    scanParams->mScanBuf = g_GlobalZE->mScanBssDescBuffer;
    scanParams->mChannel = 0;
    scanParams->mMaxChannelTime = 0;
    for (index = 0; index < 6; index++) {
        scanParams->mBssid[index] = CONNECTION_BSSID_ANY_BYTE;
    }
    scanExParams = g_GlobalZE->mScanExParams;
    scanExParams->mScanBuf = g_GlobalZE->mScanExBuffer;
    scanExParams->mScanBufSize = CONNECTION_SCAN_BUFFER_SIZE;
    scanExParams->mChannelList = 0;
    scanExParams->mMaxChannelTime = 0;
    scanExParams->mScanType = 1;
    scanExParams->mSsidLength = 0;
    for (index = 0; index < 6; index++) {
        scanExParams->mBssid[index] = CONNECTION_BSSID_ANY_BYTE;
    }
    ResetConnectionData();
    blocks = &g_GlobalZE->mBlockTransfer;
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
    StructBin_SomeFn_from_thumb(&g_GlobalZE->mMultiBootState);
    InitMPStateMachine();
    FillParentParameter(1);
}

// Fills the record handed to WM_StepDataSharing, steps the data sharing with it and keeps the result.
void StepDataSharing(void) {
    SharingSendRecord *sendData;
    u32 role;
    s32 result;

    GetSceneFrames();
    sendData = g_GlobalZE->mSharingSendRecord;
    if (g_GlobalZE->mState == CONNECTION_STATE_SYNCED) {
        sendData->mSendByte = g_GlobalZE->mDataSharingSendByte;
    } else {
        sendData->mSendByte = 0;
    }
    sendData->mLeftParticipantMask =
        (g_GlobalZE == NULL ? CONNECTION_MODE_NONE : g_GlobalZE->mConnectionMode) == CONNECTION_MODE_PARENT
            ? g_GlobalZE->mLeftParticipantMask[0]
            : 0;
    sendData->mPadKeys = GetPadKeys();
    sendData->mFlags = 0;
    sendData->mUnk_07 = 0;
    role = CONNECTION_MODE_NONE;
    if (g_GlobalZE->mState == CONNECTION_STATE_SYNCED_RACE) {
        if (g_GlobalZE != NULL) {
            role = g_GlobalZE->mConnectionMode;
        }
        if (role == CONNECTION_MODE_PARENT) {
            if (HasAAFlag8() != FALSE) {
                sendData->mFlags |= SHARING_RECORD_FLAG_DISP_CAP_FADE;
            } else {
                sendData->mFlags &= ~SHARING_RECORD_FLAG_DISP_CAP_FADE;
            }
        }
    }
    role = g_GlobalZE == NULL ? CONNECTION_MODE_NONE : g_GlobalZE->mConnectionMode;
    if (role != CONNECTION_MODE_PARENT || (g_GlobalZE->mStatusFlags & CONNECTION_STATUS_SHARING_SYNCED) != 0) {
        if (g_GlobalZE->mSyncToggle == 0) {
            sendData->mFlags |= SHARING_RECORD_FLAG_SYNC_PHASE_A;
            sendData->mFlags &= ~SHARING_RECORD_FLAG_SYNC_PHASE_B;
        } else {
            sendData->mFlags |= SHARING_RECORD_FLAG_SYNC_PHASE_B;
            sendData->mFlags &= ~SHARING_RECORD_FLAG_SYNC_PHASE_A;
        }
    }
    sendData->mMicOverThreshold = g_Global59C4->mMicOverThreshold;
    sendData->mTouchPoint = GetPackedTouchPoint();
    result = WM_StepDataSharing(g_GlobalZE->mSharingInfo, sendData, g_GlobalZE->mSharingDataSet);
    if (result == 0) {
        if (g_GlobalZE->mState == CONNECTION_STATE_SYNCED) {
            g_GlobalZE->mDataSharingSendByte = 0;
        }
    }
    g_GlobalZE->mSharingStepResult = result;
}

BOOL UpdateDataSharing(void) {
    DataSharing *dataSharing;
    BOOL allRead;
    u16 participantIndex;
    u16 clearIndex;
    u8 receivedMask;
    u8 *sharedData;
    u8 buf[8][8];
    u32 participantMask;
    u32 bit;
    u16 entryIndex;

    dataSharing = &g_GlobalZE->mDataSharing;
    g_GlobalZE->mArrivedMemberMask =
        g_GlobalZE->mSharingInfo->mDs[g_GlobalZE->mSharingInfo->mWriteIndex].mArrivedMembers;
    g_GlobalZE->mFlags &= ~CONNECTION_FLAG_SHARING_NOT_UPDATED;
    switch (g_GlobalZE == NULL ? CONNECTION_MODE_NONE : g_GlobalZE->mConnectionMode) {
        case CONNECTION_MODE_PARENT:
            if (g_GlobalZE->mChildren.mChildCount != 0) {
                StepDataSharing();
            } else {
                return FALSE;
            }
            break;
        case CONNECTION_MODE_CHILD:
            if (g_GlobalZE->mOwnIndex != CONNECTION_OWN_INDEX_NONE) {
                StepDataSharing();
            } else {
                return FALSE;
            }
            break;
    }
    switch (g_GlobalZE->mState) {
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
                if ((g_GlobalZE == NULL ? CONNECTION_MODE_NONE : g_GlobalZE->mConnectionMode) ==
                    CONNECTION_MODE_PARENT) {
                    for (clearIndex = 1; clearIndex < 8; clearIndex++) {
                        if (BIT_IS_SET(g_GlobalZE->mParticipantMask, clearIndex)) {
                            g_GlobalZE->mUnk_15f8[clearIndex - 1] = 0;
                        }
                    }
                }
            }
            break;
    }
    allRead = TRUE;
    sharedData = WM_GetSharedDataAddress(g_GlobalZE->mSharingInfo, g_GlobalZE->mSharingDataSet, 0);
    if (sharedData != NULL) {
        receivedMask = sharedData[4];
        if (receivedMask != 0) {
            for (participantIndex = 0; participantIndex < 8; participantIndex++) {
                bit = 1 << participantIndex;
                participantMask = g_GlobalZE->mParticipantMask;
                entryIndex = g_GlobalZE->mParticipantPosByIndex[participantIndex].mEntryIndex;
                if ((participantMask & bit) != 0 && (receivedMask & bit) != 0) {
                    g_GlobalZE->mParticipantMask = participantMask & ~bit;
                    if (g_GlobalZE->mState == CONNECTION_STATE_SYNCED_RACE) {
                        RemoveRaceProgressKart(entryIndex);
                    }
                    if ((g_GlobalZE == NULL ? CONNECTION_MODE_NONE : g_GlobalZE->mConnectionMode) ==
                        CONNECTION_MODE_PARENT) {
                        g_GlobalZE->mLeftParticipantMask[0] &= ~bit;
                    }
                }
            }
        }
        Mem_CpuCopy8(sharedData, &buf[0], 8);
    } else {
        allRead = FALSE;
    }
    if (allRead != FALSE) {
        for (participantIndex = 1; participantIndex < 8; participantIndex++) {
            if (BIT_IS_SET(g_GlobalZE->mParticipantMask, participantIndex)) {
                sharedData = WM_GetSharedDataAddress(g_GlobalZE->mSharingInfo, g_GlobalZE->mSharingDataSet,
                                                     participantIndex);
                if (sharedData != NULL) {
                    Mem_CpuCopy8(sharedData, &buf[participantIndex], 8);
                } else {
                    allRead = FALSE;
                    break;
                }
            }
        }
    }
    for (participantIndex = 0; participantIndex < 8; participantIndex++) {
        if (allRead != FALSE && BIT_IS_SET(g_GlobalZE->mParticipantMask, participantIndex)) {
            Mem_CpuCopy8(&buf[participantIndex], &dataSharing->mReceivedRecords[participantIndex], 8);
            dataSharing->mSharedDataCopied[participantIndex] = 1;
        } else {
            dataSharing->mSharedDataCopied[participantIndex] = 0;
        }
    }
    return allRead != FALSE;
}

void Initialize(void) {
    g_GlobalZE->mStep = CONNECTION_STEP_STARTING_UP;
    g_GlobalZE->mRequestPending = 1;
    if (StructWM_SomeFn(g_GlobalZE->mWmWorkBuffer, InitializeCallback, 2) != 2) {
        g_GlobalZE->mRequestPending = 0;
    }
}

void InitializeCallback(WirelessMessage *event) {
    s32 result;

    result = WM_SetPortCallback(0xf, MPDataPortCallback, NULL);
    g_GlobalZE->mRequestPending = 0;
    if (result != 0) {
        return;
    }
    if (event->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
        return;
    }
    if (g_GlobalZE->mConnectionKind != 0) {
        WM_SetPortCallback(1, PacketPortCallback, NULL);
    }
    ResetConnectionData();
}

void StopConnection(void) {
    u32 role;
    BOOL shouldStop;
    BOOL allowed;

    if ((g_GlobalZE->mFlags & CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER) != 0) {
        g_GlobalZE->mStep = CONNECTION_STEP_ROM_ARCHIVE_STOP;
        g_GlobalZE->mRequestPending = 1;
        shouldStop = FALSE;
        if ((g_GlobalZE->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
            allowed = TRUE;
            role = g_GlobalZE == NULL ? CONNECTION_MODE_NONE : g_GlobalZE->mConnectionMode;
            if (role != CONNECTION_MODE_PARENT && gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                allowed = FALSE;
            }
            if (allowed != FALSE) {
                shouldStop = TRUE;
            }
        }
        if (shouldStop != FALSE) {
            StopRomArchive();
            g_GlobalZE->mFlags &= ~CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER;
        }
        g_GlobalZE->mRequestPending = 0;
        return;
    }
    if ((g_GlobalZE->mFlags & CONNECTION_FLAG_BLOCK_TRANSFER) != 0) {
        EndWbtStep();
        return;
    }
    g_GlobalZE->mStep = CONNECTION_STEP_RESTARTING;
    g_GlobalZE->mRequestPending = 1;
    if (WM_Reset(ResetCallback) == 2) {
        return;
    }
    g_GlobalZE->mStep = CONNECTION_STEP_SHUTTING_DOWN;
    g_GlobalZE->mRequestPending = 1;
    if (WM_End(EndCallback) == 2) {
        return;
    }
    if ((g_GlobalZE->mFlags & CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER) != 0) {
        g_GlobalZE->mStep = CONNECTION_STEP_ROM_ARCHIVE_STOP;
        g_GlobalZE->mRequestPending = 1;
        if (IsMultiBootSetupStarted() != FALSE &&
            (GetConnectionMode() == CONNECTION_MODE_PARENT || ConnectionMB_IsMultiBootChild() != FALSE)) {
            allowed = TRUE;
        } else {
            allowed = FALSE;
        }
        if (allowed != FALSE) {
            StopRomArchive();
            g_GlobalZE->mFlags &= ~CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER;
        }
        g_GlobalZE->mRequestPending = 0;
        return;
    }
    if ((g_GlobalZE->mFlags & CONNECTION_FLAG_BLOCK_TRANSFER) != 0) {
        EndWbtStep();
        return;
    }
    g_GlobalZE->mStep = CONNECTION_STEP_RESTARTING;
    g_GlobalZE->mRequestPending = 1;
    if (WM_Reset(ResetCallback) == 2) {
        return;
    }
    g_GlobalZE->mStep = CONNECTION_STEP_SHUTTING_DOWN;
    g_GlobalZE->mRequestPending = 1;
    if (WM_End(EndCallback) == 2) {
        return;
    }
    if ((g_GlobalZE->mFlags & CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER) != 0) {
        StopRomArchiveTransfer();
        return;
    }
    if ((g_GlobalZE->mFlags & CONNECTION_FLAG_BLOCK_TRANSFER) != 0) {
        EndWbtStep();
        return;
    }
    SetStepAndRequestPending(CONNECTION_STEP_RESTARTING);
    if (WM_Reset(ResetCallback) == 2) {
        return;
    }
    End();
}

void ResetCallback(WirelessMessage *event) {
    g_GlobalZE->mRequestPending = 0;
    if (event->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
        g_GlobalZE->mErrorCode = CONNECTION_ERROR_RESET_FAILED;
        g_GlobalZE->mRequestPending = 0;
    } else {
        ResetConnectionData();
    }
}

void SetLifeTime(s32 camLifeTime) {
    g_GlobalZE->mStep = CONNECTION_STEP_SETTING_TIMEOUT;
    g_GlobalZE->mRequestPending = 1;
    if (WM_SetLifeTime(SetLifeTimeCallback, 0xffff, camLifeTime, 0xffff, 0xf) != 2) {
        StopConnection();
    }
}

void SetLifeTimeCallback(WirelessMessage *event) {
    g_GlobalZE->mRequestPending = 0;
    if (event->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
        StopConnection();
    }
}

// Measures each allowed channel 7 times in a row, in two passes over channels 1 to 14; a is the one just measured.
void MeasureChannel(u16 measuredChannel) {
    u16 allowedChannels;
    u16 channel;
    s32 channelIndex;

    g_GlobalZE->mStep = CONNECTION_STEP_CHECKING_CHANNELS;
    g_GlobalZE->mRequestPending = 1;
    channel = measuredChannel;
    allowedChannels = WM_GetAllowedChannel();
    if (allowedChannels == 0) {
        g_GlobalZE->mRequestPending = 0;
        g_GlobalZE->mErrorCode = CONNECTION_ERROR_NO_CHANNEL;
        g_GlobalZE->mRequestPending = 0;
    } else if (allowedChannels == 0x8000) {
        g_GlobalZE->mRequestPending = 0;
        g_GlobalZE->mErrorCode = CONNECTION_ERROR_OPERATION_FAILED;
        g_GlobalZE->mRequestPending = 0;
    }
    if (channel == 0) {
        g_GlobalZE->mMeasureCount = 1;
        g_GlobalZE->mMeasurePass = 1;
        for (channelIndex = 1; channelIndex < 0xe; channelIndex++) {
            g_GlobalZE->mChannelSums[channelIndex] = -1;
        }
        channel = 1;
    } else if (g_GlobalZE->mMeasureCount >= CONNECTION_MEASURES_PER_CHANNEL) {
        channel = channel + 1;
        g_GlobalZE->mMeasureCount = 1;
        if (((1 << (channel - 1)) & allowedChannels) == 0) {
            do {
                channel = channel + 1;
                if (channel > 0xe) {
                    if (g_GlobalZE->mMeasurePass >= CONNECTION_MEASURE_PASS_COUNT) {
                        g_GlobalZE->mRequestPending = 0;
                        return;
                    }
                    g_GlobalZE->mMeasurePass += 1;
                    channel = 1;
                    g_GlobalZE->mMeasureCount = 1;
                }
            } while (((1 << (channel - 1)) & allowedChannels) == 0);
        }
    } else {
        g_GlobalZE->mMeasureCount += 1;
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
    channelSum = &g_GlobalZE->mChannelSums[event->mReplyState];
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
    savedInterrupts = Os_DisableIrq();
    if (block != NULL) {
        Mem_FreeHeap(g_GlobalZE->mHeap, block);
    } else {
        allocated = Mem_AllocateHeapAligned(g_GlobalZE->mHeap, size, -0x20);
    }
    Os_RestoreIrq(savedInterrupts);
    return allocated;
}

void StartRomArchiveTransfer(void) {
    u32 role;
    BOOL flag;
    BOOL shouldStart;

    g_GlobalZE->mStep = CONNECTION_STEP_ROM_ARCHIVE_TRANSFER;
    g_GlobalZE->mRequestPending = 1;
    shouldStart = FALSE;
    if ((g_GlobalZE->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
        flag = TRUE;
        role = g_GlobalZE == NULL ? CONNECTION_MODE_NONE : g_GlobalZE->mConnectionMode;
        if (role != CONNECTION_MODE_PARENT && gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
            flag = FALSE;
        }
        if (flag != FALSE) {
            shouldStart = TRUE;
        }
    }
    if (shouldStart != FALSE) {
        role = g_GlobalZE == NULL ? CONNECTION_MODE_NONE : g_GlobalZE->mConnectionMode;
        StartRomArchive(role == CONNECTION_MODE_PARENT ? 1 : 0, 4, 0x154, RomArchiveStateCallback, RomArchiveAllocFunc,
                        0);
    }
    g_GlobalZE->mRequestPending = 0;
    ResetPendingFiles();
}

void RomArchiveStateCallback(s32 unusedValue) {
    if (g_GlobalZE->mStep == CONNECTION_STEP_ROM_ARCHIVE_TRANSFER) {
        if (GetRomArchiveState() == ROM_ARCHIVE_READY) {
            g_GlobalZE->mRequestPending = 0;
            ResetPendingFiles();
        }
    } else {
        g_GlobalZE->mRequestPending = 0;
    }
}

void StartRomArchiveSend(void) {
    u32 role;
    BOOL allowed;
    BOOL shouldStart;

    g_GlobalZE->mStep = CONNECTION_STEP_ROM_ARCHIVE_SEND;
    g_GlobalZE->mRequestPending = 1;
    shouldStart = FALSE;
    if ((g_GlobalZE->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
        allowed = TRUE;
        role = g_GlobalZE == NULL ? CONNECTION_MODE_NONE : g_GlobalZE->mConnectionMode;
        if (role != CONNECTION_MODE_PARENT && gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
            allowed = FALSE;
        }
        if (allowed != FALSE) {
            shouldStart = TRUE;
        }
    }
    if (shouldStart != FALSE) {
        StartRomArchivePacketSend();
        g_GlobalZE->mSyncState = CONNECTION_SYNC_START;
        g_GlobalZE->mFlags |= CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER;
    }
    g_GlobalZE->mRequestPending = 0;
}

void StopRomArchiveTransfer(void) {
    u32 role;
    BOOL flag;
    BOOL shouldStop;

    g_GlobalZE->mStep = CONNECTION_STEP_ROM_ARCHIVE_STOP;
    g_GlobalZE->mRequestPending = 1;
    shouldStop = FALSE;
    if ((g_GlobalZE->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
        flag = TRUE;
        role = g_GlobalZE == NULL ? CONNECTION_MODE_NONE : g_GlobalZE->mConnectionMode;
        if (role != CONNECTION_MODE_PARENT && gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
            flag = FALSE;
        }
        if (flag != FALSE) {
            shouldStop = TRUE;
        }
    }
    if (shouldStop != FALSE) {
        StopRomArchive();
        g_GlobalZE->mFlags &= ~CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER;
    }
    g_GlobalZE->mRequestPending = 0;
}

u16 ComputeParentTgid(u32 unusedValue) {
    RTCTime time;
    u32 hour;
    u16 seconds;
    u64 generatorState;
    u64 highWord;

    GetCurrentTime(&time);
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

// Calls WM_SetParentParameter; also stores 1 in the first session word.
void SetParentParameter(void) {
    g_GlobalZE->mConnectionMode = CONNECTION_MODE_PARENT;
    g_GlobalZE->mStep = CONNECTION_STEP_CONFIGURING_HOST;
    g_GlobalZE->mRequestPending = 1;
    if (WM_SetParentParameter(SetParentParameterCallback, g_GlobalZE->mParentParameter) != 2) {
        StopConnection();
    }
}

void SetParentParameterCallback(WirelessMessage *event) {
    g_GlobalZE->mRequestPending = 0;
    if (event->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
        StopConnection();
    }
}

void StartParent(WirelessMessageCallback callback) {
    if (callback == NULL) {
        callback = StartParentCallback;
    }
    g_GlobalZE->mStep = CONNECTION_STEP_OPENING_HOST;
    g_GlobalZE->mRequestPending = 1;
    if (WM_StartParent(callback) != 2) {
        StopConnection();
    }
}

// Callback of WM_StartParent: code 7 adds a child, 9 removes one, 0 copies the own data into the first member record.
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
                Mem_CpuCopy8(&g_SaveDataHolder->mFirstBlock->mPlayerName, &g_GlobalZE->mPlayerRecords[0],
                            PLAYER_NAME_BYTES);
                Mem_CpuCopy8(&g_SaveDataHolder->mFirstBlock->mFlags, &g_GlobalZE->mPlayerRecords[0].mBits,
                            sizeof(g_GlobalZE->mPlayerRecords[0].mBits));
                seed = 0;
                role = g_GlobalZE == NULL ? CONNECTION_MODE_NONE : g_GlobalZE->mConnectionMode;
                switch (role) {
                    case CONNECTION_MODE_PARENT:
                        seed = g_GlobalZE->mParentParameter->mTgid;
                        break;
                    case CONNECTION_MODE_CHILD:
                        seed = g_GlobalZE->mParentBssDesc->mGameInfo.mTgid;
                        break;
                }
                randomState = &g_GlobalZE->mRandomState;
                randomState->mValue = (u32) (seed * 3 | seed << 16);
                randomState->mMultiplier = RANDOM_STATE64_MULTIPLIER;
                randomState->mIncrement = RANDOM_STATE64_INCREMENT;
                g_GlobalZE->mRequestPending = 0;
                break;
            case WIRELESS_STATE_UNLINKED:
                RemoveChild(event->mLength);
                aid = event->mLength;
                role = g_GlobalZE == NULL ? CONNECTION_MODE_NONE : g_GlobalZE->mConnectionMode;
                if (role == CONNECTION_MODE_PARENT && g_GlobalZE->mState == CONNECTION_STATE_SYNCED_RACE) {
                    BIT_SET(g_GlobalZE->mLeftParticipantMask[0], aid);
                }
                break;
        }
    } else {
        StopConnection();
    }
}
