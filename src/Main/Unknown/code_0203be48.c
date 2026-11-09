#include "Main/Unknown/code_0203be48.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_0203ba84.h"

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
