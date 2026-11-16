#pragma once

#include "types.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_set_load.h" // SndFileIdList

typedef struct NNSSndHeap NNSSndHeap;

u32 Sound_ReadSdatFromPathImplV2(NNSSndArc *arc, const u8 *filePath, NNSSndHeap *heap, u32 symbolLoadFlag);
void ClearSndFileIdList(SndFileIdList *fileIdList);
void ClearSndFileAddresses(SndFileIdList *fileIdList);
