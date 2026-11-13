#include "mb_gameinfo.h"
#include "code_020091fc.h"
#include "code_02003024.h"
#include "code_0214d018.h"
#include "code_02009908.h"
#include "code_0214cfe4.h"

GameInfoList mbss;
MbBeaconRecvStatus mbrs;
MbBeaconRecvStatus *mbrsp = NULL;
void (*gSetBssidCallback)(const u8 *) = NULL;
void (*gClearBssidCallback)(void) = NULL;
GameInfoBlock gGameInfoBlock __attribute__((aligned(32)));
MbBeacon *gReceivedGameInfo;
WMBssDesc bssDescbuf __attribute__((aligned(32)));
void (*sSendVolatCallback)(u32 a) = NULL;
u32 sSendVolatCallbackTimming;

#pragma thumb on

void MBi_SetBeaconRecvStatusBuffer(void *entryTable) {
    mbrsp = entryTable;
}

#pragma thumb off

#pragma thumb on
void MBi_SetScanLockFunc(void (*setCallback)(const u8 *), void (*clearCallback)(void)) {
    gSetBssidCallback = setCallback;
    gClearBssidCallback = clearCallback;
}
#pragma thumb off

#pragma thumb on

void MBi_MakeGameInfo(GameInfoEntry *entry, MBGameRegistry *params, const u8 *record) {
    u32 value;
    u32 iconPaletteMissing;
    volatile u16 clearValue;
    clearValue = 0;
    MIi_CpuClear16(clearValue, entry, 0x4c0);
    entry->mDataAttr = 0;
    value = MBi_ReadIconInfo(params->mIconCharPathp, (u8 *) entry, 1) == 0;
    iconPaletteMissing = MBi_ReadIconInfo(params->mIconPalettePathp, (u8 *) entry, 0) == 0;
    if ((value | iconPaletteMissing) != 0) {
        entry->mDataAttr = 1;
        MemFillWordsByBlock_inline(entry, 0x220);
    }
    entry->mGgid = params->mGgid;
    if (record != NULL) {
        MIi_CpuCopy16(record, entry->mParent, 0x16);
    }
    entry->mMaxPlayerNum = params->mMaxPlayerNum;
    value = mystrlen(params->mGameNamep) * 2;
    MIi_CpuCopy16(params->mGameNamep, entry->mGameName, (u16) value);
    MIi_CpuCopy16(params->mGameIntroductionp, entry->mGameIntroduction, 0xc0);
    entry->mNowPlayerNum = 1;
    entry->mNowPlayerFlag = 1;
    entry->mBroadcastedPlayerFlag = 1;
}

// Reads file a into b (b + 0x20 when c is non-zero) only when its size is 0x20 (c == 0) or 0x200 (c != 0).
u32 MBi_ReadIconInfo(const u8 *path, u8 *buffer, u32 isLarge) {
    FSFile file;
    u32 expectedSize;
    if (isLarge != 0) {
        expectedSize = 0x200;
    } else {
        expectedSize = 0x20;
    }
    if (isLarge != 0) {
        buffer += 0x20;
    }
    if (path == NULL) {
        return 0;
    }
    FS_InitFile(&file);
    if (FS_OpenFile(&file, path) == 0) {
        return 0;
    }
    if (expectedSize != file.mProp.w.mUnk_08 - file.mProp.w.mUnk_04) {
        FS_CloseFile(&file);
        return 0;
    }
    FS_ReadFile(&file, buffer, expectedSize);
    FS_CloseFile(&file);
    return 1;
}

void MB_UpdateGameInfoMember(GameInfoEntry *entry, const void *records, u32 recordMask, u32 value) {
    u8 count;
    s32 recordIndex;
    count = 1;
    MIi_CpuCopy16(records, entry->mMember, 0x14a);
    for (recordIndex = 0; recordIndex < 15; recordIndex++) {
        if ((recordMask & (2 << recordIndex)) != 0) {
            count++;
        }
    }
    entry->mNowPlayerNum = count;
    entry->mNowPlayerFlag = recordMask | 1;
    entry->mChangePlayerFlag = value;
    entry->mSeqNoVolat++;
}

