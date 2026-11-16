#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"

#include "code_02147cd8.h"
#include "Main/Unknown/code_020b4dc4.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Item/ItemGesso.h"
#include "code_02148538.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020b65f0.h"
#include "Main/Unknown/code_020b681c.h"
#include "Main/Unknown/code_020b6800.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02077bc0.h"

const Vec3 data_02156874 = {0, 0, 0};

void m2d_init(void) {
    UnkPair020b502c state0Min;
    UnkPair020b502c state0Max;
    UnkPair020b502c courseMin;
    UnkPair020b502c courseMax;
    UnkPair020b502c bg3Min;
    UnkPair020b502c bg3Max;

    gMap2DStatus = heap_alloc(m2d_proc_getCurrentHeap(), 0x9c);
    gMap2DStatus->mCenter.field0 = 0;
    gMap2DStatus->mCenter.field4 = 0;
    gMap2DStatus->mCenterWhole.field0 = 0;
    gMap2DStatus->mCenterWhole.field4 = 0;
    gMap2DStatus->mHalfSize = 0;
    gMap2DStatus->mAnglePairSecond = 0;
    gMap2DStatus->mAnglePairFirst = 0;
    gMap2DStatus->mAnglePairSecondScaled = 0;
    gMap2DStatus->mAnglePairFirstScaled = 0;
    GetGlobalMapScale(&state0Min, &state0Max);
    gMap2DStatus->mState0Min = state0Min;
    gMap2DStatus->mState0Max = state0Max;
    gMap2DStatus->mState0InverseX = FX_InvFx64c(state0Max.field0 - state0Min.field0);
    gMap2DStatus->mState0InverseZ = FX_InvFx64c(state0Max.field4 - state0Min.field4);
    GetLocalMapScale(&courseMin, &courseMax);
    gMap2DStatus->mCourseMin = courseMin;
    gMap2DStatus->mCourseMax = courseMax;
    gMap2DStatus->mCourseInverseX = FX_InvFx64c(courseMax.field0 - courseMin.field0);
    gMap2DStatus->mCourseInverseZ = FX_InvFx64c(courseMax.field4 - courseMin.field4);
    gMap2DStatus->field28 =
        lmap_20B502C(FX_Div(courseMax.field0 - courseMin.field0, 0x200000), 0xb0000);
    Map_20B681C(&bg3Min, &bg3Max);
    gMap2DStatus->mBg3Min = bg3Min;
    gMap2DStatus->mBg3Max = bg3Max;
    gMap2DStatus->mBg3InverseX = FX_InvFx64c(bg3Max.field0 - bg3Min.field0);
    gMap2DStatus->mBg3InverseZ = FX_InvFx64c(bg3Max.field4 - bg3Min.field4);
    gMap2DStatus->mScrollTimer = 0;
    gMap2DStatus->mScrollPosition = data_02156874;
}

u32 m2d_finalize(void) {
    u32 pointerAddress;
    u32 nullValue;
    pointerAddress = (u32) &gMap2DStatus;
    nullValue = 0u;
    *(u32 *) ((pointerAddress) + (0)) = nullValue;
    return pointerAddress;
}

