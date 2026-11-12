#pragma once

#include "types.h"
#include "Main/Menu/data_0217d000.h"

void SetKartIndicesFromCharacters(void);
void FillRandomKartIndices(void);
void FillRandomCharacterIndices(void);
void ClearNonParticipantKartIndices(void);
void ClearNonParticipantCharacterIndices(void);
void ClearPicksHolderPointer(void);
void CreatePicksHolder(void *heap);

extern const u32 gCharacterKartIndices[13];
extern struct PicksHolder *gPicksHolder;
