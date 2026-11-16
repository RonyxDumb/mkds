#include "Main/Unknown/code_020b1cf4.h"

s32 GetRaceHudSubScreenCourseScale(void) {
    return (r2d_sStatus->mSubScreenCourseScale);
}

RaceHudSubScreenBgAffine *GetRaceHudSubScreenBgAffine(void) {
    return (RaceHudSubScreenBgAffine *) r2d_sStatus->field858;
}

u32 sub_20B1D20(void) {
    return (r2d_sStatus->field848);
}

u32 sub_20B1D0C(void) {
    return (r2d_sStatus->field84C);
}

u32 GetRaceHudKartRemoved(u32 kartIndex) {
    return (r2d_sStatus->mKartRemoved[kartIndex]);
}
