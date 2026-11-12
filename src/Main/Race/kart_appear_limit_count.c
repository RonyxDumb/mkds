#include "Main/Race/kart_appear_limit_count.h"
#include "Main/Kart/kart_table_index.h"

#pragma thumb on

int CountKartsWithinAppearLimit(KartAppear *appear, u32 characterIndex) {
    int count;
    int tableIndex;
    int testResult;
    u32 kartIndex;
    count = 0;
    tableIndex = 0;
    do {
        kartIndex = GetKartIndexAtTableIndex(tableIndex);
        testResult = IsKartAppearWithinLimit(appear, characterIndex, kartIndex);
        if (testResult != 0) {
            count = count + 1;
        }
        tableIndex = tableIndex + 1;
    } while (tableIndex < 0x24);
    return count;
}

#pragma thumb off
