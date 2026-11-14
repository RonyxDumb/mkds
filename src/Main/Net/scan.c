#include "Main/Net/scan.h"
#include "os_thread.h"
#include "code_0200eddc.h"
#include "Main/Net/scan_game_info.h"
#include "Main/Net/multiboot_connect.h"
#include "Main/Net/mp_link.h"
#include "Main/Net/packet_port.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Net/block.h"
#include "Main/Net/scan_ghost_info.h"
#include "Main/Net/request_pending.h"
#include "Main/Net/connection.h"
#include "Main/Net/connection_sharing.h"
#include "code_021445e0.h"
#include "wm_etc.h"
#include "code_02142eac.h"
#include "code_0214d018.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/Menu/data_02175000.h"

static inline u32 ScanGetConnectionMode(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

void StartScan(s32 isRepeat, s32 (*resultCallback)(), s32 (*filterCallback)()) {
    ConnectionWork *connection;
    ScanStateView *scanState;
    ScanParam *scanParams;
    u16 channel;
    s32 index;
    u16 allowedChannels;

    connection = gConnectionWork;
    scanState = &connection->mScanState;
    channel = scanState->mChannel;
    scanParams = connection->mScanParams;
    connection->mConnectionMode = CONNECTION_MODE_CHILD;
    gConnectionWork->mStep = CONNECTION_STEP_SEARCHING;
    gConnectionWork->mRequestPending = 1;
    allowedChannels = WM_GetAllowedChannel();
    if (allowedChannels == 0) {
        gConnectionWork->mRequestPending = 0;
        gConnectionWork->mErrorCode = CONNECTION_ERROR_NO_CHANNEL;
        gConnectionWork->mRequestPending = 0;
        return;
    }
    if (allowedChannels == 0x8000) {
        gConnectionWork->mRequestPending = 0;
        gConnectionWork->mErrorCode = CONNECTION_ERROR_OPERATION_FAILED;
        gConnectionWork->mRequestPending = 0;
        return;
    }
    if (scanState->mTargetRemaining == 0) {
        if (((1 << (channel - 1)) & allowedChannels) == 0) {
            do {
                channel = channel + 1;
                if (channel > 0xe) {
                    channel = 1;
                }
            } while (((1 << (channel - 1)) & allowedChannels) == 0);
        }
        scanParams->mChannel = channel;
        scanState->mChannel = channel;
        for (index = 0; index < 6; index++) {
            scanParams->mBssid[index] = 0xff;
        }
    } else {
        scanParams->mBssid[0] = scanState->mTargetAddress[0];
        scanParams->mBssid[1] = scanState->mTargetAddress[1];
        scanParams->mBssid[2] = scanState->mTargetAddress[2];
        scanParams->mBssid[3] = scanState->mTargetAddress[3];
        scanParams->mBssid[4] = scanState->mTargetAddress[4];
        scanParams->mBssid[5] = scanState->mTargetAddress[5];
        scanState->mTargetRemaining = scanState->mTargetRemaining - 1;
    }
    scanParams->mMaxChannelTime = WM_GetDispersionScanPeriod();
    if (WM_StartScan(StartScanCallback, scanParams) != 2) {
        gConnectionWork->mOperationFlags &= ~CONNECTION_OPERATION_SCANNING;
        StopConnection();
        return;
    }
    gConnectionWork->mOperationFlags |= CONNECTION_OPERATION_SCANNING;
    gConnectionWork->mScanResultCallback = resultCallback;
    gConnectionWork->mScanFilterCallback = filterCallback;
    if (isRepeat != 0) {
        scanState->mIsRepeat = 1;
    } else {
        scanState->mIsRepeat = 0;
    }
}

void FillScanSlot(ScanSlot *slot, WMBssDesc *scanBuffer, ScanMacAddress *key, UserGameInfo *gameInfo, u8 entryIndex) {
    s32 childCount;
    u8 languageIndex;
    s32 isGhost;

    if (entryIndex >= 4) {
        return;
    }
    isGhost = gameInfo->mGameInfoPart.mHasGhost;
    if (isGhost != 0) {
        if (gConnectionWork->mConnectionKind != 2) {
            return;
        }
        languageIndex = gameInfo->mGameInfoPart.mLanguageIndex;
        childCount = gameInfo->mGameInfoPart.mChildCount;
        MI_CpuCopy8(scanBuffer, slot, 0xc0);
        slot->mKey = *key;
        slot->mInUse = 1;
        slot->mAge = 0;
        if (childCount >= 0) {
            slot->mChildCount = childCount;
        }
        slot->mLanguageIndex = languageIndex;
        slot->mMultiBoot = 0;
        slot->mHasGhost = isGhost;
        MI_CpuCopy8(gameInfo, slot->mName, 0x14);
        SetScanGhostInfo(entryIndex, gameInfo);
    } else {
        s32 gameChildCount;
        u8 gameLanguageIndex;

        if (gConnectionWork->mConnectionKind == 2) {
            return;
        }
        gameLanguageIndex = gameInfo->mGameInfoPart.mLanguageIndex;
        gameChildCount = gameInfo->mGameInfoPart.mChildCount;
        MI_CpuCopy8(scanBuffer, slot, 0xc0);
        slot->mKey = *key;
        slot->mInUse = 1;
        slot->mAge = 0;
        if (gameChildCount >= 0) {
            slot->mChildCount = gameChildCount;
        }
        slot->mLanguageIndex = gameLanguageIndex;
        slot->mMultiBoot = 0;
        slot->mHasGhost = isGhost;
        MI_CpuCopy8(gameInfo, slot->mName, 0x14);
    }
}

void FindOrAddScanSlot(WMBssDesc *scanBuffer, ScanMacAddress *key, UserGameInfo *gameInfo) {
    Unk0217aa00_24_50_0e_36 *nameInfo;
    s32 slotIndex;
    s32 oldestAge;
    ScanStateView *scanState;
    ScanSlot *chosenSlot;
    ScanSlot *slotCursor;
    ConnectionWork *connection;
    BOOL found;
    ScanSlot *slot;
    Unk0217aa00_24_50_0e *gameInfoPart;
    UserGameInfo *userGameInfo;
    s8 childCount;

    connection = gConnectionWork;
    chosenSlot = NULL;
    slotCursor = connection->mScanSlots;
    oldestAge = 0;
    found = FALSE;
    for (slotIndex = 0, slot = slotCursor; slotIndex < 4; slotIndex++, slot++) {
        if (slot->mInUse != 0 && key->mBytes[0] == slot->mKey.mBytes[0] && key->mBytes[1] == slot->mKey.mBytes[1] &&
            key->mBytes[2] == slot->mKey.mBytes[2] && key->mBytes[3] == slot->mKey.mBytes[3] &&
            key->mBytes[4] == slot->mKey.mBytes[4] && key->mBytes[5] == slot->mKey.mBytes[5]) {
            chosenSlot = slot;
            found = TRUE;
            break;
        }
    }
    if (chosenSlot == NULL) {
        for (slotIndex = 0, slot = slotCursor; slotIndex < 4; slotIndex++, slot++) {
            if (slot->mInUse == 0) {
                chosenSlot = slot;
                break;
            }
        }
    }
    if (chosenSlot == NULL) {
        for (slotIndex = 0; slotIndex < 4; slotIndex++) {
            if (slotCursor->mAge < 5) {
                if (slotCursor->mAge > oldestAge) {
                    oldestAge = slotCursor->mAge;
                    chosenSlot = slotCursor;
                }
            }
            slotCursor++;
        }
    }
    if (chosenSlot == NULL) {
        return;
    }
    if ((scanBuffer->mGameInfo.mAttribute & 2) != 0) {
        if (connection->mConnectionKind != 2) {
            userGameInfo = &scanBuffer->mGameInfo.mUserGameInfo;
            if (userGameInfo->mKind == 5) {
                gameInfoPart = (void *) &userGameInfo->mGameInfoPart;
                nameInfo = &gameInfoPart->mNameInfo;
                childCount = -(found != FALSE);
                MI_CpuCopy8(scanBuffer, chosenSlot, 0xc0);
                chosenSlot->mKey = *key;
                chosenSlot->mInUse = 1;
                chosenSlot->mAge = 0;
                if (childCount >= 0) {
                    chosenSlot->mChildCount = childCount;
                }
                chosenSlot->mLanguageIndex = LANGUAGE_UNSUFFIXED;
                chosenSlot->mMultiBoot = 1;
                chosenSlot->mHasGhost = 0;
                MI_CpuCopy8(nameInfo->mName, chosenSlot->mName, 0x14);
                gConnectionWork->mRememberedScanKeyHeld = 0;
            } else if (userGameInfo->mKind == 9) {
                if (chosenSlot->mInUse != 0) {
                    chosenSlot->mChildCount = userGameInfo->mMemberCount - 1;
                }
            } else if (chosenSlot->mInUse != 0) {
                chosenSlot->mAge = 0;
            } else {
                connection = gConnectionWork;
                connection->mRememberedScanKey = *key;
                connection->mRememberedScanKeyHeld = 0xf;
            }
        }
    } else if (scanBuffer->mGameInfo.mUserGameInfoLength == 0x1c) {
        FillScanSlot(chosenSlot, scanBuffer, key, gameInfo, slotIndex);
    }
    scanState = &gConnectionWork->mScanState;
    scanState->mSlotCount = 0;
    for (slotIndex = 0, slot = scanState->mSlots; slotIndex < 4; slotIndex++, slot++) {
        if (slot->mInUse != 0) {
            scanState->mSlotCount += 1;
        }
    }
}

void StartScanCallback(WirelessMessage *event) {
    WMBssDesc scanBuffer;
    ScanMacAddress key;
    s32 slotIndex;
    ConnectionWork *connection;
    s32 countedIndex;
    ScanSlot *countedSlot;
    ScanStateView *scanState;
    u16 value;
    BOOL accepted;
    ScanSlot *slot;

    if (gConnectionWork->mStep != CONNECTION_STEP_SEARCHING) {
        return;
    }
    if (event->mResultCode == WIRELESS_RESULT_SUCCEEDED) {
        switch (event->mReplyState) {
            case WIRELESS_STATE_HOST_SIGHTED:
                DC_InvalidateRange(gConnectionWork->mScanBssDescBuffer, 0xc0);
                MI_CpuCopy8(gConnectionWork->mScanBssDescBuffer, &scanBuffer, 0xc0);
                DC_StoreRange(&scanBuffer, 0xc0);
                if (gConnectionWork->mState == CONNECTION_STATE_ENDED) {
                    value = event->mAid;
                    if (IsScanBlockGameInfoMatch(&scanBuffer) != 0) {
                        gConnectionWork->mUnk_1ed0 = 1;
                        gConnectionWork->mUnk_1ed4 = value;
                        gConnectionWork->mUnk_1ed6 = 0;
                    } else if (scanBuffer.mGameInfoLength >= 8 && scanBuffer.mGameInfo.mGgid == 0x25 &&
                               (scanBuffer.mGameInfo.mAttribute & 1) != 0) {
                        if ((scanBuffer.mGameInfo.mAttribute & 2) != 0) {
                            gConnectionWork->mUnk_1ed8 = 2;
                        } else {
                            gConnectionWork->mUnk_1ed8 = 3;
                        }
                        gConnectionWork->mUnk_1edc = value;
                        gConnectionWork->mUnk_1ede = 0;
                    }
                } else {
                    accepted = TRUE;
                    if (scanBuffer.mGameInfoLength < 8 || scanBuffer.mGameInfo.mGgid != 0x25 ||
                        (scanBuffer.mGameInfo.mAttribute & 1) == 0) {
                        accepted = FALSE;
                    } else if (gConnectionWork->mScanFilterCallback != 0) {
                        if (gConnectionWork->mScanFilterCallback(&scanBuffer) == 0) {
                            accepted = FALSE;
                        }
                    }
                    if (accepted != FALSE) {
                        if (gConnectionWork->mScanResultCallback != 0) {
                            gConnectionWork->mScanResultCallback(event, &scanBuffer);
                        } else if ((gConnectionWork->mOperationFlags & CONNECTION_OPERATION_SCANNING) != 0) {
                            if ((scanBuffer.mGameInfo.mTgid & 0x8000) != 0) {
                                key.mBytes[0] = event->mMacAddress[0];
                                key.mBytes[1] = event->mMacAddress[1];
                                key.mBytes[2] = event->mMacAddress[2];
                                key.mBytes[3] = event->mMacAddress[3];
                                key.mBytes[4] = event->mMacAddress[4];
                                key.mBytes[5] = event->mMacAddress[5];
                                FindOrAddScanSlot(&scanBuffer, &key, &scanBuffer.mGameInfo.mUserGameInfo);
                                *gConnectionWork->mParentBssDesc = scanBuffer;
                            }
                        }
                    } else if (gConnectionWork->mRememberedScanKeyHeld == 0) {
                        gConnectionWork->mUnk_0439 += 1;
                    }
                }
                break;
            case WIRELESS_STATE_SEARCH_EMPTY:
                if (gConnectionWork->mRememberedScanKeyHeld == 0) {
                    gConnectionWork->mUnk_0439 += 1;
                }
                break;
        }
        connection = gConnectionWork;
        if ((connection->mOperationFlags & CONNECTION_OPERATION_SCANNING) != 0 &&
            connection->mState != CONNECTION_STATE_ENDED) {
            for (slotIndex = 0, slot = connection->mScanSlots; slotIndex < 4; slotIndex++, slot++) {
                if (slot->mInUse != 0) {
                    slot->mAge += 1;
                    if (slot->mAge > 0xc8) {
                        slot->mInUse = 0;
                        scanState = &gConnectionWork->mScanState;
                        scanState->mSlotCount = 0;
                        for (countedIndex = 0, countedSlot = scanState->mSlots; countedIndex < 4;
                             countedIndex++, countedSlot++) {
                            if (countedSlot->mInUse != 0) {
                                scanState->mSlotCount += 1;
                            }
                        }
                    }
                }
            }
        }
        if (gConnectionWork->mKeepScanning == 0) {
            gConnectionWork->mRequestPending = 0;
            return;
        }
        StartScan(1, gConnectionWork->mScanResultCallback, gConnectionWork->mScanFilterCallback);
    } else {
        StopConnection();
    }
}

void EndScan(void) {
    gConnectionWork->mOperationFlags &= ~CONNECTION_OPERATION_SCANNING;
    gConnectionWork->mStep = CONNECTION_STEP_STOPPING_SEARCH;
    gConnectionWork->mRequestPending = 1;
    if (WM_EndScan(EndScanCallback) == 2) {
        return;
    }
    StopConnection();
}

void EndScanCallback(WirelessMessage *event) {
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode == WIRELESS_RESULT_SUCCEEDED) {
        return;
    }
    StopConnection();
}

