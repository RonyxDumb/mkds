#include "03/Net/multiboot_parent_download.h"
#include "03/Net/essid_packet_steps.h"
#include "code_0200fc8c.h"
#include "os_thread.h"
#include "mb_data.h"
#include "code_02009928.h"

#include "03/unk_021da000.h"
#include "code_0214d018.h"
#include "mb_parent.h"
#include "fs_file.h"
#include "data_02008000.h"
#include "code_02008880.h"
#include "code_0200c0d8.h"
#include "code_02142eac.h"
#include "code_0200ad00.h"
#include "wm_etc.h"
#include "code_0214c778.h"
#include "code_0214cfe4.h"
#include "code_02007ec4.h"
#include "code_02003be0.h"
#include "03/Net/wh.h"
#include "mb_fileinfo.h"

MultiBootParent *gMultiBootParent;
u16 *gMultiBootMaskPointers[6];

void InitMultiBootParent(u8 *object) {
    gMultiBootParent = (MultiBootParent *) object;
    InitWhWork((WhWork *) (object + 0x1b160));
    gMultiBootParent->mCommWorkPointer = NULL;
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
    *(MultiBootParentHeader *) gMultiBootParent = clearedHeader;
    gMultiBootParent->mCommWorkPointer = gMultiBootParent->mCommWork;
    if (MB_Init(gMultiBootParent->mCommWorkPointer, &userInfo, ggid, tgid, 2) != 0) {
        OS_Terminate();
    }
    MB_SetParentCommParam(0x100, 1);
    MB_CommSetParentStateCallback(MultiBootParentStateCallback);
    SetMultiBootParentState(1);
}

void StartMultiBootParentFromIdle(MultiBootGameRegistryView *gameRegistry, u16 channel) {
    SetMultiBootParentState(2);
    if (MB_StartParentFromIdle(channel) != 0) {
        SetMultiBootParentState(7);
        return;
    }
    if (RegisterMultiBootFile(gameRegistry) == 0) {
        OS_Terminate();
    }
}

BOOL RegisterMultiBootFile(MultiBootGameRegistryView *gameRegistry) {
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
        gMultiBootParent->mFileBuffer = (u8 *) gMultiBootParent + 0x2c;
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

    if (MB_CommResponseRequest(aid, 1) == 0) {
        clearMask = ~(1 << aid);
        savedInterrupts = OS_DisableInterrupts();
        gMultiBootParent->mMask &= clearMask;
        gMultiBootParent->mRequestedMask &= clearMask;
        gMultiBootParent->mDownloadPendingMask &= clearMask;
        gMultiBootParent->mDownloadStartedMask &= clearMask;
        gMultiBootParent->mSendCompleteMask &= clearMask;
        gMultiBootParent->mBootStartableMask &= clearMask;
        OS_RestoreInterrupts(savedInterrupts);
        MB_DisconnectChild(aid);
    }
}

void KickMultiBootChild(u32 aid) {
    u16 clearMask;
    u32 savedInterrupts;
    s32 aidBit;

    if (MB_CommResponseRequest(aid, 0) == 0) {
        clearMask = ~(1 << aid);
        savedInterrupts = OS_DisableInterrupts();
        gMultiBootParent->mMask &= clearMask;
        gMultiBootParent->mRequestedMask &= clearMask;
        gMultiBootParent->mDownloadPendingMask &= clearMask;
        gMultiBootParent->mDownloadStartedMask &= clearMask;
        gMultiBootParent->mSendCompleteMask &= clearMask;
        gMultiBootParent->mBootStartableMask &= clearMask;
        OS_RestoreInterrupts(savedInterrupts);
        MB_DisconnectChild(aid);
    } else {
        savedInterrupts = OS_DisableInterrupts();
        aidBit = 1 << aid;
        gMultiBootParent->mRequestedMask &= ~aidBit;
        gMultiBootParent->mMask &= ~aidBit;
        OS_RestoreInterrupts(savedInterrupts);
    }
}

