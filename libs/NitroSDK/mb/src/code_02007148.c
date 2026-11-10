#include "code_02007148.h"
#include "mb_data.h"

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
