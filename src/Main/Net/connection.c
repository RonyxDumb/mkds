#include "Main/Net/connection.h"
#include "Main/System/heap.h"
#include "Main/Menu/title_scene.h"
#include "Main/System/touch_mic_input.h"
#include "Main/Net/participant_get_connection.h"
#include "Main/Unknown/code_0200f000.h"
#include "os_tick.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Scene/scene_frames.h"
#include "Main/Unknown/code_0204b000.h"
#include "Main/Net/connection_sharing.h"
#include "Main/Graphics/disp_cap.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Net/rom_archive.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_0204f5e4.h"
#include "Main/Net/disconnect.h"
#include "Main/Unknown/code_02053000.h"
#include "Main/Unknown/code_02055000.h"
#include "Main/Net/mp_chunk_state_machine.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200fc8c.h"
#include "code_02142eac.h"
#include "code_021445e0.h"
#include "wm_etc.h"
#include "code_0214d018.h"
#include "Main/Race/race_progress_rank.h"

void ResetConnection(void) {
    ScanParam *scanParams;
    ScanExParam *scanExParams;
    BlockTransferView *blocks;
    BlockEntry *blockEntry;
    s32 index;

    if (gConnectionWork == NULL) {
        return;
    }
    gConnectionWork->mConnectionMode = 0;
    gConnectionWork->mState = 0;
    gConnectionWork->mErrorCode = 9;
    gConnectionWork->mStep = 0;
    gConnectionWork->mRequestPending = 0;
    gConnectionWork->mFlags = 0;
    scanParams = gConnectionWork->mScanParams;
    scanParams->mScanBuf = gConnectionWork->mScanBssDescBuffer;
    scanParams->mChannel = 0;
    scanParams->mMaxChannelTime = 0;
    for (index = 0; index < 6; index++) {
        scanParams->mBssid[index] = 0xff;
    }
    scanExParams = gConnectionWork->mScanExParams;
    scanExParams->mScanBuf = gConnectionWork->mScanExBuffer;
    scanExParams->mScanBufSize = 0x400;
    scanExParams->mChannelList = 0;
    scanExParams->mMaxChannelTime = 0;
    scanExParams->mScanType = 1;
    scanExParams->mSsidLength = 0;
    for (index = 0; index < 6; index++) {
        scanExParams->mBssid[index] = 0xff;
    }
    ResetConnectionData();
    blocks = &gConnectionWork->mUnk_16a0_view;
    blockEntry = &blocks->mBlockEntries[0];
    for (index = 0; index < 0xc; index++) {
        blockEntry->mPath = 0;
        blockEntry->mBuffer = NULL;
        blockEntry++;
    }
    blocks->mUnk_6b4 = 0;
    blocks->mUnk_660 = 0;
    blocks->mZeroWordReceived = FALSE;
    blocks->mMPSetupActive = FALSE;
    ResetConnectionBuffers(&gConnectionWork->mUnk_1658_view);
    InitMPStateMachine();
    FillParentParameter(1);
}

