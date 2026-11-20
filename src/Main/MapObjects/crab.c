#include "Main/MapObjects/crab.h"
#include "matrix_3x3_basic.h"

#include "Main/MapObjects/map_object_model_frame.h"
#include "fixed_vector_math.h"
#include "Main/Course/course_map_group_entry.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/MapObjects/bound.h"
#include "Main/Item/item_objects_and_race_progress.h" // ItemObject
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/MapObjects/view_matrix_setters.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/Item/mission_run_koura_effects.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/Kart/karts.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

const u16 gPakkunSpitInitMapObjectFlag = 0x200;
const u16 gCrabLaunchFlag = 1;
MapObjectKindDescriptor gCrabKindDescriptor = {0,
                                               {0, 0},
                                               0x118,
                                               InitCrab,
                                               CreateCrabKindData,
                                               CreateCrabDrawList,
                                               0,
                                               0,
                                               CreateCrabUpdateList};
MapObjectModel *gCrabHand;
MapObjectModel *gCrab;

void InitCrab(Crab *crab) {
    InitGroupFollower(&crab->mFollower, crab->mMapObject.mCourseMapRow, 0);
}

static inline u16 CrabNextRandomBelow(RandomState64 *random, u32 limit) {
    RANDOM_ADVANCE(random);
    if (limit == 0) {
        return RANDOM_HIGH32(random);
    } else {
        return RANDOM_BELOW(random, limit);
    }
}

void StartCrabLaunch(Crab *crab, Vec3 *sourcePosition, Vec3 *sourceDirection, Vec3 *sourceVelocity) {
    Vec3 sideDirection;
    RandomState64 *mapObjectRandom;
    s32 valueX;
    s32 valueZ;

    if (sourcePosition != NULL && sourceDirection != NULL) {
        VEC_Subtract(&crab->mMapObject.mPos, sourcePosition, &sideDirection);
        valueZ = sourceDirection->z;
        valueX = sourceDirection->x;
        if ((s64) sideDirection.z * valueX - (s64) sideDirection.x * valueZ < 0) {
            sideDirection.z = -valueX;
            sideDirection.x = valueZ;
            sideDirection.y = 0;
            crab->mRotateZAnglePerFrame = CRAB_ROTATE_Z_ANGLE_PER_FRAME;
        } else {
            sideDirection.z = valueX;
            sideDirection.x = -valueZ;
            sideDirection.y = 0;
            crab->mRotateZAnglePerFrame = CRAB_ROTATE_Z_ANGLE_PER_FRAME_REVERSE;
        }
        crab->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(sideDirection.x, 0x1800);
        crab->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(sideDirection.y, 0x1800);
        crab->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(sideDirection.z, 0x1800);
    } else {
        mapObjectRandom = GetMapObjectRandom();
        valueZ = CrabNextRandomBelow(mapObjectRandom, 0x10000);
        valueX = FX_CosIdx((u16) valueZ);
        valueX = MUL_FIXED12_NO_ROUND(valueX, 0x1800);
        crab->mMapObject.mPosStep.x = valueX;
        crab->mMapObject.mPosStep.z = valueX;
        mapObjectRandom = GetMapObjectRandom();
        if (CrabNextRandomBelow(mapObjectRandom, 2) != 0) {
            crab->mRotateZAnglePerFrame = CRAB_ROTATE_Z_ANGLE_PER_FRAME;
        } else {
            crab->mRotateZAnglePerFrame = CRAB_ROTATE_Z_ANGLE_PER_FRAME_REVERSE;
        }
    }
    if (sourceVelocity != NULL) {
        crab->mMapObject.mPosStep.x += sourceVelocity->x / 2;
        crab->mMapObject.mPosStep.z += sourceVelocity->z / 2;
    }
    crab->mMapObject.mPosStep.y = 0x4000;
    crab->mTimer = CRAB_FLUNG_FRAMES;
    crab->mState = CRAB_STATE_FLUNG;
    crab->mMapObject.mFlags |= gCrabLaunchFlag;
}

u8 CollideKartWithCrab(Crab *crab, Kart *kart, u8 *hitFlag, u8 *passedValue) {
    u32 result;

    result = *passedValue;
    if (*hitFlag == 1) {
        StartCrabLaunch(crab, &kart->mPos, &kart->mEasedTurnedForward, &kart->mVelocity);
        StartSoundIfKartStarOrKiller(&crab->mMapObject, kart);
    }
    return result;
}

