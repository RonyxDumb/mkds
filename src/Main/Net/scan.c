#include "Main/Net/scan.h"
#include "thread_scheduler.h"
#include "arena_cache_init.h"
#include "Main/Net/scan_game_info.h"
#include "Main/Net/multiboot_connect.h"
#include "Main/Net/mp_link.h"
#include "Main/Net/packet_port.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Net/block.h"
#include "Main/Net/scan_ghost_info.h"
#include "Main/Net/request_pending.h"
#include "Main/Net/connection.h"
#include "Main/Net/connection_sharing.h"
#include "wireless_key_data_sharing.h"
#include "wireless_beacon_wep_settings.h"
#include "wireless_link_control.h"
#include "cpu_copy_fill.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/Scene/scene_display_archive_work.h"

static inline u32 ScanGetConnectionMode(void) {
    if (g_GlobalZE == NULL) {
        return 0;
    }
    return g_GlobalZE->mConnectionMode;
}

void StartScan(s32 isRepeat, s32 (*resultCallback)(), s32 (*filterCallback)()) {
    ConnectionWork *connection;
    ScanStateView *scanState;
    ScanParam *scanParams;
    u16 channel;
    s32 index;
    u16 allowedChannels;

    connection = g_GlobalZE;
    scanState = &connection->mScanState;
    channel = scanState->mChannel;
    scanParams = connection->mScanParams;
    connection->mConnectionMode = CONNECTION_MODE_CHILD;
    g_GlobalZE->mStep = CONNECTION_STEP_SEARCHING;
    g_GlobalZE->mRequestPending = 1;
    allowedChannels = WM_GetAllowedChannel();
    if (allowedChannels == 0) {
        g_GlobalZE->mRequestPending = 0;
        g_GlobalZE->mErrorCode = CONNECTION_ERROR_NO_CHANNEL;
        g_GlobalZE->mRequestPending = 0;
        return;
    }
    if (allowedChannels == 0x8000) {
        g_GlobalZE->mRequestPending = 0;
        g_GlobalZE->mErrorCode = CONNECTION_ERROR_OPERATION_FAILED;
        g_GlobalZE->mRequestPending = 0;
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
            scanParams->mBssid[index] = CONNECTION_BSSID_ANY_BYTE;
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
        g_GlobalZE->mOperationFlags &= ~CONNECTION_OPERATION_SCANNING;
        StopConnection();
        return;
    }
    g_GlobalZE->mOperationFlags |= CONNECTION_OPERATION_SCANNING;
    g_GlobalZE->mScanResultCallback = resultCallback;
    g_GlobalZE->mScanFilterCallback = filterCallback;
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
        if (g_GlobalZE->mConnectionKind != CONNECTION_KIND_WL_MENU) {
            return;
        }
        languageIndex = gameInfo->mGameInfoPart.mLanguageIndex;
        childCount = gameInfo->mGameInfoPart.mChildCount;
        Mem_CpuCopy8(scanBuffer, slot, sizeof(WMBssDesc));
        slot->mKey = *key;
        slot->mInUse = 1;
        slot->mAge = 0;
        if (childCount >= 0) {
            slot->mChildCount = childCount;
        }
        slot->mLanguageIndex = languageIndex;
        slot->mMultiBoot = 0;
        slot->mHasGhost = isGhost;
        Mem_CpuCopy8(gameInfo, slot->mName, sizeof(slot->mName));
        SetScanGhostInfo(entryIndex, gameInfo);
    } else {
        s32 gameChildCount;
        u8 gameLanguageIndex;

        if (g_GlobalZE->mConnectionKind == CONNECTION_KIND_WL_MENU) {
            return;
        }
        gameLanguageIndex = gameInfo->mGameInfoPart.mLanguageIndex;
        gameChildCount = gameInfo->mGameInfoPart.mChildCount;
        Mem_CpuCopy8(scanBuffer, slot, sizeof(WMBssDesc));
        slot->mKey = *key;
        slot->mInUse = 1;
        slot->mAge = 0;
        if (gameChildCount >= 0) {
            slot->mChildCount = gameChildCount;
        }
        slot->mLanguageIndex = gameLanguageIndex;
        slot->mMultiBoot = 0;
        slot->mHasGhost = isGhost;
        Mem_CpuCopy8(gameInfo, slot->mName, sizeof(slot->mName));
    }
}

