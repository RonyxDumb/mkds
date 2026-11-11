#include "Main/Unknown/code_020c3db4.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"

BOOL IsRaceGoalSRuleCourseCountReached(void) {
    u32 courseCountReached = gRaceGoalS->mCourseCountReached;
    RaceSetup *setup = gRaceSetup;

    if (setup->mMode == MODE_VS || setup->mMode == MODE_WIFI || setup->mMode == MODE_BATTLE) {
        if (setup->mRuleKind != 0) {
            return courseCountReached;
        }
    }
    return 0;
}
