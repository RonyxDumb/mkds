#include "03/Net/child_wait_session.h"

#include "03/unk_021da000.h"
#include "03/Net/essid_wcm.h"
#include "code_0200fc8c.h"
#include "os_thread.h"
#include "mb_data.h"
#include "code_02009928.h"
#include "03/Net/multiboot_parent_download.h"
#include "03/Menu/message_box_create.h"
#include "03/Net/wh.h"
#include "code_0214d018.h"
#include "mb_parent.h"
#include "03/code_021d0dd8.h"
#include "03/code_021d0df8.h"
#include "03/code_021cd2e0.h"
#include "03/code_021d0000.h"
#include "os_tick.h"
#include "code_02142eac.h"
#include "dwc_backup.h"

void InitChildWaitSession(ChildWaitSessionView *session, ChildWaitParamsView *params) {
    gChildWaitSessionView = session;
    InitMultiBootParent(session->mUnk_b00);
    gChildWaitSessionView->mTgid = 0;
    gChildWaitSessionView->mChannel = 0;
    gChildWaitSessionView->mState = 1;
    gChildWaitSessionView->mPrevState = 1;
    gChildWaitSessionView->mEndWaitFrames = 0;
    ClearChildWaitSharedEntries();
    gChildWaitSessionView->mRomFilePathp = params->mRomFilePathp;
    gChildWaitSessionView->mGameNamep = params->mGameNamep;
    gChildWaitSessionView->mGameIntroductionp = params->mGameIntroductionp;
    gChildWaitSessionView->mIconCharPathp = params->mIconCharPathp;
    gChildWaitSessionView->mIconPalettePathp = params->mIconPalettePathp;
    gChildWaitSessionView->mGgid = params->mGgid;
    gChildWaitSessionView->mHandshakeByte = params->mHandshakeByte;
    gChildWaitSessionView->mMaxPlayerNum = 2;
    OS_GetTick();
    ReadNvramEntries(gChildWaitSessionView->mUnk_64c);
    OS_GetTick();
    gChildWaitSessionView->mUnk_aa0[1] = (u8 *) GetApStore();
}

BOOL StopChildWaitSession(void) {
    ChildWaitSessionView *session = gChildWaitSessionView;
    u8 *statePointer = &session->mState;
    u8 state = *statePointer;

    if (state == 1 || state == 0x14 || state == 0x17 || state == 0x1a || state == 0x1d) {
        session->mState = 0x22;
        gChildWaitSessionView->mRequest = 0;
        return 1;
    }
    if (state == 4 || state == 5 || state == 6 || state == 0xd) {
        if (state == 4 && session->mMultiBootInitFrames < 6) {
            return 0;
        }
        MB_EndToIdle();
        gChildWaitSessionView->mState = 0x10;
        gChildWaitSessionView->mRequest = 2;
        return 1;
    }
    if (state == 9 || state == 10) {
        *statePointer = 0x20;
        return 1;
    }
    if (state == 0xc) {
        *statePointer = 0x22;
        return 1;
    }
    switch (state) {
        case 2:
            return 0;
        default:
            return 0;
    }
}

void ResetChildWaitSessionState(void) {
    SetWhGgid(gChildWaitSessionView->mGgid);
    gChildWaitSessionView->mState = 1;
    gChildWaitSessionView->mTgid = WM_GetNextTgid();
    MI_CpuCopy8(gChildWaitSessionView->mUnk_aa0[1], gChildWaitSessionView->mUnk_a50, 0x40);
    gChildWaitSessionView->mHandshakeDone = 0;
    gChildWaitSessionView->mStallCount = 0;
    gChildWaitSessionView->mTgid++;
}

BOOL StartChildWaitSession(void) {
    if (gChildWaitSessionView->mState == 1 || gChildWaitSessionView->mState == 0x1a ||
        gChildWaitSessionView->mState == 0x1d) {
        ResetChildWaitSessionState();
        ClearWhAndInitialize();
        gChildWaitSessionView->mState = 2;
        return 1;
    }
    return 0;
}

BOOL StartChildWaitDownload(void) {
    if (gChildWaitSessionView->mState == 5) {
        gChildWaitSessionView->mState = 6;
        StartMultiBootDownloads();
        return 1;
    }
    return 0;
}

