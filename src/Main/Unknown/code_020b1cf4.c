#include "Main/Unknown/code_020b1cf4.h"

s32 GetRaceHudSubScreenCourseScale(void) {
    return (gRaceHud->mSubScreenCourseScale);
}

RaceHudSubScreenBgAffine *GetRaceHudSubScreenBgAffine(void) {
    return gRaceHud->mSubScreenBgAffines;
}

BOOL IsRaceHudGoalMUploaded(void) {
    return (gRaceHud->mGoalMUploaded);
}

BOOL IsRaceHudGoalMEnabled(void) {
    return (gRaceHud->mGoalMEnabled);
}

u32 GetRaceHudKartRemoved(u32 kartIndex) {
    return (gRaceHud->mKartRemoved[kartIndex]);
}
