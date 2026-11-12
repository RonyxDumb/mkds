#pragma once

#include "types.h"

void SetKartIndicesFromCharacters(void);
void FillRandomKartIndices(void);
void FillRandomCharacterIndices(void);
void ClearNonParticipantKartIndices(void);
void ClearNonParticipantCharacterIndices(void);
void ClearPicksHolderPointer(void);
void CreatePicksHolder(void *heap);
