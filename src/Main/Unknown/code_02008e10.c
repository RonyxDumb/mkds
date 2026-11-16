#include "Main/Unknown/code_02008e10.h"
#include "code_0214cfe4.h"

#pragma thumb on

s32 FindOrAddEntry(const u8 *scanBlock, EntryCallbackFunc callback) {
    s32 i;
    EntryTable *entryTable;
    EntryRecord *entry;
    u16 usedMask;
    i = 0;
    entryTable = gEntryTable;
    entry = entryTable->mEntries;
    for (; i < 0x10; i++) {
        u32 entryBit = 1 << i;
        usedMask = entryTable->mUsedMask;
        if ((usedMask & entryBit) != 0 && entry->field4B8 == gReceivedGameInfo->field0 &&
            entry->mBssid[0] == scanBlock[4] && entry->mBssid[1] == scanBlock[5] && entry->mBssid[2] == scanBlock[6] &&
            entry->mBssid[3] == scanBlock[7] && entry->mBssid[4] == scanBlock[8] && entry->mBssid[5] == scanBlock[9] &&
            gReceivedGameInfo->field4_2 == entryTable->mEntries[i].field4B5) {
            if ((entryTable->field4 & entryBit) == 0) {
                SetScanBssidFromEntry(i);
            }
            return i;
        }
        entry++;
    }
    i = 0;
    usedMask = *(u16 *) entryTable;
    for (; i < 0x10; i++) {
        u32 entryBit = 1 << i;
        if ((usedMask & entryBit) == 0) {
            MIi_CpuCopy16(scanBlock, entryTable->mEntries[i].mScanBuffer, 0xc0);
            gEntryTable->mEntries[i].field4B3 = gReceivedGameInfo->field5;
            gEntryTable->mUsedMask |= (u16) entryBit;
            SetScanBssidFromEntry(i);
            return i;
        }
    }
    if (callback != NULL) {
        callback(4, NULL, 0);
    }
    return -1;
}

void func_02008ff0(u32 entryIndex, EntryCallbackFunc callback) {
    EntryRecord *entry;
    u32 entryBit;
    entry = &gEntryTable->mEntries[entryIndex];
    if (entry->field580 == entry->field584 && entry->field580 != 0 && entry->field35A != 0 &&
        entry->field588 == entry->field35A) {
        entryBit = 1 << entryIndex;
        if ((gEntryTable->field4 & entryBit) == 0) {
            gEntryTable->field4 |= entryBit;
            gEntryTable->field2 |= entryBit;
            ClearScanBssid();
            if (callback != NULL) {
                callback(1, entry, entryIndex);
            }
        }
    } else {
        entryBit = 1 << entryIndex;
        if ((gEntryTable->field4 & entryBit) != 0) {
            gEntryTable->field4 ^= entryBit;
            if (callback != NULL) {
                callback(2, entry, entryIndex);
            }
        }
    }
}

void MB_CountGameInfoLifetime(EntryCallbackFunc callback, u32 b) {
    u32 stopFollowing;
    s32 i;
    u32 entryOffset;
    stopFollowing = 0;
    i = 0;
    entryOffset = 0;
    for (; i < 0x10; i++) {
        EntryRecord *entry = OFFSET_PTR(EntryRecord, gEntryTable->mEntries, entryOffset);
        u16 entryBit = 1 << i;
        if (gEntryTable->mUsedMask & entryBit) {
            entry->mTimer -= gEntryTable->fieldC;
            if (entry->mTimer < 0) {
                entry->mTimer = 0;
                if ((gEntryTable->field4 & entryBit) != 0 && callback != NULL) {
                    callback(3, NULL, i);
                }
                if ((gEntryTable->field6 & entryBit) != 0) {
                    stopFollowing = 1;
                }
                gEntryTable->mUsedMask &= ~entryBit;
                ClearEntry(i);
            }
        }
        entryOffset += sizeof(EntryRecord);
    }
    if (gEntryTable->field6 != 0 && gEntryTable->field8 > 0) {
        gEntryTable->field8 -= gEntryTable->fieldC;
        if (gEntryTable->field8 < 0) {
            stopFollowing = 1;
        } else if (b == 0) {
            gEntryTable->fieldA++;
            if (gEntryTable->fieldA > 4) {
                stopFollowing = 1;
            }
        } else {
            gEntryTable->fieldA = 0;
        }
    }
    if (stopFollowing != 0) {
        gEntryTable->field8 = 0;
        ClearScanBssid();
    }
}

void UpdateEntryFromScan(u8 *scanBlock, u32 entryIndex, u32 c) {
    EntryRecord *entry;
    ReplaceEntryIfChanged(scanBlock, entryIndex);
    func_02008d68(entryIndex);
    func_02008d30(entryIndex);
    entry = &gEntryTable->mEntries[entryIndex];
    if (entry->mLastSequence == gReceivedGameInfo->mSequence) {
        entry->mSequenceRepeats++;
        if (entry->mSequenceRepeats > 3) {
            entry->mTimer = 0;
            ExpireEntriesWithBssid(entry->mBssid);
            return;
        }
    } else {
        entry->mSequenceRepeats = 0;
    }
    entry->mLastSequence = gReceivedGameInfo->mSequence;
    entry->mTimer = 0x1771;
    entry->field4B8 = gReceivedGameInfo->field0;
    entry->field4B5 = gReceivedGameInfo->field4_2;
    entry->field58C = c;
    func_020091e0((u16 *) entry->mScanBuffer, entry->field4B8);
    if (gReceivedGameInfo->field4 == 2) {
        func_02008aa0(entryIndex);
    } else {
        func_02008c08(entryIndex);
    }
}

#pragma thumb off
