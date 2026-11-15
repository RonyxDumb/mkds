#include "Main/Race/cup_reset.h"
#include "Main/Race/cup_records.h"
#include "Main/Race/race_setup_block.h"
#include "tp.h"

void ResetCupToFirstCourse(void) {
    ResetCupRecords();
    gRaceSetup->mNextHeader.mCourseNumber = 1;
}