void StartConnect(WMBssDesc *parentBssDesc, void *customUserData, void (*connectedCallback)(), void (*failedCallback)(),
                  void (*disconnectedCallback)()) {
    u8 userData[0x18];

    MI_CpuFill8(userData, 0, 0x18);
    MI_CpuCopy8(&gBackupBuffers->mFirstBlock->mPlayerName, userData, 0x14);
    if (parentBssDesc != NULL) {
        *gConnectionWork->mParentBssDesc = *parentBssDesc;
    }
    if (customUserData == NULL) {
        userData[0x14] = 0;
        if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
            userData[0x14] = userData[0x14] | 1;
        }
    } else {
        MI_CpuCopy8(customUserData, userData, 0x18);
    }
    gConnectionWork->mStep = CONNECTION_STEP_JOINING;
    gConnectionWork->mRequestPending = 1;
    if (WM_StartConnectEx(StartConnectCallback, (u16 *) gConnectionWork->mParentBssDesc, userData, 1, 0) != 2) {
        StopConnection();
        return;
    }
    gConnectionWork->mConnectedCallback = connectedCallback;
    gConnectionWork->mConnectFailedCallback = failedCallback;
    gConnectionWork->mDisconnectedCallback = disconnectedCallback;
}

void StartConnectCallback(WirelessMessage *event) {
    BOOL shouldReset;
    u16 seed;
    RandomState64 *randomState;

    shouldReset = FALSE;
    switch (event->mResultCode) {
        case WIRELESS_RESULT_SUCCEEDED:
            switch (event->mReplyState) {
                case WIRELESS_STATE_LINKED:
                    gConnectionWork->mOwnIndex = event->mUnk_08_2;
                    gConnectionWork->mExpectedRecordMask = shouldReset;
                    seed = shouldReset;
                    switch (ScanGetConnectionMode()) {
                        case CONNECTION_MODE_PARENT:
                            seed = gConnectionWork->mParentParameter->mTgid;
                            break;
                        case CONNECTION_MODE_CHILD:
                            seed = gConnectionWork->mParentBssDesc->mGameInfo.mTgid;
                            break;
                    }
                    randomState = &gConnectionWork->mRandomState;
                    randomState->mValue = (u32) (seed * 3 | seed << 16);
                    randomState->mMultiplier = 0x5d588b656c078965;
                    randomState->mIncrement = 0x269ec3;
                    if (gConnectionWork->mConnectedCallback != 0) {
                        gConnectionWork->mConnectedCallback();
                    }
                    gConnectionWork->mRequestPending = 0;
                    break;
                case WIRELESS_STATE_UNLINKED:
                    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
                        shouldReset = TRUE;
                    } else if (gConnectionWork->mDisconnectedCallback != 0) {
                        gConnectionWork->mDisconnectedCallback();
                    } else {
                        switch (gConnectionWork->mState) {
                            case CONNECTION_STATE_MULTIBOOT_PARENT_READY:
                            case CONNECTION_STATE_MULTIBOOT_SCAN_READY:
                            case CONNECTION_STATE_SETUP_SPARE:
                            case CONNECTION_STATE_MULTIBOOT_PARENT_ACTIVE:
                            case CONNECTION_STATE_CONNECTED:
                                StopConnection();
                                break;
                            case CONNECTION_STATE_ENTRY_EXCHANGE:
                                shouldReset = TRUE;
                                break;
                            case CONNECTION_STATE_GATHERING:
                            case CONNECTION_STATE_MP_ENDING:
                                break;
                            default:
                                shouldReset = TRUE;
                                break;
                        }
                    }
                    break;
                case WIRELESS_STATE_CHILD_SESSION_START:
                case WIRELESS_STATE_CHILD_NO_ACTION:
                    break;
                default:
                    shouldReset = TRUE;
                    break;
            }
            break;
        case WIRELESS_RESULT_REFUSED:
        case WIRELESS_RESULT_NOT_LISTED:
        case WIRELESS_RESULT_LIST_FULL:
            if (gConnectionWork->mConnectFailedCallback == 0) {
                shouldReset = TRUE;
            } else {
                gConnectionWork->mConnectFailedCallback();
                gConnectionWork->mRequestPending = 0;
            }
            break;
        default:
            shouldReset = TRUE;
            break;
    }
    if (shouldReset == FALSE) {
        return;
    }
    ResetConnectionData();
    gConnectionWork->mErrorCode = CONNECTION_ERROR_DISCONNECTED;
    gConnectionWork->mRequestPending = 0;
}

