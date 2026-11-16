#include "03/Net/child_wait_session.h"

#include "03/Menu/wifi_menu_shared.h"
#include "03/Net/essid_packet_steps.h"
#include "reset_interrupts_halt.h"
#include "thread_scheduler.h"
#include "multiboot_piece_buffers.h"
#include "multiboot_communication.h"
#include "03/Net/multiboot_parent_download.h"
#include "03/Menu/message_box_create.h"
#include "03/Net/wh.h"
#include "cpu_copy_fill.h"
#include "multiboot_parent_state_machine.h"
#include "03/Net/child_wait_multiboot.h"
#include "03/Net/child_wait_wh_start.h"
#include "03/Net/ap_entries.h"
#include "tick_counter.h"
#include "wireless_link_control.h"
#include "wifi_settings_nvram_backup.h"

ChildWaitSessionView *gChildWaitSessionView;

void InitChildWaitSession(ChildWaitSessionView *session, ChildWaitParams *params) {
    gChildWaitSessionView = session;
    InitMultiBootParent(session->mMultiBootParent);
    gChildWaitSessionView->mTgid = 0;
    gChildWaitSessionView->mChannel = 0;
    gChildWaitSessionView->mState = CHILD_WAIT_STATE_IDLE;
    gChildWaitSessionView->mPrevState = 1;
    gChildWaitSessionView->mEndWaitFrames = 0;
    ClearChildWaitSharedEntries();
    gChildWaitSessionView->mGameRegistry.mRomFilePathp = params->mRomFilePathp;
    gChildWaitSessionView->mGameRegistry.mGameNamep = params->mGameNamep;
    gChildWaitSessionView->mGameRegistry.mGameIntroductionp = params->mGameIntroductionp;
    gChildWaitSessionView->mGameRegistry.mIconCharPathp = params->mBannerCharFilePathp;
    gChildWaitSessionView->mGameRegistry.mIconPalettePathp = params->mBannerPaletteFilePathp;
    gChildWaitSessionView->mGameRegistry.mGgid = params->mGgid;
    gChildWaitSessionView->mHandshakeByte = params->mHandshakeByte;
    gChildWaitSessionView->mGameRegistry.mMaxPlayerNum = 2;
    Os_GetTick();
    StructDC_SomeFn_1_from_thumb(gChildWaitSessionView->mNvramEntries);
    Os_GetTick();
    gChildWaitSessionView->mUnk_aa0[1] = (u8 *) GetApStore();
}

BOOL StopChildWaitSession(void) {
    ChildWaitSessionView *session = gChildWaitSessionView;
    u8 *statePointer = &session->mState;
    u8 state = *statePointer;

    if (state == CHILD_WAIT_STATE_IDLE || state == CHILD_WAIT_STATE_END_DONE ||
        state == CHILD_WAIT_STATE_CLOSE_NO_RESTART_DONE || state == CHILD_WAIT_STATE_CLOSE_RESTARTABLE_DONE ||
        state == CHILD_WAIT_STATE_ABORT_DONE) {
        session->mState = CHILD_WAIT_STATE_ENDED;
        gChildWaitSessionView->mRequest = CHILD_WAIT_REQUEST_NONE;
        return 1;
    }
    if (state == CHILD_WAIT_STATE_MULTIBOOT_WAIT || state == CHILD_WAIT_STATE_CHILD_JOINED ||
        state == CHILD_WAIT_STATE_DOWNLOADING || state == CHILD_WAIT_STATE_CHILD_LEFT) {
        if (state == CHILD_WAIT_STATE_MULTIBOOT_WAIT &&
            session->mMultiBootInitFrames < CHILD_WAIT_MULTIBOOT_MIN_RUN_FRAMES) {
            return 0;
        }
        MB_EndToIdle();
        gChildWaitSessionView->mState = CHILD_WAIT_STATE_STOP_MULTIBOOT;
        gChildWaitSessionView->mRequest = CHILD_WAIT_REQUEST_STOP;
        return 1;
    }
    if (state == CHILD_WAIT_STATE_SHARING_HANDSHAKE_ACKED || state == CHILD_WAIT_STATE_SHARING_BLOCK_ACKED) {
        *statePointer = CHILD_WAIT_STATE_STOP_FINALIZE;
        return 1;
    }
    if (state == CHILD_WAIT_STATE_FINAL_REPLY_DONE) {
        *statePointer = CHILD_WAIT_STATE_ENDED;
        return 1;
    }
    switch (state) {
        case CHILD_WAIT_STATE_WH_START:
            return 0;
        default:
            return 0;
    }
}

