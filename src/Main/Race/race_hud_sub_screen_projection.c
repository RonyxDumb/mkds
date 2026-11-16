#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"

#include "fixed_vector_math.h"
#include "Main/Race/race_hud_sub_screen_mode.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"
#include "Main/Kart/camera.h"
#include "Main/Item/item_gesso.h"
#include "fixed_arctangent.h"
#include "Main/System/heap.h"
#include "Main/Race/race_hud_sub_screen_bg3.h"
#include "Main/Race/race_hud_sub_screen_heap.h"
#include "Main/Kart/karts.h"
#include "Main/System/init_after_startup.h"

RaceHudSubScreenProjection *gRaceHudSubScreenProjection;

const Vec3 gRaceHudSubScreenInitialScrollPosition = {0, 0, 0};

void InitRaceHudSubScreenProjection(void) {
    IntPair kartIconsMin;
    IntPair kartIconsMax;
    IntPair courseMin;
    IntPair courseMax;
    IntPair bg3Min;
    IntPair bg3Max;

    gRaceHudSubScreenProjection = HeapAlloc(RaceHudSubScreenGetCurrentHeap(), sizeof(RaceHudSubScreenProjection));
    gRaceHudSubScreenProjection->mCenter.mFirst = 0;
    gRaceHudSubScreenProjection->mCenter.mSecond = 0;
    gRaceHudSubScreenProjection->mCenterWhole.mFirst = 0;
    gRaceHudSubScreenProjection->mCenterWhole.mSecond = 0;
    gRaceHudSubScreenProjection->mHalfSize = 0;
    gRaceHudSubScreenProjection->mAnglePairSecond = 0;
    gRaceHudSubScreenProjection->mAnglePairFirst = 0;
    gRaceHudSubScreenProjection->mAnglePairSecondScaled = 0;
    gRaceHudSubScreenProjection->mAnglePairFirstScaled = 0;
    GetRaceHudSubScreenKartIconsMinMax(&kartIconsMin, &kartIconsMax);
    gRaceHudSubScreenProjection->mKartIconsMin = kartIconsMin;
    gRaceHudSubScreenProjection->mKartIconsMax = kartIconsMax;
    gRaceHudSubScreenProjection->mKartIconsInverseFirst = FX_InvFx64c(kartIconsMax.mFirst - kartIconsMin.mFirst);
    gRaceHudSubScreenProjection->mKartIconsInverseSecond = FX_InvFx64c(kartIconsMax.mSecond - kartIconsMin.mSecond);
    GetRaceHudSubScreenCourseMinMax(&courseMin, &courseMax);
    gRaceHudSubScreenProjection->mCourseMin = courseMin;
    gRaceHudSubScreenProjection->mCourseMax = courseMax;
    gRaceHudSubScreenProjection->mCourseInverseX = FX_InvFx64c(courseMax.mFirst - courseMin.mFirst);
    gRaceHudSubScreenProjection->mCourseInverseZ = FX_InvFx64c(courseMax.mSecond - courseMin.mSecond);
    gRaceHudSubScreenProjection->mCourseWidthScaled =
        MulFixed12NoRound(FX_Div(courseMax.mFirst - courseMin.mFirst, 0x200000), 0xb0000);
    GetRaceHudSubScreenBg3MinMax(&bg3Min, &bg3Max);
    gRaceHudSubScreenProjection->mBg3Min = bg3Min;
    gRaceHudSubScreenProjection->mBg3Max = bg3Max;
    gRaceHudSubScreenProjection->mBg3InverseX = FX_InvFx64c(bg3Max.mFirst - bg3Min.mFirst);
    gRaceHudSubScreenProjection->mBg3InverseZ = FX_InvFx64c(bg3Max.mSecond - bg3Min.mSecond);
    gRaceHudSubScreenProjection->mScrollTimer = 0;
    gRaceHudSubScreenProjection->mScrollPosition = gRaceHudSubScreenInitialScrollPosition;
}

void ClearRaceHudSubScreenProjection(void) {
    gRaceHudSubScreenProjection = NULL;
}

