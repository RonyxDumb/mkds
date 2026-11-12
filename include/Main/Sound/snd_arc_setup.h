#pragma once

#include "types.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_set_load.h" // SndFileIdList

typedef struct NNSSndHeap NNSSndHeap;

u32 SetupSndArcFromFile(NNSSndArc *arc, const u8 *filePath, NNSSndHeap *heap, u32 symbolLoadFlag);
void ClearSndFileIdList(SndFileIdList *fileIdList);
void ClearSndFileAddresses(SndFileIdList *fileIdList);
