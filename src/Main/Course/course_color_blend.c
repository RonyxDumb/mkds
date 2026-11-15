#include "Main/Course/course_color_blend.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/System/init_after_startup.h"

CourseColorBlend *InitCourseColorBlend(CourseColorBlend *blend, u32 colorMask) {
    u16 colorIndex;
    u16 color;

    for (colorIndex = 0; colorIndex < 4; colorIndex++) {
        if (colorMask & (1 << colorIndex)) {
            break;
        }
    }
    color = gCourseMap->mSettings->mColors[colorIndex];
    blend->mColor = color;
    blend->mColorBit = 1 << colorIndex;
    blend->mStartComponent0 = blend->mColor & 0x1f;
    blend->mStartComponent1 = (blend->mColor >> 5) & 0x1f;
    blend->mStartComponent2 = (blend->mColor >> 10) & 0x1f;
    blend->mComponentDelta0 = 0;
    blend->mComponentDelta1 = 0;
    blend->mComponentDelta2 = 0;
    blend->mBlendFactor = TO_FIXED12(1);
    return blend;
}

void SetCourseColorBlendColor(CourseColorBlend *blend, u32 colorMask) {
    u16 colorIndex;

    for (colorIndex = 0; colorIndex < 4; colorIndex++) {
        if (colorMask & (1 << colorIndex)) {
            break;
        }
    }
    blend->mColor = gCourseMap->mSettings->mColors[colorIndex];
    blend->mColorBit = 1 << colorIndex;
}

void AdvanceCourseColorBlend(CourseColorBlend *blend, u16 colorMask, s32 step) {
    u16 newColorBits = ~blend->mColorBit & colorMask;
    u16 colorIndex;
    u16 color;
    s32 unusedValue;

    if (newColorBits != 0) {
        for (colorIndex = 0; colorIndex < 4; colorIndex++) {
            if (newColorBits & (1 << colorIndex)) {
                break;
            }
        }
        color = gCourseMap->mSettings->mColors[colorIndex];
        blend->mStartComponent0 = blend->mColor & 0x1f;
        blend->mComponentDelta0 = (s16) (color & 0x1f) - blend->mStartComponent0;
        blend->mStartComponent1 = (blend->mColor >> 5) & 0x1f;
        blend->mComponentDelta1 = (s16) ((color >> 5) & 0x1f) - blend->mStartComponent1;
        blend->mStartComponent2 = (blend->mColor >> 10) & 0x1f;
        blend->mComponentDelta2 = (s16) ((color >> 10) & 0x1f) - blend->mStartComponent2;
        blend->mBlendFactor = 0;
        blend->mColorBit = 1 << colorIndex;
    }
    if (blend->mBlendFactor == TO_FIXED12(1)) {
        return;
    }
    blend->mBlendFactor = blend->mBlendFactor + (MUL_FIXED12_ROUNDED(step, 0xa4) + 0x29);
    if (blend->mBlendFactor >= TO_FIXED12(1)) {
        blend->mBlendFactor = TO_FIXED12(1);
    }
    blend->mColor =
        (s16) (blend->mStartComponent0 + MUL_FIXED12_ROUNDED(blend->mComponentDelta0, blend->mBlendFactor)) +
        ((s16) (blend->mStartComponent1 + MUL_FIXED12_ROUNDED(blend->mComponentDelta1, blend->mBlendFactor)) << 5) +
        ((s16) (blend->mStartComponent2 + MUL_FIXED12_ROUNDED(blend->mComponentDelta2, blend->mBlendFactor)) << 10);
}