u8 CollideItemObjectWithCrab(Crab *crab, ItemObject *itemObject, u8 *hitFlag, u8 *passedValue) {
    Vec3 direction;
    Kart *entryKart;
    u32 result;

    result = *passedValue;
    if (*hitFlag == 1) {
        if (itemObject != NULL) {
            if ((s64) itemObject->mVelocity.x * itemObject->mVelocity.x +
                    (s64) itemObject->mVelocity.y * itemObject->mVelocity.y +
                    (s64) itemObject->mVelocity.z * itemObject->mVelocity.z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&itemObject->mVelocity, &direction);
                StartCrabLaunch(crab, &itemObject->mPos, &direction, NULL);
            } else {
                StartCrabLaunch(crab, NULL, NULL, NULL);
            }
            StartMissionRunKouraEffects(itemObject);
        } else {
            entryKart = GetKart((u16) gRaceSetup->mEntryIndex);
            StartCrabLaunch(crab, &entryKart->mPos, &entryKart->mEasedTurnedForward, &entryKart->mVelocity);
        }
    }
    return result;
}

void CreateCrabAndCrabHand(void *mapObjectList) {
    gCrab = CreateMapObjectModelNsbmdNsbtp(mapObjectList, "crab.nsbmd", "crab.nsbtp");
    gCrabHand = CreateMapObjectModelNsbmdNsbtp(mapObjectList, "crab_hand.nsbmd", "crab_hand.nsbtp");
    SetMapObjectModelPolygonId(gCrab, 0x3f);
    SetMapObjectModelPolygonId(gCrabHand, 0x3f);
}

void CrabSetupDrawNop(void) {}

void DrawCrab(void *mapObjectList, Crab *crab) {
    s32 commandParam;
    MtxFx33 crabRotation;
    MtxFx33 handRotation;

    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    BuildYAxisMatrix(&crab->mMapObject.mMatrix.mRows[1]);
    NNS_G3dGeBufferOP_N(0x19, SetYAxisMatrixPos(&crab->mMapObject.mPos), 0xc);
    if (crab->mRotateZAngle != 0) {
        MTX_RotZ33_(&crabRotation, FX_SinIdx(crab->mRotateZAngle), FX_CosIdx(crab->mRotateZAngle));
        NNS_G3dGeBufferOP_N(0x1a, &crabRotation, 9);
    }
    NNS_G3dGeBufferOP_N(0x1b, &crab->mMapObject.mScale, 3);
    SetMapObjectModelNsbtpFrameIndex(gCrab, FROM_FIXED12(crab->mCrabNsbtpFrameIndexFixed12));
    QueueMapObjectModelMaterial(mapObjectList, gCrab);
    DrawMapObjectModel(mapObjectList, gCrab, crab);
    MTX_RotZ33_(&handRotation, FX_SinIdx((u16) crab->mHandWobble.mValue), FX_CosIdx((u16) crab->mHandWobble.mValue));
    NNS_G3dGeBufferOP_N(0x1a, &handRotation, 9);
    SetMapObjectModelNsbtpFrameIndex(gCrabHand, FROM_FIXED12(crab->mHandNsbtpFrameIndexFixed12));
    QueueMapObjectModelMaterial(mapObjectList, gCrabHand);
    DrawMapObjectModel(mapObjectList, gCrabHand, crab);
}

void InitCrabObjects(MapObjectList *mapObjectList) {
    s32 objectIndex;
    Crab *crab;
    RandomState64 *mapObjectRandom;

    if (mapObjectList == NULL) {
        return;
    }
    for (objectIndex = 0;
         objectIndex < mapObjectList->mMapObjectCount && (crab = mapObjectList->mMapObjects[objectIndex]) != NULL;
         objectIndex++) {
        crab->mHandWobble.mAngle = 0;
        crab->mHandWobble.mMid = 0;
        crab->mHandWobble.mAmplitude = CRAB_HAND_WOBBLE_AMPLITUDE;
        crab->mHandWobble.mAmplitudePerFrame = 0;
        crab->mHandWobble.mAnglePerFrame = CRAB_HAND_WOBBLE_ANGLE_PER_FRAME;
        crab->mHandWobble.mAnglePerFrameDelta = 0;
        mapObjectRandom = GetMapObjectRandom();
        RANDOM_ADVANCE(mapObjectRandom);
        crab->mTimer = (u16) ((u16) RANDOM_BELOW_U64(mapObjectRandom, 60) + 30);
        crab->mState = CRAB_STATE_WAIT;
    }
}

s16 CrabFX_SinIdx(s32 angle) {
    return FX_SinIdx(angle);
}

s32 CrabFX_MulInline(s32 value, s32 factor) {
    return MUL_FIXED12_ROUNDED(value, factor);
}

