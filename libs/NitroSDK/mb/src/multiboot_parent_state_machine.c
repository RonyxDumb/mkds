#include "multiboot_parent_state_machine.h"
#include "reset_interrupt_enable.h"
#include "multiboot_game_entry.h"
#include "cpu_copy_fill.h"
#include "multiboot_block_header_end.h"
#include "multiboot_data_pieces.h"
#include "mb_data.h"
#include "multiboot_file_register.h"
#include "cpu_copy_clear_16.h"
#include "multiboot_comm_start.h"

u8 prev_fid = 0xff;

#pragma thumb on

void MB_CommSetParentStateCallback(MBParentStateCallback parentStateCallback) {
    u32 enabled = (OS_DisableInterrupts());
    u32 previousState;
    mbc->mCallback = parentStateCallback;
    previousState = (OS_RestoreInterrupts(enabled));
}

#pragma thumb off

#pragma thumb on

void *MB_CommGetChildUser(u32 child) {
    u32 savedInterrupts;
    savedInterrupts = OS_DisableInterrupts();
    if (mbc != NULL && IsChildAidValid(child) != 0) {
        MI_CpuCopy8(&mbc->mChildUser[child - 1], mbc->mChildUserBuf, sizeof(MBUserInfo));
        OS_RestoreInterrupts(savedInterrupts);
        return mbc->mChildUserBuf;
    }
    OS_RestoreInterrupts(savedInterrupts);
    return NULL;
}

u32 MB_CommIsBootable(u32 child) {
    if (mbc != NULL && IsChildAidValid(child) != 0 && mbc->mPCommState[child - 1] == MULTIBOOT_PARENT_DOWNLOAD_DONE) {
        return 1;
    }
    return 0;
}

u32 MB_CommResponseRequest(u32 child, u32 pairIndex) {
    u32 savedInterrupts;
    u32 newValue;
    u32 expectedValue;
    savedInterrupts = OS_DisableInterrupts();
    switch (pairIndex) {
        case MULTIBOOT_RESPONSE_REFUSE:
            expectedValue = MULTIBOOT_PARENT_CHILD_REQUESTED;
            newValue = MULTIBOOT_CHILD_REQUEST_REFUSE;
            break;
        case MULTIBOOT_RESPONSE_ACCEPT:
            expectedValue = MULTIBOOT_PARENT_CHILD_REQUESTED;
            newValue = MULTIBOOT_CHILD_REQUEST_ACCEPT;
            break;
        case MULTIBOOT_RESPONSE_SEND:
            expectedValue = MULTIBOOT_PARENT_CHILD_WAITING;
            newValue = MULTIBOOT_CHILD_REQUEST_DOWNLOAD;
            break;
        case MULTIBOOT_RESPONSE_BOOT:
            expectedValue = MULTIBOOT_PARENT_DOWNLOAD_DONE;
            newValue = MULTIBOOT_CHILD_REQUEST_BOOT;
            break;
        default:
            OS_RestoreInterrupts(savedInterrupts);
            return 0;
    }
    if (mbc != NULL && IsChildAidValid(child) != 0 && expectedValue == mbc->mPCommState[child - 1]) {
        mbc->mReq2child[child - 1] = newValue;
        OS_RestoreInterrupts(savedInterrupts);
        return 1;
    }
    OS_RestoreInterrupts(savedInterrupts);
    return 0;
}

void MBi_CommChangeParentState(u32 child, u32 value, void *data) {
    if (IsChildAidValid(child) != 0) {
        mbc->mPCommState[child - 1] = value;
    }
    MBi_CommChangeParentStateCallbackOnly(child, value, data);
}

void MBi_CommChangeParentStateCallbackOnly(u32 child, u32 value, void *data) {
    MB_CommPWork *work;
    work = mbc;
    if (work->mCallback != NULL) {
        work->mCallback(child, value, data);
    }
}

