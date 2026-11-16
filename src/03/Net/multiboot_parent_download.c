#include "03/Net/multiboot_parent_download.h"
#include "03/Net/essid_packet_steps.h"
#include "reset_interrupts_halt.h"
#include "thread_scheduler.h"
#include "multiboot_piece_buffers.h"
#include "multiboot_communication.h"

#include "03/Menu/wifi_menu_shared.h"
#include "cpu_copy_fill.h"
#include "multiboot_parent_state_machine.h"
#include "file_handle_setup.h"
#include "file_handle_forward.h"
#include "multiboot_checksum.h"
#include "multiboot_data_pieces.h"
#include "wireless_link_control.h"
#include "multiboot_mode_constants.h"
#include "wireless_beacon_wep_settings.h"
#include "dma_copy_fill_wait.h"
#include "cpu_copy_clear_16.h"
#include "multiboot_file_register.h"
#include "file_archive_access.h"
#include "03/Net/wh.h"
#include "multiboot_segment_read.h"

MultiBootParent *gMultiBootParent;
u16 *gMultiBootMaskPointers[6];

void InitMultiBootParent(u8 *object) {
    gMultiBootParent = (MultiBootParent *) object;
    InitWhWork(&gMultiBootParent->mWhWork);
    gMultiBootParent->mMultiBootWorkPointer = NULL;
    gMultiBootParent->mFileBuffer = NULL;
}

void InitMultiBootParentComm(u32 ggid, u32 tgid) {
    OwnerInfo ownerInfo;
    MBUserInfo userInfo;
    MultiBootParentHeader clearedHeader;

    OS_GetOwnerInfo(&ownerInfo);
    userInfo.mColorAndPlayerNo = (userInfo.mColorAndPlayerNo & ~0xf) | (ownerInfo.mFavoriteColor & 0xf);
    userInfo.mNameLength = ownerInfo.mNickNameLength;
    MI_CpuCopy8(ownerInfo.mNickName, userInfo.mName, ownerInfo.mNickNameLength * 2);
    userInfo.mColorAndPlayerNo &= ~0xf0;
    {
        u16 *words = (u16 *) &clearedHeader;
        words[0] = 0;
        words[1] = 0;
        words[2] = 0;
        words[3] = 0;
        words[4] = 0;
        words[5] = 0;
        words[6] = 0;
    }
    gMultiBootParent->mHeader = clearedHeader;
    gMultiBootParent->mMultiBootWorkPointer = gMultiBootParent->mCommWork;
    if (MB_Init(gMultiBootParent->mMultiBootWorkPointer, &userInfo, ggid, tgid, 2) != 0) {
        OS_Terminate();
    }
    MB_SetParentCommParam(0x100, 1);
    MB_CommSetParentStateCallback(MultiBootParentStateCallback);
    SetMultiBootParentState(MULTIBOOT_PARENT_STATE_READY);
}

void StartMultiBootParentFromIdle(MBGameRegistry *gameRegistry, u16 channel) {
    SetMultiBootParentState(MULTIBOOT_PARENT_STATE_ACCEPTING_CHILDREN);
    if (MB_StartParentFromIdle(channel) != 0) {
        SetMultiBootParentState(MULTIBOOT_PARENT_STATE_FAILED);
        return;
    }
    if (RegisterMultiBootFile(gameRegistry) == 0) {
        OS_Terminate();
    }
}

BOOL RegisterMultiBootFile(MBGameRegistry *gameRegistry) {
    FSFile *segmentFile;
    FSFile openedFile;
    u32 registered;

    registered = 0;
    if (gameRegistry->mRomFilePathp == NULL) {
        segmentFile = NULL;
    } else {
        FS_InitFile(&openedFile);
        if (FS_OpenFile(&openedFile, gameRegistry->mRomFilePathp) == 0) {
            return registered;
        }
        segmentFile = &openedFile;
    }
    if (MB_GetSegmentLength(segmentFile) != 0) {
        gMultiBootParent->mFileBuffer = gMultiBootParent->mFileData;
        if (gMultiBootParent->mFileBuffer != NULL) {
            if (MB_ReadSegment(segmentFile, gMultiBootParent->mFileBuffer, 0x10000) != 0) {
                if (MB_RegisterFile(gameRegistry, gMultiBootParent->mFileBuffer) != 0) {
                    registered = 1;
                }
            }
        }
    }
    if (segmentFile == &openedFile) {
        FS_CloseFile(&openedFile);
    }
    return registered;
}

