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
    u32 v1;
    u32 v2;
    volatile u16 clearValue;
    clearValue = 0;
    MIi_CpuClear16(clearValue, entry, 0x4c0);
    entry->mUnk_4b2 = 0;
    v1 = MBi_ReadIconInfo(params->mIconCharPathp, (u8 *) entry, 1) == 0;
    v2 = MBi_ReadIconInfo(params->mIconPalettePathp, (u8 *) entry, 0) == 0;
    if ((v1 | v2) != 0) {
        entry->mUnk_4b2 = 1;
        MemFillWordsByBlock_inline(entry, 0x220);
    }
    entry->mUnk_4b8 = params->mGgid;
    if (record != NULL) {
        MIi_CpuCopy16(record, entry->mUnk_220, 0x16);
    }
    entry->mUnk_236 = params->mMaxPlayerNum;
    v1 = mystrlen(params->mGameNamep) * 2;
    MIi_CpuCopy16(params->mGameNamep, entry->mUnk_238, (u16) v1);
    MIi_CpuCopy16(params->mGameIntroductionp, entry->mUnk_298, 0xc0);
    entry->mUnk_358 = 1;
    entry->mUnk_35a = 1;
    entry->mUnk_4b0 = 1;
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

void MB_UpdateGameInfoMember(GameInfoEntry *entry, const void *records, u32 recordMask, u32 d) {
    u8 v1;
    s32 i;
    v1 = 1;
    MIi_CpuCopy16(records, entry->mUnk_35e, 0x14a);
    for (i = 0; i < 15; i++) {
        if ((recordMask & (2 << i)) != 0) {
            v1++;
        }
    }
    entry->mUnk_358 = v1;
    entry->mUnk_35a = recordMask | 1;
    entry->mUnk_35c = d;
    entry->mUnk_4b4++;
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
    mbss.mUnk_0d = 0;
    mbss.mUnk_0e = 0;
    mbss.mUnk_0f = 0;
    mbss.mUnk_10 = 0;
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
    mbss.mUnk_0e = mbss.mCurrent->mUnk_4b4;
    mbss.mState = 2;
    return 1;
}

void MBi_InitSendFixedBeacon(void) {
    GameInfoEntry *entry;
    if (mbss.mState == 2) {
        entry = mbss.mCurrent;
        if (entry->mUnk_4b2 == 0) {
            mbss.mUnk_10 = 9;
            mbss.mUnk_08 = (u8 *) entry;
        } else {
            mbss.mUnk_10 = 4;
            mbss.mUnk_08 = entry->mUnk_220;
        }
        mbss.mState = 3;
    }
}

void MBi_SendFixedBeacon(u32 ggid, u16 tgid, u32 attr) {
    GameInfoEntry *entry;
    u8 *source;
    u8 *dataEnd;
    volatile u16 clearValue;
    dataEnd = &mbss.mCurrent->mUnk_358;
    source = mbss.mUnk_08;
    if (source + 0x62 <= dataEnd) {
        gGameInfoBlock.mUnk_0c_b = 0x62;
    } else {
        gGameInfoBlock.mUnk_0c_b = dataEnd - source;
        clearValue = 0;
        MIi_CpuClear16(clearValue, (u8 *) &gGameInfoBlock.mUnk_0e + gGameInfoBlock.mUnk_0c_b,
                       0x62 - gGameInfoBlock.mUnk_0c_b);
    }
    MIi_CpuCopy16(mbss.mUnk_08, &gGameInfoBlock.mUnk_0e, gGameInfoBlock.mUnk_0c_b);
    gGameInfoBlock.mUnk_0a = mbss.mUnk_0f;
    gGameInfoBlock.mUnk_0b = mbss.mUnk_10;
    entry = mbss.mCurrent;
    gGameInfoBlock.mUnk_04_0 = entry->mUnk_4b2;
    gGameInfoBlock.mUnk_05 = entry->mUnk_4b3;
    gGameInfoBlock.mUnk_06 = mbss.mUnk_0e;
    gGameInfoBlock.mUnk_00 = entry->mUnk_4b8;
    gGameInfoBlock.mUnk_04_2 = entry->mUnk_4b5;
    gGameInfoBlock.mSequence = mbss.mNextSequence++;
    gGameInfoBlock.mChecksum = 0;
    gGameInfoBlock.mChecksum = MBi_calc_cksum(&gGameInfoBlock.mChecksum, 0x68);
    mbss.mUnk_0f++;
    if (mbss.mUnk_0f < mbss.mUnk_10) {
        mbss.mUnk_08 += 0x62;
    } else {
        mbss.mState = 4;
    }
    attr |= 2;
    WM_SetGameInfo(NULL, &gGameInfoBlock, 0x70, ggid, tgid, attr);
}

