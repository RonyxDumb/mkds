#include "mb_parent.h"
#include "code_0200fc8c.h"
#include "code_020091fc.h"
#include "code_0214d018.h"
#include "code_02008908.h"
#include "code_0200c0d8.h"
#include "mb_data.h"
#include "code_02007ec4.h"
#include "code_0214cfe4.h"
#include "code_02009928.h"

u8 prev_fid = 0xff;

#pragma thumb on

void MB_CommSetParentStateCallback(UnkFunc *p0) {
    u32 enabled = (OS_DisableInterrupts());
    u32 v7;
    mbc->mCallback = p0;
    v7 = (OS_RestoreInterrupts(enabled));
}

#pragma thumb off

#pragma thumb on

void *MB_CommGetChildUser(u32 child) {
    u32 savedInterrupts;
    savedInterrupts = OS_DisableInterrupts();
    if (mbc != NULL && IsChildAidValid(child) != 0) {
        MI_CpuCopy8(&mbc->mChildUser[child - 1], mbc->mChildUserBuf, 0x16);
        OS_RestoreInterrupts(savedInterrupts);
        return mbc->mChildUserBuf;
    }
    OS_RestoreInterrupts(savedInterrupts);
    return NULL;
}

u32 MB_CommIsBootable(u32 child) {
    if (mbc != NULL && IsChildAidValid(child) != 0 && mbc->mPCommState[child - 1] == 7) {
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
        case 0:
            expectedValue = 0xa;
            newValue = 4;
            break;
        case 1:
            expectedValue = 0xa;
            newValue = 3;
            break;
        case 2:
            expectedValue = 0xe;
            newValue = 2;
            break;
        case 3:
            expectedValue = 7;
            newValue = 5;
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
        case 0x15:
            MBi_CommChangeParentState(0, 1, eventData);
            break;
        case 0:
            aid = eventData->mLength;
            if (aid != 0 && aid < 16) {
                MBi_CommChangeParentState(aid, 2, eventData);
            }
            break;
        case 1:
            aid = eventData->mLength;
            if (aid != 0 && aid < 16) {
                mbc->mChildversion[eventData->mLength - 1] = 0;
                MI_CpuFill8(mbc->mChildggid + (eventData->mLength - 1), 0, 4);
                MI_CpuFill8(&mbc->mChildUser[eventData->mLength - 1], 0, 0x16);
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
                if (mbc->mPCommState[aid - 1] == 8) {
                    MBi_CommChangeParentState(aid, 9, NULL);
                }
                MBi_CommChangeParentState(eventData->mLength, 3, eventData);
                mbc->mPCommState[eventData->mLength - 1] = 0;
            }
            break;
        case 0x11:
            break;
        case 3:
            MBi_CommParentRecvData((WMMpRecvHeader *) eventData);
            break;
        case 0x19:
            MBi_CommParentSendData();
            break;
        case 0x1c:
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
        case 0xff:
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
        case 0x100:
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
    if (eventCode == 0x11) {
        callback = mbc->mCallback;
        MemFillWordsByBlock_inline(mbc, 0x7d00);
        mbc = NULL;
        if (callback != NULL) {
            callback(0, 0xc, NULL);
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
            if (childValue == 2) {
                if (payload == NULL) {
                    return;
                }
                MI_CpuCopy8(payload, &payloadCopy, 0x1d);
                index = child - 1;
                mbc->mChildggid[arrayIndex] = payloadCopy.mGgid;
                mbc->mChildversion[index] = payloadCopy.mVersion;
                index *= 0x16;
                MI_CpuCopy8(payloadCopy.mUserInfo, OFFSET_PTR(MBUserInfo, mbc->mChildUser, index), 0x16);
                OFFSET_PTR(MBUserInfo, mbc->mChildUser, index)->mPlayerNo = child;
                MBi_CommChangeParentState(child, 0xa, payloadCopy.mUserInfo);
            }
            if (childValue == 10) {
                bitCount = 0;
                entryIndex = ((MBCommRequestData *) payload)->mFileId;
                if (entryIndex >= 16 || (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mEntryUsed == 0 ||
                    mbc->mChildggid[arrayIndex] !=
                        (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mGameReg->mGgid) {
                    mbc->mReq2child[arrayIndex] = 4;
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
                        mbc->mReq2child[arrayIndex] = 0;
                        MBi_CommChangeParentState(child, 0xb, NULL);
                        return;
                    }
                }
                switch (mbc->mReq2child[arrayIndex]) {
                    case 3:
                        if ((mbc->mChildEntryBmp & (1U << child)) != 0) {
                            return;
                        }
                        mbc->mChildNum++;
                        mbc->mChildEntryBmp |= 1 << child;
                        mbc->mChildEntryIndex[child - 1] = entryIndex;
                        (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mGameinfoChildBmp |= 1 << child;
                        (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mGameinfoChangedBmp |= 1 << child;
                        mbc->mReq2child[arrayIndex] = 0;
                        MBi_CommChangeParentState(child, 5, NULL);
                        break;
                    case 4:
                        (OFFSET_PTR(MB_CommPWork, mbc, arrayIndex * 2))->mReq2child[0] = 0;
                        MBi_CommChangeParentState(child, 4, NULL);
                        break;
                }
            }
            break;
        case CHILD_MESSAGE_ACCEPT_ACK:
            if (childValue == 5) {
                MBi_CommChangeParentState(child, 0xe, NULL);
            } else if (childValue == 0xe) {
                if (mbc->mReq2child[arrayIndex] == 2) {
                    entryIndex = mbc->mChildEntryIndex[arrayIndex];
                    (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mPollbmp |= 1 << child;
                    (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mCurrentb = 0;
                    mbc->mReq2child[arrayIndex] = 0;
                    MBi_CommChangeParentState(child, 6, NULL);
                }
            }
            break;
        case CHILD_MESSAGE_ACK_WITH_DATA:
            if (childValue == 6) {
                entryIndex = mbc->mChildEntryIndex[arrayIndex];
                if (entryIndex != 0xff) {
                    (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mNextb = MBi_calc_nextsendblock(
                        (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mNextb, message.mPieceRequest);
                }
            }
            break;
        case CHILD_MESSAGE_START_ACK:
            if (childValue == 6) {
                entryIndex = mbc->mChildEntryIndex[arrayIndex];
                if (entryIndex != 0xff) {
                    (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mPollbmp &= ~(1 << child);
                    MBi_CommChangeParentState(child, 7, NULL);
                }
            } else if (childValue == 7) {
                if (mbc->mReq2child[arrayIndex] == 5) {
                    (OFFSET_PTR(MB_CommPWork, mbc, arrayIndex * 2))->mReq2child[0] = 0;
                    MBi_CommChangeParentState(child, 8, NULL);
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
    u8 message[8];
    message[0] = messageKind;
    MBi_MakeParentSendBuffer(message, (u8 *) mbc);
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
        if (work->mPCommState[aid - 1] == 5) {
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
        if (work->mPCommState[aid - 1] == 5 && candidateFile == work->mChildEntryIndex[aid - 1]) {
            childMask |= 1 << aid;
        }
    }
    message.mKind = PARENT_MESSAGE_WELCOMED;
    message.mFid = candidateFile;
    sendBlock = MBi_MakeParentSendBuffer((u8 *) &message, (u8 *) work);
    if (sendBlock != NULL) {
        MI_CpuCopy8(mbc->mFileInfo + candidateFile * 0x5d4, sendBlock, 0xe4);
    }
    return MBi_BlockHeaderEnd(0xea, childMask, *(u32 *) &mbc);
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
            range->mState = 2;
        }
        FS_CloseFile(&file);
    }
    if (range->mState != 2) {
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
    sendBlock = MBi_MakeParentSendBuffer((u8 *) &message, (u8 *) work);
    segmentNum = blockInfo.mSegmentNo;
    work = mbc;
    readOffset = blockInfo.mOffset -
               ((u32 *) (OFFSET_PTR(MB_CommPWork, work, work->mCurFileid * 0x5d4))->mBlockInfoTable)[segmentNum] +
               (OFFSET_PTR(MB_CommPWork, work, work->mCurFileid * 0x5d4))->mCardMapping[segmentNum];
    childEntry = OFFSET_PTR(MB_CommPWork, work, work->mCurFileid * 0x5d4);
    rangeTable = childEntry->mCacheList;
    if (MBi_ReadFromCache(rangeTable, readOffset, sendBlock, blockInfo.mSize) == 0) {
        loadJob = (DataRangeLoadJob *) mbc->mCurTask;
        if (MBi_IsTaskBusy(&loadJob->mTask) == 0) {
            if (rangeTable->mLifetime != 0) {
                range = rangeTable->mList;
                lowestRange = NULL;
                for (rangeIndex = 0; rangeIndex < 4; range++, rangeIndex++) {
                    if (range->mState == 2) {
                        if (lowestRange == NULL || lowestRange->mSrc > range->mSrc) {
                            lowestRange = range;
                        }
                    }
                }
                if (lowestRange == NULL) {
                    OS_Terminate();
                }
                rangeTable->mLifetime = 0;
                lowestRange->mState = 1;
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
            case 2:
                childMasks[1] |= 1 << childNo;
                break;
            case 5:
                childMasks[2] |= 1 << childNo;
                break;
            case 4:
                childMasks[3] |= 1 << childNo;
                break;
            case 8:
                childMasks[4] |= 1 << childNo;
                break;
            case 11:
                childMasks[5] |= 1 << childNo;
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
    enum { K0 } k;
    k = entryIndex * 0x5d4;
    entry = OFFSET_PTR(MB_CommPWork, mbc, k);
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
