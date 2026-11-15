#include "Main/Graphics/player_character_cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"

#pragma thumb on
u32 SetPlayerCharacterCellFileSet(u32 characterIndex, void *cellFileSet) {
    u32 value = characterIndex;
    u32 cellFileSetAddress = (u32) cellFileSet;
    u32 cellFileSetCopy;
    u32 characterIndexCopy;
    characterIndexCopy = (value) + (0u);
    cellFileSetCopy = (cellFileSetAddress) + (0u);
    value = (u32) GetPlayerCharacterNcgr(value);
    *(u32 *) ((cellFileSetCopy) + 0u) = value;
    value = (characterIndexCopy) + (0u);
    value = (u32) GetPlayerCharacterNcer(value);
    *(u32 *) ((cellFileSetCopy) + 8u) = value;
    value = (characterIndexCopy) + (0u);
    value = (u32) GetPlayerCharacterNclr(value);
    *(u32 *) ((cellFileSetCopy) + 4u) = value;
    value = (characterIndexCopy) + (0u);
    value = (u32) GetPlayerCharacterBncl(value);
    *(u32 *) ((cellFileSetCopy) + 12u) = value;
    return value;
}
#pragma thumb off
