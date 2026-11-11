#include "03/code_021d083c.h"

#include "03/unk_021da000.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_02009000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_02009928.h"
#include "03/code_021cf260.h"
#include "03/code_021cef90.h"
#include "03/code_021cfa68.h"
#include "code_0214d018.h"
#include "code_02007624.h"
#include "Main/Unknown/code_02007e38.h"
#include "03/code_021d0dd8.h"
#include "03/code_021d0df8.h"
#include "03/code_021cd2e0.h"
#include "03/code_021d0000.h"
#include "code_0200f5ac.h"
#include "code_02142eac.h"
#include "Main/Unknown/code_02151718.h"

void InitChildWaitSession(ChildWaitSessionView *session, Unk021d1358 *params) {
    gChildWaitSessionView = session;
    InitMultiBootParent(session->mUnk_b00);
    gChildWaitSessionView->mUnk_648 = 0;
    gChildWaitSessionView->mUnk_64a = 0;
    gChildWaitSessionView->mUnk_a90 = 1;
    gChildWaitSessionView->mUnk_a91 = 1;
    gChildWaitSessionView->mUnk_a9c = 0;
    ClearChildWaitSharedEntries();
    gChildWaitSessionView->mUnk_ab4 = params->mUnk_00;
    gChildWaitSessionView->mUnk_ab8 = params->mUnk_04;
    gChildWaitSessionView->mUnk_abc = params->mUnk_08;
    gChildWaitSessionView->mUnk_ac0 = params->mUnk_0c;
    gChildWaitSessionView->mUnk_ac4 = params->mUnk_10;
    gChildWaitSessionView->mUnk_ac8 = params->mUnk_14;
    gChildWaitSessionView->mUnk_a92 = params->mUnk_18;
    gChildWaitSessionView->mUnk_acc = 2;
    OS_GetTick();
    ReadNvramEntries(gChildWaitSessionView->mUnk_64c);
    OS_GetTick();
    gChildWaitSessionView->mUnk_aa0[1] = (u8 *) GetApStore();
}