static inline void AdvanceCrabWobble(TeresaWobble *wobble) {
    s32 nextValue;

    wobble->mAngle += wobble->mAnglePerFrame;
    wobble->mValueDelta =
        wobble->mMid + CrabFX_MulInline(wobble->mAmplitude, CrabFX_SinIdx(wobble->mAngle)) - wobble->mValue;
    wobble->mValue += wobble->mValueDelta;
    if (wobble->mAmplitude > 0) {
        nextValue = wobble->mAmplitude + wobble->mAmplitudePerFrame;
        if (nextValue <= 0) {
            nextValue = 0;
        }
        wobble->mAmplitude = nextValue;
    } else if (wobble->mAmplitude < 0) {
        nextValue = wobble->mAmplitude + wobble->mAmplitudePerFrame;
        if (nextValue >= 0) {
            nextValue = 0;
        }
        wobble->mAmplitude = nextValue;
    }
    if (wobble->mAnglePerFrame > 0) {
        nextValue = wobble->mAnglePerFrame + wobble->mAnglePerFrameDelta;
        if (nextValue <= 0) {
            nextValue = 0;
        }
        wobble->mAnglePerFrame = nextValue;
    } else if (wobble->mAnglePerFrame < 0) {
        nextValue = wobble->mAnglePerFrame + wobble->mAnglePerFrameDelta;
        if (nextValue >= 0) {
            nextValue = 0;
        }
        wobble->mAnglePerFrame = nextValue;
    }
}

