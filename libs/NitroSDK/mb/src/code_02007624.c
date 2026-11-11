#include "code_02007624.h"
#include "code_020091fc.h"
#include "code_0214d018.h"

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

void MBi_CommParentCallback(s32 eventCode, Unk021425e8 *eventData) {
    u32 childBit;
    u8 slotIndex;
    MB_CommPWork *work;
    u32 value;
    u16 child;
    u8 entryIndex;
    s32 childEntryIndex;
    void (*callback)(u32, u32, void *);
    childBit = 0;
    switch (eventCode) {
        case 0x15:
            MBi_CommChangeParentState(0, 1, eventData);
            break;
        case 0:
            child = eventData->mUnk_10;
            if (child != 0 && child < 16) {
                MBi_CommChangeParentState(child, 2, eventData);
            }
            break;
        case 1:
            child = eventData->mUnk_10;
            if (child != 0 && child < 16) {
                mbc->mChildversion[eventData->mUnk_10 - 1] = 0;
                MI_CpuFill8(mbc->mChildggid + (eventData->mUnk_10 - 1), 0, 4);
                MI_CpuFill8(&mbc->mChildUser[eventData->mUnk_10 - 1], 0, 0x16);
                MBi_ClearParentPieceBuffer(eventData->mUnk_10);
                value = 0;
                mbc->mReq2child[eventData->mUnk_10 - 1] = value;
                child = eventData->mUnk_10;
                childEntryIndex = mbc->mChildEntryIndex[(s32) child - 1];
                value = ~value;
                if (childEntryIndex != value) {
                    childBit = 1 << child;
                    entryIndex = childEntryIndex;
                    (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mGameinfoChildBmp &= ~childBit;
                    (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mGameinfoChangedBmp |= childBit;
                    mbc->mChildEntryIndex[child - 1] = value;
                    (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mPollbmp &= ~childBit;
                }
                if ((mbc->mChildEntryBmp & (1 << eventData->mUnk_10)) != 0) {
                    mbc->mChildNum--;
                    mbc->mChildEntryBmp &= ~(1 << eventData->mUnk_10);
                }
                child = eventData->mUnk_10;
                if (mbc->mPCommState[child - 1] == 8) {
                    MBi_CommChangeParentState(child, 9, NULL);
                }
                MBi_CommChangeParentState(eventData->mUnk_10, 3, eventData);
                mbc->mPCommState[eventData->mUnk_10 - 1] = 0;
            }
            break;
        case 0x11:
            break;
        case 3:
            MBi_CommParentRecvData((Unk021432ac *) eventData);
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
                    MB_UpdateGameInfoMember((GameInfoEntry *) (work->mUnk_1788 + 0xe4 + value), work->mChildUser,
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
                case 1:
                case 4:
                case 5:
                case 6:
                case 8:
                case 9:
                    MBi_CommCallParentError(0, 9);
                    break;
                case 15:
                default:
                    MBi_CommCallParentError(0, 8);
                    break;
            }
            break;
        case 0x100:
            switch (eventData->mCommand) {
                case 0:
                case 7:
                case 8:
                case 13:
                case 14:
                case 15:
                case 17:
                case 18:
                case 21:
                case 25:
                case 29:
                    MBi_CommCallParentError(0, 9);
                    break;
                case 22:
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
    Unk0200c12c payloadCopy;
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
        case 7:
            if (childValue == 2) {
                if (payload == NULL) {
                    return;
                }
                MI_CpuCopy8(payload, &payloadCopy, 0x1d);
                index = child - 1;
                mbc->mChildggid[arrayIndex] = payloadCopy.mUnk_00;
                mbc->mChildversion[index] = payloadCopy.mUnk_1a;
                index *= 0x16;
                MI_CpuCopy8(payloadCopy.mUnk_04, OFFSET_PTR(MBUserInfo, mbc->mChildUser, index), 0x16);
                OFFSET_PTR(MBUserInfo, mbc->mChildUser, index)->mPlayerNo = child;
                MBi_CommChangeParentState(child, 0xa, payloadCopy.mUnk_04);
            }
            if (childValue == 10) {
                bitCount = 0;
                entryIndex = ((Unk0200c12c *) payload)->mUnk_1c;
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
        case 8:
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
        case 9:
            if (childValue == 6) {
                entryIndex = mbc->mChildEntryIndex[arrayIndex];
                if (entryIndex != 0xff) {
                    (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mNextb = MBi_calc_nextsendblock(
                        (OFFSET_PTR(MB_CommPWork, mbc, entryIndex * 0x5d4))->mNextb, message.mUnk_02);
                }
            }
            break;
        case 10:
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
        case 11:
            break;
    }
}

void MBi_CommParentRecvData(Unk021432ac *header) {
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