void ResetChildWaitSessionState(void) {
    SetWhGgid(gChildWaitSessionView->mGameRegistry.mGgid);
    gChildWaitSessionView->mState = CHILD_WAIT_STATE_IDLE;
    gChildWaitSessionView->mTgid = WM_GetNextTgid();
    Mem_CpuCopy8(gChildWaitSessionView->mUnk_aa0[1], gChildWaitSessionView->mApStoreHeadCopy,
                sizeof(gChildWaitSessionView->mApStoreHeadCopy));
    gChildWaitSessionView->mHandshakeDone = 0;
    gChildWaitSessionView->mStallCount = 0;
    gChildWaitSessionView->mTgid++;
}

BOOL StartChildWaitSession(void) {
    if (gChildWaitSessionView->mState == CHILD_WAIT_STATE_IDLE ||
        gChildWaitSessionView->mState == CHILD_WAIT_STATE_CLOSE_RESTARTABLE_DONE ||
        gChildWaitSessionView->mState == CHILD_WAIT_STATE_ABORT_DONE) {
        ResetChildWaitSessionState();
        ClearWhAndInitialize();
        gChildWaitSessionView->mState = CHILD_WAIT_STATE_WH_START;
        return 1;
    }
    return 0;
}

BOOL StartChildWaitDownload(void) {
    if (gChildWaitSessionView->mState == CHILD_WAIT_STATE_CHILD_JOINED) {
        gChildWaitSessionView->mState = CHILD_WAIT_STATE_DOWNLOADING;
        StartMultiBootDownloads();
        return 1;
    }
    return 0;
}

