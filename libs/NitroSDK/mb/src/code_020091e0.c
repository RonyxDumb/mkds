#include "code_020091e0.h"
#include "code_020091fc.h"
#include "code_02003024.h"
#include "code_0214d018.h"
#include "code_02009908.h"
#include "code_02008934.h"

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
    MIi_CpuCopy16(scanBlock, &data_0216fce0, 0xc0);
    scanBlock = &data_0216fce0;
    gReceivedGameInfo = data_0216fd30;
    if (MBi_calc_cksum(OFFSET_PTR(u16, gReceivedGameInfo, 8), 0x68) != 0) {
        return 0;
    }
    entryIndex = MBi_GetStoreElement((u8 *) scanBlock, callback);
    if (entryIndex < 0) {
        return 0;
    }
    MBi_AnalyzeBeacon((u8 *) scanBlock, entryIndex, value);
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
