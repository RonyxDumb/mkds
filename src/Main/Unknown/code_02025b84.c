#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_020b4000.h"

#pragma thumb on
u32 SetPlayerCharacterCellFileSet(u32 characterIndex, void *cellFileSet) {
    u32 value0 = characterIndex;
    u32 cellFileSetAddress = (u32) cellFileSet;
    u32 cellFileSetCopy;
    u32 characterIndexCopy;
    characterIndexCopy = (value0) + (0u);
    cellFileSetCopy = (cellFileSetAddress) + (0u);
    value0 = (u32) GetPlayerCharacterNcgr(value0);
    *(u32 *) ((cellFileSetCopy) + 0u) = value0;
    value0 = (characterIndexCopy) + (0u);
    value0 = (u32) GetPlayerCharacterNcer(value0);
    *(u32 *) ((cellFileSetCopy) + 8u) = value0;
    value0 = (characterIndexCopy) + (0u);
    value0 = (u32) GetPlayerCharacterNclr(value0);
    *(u32 *) ((cellFileSetCopy) + 4u) = value0;
    value0 = (characterIndexCopy) + (0u);
    value0 = (u32) GetPlayerCharacterBncl(value0);
    *(u32 *) ((cellFileSetCopy) + 12u) = value0;
    return value0;
}
#pragma thumb off