void AdvanceChildWaitState(void) {
    switch (gChildWaitSessionView->mState) {
        case CHILD_WAIT_STATE_IDLE:
            if (gChildWaitSessionView->mRequest == CHILD_WAIT_REQUEST_START) {
                gChildWaitSessionView->mRequest = CHILD_WAIT_REQUEST_NONE;
                StartChildWaitSession();
                return;
            }
            if (gChildWaitSessionView->mRequest == CHILD_WAIT_REQUEST_STOP) {
                gChildWaitSessionView->mRequest = CHILD_WAIT_REQUEST_NONE;
                gChildWaitSessionView->mState = CHILD_WAIT_STATE_ENDED;
            }
            return;
        case CHILD_WAIT_STATE_WH_START:
            AdvanceChildWaitWhStart();
            return;
        case CHILD_WAIT_STATE_MULTIBOOT_START:
            InitChildWaitMultiBoot();
            gChildWaitSessionView->mState = CHILD_WAIT_STATE_MULTIBOOT_WAIT;
            return;
        case CHILD_WAIT_STATE_MULTIBOOT_WAIT:
            gChildWaitSessionView->mMultiBootInitFrames++;
            AdvanceChildWaitMultiBoot();
            return;
        case CHILD_WAIT_STATE_CHILD_JOINED:
        case CHILD_WAIT_STATE_DOWNLOADING:
            AdvanceChildWaitMultiBoot();
            return;
        case CHILD_WAIT_STATE_DATA_CONNECT:
            StartChildWaitDataConnect();
            return;
        case CHILD_WAIT_STATE_DATA_SHARING:
        case CHILD_WAIT_STATE_SHARING_HANDSHAKE_ACKED:
        case CHILD_WAIT_STATE_SHARING_BLOCK_ACKED:
            AdvanceChildWaitDataSharing();
            return;
        case CHILD_WAIT_STATE_FINAL_REPLY:
            AdvanceChildWaitAfterReply();
            return;
        case CHILD_WAIT_STATE_STOP_MULTIBOOT:
            gChildWaitSessionView->mEndWaitFrames = 0;
            gChildWaitSessionView->mState = CHILD_WAIT_STATE_STOP_MULTIBOOT_WAIT;
            return;
        case CHILD_WAIT_STATE_STOP_MULTIBOOT_WAIT:
            if (gChildWaitSessionView->mEndWaitFrames++ > 0x1e) {
                EndChildWaitWh();
            }
            return;
        case CHILD_WAIT_STATE_CHILD_LOST:
            MB_EndToIdle();
            gChildWaitSessionView->mEndWaitFrames = 0;
            gChildWaitSessionView->mState = CHILD_WAIT_STATE_CLOSE_NO_RESTART_WAIT;
            return;
        case CHILD_WAIT_STATE_END_WAIT:
            if (gChildWaitSessionView->mEndWaitFrames++ > 0x1e) {
                if (GetWhState() == WH_STATE_IDLE) {
                    EndWh();
                    gChildWaitSessionView->mState = CHILD_WAIT_STATE_END_DONE;
                }
            }
            return;
        case CHILD_WAIT_STATE_CLOSE_NO_RESTART_FINALIZE:
            FinalizeWh();
            gChildWaitSessionView->mEndWaitFrames = 0;
            gChildWaitSessionView->mState = CHILD_WAIT_STATE_CLOSE_NO_RESTART_WAIT;
            return;
        case CHILD_WAIT_STATE_CLOSE_NO_RESTART_WAIT:
            if (gChildWaitSessionView->mEndWaitFrames++ > 0x1e) {
                if (GetWhState() == WH_STATE_IDLE) {
                    EndWh();
                    gChildWaitSessionView->mState = CHILD_WAIT_STATE_CLOSE_NO_RESTART_DONE;
                }
            }
            return;
        case CHILD_WAIT_STATE_CLOSE_RESTARTABLE_FINALIZE:
            FinalizeWh();
            gChildWaitSessionView->mEndWaitFrames = 0;
            gChildWaitSessionView->mState = CHILD_WAIT_STATE_CLOSE_RESTARTABLE_WAIT;
            return;
        case CHILD_WAIT_STATE_CLOSE_RESTARTABLE_WAIT:
            if (gChildWaitSessionView->mEndWaitFrames++ > 0x1e) {
                if (GetWhState() == WH_STATE_IDLE) {
                    EndWh();
                    gChildWaitSessionView->mState = CHILD_WAIT_STATE_CLOSE_RESTARTABLE_DONE;
                }
            }
            return;
        case CHILD_WAIT_STATE_ABORT_FINALIZE:
            FinalizeWh();
            gChildWaitSessionView->mEndWaitFrames = 0;
            gChildWaitSessionView->mState = CHILD_WAIT_STATE_ABORT_WAIT;
            return;
        case CHILD_WAIT_STATE_ABORT_WAIT:
            if (gChildWaitSessionView->mEndWaitFrames++ > 0x1e) {
                if (GetWhState() == WH_STATE_IDLE) {
                    EndWh();
                    gChildWaitSessionView->mState = CHILD_WAIT_STATE_ABORT_DONE;
                    return;
                } else {
                    u32 stateFrames = gChildWaitSessionView->mEndWaitFrames;

                    if (stateFrames % 0x1e == 1 && stateFrames > 0x37) {
                        FinalizeWh();
                    }
                }
            }
            return;
        case CHILD_WAIT_STATE_STOP_FINALIZE:
            FinalizeWh();
            gChildWaitSessionView->mEndWaitFrames = 0;
            gChildWaitSessionView->mState = CHILD_WAIT_STATE_STOP_WAIT;
            return;
        case CHILD_WAIT_STATE_STOP_WAIT:
            if (gChildWaitSessionView->mEndWaitFrames++ > 0x1e) {
                if (GetWhState() == WH_STATE_IDLE) {
                    EndWh();
                    gChildWaitSessionView->mState = CHILD_WAIT_STATE_ENDED;
                }
            }
            return;
        case CHILD_WAIT_STATE_FINALIZE_ONLY:
            FinalizeWh();
            return;
        case CHILD_WAIT_STATE_ENDED:
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
        case WH_STATE_IDLE:
            StartWhChannelSearch();
            return;
        case WH_STATE_MEASURE_CHANNEL:
            gChildWaitSessionView->mChannel = DecideWhChannel();
            gChildWaitSessionView->mMultiBootInitFrames = 0;
            gChildWaitSessionView->mState = CHILD_WAIT_STATE_MULTIBOOT_START;
            return;
        case WH_STATE_STOP:
            gChildWaitSessionView->mMultiBootInitFrames = 0;
            gChildWaitSessionView->mState = CHILD_WAIT_STATE_MULTIBOOT_START;
            return;
        case WH_STATE_ERROR:
            StartWhResetOrFail();
            return;
        case WH_STATE_BUSY:
            break;
        default:
            Os_Terminate();
            break;
    }
}