u32 mystrlen(const u16 *string) {
    u32 length;
    for (length = 0; *string++ != 0; length++) {
    }
    return length;
}

void MB_AddGameInfo(GameInfoEntry *newEntry) {
    GameInfoEntry *lastEntry;
    GameInfoEntry *nextEntry;
    if (mbss.mFirst == NULL) {
        mbss.mFirst = newEntry;
    } else {
        lastEntry = mbss.mFirst;
        nextEntry = lastEntry->mNext;
        if (nextEntry != NULL) {
            do {
                lastEntry = nextEntry;
                nextEntry = nextEntry->mNext;
            } while (nextEntry != NULL);
        }
        lastEntry->mNext = newEntry;
    }
    newEntry->mNext = NULL;
}

void MB_InitSendGameInfoStatus(void) {
    mbss.mFirst = NULL;
    mbss.mCurrent = NULL;
    mbss.mState = 1;
    sSendVolatCallback = NULL;
    MBi_ClearSendStatus();
}

void MBi_ClearSendStatus(void) {
    mbss.mSeqNoFixed = 0;
    mbss.mSeqNoVolat = 0;
    mbss.mFlagmentNo = 0;
    mbss.mFlagmentMaxNum = 0;
    mbss.mNextSequence = 0;
}

void MB_SendGameInfoBeacon(u32 ggid, u16 tgid, u32 attr) {
    while (1) {
        switch (mbss.mState) {
            case 0:
            case 1:
                if (MBi_ReadyBeaconSendStatus() == 0) {
                    return;
                }
                break;
            case 2:
                MBi_InitSendFixedBeacon();
                break;
            case 3:
                MBi_SendFixedBeacon(ggid, tgid, attr);
                return;
            case 4:
                MBi_InitSendVolatBeacon();
                break;
            case 5:
                MBi_SendVolatBeacon(ggid, tgid, attr);
                return;
            case 6:
                break;
        }
    }
}

u32 MBi_ReadyBeaconSendStatus(void) {
    GameInfoEntry *entry;
    entry = mbss.mFirst;
    if (entry == NULL) {
        return 0;
    }
    if (mbss.mCurrent != NULL) {
        if (mbss.mCurrent->mNext != NULL) {
            entry = mbss.mCurrent->mNext;
        }
    }
    mbss.mCurrent = entry;
    MBi_ClearSendStatus();
    mbss.mSeqNoVolat = mbss.mCurrent->mSeqNoVolat;
    mbss.mState = 2;
    return 1;
}

void MBi_InitSendFixedBeacon(void) {
    GameInfoEntry *entry;
    if (mbss.mState == 2) {
        entry = mbss.mCurrent;
        if (entry->mDataAttr == 0) {
            mbss.mFlagmentMaxNum = 9;
            mbss.mSrcp = (u8 *) entry;
        } else {
            mbss.mFlagmentMaxNum = 4;
            mbss.mSrcp = entry->mParent;
        }
        mbss.mState = 3;
    }
}

void MBi_SendFixedBeacon(u32 ggid, u16 tgid, u32 attr) {
    GameInfoEntry *entry;
    u8 *source;
    u8 *dataEnd;
    volatile u16 clearValue;
    dataEnd = &mbss.mCurrent->mNowPlayerNum;
    source = mbss.mSrcp;
    if (source + 0x62 <= dataEnd) {
        gGameInfoBlock.mSize = 0x62;
    } else {
        gGameInfoBlock.mSize = dataEnd - source;
        clearValue = 0;
        MIi_CpuClear16(clearValue, (u8 *) &gGameInfoBlock.mHalf0e + gGameInfoBlock.mSize,
                       0x62 - gGameInfoBlock.mSize);
    }
    MIi_CpuCopy16(mbss.mSrcp, &gGameInfoBlock.mHalf0e, gGameInfoBlock.mSize);
    gGameInfoBlock.mByte0a = mbss.mFlagmentNo;
    gGameInfoBlock.mFlagmentMaxNum = mbss.mFlagmentMaxNum;
    entry = mbss.mCurrent;
    gGameInfoBlock.mDataAttr = entry->mDataAttr;
    gGameInfoBlock.mSeqNoFixed = entry->mSeqNoFixed;
    gGameInfoBlock.mSeqNoVolat = mbss.mSeqNoVolat;
    gGameInfoBlock.mGgid = entry->mGgid;
    gGameInfoBlock.mFileNo = entry->mFileNo;
    gGameInfoBlock.mSequence = mbss.mNextSequence++;
    gGameInfoBlock.mChecksum = 0;
    gGameInfoBlock.mChecksum = MBi_calc_cksum(&gGameInfoBlock.mChecksum, 0x68);
    mbss.mFlagmentNo++;
    if (mbss.mFlagmentNo < mbss.mFlagmentMaxNum) {
        mbss.mSrcp += 0x62;
    } else {
        mbss.mState = 4;
    }
    attr |= 2;
    WM_SetGameInfo(NULL, &gGameInfoBlock, 0x70, ggid, tgid, attr);
}

