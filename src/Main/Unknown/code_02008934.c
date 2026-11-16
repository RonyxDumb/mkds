#include "Main/Unknown/code_02008934.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0214cfe4.h"

#pragma thumb on

void func_02008d68(u32 entryIndex) {
    if (gReceivedGameInfo->field5 != gEntryTable->mEntries[entryIndex].field4B3) {
        func_0200895c(entryIndex);
        SetScanBssidFromEntry(entryIndex);
        gEntryTable->mEntries[entryIndex].field4B3 = gReceivedGameInfo->field5;
    }
}

void func_02008d30(u32 entryIndex) {
    if (gReceivedGameInfo->field6 != gEntryTable->mEntries[entryIndex].field4B4) {
        SetScanBssidFromEntry(entryIndex);
    }
}

void ExpireEntriesWithBssid(const u8 *bssid) {
    s32 i;
    u32 entryOffset;
    u32 zero;
    i = 0;
    entryOffset = 0;
    zero = 0;
    for (; i < 0x10; i++) {
        if (gEntryTable->mUsedMask & (1 << i)) {
            u8 *firstBssid = gEntryTable->mEntries[0].mBssid;
            u8 *entryBssid = firstBssid + entryOffset;
            if (bssid[0] == firstBssid[entryOffset] && bssid[1] == entryBssid[1] && bssid[2] == entryBssid[2] &&
                bssid[3] == entryBssid[3] && bssid[4] == entryBssid[4] && bssid[5] == entryBssid[5]) {
                *(s16 *) ((u8 *) gEntryTable + entryOffset + 0x59a) = zero;
            }
        }
        entryOffset += sizeof(EntryRecord);
    }
}

void func_02008c08(u32 entryIndex) {
    EntryRecord *entry;
    u8 *dataEnd;
    u8 *destination;
    Unk0216fc1c *gameInfo;
    u32 byteCount;
    entry = &gEntryTable->mEntries[entryIndex];
    dataEnd = &entry->field358;
    if (entry->field4B3 == gReceivedGameInfo->field5 && (entry->field580 & (1 << gReceivedGameInfo->fieldA)) != 0) {
        return;
    }
    if (gReceivedGameInfo->field4 == 0) {
        destination = (u8 *) entry;
    } else {
        destination = entry->field220;
    }
    gameInfo = gReceivedGameInfo;
    destination += gameInfo->fieldA * 0x62;
    byteCount = *(u8 *) &gameInfo->fieldC;
    if (destination + byteCount > dataEnd) {
        return;
    }
    MIi_CpuCopy16(&gReceivedGameInfo->fieldE, destination, byteCount);
    entry->field4B2 = gReceivedGameInfo->field4;
    entry->field580 |= 1 << gReceivedGameInfo->fieldA;
    entry->field584 = (1 << gReceivedGameInfo->fieldB) - 1;
}

void func_02008aa0(u32 entryIndex) {
    EntryRecord *entry;
    s32 i;
    u32 j;
    u8 *record;
    vu16 clearValue;
    u16 zero;
    entry = &gEntryTable->mEntries[entryIndex];
    if (entry->field4B4 != gReceivedGameInfo->field6) {
        if ((u8) (entry->field4B4 + 1) == gReceivedGameInfo->field6) {
            i = 0;
            record = entry->field35E;
            zero = 0;
            for (; i < 0xf; i++) {
                if (gReceivedGameInfo->fieldE & (2 << i)) {
                    clearValue = zero;
                    MIi_CpuClear16(clearValue, record, 0x16);
                }
                record += 0x16;
            }
            *(u16 *) &entry->field588 &= ~gReceivedGameInfo->fieldE;
            gEntryTable->field4 &= ~(1 << entryIndex);
        } else {
            vu16 v2 = 0;
            MIi_CpuClear16(v2, entry->field35E, 0x14a);
            entry->field588 = 0;
            gEntryTable->field4 &= ~(1 << entryIndex);
        }
        entry->field4B4 = gReceivedGameInfo->field6;
    } else if (entry->field588 == gReceivedGameInfo->fieldC) {
        return;
    }
    entry->field358 = gReceivedGameInfo->fieldA;
    entry->field35A = gReceivedGameInfo->fieldC;
    entry->field35C = gReceivedGameInfo->fieldE;
    entry->field588 |= 1;
    for (i = 0; i < 8; i++) {
        entry->field4A8[i] = gReceivedGameInfo->field68[i];
    }
    for (j = 0; j < 4; j++) {
        u32 recordNumber = gReceivedGameInfo->field10[j].field0_4;
        if (recordNumber != 0) {
            MIi_CpuCopy16(&gReceivedGameInfo->field10[j], &entry->field35E[(recordNumber - 1) * 0x16], 0x16);
            entry->field588 |= 1 << recordNumber;
        }
    }
}

void SetScanBssidFromEntry(u32 entryIndex) {
    if (gEntryTable->field6 == 0) {
        if (gSetBssidCallback != NULL) {
            gSetBssidCallback(gEntryTable->mEntries[entryIndex].mBssid);
        }
        gEntryTable->fieldC = 0x16;
        gEntryTable->field6 = 1 << entryIndex;
        gEntryTable->field8 = 0x321;
    }
}

void ClearScanBssid(void) {
    if (gEntryTable->field6 != 0) {
        if (*gClearBssidCallback != 0) {
            (*gClearBssidCallback)();
        }
        gEntryTable->fieldC = 1;
        gEntryTable->field6 = 0;
        gEntryTable->fieldA = 0;
    }
}

void ClearEntry(u32 entryIndex) {
    u32 entryBit = 1 << entryIndex;
    vu16 clearValue;
    gEntryTable->field2 &= ~entryBit;
    gEntryTable->field4 &= ~entryBit;
    clearValue = 0;
    MIi_CpuClear16(clearValue, &gEntryTable->mEntries[entryIndex], sizeof(EntryRecord));
}

void func_0200895c(u32 entryIndex) {
    u32 entryBit = 1 << entryIndex;
    vu16 clearValue;
    gEntryTable->field2 &= ~entryBit;
    gEntryTable->field4 &= ~entryBit;
    gEntryTable->mEntries[entryIndex].field580 = 0;
    gEntryTable->mEntries[entryIndex].field584 = 0;
    gEntryTable->mEntries[entryIndex].field588 = 0;
    gEntryTable->mEntries[entryIndex].field58C = 0;
    clearValue = 0;
    MIi_CpuClear16(clearValue, &gEntryTable->mEntries[entryIndex], 0x4c0);
}

EntryRecord *MB_GetGameInfoRecvList(u32 entryIndex) {
    if ((gEntryTable->field2 & (1 << entryIndex)) == 0) {
        return NULL;
    }
    return &gEntryTable->mEntries[entryIndex];
}

#pragma thumb off