void StartMP(void) {
    gConnectionWork->mStep = CONNECTION_STEP_STARTING_EXCHANGE;
    gConnectionWork->mRequestPending = 1;
    if (WM_StartMPEx(StartMPCallback, gConnectionWork->mStartMPReceiveBuffer,
                     gConnectionWork->mStartMPReceiveBufferSize, gConnectionWork->mStartMPSendBuffer,
                     gConnectionWork->mStartMPSendBufferSize, 1, 0, 0, 0, 0, 0) == 2) {
        return;
    }
    gConnectionWork->mErrorCode = CONNECTION_ERROR_MP_FAILED;
    gConnectionWork->mRequestPending = 0;
}

void StartMPCallback(WirelessMessage *event) {
    switch (event->mResultCode) {
        case WIRELESS_RESULT_SUCCEEDED:
            switch (event->mState) {
                case WIRELESS_STATE_EXCHANGE_BEGUN:
                    gConnectionWork->mFlags |= CONNECTION_FLAG_SEND_READY;
                    gConnectionWork->mSyncDoneChildMask = 0;
                    gConnectionWork->mRequestPending = 0;
                    break;
                case WIRELESS_STATE_EXCHANGE_PASS_RECV_BUFFER:
                case WIRELESS_STATE_EXCHANGE_IGNORED_FIRST:
                    break;
            }
            break;
        case WIRELESS_RESULT_NO_ANSWER:
        case WIRELESS_RESULT_EMPTY_STATION_MASK:
        case WIRELESS_RESULT_TRANSMIT_ERROR:
            break;
        default:
            gConnectionWork->mFlags |= CONNECTION_FLAG_SEND_READY;
            gConnectionWork->mErrorCode = CONNECTION_ERROR_MP_FAILED;
            gConnectionWork->mRequestPending = 0;
            break;
    }
}

