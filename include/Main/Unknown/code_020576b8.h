#pragma once

#include "types.h"

typedef struct EmblemBlockData EmblemBlockData;

void savd_readNkfe(EmblemBlockData *blockData, s32 blockIndex);
void savd_writeNkfe(EmblemBlockData *blockData, s32 blockIndex);