void StartMultiBootChildDownload(u32 aid) {
    u16 clearMask;
    u32 savedInterrupts;
    s32 aidBit;

    if (MB_CommResponseRequest(aid, 2) == 0) {
        clearMask = ~(1 << aid);
        savedInterrupts = OS_DisableInterrupts();
        gMultiBootParent->mMask &= clearMask;
        gMultiBootParent->mRequestedMask &= clearMask;
        gMultiBootParent->mDownloadPendingMask &= clearMask;
        gMultiBootParent->mDownloadStartedMask &= clearMask;
        gMultiBootParent->mSendCompleteMask &= clearMask;
        gMultiBootParent->mBootStartableMask &= clearMask;
        OS_RestoreInterrupts(savedInterrupts);
        MB_DisconnectChild(aid);
    } else {
        savedInterrupts = OS_DisableInterrupts();
        aidBit = 1 << aid;
        gMultiBootParent->mDownloadPendingMask &= ~aidBit;
        gMultiBootParent->mDownloadStartedMask |= aidBit;
        OS_RestoreInterrupts(savedInterrupts);
    }
}

void StartMultiBootDownloads(void) {
    u16 aid;
    s32 aidBit;
    u16 clearMask;
    u32 savedInterrupts;

    SetMultiBootParentState(3);
    for (aid = 1; aid < 16; aid++) {
        aidBit = 1 << aid;
        if ((gMultiBootParent->mMask & aidBit) != 0) {
            if ((gMultiBootParent->mRequestedMask & aidBit) == 0) {
                if ((gMultiBootParent->mDownloadPendingMask & aidBit) == 0) {
                    clearMask = ~aidBit;
                    savedInterrupts = OS_DisableInterrupts();
                    gMultiBootParent->mMask &= clearMask;
                    gMultiBootParent->mRequestedMask &= clearMask;
                    gMultiBootParent->mDownloadPendingMask &= clearMask;
                    gMultiBootParent->mDownloadStartedMask &= clearMask;
                    gMultiBootParent->mSendCompleteMask &= clearMask;
                    gMultiBootParent->mBootStartableMask &= clearMask;
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

    if (gMultiBootParent->mMask == 0) {
        return 0;
    }
    for (aid = 1; aid < 16; aid++) {
        if ((gMultiBootParent->mMask & (1 << aid)) != 0) {
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
        if ((gMultiBootParent->mSendCompleteMask & aidBit) != 0) {
            if (MB_CommResponseRequest(aid, 3) == 0) {
                clearMask = ~aidBit;
                savedInterrupts = OS_DisableInterrupts();
                gMultiBootParent->mMask &= clearMask;
                gMultiBootParent->mRequestedMask &= clearMask;
                gMultiBootParent->mDownloadPendingMask &= clearMask;
                gMultiBootParent->mDownloadStartedMask &= clearMask;
                gMultiBootParent->mSendCompleteMask &= clearMask;
                gMultiBootParent->mBootStartableMask &= clearMask;
                OS_RestoreInterrupts(savedInterrupts);
                MB_DisconnectChild(aid);
            } else {
                requestedMask |= aidBit;
            }
        }
    }
    if (requestedMask == 0) {
        SetMultiBootParentState(7);
    } else {
        SetMultiBootParentState(4);
    }
}

void StartMultiBootEndToIdle(void) {
    SetMultiBootParentState(6);
    MB_EndToIdle();
}

void MultiBootParentStateCallback(u32 aid, u32 code, WirelessMessage *event) {
    MultiBootParent *parent;
    u32 value;
    u16 clearMask;
    u8 *childMac;

    switch (code) {
        case MULTIBOOT_PARENT_CHILD_CONNECTED:
            if (GetMultiBootParentState() == 2) {
                parent = gMultiBootParent;
                value = OS_DisableInterrupts();
                parent->mMask |= 1 << aid;
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
            if (GetMultiBootChildState(aid) != 6) {
                clearMask = ~(1 << aid);
                value = OS_DisableInterrupts();
                gMultiBootParent->mMask &= clearMask;
                gMultiBootParent->mRequestedMask &= clearMask;
                gMultiBootParent->mDownloadPendingMask &= clearMask;
                gMultiBootParent->mDownloadStartedMask &= clearMask;
                gMultiBootParent->mSendCompleteMask &= clearMask;
                gMultiBootParent->mBootStartableMask &= clearMask;
                OS_RestoreInterrupts(value);
            }
            break;
        case MULTIBOOT_PARENT_CHILD_REQUESTED:
            if (GetMultiBootParentState() != 2) {
                KickMultiBootChild(aid);
                break;
            }
            gMultiBootParent->mRequestedMask |= 1 << aid;
            AcceptMultiBootChildRequest(aid);
            value = (u32) MB_CommGetChildUser(aid);
            if (value != 0) {
                MI_CpuCopy8((void *) value, &gMultiBootParent->mRecords[aid - 1], 0x16);
            }
            break;
        case MULTIBOOT_PARENT_CHILD_WAITING:
            gMultiBootParent->mRequestedMask &= ~(1 << aid);
            gMultiBootParent->mDownloadPendingMask |= 1 << aid;
            if (GetMultiBootParentState() == 3) {
                StartMultiBootChildDownload(aid);
            }
            break;
        case MULTIBOOT_PARENT_DOWNLOAD_DONE:
            gMultiBootParent->mDownloadStartedMask &= ~(1 << aid);
            gMultiBootParent->mSendCompleteMask |= 1 << aid;
            break;
        case MULTIBOOT_PARENT_CHILD_BOOTED:
            gMultiBootParent->mSendCompleteMask &= ~(1 << aid);
            gMultiBootParent->mBootStartableMask |= 1 << aid;
            if (gMultiBootParent->mMask == gMultiBootParent->mBootStartableMask) {
                MB_EndToIdle();
            }
            break;
        case MULTIBOOT_PARENT_ENDED:
            if (GetMultiBootParentState() == 4) {
                SetMultiBootParentState(5);
            } else {
                SetMultiBootParentState(0);
            }
            if (gMultiBootParent->mFileBuffer != NULL) {
                gMultiBootParent->mFileBuffer = NULL;
            }
            if (gMultiBootParent->mCommWorkPointer != NULL) {
                gMultiBootParent->mCommWorkPointer = NULL;
            }
            break;
        case MULTIBOOT_PARENT_ERROR:
            switch (event->mCommand) {
                case 1:
                case 2:
                case 9:
                    SetMultiBootParentState(7);
                    break;
                case 8:
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
    *(u16 *) (*(u32 *) &gMultiBootParent) = state;
}

u16 GetMultiBootParentState(void) {
    return *(u16 *) (u32) gMultiBootParent;
}

u16 GetMultiBootChildMask(u32 maskIndex) {
    MultiBootParent *parent;

    parent = gMultiBootParent;
    gMultiBootMaskPointers[0] = &parent->mMask;
    gMultiBootMaskPointers[1] = &parent->mRequestedMask;
    gMultiBootMaskPointers[2] = &parent->mDownloadPendingMask;
    gMultiBootMaskPointers[3] = &parent->mDownloadStartedMask;
    gMultiBootMaskPointers[4] = &parent->mSendCompleteMask;
    gMultiBootMaskPointers[5] = &parent->mBootStartableMask;
    return *gMultiBootMaskPointers[maskIndex];
}

u32 GetMultiBootChildState(u32 aid) {
    u32 savedInterrupts;
    u16 aidBit;
    u16 headerCopy[7];

    savedInterrupts = OS_DisableInterrupts();
    aidBit = 1 << aid;
    if ((gMultiBootParent->mMask & aidBit) == 0) {
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

void *GetMultiBootChildRecord(u32 index) {
    MultiBootParent *state = gMultiBootParent;
    if ((state->mMask & (1 << index)) != 0) {
        return &state->mRecords[index - 1];
    }
    return NULL;
}