void SetMPFrequency(u32 mpFreq) {
    s32 result;

    gConnectionWork->mStep = CONNECTION_STEP_SETTING_EXCHANGE_RATE;
    gConnectionWork->mRequestPending = 1;
    result = WM_SetMPFrequency(SetMPFrequencyCallback, mpFreq);
    if (result == 0) {
        gConnectionWork->mRequestPending = 0;
        return;
    }
    if (result == 2) {
        return;
    }
    gConnectionWork->mErrorCode = CONNECTION_ERROR_MP_FAILED;
    gConnectionWork->mRequestPending = 0;
}

void SetMPFrequencyCallback(WirelessMessage *event) {
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
        gConnectionWork->mErrorCode = CONNECTION_ERROR_MP_FAILED;
        gConnectionWork->mRequestPending = 0;
    }
}

void SetEntry(s32 enabled) {
    s32 result;

    if ((gConnectionWork->mParentParameter->mEntryFlag != 0) == enabled) {
        return;
    }
    gConnectionWork->mStep = CONNECTION_STEP_REGISTERING_ENTRY;
    gConnectionWork->mRequestPending = 1;
    result = WM_SetEntry(SetEntryCallback, enabled);
    if (result == 2) {
        return;
    }
    StopConnection();
}

void SetEntryCallback(WirelessMessage *event) {
    gConnectionWork->mRequestPending = 0;
    if (event->mResultCode == WIRELESS_RESULT_SUCCEEDED) {
        return;
    }
    StopConnection();
}