BOOL IsCourseWithMap2DLocal3(void) {
    BOOL result = FALSE;

    switch (RaceHudSubScreenGetCurrentCourseId()) {
        case COURSE_ID_OLD_YOSHI_GC:
        case COURSE_ID_OLD_MOMO_64:
        case COURSE_ID_OLD_LUIGI_GC:
        case COURSE_ID_OLD_FRAPPE_64:
        case COURSE_ID_CLOCK:
        case COURSE_ID_MANSION:
        case COURSE_ID_AIRSHIP:
        case COURSE_ID_CROSS:
        case COURSE_ID_OLD_HYUDORO_64:
        case COURSE_ID_RIDGE:
        case COURSE_ID_MARIO:
        case COURSE_ID_GARDEN:
        case COURSE_ID_DESERT:
        case COURSE_ID_TOWN:
        case COURSE_ID_SNOW:
        case COURSE_ID_PINBALL:
        case COURSE_ID_STADIUM:
        case COURSE_ID_OLD_KINOKO_GC:
        case COURSE_ID_OLD_SKY_AGB:
        case COURSE_ID_MR_STAGE1:
        case COURSE_ID_MR_STAGE3:
            result = TRUE;
            break;
    }
    return result;
}

BOOL IsCourseWithSubBg3AreaOverflow(void) {
    BOOL result = FALSE;

    switch (RaceHudSubScreenGetCurrentCourseId()) {
        case COURSE_ID_OLD_YOSHI_GC:
        case COURSE_ID_OLD_MOMO_64:
        case COURSE_ID_OLD_FRAPPE_64:
        case COURSE_ID_OLD_HYUDORO_64:
        case COURSE_ID_RIDGE:
        case COURSE_ID_MARIO:
        case COURSE_ID_GARDEN:
        case COURSE_ID_DESERT:
        case COURSE_ID_STADIUM:
        case COURSE_ID_OLD_SKY_AGB:
        case COURSE_ID_MR_STAGE1:
        case COURSE_ID_MR_STAGE3:
            result = TRUE;
            break;
    }
    return result;
}

// Only state 1, which takes the angle from the camera, also clears the scroll timer.
u16 GetSubScreenAngleAndClearScrollTimer(void) {
    u16 angle = 0;
    Camera *camera;
    s32 rawAngle;

    switch (GetRaceHudSubScreenState()) {
        case RACE_HUD_SUB_SCREEN_MAP_TURNING:
            if (RaceHudSubScreenGetCurrentMode() == MODE_BATTLE) {
                camera = GetCurrentCamera();
            } else {
                camera = GetChaseCamera();
            }
            rawAngle = FX_Atan2Idx(camera->mViewMatrix.mRows[2].z, camera->mViewMatrix.mRows[0].z);
            angle = (0x14000 - rawAngle) % 0x10000;
            gRaceHudSubScreenProjection->mScrollTimer = 0;
            break;
        case RACE_HUD_SUB_SCREEN_MAP_FIXED_SCROLL:
            angle = 0;
            break;
        case RACE_HUD_SUB_SCREEN_MAP_VIEW:
            rawAngle = GetFixed12Whole(GetCourseMapSubScreenView()->mAngleDegrees);
            angle = (rawAngle << 16) / 360 + 0x8000;
            break;
        default:
            break;
    }
    return angle;
}

u16 GetRaceHudSubScreenKartAngle(s32 kartIndex) {
    return (0x18000 - GetKartHeadingAngle(kartIndex)) % 0x10000;
}

