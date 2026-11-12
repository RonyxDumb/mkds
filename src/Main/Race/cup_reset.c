#include "Main/Race/cup_reset.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Race/cup_records.h"
#include "Main/Unknown/unk_021759c0.h"

void ResetCupToFirstCourse(void) {
    ResetCupRecords();
    gRaceSetup->mNextHeader.mCourseNumber = 1;
}
