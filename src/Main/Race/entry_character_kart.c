#include "Main/Race/entry_character_kart.h"
#include "Main/Menu/title_scene.h"
#include "Main/Race/random_pick.h"

#pragma thumb on

void SetGivenCharacterAndKart(CharacterKartPicks *picks, u32 entryIndex, u32 characterIndex, u32 kartIndex) {
    SetGivenCharacter(picks, entryIndex, characterIndex);
    SetGivenKart(picks, entryIndex, kartIndex);
}

void GetEntryCharacterAndKart(CharacterKartPicks *picks, u8 entryIndex, u32 *outCharacterIndex, u32 *outKartIndex) {
    if (outCharacterIndex != NULL) {
        *outCharacterIndex = picks->mCharacterIndices[entryIndex];
    }
    if (outKartIndex != NULL) {
        *outKartIndex = picks->mKartIndices[entryIndex];
    }
}

#pragma thumb off
