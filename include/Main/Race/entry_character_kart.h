#pragma once

#include "types.h"

typedef struct CharacterKartPicks CharacterKartPicks;

void GetEntryCharacterAndKart(CharacterKartPicks *picks, u8 entryIndex, u32 *outCharacterIndex, u32 *outKartIndex);
void SetGivenCharacterAndKart(CharacterKartPicks *picks, u32 entryIndex, u32 characterIndex, u32 kartIndex);