void FindOrAddScanSlot(WMBssDesc *scanBuffer, ScanMacAddress *key, UserGameInfo *gameInfo) {
    UserGameNameBlock *nameInfo;
    s32 slotIndex;
    s32 oldestAge;
    ScanStateView *scanState;
    ScanSlot *chosenSlot;
    ScanSlot *slotCursor;
    ConnectionWork *connection;
    BOOL found;
    ScanSlot *slot;
    UserGameDetails *gameInfoPart;
    UserGameInfo *userGameInfo;
    s8 childCount;

    connection = g_GlobalZE;
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
            if (slotCursor->mAge < SCAN_SLOT_REPLACE_AGE_LIMIT) {
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
    if ((scanBuffer->mGameInfo.mAttribute & BEACON_ATTRIBUTE_MULTIBOOT) != 0) {
        if (connection->mConnectionKind != CONNECTION_KIND_WL_MENU) {
            userGameInfo = &scanBuffer->mGameInfo.mUserGameInfo;
            if (userGameInfo->mKind == USER_GAME_INFO_KIND_NAME_INFO) {
                gameInfoPart = (void *) &userGameInfo->mGameInfoPart;
                nameInfo = &gameInfoPart->mNameInfo;
                childCount = -(found != FALSE);
                Mem_CpuCopy8(scanBuffer, chosenSlot, sizeof(WMBssDesc));
                chosenSlot->mKey = *key;
                chosenSlot->mInUse = 1;
                chosenSlot->mAge = 0;
                if (childCount >= 0) {
                    chosenSlot->mChildCount = childCount;
                }
                chosenSlot->mLanguageIndex = LANGUAGE_UNSUFFIXED;
                chosenSlot->mMultiBoot = 1;
                chosenSlot->mHasGhost = 0;
                Mem_CpuCopy8(nameInfo->mName, chosenSlot->mName, sizeof(chosenSlot->mName));
                g_GlobalZE->mRememberedScanKeyHeld = 0;
            } else if (userGameInfo->mKind == USER_GAME_INFO_KIND_MEMBER_COUNT) {
                if (chosenSlot->mInUse != 0) {
                    chosenSlot->mChildCount = userGameInfo->mMemberCount - 1;
                }
            } else if (chosenSlot->mInUse != 0) {
                chosenSlot->mAge = 0;
            } else {
                connection = g_GlobalZE;
                connection->mRememberedScanKey = *key;
                connection->mRememberedScanKeyHeld = SCAN_REMEMBERED_KEY_HELD;
            }
        }
    } else if (scanBuffer->mGameInfo.mUserGameInfoLength == SCAN_USER_GAME_INFO_BYTES) {
        FillScanSlot(chosenSlot, scanBuffer, key, gameInfo, slotIndex);
    }
    scanState = &g_GlobalZE->mScanState;
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

    if (g_GlobalZE->mStep != CONNECTION_STEP_SEARCHING) {
        return;
    }
    if (event->mResultCode == WIRELESS_RESULT_SUCCEEDED) {
        switch (event->mReplyState) {
            case WIRELESS_STATE_HOST_SIGHTED:
                DC_InvalidateRangeNoClean(g_GlobalZE->mScanBssDescBuffer, 0xc0);
                Mem_CpuCopy8(g_GlobalZE->mScanBssDescBuffer, &scanBuffer, sizeof(WMBssDesc));
                DC_SomeClean(&scanBuffer, 0xc0);
                if (g_GlobalZE->mState == CONNECTION_STATE_ENDED) {
                    value = event->mAid;
                    if (IsScanBlockGameInfoMatch(&scanBuffer) != 0) {
                        g_GlobalZE->mMatchingHostFound = 1;
                        g_GlobalZE->mMatchingHostAid = value;
                        g_GlobalZE->mUnk_1ed6 = 0;
                    } else if (scanBuffer.mGameInfoLength >= SCAN_GAME_INFO_LENGTH_WITH_GROUP_ID &&
                               scanBuffer.mGameInfo.mGgid == CONNECTION_GAME_GROUP_ID &&
                               (scanBuffer.mGameInfo.mAttribute & BEACON_ATTRIBUTE_ENTRY_OPEN) != 0) {
                        if ((scanBuffer.mGameInfo.mAttribute & BEACON_ATTRIBUTE_MULTIBOOT) != 0) {
                            g_GlobalZE->mOtherHostKind = OTHER_HOST_KIND_MULTIBOOT;
                        } else {
                            g_GlobalZE->mOtherHostKind = OTHER_HOST_KIND_NON_MULTIBOOT;
                        }
                        g_GlobalZE->mOtherHostAid = value;
                        g_GlobalZE->mUnk_1ede = 0;
                    }
                } else {
                    accepted = TRUE;
                    if (scanBuffer.mGameInfoLength < SCAN_GAME_INFO_LENGTH_WITH_GROUP_ID ||
                        scanBuffer.mGameInfo.mGgid != CONNECTION_GAME_GROUP_ID ||
                        (scanBuffer.mGameInfo.mAttribute & BEACON_ATTRIBUTE_ENTRY_OPEN) == 0) {
                        accepted = FALSE;
                    } else if (g_GlobalZE->mScanFilterCallback != 0) {
                        if (g_GlobalZE->mScanFilterCallback(&scanBuffer) == 0) {
                            accepted = FALSE;
                        }
                    }
                    if (accepted != FALSE) {
                        if (g_GlobalZE->mScanResultCallback != 0) {
                            g_GlobalZE->mScanResultCallback(event, &scanBuffer);
                        } else if ((g_GlobalZE->mOperationFlags & CONNECTION_OPERATION_SCANNING) != 0) {
                            if ((scanBuffer.mGameInfo.mTgid & PARENT_TGID_FLAG) != 0) {
                                key.mBytes[0] = event->mMacAddress[0];
                                key.mBytes[1] = event->mMacAddress[1];
                                key.mBytes[2] = event->mMacAddress[2];
                                key.mBytes[3] = event->mMacAddress[3];
                                key.mBytes[4] = event->mMacAddress[4];
                                key.mBytes[5] = event->mMacAddress[5];
                                FindOrAddScanSlot(&scanBuffer, &key, &scanBuffer.mGameInfo.mUserGameInfo);
                                *g_GlobalZE->mParentBssDesc = scanBuffer;
                            }
                        }
                    } else if (g_GlobalZE->mRememberedScanKeyHeld == 0) {
                        g_GlobalZE->mScanMissCount += 1;
                    }
                }
                break;
            case WIRELESS_STATE_SEARCH_EMPTY:
                if (g_GlobalZE->mRememberedScanKeyHeld == 0) {
                    g_GlobalZE->mScanMissCount += 1;
                }
                break;
        }
        connection = g_GlobalZE;
        if ((connection->mOperationFlags & CONNECTION_OPERATION_SCANNING) != 0 &&
            connection->mState != CONNECTION_STATE_ENDED) {
            for (slotIndex = 0, slot = connection->mScanSlots; slotIndex < 4; slotIndex++, slot++) {
                if (slot->mInUse != 0) {
                    slot->mAge += 1;
                    if (slot->mAge > SCAN_SLOT_EXPIRE_AGE) {
                        slot->mInUse = 0;
                        scanState = &g_GlobalZE->mScanState;
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
        if (g_GlobalZE->mKeepScanning == 0) {
            g_GlobalZE->mRequestPending = 0;
            return;
        }
        StartScan(1, g_GlobalZE->mScanResultCallback, g_GlobalZE->mScanFilterCallback);
    } else {
        StopConnection();
    }
}

void EndScan(void) {
    g_GlobalZE->mOperationFlags &= ~CONNECTION_OPERATION_SCANNING;
    g_GlobalZE->mStep = CONNECTION_STEP_STOPPING_SEARCH;
    g_GlobalZE->mRequestPending = 1;
    if (WM_EndScan(EndScanCallback) == 2) {
        return;
    }
    StopConnection();
}

void EndScanCallback(WirelessMessage *event) {
    g_GlobalZE->mRequestPending = 0;
    if (event->mResultCode == WIRELESS_RESULT_SUCCEEDED) {
        return;
    }
    StopConnection();
}

void StartConnect(WMBssDesc *parentBssDesc, void *customUserData, void (*connectedCallback)(), void (*failedCallback)(),
                  void (*disconnectedCallback)()) {
    u8 userData[0x18];

    Mem_CpuFill8(userData, 0, sizeof(userData));
    Mem_CpuCopy8(&g_SaveDataHolder->mFirstBlock->mPlayerName, userData, PLAYER_NAME_BYTES);
    if (parentBssDesc != NULL) {
        *g_GlobalZE->mParentBssDesc = *parentBssDesc;
    }
    if (customUserData == NULL) {
        userData[0x14] = 0;
        if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
            userData[0x14] = userData[0x14] | 1;
        }
    } else {
        Mem_CpuCopy8(customUserData, userData, sizeof(userData));
    }
    g_GlobalZE->mStep = CONNECTION_STEP_JOINING;
    g_GlobalZE->mRequestPending = 1;
    if (WM_StartConnectEx(StartConnectCallback, g_GlobalZE->mParentBssDesc, userData, 1, 0) != 2) {
        StopConnection();
        return;
    }
    g_GlobalZE->mConnectedCallback = connectedCallback;
    g_GlobalZE->mConnectFailedCallback = failedCallback;
    g_GlobalZE->mDisconnectedCallback = disconnectedCallback;
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
                    g_GlobalZE->mOwnIndex = event->mOwnAid;
                    g_GlobalZE->mExpectedRecordMask = shouldReset;
                    seed = shouldReset;
                    switch (ScanGetConnectionMode()) {
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
                    if (g_GlobalZE->mConnectedCallback != 0) {
                        g_GlobalZE->mConnectedCallback();
                    }
                    g_GlobalZE->mRequestPending = 0;
                    break;
                case WIRELESS_STATE_UNLINKED:
                    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
                        shouldReset = TRUE;
                    } else if (g_GlobalZE->mDisconnectedCallback != 0) {
                        g_GlobalZE->mDisconnectedCallback();
                    } else {
                        switch (g_GlobalZE->mState) {
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
            if (g_GlobalZE->mConnectFailedCallback == 0) {
                shouldReset = TRUE;
            } else {
                g_GlobalZE->mConnectFailedCallback();
                g_GlobalZE->mRequestPending = 0;
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
    g_GlobalZE->mErrorCode = CONNECTION_ERROR_DISCONNECTED;
    g_GlobalZE->mRequestPending = 0;
}

void StartMP(void) {
    g_GlobalZE->mStep = CONNECTION_STEP_STARTING_EXCHANGE;
    g_GlobalZE->mRequestPending = 1;
    if (WM_StartMPEx(StartMPCallback, g_GlobalZE->mStartMPReceiveBuffer,
                     g_GlobalZE->mStartMPReceiveBufferSize, g_GlobalZE->mStartMPSendBuffer,
                     g_GlobalZE->mStartMPSendBufferSize, 1, 0, 0, 0, 0, 0) == 2) {
        return;
    }
    g_GlobalZE->mErrorCode = CONNECTION_ERROR_MP_FAILED;
    g_GlobalZE->mRequestPending = 0;
}

void StartMPCallback(WirelessMessage *event) {
    switch (event->mResultCode) {
        case WIRELESS_RESULT_SUCCEEDED:
            switch (event->mState) {
                case WIRELESS_STATE_EXCHANGE_BEGUN:
                    g_GlobalZE->mFlags |= CONNECTION_FLAG_SEND_READY;
                    g_GlobalZE->mSyncDoneChildMask = 0;
                    g_GlobalZE->mRequestPending = 0;
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
            g_GlobalZE->mFlags |= CONNECTION_FLAG_SEND_READY;
            g_GlobalZE->mErrorCode = CONNECTION_ERROR_MP_FAILED;
            g_GlobalZE->mRequestPending = 0;
            break;
    }
}

void SetMPFrequency(u32 mpFreq) {
    s32 result;

    g_GlobalZE->mStep = CONNECTION_STEP_SETTING_EXCHANGE_RATE;
    g_GlobalZE->mRequestPending = 1;
    result = WM_SetMPFrequency(SetMPFrequencyCallback, mpFreq);
    if (result == 0) {
        g_GlobalZE->mRequestPending = 0;
        return;
    }
    if (result == 2) {
        return;
    }
    g_GlobalZE->mErrorCode = CONNECTION_ERROR_MP_FAILED;
    g_GlobalZE->mRequestPending = 0;
}

void SetMPFrequencyCallback(WirelessMessage *event) {
    g_GlobalZE->mRequestPending = 0;
    if (event->mResultCode != WIRELESS_RESULT_SUCCEEDED) {
        g_GlobalZE->mErrorCode = CONNECTION_ERROR_MP_FAILED;
        g_GlobalZE->mRequestPending = 0;
    }
}

void SetEntry(s32 enabled) {
    s32 result;

    if ((g_GlobalZE->mParentParameter->mEntryFlag != 0) == enabled) {
        return;
    }
    g_GlobalZE->mStep = CONNECTION_STEP_REGISTERING_ENTRY;
    g_GlobalZE->mRequestPending = 1;
    result = WM_SetEntry(SetEntryCallback, enabled);
    if (result == 2) {
        return;
    }
    StopConnection();
}

void SetEntryCallback(WirelessMessage *event) {
    g_GlobalZE->mRequestPending = 0;
    if (event->mResultCode == WIRELESS_RESULT_SUCCEEDED) {
        return;
    }
    StopConnection();
}

void StartDataSharing(void) {
    s32 result;

    g_GlobalZE->mStep = CONNECTION_STEP_STARTING_SHARING;
    g_GlobalZE->mRequestPending = 1;
    result = WM_StartDataSharing(g_GlobalZE->mSharingInfo, 0xc, 0xff, 8, 1);
    g_GlobalZE->mRequestPending = 0;
    if (result != 0) {
        g_GlobalZE->mErrorCode = CONNECTION_ERROR_MP_FAILED;
        g_GlobalZE->mRequestPending = 0;
        return;
    }
    ResetDataSharing(&g_GlobalZE->mDataSharing);
}

void SetGameInfo(void) {
    ChildList *children;
    BOOL isSyncedOrSyncedRace;
    u8 unusedValue;

    if (ScanGetConnectionMode() != CONNECTION_MODE_PARENT) {
        return;
    }
    g_GlobalZE->mStep = CONNECTION_STEP_PUBLISHING_GAME_INFO;
    g_GlobalZE->mRequestPending = 1;
    children = &g_GlobalZE->mChildren;
    children->mGameInfo->mGameInfoPart.mChildCount = children->mChildCount;
    isSyncedOrSyncedRace = TRUE;
    if (g_GlobalZE->mState != CONNECTION_STATE_SYNCED && g_GlobalZE->mState != CONNECTION_STATE_SYNCED_RACE) {
        isSyncedOrSyncedRace = FALSE;
    }
    if (WM_SetGameInfo(ClearRequestPending, children->mGameInfo, SCAN_USER_GAME_INFO_BYTES, CONNECTION_GAME_GROUP_ID,
                       g_GlobalZE->mParentParameter->mTgid, isSyncedOrSyncedRace == FALSE) != 2) {
        g_GlobalZE->mRequestPending = 0;
    }
}