void MBi_InitSendVolatBeacon(void) {
    mbss.mCurrent->mBroadcastedPlayerFlag = 1;
    mbss.mSeqNoVolat = mbss.mCurrent->mSeqNoVolat;
    mbss.mState = 5;
}

void MBi_SendVolatBeacon(u32 ggid, u16 tgid, u32 attr) {
    GameInfoEntry *entry;
    u32 pendingMask;
    u32 recordBit;
    u8 *destination;
    s32 index;
    s32 sourceOffset;
    u32 recordCount;
    volatile u16 clearValue;
    if (mbss.mSeqNoVolat != mbss.mCurrent->mSeqNoVolat) {
        MBi_InitSendVolatBeacon();
    }
    gGameInfoBlock.mDataAttr = 2;
    entry = mbss.mCurrent;
    gGameInfoBlock.mSeqNoFixed = entry->mSeqNoFixed;
    gGameInfoBlock.mSeqNoVolat = mbss.mSeqNoVolat;
    gGameInfoBlock.mGgid = entry->mGgid;
    gGameInfoBlock.mFileNo = entry->mFileNo;
    gGameInfoBlock.mSequence = mbss.mNextSequence++;
    gGameInfoBlock.mByte0a = entry->mNowPlayerNum;
    gGameInfoBlock.mNowPlayerFlag = entry->mNowPlayerFlag;
    gGameInfoBlock.mHalf0e = entry->mChangePlayerFlag;
    if (sSendVolatCallbackTimming == 0 && sSendVolatCallback != NULL) {
        sSendVolatCallback(entry->mGgid);
    }
    for (index = 0; index < 8; index++) {
        gGameInfoBlock.mUserVolatData[index] = mbss.mCurrent->mUserVolatData[index];
    }
    clearValue = 0;
    MIi_CpuClear16(clearValue, gGameInfoBlock.mMember, 0x58);
    recordCount = 0;
    pendingMask = (u16) (mbss.mCurrent->mBroadcastedPlayerFlag ^ mbss.mCurrent->mNowPlayerFlag);
    index = 0;
    destination = gGameInfoBlock.mMember;
    sourceOffset = 0;
    for (; index < 15; index++) {
        recordBit = 2 << index;
        if ((pendingMask & recordBit) != 0) {
            MIi_CpuCopy16(mbss.mCurrent->mMember + sourceOffset, destination, 0x16);
            mbss.mCurrent->mBroadcastedPlayerFlag |= recordBit;
            destination += 0x16;
            recordCount++;
            if (recordCount == 4) {
                break;
            }
        }
        sourceOffset += 0x16;
    }
    if (recordCount < 4) {
        gGameInfoBlock.mMember[recordCount * 0x16] &= ~0xf0;
    }
    gGameInfoBlock.mChecksum = 0;
    gGameInfoBlock.mChecksum = MBi_calc_cksum(&gGameInfoBlock.mChecksum, 0x68);
    if (mbss.mCurrent->mBroadcastedPlayerFlag == mbss.mCurrent->mNowPlayerFlag) {
        mbss.mState = 1;
    }
    attr |= 2;
    WM_SetGameInfo(NULL, &gGameInfoBlock, 0x70, ggid, tgid, attr);
    if (sSendVolatCallbackTimming == 1 && sSendVolatCallback != NULL) {
        sSendVolatCallback(mbss.mCurrent->mGgid);
    }
}

