#include "code_02008e10.h"
#include "code_0214cfe4.h"

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
        if ((usedMask & entryBit) != 0 && entry->mUnk_4b8 == gReceivedGameInfo->mUnk_00 &&
            entry->mBssid[0] == scanBlock[4] && entry->mBssid[1] == scanBlock[5] && entry->mBssid[2] == scanBlock[6] &&
            entry->mBssid[3] == scanBlock[7] && entry->mBssid[4] == scanBlock[8] && entry->mBssid[5] == scanBlock[9] &&
            gReceivedGameInfo->mUnk_04_2 == entryTable->mEntries[entryIndex].mUnk_4b5) {
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
            mbrsp->mEntries[entryIndex].mUnk_4b3 = gReceivedGameInfo->mUnk_05;
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
    if (entry->mUnk_580 == entry->mUnk_584 && entry->mUnk_580 != 0 && entry->mUnk_35a != 0 &&
        entry->mUnk_588 == entry->mUnk_35a) {
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

void MBi_AnalyzeBeacon(u8 *scanBlock, u32 entryIndex, u32 value) {
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
    entry->mUnk_4b8 = gReceivedGameInfo->mUnk_00;
    entry->mUnk_4b5 = gReceivedGameInfo->mUnk_04_2;
    entry->mUnk_58c = value;
    MBi_SetSSIDToBssDesc((u16 *) entry->mScanBuffer, entry->mUnk_4b8);
    if (gReceivedGameInfo->mUnk_04 == 2) {
        MBi_RecvVolatBeacon(entryIndex);
    } else {
        MBi_RecvFixedBeacon(entryIndex);
    }
}

#pragma thumb off