void InitChildWaitMultiBoot(void) {
    InitMultiBootParentComm(gChildWaitSessionView->mGameRegistry.mGgid, gChildWaitSessionView->mTgid);
}

void AdvanceChildWaitMultiBoot(void) {
    switch (GetMultiBootParentState()) {
        case MULTIBOOT_PARENT_STATE_READY:
            StartMultiBootParentFromIdle(&gChildWaitSessionView->mGameRegistry, gChildWaitSessionView->mChannel);
            return;
        case MULTIBOOT_PARENT_STATE_ACCEPTING_CHILDREN:
            if (GetMultiBootChildMask(MULTIBOOT_CHILD_MASK_DOWNLOAD_PENDING) != 0) {
                gChildWaitSessionView->mState = CHILD_WAIT_STATE_CHILD_JOINED;
                return;
            }
            if (GetMultiBootChildMask(MULTIBOOT_CHILD_MASK_DOWNLOAD_STARTED) != 0 ||
                GetMultiBootChildMask(MULTIBOOT_CHILD_MASK_SEND_COMPLETE) != 0) {
                gChildWaitSessionView->mState = CHILD_WAIT_STATE_DOWNLOADING;
                return;
            }
            if (gChildWaitSessionView->mState == CHILD_WAIT_STATE_CHILD_JOINED) {
                if (GetMultiBootChildMask(MULTIBOOT_CHILD_MASK_DOWNLOAD_PENDING) == 0) {
                    gChildWaitSessionView->mState = CHILD_WAIT_STATE_CHILD_LEFT;
                    return;
                }
            }
            break;
        case MULTIBOOT_PARENT_STATE_DOWNLOADING:
            if (AreMultiBootChildrenBootable() != 0) {
                StartMultiBootBootRequests();
                return;
            }
            if ((u8) (gChildWaitSessionView->mState + (256 - CHILD_WAIT_STATE_DOWNLOADING)) <= 1) {
                if (GetMultiBootChildMask(MULTIBOOT_CHILD_MASK_DOWNLOAD_STARTED) == 0) {
                    gChildWaitSessionView->mState = CHILD_WAIT_STATE_CHILD_LOST;
                    return;
                }
            }
            break;
        case MULTIBOOT_PARENT_STATE_BOOTED:
            gChildWaitSessionView->mState = CHILD_WAIT_STATE_DATA_CONNECT;
            return;
        case MULTIBOOT_PARENT_STATE_FAILED:
            StartMultiBootEndToIdle();
            gChildWaitSessionView->mState = CHILD_WAIT_STATE_IDLE;
            return;
        case MULTIBOOT_PARENT_STATE_ENDED:
            switch (GetWhState()) {
                case WH_STATE_IDLE:
                    EndWh();
                    return;
                case WH_STATE_STOP:
                    gChildWaitSessionView->mState = CHILD_WAIT_STATE_ERROR;
                    return;
                case WH_STATE_BUSY:
                    break;
                default:
                    gChildWaitSessionView->mState = CHILD_WAIT_STATE_ERROR;
                    break;
            }
            break;
    }
}