BOOL StopChildWaitSession(void) {
    ChildWaitSessionView *session = gChildWaitSessionView;
    u8 *statePointer = &session->mUnk_a90;
    u8 state = *statePointer;

    if (state == 1 || state == 0x14 || state == 0x17 || state == 0x1a || state == 0x1d) {
        session->mUnk_a90 = 0x22;
        gChildWaitSessionView->mUnk_aac = 0;
        return 1;
    }
    if (state == 4 || state == 5 || state == 6 || state == 0xd) {
        if (state == 4 && session->mUnk_a98 < 6) {
            return 0;
        }
        MB_EndToIdle();
        gChildWaitSessionView->mUnk_a90 = 0x10;
        gChildWaitSessionView->mUnk_aac = 2;
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
    SetWhGgid(gChildWaitSessionView->mUnk_ac8);
    gChildWaitSessionView->mUnk_a90 = 1;
    gChildWaitSessionView->mUnk_648 = WM_GetNextTgid();
    MI_CpuCopy8(gChildWaitSessionView->mUnk_aa0[1], gChildWaitSessionView->mUnk_a50, 0x40);
    gChildWaitSessionView->mUnk_a93 = 0;
    gChildWaitSessionView->mUnk_204 = 0;
    gChildWaitSessionView->mUnk_648++;
}

BOOL StartChildWaitSession(void) {
    if (gChildWaitSessionView->mUnk_a90 == 1 || gChildWaitSessionView->mUnk_a90 == 0x1a ||
        gChildWaitSessionView->mUnk_a90 == 0x1d) {
        ResetChildWaitSessionState();
        ClearWhAndInitialize();
        gChildWaitSessionView->mUnk_a90 = 2;
        return 1;
    }
    return 0;
}

BOOL StartChildWaitDownload(void) {
    if (gChildWaitSessionView->mUnk_a90 == 5) {
        gChildWaitSessionView->mUnk_a90 = 6;
        StartMultiBootDownloads();
        return 1;
    }
    return 0;
}

void AdvanceChildWaitState(void) {
    switch (gChildWaitSessionView->mUnk_a90) {
        case 1:
            if (gChildWaitSessionView->mUnk_aac == 1) {
                gChildWaitSessionView->mUnk_aac = 0;
                StartChildWaitSession();
                return;
            }
            if (gChildWaitSessionView->mUnk_aac == 2) {
                gChildWaitSessionView->mUnk_aac = 0;
                gChildWaitSessionView->mUnk_a90 = 0x22;
            }
            return;
        case 2:
            AdvanceChildWaitWhStart();
            return;
        case 3:
            InitChildWaitMultiBoot();
            gChildWaitSessionView->mUnk_a90 = 4;
            return;
        case 4:
            gChildWaitSessionView->mUnk_a98++;
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
            gChildWaitSessionView->mUnk_a9c = 0;
            gChildWaitSessionView->mUnk_a90 = 0x11;
            return;
        case 17:
            if (gChildWaitSessionView->mUnk_a9c++ > 0x1e) {
                EndChildWaitWh();
            }
            return;
        case 18:
            MB_EndToIdle();
            gChildWaitSessionView->mUnk_a9c = 0;
            gChildWaitSessionView->mUnk_a90 = 0x16;
            return;
        case 19:
            if (gChildWaitSessionView->mUnk_a9c++ > 0x1e) {
                if (GetWhState() == 1) {
                    EndWh();
                    gChildWaitSessionView->mUnk_a90 = 0x14;
                }
            }
            return;
        case 21:
            FinalizeWh();
            gChildWaitSessionView->mUnk_a9c = 0;
            gChildWaitSessionView->mUnk_a90 = 0x16;
            return;
        case 22:
            if (gChildWaitSessionView->mUnk_a9c++ > 0x1e) {
                if (GetWhState() == 1) {
                    EndWh();
                    gChildWaitSessionView->mUnk_a90 = 0x17;
                }
            }
            return;
        case 24:
            FinalizeWh();
            gChildWaitSessionView->mUnk_a9c = 0;
            gChildWaitSessionView->mUnk_a90 = 0x19;
            return;
        case 25:
            if (gChildWaitSessionView->mUnk_a9c++ > 0x1e) {
                if (GetWhState() == 1) {
                    EndWh();
                    gChildWaitSessionView->mUnk_a90 = 0x1a;
                }
            }
            return;
        case 27:
            FinalizeWh();
            gChildWaitSessionView->mUnk_a9c = 0;
            gChildWaitSessionView->mUnk_a90 = 0x1c;
            return;
        case 28:
            if (gChildWaitSessionView->mUnk_a9c++ > 0x1e) {
                if (GetWhState() == 1) {
                    EndWh();
                    gChildWaitSessionView->mUnk_a90 = 0x1d;
                    return;
                } else {
                    u32 stateFrames = gChildWaitSessionView->mUnk_a9c;

                    if (stateFrames % 0x1e == 1 && stateFrames > 0x37) {
                        FinalizeWh();
                    }
                }
            }
            return;
        case 32:
            FinalizeWh();
            gChildWaitSessionView->mUnk_a9c = 0;
            gChildWaitSessionView->mUnk_a90 = 0x21;
            return;
        case 33:
            if (gChildWaitSessionView->mUnk_a9c++ > 0x1e) {
                if (GetWhState() == 1) {
                    EndWh();
                    gChildWaitSessionView->mUnk_a90 = 0x22;
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
    *stateOut = gChildWaitSessionView->mUnk_a90;
    if (gChildWaitSessionView->mUnk_a90 != gChildWaitSessionView->mUnk_a91) {
        *changedOut = 1;
    } else {
        *changedOut = 0;
    }
    gChildWaitSessionView->mUnk_a91 = gChildWaitSessionView->mUnk_a90;
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
            gChildWaitSessionView->mUnk_64a = DecideWhChannel();
            gChildWaitSessionView->mUnk_a98 = 0;
            gChildWaitSessionView->mUnk_a90 = 3;
            return;
        case 0:
            gChildWaitSessionView->mUnk_a98 = 0;
            gChildWaitSessionView->mUnk_a90 = 3;
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
    InitMultiBootParentComm(gChildWaitSessionView->mUnk_ac8, gChildWaitSessionView->mUnk_648);
}

void AdvanceChildWaitMultiBoot(void) {
    switch (GetMultiBootParentState()) {
        case 1:
            StartMultiBootParentFromIdle((Unk021cf8ac *) &gChildWaitSessionView->mUnk_ab4,
                                         gChildWaitSessionView->mUnk_64a);
            return;
        case 2:
            if (GetMultiBootChildMask(2) != 0) {
                gChildWaitSessionView->mUnk_a90 = 5;
                return;
            }
            if (GetMultiBootChildMask(3) != 0 || GetMultiBootChildMask(4) != 0) {
                gChildWaitSessionView->mUnk_a90 = 6;
                return;
            }
            if (gChildWaitSessionView->mUnk_a90 == 5) {
                if (GetMultiBootChildMask(2) == 0) {
                    gChildWaitSessionView->mUnk_a90 = 0xd;
                    return;
                }
            }
            break;
        case 3:
            if (AreMultiBootChildrenBootable() != 0) {
                StartMultiBootBootRequests();
                return;
            }
            if ((u8) (gChildWaitSessionView->mUnk_a90 + 250) <= 1) {
                if (GetMultiBootChildMask(3) == 0) {
                    gChildWaitSessionView->mUnk_a90 = 0x12;
                    return;
                }
            }
            break;
        case 5:
            gChildWaitSessionView->mUnk_a90 = 7;
            return;
        case 7:
            StartMultiBootEndToIdle();
            gChildWaitSessionView->mUnk_a90 = 1;
            return;
        case 0:
            switch (GetWhState()) {
                case 1:
                    EndWh();
                    return;
                case 0:
                    gChildWaitSessionView->mUnk_a90 = 0x1f;
                    return;
                case 3:
                    break;
                default:
                    gChildWaitSessionView->mUnk_a90 = 0x1f;
                    break;
            }
            break;
    }
}

void StartChildWaitDataConnect(void) {
    ClearChildWaitSharedEntries();
    SetWhConnectCallback((u32) &AcceptMatchingWhChild);
    gChildWaitSessionView->mUnk_a90 = 8;
}

void AdvanceChildWaitDataSharing(void) {
    u16 blockNumber;
    s32 blockIndex;

    switch (GetWhState()) {
        case 1:
            StartWhParentConnect(4, gChildWaitSessionView->mUnk_648 + 1, gChildWaitSessionView->mUnk_64a);
            break;
        case 4:
        case 5:
        case 6:
            blockNumber = gChildWaitSessionView->mUnk_200;
            blockIndex = blockNumber % 16;
            ExchangeChildWaitSharedEntries(0, blockNumber, gChildWaitSessionView->mUnk_aa0[1] + (blockIndex << 6));
            ReadChildWaitReply();
            if (gChildWaitSessionView->mUnk_a90 != 0x1b) {
                if (gChildWaitSessionView->mUnk_204 > 0x1e0) {
                    gChildWaitSessionView->mUnk_a90 = 0x1b;
                    return;
                }
                if (GetChildWaitReplyCode() == 0x10 || GetChildWaitReplyCode() == 0x20) {
                    GetChildWaitReplyCode();
                    gChildWaitSessionView->mUnk_a90 = 0xa;
                } else if (GetChildWaitReplyCode() == 0x40) {
                    gChildWaitSessionView->mUnk_a90 = 0xb;
                } else if (GetChildWaitReplyCode() == 0xff) {
                    gChildWaitSessionView->mUnk_a90 = 0x1b;
                } else if (GetChildWaitReplyCode() == 0x50) {
                    gChildWaitSessionView->mUnk_a90 = 0x15;
                } else if (GetChildWaitReplyCode() == 0x60) {
                    gChildWaitSessionView->mUnk_a90 = 0x18;
                } else if (GetChildWaitReplyCode() == 0x70) {
                    gChildWaitSessionView->mUnk_a90 = 0x1b;
                } else if (GetChildWaitReplyCode() == 0) {
                    gChildWaitSessionView->mUnk_a90 = 8;
                } else if (GetChildWaitReplyCode() == 0xbd) {
                    gChildWaitSessionView->mUnk_a90 = 9;
                } else {
                    gChildWaitSessionView->mUnk_a90 = 0x1f;
                }
            }
            break;
    }
}

void AdvanceChildWaitAfterReply(void) {
    gChildWaitSessionView->mUnk_a90 = 0xc;
}

BOOL EndChildWaitWh(void) {
    int whState;
    whState = GetWhState();
    if (whState == 1) {
        EndWh();
        gChildWaitSessionView->mUnk_a90 = 1;
        return 1;
    }
    return 0;
}

u32 AcceptMatchingWhChild(Unk021425e8 *event) {
    u16 aid = GetRecordValueByMacAddress(event->mUnk_0a);
    if (aid == 0) {
        return 0;
    }
    gChildWaitSessionView->mUnk_aa0[aid - 1] = GetMultiBootChildRecord(aid);
    return 1;
}

void ClearChildWaitSharedEntries(void) {
    MI_CpuFill8(gChildWaitSessionView->mUnk_100, 0, 0x100);
    MI_CpuFill8(gChildWaitSessionView, 0, 0x100);
    gChildWaitSessionView->mUnk_ab0 = (ChildWaitSharedEntry *) gChildWaitSessionView;
}

void ExchangeChildWaitSharedEntries(u16 code, u16 value, u8 *payload) {
    u16 aid;

    if (gChildWaitSessionView->mUnk_a93 == 1) {
        gChildWaitSessionView->mUnk_ab0->mUnk_00 = code;
        gChildWaitSessionView->mUnk_ab0->mUnk_02 = value;
        MI_CpuCopy8(payload, gChildWaitSessionView->mUnk_ab0->mUnk_04, 0x40);
    } else {
        gChildWaitSessionView->mUnk_204 = gChildWaitSessionView->mUnk_204 + 1;
        gChildWaitSessionView->mUnk_ab0->mUnk_00 = 0xbc;
        gChildWaitSessionView->mUnk_ab0->mUnk_04[0] = gChildWaitSessionView->mUnk_a92;
    }
    if (GetWhState() == 5) {
        if (StepWhDataSharing(gChildWaitSessionView) == FALSE) {
            gChildWaitSessionView->mUnk_204 = gChildWaitSessionView->mUnk_204 + 4;
            return;
        }
        if (gChildWaitSessionView->mUnk_a93 == 0) {
            gChildWaitSessionView->mUnk_204 = gChildWaitSessionView->mUnk_204 + 1;
        } else {
            gChildWaitSessionView->mUnk_204 = 0;
            if (GetWhConnectedMask() != 3) {
                gChildWaitSessionView->mUnk_a90 = 0x1b;
                return;
            }
        }
        for (aid = 0; aid < 2; aid++) {
            u8 *sharedData = GetWhSharedDataAddress(aid);
            if (sharedData != NULL) {
                MI_CpuCopy8(sharedData, &gChildWaitSessionView->mUnk_100[aid], 0x44);
                gChildWaitSessionView->mUnk_208[aid] = 1;
            } else {
                gChildWaitSessionView->mUnk_208[aid] = 0;
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
        if (session->mUnk_208[entryIndex] != 0) {
            entry = GetChildWaitSharedEntry(session, entryIndex);
            if (entryIndex == 1) {
                if (session->mUnk_a93 == 1) {
                    if (entry->mUnk_00 != 0x10) {
                        return;
                    }
                    session->mUnk_a94 = session->mUnk_a94 + 1;
                    if ((gChildWaitSessionView->mUnk_a94 & 1) == 0) {
                        gChildWaitSessionView->mUnk_200 = gChildWaitSessionView->mUnk_200 + 1;
                        if (gChildWaitSessionView->mUnk_200 >= 0x24) {
                            gChildWaitSessionView->mUnk_200 = 0;
                        }
                    }
                } else {
                    session->mUnk_202 = 0xbc;
                    if (entry->mUnk_00 == 0xbd) {
                        gChildWaitSessionView->mUnk_a93 = 1;
                        gChildWaitSessionView->mUnk_200 = 0;
                        gChildWaitSessionView->mUnk_a94 = 0;
                    }
                }
            }
        }
    }
}

u16 GetChildWaitReplyCode(void) {
    return gChildWaitSessionView->mUnk_100[1].mUnk_00;
}
