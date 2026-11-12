#include "Main/Kart/kart_table_index.h"

#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/code_02029890.h"

#pragma thumb on
s32 GetCharacterKartIndexByMode(s32 characterIndex) {
    s32 kartIndex = -1;
    switch (GetRaceSetupCopy()->mMode) {
        case 0:
        case 1:
        case 3:
        case MODE_WIFI:
            kartIndex = gCharacterKartIndexTable[characterIndex];
            break;
        case 2:
            kartIndex = gCharacterKartIndexTableBattle[characterIndex];
            break;
    }
    return kartIndex;
}

s32 FindKartTableIndex(u32 kartIndex) {
    s32 tableIndex = 0;
    s32 foundIndex = -1;
    if (kartIndex != 0x24) {
        for (; tableIndex < 0x24; tableIndex++) {
            if (kartIndex == gKartIndexTable[tableIndex]) {
                foundIndex = tableIndex;
                break;
            }
        }
    }
    return foundIndex;
}
#pragma thumb off

#pragma thumb on
u32 GetKartIndexAtTableIndex(u32 tableIndex) {
    return gKartIndexTable[tableIndex];
}
#pragma thumb off