void ComputeSubScreenKartIconsKartPosition(s32 kartIndex, IntPair *out) {
    IntPair kartIconsMin = gRaceHudSubScreenProjection->mKartIconsMin;
    Vec3 kartPos;

    GetKartPos(&kartPos, (u8) kartIndex);
    switch (RaceHudSubScreenGetCurrentCourseId()) {
        case COURSE_ID_OLD_MOMO_64:
        case COURSE_ID_CROSS:
        case COURSE_ID_OLD_KINOKO_GC:
            if (RaceHudSubScreenGetCurrentMirrorMode() != 0) {
                out->mFirst = GetFixed12Whole(MulFixed12NoRound(
                                  0x80000, MulFx64c(kartIconsMin.mFirst - kartPos.z,
                                                    gRaceHudSubScreenProjection->mKartIconsInverseFirst))) +
                              0xf8;
            } else {
                out->mFirst = GetFixed12Whole(MulFixed12NoRound(
                                  0x80000, MulFx64c(kartPos.z - kartIconsMin.mFirst,
                                                    gRaceHudSubScreenProjection->mKartIconsInverseFirst))) +
                              0x78;
            }
            out->mSecond =
                GetFixed12Whole(MulFixed12NoRound(0x98000, MulFx64c(kartPos.x - kartIconsMin.mSecond,
                                                                    gRaceHudSubScreenProjection->mKartIconsInverseSecond))) +
                0x28;
            break;
        case COURSE_ID_BANK:
            if (RaceHudSubScreenGetCurrentMirrorMode() != 0) {
                out->mFirst = GetFixed12Whole(MulFixed12NoRound(
                                  0x80000, MulFx64c(kartIconsMin.mFirst - kartPos.z,
                                                    gRaceHudSubScreenProjection->mKartIconsInverseFirst))) +
                              0xf8;
            } else {
                out->mFirst = GetFixed12Whole(MulFixed12NoRound(
                                  0x80000, MulFx64c(kartPos.z - kartIconsMin.mFirst,
                                                    gRaceHudSubScreenProjection->mKartIconsInverseFirst))) +
                              0x78;
            }
            out->mSecond =
                GetFixed12Whole(MulFixed12NoRound(0x98000, MulFx64c(kartPos.x - kartIconsMin.mSecond,
                                                                    gRaceHudSubScreenProjection->mKartIconsInverseSecond))) +
                0x28;
            break;
        default:
            if (RaceHudSubScreenGetCurrentMirrorMode() != 0) {
                out->mFirst = GetFixed12Whole(MulFixed12NoRound(
                                  0x80000, MulFx64c(kartIconsMin.mFirst - kartPos.x,
                                                    gRaceHudSubScreenProjection->mKartIconsInverseFirst))) +
                              0xf8;
            } else {
                out->mFirst = GetFixed12Whole(MulFixed12NoRound(
                                  0x80000, MulFx64c(kartPos.x - kartIconsMin.mFirst,
                                                    gRaceHudSubScreenProjection->mKartIconsInverseFirst))) +
                              0x78;
            }
            out->mSecond =
                GetFixed12Whole(MulFixed12NoRound(0x98000, MulFx64c(kartPos.z - kartIconsMin.mSecond,
                                                                    gRaceHudSubScreenProjection->mKartIconsInverseSecond))) +
                0x28;
            break;
    }
}

void ComputeRaceHudSubScreenCoursePosition(const Vec3 *pos, IntPair *out) {
    IntPair courseMin = gRaceHudSubScreenProjection->mCourseMin;

    out->mFirst = GetFixed12Whole(
        MulFixed12NoRound(0x200000, MulFx64c(pos->x - courseMin.mFirst, gRaceHudSubScreenProjection->mCourseInverseX)));
    out->mSecond = GetFixed12Whole(MulFixed12NoRound(
        0x200000, MulFx64c(pos->z - courseMin.mSecond, gRaceHudSubScreenProjection->mCourseInverseZ)));
}

BOOL IsRaceHudSubScreenPairNearCenter(const IntPair *position) {
    IntPair centerWhole = gRaceHudSubScreenProjection->mCenterWhole;
    s32 halfSize = gRaceHudSubScreenProjection->mHalfSize;

    if (position->mFirst - halfSize < centerWhole.mFirst && centerWhole.mFirst < position->mFirst + halfSize &&
        position->mSecond - halfSize < centerWhole.mSecond && centerWhole.mSecond < position->mSecond + halfSize) {
        return TRUE;
    }
    return FALSE;
}