void AcceptMultiBootChildRequest(u32 aid) {
    u16 clearMask;
    u32 savedInterrupts;

    if (MB_CommResponseRequest(aid, MULTIBOOT_RESPONSE_ACCEPT) == 0) {
        clearMask = ~(1 << aid);
        savedInterrupts = OS_DisableInterrupts();
        gMultiBootParent->mHeader.mMask &= clearMask;
        gMultiBootParent->mHeader.mRequestedMask &= clearMask;
        gMultiBootParent->mHeader.mDownloadPendingMask &= clearMask;
        gMultiBootParent->mHeader.mDownloadStartedMask &= clearMask;
        gMultiBootParent->mHeader.mSendCompleteMask &= clearMask;
        gMultiBootParent->mHeader.mBootedMask &= clearMask;
        OS_RestoreInterrupts(savedInterrupts);
        MB_DisconnectChild(aid);
    }
}

void KickMultiBootChild(u32 aid) {
    u16 clearMask;
    u32 savedInterrupts;
    s32 aidBit;

    if (MB_CommResponseRequest(aid, MULTIBOOT_RESPONSE_REFUSE) == 0) {
        clearMask = ~(1 << aid);
        savedInterrupts = OS_DisableInterrupts();
        gMultiBootParent->mHeader.mMask &= clearMask;
        gMultiBootParent->mHeader.mRequestedMask &= clearMask;
        gMultiBootParent->mHeader.mDownloadPendingMask &= clearMask;
        gMultiBootParent->mHeader.mDownloadStartedMask &= clearMask;
        gMultiBootParent->mHeader.mSendCompleteMask &= clearMask;
        gMultiBootParent->mHeader.mBootedMask &= clearMask;
        OS_RestoreInterrupts(savedInterrupts);
        MB_DisconnectChild(aid);
    } else {
        savedInterrupts = OS_DisableInterrupts();
        aidBit = 1 << aid;
        gMultiBootParent->mHeader.mRequestedMask &= ~aidBit;
        gMultiBootParent->mHeader.mMask &= ~aidBit;
        OS_RestoreInterrupts(savedInterrupts);
    }
}

void StartMultiBootChildDownload(u32 aid) {
    u16 clearMask;
    u32 savedInterrupts;
    s32 aidBit;

    if (MB_CommResponseRequest(aid, MULTIBOOT_RESPONSE_SEND) == 0) {
        clearMask = ~(1 << aid);
        savedInterrupts = OS_DisableInterrupts();
        gMultiBootParent->mHeader.mMask &= clearMask;
        gMultiBootParent->mHeader.mRequestedMask &= clearMask;
        gMultiBootParent->mHeader.mDownloadPendingMask &= clearMask;
        gMultiBootParent->mHeader.mDownloadStartedMask &= clearMask;
        gMultiBootParent->mHeader.mSendCompleteMask &= clearMask;
        gMultiBootParent->mHeader.mBootedMask &= clearMask;
        OS_RestoreInterrupts(savedInterrupts);
        MB_DisconnectChild(aid);
    } else {
        savedInterrupts = OS_DisableInterrupts();
        aidBit = 1 << aid;
        gMultiBootParent->mHeader.mDownloadPendingMask &= ~aidBit;
        gMultiBootParent->mHeader.mDownloadStartedMask |= aidBit;
        OS_RestoreInterrupts(savedInterrupts);
    }
}

void StartMultiBootDownloads(void) {
    u16 aid;
    s32 aidBit;
    u16 clearMask;
    u32 savedInterrupts;

    SetMultiBootParentState(MULTIBOOT_PARENT_STATE_DOWNLOADING);
    for (aid = 1; aid < 16; aid++) {
        aidBit = 1 << aid;
        if ((gMultiBootParent->mHeader.mMask & aidBit) != 0) {
            if ((gMultiBootParent->mHeader.mRequestedMask & aidBit) == 0) {
                if ((gMultiBootParent->mHeader.mDownloadPendingMask & aidBit) == 0) {
                    clearMask = ~aidBit;
                    savedInterrupts = OS_DisableInterrupts();
                    gMultiBootParent->mHeader.mMask &= clearMask;
                    gMultiBootParent->mHeader.mRequestedMask &= clearMask;
                    gMultiBootParent->mHeader.mDownloadPendingMask &= clearMask;
                    gMultiBootParent->mHeader.mDownloadStartedMask &= clearMask;
                    gMultiBootParent->mHeader.mSendCompleteMask &= clearMask;
                    gMultiBootParent->mHeader.mBootedMask &= clearMask;
                    OS_RestoreInterrupts(savedInterrupts);
                    MB_DisconnectChild(aid);
                } else {
                    StartMultiBootChildDownload(aid);
                }
            }
        }
    }
}

