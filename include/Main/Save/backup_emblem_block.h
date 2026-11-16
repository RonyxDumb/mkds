#pragma once

#include "types.h"

typedef struct EmblemBlockData EmblemBlockData;

void ReadSaveChunk_NKFE_from_thumb(EmblemBlockData *blockData, s32 blockIndex);
void WriteSaveChunk_NKFE_from_thumb(EmblemBlockData *blockData, s32 blockIndex);