void ComputeRaceHudSubScreenKartPosition(s32 kartIndex, IntPair *out, s32 unused) {
    IntPair center = gRaceHudSubScreenProjection->mCenter;
    s32 centerY = center.mSecond;
    s32 pairSecondScaled = gRaceHudSubScreenProjection->mAnglePairSecondScaled;
    s32 pairFirstScaled = gRaceHudSubScreenProjection->mAnglePairFirstScaled;
    IntPair courseMin = gRaceHudSubScreenProjection->mCourseMin;
    Vec3 kartPos;
    s32 projectedX;
    s32 projectedY;
    s32 dx;
    s32 dy;

    GetKartPos(&kartPos, (u8) kartIndex);
    projectedX = MulFixed12NoRound(
        0x200000, MulFx64c(kartPos.x - courseMin.mFirst, gRaceHudSubScreenProjection->mCourseInverseX));
    projectedY = MulFixed12NoRound(
        0x200000, MulFx64c(kartPos.z - courseMin.mSecond, gRaceHudSubScreenProjection->mCourseInverseZ));
    if (RaceHudSubScreenGetCurrentMirrorMode() != 0) {
        dy = projectedY - centerY;
        dx = projectedX - center.mFirst;
        out->mFirst =
            GetFixed12Whole(MulFixed12NoRound(-pairSecondScaled, dx) + MulFixed12NoRound(pairFirstScaled, dy)) + 0x80;
        out->mSecond =
            GetFixed12Whole(MulFixed12NoRound(pairFirstScaled, dx) + MulFixed12NoRound(pairSecondScaled, dy)) + 0x60;
    } else {
        dx = projectedX - center.mFirst;
        dy = projectedY - centerY;
        out->mFirst =
            GetFixed12Whole(MulFixed12NoRound(pairSecondScaled, dx) - MulFixed12NoRound(pairFirstScaled, dy)) + 0x80;
        out->mSecond =
            GetFixed12Whole(MulFixed12NoRound(pairFirstScaled, dx) + MulFixed12NoRound(pairSecondScaled, dy)) + 0x60;
    }
}

static inline s32 ClearFixed12Fraction(s32 value) {
    float wholePart;

    if (GetFixed12Whole(value) > 0) {
        wholePart = 0.5f + TO_FIXED12(GetFixed12Whole(value));
    } else {
        wholePart = TO_FIXED12(GetFixed12Whole(value)) - 0.5f;
    }
    return wholePart;
}

BOOL ComputeRaceHudSubScreenPosition(const Vec3 *pos, IntPair *out, s32 unusedSubScreenScale, s32 requireNearCenter,
                                     s32 exactCenter) {
    IntPair center = gRaceHudSubScreenProjection->mCenter;
    s32 pairSecondScaled = gRaceHudSubScreenProjection->mAnglePairSecondScaled;
    s32 pairFirstScaled = gRaceHudSubScreenProjection->mAnglePairFirstScaled;
    IntPair courseMin = gRaceHudSubScreenProjection->mCourseMin;
    s32 centerX;
    s32 centerY;
    s32 dx;
    s32 projectedX;
    s32 projectedY;
    s32 dy;
    s32 deltaY;
    s32 screenX;
    s32 screenY;
    IntPair centerWhole;
    s32 halfSize;
    s32 wholeX;
    s32 wholeY;

    projectedX =
        MulFixed12NoRound(0x200000, MulFx64c(pos->x - courseMin.mFirst, gRaceHudSubScreenProjection->mCourseInverseX));
    projectedY =
        MulFixed12NoRound(0x200000, MulFx64c(pos->z - courseMin.mSecond, gRaceHudSubScreenProjection->mCourseInverseZ));
    if (requireNearCenter != 0) {
        centerWhole = gRaceHudSubScreenProjection->mCenterWhole;
        halfSize = gRaceHudSubScreenProjection->mHalfSize;
        wholeX = GetFixed12Whole(projectedX);
        wholeY = GetFixed12Whole(projectedY);

        if (wholeX - halfSize >= centerWhole.mFirst || centerWhole.mFirst >= wholeX + halfSize ||
            wholeY - halfSize >= centerWhole.mSecond || centerWhole.mSecond >= wholeY + halfSize) {
            return FALSE;
        }
    }
    if (exactCenter != 0) {
        centerX = center.mFirst;
        centerY = center.mSecond;
    } else {
        centerX = ClearFixed12Fraction(center.mFirst);
        centerY = ClearFixed12Fraction(center.mSecond);
    }
    if (RaceHudSubScreenGetCurrentMirrorMode() != 0) {
        dx = projectedX - centerX;
        dy = projectedY - centerY;
        screenX =
            GetFixed12Whole(MulFixed12NoRound(-pairSecondScaled, dx) + MulFixed12NoRound(pairFirstScaled, dy)) + 0x80;
        screenY =
            GetFixed12Whole(MulFixed12NoRound(pairFirstScaled, dx) + MulFixed12NoRound(pairSecondScaled, dy)) + 0x60;
    } else {
        dx = projectedX - centerX;
        deltaY = projectedY - centerY;
        screenX =
            GetFixed12Whole(MulFixed12NoRound(pairSecondScaled, dx) - MulFixed12NoRound(pairFirstScaled, deltaY)) +
            0x80;
        screenY =
            GetFixed12Whole(MulFixed12NoRound(pairFirstScaled, dx) + MulFixed12NoRound(pairSecondScaled, deltaY)) +
            0x60;
    }
    if (screenX > -32 && screenX < 0x120 && screenY > -32 && screenY < 0xe0) {
        out->mFirst = screenX;
        out->mSecond = screenY;
        return TRUE;
    }
    out->mFirst = screenX;
    out->mSecond = screenY;
    return FALSE;
}

