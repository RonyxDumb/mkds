#include "Main/Unknown/code_020b1cf4.h"

s32 GetRaceHudSubScreenCourseScale(void) {
    return (r2d_sStatus->mSubScreenCourseScale);
}

RaceHudSubScreenBgAffine *GetRaceHudSubScreenBgAffine(void) {
    return (RaceHudSubScreenBgAffine *) r2d_sStatus->field858;
}

u32 func_020b1d20(void) {
    return (r2d_sStatus->field848);
}

u32 func_020b1d0c(void) {
    return (r2d_sStatus->field84C);
}

u32 GetRaceHudKartRemoved(u32 kartIndex) {
    return (r2d_sStatus->mKartRemoved[kartIndex]);
}