void StartDataSharing(void) {
    s32 result;

    gConnectionWork->mStep = CONNECTION_STEP_STARTING_SHARING;
    gConnectionWork->mRequestPending = 1;
    result = WM_StartDataSharing(gConnectionWork->mSharingInfo, 0xc, 0xff, 8, 1);
    gConnectionWork->mRequestPending = 0;
    if (result != 0) {
        gConnectionWork->mErrorCode = CONNECTION_ERROR_MP_FAILED;
        gConnectionWork->mRequestPending = 0;
        return;
    }
    ResetDataSharing(&gConnectionWork->mDataSharing);
}

void SetGameInfo(void) {
    ChildList *children;
    BOOL isState8Or9;
    u8 unusedValue;

    if (ScanGetConnectionMode() != CONNECTION_MODE_PARENT) {
        return;
    }
    gConnectionWork->mStep = CONNECTION_STEP_PUBLISHING_GAME_INFO;
    gConnectionWork->mRequestPending = 1;
    children = &gConnectionWork->mChildren;
    children->mGameInfo->mGameInfoPart.mChildCount = children->mChildCount;
    isState8Or9 = TRUE;
    if (gConnectionWork->mState != CONNECTION_STATE_SYNCED && gConnectionWork->mState != CONNECTION_STATE_SYNCED_RACE) {
        isState8Or9 = FALSE;
    }
    if (WM_SetGameInfo(ClearRequestPending, children->mGameInfo, 0x1c, 0x25, gConnectionWork->mParentParameter->mTgid,
                       isState8Or9 == FALSE) != 2) {
        gConnectionWork->mRequestPending = 0;
    }
}
