#include "Main/Unknown/code_02025e28.h"

#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/code_02029890.h"

#pragma thumb on
s32 GetCharacterKartIndexByMode(s32 characterIndex) {
    s32 kartIndex = -1;
    switch (GetRaceSetupCopy()->mMode) {
        case 0:
        case 1:
        case 3:
        case 5:
            kartIndex = gCharacterKartIndexTable[characterIndex];
            break;
        case 2:
            kartIndex = gCharacterKartIndexTableBattle[characterIndex];
            break;
    }
    return kartIndex;
}

s32 FindKartTableIndex(u32 kartIndex) {
    s32 i = 0;
    s32 r = -1;
    if (kartIndex != 0x24) {
        for (; i < 0x24; i++) {
            if (kartIndex == gKartIndexTable[i]) {
                r = i;
                break;
            }
        }
    }
    return r;
}
#pragma thumb off

#pragma thumb on
u32 GetKartIndexAtTableIndex(u32 tableIndex) {
    return gKartIndexTable[tableIndex];
}
#pragma thumb off