void StartChildWaitDataConnect(void) {
    ClearChildWaitSharedEntries();
    SetWhConnectCallback(AcceptMatchingWhChild);
    gChildWaitSessionView->mState = CHILD_WAIT_STATE_DATA_SHARING;
}

void AdvanceChildWaitDataSharing(void) {
    u16 blockNumber;
    s32 blockIndex;

    switch (GetWhState()) {
        case WH_STATE_IDLE:
            StartWhParentConnect(WIRELESS_CONNECT_MODE_DATA_SHARING, gChildWaitSessionView->mTgid + 1,
                                 gChildWaitSessionView->mChannel);
            break;
        case WH_STATE_CONNECTED:
        case WH_STATE_DATA_SHARING:
        case WH_STATE_KEY_SHARING:
            blockNumber = gChildWaitSessionView->mBlockNumber;
            blockIndex = blockNumber % 16;
            ExchangeChildWaitSharedEntries(CHILD_WAIT_CODE_NONE, blockNumber,
                                           gChildWaitSessionView->mUnk_aa0[1] + (blockIndex << 6));
            ReadChildWaitReply();
            if (gChildWaitSessionView->mState != CHILD_WAIT_STATE_ABORT_FINALIZE) {
                if (gChildWaitSessionView->mStallCount > CHILD_WAIT_STALL_ABORT_LIMIT) {
                    gChildWaitSessionView->mState = CHILD_WAIT_STATE_ABORT_FINALIZE;
                    return;
                }
                if (GetChildWaitReplyCode() == CHILD_WAIT_CODE_BLOCK_ACK ||
                    GetChildWaitReplyCode() == CHILD_WAIT_CODE_BLOCK_ACK_END) {
                    GetChildWaitReplyCode();
                    gChildWaitSessionView->mState = CHILD_WAIT_STATE_SHARING_BLOCK_ACKED;
                } else if (GetChildWaitReplyCode() == CHILD_WAIT_CODE_FINAL_REPLY) {
                    gChildWaitSessionView->mState = CHILD_WAIT_STATE_FINAL_REPLY;
                } else if (GetChildWaitReplyCode() == 0xff) {
                    gChildWaitSessionView->mState = CHILD_WAIT_STATE_ABORT_FINALIZE;
                } else if (GetChildWaitReplyCode() == CHILD_WAIT_CODE_CLOSE_NO_RESTART) {
                    gChildWaitSessionView->mState = CHILD_WAIT_STATE_CLOSE_NO_RESTART_FINALIZE;
                } else if (GetChildWaitReplyCode() == CHILD_WAIT_CODE_CLOSE_RESTARTABLE) {
                    gChildWaitSessionView->mState = CHILD_WAIT_STATE_CLOSE_RESTARTABLE_FINALIZE;
                } else if (GetChildWaitReplyCode() == 0x70) {
                    gChildWaitSessionView->mState = CHILD_WAIT_STATE_ABORT_FINALIZE;
                } else if (GetChildWaitReplyCode() == CHILD_WAIT_CODE_NONE) {
                    gChildWaitSessionView->mState = CHILD_WAIT_STATE_DATA_SHARING;
                } else if (GetChildWaitReplyCode() == CHILD_WAIT_CODE_HANDSHAKE_ACK) {
                    gChildWaitSessionView->mState = CHILD_WAIT_STATE_SHARING_HANDSHAKE_ACKED;
                } else {
                    gChildWaitSessionView->mState = CHILD_WAIT_STATE_ERROR;
                }
            }
            break;
    }
}

