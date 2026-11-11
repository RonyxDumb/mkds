#include "code_02008934.h"
#include "code_0214cfe4.h"

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
