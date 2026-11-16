#pragma once

#include "types.h"

// A colour that fades between course colours: mColor, its start parts, the steps to the new one, mBlendFactor.
typedef struct CourseColorBlend {
    /* 00 */ u16 mColor;
    /* 02 */ s16 mStartComponent0;
    /* 04 */ s16 mStartComponent1;
    /* 06 */ s16 mStartComponent2;
    /* 08 */ s16 mComponentDelta0;
    /* 0a */ s16 mComponentDelta1;
    /* 0c */ s16 mComponentDelta2;
    /* 0e */ u16 mColorBit;
    /* 10 */ s16 mBlendFactor;
} CourseColorBlend;

void AdvanceCourseColorBlend(CourseColorBlend *blend, u16 colorMask, s32 step);
void SetCourseColorBlendColor(CourseColorBlend *blend, u32 colorMask);
CourseColorBlend *InitCourseColorBlend(CourseColorBlend *blend, u32 colorMask);