void AdvanceChildWaitAfterReply(void) {
    gChildWaitSessionView->mState = CHILD_WAIT_STATE_FINAL_REPLY_DONE;
}

BOOL EndChildWaitWh(void) {
    int whState;
    whState = GetWhState();
    if (whState == WH_STATE_IDLE) {
        EndWh();
        gChildWaitSessionView->mState = CHILD_WAIT_STATE_IDLE;
        return 1;
    }
    return 0;
}

u32 AcceptMatchingWhChild(WirelessMessage *event) {
    u16 aid = GetRecordValueByMacAddress(event->mMacAddress);
    if (aid == 0) {
        return 0;
    }
    gChildWaitSessionView->mUnk_aa0[aid - 1] = GetMultiBootChildRecord(aid);
    return 1;
}

void ClearChildWaitSharedEntries(void) {
    Mem_CpuFill8(gChildWaitSessionView->mSharedEntries, 0, 0x100);
    Mem_CpuFill8(gChildWaitSessionView, 0, 0x100);
    gChildWaitSessionView->mSendEntry = &gChildWaitSessionView->mSendEntryStorage;
}

void ExchangeChildWaitSharedEntries(u16 code, u16 value, u8 *payload) {
    u16 aid;

    if (gChildWaitSessionView->mHandshakeDone == CHILD_WAIT_STATE_IDLE) {
        gChildWaitSessionView->mSendEntry->mCode = code;
        gChildWaitSessionView->mSendEntry->mValue = value;
        Mem_CpuCopy8(payload, gChildWaitSessionView->mSendEntry->mPayload,
                    sizeof(gChildWaitSessionView->mSendEntry->mPayload));
    } else {
        gChildWaitSessionView->mStallCount = gChildWaitSessionView->mStallCount + 1;
        gChildWaitSessionView->mSendEntry->mCode = CHILD_WAIT_CODE_HANDSHAKE_REQUEST;
        gChildWaitSessionView->mSendEntry->mPayload[0] = gChildWaitSessionView->mHandshakeByte;
    }
    if (GetWhState() == WH_STATE_DATA_SHARING) {
        if (StepWhDataSharing(gChildWaitSessionView) == FALSE) {
            gChildWaitSessionView->mStallCount = gChildWaitSessionView->mStallCount + 4;
            return;
        }
        if (gChildWaitSessionView->mHandshakeDone == 0) {
            gChildWaitSessionView->mStallCount = gChildWaitSessionView->mStallCount + 1;
        } else {
            gChildWaitSessionView->mStallCount = 0;
            if (GetWhConnectedMask() != 3) {
                gChildWaitSessionView->mState = CHILD_WAIT_STATE_ABORT_FINALIZE;
                return;
            }
        }
        for (aid = 0; aid < 2; aid++) {
            u8 *sharedData = GetWhSharedDataAddress(aid);
            if (sharedData != NULL) {
                Mem_CpuCopy8(sharedData, &gChildWaitSessionView->mSharedEntries[aid],
                            sizeof(gChildWaitSessionView->mSharedEntries[aid]));
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
            if (entryIndex == CHILD_WAIT_STATE_IDLE) {
                if (session->mHandshakeDone == CHILD_WAIT_STATE_IDLE) {
                    if (entry->mCode != CHILD_WAIT_CODE_BLOCK_ACK) {
                        return;
                    }
                    session->mReplyCount = session->mReplyCount + 1;
                    if ((gChildWaitSessionView->mReplyCount & 1) == 0) {
                        gChildWaitSessionView->mBlockNumber = gChildWaitSessionView->mBlockNumber + 1;
                        if (gChildWaitSessionView->mBlockNumber >= CHILD_WAIT_BLOCK_COUNT) {
                            gChildWaitSessionView->mBlockNumber = 0;
                        }
                    }
                } else {
                    session->mUnk_202 = CHILD_WAIT_CODE_HANDSHAKE_REQUEST;
                    if (entry->mCode == CHILD_WAIT_CODE_HANDSHAKE_ACK) {
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