void MB_InitRecvGameInfoStatus(void) {
    MemFillWordsByBlock_inline(mbrsp, 0x5910);
    mbrsp->mScanCountUnit = 1;
}

u32 MB_RecvGameInfoBeacon(EntryCallbackFunc callback, u32 value, WMBssDesc *scanBlock) {
    s32 entryIndex;
    if (MBi_CheckMBParent(scanBlock) == 0) {
        return 0;
    }
    MIi_CpuCopy16(scanBlock, &bssDescbuf, 0xc0);
    scanBlock = &bssDescbuf;
    gReceivedGameInfo = (MbBeacon *) &bssDescbuf.mGameInfo.mUserGameInfo;
    if (MBi_calc_cksum(&gReceivedGameInfo->mChecksum, 0x68) != 0) {
        return 0;
    }
    entryIndex = MBi_GetStoreElement((u8 *) scanBlock, callback);
    if (entryIndex < 0) {
        return 0;
    }
    MBi_AnalyzeBeacon(scanBlock, entryIndex, value);
    MBi_CheckCompleteGameInfoFlagments(entryIndex, callback);
    return 1;
}

u32 MBi_CheckMBParent(WMBssDesc *scanBlock) {
    if ((scanBlock->mGameInfo.mAttribute & 2) == 0 || scanBlock->mGameInfo.mMagicNumber != 1) {
        return 0;
    }
    return 1;
}

#pragma thumb off

#pragma thumb on

void MBi_SetSSIDToBssDesc(u16 *scanBlock, u32 value) {
    scanBlock[5] = 0x20u;
    scanBlock[6] = value;
    scanBlock[7] = ((((value) & (0xffff0000u))) >> 16);
    scanBlock[8] = (scanBlock[0x24]);
}

#pragma thumb off

#pragma thumb on

s32 MBi_GetStoreElement(const u8 *scanBlock, EntryCallbackFunc callback) {
    s32 entryIndex;
    MbBeaconRecvStatus *entryTable;
    MBGameInfoRecvList *entry;
    u16 usedMask;
    entryIndex = 0;
    entryTable = mbrsp;
    entry = entryTable->mEntries;
    for (; entryIndex < 0x10; entryIndex++) {
        u32 entryBit = 1 << entryIndex;
        usedMask = entryTable->mUsedMask;
        if ((usedMask & entryBit) != 0 && entry->mGgid == gReceivedGameInfo->mGgid &&
            entry->mBssid[0] == scanBlock[4] && entry->mBssid[1] == scanBlock[5] && entry->mBssid[2] == scanBlock[6] &&
            entry->mBssid[3] == scanBlock[7] && entry->mBssid[4] == scanBlock[8] && entry->mBssid[5] == scanBlock[9] &&
            gReceivedGameInfo->mFileNo == entryTable->mEntries[entryIndex].mFileNo) {
            if ((entryTable->mValidGameInfoFlag & entryBit) == 0) {
                MBi_LockScanTarget(entryIndex);
            }
            return entryIndex;
        }
        entry++;
    }
    entryIndex = 0;
    usedMask = *(u16 *) entryTable;
    for (; entryIndex < 0x10; entryIndex++) {
        u32 entryBit = 1 << entryIndex;
        if ((usedMask & entryBit) == 0) {
            MIi_CpuCopy16(scanBlock, entryTable->mEntries[entryIndex].mScanBuffer, 0xc0);
            mbrsp->mEntries[entryIndex].mSeqNoFixed = gReceivedGameInfo->mSeqNoFixed;
            mbrsp->mUsedMask |= (u16) entryBit;
            MBi_LockScanTarget(entryIndex);
            return entryIndex;
        }
    }
    if (callback != NULL) {
        callback(4, NULL, 0);
    }
    return -1;
}

