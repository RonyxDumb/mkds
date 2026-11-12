#include "03/Net/multiboot_parent_download.h"
#include "03/Net/essid_wcm.h"
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

u16 *gMultiBootMaskPointers[6];

void InitMultiBootParent(u8 *object) {
    gMultiBootParent = (MultiBootParent *) object;
    InitWhWork((WhWork *) (object + 0x1b160));
    gMultiBootParent->mUnk_1b140 = NULL;
    gMultiBootParent->mUnk_1b144 = NULL;
}

void InitMultiBootParentComm(u32 ggid, u32 tgid) {
    OwnerInfo ownerInfo;
    MBUserInfo userInfo;
    MultiBootParentHeader clearedHeader;

    OS_GetOwnerInfo(&ownerInfo);
    userInfo.mUnk_00 = (userInfo.mUnk_00 & ~0xf) | (ownerInfo.mFavoriteColor & 0xf);
    userInfo.mNameLength = ownerInfo.mNickNameLength;
    MI_CpuCopy8(ownerInfo.mNickName, userInfo.mName, ownerInfo.mNickNameLength * 2);
    userInfo.mUnk_00 &= ~0xf0;
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
    gMultiBootParent->mUnk_1b140 = gMultiBootParent->mUnk_10040;
    if (MB_Init(gMultiBootParent->mUnk_1b140, &userInfo, ggid, tgid, 2) != 0) {
        OS_Terminate();
    }
    MB_SetParentCommParam(0x100, 1);
    MB_CommSetParentStateCallback(MultiBootParentStateCallback);
    SetMultiBootParentState(1);
}

void StartMultiBootParentFromIdle(Unk021cf8ac *gameRegistry, u16 channel) {
    SetMultiBootParentState(2);
    if (MB_StartParentFromIdle(channel) != 0) {
        SetMultiBootParentState(7);
        return;
    }
    if (RegisterMultiBootFile(gameRegistry) == 0) {
        OS_Terminate();
    }
}