void UpdateRaceHudSubScreenCenter(RaceHudSubScreenBgAffine *out) {
    IntPair courseMin = gRaceHudSubScreenProjection->mCourseMin;
    Vec3 pos;
    float wholePart;

    if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
        pos = gRaceHudSubScreenProjection->mScrollPosition;
    } else {
        GetKartPosFromPosSourceCopy(&pos, GetFollowedKartOrEntryIndex());
    }
    if (GetRaceHudSubScreenState() == RACE_HUD_SUB_SCREEN_MAP_VIEW) {
        pos = GetCourseMapSubScreenView()->mPos;
    }
    gRaceHudSubScreenProjection->mCenter.mFirst =
        MulFixed12NoRound(0x200000, MulFx64c(pos.x - courseMin.mFirst, gRaceHudSubScreenProjection->mCourseInverseX));
    gRaceHudSubScreenProjection->mCenter.mSecond =
        MulFixed12NoRound(0x200000, MulFx64c(pos.z - courseMin.mSecond, gRaceHudSubScreenProjection->mCourseInverseZ));
    gRaceHudSubScreenProjection->mCenterWhole.mFirst = GetFixed12Whole(gRaceHudSubScreenProjection->mCenter.mFirst);
    out->mCenterX = gRaceHudSubScreenProjection->mCenterWhole.mFirst;
    gRaceHudSubScreenProjection->mCenterWhole.mSecond = GetFixed12Whole(gRaceHudSubScreenProjection->mCenter.mSecond);
    out->mCenterY = gRaceHudSubScreenProjection->mCenterWhole.mSecond;
    out->mX1 = out->mCenterX - 0x80;
    out->mY1 = out->mCenterY - 0x60;
    if (gRaceHudSubScreenProjection->mCenterWhole.mFirst > 0) {
        wholePart = 0.5f + TO_FIXED12(gRaceHudSubScreenProjection->mCenterWhole.mFirst);
    } else {
        wholePart = TO_FIXED12(gRaceHudSubScreenProjection->mCenterWhole.mFirst) - 0.5f;
    }
    gRaceHudSubScreenProjection->mCenterRemainderX = gRaceHudSubScreenProjection->mCenter.mFirst - (s32) wholePart;
    if (gRaceHudSubScreenProjection->mCenterWhole.mSecond > 0) {
        wholePart = 0.5f + TO_FIXED12(gRaceHudSubScreenProjection->mCenterWhole.mSecond);
    } else {
        wholePart = TO_FIXED12(gRaceHudSubScreenProjection->mCenterWhole.mSecond) - 0.5f;
    }
    gRaceHudSubScreenProjection->mCenterRemainderY = gRaceHudSubScreenProjection->mCenter.mSecond - (s32) wholePart;
}