void MBi_InitSendVolatBeacon(void) {
    mbss.mCurrent->mUnk_4b0 = 1;
    mbss.mUnk_0e = mbss.mCurrent->mUnk_4b4;
    mbss.mState = 5;
}

void MBi_SendVolatBeacon(u32 ggid, u16 tgid, u32 attr) {
    GameInfoEntry *entry;
    u32 pendingMask;
    u32 recordBit;
    u8 *destination;
    s32 i;
    s32 sourceOffset;
    u32 recordCount;
    volatile u16 clearValue;
    if (mbss.mUnk_0e != mbss.mCurrent->mUnk_4b4) {
        MBi_InitSendVolatBeacon();
    }
    gGameInfoBlock.mUnk_04_0 = 2;
    entry = mbss.mCurrent;
    gGameInfoBlock.mUnk_05 = entry->mUnk_4b3;
    gGameInfoBlock.mUnk_06 = mbss.mUnk_0e;
    gGameInfoBlock.mUnk_00 = entry->mUnk_4b8;
    gGameInfoBlock.mUnk_04_2 = entry->mUnk_4b5;
    gGameInfoBlock.mSequence = mbss.mNextSequence++;
    gGameInfoBlock.mUnk_0a = entry->mUnk_358;
    gGameInfoBlock.mUnk_0c = entry->mUnk_35a;
    gGameInfoBlock.mUnk_0e = entry->mUnk_35c;
    if (sSendVolatCallbackTimming == 0 && sSendVolatCallback != NULL) {
        sSendVolatCallback(entry->mUnk_4b8);
    }
    for (i = 0; i < 8; i++) {
        gGameInfoBlock.mUnk_68[i] = mbss.mCurrent->mUnk_4a8[i];
    }
    clearValue = 0;
    MIi_CpuClear16(clearValue, gGameInfoBlock.mUnk_10, 0x58);
    recordCount = 0;
    pendingMask = (u16) (mbss.mCurrent->mUnk_4b0 ^ mbss.mCurrent->mUnk_35a);
    i = 0;
    destination = gGameInfoBlock.mUnk_10;
    sourceOffset = 0;
    for (; i < 15; i++) {
        recordBit = 2 << i;
        if ((pendingMask & recordBit) != 0) {
            MIi_CpuCopy16(mbss.mCurrent->mUnk_35e + sourceOffset, destination, 0x16);
            mbss.mCurrent->mUnk_4b0 |= recordBit;
            destination += 0x16;
            recordCount++;
            if (recordCount == 4) {
                break;
            }
        }
        sourceOffset += 0x16;
    }
    if (recordCount < 4) {
        gGameInfoBlock.mUnk_10[recordCount * 0x16] &= ~0xf0;
    }
    gGameInfoBlock.mChecksum = 0;
    gGameInfoBlock.mChecksum = MBi_calc_cksum(&gGameInfoBlock.mChecksum, 0x68);
    if (mbss.mCurrent->mUnk_4b0 == mbss.mCurrent->mUnk_35a) {
        mbss.mState = 1;
    }
    attr |= 2;
    WM_SetGameInfo(NULL, &gGameInfoBlock, 0x70, ggid, tgid, attr);
    if (sSendVolatCallbackTimming == 1 && sSendVolatCallback != NULL) {
        sSendVolatCallback(mbss.mCurrent->mUnk_4b8);
    }
}

void MB_InitRecvGameInfoStatus(void) {
    MemFillWordsByBlock_inline(mbrsp, 0x5910);
    mbrsp->mScanCountUnit = 1;
}

u32 MB_RecvGameInfoBeacon(EntryCallbackFunc callback, u32 b, WMBssDesc *scanBlock) {
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
    MBi_AnalyzeBeacon((u8 *) scanBlock, entryIndex, b);
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

void MBi_SetSSIDToBssDesc(u16 *scanBlock, u32 p1) {
    scanBlock[5] = 0x20u;
    scanBlock[6] = p1;
    scanBlock[7] = ((((p1) & (0xffff0000u))) >> 16);
    scanBlock[8] = (scanBlock[0x24]);
}

#pragma thumb off
