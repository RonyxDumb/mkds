#include "Main/Unknown/code_0202a340.h"
#include "Main/Unknown/code_02025000.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02025cd0.h"

#pragma thumb on

void gpres_getCourseTimeAsString(s16 *a, int index) {
    Unk0217aa1c_144_00 *entry;
    entry = &gStruct217B488->mCourseTimes[index];
    mutil2_timeToString((a), entry->field2, entry->field3, gStruct217B488->mCourseTimes[index].field0);
}

#pragma thumb off
