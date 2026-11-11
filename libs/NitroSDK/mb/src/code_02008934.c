#include "code_02008934.h"
#include "code_0214cfe4.h"

#pragma thumb on

void MBi_CheckSeqNoFixed(u32 entryIndex) {
    if (gReceivedGameInfo->mUnk_05 != mbrsp->mEntries[entryIndex].mUnk_4b3) {
        MB_DeleteRecvGameInfoWithoutBssdesc(entryIndex);
        MBi_LockScanTarget(entryIndex);
        mbrsp->mEntries[entryIndex].mUnk_4b3 = gReceivedGameInfo->mUnk_05;
    }
}

void MBi_CheckSeqNoVolat(u32 entryIndex) {
    if (gReceivedGameInfo->mUnk_06 != mbrsp->mEntries[entryIndex].mUnk_4b4) {
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
    Unk0216fc1c *gameInfo;
    u32 byteCount;
    entry = &mbrsp->mEntries[entryIndex];
    dataEnd = &entry->mUnk_358;
    if (entry->mUnk_4b3 == gReceivedGameInfo->mUnk_05 && (entry->mUnk_580 & (1 << gReceivedGameInfo->mUnk_0a)) != 0) {
        return;
    }
    if (gReceivedGameInfo->mUnk_04 == 0) {
        destination = (u8 *) entry;
    } else {
        destination = entry->mUnk_220;
    }
    gameInfo = gReceivedGameInfo;
    destination += gameInfo->mUnk_0a * 0x62;
    byteCount = *(u8 *) &gameInfo->mUnk_0c;
    if (destination + byteCount > dataEnd) {
        return;
    }
    MIi_CpuCopy16(&gReceivedGameInfo->mUnk_0e, destination, byteCount);
    entry->mUnk_4b2 = gReceivedGameInfo->mUnk_04;
    entry->mUnk_580 |= 1 << gReceivedGameInfo->mUnk_0a;
    entry->mUnk_584 = (1 << gReceivedGameInfo->mUnk_0b) - 1;
}

void MBi_RecvVolatBeacon(u32 entryIndex) {
    MBGameInfoRecvList *entry;
    s32 index;
    u32 recordIndex;
    u8 *record;
    vu16 clearValue;
    u16 zero;
    entry = &mbrsp->mEntries[entryIndex];
    if (entry->mUnk_4b4 != gReceivedGameInfo->mUnk_06) {
        if ((u8) (entry->mUnk_4b4 + 1) == gReceivedGameInfo->mUnk_06) {
            index = 0;
            record = entry->mUnk_35e;
            zero = 0;
            for (; index < 0xf; index++) {
                if (gReceivedGameInfo->mUnk_0e & (2 << index)) {
                    clearValue = zero;
                    MIi_CpuClear16(clearValue, record, 0x16);
                }
                record += 0x16;
            }
            *(u16 *) &entry->mUnk_588 &= ~gReceivedGameInfo->mUnk_0e;
            mbrsp->mValidGameInfoFlag &= ~(1 << entryIndex);
        } else {
            vu16 zeroValue = 0;
            MIi_CpuClear16(zeroValue, entry->mUnk_35e, 0x14a);
            entry->mUnk_588 = 0;
            mbrsp->mValidGameInfoFlag &= ~(1 << entryIndex);
        }
        entry->mUnk_4b4 = gReceivedGameInfo->mUnk_06;
    } else if (entry->mUnk_588 == gReceivedGameInfo->mUnk_0c) {
        return;
    }
    entry->mUnk_358 = gReceivedGameInfo->mUnk_0a;
    entry->mUnk_35a = gReceivedGameInfo->mUnk_0c;
    entry->mUnk_35c = gReceivedGameInfo->mUnk_0e;
    entry->mUnk_588 |= 1;
    for (index = 0; index < 8; index++) {
        entry->mUnk_4a8[index] = gReceivedGameInfo->mUnk_68[index];
    }
    for (recordIndex = 0; recordIndex < 4; recordIndex++) {
        u32 recordNumber = gReceivedGameInfo->mUnk_10[recordIndex].mUnk_00_4;
        if (recordNumber != 0) {
            MIi_CpuCopy16(&gReceivedGameInfo->mUnk_10[recordIndex], &entry->mUnk_35e[(recordNumber - 1) * 0x16], 0x16);
            entry->mUnk_588 |= 1 << recordNumber;
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
    mbrsp->mEntries[entryIndex].mUnk_580 = 0;
    mbrsp->mEntries[entryIndex].mUnk_584 = 0;
    mbrsp->mEntries[entryIndex].mUnk_588 = 0;
    mbrsp->mEntries[entryIndex].mUnk_58c = 0;
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
