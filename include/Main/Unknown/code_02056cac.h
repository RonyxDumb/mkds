#pragma once

#include "types.h"

typedef struct TimeRecord TimeRecord;
typedef struct PackedCourseTimeRecord PackedCourseTimeRecord;

void savd_packNktaEntry(PackedCourseTimeRecord *packedCourseTimeRecord, TimeRecord *timeRecord);
