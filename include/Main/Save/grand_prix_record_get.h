#pragma once

#include "types.h"

typedef struct TimeRecord TimeRecord;

u32 GetGrandPrixRecord(int cup, int engineClass, TimeRecord *record);

typedef struct PackedGrandPrixRecord PackedGrandPrixRecord;

void UnpackGrandPrixRecord(PackedGrandPrixRecord *packedGrandPrixRecord, TimeRecord *timeRecord);

void SetGrandPrixRecord(int cup, int engineClass, TimeRecord *record);