void UpdateRaceHudSubScreenBg3Center(RaceHudSubScreenBgAffine *out) {
    IntPair bg3Min = gRaceHudSubScreenProjection->mBg3Min;
    Vec3 pos;

    if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
        pos = gRaceHudSubScreenProjection->mScrollPosition;
    } else {
        GetKartPosFromPosSourceCopy(&pos, GetFollowedKartOrEntryIndex());
    }
    if (GetRaceHudSubScreenState() == RACE_HUD_SUB_SCREEN_MAP_VIEW) {
        pos = GetCourseMapSubScreenView()->mPos;
    }
    out->mCenterX = GetFixed12Whole(
        MulFixed12NoRound(0x200000, MulFx64c(pos.x - bg3Min.mFirst, gRaceHudSubScreenProjection->mBg3InverseX)));
    out->mCenterY = GetFixed12Whole(
        MulFixed12NoRound(0x200000, MulFx64c(pos.z - bg3Min.mSecond, gRaceHudSubScreenProjection->mBg3InverseZ)));
    out->mX1 = out->mCenterX - 0x80;
    out->mY1 = out->mCenterY - 0x60;
}

CourseMapSubScreenView *GetCourseMapSubScreenView(void) {
    return gCourseMap->mSubScreenView;
}

s32 MulFx64c(s32 value, s64 factor) {
    return (factor * value + 0x80000000) >> 32;
}

void UpdateRaceHudSubScreenBg3CenterByFrames(RaceHudSubScreenBgAffine *out) {
    IntPair bg3Min = gRaceHudSubScreenProjection->mBg3Min;
    IntPair bg3Max = gRaceHudSubScreenProjection->mBg3Max;
    Vec3 pos;
    s32 framesQuotient;
    s32 spanX;
    s32 spanZ;
    s32 offsetX;
    s32 offsetZ;

    if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
        pos = gRaceHudSubScreenProjection->mScrollPosition;
    } else {
        GetKartPosFromPosSourceCopy(&pos, GetFollowedKartOrEntryIndex());
    }
    if (GetRaceHudSubScreenState() == RACE_HUD_SUB_SCREEN_MAP_VIEW) {
        pos = GetCourseMapSubScreenView()->mPos;
    }
    spanX = bg3Max.mFirst - bg3Min.mFirst;
    spanZ = bg3Max.mSecond - bg3Min.mSecond;
    framesQuotient = GetRaceHudUpdateFrames() / 32;
    offsetX = spanX * framesQuotient;
    offsetZ = spanZ * framesQuotient;
    pos.x -= offsetX / 512;
    pos.z -= offsetZ / 512;
    out->mCenterX = GetFixed12Whole(
        MulFixed12NoRound(0x200000, MulFx64c(pos.x - bg3Min.mFirst, gRaceHudSubScreenProjection->mBg3InverseX)));
    out->mCenterY = GetFixed12Whole(
        MulFixed12NoRound(0x200000, MulFx64c(pos.z - bg3Min.mSecond, gRaceHudSubScreenProjection->mBg3InverseZ)));
    out->mX1 = out->mCenterX - 0x80;
    out->mY1 = out->mCenterY - 0x60;
}

u16 RaceHudSubScreenGetSlotDownBits(InputSlot *inputSlot, s32 mask) {
    return inputSlot->mBits & mask;
}

u16 RaceHudSubScreenGetDownBits(s32 slotIndex, s32 mask) {
    return RaceHudSubScreenGetSlotDownBits(&gInputSlots[slotIndex], mask);
}