void AdvanceChildWaitState(void) {
    switch (gChildWaitSessionView->mState) {
        case 1:
            if (gChildWaitSessionView->mRequest == 1) {
                gChildWaitSessionView->mRequest = 0;
                StartChildWaitSession();
                return;
            }
            if (gChildWaitSessionView->mRequest == 2) {
                gChildWaitSessionView->mRequest = 0;
                gChildWaitSessionView->mState = 0x22;
            }
            return;
        case 2:
            AdvanceChildWaitWhStart();
            return;
        case 3:
            InitChildWaitMultiBoot();
            gChildWaitSessionView->mState = 4;
            return;
        case 4:
            gChildWaitSessionView->mMultiBootInitFrames++;
            AdvanceChildWaitMultiBoot();
            return;
        case 5:
        case 6:
            AdvanceChildWaitMultiBoot();
            return;
        case 7:
            StartChildWaitDataConnect();
            return;
        case 8:
        case 9:
        case 10:
            AdvanceChildWaitDataSharing();
            return;
        case 11:
            AdvanceChildWaitAfterReply();
            return;
        case 16:
            gChildWaitSessionView->mEndWaitFrames = 0;
            gChildWaitSessionView->mState = 0x11;
            return;
        case 17:
            if (gChildWaitSessionView->mEndWaitFrames++ > 0x1e) {
                EndChildWaitWh();
            }
            return;
        case 18:
            MB_EndToIdle();
            gChildWaitSessionView->mEndWaitFrames = 0;
            gChildWaitSessionView->mState = 0x16;
            return;
        case 19:
            if (gChildWaitSessionView->mEndWaitFrames++ > 0x1e) {
                if (GetWhState() == 1) {
                    EndWh();
                    gChildWaitSessionView->mState = 0x14;
                }
            }
            return;
        case 21:
            FinalizeWh();
            gChildWaitSessionView->mEndWaitFrames = 0;
            gChildWaitSessionView->mState = 0x16;
            return;
        case 22:
            if (gChildWaitSessionView->mEndWaitFrames++ > 0x1e) {
                if (GetWhState() == 1) {
                    EndWh();
                    gChildWaitSessionView->mState = 0x17;
                }
            }
            return;
        case 24:
            FinalizeWh();
            gChildWaitSessionView->mEndWaitFrames = 0;
            gChildWaitSessionView->mState = 0x19;
            return;
        case 25:
            if (gChildWaitSessionView->mEndWaitFrames++ > 0x1e) {
                if (GetWhState() == 1) {
                    EndWh();
                    gChildWaitSessionView->mState = 0x1a;
                }
            }
            return;
        case 27:
            FinalizeWh();
            gChildWaitSessionView->mEndWaitFrames = 0;
            gChildWaitSessionView->mState = 0x1c;
            return;
        case 28:
            if (gChildWaitSessionView->mEndWaitFrames++ > 0x1e) {
                if (GetWhState() == 1) {
                    EndWh();
                    gChildWaitSessionView->mState = 0x1d;
                    return;
                } else {
                    u32 stateFrames = gChildWaitSessionView->mEndWaitFrames;

                    if (stateFrames % 0x1e == 1 && stateFrames > 0x37) {
                        FinalizeWh();
                    }
                }
            }
            return;
        case 32:
            FinalizeWh();
            gChildWaitSessionView->mEndWaitFrames = 0;
            gChildWaitSessionView->mState = 0x21;
            return;
        case 33:
            if (gChildWaitSessionView->mEndWaitFrames++ > 0x1e) {
                if (GetWhState() == 1) {
                    EndWh();
                    gChildWaitSessionView->mState = 0x22;
                }
            }
            return;
        case 30:
            FinalizeWh();
            return;
        case 34:
            return;
    }
}

void GetChildWaitStateChange(u8 *stateOut, u8 *changedOut) {
    *stateOut = gChildWaitSessionView->mState;
    if (gChildWaitSessionView->mState != gChildWaitSessionView->mPrevState) {
        *changedOut = 1;
    } else {
        *changedOut = 0;
    }
    gChildWaitSessionView->mPrevState = gChildWaitSessionView->mState;
}

void *GetChildWaitChildUser(void) {
    return MB_CommGetChildUser(1);
}

