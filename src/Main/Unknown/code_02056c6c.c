#include "Main/Unknown/code_02056c6c.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02056cac.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void savd_setNktaEntry(u32 courseId, int recordIndex, TimeRecord *timeRecord) {
    int cupCourseIndex;
    cupCourseIndex = rconf_getCourseNumber(courseId);
    if (cupCourseIndex != -1) {
        savd_packNktaEntry(&gSaveData->mCourseTimeRecordBlock->mRecords[recordIndex][cupCourseIndex], timeRecord);
    }
}

#pragma thumb off