void UpdateCrab(void *mapObjectList, Crab *crab) {
    Vec3 upVector;
    RandomState64 *mapObjectRandom;

    switch (crab->mState) {
        case CRAB_STATE_WAIT:
            crab->mHandNsbtpFrameIndexFixed12 += 0x200;
            if (crab->mHandNsbtpFrameIndexFixed12 >=
                (s32) (GetMapObjectModelNsbtpFrameCount(gCrabHand) > 0
                           ? 0.5f + TO_FIXED12(GetMapObjectModelNsbtpFrameCount(gCrabHand))
                           : TO_FIXED12(GetMapObjectModelNsbtpFrameCount(gCrabHand)) - 0.5f)) {
                crab->mHandNsbtpFrameIndexFixed12 = 0;
            }
            if (crab->mTimer-- > 0) {
                return;
            }
            if (crab->mHandNsbtpFrameIndexFixed12 == 0) {
                crab->mState = CRAB_STATE_WALK;
            }
            break;
        case CRAB_STATE_WALK:
            crab->mFollower.mSpeed = CRAB_PATH_SPEED;
            crab->mFollower.mProgressStep = MUL_FIXED12_NO_ROUND(
                crab->mFollower.mPath->mSegments[crab->mFollower.mSegmentIndex].mInverseProgressLength,
                CRAB_PATH_SPEED);
            if (AdvanceGroupFollower(&crab->mFollower) != FALSE) {
                crab->mHandWobble.mAngle = 0;
                crab->mHandWobble.mMid = 0;
                crab->mHandWobble.mAmplitude = CRAB_HAND_WOBBLE_AMPLITUDE;
                crab->mHandWobble.mAmplitudePerFrame = 0;
                crab->mHandWobble.mAnglePerFrame = CRAB_HAND_WOBBLE_ANGLE_PER_FRAME;
                crab->mHandWobble.mAnglePerFrameDelta = 0;
                mapObjectRandom = GetMapObjectRandom();
                RANDOM_ADVANCE(mapObjectRandom);
                crab->mTimer = (u16) ((u16) RANDOM_BELOW_U64(mapObjectRandom, 60) + 30);
                crab->mState = CRAB_STATE_WAIT;
            }
            crab->mCrabNsbtpFrameIndexFixed12 += 0x200;
            if (crab->mCrabNsbtpFrameIndexFixed12 >=
                (s32) (GetMapObjectModelNsbtpFrameCount(gCrab) > 0
                           ? 0.5f + TO_FIXED12(GetMapObjectModelNsbtpFrameCount(gCrab))
                           : TO_FIXED12(GetMapObjectModelNsbtpFrameCount(gCrab)) - 0.5f)) {
                crab->mCrabNsbtpFrameIndexFixed12 = 0;
            }
            AdvanceCrabWobble(&crab->mHandWobble);
            GetGroupFollowerLinearPosition(&crab->mFollower, &crab->mMapObject.mPos);
            upVector = *GetGroupFollowerSegmentUp(&crab->mFollower);
            VEC_Subtract(&upVector, &crab->mMapObject.mMatrix.mRows[1], &upVector);
            upVector.x = MUL_FIXED12_NO_ROUND(upVector.x, 0x800);
            upVector.y = MUL_FIXED12_NO_ROUND(upVector.y, 0x800);
            upVector.z = MUL_FIXED12_NO_ROUND(upVector.z, 0x800);
            VEC_Add(&crab->mMapObject.mMatrix.mRows[1], &upVector, &crab->mMapObject.mMatrix.mRows[1]);
            if ((s64) crab->mMapObject.mMatrix.mRows[1].x * crab->mMapObject.mMatrix.mRows[1].x +
                    (s64) crab->mMapObject.mMatrix.mRows[1].y * crab->mMapObject.mMatrix.mRows[1].y +
                    (s64) crab->mMapObject.mMatrix.mRows[1].z * crab->mMapObject.mMatrix.mRows[1].z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&crab->mMapObject.mMatrix.mRows[1],
                                                   &crab->mMapObject.mMatrix.mRows[1]);
            }
            break;
        case CRAB_STATE_FLUNG:
            if (crab->mTimer-- > 0) {
                crab->mMapObject.mPosStep.y -= 0x400;
                VEC_Add(&crab->mMapObject.mPos, &crab->mMapObject.mPosStep, &crab->mMapObject.mPos);
                crab->mRotateZAngle += crab->mRotateZAnglePerFrame;
                return;
            }
            SetupGroupFollowerAtEntry(&crab->mFollower, 0, 0);
            GetGroupFollowerLinearXz(&crab->mFollower, &crab->mMapObject.mPos);
            crab->mMapObject.mPos.y = crab->mMapObject.mCourseMapRow->mPosition.y - 0x5000;
            crab->mCrabWobble.mAngle = 0;
            crab->mCrabWobble.mMid = 0;
            crab->mCrabWobble.mAmplitude = CRAB_BODY_WOBBLE_AMPLITUDE;
            crab->mCrabWobble.mAmplitudePerFrame = -0xb6;
            crab->mCrabWobble.mAnglePerFrame = CRAB_BODY_WOBBLE_ANGLE_PER_FRAME;
            crab->mCrabWobble.mAnglePerFrameDelta = 0;
            AdvanceCrabWobble(&crab->mCrabWobble);
            crab->mRotateZAngle = crab->mCrabWobble.mValue;
            crab->mState = CRAB_STATE_RISE;
            break;
        case CRAB_STATE_RISE:
            crab->mHandNsbtpFrameIndexFixed12 += 0x200;
            if (crab->mHandNsbtpFrameIndexFixed12 >=
                (s32) (GetMapObjectModelNsbtpFrameCount(gCrabHand) > 0
                           ? 0.5f + TO_FIXED12(GetMapObjectModelNsbtpFrameCount(gCrabHand))
                           : TO_FIXED12(GetMapObjectModelNsbtpFrameCount(gCrabHand)) - 0.5f)) {
                crab->mHandNsbtpFrameIndexFixed12 = 0;
            }
            AdvanceCrabWobble(&crab->mCrabWobble);
            crab->mRotateZAngle = crab->mCrabWobble.mValue;
            crab->mMapObject.mPos.y += 0x200;
            if (crab->mMapObject.mPos.y < crab->mMapObject.mCourseMapRow->mPosition.y) {
                return;
            }
            crab->mMapObject.mPos.y = crab->mMapObject.mCourseMapRow->mPosition.y;
            crab->mMapObject.mPosStep.x = 0;
            crab->mMapObject.mPosStep.y = 0;
            crab->mMapObject.mPosStep.z = 0;
            crab->mRotateZAngle = 0;
            crab->mHandWobble.mAngle = 0;
            crab->mHandWobble.mMid = 0;
            crab->mHandWobble.mAmplitude = CRAB_HAND_WOBBLE_AMPLITUDE;
            crab->mHandWobble.mAmplitudePerFrame = 0;
            crab->mHandWobble.mAnglePerFrame = CRAB_HAND_WOBBLE_ANGLE_PER_FRAME;
            crab->mHandWobble.mAnglePerFrameDelta = 0;
            mapObjectRandom = GetMapObjectRandom();
            RANDOM_ADVANCE(mapObjectRandom);
            crab->mTimer = (u16) ((u16) RANDOM_BELOW_U64(mapObjectRandom, 60) + 30);
            crab->mState = CRAB_STATE_WAIT;
            crab->mMapObject.mFlags &= ~MAP_OBJECT_FLAG_DISABLED;
            break;
    }
}

MapObjectKindData *CreateCrabKindData(void) {
    MapObjectKindData *kindData;

    kindData = CreateMapObjectKindDataWithSound(CollideKartWithCrab, CollideItemObjectWithCrab, NULL, 2, 1, 0x10e);
    kindData->mCollideItemObjectSoundId = CRAB_ITEM_HIT_SOUND_ID;
    return kindData;
}

MapObjectList *CreateCrabDrawList(void) {
    return CreateMapObjectDrawList2(CreateCrabAndCrabHand, DrawCrab, CrabSetupDrawNop);
}

MapObjectList *CreateCrabUpdateList(void) {
    return CreateMapObjectUpdateList(InitCrabObjects, UpdateCrab, NULL);
}
