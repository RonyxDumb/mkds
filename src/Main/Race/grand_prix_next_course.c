#include "Main/Race/grand_prix_next_course.h"
#include "Main/MapObjects/data_02154000.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/race_setup_input.h"

void SetNextGrandPrixCourse(void) {
    gRaceSetup->mNextHeader.mCourseNumber = gRaceSetup->mCourseNumber + 1;
    if (gRaceSetup->mNextHeader.mCourseNumber <= COURSES_PER_CUP) {
        gRaceSetup->mNextHeader.mCourseId =
            gCupCourseIdTable[gRaceSetup->mNextHeader.mCupIndex][gRaceSetup->mNextHeader.mCourseNumber - 1];
    }
    gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_START_GP;
}