// Fills the record handed to WM_StepDataSharing, steps the data sharing with it and keeps the result.
void StepDataSharing(void) {
    SharingSendRecord *sendData;
    u32 role;
    s32 result;

    GetSceneFrames();
    sendData = gConnectionWork->mSharingSendRecord;
    if (gConnectionWork->mState == 8) {
        sendData->mSendByte = gConnectionWork->mDataSharingSendByte;
    } else {
        sendData->mSendByte = 0;
    }
    sendData->mLeftParticipantMask = (gConnectionWork == NULL ? 0 : gConnectionWork->mConnectionMode) == 1
                                         ? gConnectionWork->mLeftParticipantMask[0]
                                         : 0;
    sendData->mPadKeys = GetPadKeys();
    sendData->mUnk_06_0 = 0;
    sendData->mUnk_07 = 0;
    role = 0;
    if (gConnectionWork->mState == 9) {
        if (gConnectionWork != NULL) {
            role = gConnectionWork->mConnectionMode;
        }
        if (role == 1) {
            if (IsDispCapFadeFlagSet() != FALSE) {
                sendData->mUnk_06_0 |= 4;
            } else {
                sendData->mUnk_06_0 &= ~4;
            }
        }
    }
    role = gConnectionWork == NULL ? 0 : gConnectionWork->mConnectionMode;
    if (role != 1 || (gConnectionWork->mStatusFlags & CONNECTION_STATUS_SHARING_SYNCED) != 0) {
        if (gConnectionWork->mSyncToggle == 0) {
            sendData->mUnk_06_0 |= 1;
            sendData->mUnk_06_0 &= ~2;
        } else {
            sendData->mUnk_06_0 |= 2;
            sendData->mUnk_06_0 &= ~1;
        }
    }
    sendData->mMicOverThreshold = gTouchMicInput->mMicOverThreshold;
    sendData->mTouchPoint = GetPackedTouchPoint();
    result = WM_StepDataSharing(gConnectionWork->mSharingInfo, sendData, gConnectionWork->mSharingDataSet);
    if (result == 0) {
        if (gConnectionWork->mState == 8) {
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
    u8 receivedMask;
    u8 *sharedData;
    u8 buf[8][8];
    u32 participantMask;
    u32 bit;
    u16 entryIndex;

    dataSharing = &gConnectionWork->mUnk_15bc_view;
    gConnectionWork->mArrivedMemberMask =
        gConnectionWork->mSharingInfo->mDs[gConnectionWork->mSharingInfo->mWriteIndex].mArrivedMembers;
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SHARING_NOT_UPDATED;
    switch (gConnectionWork == NULL ? 0 : gConnectionWork->mConnectionMode) {
        case 1:
            if (gConnectionWork->mChildren.mChildCount != 0) {
                StepDataSharing();
            } else {
                return FALSE;
            }
            break;
        case 2:
            if (gConnectionWork->mOwnIndex != 0xffff) {
                StepDataSharing();
            } else {
                return FALSE;
            }
            break;
    }
    switch (gConnectionWork->mState) {
        case 8:
            if (dataSharing->mSharingPhase != 0 && dataSharing->mSharingPhase == 5) {
                return FALSE;
            }
            break;
        case 9:
            if (dataSharing->mSharingPhase != 0) {
                if (dataSharing->mSharingPhase == 5) {
                    return FALSE;
                }
            } else {
                if ((gConnectionWork == NULL ? 0 : gConnectionWork->mConnectionMode) == 1) {
                    for (clearIndex = 1; clearIndex < 8; clearIndex++) {
                        if ((gConnectionWork->mParticipantMask & (1 << clearIndex)) != 0) {
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
        receivedMask = sharedData[4];
        if (receivedMask != 0) {
            for (participantIndex = 0; participantIndex < 8; participantIndex++) {
                bit = 1 << participantIndex;
                participantMask = gConnectionWork->mParticipantMask;
                entryIndex = gConnectionWork->mParticipantPosByIndex[participantIndex].mEntryIndex;
                if ((participantMask & bit) != 0 && (receivedMask & bit) != 0) {
                    gConnectionWork->mParticipantMask = participantMask & ~bit;
                    if (gConnectionWork->mState == 9) {
                        RemoveRaceProgressKart(entryIndex);
                    }
                    if ((gConnectionWork == NULL ? 0 : gConnectionWork->mConnectionMode) == 1) {
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
            if ((gConnectionWork->mParticipantMask & (1 << participantIndex)) != 0) {
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
        if (allRead != FALSE && (gConnectionWork->mParticipantMask & (1 << participantIndex)) != 0) {
            MI_CpuCopy8(&buf[participantIndex], &dataSharing->mReceivedRecords[participantIndex], 8);
            dataSharing->mSharedDataCopied[participantIndex] = 1;
        } else {
            dataSharing->mSharedDataCopied[participantIndex] = 0;
        }
    }
    return allRead != FALSE;
}

void Initialize(void) {
    gConnectionWork->mStep = 1;
    gConnectionWork->mRequestPending = 1;
    if (WM_Initialize(gConnectionWork->mWmWorkBuffer, InitializeCallback, 2) != 2) {
        gConnectionWork->mRequestPending = 0;
    }
}

void InitializeCallback(Unk021425e8 *event) {
    s32 result;

    result = WM_SetPortCallback(0xf, MPDataPortCallback, NULL);
    gConnectionWork->mRequestPending = 0;
    if (result != 0) {
        return;
    }
    if (event->mResultCode != 0) {
        return;
    }
    if (gConnectionWork->mConnectionKind != 0) {
        WM_SetPortCallback(1, PacketPortCallback, NULL);
    }
    ResetConnectionData();
}

void StopConnection(void) {
    u32 role;
    BOOL shouldStop;
    BOOL allowed;

    if ((gConnectionWork->mFlags & CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER) != 0) {
        gConnectionWork->mStep = 0x26;
        gConnectionWork->mRequestPending = 1;
        shouldStop = FALSE;
        if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
            allowed = TRUE;
            role = gConnectionWork == NULL ? 0 : gConnectionWork->mConnectionMode;
            if (role != 1 && gBootInfo->mBootType != 2) {
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
    gConnectionWork->mStep = 2;
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
        gConnectionWork->mStep = 0x26;
        gConnectionWork->mRequestPending = 1;
        if (IsMultiBootSetupStarted() != FALSE &&
            (GetConnectionMode() == 1 || ConnectionMB_IsMultiBootChild() != FALSE)) {
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
    gConnectionWork->mStep = 2;
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

void ResetCallback(Unk021425e8 *event) {
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode != 0) {
        gConnectionWork->mErrorCode = 1;
        gConnectionWork->mRequestPending = 0;
    } else {
        ResetConnectionData();
    }
}

void SetLifeTime(s32 camLifeTime) {
    gConnectionWork->mStep = 3;
    gConnectionWork->mRequestPending = 1;
    if (WM_SetLifeTime(SetLifeTimeCallback, 0xffff, camLifeTime, 0xffff, 0xf) != 2) {
        StopConnection();
    }
}

void SetLifeTimeCallback(Unk021425e8 *event) {
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode != 0) {
        StopConnection();
    }
}

// Measures each allowed channel 7 times in a row, in two passes over channels 1 to 14; a is the one just measured.
void MeasureChannel(u16 measuredChannel) {
    u16 allowedChannels;
    u16 channel;
    s32 channelIndex;

    gConnectionWork->mStep = 4;
    gConnectionWork->mRequestPending = 1;
    channel = measuredChannel;
    allowedChannels = WM_GetAllowedChannel();
    if (allowedChannels == 0) {
        gConnectionWork->mRequestPending = 0;
        gConnectionWork->mErrorCode = 3;
        gConnectionWork->mRequestPending = 0;
    } else if (allowedChannels == 0x8000) {
        gConnectionWork->mRequestPending = 0;
        gConnectionWork->mErrorCode = 8;
        gConnectionWork->mRequestPending = 0;
    }
    if (channel == 0) {
        gConnectionWork->mMeasureCount = 1;
        gConnectionWork->mMeasurePass = 1;
        for (channelIndex = 1; channelIndex < 0xe; channelIndex++) {
            gConnectionWork->mChannelSums[channelIndex] = -1;
        }
        channel = 1;
    } else if (gConnectionWork->mMeasureCount >= 7) {
        channel = channel + 1;
        gConnectionWork->mMeasureCount = 1;
        if (((1 << (channel - 1)) & allowedChannels) == 0) {
            do {
                channel = channel + 1;
                if (channel > 0xe) {
                    if (gConnectionWork->mMeasurePass >= 2) {
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

void MeasureChannelCallback(Unk021425e8 *event) {
    s16 *channelSum;

    if (event->mResultCode != 0) {
        StopConnection();
        return;
    }
    channelSum = &gConnectionWork->mChannelSums[event->mReplyState];
    if (*channelSum < 0) {
        *channelSum = 0;
    }
    *channelSum = *channelSum + event->mUnk_08_2;
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
        allocated = HeapAllocAligned(gConnectionWork->mHeap, size, -0x20);
    }
    OS_RestoreInterrupts(savedInterrupts);
    return allocated;
}

void StartRomArchiveTransfer(void) {
    u32 role;
    BOOL flag;
    BOOL shouldStart;

    gConnectionWork->mStep = 0x24;
    gConnectionWork->mRequestPending = 1;
    shouldStart = FALSE;
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
        flag = TRUE;
        role = gConnectionWork == NULL ? 0 : gConnectionWork->mConnectionMode;
        if (role != 1 && gBootInfo->mBootType != 2) {
            flag = FALSE;
        }
        if (flag != FALSE) {
            shouldStart = TRUE;
        }
    }
    if (shouldStart != FALSE) {
        role = gConnectionWork == NULL ? 0 : gConnectionWork->mConnectionMode;
        StartRomArchive(role == 1 ? 1 : 0, 4, 0x154, RomArchiveStateCallback, RomArchiveAllocFunc, 0);
    }
    gConnectionWork->mRequestPending = 0;
    ResetPendingFiles();
}

void RomArchiveStateCallback(s32 unusedValue) {
    if (gConnectionWork->mStep == 0x24) {
        if (GetRomArchiveState() == 2) {
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

    gConnectionWork->mStep = 0x25;
    gConnectionWork->mRequestPending = 1;
    shouldStart = FALSE;
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
        allowed = TRUE;
        role = gConnectionWork == NULL ? 0 : gConnectionWork->mConnectionMode;
        if (role != 1 && gBootInfo->mBootType != 2) {
            allowed = FALSE;
        }
        if (allowed != FALSE) {
            shouldStart = TRUE;
        }
    }
    if (shouldStart != FALSE) {
        StartRomArchivePacketSend();
        gConnectionWork->mSyncState = 0;
        gConnectionWork->mFlags |= CONNECTION_FLAG_ROM_ARCHIVE_TRANSFER;
    }
    gConnectionWork->mRequestPending = 0;
}

void StopRomArchiveTransfer(void) {
    u32 role;
    BOOL flag;
    BOOL shouldStop;

    gConnectionWork->mStep = 0x26;
    gConnectionWork->mRequestPending = 1;
    shouldStop = FALSE;
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
        flag = TRUE;
        role = gConnectionWork == NULL ? 0 : gConnectionWork->mConnectionMode;
        if (role != 1 && gBootInfo->mBootType != 2) {
            flag = FALSE;
        }
        if (flag != FALSE) {
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
    generatorState = generatorState * 0x5d588b656c078965ull + 0x269ec3;
    highWord = generatorState >> 32;
    return (u16) (highWord * 0x10000 >> 32) | 0x8000;
}

// Calls WM_SetParentParameter; also stores 1 in the first session word.
void SetParentParameter(void) {
    gConnectionWork->mConnectionMode = 1;
    gConnectionWork->mStep = 5;
    gConnectionWork->mRequestPending = 1;
    if (WM_SetParentParameter(SetParentParameterCallback, gConnectionWork->mParentParameter) != 2) {
        StopConnection();
    }
}

void SetParentParameterCallback(Unk021425e8 *event) {
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode != 0) {
        StopConnection();
    }
}

void StartParent(Unk021425e8Func callback) {
    if (callback == NULL) {
        callback = StartParentCallback;
    }
    gConnectionWork->mStep = 6;
    gConnectionWork->mRequestPending = 1;
    if (WM_StartParent(callback) != 2) {
        StopConnection();
    }
}

// Callback of WM_StartParent: code 7 adds a child, 9 removes one, 0 copies the own data into the first member record.
void StartParentCallback(Unk021425e8 *event) {
    RandomState64 *randomState;
    u32 role;
    u16 seed;
    u32 aid;

    if (event->mResultCode == 0) {
        switch (event->mReplyState) {
            case 7:
                AddChild(event->mLength, &event->mMacAddress[0], (PlayerRecord *) event->mPeerBytes);
                break;
            case 0:
                MI_CpuCopy8(&gBackupBuffers->mFirstBlock->mPlayerName, &gConnectionWork->mPlayerRecords[0], 0x14);
                MI_CpuCopy8(&gBackupBuffers->mFirstBlock->mFlags, &gConnectionWork->mPlayerRecords[0].mBits, 4);
                seed = 0;
                role = gConnectionWork == NULL ? 0 : gConnectionWork->mConnectionMode;
                switch (role) {
                    case 1:
                        seed = gConnectionWork->mParentParameter->mTgid;
                        break;
                    case 2:
                        seed = gConnectionWork->mParentBssDesc->mGameInfo.mTgid;
                        break;
                }
                randomState = &gConnectionWork->mRandomState;
                randomState->mValue = (u32) (seed * 3 | seed << 16);
                randomState->mMultiplier = 0x5d588b656c078965ull;
                randomState->mIncrement = 0x269ec3;
                gConnectionWork->mRequestPending = 0;
                break;
            case 9:
                RemoveChild(event->mLength);
                aid = event->mLength;
                role = gConnectionWork == NULL ? 0 : gConnectionWork->mConnectionMode;
                if (role == 1 && gConnectionWork->mState == 9) {
                    gConnectionWork->mLeftParticipantMask[0] |= 1 << aid;
                }
                break;
        }
    } else {
        StopConnection();
    }
}
