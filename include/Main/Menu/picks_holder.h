#pragma once

#include "types.h"
#include "Main/Menu/menu_screens_work.h"

void SetKartIndicesFromCharacters(void);
void FillRandomKartIndices(void);
void FillRandomCharacterIndices(void);
void ClearNonParticipantKartIndices(void);
void ClearNonParticipantCharacterIndices(void);
void ResetGlobalKTB_from_thumb(void);
void CreateSetGlobalKTB_from_thumb(void *heap);

extern const u32 gCharacterKartIndices[13];
extern struct PicksHolder *g_GlobalKTB;