void UpdateRaceHudSubScreenScroll(void) {
    IntPair scrollMin;
    IntPair scrollMax;
    Vec3 target;
    Vec3 dir;

    GetRaceHudSubScreenScrollLimits(&scrollMin, &scrollMax);
    if (RaceHudSubScreenGetDownBits(GetPadInputSlot(), PAD_KEY_LEFT) != 0) {
        if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
            gRaceHudSubScreenProjection->mScrollPosition.x -= RACE_HUD_SUB_SCREEN_SCROLL_STEP;
            if (gRaceHudSubScreenProjection->mScrollPosition.x < scrollMin.mFirst) {
                gRaceHudSubScreenProjection->mScrollPosition.x = scrollMin.mFirst;
            }
        } else {
            GetKartPosFromPosSourceCopy(&gRaceHudSubScreenProjection->mScrollPosition, GetFollowedKartOrEntryIndex());
        }
        gRaceHudSubScreenProjection->mScrollTimer = RACE_HUD_SUB_SCREEN_SCROLL_TIMER_START;
    }
    if (RaceHudSubScreenGetDownBits(GetPadInputSlot(), PAD_KEY_RIGHT) != 0) {
        if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
            gRaceHudSubScreenProjection->mScrollPosition.x += RACE_HUD_SUB_SCREEN_SCROLL_STEP;
            if (gRaceHudSubScreenProjection->mScrollPosition.x > scrollMax.mFirst) {
                gRaceHudSubScreenProjection->mScrollPosition.x = scrollMax.mFirst;
            }
        } else {
            GetKartPosFromPosSourceCopy(&gRaceHudSubScreenProjection->mScrollPosition, GetFollowedKartOrEntryIndex());
        }
        gRaceHudSubScreenProjection->mScrollTimer = RACE_HUD_SUB_SCREEN_SCROLL_TIMER_START;
    }
    if (RaceHudSubScreenGetDownBits(GetPadInputSlot(), PAD_KEY_UP) != 0) {
        if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
            gRaceHudSubScreenProjection->mScrollPosition.z -= RACE_HUD_SUB_SCREEN_SCROLL_STEP;
            if (gRaceHudSubScreenProjection->mScrollPosition.z < scrollMin.mSecond) {
                gRaceHudSubScreenProjection->mScrollPosition.z = scrollMin.mSecond;
            }
        } else {
            GetKartPosFromPosSourceCopy(&gRaceHudSubScreenProjection->mScrollPosition, GetFollowedKartOrEntryIndex());
        }
        gRaceHudSubScreenProjection->mScrollTimer = RACE_HUD_SUB_SCREEN_SCROLL_TIMER_START;
    }
    if (RaceHudSubScreenGetDownBits(GetPadInputSlot(), PAD_KEY_DOWN) != 0) {
        if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
            gRaceHudSubScreenProjection->mScrollPosition.z += RACE_HUD_SUB_SCREEN_SCROLL_STEP;
            if (gRaceHudSubScreenProjection->mScrollPosition.z > scrollMax.mSecond) {
                gRaceHudSubScreenProjection->mScrollPosition.z = scrollMax.mSecond;
            }
        } else {
            GetKartPosFromPosSourceCopy(&gRaceHudSubScreenProjection->mScrollPosition, GetFollowedKartOrEntryIndex());
        }
        gRaceHudSubScreenProjection->mScrollTimer = RACE_HUD_SUB_SCREEN_SCROLL_TIMER_START;
    }
    if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
        gRaceHudSubScreenProjection->mScrollTimer--;
        if (gRaceHudSubScreenProjection->mScrollTimer < RACE_HUD_SUB_SCREEN_SCROLL_TIMER_FOLLOW) {
            GetKartPosFromPosSourceCopy(&target, GetFollowedKartOrEntryIndex());
            gRaceHudSubScreenProjection->mScrollTimer = RACE_HUD_SUB_SCREEN_SCROLL_TIMER_FOLLOW;
            VEC_Subtract(&target, &gRaceHudSubScreenProjection->mScrollPosition, &dir);
            Vec3NormalizeAndGetLengthUnchecked(&dir, &dir);
            VEC_MultAdd(RACE_HUD_SUB_SCREEN_SCROLL_STEP, &dir, &gRaceHudSubScreenProjection->mScrollPosition,
                        &gRaceHudSubScreenProjection->mScrollPosition);
            if (GetFixed12Whole(target.x - gRaceHudSubScreenProjection->mScrollPosition.x) *
                        GetFixed12Whole(target.x - gRaceHudSubScreenProjection->mScrollPosition.x) +
                    GetFixed12Whole(target.z - gRaceHudSubScreenProjection->mScrollPosition.z) *
                        GetFixed12Whole(target.z - gRaceHudSubScreenProjection->mScrollPosition.z) <
                GetFixed12Whole(RACE_HUD_SUB_SCREEN_SCROLL_STEP) * GetFixed12Whole(RACE_HUD_SUB_SCREEN_SCROLL_STEP)) {
                gRaceHudSubScreenProjection->mScrollPosition = target;
                gRaceHudSubScreenProjection->mScrollTimer = 0;
            }
        }
    }
    if (gRaceHudSubScreenProjection->mScrollPosition.x < scrollMin.mFirst) {
        gRaceHudSubScreenProjection->mScrollPosition.x = scrollMin.mFirst;
    }
    if (gRaceHudSubScreenProjection->mScrollPosition.x > scrollMax.mFirst) {
        gRaceHudSubScreenProjection->mScrollPosition.x = scrollMax.mFirst;
    }
    if (gRaceHudSubScreenProjection->mScrollPosition.z < scrollMin.mSecond) {
        gRaceHudSubScreenProjection->mScrollPosition.z = scrollMin.mSecond;
    }
    if (gRaceHudSubScreenProjection->mScrollPosition.z > scrollMax.mSecond) {
        gRaceHudSubScreenProjection->mScrollPosition.z = scrollMax.mSecond;
    }
}