void AdvanceChildWaitWhStart(void) {
    switch (GetWhState()) {
        case 1:
            StartWhChannelSearch();
            return;
        case 7:
            gChildWaitSessionView->mChannel = DecideWhChannel();
            gChildWaitSessionView->mMultiBootInitFrames = 0;
            gChildWaitSessionView->mState = 3;
            return;
        case 0:
            gChildWaitSessionView->mMultiBootInitFrames = 0;
            gChildWaitSessionView->mState = 3;
            return;
        case 9:
            StartWhResetOrFail();
            return;
        case 3:
            break;
        default:
            OS_Terminate();
            break;
    }
}

void InitChildWaitMultiBoot(void) {
    InitMultiBootParentComm(gChildWaitSessionView->mGgid, gChildWaitSessionView->mTgid);
}

void AdvanceChildWaitMultiBoot(void) {
    switch (GetMultiBootParentState()) {
        case 1:
            StartMultiBootParentFromIdle((Unk021cf8ac *) &gChildWaitSessionView->mRomFilePathp,
                                         gChildWaitSessionView->mChannel);
            return;
        case 2:
            if (GetMultiBootChildMask(2) != 0) {
                gChildWaitSessionView->mState = 5;
                return;
            }
            if (GetMultiBootChildMask(3) != 0 || GetMultiBootChildMask(4) != 0) {
                gChildWaitSessionView->mState = 6;
                return;
            }
            if (gChildWaitSessionView->mState == 5) {
                if (GetMultiBootChildMask(2) == 0) {
                    gChildWaitSessionView->mState = 0xd;
                    return;
                }
            }
            break;
        case 3:
            if (AreMultiBootChildrenBootable() != 0) {
                StartMultiBootBootRequests();
                return;
            }
            if ((u8) (gChildWaitSessionView->mState + 250) <= 1) {
                if (GetMultiBootChildMask(3) == 0) {
                    gChildWaitSessionView->mState = 0x12;
                    return;
                }
            }
            break;
        case 5:
            gChildWaitSessionView->mState = 7;
            return;
        case 7:
            StartMultiBootEndToIdle();
            gChildWaitSessionView->mState = 1;
            return;
        case 0:
            switch (GetWhState()) {
                case 1:
                    EndWh();
                    return;
                case 0:
                    gChildWaitSessionView->mState = 0x1f;
                    return;
                case 3:
                    break;
                default:
                    gChildWaitSessionView->mState = 0x1f;
                    break;
            }
            break;
    }
}

void StartChildWaitDataConnect(void) {
    ClearChildWaitSharedEntries();
    SetWhConnectCallback((u32) &AcceptMatchingWhChild);
    gChildWaitSessionView->mState = 8;
}

void AdvanceChildWaitDataSharing(void) {
    u16 blockNumber;
    s32 blockIndex;

    switch (GetWhState()) {
        case 1:
            StartWhParentConnect(4, gChildWaitSessionView->mTgid + 1, gChildWaitSessionView->mChannel);
            break;
        case 4:
        case 5:
        case 6:
            blockNumber = gChildWaitSessionView->mBlockNumber;
            blockIndex = blockNumber % 16;
            ExchangeChildWaitSharedEntries(0, blockNumber, gChildWaitSessionView->mUnk_aa0[1] + (blockIndex << 6));
            ReadChildWaitReply();
            if (gChildWaitSessionView->mState != 0x1b) {
                if (gChildWaitSessionView->mStallCount > 0x1e0) {
                    gChildWaitSessionView->mState = 0x1b;
                    return;
                }
                if (GetChildWaitReplyCode() == 0x10 || GetChildWaitReplyCode() == 0x20) {
                    GetChildWaitReplyCode();
                    gChildWaitSessionView->mState = 0xa;
                } else if (GetChildWaitReplyCode() == 0x40) {
                    gChildWaitSessionView->mState = 0xb;
                } else if (GetChildWaitReplyCode() == 0xff) {
                    gChildWaitSessionView->mState = 0x1b;
                } else if (GetChildWaitReplyCode() == 0x50) {
                    gChildWaitSessionView->mState = 0x15;
                } else if (GetChildWaitReplyCode() == 0x60) {
                    gChildWaitSessionView->mState = 0x18;
                } else if (GetChildWaitReplyCode() == 0x70) {
                    gChildWaitSessionView->mState = 0x1b;
                } else if (GetChildWaitReplyCode() == 0) {
                    gChildWaitSessionView->mState = 8;
                } else if (GetChildWaitReplyCode() == 0xbd) {
                    gChildWaitSessionView->mState = 9;
                } else {
                    gChildWaitSessionView->mState = 0x1f;
                }
            }
            break;
    }
}

