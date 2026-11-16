#include "Main/Unknown/code_02007148.h"
#include "Main/Unknown/unk_0216f000.h"

#pragma thumb on

void func_02007154(u32 entryIndex) {
    Unk0216fdac *entry;
    u16 current;
    u16 rangeStart;
    enum { K0 } k;
    k = entryIndex * 0x5d4;
    entry = OFFSET_PTR(Unk0216fdac, data_0216fdac, k);
    if (entry->mEntryUsed == 0) {
        return;
    }
    if (entry->field1D4C == 0) {
        return;
    }
    current = entry->field1D48;
    rangeStart = entry->field1D4A;
    if (rangeStart <= current && current <= rangeStart + 2) {
        entry->field1D48 = current + 1;
        return;
    }
    entry->field1D48 = rangeStart;
}

u32 GetLargerValue(u32 first, u32 second) {
    if (second <= first) {
        second = first;
    }
    return second;
}

#pragma thumb off