s32 RaceHudSubScreenFX_CosIdx(s32 angle) {
    return FX_CosIdx(angle);
}

s32 RaceHudSubScreenFX_SinIdx(s32 angle) {
    return FX_SinIdx(angle);
}

s32 GetFixed12Whole(s32 value) {
    return FROM_FIXED12(value);
}

s32 RaceHudSubScreenGetCurrentMirrorMode(void) {
    return gRaceSetup->mMirrorMode;
}

void UpdateRaceHudSubScreenProjectionAndBgAffine(RaceHudSubScreenBgAffine *bgAffines, s32 scale) {
    s32 angle = GetSubScreenAngleAndClearScrollTimer();
    s32 secondByInverseScale;
    s32 firstByInverseScale;

    gRaceHudSubScreenProjection->mAnglePairSecond = RaceHudSubScreenFX_CosIdx(angle);
    gRaceHudSubScreenProjection->mAnglePairFirst = RaceHudSubScreenFX_SinIdx(angle);
    gRaceHudSubScreenProjection->mAnglePairSecondScaled =
        MulFixed12NoRound(gRaceHudSubScreenProjection->mAnglePairSecond, scale);
    gRaceHudSubScreenProjection->mAnglePairFirstScaled =
        MulFixed12NoRound(gRaceHudSubScreenProjection->mAnglePairFirst, scale);
    if (GetRaceHudSubScreenState() == RACE_HUD_SUB_SCREEN_MAP_FIXED_SCROLL) {
        UpdateRaceHudSubScreenScroll();
    }
    gRaceHudSubScreenProjection->mHalfSize = GetFixed12Whole(FX_Div(0xb0000, scale));
    scale = FX_Inv(scale);
    secondByInverseScale = MulFixed12NoRound(gRaceHudSubScreenProjection->mAnglePairSecond, scale);
    firstByInverseScale = MulFixed12NoRound(gRaceHudSubScreenProjection->mAnglePairFirst, scale);
    if (RaceHudSubScreenGetCurrentMirrorMode() != 0) {
        bgAffines[0].mMatrix0 = bgAffines[1].mMatrix0 = -secondByInverseScale;
        bgAffines[0].mMatrix2 = bgAffines[1].mMatrix2 = firstByInverseScale;
    } else {
        bgAffines[0].mMatrix0 = bgAffines[1].mMatrix0 = secondByInverseScale;
        bgAffines[0].mMatrix2 = bgAffines[1].mMatrix2 = -firstByInverseScale;
    }
    bgAffines[0].mMatrix1 = bgAffines[1].mMatrix1 = firstByInverseScale;
    bgAffines[0].mMatrix3 = bgAffines[1].mMatrix3 = secondByInverseScale;
    UpdateRaceHudSubScreenCenter(bgAffines);
    switch (RaceHudSubScreenGetCurrentCourseId()) {
        default:
            bgAffines[1] = bgAffines[0];
            break;
        case COURSE_ID_OLD_LUIGI_GC:
        case COURSE_ID_MANSION:
        case COURSE_ID_CROSS:
        case COURSE_ID_TOWN:
        case COURSE_ID_SNOW:
        case COURSE_ID_PINBALL:
        case COURSE_ID_OLD_KINOKO_GC:
            UpdateRaceHudSubScreenBg3Center(&bgAffines[1]);
            break;
        case COURSE_ID_MR_STAGE1:
        case COURSE_ID_MR_STAGE3:
            UpdateRaceHudSubScreenBg3CenterByFrames(&bgAffines[1]);
            break;
    }
}

s32 MulFixed12NoRound(s32 multiplicand, s32 multiplier) {
    return MUL_FIXED12_NO_ROUND(multiplicand, multiplier);
}