void MBi_CheckCompleteGameInfoFlagments(u32 entryIndex, EntryCallbackFunc callback) {
    MBGameInfoRecvList *entry;
    u32 entryBit;
    entry = &mbrsp->mEntries[entryIndex];
    if (entry->mGetFlagmentFlag == entry->mAllFlagmentFlag && entry->mGetFlagmentFlag != 0 && entry->mNowPlayerFlag != 0 &&
        entry->mGetPlayerFlag == entry->mNowPlayerFlag) {
        entryBit = 1 << entryIndex;
        if ((mbrsp->mValidGameInfoFlag & entryBit) == 0) {
            mbrsp->mValidGameInfoFlag |= entryBit;
            mbrsp->mUsefulGameInfoFlag |= entryBit;
            MBi_UnlockScanTarget();
            if (callback != NULL) {
                callback(1, entry, entryIndex);
            }
        }
    } else {
        entryBit = 1 << entryIndex;
        if ((mbrsp->mValidGameInfoFlag & entryBit) != 0) {
            mbrsp->mValidGameInfoFlag ^= entryBit;
            if (callback != NULL) {
                callback(2, entry, entryIndex);
            }
        }
    }
}

void MB_CountGameInfoLifetime(EntryCallbackFunc callback, u32 value) {
    u32 stopFollowing;
    s32 entryIndex;
    u32 entryOffset;
    stopFollowing = 0;
    entryIndex = 0;
    entryOffset = 0;
    for (; entryIndex < 0x10; entryIndex++) {
        MBGameInfoRecvList *entry = OFFSET_PTR(MBGameInfoRecvList, mbrsp->mEntries, entryOffset);
        u16 entryBit = 1 << entryIndex;
        if (mbrsp->mUsedMask & entryBit) {
            entry->mTimer -= mbrsp->mScanCountUnit;
            if (entry->mTimer < 0) {
                entry->mTimer = 0;
                if ((mbrsp->mValidGameInfoFlag & entryBit) != 0 && callback != NULL) {
                    callback(3, NULL, entryIndex);
                }
                if ((mbrsp->mNowScanTargetFlag & entryBit) != 0) {
                    stopFollowing = 1;
                }
                mbrsp->mUsedMask &= ~entryBit;
                MB_DeleteRecvGameInfo(entryIndex);
            }
        }
        entryOffset += sizeof(MBGameInfoRecvList);
    }
    if (mbrsp->mNowScanTargetFlag != 0 && mbrsp->mNowLockTimeCount > 0) {
        mbrsp->mNowLockTimeCount -= mbrsp->mScanCountUnit;
        if (mbrsp->mNowLockTimeCount < 0) {
            stopFollowing = 1;
        } else if (value == 0) {
            mbrsp->mNotFoundLockTargetCount++;
            if (mbrsp->mNotFoundLockTargetCount > 4) {
                stopFollowing = 1;
            }
        } else {
            mbrsp->mNotFoundLockTargetCount = 0;
        }
    }
    if (stopFollowing != 0) {
        mbrsp->mNowLockTimeCount = 0;
        MBi_UnlockScanTarget();
    }
}

void MBi_AnalyzeBeacon(WMBssDesc *scanBlock, u32 entryIndex, u32 value) {
    MBGameInfoRecvList *entry;
    MBi_CheckTGID(scanBlock, entryIndex);
    MBi_CheckSeqNoFixed(entryIndex);
    MBi_CheckSeqNoVolat(entryIndex);
    entry = &mbrsp->mEntries[entryIndex];
    if (entry->mLastSequence == gReceivedGameInfo->mSequence) {
        entry->mSequenceRepeats++;
        if (entry->mSequenceRepeats > 3) {
            entry->mTimer = 0;
            MBi_InvalidateGameInfoBssID(entry->mBssid);
            return;
        }
    } else {
        entry->mSequenceRepeats = 0;
    }
    entry->mLastSequence = gReceivedGameInfo->mSequence;
    entry->mTimer = 0x1771;
    entry->mGgid = gReceivedGameInfo->mGgid;
    entry->mFileNo = gReceivedGameInfo->mFileNo;
    entry->mLinkLevel = value;
    MBi_SetSSIDToBssDesc((u16 *) entry->mScanBuffer, entry->mGgid);
    if (gReceivedGameInfo->mDataAttr == 2) {
        MBi_RecvVolatBeacon(entryIndex);
    } else {
        MBi_RecvFixedBeacon(entryIndex);
    }
}

#pragma thumb off

#pragma thumb on