void MBi_CommParentCallback(s32 eventCode, WirelessMessage *eventData) {
    u32 childBit;
    u8 slotIndex;
    MB_CommPWork *work;
    u32 value;
    u16 aid;
    u8 entryIndex;
    s32 childEntryIndex;
    void (*callback)(u32, u32, void *);
    childBit = 0;
    switch (eventCode) {
        case MULTIBOOT_PARENT_EVENT_PARENT_STARTED:
            MBi_CommChangeParentState(0, MULTIBOOT_PARENT_STARTED, eventData);
            break;
        case MULTIBOOT_PARENT_EVENT_CHILD_CONNECTED:
            aid = eventData->mLength;
            if (aid != 0 && aid < 16) {
                MBi_CommChangeParentState(aid, MULTIBOOT_PARENT_CHILD_CONNECTED, eventData);
            }
            break;
        case MULTIBOOT_PARENT_EVENT_CHILD_DISCONNECTED:
            aid = eventData->mLength;
            if (aid != 0 && aid < 16) {
                mbc->mChildversion[eventData->mLength - 1] = 0;
                MI_CpuFill8(mbc->mChildggid + (eventData->mLength - 1), 0, 4);
                MI_CpuFill8(&mbc->mChildUser[eventData->mLength - 1], 0, sizeof(MBUserInfo));
                MBi_ClearParentPieceBuffer(eventData->mLength);
                value = 0;
                mbc->mReq2child[eventData->mLength - 1] = value;
                aid = eventData->mLength;
                childEntryIndex = mbc->mChildEntryIndex[(s32) aid - 1];
                value = ~value;
                if (childEntryIndex != value) {
                    childBit = 1 << aid;
                    entryIndex = childEntryIndex;
                    (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mGameinfoChildBmp &= ~childBit;
                    (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mGameinfoChangedBmp |= childBit;
                    mbc->mChildEntryIndex[aid - 1] = value;
                    (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mPollbmp &= ~childBit;
                }
                if ((mbc->mChildEntryBmp & (1 << eventData->mLength)) != 0) {
                    mbc->mChildNum--;
                    mbc->mChildEntryBmp &= ~(1 << eventData->mLength);
                }
                aid = eventData->mLength;
                if (mbc->mPCommState[aid - 1] == MULTIBOOT_PARENT_BOOT_ACKED) {
                    MBi_CommChangeParentState(aid, MULTIBOOT_PARENT_CHILD_BOOTED, NULL);
                }
                MBi_CommChangeParentState(eventData->mLength, MULTIBOOT_PARENT_CHILD_DISCONNECTED, eventData);
                mbc->mPCommState[eventData->mLength - 1] = 0;
            }
            break;
        case MULTIBOOT_PARENT_EVENT_ENDED:
            break;
        case MULTIBOOT_PARENT_EVENT_MP_DATA_RECEIVED:
            MBi_CommParentRecvData((WMMpRecvHeader *) eventData);
            break;
        case MULTIBOOT_PARENT_EVENT_MP_SEND_READY:
            MBi_CommParentSendData();
            break;
        case MULTIBOOT_PARENT_EVENT_BEACON_DUE:
            slotIndex = 0;
            childBit = 0;
            do {
                work = mbc;
                value = slotIndex * 0x5d4;
                if ((OFFSET_PTR(MB_CommPWork, work, value))->mEntryUsed != 0 &&
                    (OFFSET_PTR(MB_CommPWork, work, value))->mGameinfoChangedBmp != 0) {
                    MB_UpdateGameInfoMember((GameInfoEntry *) (work->mFileInfo + 0xe4 + value), work->mChildUser,
                                            (OFFSET_PTR(MB_CommPWork, work, value))->mGameinfoChildBmp,
                                            (OFFSET_PTR(MB_CommPWork, work, value))->mGameinfoChangedBmp);
                    (OFFSET_PTR(MB_CommPWork, mbc, value))->mGameinfoChangedBmp = childBit;
                }
                slotIndex++;
            } while (slotIndex < 16);
            {
                u32 ggid;
                u16 tgid;
                ggid = MBi_GetGgid();
                tgid = MBi_GetTgid();
                MB_SendGameInfoBeacon(ggid, tgid, MBi_GetAttribute());
            }
            break;
        case MULTIBOOT_PARENT_EVENT_ERROR:
            switch (eventData->mResultCode) {
                case WIRELESS_RESULT_REFUSED:
                case WIRELESS_RESULT_SWITCHED_OFF:
                case WIRELESS_RESULT_NOT_SET_UP:
                case WIRELESS_RESULT_BAD_INPUT:
                case WIRELESS_RESULT_PIPE_ERROR:
                case WIRELESS_RESULT_NO_ANSWER:
                    MBi_CommCallParentError(0, 9);
                    break;
                case WIRELESS_RESULT_TRANSMIT_ERROR:
                default:
                    MBi_CommCallParentError(0, 8);
                    break;
            }
            break;
        case MULTIBOOT_PARENT_EVENT_REQUEST_FAILED:
            switch (eventData->mCommand) {
                case WIRELESS_REQUEST_POWER_UP_STACK:
                case WIRELESS_REQUEST_CONFIGURE_HOST:
                case WIRELESS_REQUEST_OPEN_HOST:
                case WIRELESS_REQUEST_LEAVE:
                case WIRELESS_REQUEST_BEGIN_EXCHANGE:
                case WIRELESS_REQUEST_QUEUE_EXCHANGE_DATA:
                case WIRELESS_REQUEST_BEGIN_FRAME_MODE:
                case WIRELESS_REQUEST_QUEUE_FRAME_DATA:
                case WIRELESS_REQUEST_BEGIN_KEY_SHARE:
                case WIRELESS_REQUEST_WATCH_BEACONS:
                case WIRELESS_REQUEST_SET_TIMEOUT:
                    MBi_CommCallParentError(0, 9);
                    break;
                case WIRELESS_REQUEST_STOP_KEY_SHARE:
                default:
                    MBi_CommCallParentError(0, 8);
                    break;
            }
            break;
    }
    if (eventCode == MULTIBOOT_PARENT_EVENT_ENDED) {
        callback = mbc->mCallback;
        MemFillWordsByBlock_inline(mbc, 0x7d00);
        mbc = NULL;
        if (callback != NULL) {
            callback(0, MULTIBOOT_PARENT_ENDED, NULL);
        }
    }
}

void MBi_CommParentRecvDataPerChild(WMMpRecvData *childData, u32 child) {
    ChildMessage message;
    MBCommRequestData payloadCopy;
    u8 *payload;
    u32 arrayIndex;
    u32 childValue;
    u8 bitIndex;
    u8 bitCount;
    u8 entryIndex;
    u32 index;
    if (child == 0 || child > 15) {
        return;
    }
    payload = MBi_SetRecvBufferFromChild(childData->mPayload, &message, child);
    arrayIndex = child - 1;
    childValue = mbc->mPCommState[arrayIndex];
    switch (message.mKind) {
        case CHILD_MESSAGE_REQUEST:
            if (childValue == MULTIBOOT_PARENT_CHILD_CONNECTED) {
                if (payload == NULL) {
                    return;
                }
                MI_CpuCopy8(payload, &payloadCopy, 0x1d);
                index = child - 1;
                mbc->mChildggid[arrayIndex] = payloadCopy.mGgid;
                mbc->mChildversion[index] = payloadCopy.mVersion;
                index *= sizeof(MBUserInfo);
                MI_CpuCopy8(payloadCopy.mUserInfo, OFFSET_PTR(MBUserInfo, mbc->mChildUser, index), sizeof(MBUserInfo));
                OFFSET_PTR(MBUserInfo, mbc->mChildUser, index)->mPlayerNo = child;
                MBi_CommChangeParentState(child, MULTIBOOT_PARENT_CHILD_REQUESTED, payloadCopy.mUserInfo);
            }
            if (childValue == MULTIBOOT_PARENT_CHILD_REQUESTED) {
                bitCount = 0;
                entryIndex = ((MBCommRequestData *) payload)->mFileId;
                if (entryIndex >= 16 || (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mEntryUsed == 0 ||
                    mbc->mChildggid[arrayIndex] !=
                        (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mGameReg->mGgid) {
                    mbc->mReq2child[arrayIndex] = MULTIBOOT_CHILD_REQUEST_REFUSE;
                } else {
                    bitIndex = 0;
                    do {
                        if (((1 << bitIndex) &
                             (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mGameinfoChildBmp) != 0) {
                            bitCount++;
                        }
                        bitIndex++;
                    } while (bitIndex < 16);
                    if (bitCount >= (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mGameReg->mMaxPlayerNum) {
                        mbc->mReq2child[arrayIndex] = MULTIBOOT_CHILD_REQUEST_NONE;
                        MBi_CommChangeParentState(child, MULTIBOOT_PARENT_ENTRY_FULL, NULL);
                        return;
                    }
                }
                switch (mbc->mReq2child[arrayIndex]) {
                    case MULTIBOOT_CHILD_REQUEST_ACCEPT:
                        if ((mbc->mChildEntryBmp & (1U << child)) != 0) {
                            return;
                        }
                        mbc->mChildNum++;
                        BIT_SET(mbc->mChildEntryBmp, child);
                        mbc->mChildEntryIndex[child - 1] = entryIndex;
                        (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mGameinfoChildBmp |= 1 << child;
                        (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mGameinfoChangedBmp |= 1 << child;
                        mbc->mReq2child[arrayIndex] = MULTIBOOT_CHILD_REQUEST_NONE;
                        MBi_CommChangeParentState(child, MULTIBOOT_PARENT_CHILD_ENTERED, NULL);
                        break;
                    case MULTIBOOT_CHILD_REQUEST_REFUSE:
                        (OFFSET_PTR(MB_CommPWork, mbc, arrayIndex * 2))->mReq2child[0] = MULTIBOOT_CHILD_REQUEST_NONE;
                        MBi_CommChangeParentState(child, MULTIBOOT_PARENT_CHILD_REFUSED, NULL);
                        break;
                }
            }
            break;
        case CHILD_MESSAGE_ACCEPT_ACK:
            if (childValue == MULTIBOOT_PARENT_CHILD_ENTERED) {
                MBi_CommChangeParentState(child, MULTIBOOT_PARENT_CHILD_WAITING, NULL);
            } else if (childValue == MULTIBOOT_PARENT_CHILD_WAITING) {
                if (mbc->mReq2child[arrayIndex] == MULTIBOOT_CHILD_REQUEST_DOWNLOAD) {
                    entryIndex = mbc->mChildEntryIndex[arrayIndex];
                    (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mPollbmp |= 1 << child;
                    (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mCurrentb = 0;
                    mbc->mReq2child[arrayIndex] = MULTIBOOT_CHILD_REQUEST_NONE;
                    MBi_CommChangeParentState(child, MULTIBOOT_PARENT_DOWNLOAD_STARTED, NULL);
                }
            }
            break;
        case CHILD_MESSAGE_ACK_WITH_DATA:
            if (childValue == MULTIBOOT_PARENT_DOWNLOAD_STARTED) {
                entryIndex = mbc->mChildEntryIndex[arrayIndex];
                if (entryIndex != 0xff) {
                    (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mNextb = MBi_calc_nextsendblock(
                        (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mNextb, message.mPieceRequest);
                }
            }
            break;
        case CHILD_MESSAGE_START_ACK:
            if (childValue == MULTIBOOT_PARENT_DOWNLOAD_STARTED) {
                entryIndex = mbc->mChildEntryIndex[arrayIndex];
                if (entryIndex != 0xff) {
                    (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mPollbmp &= ~(1 << child);
                    MBi_CommChangeParentState(child, MULTIBOOT_PARENT_DOWNLOAD_DONE, NULL);
                }
            } else if (childValue == MULTIBOOT_PARENT_DOWNLOAD_DONE) {
                if (mbc->mReq2child[arrayIndex] == MULTIBOOT_CHILD_REQUEST_BOOT) {
                    (OFFSET_PTR(MB_CommPWork, mbc, arrayIndex * 2))->mReq2child[0] = MULTIBOOT_CHILD_REQUEST_NONE;
                    MBi_CommChangeParentState(child, MULTIBOOT_PARENT_BOOT_ACKED, NULL);
                }
            }
            break;
        case CHILD_MESSAGE_DONE_ACK:
            break;
    }
}

void MBi_CommParentRecvData(WMMpRecvHeader *header) {
    u16 index;
    u16 firstHalfword;
    void *childData;
    for (index = 0; index < 16; index++) {
        if ((OFFSET_PTR(MB_CommPWork, mbc, index * 0x5d4))->mEntryUsed != 0) {
            (OFFSET_PTR(MB_CommPWork, mbc, index * 0x5d4))->mNextb = 0;
        }
    }
    for (index = 1; index <= 15; index++) {
        childData = WM_ReadMPData(header, index);
        if (childData != NULL) {
            firstHalfword = *(u16 *) childData;
            if (firstHalfword != 0xffff && firstHalfword != 0) {
                MBi_CommParentRecvDataPerChild(childData, index);
            }
        }
    }
}

#pragma thumb off

#pragma thumb on

int MBi_CommParentSendMsg(u8 messageKind, u32 childMask) {
    ParentMessage message;
    message.mKind = messageKind;
    MBi_MakeParentSendBuffer(&message, (u8 *) mbc);
    return MBi_BlockHeaderEnd(6, childMask, (u32) mbc);
}

#pragma thumb off

#pragma thumb on

u32 MBi_CommParentSendDLFileInfo(void) {
    ParentMessage message;
    u8 requestCounts[16];
    u16 aid;
    u32 candidateFile;
    u16 childMask;
    u8 fid;
    MB_CommPWork *work;
    u8 searchCount;
    u8 *sendBlock;
    childMask = 0;
    candidateFile = -1;
    MI_CpuFill8(requestCounts, 0, 16);
    aid = 1;
    work = mbc;
    for (; aid <= 15; aid++) {
        if (work->mPCommState[aid - 1] == MULTIBOOT_PARENT_CHILD_ENTERED) {
            requestCounts[work->mChildEntryIndex[aid - 1]]++;
        }
    }
    fid = prev_fid;
    searchCount = 0;
    do {
        fid = (fid + 1) % 16;
        if ((OFFSET_PTR(MB_CommPWork, work, fid * 0x5d4))->mEntryUsed != 0 && requestCounts[fid] != 0) {
            candidateFile = (s8) fid;
            break;
        }
        searchCount++;
    } while (searchCount < 16);
    if (candidateFile == -1) {
        return 21;
    }
    prev_fid = candidateFile;
    for (aid = 1; aid <= 15; aid++) {
        if (work->mPCommState[aid - 1] == MULTIBOOT_PARENT_CHILD_ENTERED &&
            candidateFile == work->mChildEntryIndex[aid - 1]) {
            BIT_SET(childMask, aid);
        }
    }
    message.mKind = PARENT_MESSAGE_WELCOMED;
    message.mFid = candidateFile;
    sendBlock = MBi_MakeParentSendBuffer(&message, (u8 *) work);
    if (sendBlock != NULL) {
        MI_CpuCopy8(mbc->mFileInfo + candidateFile * 0x5d4, sendBlock, 0xe4);
    }
    return MBi_BlockHeaderEnd(0xea, childMask, (u32) mbc);
}

void MBi_ReloadCache(DataRangeLoadJob *job) {
    MBiCacheInfo *range;
    MBiCacheList *table;
    FSFile file;
    u32 offset;
    range = job->mDataRange;
    table = job->mDataRangeTable;
    FS_InitFile(&file);
    offset = range->mSrc;
    if (FS_OpenFileDirect(&file, FS_FindArchive(table->mArcName, table->mArcNameLen), offset, offset + range->mLen,
                          -1) != 0) {
        if (range->mLen == FS_ReadFile(&file, range->mPtr, range->mLen)) {
            range->mState = MULTIBOOT_CACHE_LOADED;
        }
        FS_CloseFile(&file);
    }
    if (range->mState != MULTIBOOT_CACHE_LOADED) {
        OS_Terminate();
    }
}

#pragma thumb off

#pragma thumb on

u32 MBi_CommParentSendBlock(void) {
    ParentMessage message;
    MB_BlockInfo blockInfo;
    u8 attemptCount;
    u8 segmentNum;
    MB_CommPWork *work;
    MB_CommPWork *childEntry;
    MBiCacheList *rangeTable;
    MBiCacheInfo *lowestRange;
    s32 rangeIndex;
    MBiCacheInfo *range;
    u8 *sendBlock;
    u32 readOffset;
    DataRangeLoadJob *loadJob;
    MB_CommPWork *parentWork;
    MB_CommPWork *parentWorkAgain;
    parentWork = mbc;
    if (parentWork->mEntryCount == 0) {
        return 21;
    }
    attemptCount = 0;
    do {
        work = mbc;
        work->mCurFileid = (work->mCurFileid + 1) % 16;
        parentWorkAgain = (MB_CommPWork *) *(u32 *) &mbc;
        childEntry = OFFSET_PTR(MB_CommPWork, parentWorkAgain, parentWorkAgain->mCurFileid * 0x5d4);
        if (childEntry->mEntryUsed != 0 && childEntry->mPollbmp != 0) {
            break;
        }
        attemptCount++;
    } while (attemptCount < 16);
    if (attemptCount == 16) {
        return 21;
    }
    MBi_calc_sendblock(parentWorkAgain->mCurFileid);
    work = mbc;
    childEntry = OFFSET_PTR(MB_CommPWork, work, work->mCurFileid * 0x5d4);
    if (MBi_get_blockinfo(&blockInfo, work->mBlockInfoTable + work->mCurFileid * 0x5d4, childEntry->mCurrentb,
                          work->mFileInfo + work->mCurFileid * 0x5d4) == FALSE) {
        return 21;
    }
    message.mKind = PARENT_MESSAGE_BEGIN_SEND;
    work = mbc;
    message.mFid = work->mCurFileid;
    message.mSeqno = (OFFSET_PTR(MB_CommPWork, work, work->mCurFileid * 0x5d4))->mCurrentb;
    sendBlock = MBi_MakeParentSendBuffer(&message, (u8 *) work);
    segmentNum = blockInfo.mSegmentNo;
    work = mbc;
    readOffset = blockInfo.mOffset -
               ((u32 *) (OFFSET_PTR(MB_CommPWork, work, work->mCurFileid * 0x5d4))->mBlockInfoTable)[segmentNum] +
               (OFFSET_PTR(MB_CommPWork, work, work->mCurFileid * 0x5d4))->mCardMapping[segmentNum];
    childEntry = OFFSET_PTR(MB_CommPWork, work, work->mCurFileid * 0x5d4);
    rangeTable = childEntry->mCacheList;
    if (MBi_ReadFromCache(rangeTable, readOffset, sendBlock, blockInfo.mSize) == 0) {
        loadJob = &mbc->mCurTask;
        if (MBi_IsTaskBusy(&loadJob->mTask) == 0) {
            if (rangeTable->mLifetime != 0) {
                range = rangeTable->mList;
                lowestRange = NULL;
                for (rangeIndex = 0; rangeIndex < 4; range++, rangeIndex++) {
                    if (range->mState == MULTIBOOT_CACHE_LOADED) {
                        if (lowestRange == NULL || lowestRange->mSrc > range->mSrc) {
                            lowestRange = range;
                        }
                    }
                }
                if (lowestRange == NULL) {
                    OS_Terminate();
                }
                rangeTable->mLifetime = 0;
                lowestRange->mState = MULTIBOOT_CACHE_LOADING;
                lowestRange->mSrc = readOffset & ~0x1f;
                loadJob->mDataRange = lowestRange;
                loadJob->mDataRangeTable = rangeTable;
                MBi_SetTask(&loadJob->mTask, (void *) MBi_ReloadCache, NULL, 4);
            }
        }
        return 21;
    }
    work = mbc;
    return MBi_BlockHeaderEnd(blockInfo.mSize + 6, (OFFSET_PTR(MB_CommPWork, work, work->mCurFileid * 0x5d4))->mPollbmp,
                              (u32) work);
}

int MBi_CommParentSendData(void) {
    u16 childMasks[6];
    u16 childNo;
    int result;
    MB_CommPWork *work;
    childMasks[0] = 0;
    MIi_CpuClear16(childMasks[0], &childMasks[1], 10);
    childNo = 1;
    work = mbc;
    for (; childNo <= 15; childNo++) {
        switch (work->mPCommState[childNo - 1]) {
            case MULTIBOOT_PARENT_CHILD_CONNECTED:
                BIT_SET(childMasks[1], childNo);
                break;
            case MULTIBOOT_PARENT_CHILD_ENTERED:
                BIT_SET(childMasks[2], childNo);
                break;
            case MULTIBOOT_PARENT_CHILD_REFUSED:
                BIT_SET(childMasks[3], childNo);
                break;
            case MULTIBOOT_PARENT_BOOT_ACKED:
                BIT_SET(childMasks[4], childNo);
                break;
            case MULTIBOOT_PARENT_ENTRY_FULL:
                BIT_SET(childMasks[5], childNo);
                break;
        }
    }
    if (childMasks[4] != 0) {
        result = MBi_CommParentSendMsg(5, childMasks[4]);
    } else if (childMasks[1] != 0) {
        result = MBi_CommParentSendMsg(1, childMasks[1]);
    } else if (childMasks[5] != 0) {
        result = MBi_CommParentSendMsg(6, childMasks[5]);
    } else if (childMasks[3] != 0) {
        result = MBi_CommParentSendMsg(2, childMasks[3]);
    } else if (childMasks[2] != 0) {
        result = MBi_CommParentSendDLFileInfo();
    } else {
        result = MBi_CommParentSendBlock();
    }
    if (result == 21) {
        result = MBi_CommParentSendMsg(0, 0xffff);
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void MBi_calc_sendblock(u32 entryIndex) {
    MB_CommPWork *entry;
    u16 current;
    u16 rangeStart;
    enum { ENTRY_OFFSET_FIRST } entryOffset;
    entryOffset = entryIndex * 0x5d4;
    entry = OFFSET_PTR(MB_CommPWork, mbc, entryOffset);
    if (entry->mEntryUsed == 0) {
        return;
    }
    if (entry->mPollbmp == 0) {
        return;
    }
    current = entry->mCurrentb;
    rangeStart = entry->mNextb;
    if (rangeStart <= current && current <= rangeStart + 2) {
        entry->mCurrentb = current + 1;
        return;
    }
    entry->mCurrentb = rangeStart;
}

u32 MBi_calc_nextsendblock(u32 first, u32 second) {
    if (second <= first) {
        second = first;
    }
    return second;
}

#pragma thumb off
