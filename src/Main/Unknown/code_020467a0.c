#include "Main/Unknown/code_020467a0.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/unk_021759c0.h"

void ResetCupToFirstCourse(void) {
    ResetCupRecords();
    gRaceSetup->mNextHeader.mCourseNumber = 1;
}