void MBi_CheckTGID(WMBssDesc *newBlock, int entryIndex) {
    if (newBlock->mGameInfo.mTgid != mbrsp->mEntries[entryIndex].mTgid) {
        MB_DeleteRecvGameInfoWithoutBssdesc(entryIndex);
        MIi_CpuCopy16(newBlock, mbrsp->mEntries[entryIndex].mScanBuffer, 0xc0);
        MBi_LockScanTarget(entryIndex);
    }
}

#pragma thumb off

#pragma thumb on

void MBi_CheckSeqNoFixed(u32 entryIndex) {
    if (gReceivedGameInfo->mSeqNoFixed != mbrsp->mEntries[entryIndex].mSeqNoFixed) {
        MB_DeleteRecvGameInfoWithoutBssdesc(entryIndex);
        MBi_LockScanTarget(entryIndex);
        mbrsp->mEntries[entryIndex].mSeqNoFixed = gReceivedGameInfo->mSeqNoFixed;
    }
}

void MBi_CheckSeqNoVolat(u32 entryIndex) {
    if (gReceivedGameInfo->mSeqNoVolat != mbrsp->mEntries[entryIndex].mSeqNoVolat) {
        MBi_LockScanTarget(entryIndex);
    }
}

void MBi_InvalidateGameInfoBssID(const u8 *bssid) {
    s32 entryIndex;
    u32 entryOffset;
    u32 zero;
    entryIndex = 0;
    entryOffset = 0;
    zero = 0;
    for (; entryIndex < 0x10; entryIndex++) {
        if (mbrsp->mUsedMask & (1 << entryIndex)) {
            u8 *firstBssid = mbrsp->mEntries[0].mBssid;
            u8 *entryBssid = firstBssid + entryOffset;
            if (bssid[0] == firstBssid[entryOffset] && bssid[1] == entryBssid[1] && bssid[2] == entryBssid[2] &&
                bssid[3] == entryBssid[3] && bssid[4] == entryBssid[4] && bssid[5] == entryBssid[5]) {
                *(s16 *) ((u8 *) mbrsp + entryOffset + 0x59a) = zero;
            }
        }
        entryOffset += sizeof(MBGameInfoRecvList);
    }
}

void MBi_RecvFixedBeacon(u32 entryIndex) {
    MBGameInfoRecvList *entry;
    u8 *dataEnd;
    u8 *destination;
    MbBeacon *gameInfo;
    u32 byteCount;
    entry = &mbrsp->mEntries[entryIndex];
    dataEnd = &entry->mNowPlayerNum;
    if (entry->mSeqNoFixed == gReceivedGameInfo->mSeqNoFixed &&
        (entry->mGetFlagmentFlag & (1 << gReceivedGameInfo->mByte0a)) != 0) {
        return;
    }
    if (gReceivedGameInfo->mDataAttr == 0) {
        destination = (u8 *) entry;
    } else {
        destination = entry->mFixedNoIcon;
    }
    gameInfo = gReceivedGameInfo;
    destination += gameInfo->mByte0a * 0x62;
    byteCount = *(u8 *) &gameInfo->mHalf0c;
    if (destination + byteCount > dataEnd) {
        return;
    }
    MIi_CpuCopy16(&gReceivedGameInfo->mHalf0e, destination, byteCount);
    entry->mDataAttr = gReceivedGameInfo->mDataAttr;
    entry->mGetFlagmentFlag |= 1 << gReceivedGameInfo->mByte0a;
    entry->mAllFlagmentFlag = (1 << gReceivedGameInfo->mFlagmentMaxNum) - 1;
}