BOOL RegisterMultiBootFile(Unk021cf8ac *gameRegistry) {
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
        gMultiBootParent->mUnk_1b144 = (u8 *) gMultiBootParent + 0x2c;
        if (gMultiBootParent->mUnk_1b144 != NULL) {
            if (MB_ReadSegment(segmentFile, gMultiBootParent->mUnk_1b144, 0x10000) != 0) {
                if (MB_RegisterFile(gameRegistry, gMultiBootParent->mUnk_1b144) != 0) {
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
        gMultiBootParent->mUnk_04 &= clearMask;
        gMultiBootParent->mUnk_06 &= clearMask;
        gMultiBootParent->mUnk_08 &= clearMask;
        gMultiBootParent->mUnk_0a &= clearMask;
        gMultiBootParent->mUnk_0c &= clearMask;
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
        gMultiBootParent->mUnk_04 &= clearMask;
        gMultiBootParent->mUnk_06 &= clearMask;
        gMultiBootParent->mUnk_08 &= clearMask;
        gMultiBootParent->mUnk_0a &= clearMask;
        gMultiBootParent->mUnk_0c &= clearMask;
        OS_RestoreInterrupts(savedInterrupts);
        MB_DisconnectChild(aid);
    } else {
        savedInterrupts = OS_DisableInterrupts();
        aidBit = 1 << aid;
        gMultiBootParent->mUnk_04 &= ~aidBit;
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
        gMultiBootParent->mUnk_04 &= clearMask;
        gMultiBootParent->mUnk_06 &= clearMask;
        gMultiBootParent->mUnk_08 &= clearMask;
        gMultiBootParent->mUnk_0a &= clearMask;
        gMultiBootParent->mUnk_0c &= clearMask;
        OS_RestoreInterrupts(savedInterrupts);
        MB_DisconnectChild(aid);
    } else {
        savedInterrupts = OS_DisableInterrupts();
        aidBit = 1 << aid;
        gMultiBootParent->mUnk_06 &= ~aidBit;
        gMultiBootParent->mUnk_08 |= aidBit;
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
            if ((gMultiBootParent->mUnk_04 & aidBit) == 0) {
                if ((gMultiBootParent->mUnk_06 & aidBit) == 0) {
                    clearMask = ~aidBit;
                    savedInterrupts = OS_DisableInterrupts();
                    gMultiBootParent->mMask &= clearMask;
                    gMultiBootParent->mUnk_04 &= clearMask;
                    gMultiBootParent->mUnk_06 &= clearMask;
                    gMultiBootParent->mUnk_08 &= clearMask;
                    gMultiBootParent->mUnk_0a &= clearMask;
                    gMultiBootParent->mUnk_0c &= clearMask;
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
        if ((gMultiBootParent->mUnk_0a & aidBit) != 0) {
            if (MB_CommResponseRequest(aid, 3) == 0) {
                clearMask = ~aidBit;
                savedInterrupts = OS_DisableInterrupts();
                gMultiBootParent->mMask &= clearMask;
                gMultiBootParent->mUnk_04 &= clearMask;
                gMultiBootParent->mUnk_06 &= clearMask;
                gMultiBootParent->mUnk_08 &= clearMask;
                gMultiBootParent->mUnk_0a &= clearMask;
                gMultiBootParent->mUnk_0c &= clearMask;
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

void MultiBootParentStateCallback(u32 aid, u32 code, Unk021425e8 *event) {
    MultiBootParent *parent;
    u32 t;
    u16 clearMask;
    u8 *childMac;

    switch (code) {
        case 2:
            if (GetMultiBootParentState() == 2) {
                parent = gMultiBootParent;
                t = OS_DisableInterrupts();
                parent->mMask |= 1 << aid;
                OS_RestoreInterrupts(t);
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
        case 3:
            if (GetMultiBootChildState(aid) != 6) {
                clearMask = ~(1 << aid);
                t = OS_DisableInterrupts();
                gMultiBootParent->mMask &= clearMask;
                gMultiBootParent->mUnk_04 &= clearMask;
                gMultiBootParent->mUnk_06 &= clearMask;
                gMultiBootParent->mUnk_08 &= clearMask;
                gMultiBootParent->mUnk_0a &= clearMask;
                gMultiBootParent->mUnk_0c &= clearMask;
                OS_RestoreInterrupts(t);
            }
            break;
        case 10:
            if (GetMultiBootParentState() != 2) {
                KickMultiBootChild(aid);
                break;
            }
            gMultiBootParent->mUnk_04 |= 1 << aid;
            AcceptMultiBootChildRequest(aid);
            t = (u32) MB_CommGetChildUser(aid);
            if (t != 0) {
                MI_CpuCopy8((void *) t, &gMultiBootParent->mRecords[aid - 1], 0x16);
            }
            break;
        case 14:
            gMultiBootParent->mUnk_04 &= ~(1 << aid);
            gMultiBootParent->mUnk_06 |= 1 << aid;
            if (GetMultiBootParentState() == 3) {
                StartMultiBootChildDownload(aid);
            }
            break;
        case 7:
            gMultiBootParent->mUnk_08 &= ~(1 << aid);
            gMultiBootParent->mUnk_0a |= 1 << aid;
            break;
        case 9:
            gMultiBootParent->mUnk_0a &= ~(1 << aid);
            gMultiBootParent->mUnk_0c |= 1 << aid;
            if (gMultiBootParent->mMask == gMultiBootParent->mUnk_0c) {
                MB_EndToIdle();
            }
            break;
        case 12:
            if (GetMultiBootParentState() == 4) {
                SetMultiBootParentState(5);
            } else {
                SetMultiBootParentState(0);
            }
            if (gMultiBootParent->mUnk_1b144 != NULL) {
                gMultiBootParent->mUnk_1b144 = NULL;
            }
            if (gMultiBootParent->mUnk_1b140 != NULL) {
                gMultiBootParent->mUnk_1b140 = NULL;
            }
            break;
        case 13:
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
        case 1:
        case 4:
        case 5:
        case 6:
        case 8:
        case 11:
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
    gMultiBootMaskPointers[1] = &parent->mUnk_04;
    gMultiBootMaskPointers[2] = &parent->mUnk_06;
    gMultiBootMaskPointers[3] = &parent->mUnk_08;
    gMultiBootMaskPointers[4] = &parent->mUnk_0a;
    gMultiBootMaskPointers[5] = &parent->mUnk_0c;
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