BOOL AreMultiBootChildrenBootable(void) {
    u16 aid;

    if (gMultiBootParent->mHeader.mMask == 0) {
        return 0;
    }
    for (aid = 1; aid < 16; aid++) {
        if (BIT_IS_SET(gMultiBootParent->mHeader.mMask, aid)) {
            if (MB_CommIsBootable(aid) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void StartMultiBootBootRequests(void) {
    u16 requestedMask;
    u16 aid;
    s32 aidBit;
    u16 clearMask;
    u32 savedInterrupts;

    requestedMask = 0;
    aid = 1;
    for (; aid < 16; aid++) {
        aidBit = 1 << aid;
        if ((gMultiBootParent->mHeader.mSendCompleteMask & aidBit) != 0) {
            if (MB_CommResponseRequest(aid, MULTIBOOT_RESPONSE_BOOT) == 0) {
                clearMask = ~aidBit;
                savedInterrupts = OS_DisableInterrupts();
                gMultiBootParent->mHeader.mMask &= clearMask;
                gMultiBootParent->mHeader.mRequestedMask &= clearMask;
                gMultiBootParent->mHeader.mDownloadPendingMask &= clearMask;
                gMultiBootParent->mHeader.mDownloadStartedMask &= clearMask;
                gMultiBootParent->mHeader.mSendCompleteMask &= clearMask;
                gMultiBootParent->mHeader.mBootedMask &= clearMask;
                OS_RestoreInterrupts(savedInterrupts);
                MB_DisconnectChild(aid);
            } else {
                requestedMask |= aidBit;
            }
        }
    }
    if (requestedMask == 0) {
        SetMultiBootParentState(MULTIBOOT_PARENT_STATE_FAILED);
    } else {
        SetMultiBootParentState(MULTIBOOT_PARENT_STATE_BOOTING);
    }
}

void StartMultiBootEndToIdle(void) {
    SetMultiBootParentState(MULTIBOOT_PARENT_STATE_ENDING);
    MB_EndToIdle();
}

void MultiBootParentStateCallback(u32 aid, u32 code, void *data) {
    WirelessMessage *event = data;
    MultiBootParent *parent;
    u32 value;
    u16 clearMask;
    u8 *childMac;

    switch (code) {
        case MULTIBOOT_PARENT_CHILD_CONNECTED:
            if (GetMultiBootParentState() == MULTIBOOT_PARENT_STATE_ACCEPTING_CHILDREN) {
                parent = gMultiBootParent;
                value = OS_DisableInterrupts();
                BIT_SET(parent->mHeader.mMask, aid);
                OS_RestoreInterrupts(value);
                childMac = gMultiBootParent->mRecords[aid - 1].mMacAddress;
                childMac[0] = event->mMacAddress[0];
                childMac[1] = event->mMacAddress[1];
                childMac[2] = event->mMacAddress[2];
                childMac[3] = event->mMacAddress[3];
                childMac[4] = event->mMacAddress[4];
                childMac[5] = event->mMacAddress[5];
                gMultiBootParent->mRecords[aid - 1].mAid = aid;
            }
            break;
        case MULTIBOOT_PARENT_CHILD_DISCONNECTED:
            if (GetMultiBootChildState(aid) != MULTIBOOT_CHILD_STATE_BOOT_STARTABLE) {
                clearMask = ~(1 << aid);
                value = OS_DisableInterrupts();
                gMultiBootParent->mHeader.mMask &= clearMask;
                gMultiBootParent->mHeader.mRequestedMask &= clearMask;
                gMultiBootParent->mHeader.mDownloadPendingMask &= clearMask;
                gMultiBootParent->mHeader.mDownloadStartedMask &= clearMask;
                gMultiBootParent->mHeader.mSendCompleteMask &= clearMask;
                gMultiBootParent->mHeader.mBootedMask &= clearMask;
                OS_RestoreInterrupts(value);
            }
            break;
        case MULTIBOOT_PARENT_CHILD_REQUESTED:
            if (GetMultiBootParentState() != MULTIBOOT_PARENT_STATE_ACCEPTING_CHILDREN) {
                KickMultiBootChild(aid);
                break;
            }
            BIT_SET(gMultiBootParent->mHeader.mRequestedMask, aid);
            AcceptMultiBootChildRequest(aid);
            value = (u32) MB_CommGetChildUser(aid);
            if (value != 0) {
                MI_CpuCopy8((void *) value, &gMultiBootParent->mRecords[aid - 1], 0x16);
            }
            break;
        case MULTIBOOT_PARENT_CHILD_WAITING:
            BIT_CLEAR(gMultiBootParent->mHeader.mRequestedMask, aid);
            BIT_SET(gMultiBootParent->mHeader.mDownloadPendingMask, aid);
            if (GetMultiBootParentState() == MULTIBOOT_PARENT_STATE_DOWNLOADING) {
                StartMultiBootChildDownload(aid);
            }
            break;
        case MULTIBOOT_PARENT_DOWNLOAD_DONE:
            BIT_CLEAR(gMultiBootParent->mHeader.mDownloadStartedMask, aid);
            BIT_SET(gMultiBootParent->mHeader.mSendCompleteMask, aid);
            break;
        case MULTIBOOT_PARENT_CHILD_BOOTED:
            BIT_CLEAR(gMultiBootParent->mHeader.mSendCompleteMask, aid);
            BIT_SET(gMultiBootParent->mHeader.mBootedMask, aid);
            if (gMultiBootParent->mHeader.mMask == gMultiBootParent->mHeader.mBootedMask) {
                MB_EndToIdle();
            }
            break;
        case MULTIBOOT_PARENT_ENDED:
            if (GetMultiBootParentState() == MULTIBOOT_PARENT_STATE_BOOTING) {
                SetMultiBootParentState(MULTIBOOT_PARENT_STATE_BOOTED);
            } else {
                SetMultiBootParentState(MULTIBOOT_PARENT_STATE_ENDED);
            }
            if (gMultiBootParent->mFileBuffer != NULL) {
                gMultiBootParent->mFileBuffer = NULL;
            }
            if (gMultiBootParent->mMultiBootWorkPointer != NULL) {
                gMultiBootParent->mMultiBootWorkPointer = NULL;
            }
            break;
        case MULTIBOOT_PARENT_ERROR:
            switch (event->mCommand) {
                case WIRELESS_REQUEST_RESTART:
                case WIRELESS_REQUEST_CLOSE_STACK:
                case WIRELESS_REQUEST_CLOSE_HOST:
                    SetMultiBootParentState(MULTIBOOT_PARENT_STATE_FAILED);
                    break;
                case WIRELESS_REQUEST_OPEN_HOST:
                    break;
            }
            break;
        case MULTIBOOT_PARENT_STARTED:
        case MULTIBOOT_PARENT_CHILD_REFUSED:
        case MULTIBOOT_PARENT_CHILD_ENTERED:
        case MULTIBOOT_PARENT_DOWNLOAD_STARTED:
        case MULTIBOOT_PARENT_BOOT_ACKED:
        case MULTIBOOT_PARENT_ENTRY_FULL:
            break;
        default:
            OS_Terminate();
            break;
    }
}

void SetMultiBootParentState(u16 state) {
    gMultiBootParent->mHeader.mState = state;
}

u16 GetMultiBootParentState(void) {
    return *(u16 *) (u32) gMultiBootParent;
}

u16 GetMultiBootChildMask(u32 maskIndex) {
    MultiBootParent *parent;

    parent = gMultiBootParent;
    gMultiBootMaskPointers[0] = &parent->mHeader.mMask;
    gMultiBootMaskPointers[1] = &parent->mHeader.mRequestedMask;
    gMultiBootMaskPointers[2] = &parent->mHeader.mDownloadPendingMask;
    gMultiBootMaskPointers[3] = &parent->mHeader.mDownloadStartedMask;
    gMultiBootMaskPointers[4] = &parent->mHeader.mSendCompleteMask;
    gMultiBootMaskPointers[5] = &parent->mHeader.mBootedMask;
    return *gMultiBootMaskPointers[maskIndex];
}

u32 GetMultiBootChildState(u32 aid) {
    u32 savedInterrupts;
    u16 aidBit;
    u16 headerCopy[7];

    savedInterrupts = OS_DisableInterrupts();
    aidBit = 1 << aid;
    if ((gMultiBootParent->mHeader.mMask & aidBit) == 0) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    MI_CpuCopy8(gMultiBootParent, headerCopy, 0xe);
    OS_RestoreInterrupts(savedInterrupts);
    if ((headerCopy[2] & aidBit) != 0) {
        return 2;
    }
    if ((headerCopy[3] & aidBit) != 0) {
        return 3;
    }
    if ((headerCopy[4] & aidBit) != 0) {
        return 4;
    }
    if ((headerCopy[5] & aidBit) != 0) {
        return 5;
    }
    if ((headerCopy[6] & aidBit) != 0) {
        return 6;
    }
    return 1;
}

void *GetMultiBootChildRecord(u32 aid) {
    MultiBootParent *parent = gMultiBootParent;
    if (BIT_IS_SET(parent->mHeader.mMask, aid)) {
        return &parent->mRecords[aid - 1];
    }
    return NULL;
}
