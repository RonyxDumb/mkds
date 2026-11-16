#pragma once

#include "types.h"

typedef struct TimeRecord TimeRecord;

void savd_setNktaEntry(u32 courseId, int recordIndex, TimeRecord *timeRecord);