void AdvanceChildWaitAfterReply(void) {
    gChildWaitSessionView->mState = 0xc;
}

BOOL EndChildWaitWh(void) {
    int whState;
    whState = GetWhState();
    if (whState == 1) {
        EndWh();
        gChildWaitSessionView->mState = 1;
        return 1;
    }
    return 0;
}

u32 AcceptMatchingWhChild(Unk021425e8 *event) {
    u16 aid = GetRecordValueByMacAddress(event->mMacAddress);
    if (aid == 0) {
        return 0;
    }
    gChildWaitSessionView->mUnk_aa0[aid - 1] = GetMultiBootChildRecord(aid);
    return 1;
}

void ClearChildWaitSharedEntries(void) {
    MI_CpuFill8(gChildWaitSessionView->mSharedEntries, 0, 0x100);
    MI_CpuFill8(gChildWaitSessionView, 0, 0x100);
    gChildWaitSessionView->mSendEntry = (ChildWaitSharedEntry *) gChildWaitSessionView;
}

void ExchangeChildWaitSharedEntries(u16 code, u16 value, u8 *payload) {
    u16 aid;

    if (gChildWaitSessionView->mHandshakeDone == 1) {
        gChildWaitSessionView->mSendEntry->mCode = code;
        gChildWaitSessionView->mSendEntry->mUnk_02 = value;
        MI_CpuCopy8(payload, gChildWaitSessionView->mSendEntry->mUnk_04, 0x40);
    } else {
        gChildWaitSessionView->mStallCount = gChildWaitSessionView->mStallCount + 1;
        gChildWaitSessionView->mSendEntry->mCode = 0xbc;
        gChildWaitSessionView->mSendEntry->mUnk_04[0] = gChildWaitSessionView->mHandshakeByte;
    }
    if (GetWhState() == 5) {
        if (StepWhDataSharing(gChildWaitSessionView) == FALSE) {
            gChildWaitSessionView->mStallCount = gChildWaitSessionView->mStallCount + 4;
            return;
        }
        if (gChildWaitSessionView->mHandshakeDone == 0) {
            gChildWaitSessionView->mStallCount = gChildWaitSessionView->mStallCount + 1;
        } else {
            gChildWaitSessionView->mStallCount = 0;
            if (GetWhConnectedMask() != 3) {
                gChildWaitSessionView->mState = 0x1b;
                return;
            }
        }
        for (aid = 0; aid < 2; aid++) {
            u8 *sharedData = GetWhSharedDataAddress(aid);
            if (sharedData != NULL) {
                MI_CpuCopy8(sharedData, &gChildWaitSessionView->mSharedEntries[aid], 0x44);
                gChildWaitSessionView->mEntryPresent[aid] = 1;
            } else {
                gChildWaitSessionView->mEntryPresent[aid] = 0;
            }
        }
    }
}

void ReadChildWaitReply(void) {
    s32 entryIndex;
    ChildWaitSessionView *session;
    ChildWaitSharedEntry *entry;

    for (entryIndex = 0; entryIndex < 16; entryIndex++) {
        session = gChildWaitSessionView;
        if (session->mEntryPresent[entryIndex] != 0) {
            entry = GetChildWaitSharedEntry(session, entryIndex);
            if (entryIndex == 1) {
                if (session->mHandshakeDone == 1) {
                    if (entry->mCode != 0x10) {
                        return;
                    }
                    session->mReplyCount = session->mReplyCount + 1;
                    if ((gChildWaitSessionView->mReplyCount & 1) == 0) {
                        gChildWaitSessionView->mBlockNumber = gChildWaitSessionView->mBlockNumber + 1;
                        if (gChildWaitSessionView->mBlockNumber >= 0x24) {
                            gChildWaitSessionView->mBlockNumber = 0;
                        }
                    }
                } else {
                    session->mUnk_202 = 0xbc;
                    if (entry->mCode == 0xbd) {
                        gChildWaitSessionView->mHandshakeDone = 1;
                        gChildWaitSessionView->mBlockNumber = 0;
                        gChildWaitSessionView->mReplyCount = 0;
                    }
                }
            }
        }
    }
}

u16 GetChildWaitReplyCode(void) {
    return gChildWaitSessionView->mSharedEntries[1].mCode;
}