BOOL IsCourseWithMap2DLocal3(void) {
    BOOL result = FALSE;

    switch (m2d_race_getCurrentCourse()) {
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

BOOL IsCourseWithSubBg3CntBit13(void) {
    BOOL result = FALSE;

    switch (m2d_race_getCurrentCourse()) {
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
u16 m2d_20B6368(void) {
    u16 angle = 0;
    Camera *camera;
    s32 a;

    switch (r2d_getMapMode()) {
        case 1:
            if (m2d_race_getCurrentRaceMode() == MODE_BATTLE) {
                camera = race_getCamera();
            } else {
                camera = cam_getPlayerCamera();
            }
            a = FX_Atan2Idx(camera->mViewMatrix.field0[2].z, camera->mViewMatrix.field0[0].z);
            angle = (0x14000 - a) % 0x10000;
            gMap2DStatus->mScrollTimer = 0;
            break;
        case 2:
            angle = 0;
            break;
        case 3:
            a = GetFixed12Whole(GetKTP2Pointer()->field10);
            angle = (a << 16) / 360 + 0x8000;
            break;
        default:
            break;
    }
    return angle;
}

u16 m2d_20B6338(s32 kartIndex) {
    return (0x18000 - driver_getYRot(kartIndex)) % 0x10000;
}

void RefreshGlobalMapPosition(s32 kartIndex, UnkPair020b502c *out) {
    UnkPair020b502c state0Min = gMap2DStatus->mState0Min;
    Vec3 kartPos;

    driver_getPosition(&kartPos, (u8) kartIndex);
    switch (m2d_race_getCurrentCourse()) {
        case COURSE_ID_OLD_MOMO_64:
        case COURSE_ID_CROSS:
        case COURSE_ID_OLD_KINOKO_GC:
            if (GetIsMirrorMode() != 0) {
                out->field0 = GetFixed12Whole(
                                   lmap_20B502C(0x80000, MulFx64c(state0Min.field0 - kartPos.z,
                                                                       gMap2DStatus->mState0InverseX))) +
                               0xf8;
            } else {
                out->field0 = GetFixed12Whole(
                                   lmap_20B502C(0x80000, MulFx64c(kartPos.z - state0Min.field0,
                                                                       gMap2DStatus->mState0InverseX))) +
                               0x78;
            }
            out->field4 =
                GetFixed12Whole(lmap_20B502C(
                    0x98000, MulFx64c(kartPos.x - state0Min.field4, gMap2DStatus->mState0InverseZ))) +
                0x28;
            break;
        case COURSE_ID_BANK:
            if (GetIsMirrorMode() != 0) {
                out->field0 = GetFixed12Whole(
                                   lmap_20B502C(0x80000, MulFx64c(state0Min.field0 - kartPos.z,
                                                                       gMap2DStatus->mState0InverseX))) +
                               0xf8;
            } else {
                out->field0 = GetFixed12Whole(
                                   lmap_20B502C(0x80000, MulFx64c(kartPos.z - state0Min.field0,
                                                                       gMap2DStatus->mState0InverseX))) +
                               0x78;
            }
            out->field4 =
                GetFixed12Whole(lmap_20B502C(
                    0x98000, MulFx64c(kartPos.x - state0Min.field4, gMap2DStatus->mState0InverseZ))) +
                0x28;
            break;
        default:
            if (GetIsMirrorMode() != 0) {
                out->field0 = GetFixed12Whole(
                                   lmap_20B502C(0x80000, MulFx64c(state0Min.field0 - kartPos.x,
                                                                       gMap2DStatus->mState0InverseX))) +
                               0xf8;
            } else {
                out->field0 = GetFixed12Whole(
                                   lmap_20B502C(0x80000, MulFx64c(kartPos.x - state0Min.field0,
                                                                       gMap2DStatus->mState0InverseX))) +
                               0x78;
            }
            out->field4 =
                GetFixed12Whole(lmap_20B502C(
                    0x98000, MulFx64c(kartPos.z - state0Min.field4, gMap2DStatus->mState0InverseZ))) +
                0x28;
            break;
    }
}

void ComputeRaceHudSubScreenCoursePosition(const Vec3 *pos, UnkPair020b502c *out) {
    UnkPair020b502c courseMin = gMap2DStatus->mCourseMin;

    out->field0 = GetFixed12Whole(lmap_20B502C(
        0x200000, MulFx64c(pos->x - courseMin.field0, gMap2DStatus->mCourseInverseX)));
    out->field4 = GetFixed12Whole(lmap_20B502C(
        0x200000, MulFx64c(pos->z - courseMin.field4, gMap2DStatus->mCourseInverseZ)));
}

BOOL IsRaceHudSubScreenPairNearCenter(const UnkPair020b502c *position) {
    UnkPair020b502c centerWhole = gMap2DStatus->mCenterWhole;
    s32 halfSize = gMap2DStatus->mHalfSize;

    if (position->field0 - halfSize < centerWhole.field0 && centerWhole.field0 < position->field0 + halfSize &&
        position->field4 - halfSize < centerWhole.field4 && centerWhole.field4 < position->field4 + halfSize) {
        return TRUE;
    }
    return FALSE;
}

void ComputeRaceHudSubScreenKartPosition(s32 kartIndex, UnkPair020b502c *out, s32 v1) {
    UnkPair020b502c center = gMap2DStatus->mCenter;
    s32 centerY = center.field4;
    s32 pairSecondScaled = gMap2DStatus->mAnglePairSecondScaled;
    s32 pairFirstScaled = gMap2DStatus->mAnglePairFirstScaled;
    UnkPair020b502c courseMin = gMap2DStatus->mCourseMin;
    Vec3 kartPos;
    s32 projectedX;
    s32 projectedY;
    s32 dx;
    s32 dy;

    driver_getPosition(&kartPos, (u8) kartIndex);
    projectedX = lmap_20B502C(
        0x200000, MulFx64c(kartPos.x - courseMin.field0, gMap2DStatus->mCourseInverseX));
    projectedY = lmap_20B502C(
        0x200000, MulFx64c(kartPos.z - courseMin.field4, gMap2DStatus->mCourseInverseZ));
    if (GetIsMirrorMode() != 0) {
        dy = projectedY - centerY;
        dx = projectedX - center.field0;
        out->field0 =
            GetFixed12Whole(lmap_20B502C(-pairSecondScaled, dx) + lmap_20B502C(pairFirstScaled, dy)) + 0x80;
        out->field4 =
            GetFixed12Whole(lmap_20B502C(pairFirstScaled, dx) + lmap_20B502C(pairSecondScaled, dy)) + 0x60;
    } else {
        dx = projectedX - center.field0;
        dy = projectedY - centerY;
        out->field0 =
            GetFixed12Whole(lmap_20B502C(pairSecondScaled, dx) - lmap_20B502C(pairFirstScaled, dy)) + 0x80;
        out->field4 =
            GetFixed12Whole(lmap_20B502C(pairFirstScaled, dx) + lmap_20B502C(pairSecondScaled, dy)) + 0x60;
    }
}

static inline s32 ClearFixed12Fraction(s32 value) {
    float wholePart;

    if (GetFixed12Whole(value) > 0) {
        wholePart = 0.5f + (GetFixed12Whole(value) << 12);
    } else {
        wholePart = (GetFixed12Whole(value) << 12) - 0.5f;
    }
    return wholePart;
}

BOOL lmap_20B5AE8(const Vec3 *pos, UnkPair020b502c *out, s32 unk, s32 requireNearCenter,
                                     s32 exactCenter) {
    UnkPair020b502c center = gMap2DStatus->mCenter;
    s32 pairSecondScaled = gMap2DStatus->mAnglePairSecondScaled;
    s32 pairFirstScaled = gMap2DStatus->mAnglePairFirstScaled;
    UnkPair020b502c courseMin = gMap2DStatus->mCourseMin;
    s32 centerX;
    s32 centerY;
    s32 dx;
    s32 projectedX;
    s32 projectedY;
    s32 dy;
    s32 e;
    s32 screenX;
    s32 screenY;
    UnkPair020b502c centerWhole;
    s32 halfSize;
    s32 wholeX;
    s32 wholeY;

    projectedX =
        lmap_20B502C(0x200000, MulFx64c(pos->x - courseMin.field0, gMap2DStatus->mCourseInverseX));
    projectedY =
        lmap_20B502C(0x200000, MulFx64c(pos->z - courseMin.field4, gMap2DStatus->mCourseInverseZ));
    if (requireNearCenter != 0) {
        centerWhole = gMap2DStatus->mCenterWhole;
        halfSize = gMap2DStatus->mHalfSize;
        wholeX = GetFixed12Whole(projectedX);
        wholeY = GetFixed12Whole(projectedY);

        if (wholeX - halfSize >= centerWhole.field0 || centerWhole.field0 >= wholeX + halfSize ||
            wholeY - halfSize >= centerWhole.field4 || centerWhole.field4 >= wholeY + halfSize) {
            return FALSE;
        }
    }
    if (exactCenter != 0) {
        centerX = center.field0;
        centerY = center.field4;
    } else {
        centerX = ClearFixed12Fraction(center.field0);
        centerY = ClearFixed12Fraction(center.field4);
    }
    if (GetIsMirrorMode() != 0) {
        dx = projectedX - centerX;
        dy = projectedY - centerY;
        screenX =
            GetFixed12Whole(lmap_20B502C(-pairSecondScaled, dx) + lmap_20B502C(pairFirstScaled, dy)) + 0x80;
        screenY =
            GetFixed12Whole(lmap_20B502C(pairFirstScaled, dx) + lmap_20B502C(pairSecondScaled, dy)) + 0x60;
    } else {
        dx = projectedX - centerX;
        e = projectedY - centerY;
        screenX =
            GetFixed12Whole(lmap_20B502C(pairSecondScaled, dx) - lmap_20B502C(pairFirstScaled, e)) + 0x80;
        screenY =
            GetFixed12Whole(lmap_20B502C(pairFirstScaled, dx) + lmap_20B502C(pairSecondScaled, e)) + 0x60;
    }
    if (screenX > -32 && screenX < 0x120 && screenY > -32 && screenY < 0xe0) {
        out->field0 = screenX;
        out->field4 = screenY;
        return TRUE;
    }
    out->field0 = screenX;
    out->field4 = screenY;
    return FALSE;
}

void RefreshLocalMapPosition(RaceHudSubScreenBgAffine *out) {
    UnkPair020b502c courseMin = gMap2DStatus->mCourseMin;
    Vec3 pos;
    float wholePart;

    if (gMap2DStatus->mScrollTimer != 0) {
        pos = gMap2DStatus->mScrollPosition;
    } else {
        GetKartPosFromPosSourceCopy(&pos, Race_GetPlayerId());
    }
    if (r2d_getMapMode() == 3) {
        pos = GetKTP2Pointer()->field0;
    }
    gMap2DStatus->mCenter.field0 =
        lmap_20B502C(0x200000, MulFx64c(pos.x - courseMin.field0, gMap2DStatus->mCourseInverseX));
    gMap2DStatus->mCenter.field4 =
        lmap_20B502C(0x200000, MulFx64c(pos.z - courseMin.field4, gMap2DStatus->mCourseInverseZ));
    gMap2DStatus->mCenterWhole.field0 = GetFixed12Whole(gMap2DStatus->mCenter.field0);
    out->mCenterX = gMap2DStatus->mCenterWhole.field0;
    gMap2DStatus->mCenterWhole.field4 = GetFixed12Whole(gMap2DStatus->mCenter.field4);
    out->mCenterY = gMap2DStatus->mCenterWhole.field4;
    out->mX1 = out->mCenterX - 0x80;
    out->mY1 = out->mCenterY - 0x60;
    if (gMap2DStatus->mCenterWhole.field0 > 0) {
        wholePart = 0.5f + (gMap2DStatus->mCenterWhole.field0 << 12);
    } else {
        wholePart = (gMap2DStatus->mCenterWhole.field0 << 12) - 0.5f;
    }
    gMap2DStatus->mCenterRemainderX = gMap2DStatus->mCenter.field0 - (s32) wholePart;
    if (gMap2DStatus->mCenterWhole.field4 > 0) {
        wholePart = 0.5f + (gMap2DStatus->mCenterWhole.field4 << 12);
    } else {
        wholePart = (gMap2DStatus->mCenterWhole.field4 << 12) - 0.5f;
    }
    gMap2DStatus->mCenterRemainderY = gMap2DStatus->mCenter.field4 - (s32) wholePart;
}

void UpdateRaceHudSubScreenBg3Center(RaceHudSubScreenBgAffine *out) {
    UnkPair020b502c bg3Min = gMap2DStatus->mBg3Min;
    Vec3 pos;

    if (gMap2DStatus->mScrollTimer != 0) {
        pos = gMap2DStatus->mScrollPosition;
    } else {
        GetKartPosFromPosSourceCopy(&pos, Race_GetPlayerId());
    }
    if (r2d_getMapMode() == 3) {
        pos = GetKTP2Pointer()->field0;
    }
    out->mCenterX = GetFixed12Whole(
        lmap_20B502C(0x200000, MulFx64c(pos.x - bg3Min.field0, gMap2DStatus->mBg3InverseX)));
    out->mCenterY = GetFixed12Whole(
        lmap_20B502C(0x200000, MulFx64c(pos.z - bg3Min.field4, gMap2DStatus->mBg3InverseZ)));
    out->mX1 = out->mCenterX - 0x80;
    out->mY1 = out->mCenterY - 0x60;
}

Unk020b57e4 *GetKTP2Pointer(void) {
    return gMapData->field2C;
}

s32 MulFx64c(s32 value, s64 factor) {
    return (factor * value + 0x80000000) >> 32;
}

void UpdateRaceHudSubScreenBg3CenterByFrames(RaceHudSubScreenBgAffine *out) {
    UnkPair020b502c bg3Min = gMap2DStatus->mBg3Min;
    UnkPair020b502c bg3Max = gMap2DStatus->mBg3Max;
    Vec3 pos;
    s32 framesQuotient;
    s32 spanX;
    s32 spanZ;
    s32 offsetX;
    s32 offsetZ;

    if (gMap2DStatus->mScrollTimer != 0) {
        pos = gMap2DStatus->mScrollPosition;
    } else {
        GetKartPosFromPosSourceCopy(&pos, Race_GetPlayerId());
    }
    if (r2d_getMapMode() == 3) {
        pos = GetKTP2Pointer()->field0;
    }
    spanX = bg3Max.field0 - bg3Min.field0;
    spanZ = bg3Max.field4 - bg3Min.field4;
    framesQuotient = r2d_20B1DD0() / 32;
    offsetX = spanX * framesQuotient;
    offsetZ = spanZ * framesQuotient;
    pos.x -= offsetX / 512;
    pos.z -= offsetZ / 512;
    out->mCenterX = GetFixed12Whole(
        lmap_20B502C(0x200000, MulFx64c(pos.x - bg3Min.field0, gMap2DStatus->mBg3InverseX)));
    out->mCenterY = GetFixed12Whole(
        lmap_20B502C(0x200000, MulFx64c(pos.z - bg3Min.field4, gMap2DStatus->mBg3InverseZ)));
    out->mX1 = out->mCenterX - 0x80;
    out->mY1 = out->mCenterY - 0x60;
}

u16 RaceHudSubScreenGetSlotDownBits(InputSlot *inputSlot, s32 mask) {
    return inputSlot->mBits & mask;
}

u16 RaceHudSubScreenGetDownBits(s32 slotIndex, s32 mask) {
    return RaceHudSubScreenGetSlotDownBits(&gInputUnits[slotIndex], mask);
}

void UpdateRaceHudSubScreenScroll(void) {
    UnkPair020b502c scrollMin;
    UnkPair020b502c scrollMax;
    Vec3 target;
    Vec3 dir;

    GetRaceHudSubScreenScrollLimits(&scrollMin, &scrollMax);
    if (RaceHudSubScreenGetDownBits(input_getDirectInputUnitId(), PAD_KEY_LEFT) != 0) {
        if (gMap2DStatus->mScrollTimer != 0) {
            gMap2DStatus->mScrollPosition.x -= 0xa000;
            if (gMap2DStatus->mScrollPosition.x < scrollMin.field0) {
                gMap2DStatus->mScrollPosition.x = scrollMin.field0;
            }
        } else {
            GetKartPosFromPosSourceCopy(&gMap2DStatus->mScrollPosition, Race_GetPlayerId());
        }
        gMap2DStatus->mScrollTimer = 600;
    }
    if (RaceHudSubScreenGetDownBits(input_getDirectInputUnitId(), PAD_KEY_RIGHT) != 0) {
        if (gMap2DStatus->mScrollTimer != 0) {
            gMap2DStatus->mScrollPosition.x += 0xa000;
            if (gMap2DStatus->mScrollPosition.x > scrollMax.field0) {
                gMap2DStatus->mScrollPosition.x = scrollMax.field0;
            }
        } else {
            GetKartPosFromPosSourceCopy(&gMap2DStatus->mScrollPosition, Race_GetPlayerId());
        }
        gMap2DStatus->mScrollTimer = 600;
    }
    if (RaceHudSubScreenGetDownBits(input_getDirectInputUnitId(), PAD_KEY_UP) != 0) {
        if (gMap2DStatus->mScrollTimer != 0) {
            gMap2DStatus->mScrollPosition.z -= 0xa000;
            if (gMap2DStatus->mScrollPosition.z < scrollMin.field4) {
                gMap2DStatus->mScrollPosition.z = scrollMin.field4;
            }
        } else {
            GetKartPosFromPosSourceCopy(&gMap2DStatus->mScrollPosition, Race_GetPlayerId());
        }
        gMap2DStatus->mScrollTimer = 600;
    }
    if (RaceHudSubScreenGetDownBits(input_getDirectInputUnitId(), PAD_KEY_DOWN) != 0) {
        if (gMap2DStatus->mScrollTimer != 0) {
            gMap2DStatus->mScrollPosition.z += 0xa000;
            if (gMap2DStatus->mScrollPosition.z > scrollMax.field4) {
                gMap2DStatus->mScrollPosition.z = scrollMax.field4;
            }
        } else {
            GetKartPosFromPosSourceCopy(&gMap2DStatus->mScrollPosition, Race_GetPlayerId());
        }
        gMap2DStatus->mScrollTimer = 600;
    }
    if (gMap2DStatus->mScrollTimer != 0) {
        gMap2DStatus->mScrollTimer--;
        if (gMap2DStatus->mScrollTimer < 300) {
            GetKartPosFromPosSourceCopy(&target, Race_GetPlayerId());
            gMap2DStatus->mScrollTimer = 300;
            VEC_Subtract(&target, &gMap2DStatus->mScrollPosition, &dir);
            vec_normalize(&dir, &dir);
            VEC_MultAdd(0xa000, &dir, &gMap2DStatus->mScrollPosition,
                        &gMap2DStatus->mScrollPosition);
            if (GetFixed12Whole(target.x - gMap2DStatus->mScrollPosition.x) *
                        GetFixed12Whole(target.x - gMap2DStatus->mScrollPosition.x) +
                    GetFixed12Whole(target.z - gMap2DStatus->mScrollPosition.z) *
                        GetFixed12Whole(target.z - gMap2DStatus->mScrollPosition.z) <
                GetFixed12Whole(0xa000) * GetFixed12Whole(0xa000)) {
                gMap2DStatus->mScrollPosition = target;
                gMap2DStatus->mScrollTimer = 0;
            }
        }
    }
    if (gMap2DStatus->mScrollPosition.x < scrollMin.field0) {
        gMap2DStatus->mScrollPosition.x = scrollMin.field0;
    }
    if (gMap2DStatus->mScrollPosition.x > scrollMax.field0) {
        gMap2DStatus->mScrollPosition.x = scrollMax.field0;
    }
    if (gMap2DStatus->mScrollPosition.z < scrollMin.field4) {
        gMap2DStatus->mScrollPosition.z = scrollMin.field4;
    }
    if (gMap2DStatus->mScrollPosition.z > scrollMax.field4) {
        gMap2DStatus->mScrollPosition.z = scrollMax.field4;
    }
}

s32 GetAnglePairSecond(s32 angle) {
    return FX_SinCosTable_[(angle >> 4) * 2 + 1];
}

s32 GetAnglePairFirst(s32 angle) {
    return FX_SinCosTable_[(angle >> 4) * 2];
}

s32 GetFixed12Whole(s32 value) {
    return value >> 12;
}

s32 GetIsMirrorMode(void) {
    return gRaceMultiConfig->mMirrorMode;
}

void RefreshLocalMap(RaceHudSubScreenBgAffine *bgAffines, s32 scale) {
    s32 angle = m2d_20B6368();
    s32 secondByInverseScale;
    s32 firstByInverseScale;

    gMap2DStatus->mAnglePairSecond = GetAnglePairSecond(angle);
    gMap2DStatus->mAnglePairFirst = GetAnglePairFirst(angle);
    gMap2DStatus->mAnglePairSecondScaled =
        lmap_20B502C(gMap2DStatus->mAnglePairSecond, scale);
    gMap2DStatus->mAnglePairFirstScaled =
        lmap_20B502C(gMap2DStatus->mAnglePairFirst, scale);
    if (r2d_getMapMode() == 2) {
        UpdateRaceHudSubScreenScroll();
    }
    gMap2DStatus->mHalfSize = GetFixed12Whole(FX_Div(0xb0000, scale));
    scale = FX_Inv(scale);
    secondByInverseScale = lmap_20B502C(gMap2DStatus->mAnglePairSecond, scale);
    firstByInverseScale = lmap_20B502C(gMap2DStatus->mAnglePairFirst, scale);
    if (GetIsMirrorMode() != 0) {
        bgAffines[0].mMatrix0 = bgAffines[1].mMatrix0 = -secondByInverseScale;
        bgAffines[0].mMatrix2 = bgAffines[1].mMatrix2 = firstByInverseScale;
    } else {
        bgAffines[0].mMatrix0 = bgAffines[1].mMatrix0 = secondByInverseScale;
        bgAffines[0].mMatrix2 = bgAffines[1].mMatrix2 = -firstByInverseScale;
    }
    bgAffines[0].mMatrix1 = bgAffines[1].mMatrix1 = firstByInverseScale;
    bgAffines[0].mMatrix3 = bgAffines[1].mMatrix3 = secondByInverseScale;
    RefreshLocalMapPosition(bgAffines);
    switch (m2d_race_getCurrentCourse()) {
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

s32 lmap_20B502C(s32 multiplicand, s32 multiplier) {
    return ((s64) multiplicand * multiplier) >> 12;
}
