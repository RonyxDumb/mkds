#pragma once

#include "types.h"

typedef struct TimeRecord TimeRecord;
typedef struct PackedGrandPrixRecord PackedGrandPrixRecord;

void savd_unpackNkgpEntry(PackedGrandPrixRecord *packedGrandPrixRecord, TimeRecord *timeRecord);
