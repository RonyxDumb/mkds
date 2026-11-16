#pragma once

#include "types.h"

typedef struct TimeRecord TimeRecord;

u32 CopyCupEntryTo_from_thumb(int cup, int engineClass, TimeRecord *record);

typedef struct PackedGrandPrixRecord PackedGrandPrixRecord;

void StructNKGPCupEntry_CopyTo_from_thumb(PackedGrandPrixRecord *packedGrandPrixRecord, TimeRecord *timeRecord);

void CopyCupEntryFrom_from_thumb(int cup, int engineClass, TimeRecord *record);