void MBi_RecvVolatBeacon(u32 entryIndex) {
    MBGameInfoRecvList *entry;
    s32 index;
    u32 recordIndex;
    u8 *record;
    vu16 clearValue;
    u16 zero;
    entry = &mbrsp->mEntries[entryIndex];
    if (entry->mSeqNoVolat != gReceivedGameInfo->mSeqNoVolat) {
        if ((u8) (entry->mSeqNoVolat + 1) == gReceivedGameInfo->mSeqNoVolat) {
            index = 0;
            record = entry->mMember;
            zero = 0;
            for (; index < 0xf; index++) {
                if (gReceivedGameInfo->mHalf0e & (2 << index)) {
                    clearValue = zero;
                    MIi_CpuClear16(clearValue, record, 0x16);
                }
                record += 0x16;
            }
            *(u16 *) &entry->mGetPlayerFlag &= ~gReceivedGameInfo->mHalf0e;
            mbrsp->mValidGameInfoFlag &= ~(1 << entryIndex);
        } else {
            vu16 zeroValue = 0;
            MIi_CpuClear16(zeroValue, entry->mMember, 0x14a);
            entry->mGetPlayerFlag = 0;
            mbrsp->mValidGameInfoFlag &= ~(1 << entryIndex);
        }
        entry->mSeqNoVolat = gReceivedGameInfo->mSeqNoVolat;
    } else if (entry->mGetPlayerFlag == gReceivedGameInfo->mHalf0c) {
        return;
    }
    entry->mNowPlayerNum = gReceivedGameInfo->mByte0a;
    entry->mNowPlayerFlag = gReceivedGameInfo->mHalf0c;
    entry->mChangePlayerFlag = gReceivedGameInfo->mHalf0e;
    entry->mGetPlayerFlag |= 1;
    for (index = 0; index < 8; index++) {
        entry->mUserVolatData[index] = gReceivedGameInfo->mUserVolatData[index];
    }
    for (recordIndex = 0; recordIndex < 4; recordIndex++) {
        u32 recordNumber = gReceivedGameInfo->mMember[recordIndex].mPlayerNo;
        if (recordNumber != 0) {
            MIi_CpuCopy16(&gReceivedGameInfo->mMember[recordIndex], &entry->mMember[(recordNumber - 1) * 0x16], 0x16);
            entry->mGetPlayerFlag |= 1 << recordNumber;
        }
    }
}

void MBi_LockScanTarget(u32 entryIndex) {
    if (mbrsp->mNowScanTargetFlag == 0) {
        if (gSetBssidCallback != NULL) {
            gSetBssidCallback(mbrsp->mEntries[entryIndex].mBssid);
        }
        mbrsp->mScanCountUnit = 0x16;
        mbrsp->mNowScanTargetFlag = 1 << entryIndex;
        mbrsp->mNowLockTimeCount = 0x321;
    }
}

void MBi_UnlockScanTarget(void) {
    if (mbrsp->mNowScanTargetFlag != 0) {
        if (*gClearBssidCallback != 0) {
            (*gClearBssidCallback)();
        }
        mbrsp->mScanCountUnit = 1;
        mbrsp->mNowScanTargetFlag = 0;
        mbrsp->mNotFoundLockTargetCount = 0;
    }
}

void MB_DeleteRecvGameInfo(u32 entryIndex) {
    u32 entryBit = 1 << entryIndex;
    vu16 clearValue;
    mbrsp->mUsefulGameInfoFlag &= ~entryBit;
    mbrsp->mValidGameInfoFlag &= ~entryBit;
    clearValue = 0;
    MIi_CpuClear16(clearValue, &mbrsp->mEntries[entryIndex], sizeof(MBGameInfoRecvList));
}

void MB_DeleteRecvGameInfoWithoutBssdesc(u32 entryIndex) {
    u32 entryBit = 1 << entryIndex;
    vu16 clearValue;
    mbrsp->mUsefulGameInfoFlag &= ~entryBit;
    mbrsp->mValidGameInfoFlag &= ~entryBit;
    mbrsp->mEntries[entryIndex].mGetFlagmentFlag = 0;
    mbrsp->mEntries[entryIndex].mAllFlagmentFlag = 0;
    mbrsp->mEntries[entryIndex].mGetPlayerFlag = 0;
    mbrsp->mEntries[entryIndex].mLinkLevel = 0;
    clearValue = 0;
    MIi_CpuClear16(clearValue, &mbrsp->mEntries[entryIndex], 0x4c0);
}

MBGameInfoRecvList *MB_GetGameInfoRecvList(u32 entryIndex) {
    if ((mbrsp->mUsefulGameInfoFlag & (1 << entryIndex)) == 0) {
        return NULL;
    }
    return &mbrsp->mEntries[entryIndex];
}

#pragma thumb off
