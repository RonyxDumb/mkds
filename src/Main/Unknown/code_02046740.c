#include "Main/Unknown/code_02046740.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_021759c0.h"

void rconf_gotoNextGpRace(void) {
    gRaceMultiConfig->mNextHeader.mCourseNumber = gRaceMultiConfig->mCourseNumber + 1;
    if (gRaceMultiConfig->mNextHeader.mCourseNumber <= 4) {
        gRaceMultiConfig->mNextHeader.mCourseId =
            sCupDefs[gRaceMultiConfig->mNextHeader.mCupIndex][gRaceMultiConfig->mNextHeader.mCourseNumber - 1];
    }
    gRaceMultiConfig->mNextHeader.mRaceKind = RACE_KIND_START_GP;
}
