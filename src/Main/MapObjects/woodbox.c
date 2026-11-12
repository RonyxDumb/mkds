#include "Main/MapObjects/woodbox.h"

#include "Main/Graphics/emitters.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/data_02159000.h"
#include "Main/MapObjects/ob_pakkun_sf.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/Kart/code_0207a000.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/code_020ebef8.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/MapObjects/code_020ec1fc.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/Race/race.h"
#include "Main/System/state_machine_init.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/kart_motion.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "code_02147cd8.h"
#include "code_02012b30.h"
#include "code_02010c84.h"
#include "code_020109c4.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/shadow_position_raised.h"
#include "Main/Item/item_kinoko.h"
#include "Main/Item/item_slot_tables.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/MapObjects/pushed_motion.h"
#include "01/Race/mission_run_state.h"

s32 gSavedModelAlpha = -1;
Vec3 gWoodbox1GroundUp = {0, 0x1000, 0};
StateCallbacks gWoodbox1StateTable[4] = {{EnterWoodbox1State0, NULL}, {EnterWoodbox1State1, UpdateWoodbox1State1}, {EnterWoodbox1State2, UpdateWoodbox1State2}, {NULL, UpdateWoodbox1State3}};
const u16 gWoodbox1Flag = 1;
const u16 gWoodbox1SecondFlag = 2;
const u16 gWoodbox1ThirdFlag = 8;
const MapObjectList gWoodbox1UpdateListData = {
    0, 0, {0, 0}, &ClearWoodbox1Pointer, 0, &AdvanceWoodbox1, 0, 0, 0, 0, 0,
};
const Woodbox1DrawList gWoodbox1DrawListData = {
    0, 0, {0, 0}, &CreateWoodbox1, 0, &DrawWoodbox1, 0, 1, 0, 0, 0, 0,
};
const Unk02159538 gWoodbox1KindData = {
    &CollideKartWithWoodbox1,
    &CollideItemObjectWithWoodbox1,
    4,
    0xa000,
    0xa000,
    0xa000,
    0,
    1,
    1,
    0x168,
    0x169,
    0,
    0,
    0,
    0,
    0,
};
Woodbox1 *gBouncingWoodbox1;
Nsbmd *gWoodbox1;
u32 gWoodbox1PolyAttr;
MapObjectList *gWoodbox1UpdateList;
Woodbox1DrawList *gWoodbox1DrawList;

BOOL HitPushedObjectByKart(PushedObject *mapObject, void *other, u8 *firstResponse) {
    if (*firstResponse != 1) {
        return FALSE;
    }
    SetPushedMotionFromKart(mapObject, other);
    mapObject->mMapObject.mStateMachine.mNextState = 1;
    mapObject->mMapObject.mStateMachine.mNextStateRequested = 1;
    return TRUE;
}

BOOL HitPushedObjectByItemObject(PushedObject *mapObject, void *other, u8 *firstResponse) {
    if (*firstResponse != 1) {
        return FALSE;
    }
    SetPushedMotionFromItemObject(mapObject, other);
    mapObject->mMapObject.mStateMachine.mNextState = 1;
    mapObject->mMapObject.mStateMachine.mNextStateRequested = 1;
    return TRUE;
}

Unk02159538 *CreateWoodbox1KindData(void) {
    Unk02159538 *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = gWoodbox1KindData;
    return kindData;
}

Woodbox1DrawList *CreateWoodbox1DrawList(void) {
    Woodbox1DrawList *drawList;

    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gWoodbox1DrawList = drawList;
    *drawList = gWoodbox1DrawListData;
    SetDrawListSlot(&gWoodbox1DrawList);
    return gWoodbox1DrawList;
}

MapObjectList *CreateWoodbox1UpdateList(void) {
    MapObjectList *updateList;

    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gWoodbox1UpdateList = updateList;
    *updateList = gWoodbox1UpdateListData;
    SetUpdateListSlot(&gWoodbox1UpdateList);
    return gWoodbox1UpdateList;
}

void DrawWoodbox1(void *mapObjectList, Woodbox1 *woodbox, void *unused, u32 maxAlpha) {
    u16 state;
    s32 shadowValue;
    Vec3 shadowPos;

    state = woodbox->mMapObject.mStateMachine.mState;
    woodbox->mMapObject.mMatrix.mRows[3].x = woodbox->mMapObject.mPos.x >> 4;
    woodbox->mMapObject.mMatrix.mRows[3].y = woodbox->mMapObject.mPos.y >> 4;
    woodbox->mMapObject.mMatrix.mRows[3].z = woodbox->mMapObject.mPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(gWoodbox1, &woodbox->mMapObject.mMatrix, &woodbox->mMapObject.mScale, maxAlpha);
    if (state == 0) {
        return;
    }
    shadowValue = MUL_FIXED12_NO_ROUND(0x5a000 - woodbox->mPosOffset.y, 0x2e);
    shadowPos.x = woodbox->mMapObject.mPos.x;
    shadowPos.z = woodbox->mMapObject.mPos.z;
    shadowPos.y = woodbox->mBasePos.y - MUL_FIXED12_NO_ROUND(woodbox->mGroundUp.x, woodbox->mPosOffset.x) -
                  MUL_FIXED12_NO_ROUND(woodbox->mGroundUp.z, woodbox->mPosOffset.z);
    VEC_MultAdd(-woodbox->mMapObject.mExtent.x, &woodbox->mGroundUp, &shadowPos, &shadowPos);
    SetShadowPositionRaised(&woodbox->mUnk_114, &shadowPos);
    DrawObjShadow(&woodbox->mUnk_114, &shadowValue, 0, maxAlpha);
}

void AdvanceWoodbox1(u32 unused, Woodbox1 *woodbox) {
    AdvanceStateMachine(&woodbox->mMapObject.mStateMachine);
}

void EnterWoodbox1State0(Woodbox1 *woodbox) {
    Quaternion rotation;
    Vec3 *velocity;

    velocity = &woodbox->mMapObject.mPosStep;
    velocity->x = 0;
    velocity->y = 0;
    velocity->z = 0;
    woodbox->mMapObject.mPos = woodbox->mBasePos;
    QuaternionFromVec3AndAngleAroundY(&woodbox->mGroundUp, woodbox->mHeadingAngle, &rotation);
    Matrix3x3FromQuaternion(&woodbox->mMapObject.mMatrix.mAxes, &rotation);
}

// With a chance given by the box, starts one item object that moves off with the given velocity.
void StartWoodbox1ItemObject(Woodbox1 *woodbox, Vec3 *velocity) {
    s32 spawnDistance;
    Vec3 direction;
    Vec3 sideDirection;
    RandomState64 *raceRandom;
    ItemObject *itemObject;
    s32 itemIndex;

    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunCountForMapObjectKind(woodbox->mMapObject.mKind);
    }
    woodbox->mMapObject.mFlags |= gWoodbox1Flag;
    if (gRaceSetup->mMode == MODE_WIFI) {
        return;
    }
    raceRandom = GetRaceRandom();
    raceRandom->mValue = raceRandom->mMultiplier * raceRandom->mValue + raceRandom->mIncrement;
    if (woodbox->mItemChancePercent <= (u16) (((u64) (u32) (raceRandom->mValue >> 32) * 100) >> 32)) {
        return;
    }
    if (woodbox->mItemRowHandle == 0) {
        return;
    }
    itemIndex = PickItem(0, woodbox->mItemRowHandle, 1, 1, 0, 0x12);
    itemObject =
        StartItemObjectOrZero(gItemInfos[itemIndex].mObjectKind, 8, &woodbox->mMapObject.mPos, &woodbox->mGroundUp);
    if (itemObject == NULL) {
        return;
    }
    if (LENGTH_SQUARED(*velocity) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(velocity, &direction);
    }
    Vec3CrossUnrounded(&woodbox->mGroundUp, &direction, &sideDirection);
    raceRandom = GetRaceRandom();
    raceRandom->mValue = raceRandom->mMultiplier * raceRandom->mValue + raceRandom->mIncrement;
    spawnDistance =
        ((s64) (s32) ((u32) (((u64) (u32) (raceRandom->mValue >> 32) * 0x1800) >> 32) + 0x119a) << 12) >> 12;
    raceRandom = GetRaceRandom();
    raceRandom->mValue = raceRandom->mMultiplier * raceRandom->mValue + raceRandom->mIncrement;
    itemObject->mVelocity = *velocity;
    VEC_MultAdd(spawnDistance, &direction, &woodbox->mMapObject.mPos, &itemObject->mPos);
    VEC_MultAdd(0, &sideDirection, &itemObject->mPos, &itemObject->mPos);
    itemObject->mScale.x = 0xcd;
    itemObject->mScale.y = 0xcd;
    itemObject->mScale.z = 0xcd;
    LaunchItemObjectFromPos(itemObject, 2, &woodbox->mMapObject.mPos, velocity, &woodbox->mGroundUp);
}

void EnterWoodbox1State1(Woodbox1 *woodbox) {
    woodbox->mMapObject.mFlags |= gWoodbox1Flag;
    woodbox->mMapObject.mFlags |= gWoodbox1SecondFlag;
    woodbox->mMapObject.mFlags |= gWoodbox1ThirdFlag;
}

#pragma thumb off

void UpdateWoodbox1State1(Woodbox1 *woodbox) {
    if (woodbox->mMapObject.mStateMachine.mStateFrames < 900) {
        return;
    }
    if (woodbox->mMapObject.mCourseMapRow->mSettings[2] != 0) {
        return;
    }
    if (gBouncingWoodbox1 == NULL) {
        gBouncingWoodbox1 = woodbox;
        woodbox->mMapObject.mStateMachine.mNextState = 2;
        woodbox->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

BOOL BounceWoodbox1OffGround(Woodbox1 *woodbox) {
    Vec3 cornerPos;
    Vec3 *axis;
    s32 dot;
    s32 extent;

    cornerPos = woodbox->mMapObject.mPos;
    axis = &woodbox->mMapObject.mMatrix.mRows[0];
    extent = woodbox->mMapObject.mExtent.x;
    dot = Vec3DotUnrounded(&woodbox->mGroundUp, axis);
    if (dot > 0) {
        VEC_MultAdd(-extent, axis, &cornerPos, &cornerPos);
    } else {
        VEC_MultAdd(extent, axis, &cornerPos, &cornerPos);
    }
    axis = &woodbox->mMapObject.mMatrix.mRows[1];
    extent = woodbox->mMapObject.mExtent.x;
    dot = Vec3DotUnrounded(&woodbox->mGroundUp, axis);
    if (dot > 0) {
        VEC_MultAdd(-extent, axis, &cornerPos, &cornerPos);
    } else {
        VEC_MultAdd(extent, axis, &cornerPos, &cornerPos);
    }
    axis = &woodbox->mMapObject.mMatrix.mRows[2];
    extent = woodbox->mMapObject.mExtent.x;
    dot = Vec3DotUnrounded(&woodbox->mGroundUp, axis);
    if (dot > 0) {
        VEC_MultAdd(-extent, axis, &cornerPos, &cornerPos);
    } else {
        VEC_MultAdd(extent, axis, &cornerPos, &cornerPos);
    }
    VEC_Subtract(&cornerPos, &woodbox->mBasePos, &cornerPos);
    cornerPos.y = cornerPos.y + woodbox->mMapObject.mExtent.x;
    dot = -Vec3DotUnrounded(&cornerPos, &woodbox->mGroundUp);
    if (dot > 0 && woodbox->mMapObject.mPosStep.y < 0) {
        woodbox->mPosOffset.y = woodbox->mPosOffset.y + dot;
        woodbox->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(-woodbox->mMapObject.mPosStep.y, 0x400);
        woodbox->mTiltOffsetPerFrame.x = MUL_FIXED12_NO_ROUND(woodbox->mTiltOffset.x, -0x266);
        woodbox->mTiltOffsetPerFrame.y = MUL_FIXED12_NO_ROUND(woodbox->mTiltOffset.y, -0x266);
        woodbox->mTiltOffsetPerFrame.z = MUL_FIXED12_NO_ROUND(woodbox->mTiltOffset.z, -0x266);
        woodbox->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(woodbox->mTiltOffsetPerFrame.x, 0x9000);
        woodbox->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(woodbox->mTiltOffsetPerFrame.z, 0x9000);
        return TRUE;
    }
    return FALSE;
}

void EnterWoodbox1State2(Woodbox1 *woodbox) {
    Quaternion rotation;
    u32 frameCount;
    u16 headingOffset;

    frameCount = GetRaceUpdateFrames();
    woodbox->mMapObject.mFlags &= ~1;
    woodbox->mMapObject.mFlags &= ~2;
    woodbox->mMapObject.mFlags &= ~8;
    woodbox->mMapObject.mAlpha = 1;
    woodbox->mTiltOffset = *((frameCount & 1) ? &woodbox->mUnk_0f4 : &woodbox->mUnk_100);
    if (frameCount & 2) {
        headingOffset = woodbox->mUnk_10c;
    } else {
        headingOffset = 0x10000 - woodbox->mHeadingAngleOffset;
    }
    woodbox->mHeadingAngleOffset = headingOffset;
    woodbox->mTiltOffsetPerFrame.x = 0;
    woodbox->mTiltOffsetPerFrame.y = 0;
    woodbox->mTiltOffsetPerFrame.z = 0;
    woodbox->mPosOffset.x = MUL_FIXED12_NO_ROUND(woodbox->mTiltOffset.x, 0x14000);
    woodbox->mPosOffset.y = 0x3c000;
    woodbox->mPosOffset.z = MUL_FIXED12_NO_ROUND(woodbox->mTiltOffset.z, 0x14000);
    woodbox->mMapObject.mPosStep.x = 0;
    woodbox->mMapObject.mPosStep.y = 0;
    woodbox->mMapObject.mPosStep.z = 0;
    VEC_Add(&woodbox->mGroundUp, &woodbox->mTiltOffset, &woodbox->mTiltedUp);
    woodbox->mMatrixHeadingAngle = woodbox->mHeadingAngle + woodbox->mHeadingAngleOffset;
    QuaternionFromVec3AndAngleAroundY(&woodbox->mTiltedUp, woodbox->mMatrixHeadingAngle, &rotation);
    Matrix3x3FromQuaternion(&woodbox->mMapObject.mMatrix.mAxes, &rotation);
}

void UpdateWoodbox1State2(Woodbox1 *woodbox) {
    if (BounceWoodbox1OffGround(woodbox) != FALSE) {
        woodbox->mMapObject.mStateMachine.mNextState = 3;
        woodbox->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
    woodbox->mMapObject.mPosStep.y -= 0x1ec;
    woodbox->mPosOffset.y = woodbox->mPosOffset.y + woodbox->mMapObject.mPosStep.y;
    VEC_Add(&woodbox->mBasePos, &woodbox->mPosOffset, &woodbox->mMapObject.mPos);
}

void UpdateWoodbox1State3(Woodbox1 *woodbox) {
    Quaternion rotation;
    s32 headingOffset;

    BounceWoodbox1OffGround(woodbox);
    woodbox->mPosOffset.x -= MUL_FIXED12_NO_ROUND(woodbox->mPosOffset.x, 164);
    woodbox->mPosOffset.z -= MUL_FIXED12_NO_ROUND(woodbox->mPosOffset.z, 164);
    VEC_Add(&woodbox->mTiltOffset, &woodbox->mTiltOffsetPerFrame, &woodbox->mTiltOffset);
    headingOffset = woodbox->mHeadingAngleOffset;
    if ((u32) headingOffset < 0x8000) {
        woodbox->mHeadingAngleOffset = headingOffset - MUL_FIXED12_NO_ROUND(headingOffset, 246);
    } else {
        woodbox->mHeadingAngleOffset = headingOffset + MUL_FIXED12_NO_ROUND(0x10000 - headingOffset, 246);
    }
    woodbox->mMapObject.mPosStep.y -= 655;
    VEC_Add(&woodbox->mPosOffset, &woodbox->mMapObject.mPosStep, &woodbox->mPosOffset);
    VEC_Add(&woodbox->mBasePos, &woodbox->mPosOffset, &woodbox->mMapObject.mPos);
    VEC_Add(&woodbox->mGroundUp, &woodbox->mTiltOffset, &woodbox->mTiltedUp);
    if ((s64) woodbox->mTiltedUp.x * woodbox->mTiltedUp.x + (s64) woodbox->mTiltedUp.y * woodbox->mTiltedUp.y +
            (s64) woodbox->mTiltedUp.z * woodbox->mTiltedUp.z >=
        16) {
        Vec3NormalizeAndGetLengthUnchecked(&woodbox->mTiltedUp, &woodbox->mTiltedUp);
    }
    woodbox->mMatrixHeadingAngle = woodbox->mHeadingAngle + woodbox->mHeadingAngleOffset;
    QuaternionFromVec3AndAngleAroundY(&woodbox->mTiltedUp, woodbox->mMatrixHeadingAngle, &rotation);
    Matrix3x3FromQuaternion(&woodbox->mMapObject.mMatrix.mAxes, &rotation);
    if (woodbox->mMapObject.mStateMachine.mStateFrames >= 90) {
        gBouncingWoodbox1 = NULL;
        woodbox->mMapObject.mStateMachine.mNextState = 0;
        woodbox->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

u32 CollideKartWithWoodbox1(Woodbox1 *woodbox, Kart *kart, u8 *firstResponse, u8 *response) {
    if (*firstResponse == 3) {
        if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
            if (kart->mItemEffect == 1 || kart->mVelocityLength > 0x3000) {
                StartWoodbox1ItemObject(woodbox, &kart->mVelocity);
                if (gBouncingWoodbox1 == woodbox) {
                    gBouncingWoodbox1 = NULL;
                }
                woodbox->mMapObject.mStateMachine.mNextState = 1;
                woodbox->mMapObject.mStateMachine.mNextStateRequested = 1;
                StartSoundFullVolumeWrapper(kart, 0x167);
                woodbox->mMapObject.mDistanceSquaredAndFlags |= gWoodbox1HitFlag;
                StartSoundIfKartStarOrKiller(&woodbox->mMapObject, kart);
                if ((woodbox->mMapObject.mDistanceSquaredAndFlags & 3) == 0) {
                    if (*response == 0) {
                        StartEffectWithKartVelocity(0x31, &woodbox->mMapObject.mPos, kart->mIndex, 0x1000);
                        StartEffectWithKartVelocity(0x32, &woodbox->mMapObject.mPos, kart->mIndex, 0x1000);
                    } else {
                        StartEffect(0x31, &woodbox->mMapObject.mPos);
                        StartEffect(0x32, &woodbox->mMapObject.mPos);
                    }
                }
            }
        }
    }
    return *response;
}

u32 CollideItemObjectWithWoodbox1(Woodbox1 *woodbox, ItemObject *itemObject, u8 *firstResponse, u8 *response) {
    u32 firstResponseMinusOne;

    firstResponseMinusOne = *firstResponse - 1;
    if (firstResponseMinusOne <= 1) {
        StartWoodbox1ItemObject(woodbox, &itemObject->mVelocity);
        if (gBouncingWoodbox1 == woodbox) {
            gBouncingWoodbox1 = NULL;
        }
        woodbox->mMapObject.mStateMachine.mNextState = 1;
        woodbox->mMapObject.mStateMachine.mNextStateRequested = 1;
        if ((woodbox->mMapObject.mDistanceSquaredAndFlags & 3) == 0) {
            StartEffect(0x31, &woodbox->mMapObject.mPos);
            StartEffect(0x32, &woodbox->mMapObject.mPos);
        }
    }
    return *response;
}

#pragma thumb on

void CreateWoodbox1(MapObjectList *list) {
    CreateNsbmd(&gWoodbox1, FindCourseMapObjFile("woodbox1.nsbmd"), NULL);
    SetNsbmdPolygonIdLightEmiAll(gWoodbox1, 0x3f, 2, 0x294a);
}

void ClearWoodbox1Pointer(MapObjectList *list) {
    gBouncingWoodbox1 = NULL;
}

void InitWoodbox1(Woodbox1 *woodbox, CourseMapRow *courseRow) {
    Quaternion rotation;
    s32 length;

    if (CollideSphereWithCourse(&woodbox->mMapObject.mPos, NULL, 0, 0xa000, 8, -2, NULL, &woodbox->mGroundUp, NULL,
                                NULL, NULL, NULL, NULL, NULL) == 0) {
        woodbox->mGroundUp = gWoodbox1GroundUp;
    }
    woodbox->mMapObject.mPos.y = woodbox->mMapObject.mPos.y + woodbox->mMapObject.mExtent.x;
    woodbox->mBasePos = woodbox->mMapObject.mPos;
    woodbox->mMapObject.mPosStep.x = 0;
    woodbox->mMapObject.mPosStep.y = 0;
    woodbox->mMapObject.mPosStep.z = 0;
    woodbox->mHeadingAngle = DEG_TO_ANGLE(courseRow->mRotationDegrees.y);
    QuaternionFromVec3AndAngleAroundY(&woodbox->mGroundUp, woodbox->mHeadingAngle, &rotation);
    Matrix3x3FromQuaternion(&woodbox->mMapObject.mMatrix.mAxes, &rotation);
    woodbox->mUnk_0f4.x = -woodbox->mGroundUp.x;
    woodbox->mUnk_0f4.y = 0;
    woodbox->mUnk_0f4.z = -woodbox->mGroundUp.z;
    if ((s64) woodbox->mUnk_0f4.x * woodbox->mUnk_0f4.x + (s64) woodbox->mUnk_0f4.y * woodbox->mUnk_0f4.y +
            (s64) woodbox->mUnk_0f4.z * woodbox->mUnk_0f4.z <
        16) {
        length = 0;
    } else {
        length = Vec3NormalizeAndGetLengthUnchecked(&woodbox->mUnk_0f4, &woodbox->mUnk_0f4);
    }
    if (length == 0) {
        woodbox->mUnk_0f4.x = -woodbox->mMapObject.mMatrix.mRows[2].x;
        woodbox->mUnk_0f4.z = -woodbox->mMapObject.mMatrix.mRows[2].z;
    }
    Vec3RotateAroundY(&woodbox->mUnk_0f4, 0x0aab, &woodbox->mUnk_100);
    Vec3RotateAroundY(&woodbox->mUnk_0f4, 0xf555, &woodbox->mUnk_0f4);
    woodbox->mUnk_0f4.x = MUL_FIXED12_NO_ROUND(woodbox->mUnk_0f4.x, 0x800);
    woodbox->mUnk_0f4.y = MUL_FIXED12_NO_ROUND(woodbox->mUnk_0f4.y, 0x800);
    woodbox->mUnk_0f4.z = MUL_FIXED12_NO_ROUND(woodbox->mUnk_0f4.z, 0x800);
    woodbox->mUnk_100.x = MUL_FIXED12_NO_ROUND(woodbox->mUnk_100.x, 0x800);
    woodbox->mUnk_100.y = MUL_FIXED12_NO_ROUND(woodbox->mUnk_100.y, 0x800);
    woodbox->mUnk_100.z = MUL_FIXED12_NO_ROUND(woodbox->mUnk_100.z, 0x800);
    woodbox->mUnk_10c = 0x1555;
    woodbox->mItemRowHandle = courseRow->mSettings[0];
    woodbox->mItemChancePercent = courseRow->mSettings[1];
    InitStateMachine(&woodbox->mMapObject.mStateMachine, gWoodbox1StateTable, 4, woodbox);
    woodbox->mMapObject.mStateMachine.mNextState = 0;
    woodbox->mMapObject.mStateMachine.mNextStateRequested = 1;
    RefreshShadowMatrix(&woodbox->mUnk_114, &courseRow->mPosition,
                        MUL_FIXED12_NO_ROUND(woodbox->mMapObject.mScale.x, 0x19000), 13);
}

#pragma thumb off

void ComputeSphereOverlapOffset(Vec3 *position, Vec3 *center, s32 radius, Vec3 *offset) {
    Vec3 direction;

    VEC_Subtract(position, center, offset);
    if (LENGTH_SQUARED(*offset) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(offset, &direction);
    }
    direction.x = MUL_FIXED12_NO_ROUND(direction.x, radius);
    direction.y = MUL_FIXED12_NO_ROUND(direction.y, radius);
    direction.z = MUL_FIXED12_NO_ROUND(direction.z, radius);
    VEC_Subtract(&direction, offset, offset);
}

void ComputeCylinderOverlapOffset(Vec3 *position, Vec3 *center, s32 radius, s32 halfHeight, Vec3 *offset) {
    Vec3 direction;
    s32 limit;

    offset->x = position->x - center->x;
    offset->y = 0;
    offset->z = position->z - center->z;
    if (LENGTH_SQUARED(*offset) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(offset, &direction);
    }
    offset->x = MUL_FIXED12_NO_ROUND(direction.x, radius) - offset->x;
    offset->z = MUL_FIXED12_NO_ROUND(direction.z, radius) - offset->z;
    offset->y = position->y - center->y;
    if (offset->y > 0) {
        offset->y = halfHeight - offset->y;
    } else {
        offset->y = -(halfHeight + offset->y);
    }
    if (HORIZONTAL_LENGTH_SQUARED(*offset) > (s64) offset->y * offset->y) {
        limit = offset->y;
        if (limit <= 0) {
            limit = -limit;
        }
        if (offset->x > limit) {
            offset->x = limit;
        } else if (offset->x < -limit) {
            offset->x = -limit;
        }
        if (offset->z > limit) {
            offset->z = limit;
        } else if (offset->z < -limit) {
            offset->z = -limit;
        }
    }
    offset->y = 0;
}

s32 ComputeSphereHitOnRotatedBox(Vec3 *sphereCenter, Vec3 *boxCenter, Vec3 *axes, const Vec3 *halfSizesPositive,
                                 const Vec3 *halfSizesNegative, s32 radius, Vec3 *pushOut) {
    Vec3 delta;
    s32 overlapY;
    Vec3 *axisY;
    s32 distanceX;
    s32 distanceY;
    s32 distanceZ;
    s32 overlapX;
    s32 overlapZ;
    Vec3 *axisZ;

    axisY = &axes[1];
    axisZ = &axes[2];
    VEC_Subtract(sphereCenter, boxCenter, &delta);
    distanceX = Vec3DotUnrounded(&delta, axes);
    if (distanceX >= halfSizesPositive->x + radius || distanceX <= -(halfSizesNegative->x + radius)) {
        return 0;
    }
    if (distanceX > 0) {
        overlapX = (halfSizesPositive->x + radius) - distanceX;
    } else {
        overlapX = distanceX + (halfSizesNegative->x + radius);
    }
    distanceY = Vec3DotUnrounded(&delta, axisY);
    if (distanceY >= halfSizesPositive->y + radius || distanceY <= -(halfSizesNegative->y + radius)) {
        return 0;
    }
    if (distanceY > 0) {
        overlapY = halfSizesPositive->y + radius;
        overlapY -= distanceY;
    } else {
        overlapY = distanceY + (halfSizesNegative->y + radius);
    }
    distanceZ = Vec3DotUnrounded(&delta, axisZ);
    if (distanceZ >= halfSizesPositive->z + radius || distanceZ <= -(halfSizesNegative->z + radius)) {
        return 0;
    }
    if (distanceZ > 0) {
        overlapZ = (halfSizesPositive->z + radius) - distanceZ;
    } else {
        overlapZ = distanceZ + (halfSizesNegative->z + radius);
    }
    if (overlapZ < overlapX) {
        if (overlapY < overlapZ && distanceY > 0) {
            if (pushOut != NULL) {
                pushOut->x = MUL_FIXED12_NO_ROUND(axisY->x, overlapY);
                pushOut->y = MUL_FIXED12_NO_ROUND(axisY->y, overlapY);
                pushOut->z = MUL_FIXED12_NO_ROUND(axisY->z, overlapY);
            }
            return 1;
        }
        if (pushOut != NULL) {
            if (distanceZ <= 0) {
                overlapZ = -overlapZ;
            }
            pushOut->x = MUL_FIXED12_NO_ROUND(axisZ->x, overlapZ);
            pushOut->y = MUL_FIXED12_NO_ROUND(axisZ->y, overlapZ);
            pushOut->z = MUL_FIXED12_NO_ROUND(axisZ->z, overlapZ);
            pushOut->y = 0;
        }
        return 4;
    }
    if (overlapY < overlapX && distanceY > 0) {
        if (pushOut != NULL) {
            pushOut->x = MUL_FIXED12_NO_ROUND(axisY->x, overlapY);
            pushOut->y = MUL_FIXED12_NO_ROUND(axisY->y, overlapY);
            pushOut->z = MUL_FIXED12_NO_ROUND(axisY->z, overlapY);
        }
        return 1;
    }
    if (pushOut != NULL) {
        if (distanceX <= 0) {
            overlapX = -overlapX;
        }
        pushOut->x = MUL_FIXED12_NO_ROUND(axes->x, overlapX);
        pushOut->y = MUL_FIXED12_NO_ROUND(axes->y, overlapX);
        pushOut->z = MUL_FIXED12_NO_ROUND(axes->z, overlapX);
        pushOut->y = 0;
    }
    return 3;
}

s32 ComputeSphereHitOnRotatedCylinder(Vec3 *sphereCenter, Vec3 *cylinderCenter, Vec3 *axes, s32 cylinderRadius,
                                      s32 halfHeightPositive, s32 halfHeightNegative, s32 sphereRadius, Vec3 *pushOut) {
    Vec3 delta;
    Vec3 local;
    s32 overlapY;
    s32 horizontalDistance;
    s32 overlapRadial;
    Vec3 *axisY;
    Vec3 *axisZ;

    axisY = &axes[1];
    axisZ = &axes[2];

    VEC_Subtract(sphereCenter, cylinderCenter, &delta);
    local.y = Vec3DotUnrounded(&delta, axisY);
    if (local.y >= halfHeightPositive + sphereRadius || local.y <= -(halfHeightNegative + sphereRadius)) {
        return 0;
    }
    if (local.y > 0) {
        overlapY = (halfHeightPositive + sphereRadius) - local.y;
    } else {
        overlapY = local.y + (halfHeightNegative + sphereRadius);
    }
    local.x = Vec3DotUnrounded(&delta, axes);
    local.y = 0;
    local.z = Vec3DotUnrounded(&delta, axisZ);
    horizontalDistance = VEC_Mag(&local);
    if (horizontalDistance >= cylinderRadius + sphereRadius) {
        return 0;
    }
    overlapRadial = (cylinderRadius + sphereRadius) - horizontalDistance;
    if (overlapY < overlapRadial && local.y > 0) {
        if (pushOut != NULL) {
            pushOut->x = MUL_FIXED12_NO_ROUND(axisY->x, overlapY);
            pushOut->y = MUL_FIXED12_NO_ROUND(axisY->y, overlapY);
            pushOut->z = MUL_FIXED12_NO_ROUND(axisY->z, overlapY);
        }
        return 1;
    }
    if (pushOut != NULL) {
        Vec3 radialPush = {0};

        if (LENGTH_SQUARED(local) >= 16) {
            Vec3NormalizeAndGetLengthUnchecked(&local, &radialPush);
        }
        radialPush.x = MUL_FIXED12_NO_ROUND(radialPush.x, overlapRadial);
        radialPush.y = 0;
        radialPush.z = MUL_FIXED12_NO_ROUND(radialPush.z, overlapRadial);
        pushOut->x = MUL_FIXED12_NO_ROUND(axes->x, radialPush.x) + MUL_FIXED12_NO_ROUND(axisZ->x, radialPush.z);
        pushOut->y = MUL_FIXED12_NO_ROUND(axes->y, radialPush.x) + MUL_FIXED12_NO_ROUND(axisZ->y, radialPush.z);
        pushOut->z = MUL_FIXED12_NO_ROUND(axes->z, radialPush.x) + MUL_FIXED12_NO_ROUND(axisZ->z, radialPush.z);
    }
    return 2;
}

void BlendDirectionTowardVector(Vec3 *direction, s32 blendFactor, Vec3 *target, Vec3 *result) {
    Vec3 scaled;
    s32 negatedDot;
    s32 blend;
    s32 remaining;
    s32 blendProduct;
    s32 directionScale;
    s32 extra;

    negatedDot = -Vec3DotUnrounded(direction, target);
    blend = MUL_FIXED12_NO_ROUND(0x1000 - negatedDot, blendFactor);
    if (blend > 0x1000) {
        blend = 0x1000;
    }
    remaining = 0x1000 - blend;
    blendProduct = MUL_FIXED12_NO_ROUND(blend, remaining);
    extra = MUL_FIXED12_NO_ROUND(negatedDot + 0x1000, blendProduct >> 1);
    directionScale = remaining + extra;
    scaled.x = MUL_FIXED12_NO_ROUND(direction->x, directionScale);
    scaled.y = MUL_FIXED12_NO_ROUND(direction->y, directionScale);
    scaled.z = MUL_FIXED12_NO_ROUND(direction->z, directionScale);
    VEC_MultAdd(blend + extra, target, &scaled, result);
}

void BlendDirectionTowardUp(Vec3 *direction, s32 blendFactor) {
    s32 blend;
    s32 negatedY;
    s32 remaining;
    s32 blendProduct;
    s32 extra;
    s32 directionScale;

    negatedY = -direction->y;
    blend = MUL_FIXED12_NO_ROUND(0x1000 - negatedY, blendFactor);
    if (blend > 0x1000) {
        blend = 0x1000;
    }
    remaining = 0x1000 - blend;
    blendProduct = MUL_FIXED12_NO_ROUND(blend, remaining);
    negatedY += 0x1000;
    extra = MUL_FIXED12_NO_ROUND(negatedY, blendProduct >> 1);
    directionScale = remaining + extra;
    blend = blend + extra;
    direction->x = MUL_FIXED12_NO_ROUND(direction->x, directionScale);
    direction->y = MUL_FIXED12_NO_ROUND(direction->y, directionScale);
    direction->z = MUL_FIXED12_NO_ROUND(direction->z, directionScale);
    direction->y += blend;
}

void BounceVelocityOffSurface(Vec3 *velocity, Vec3 *surfaceNormal, s32 tangentScale, s32 bounceScale,
                              s32 minNormalSpeed, Vec3 *result) {
    Vec3 normal;
    Vec3 normalPart;
    s32 normalSpeed;
    s32 negatedBounce;
    s32 length;

    normal = *surfaceNormal;
    if (normal.y > 0) {
        normal.y = 0;
        length = 0;
        if (LENGTH_SQUARED(normal) >= 16) {
            length = Vec3NormalizeAndGetLengthUnchecked(&normal, &normal);
        }
        if (length == 0) {
            *result = *velocity;
            return;
        }
    }
    normalSpeed = VEC_DotProduct(&normal, velocity);
    normalPart.x = MUL_FIXED12_NO_ROUND(normal.x, normalSpeed);
    normalPart.y = MUL_FIXED12_NO_ROUND(normal.y, normalSpeed);
    normalPart.z = MUL_FIXED12_NO_ROUND(normal.z, normalSpeed);
    result->x = velocity->x - normalPart.x;
    result->y = velocity->y - normalPart.y;
    result->z = velocity->z - normalPart.z;
    negatedBounce = -bounceScale;
    result->x = MUL_FIXED12_NO_ROUND(result->x, tangentScale);
    result->y = MUL_FIXED12_NO_ROUND(result->y, tangentScale);
    result->z = MUL_FIXED12_NO_ROUND(result->z, tangentScale);
    normalPart.x = MUL_FIXED12_NO_ROUND(normalPart.x, negatedBounce);
    normalPart.y = MUL_FIXED12_NO_ROUND(normalPart.y, negatedBounce);
    normalPart.z = MUL_FIXED12_NO_ROUND(normalPart.z, negatedBounce);
    if (HORIZONTAL_LENGTH_SQUARED(normalPart) < (s64) minNormalSpeed * minNormalSpeed) {
        normalPart.x = MUL_FIXED12_NO_ROUND(normal.x, minNormalSpeed);
        normalPart.y = MUL_FIXED12_NO_ROUND(normal.y, minNormalSpeed);
        normalPart.z = MUL_FIXED12_NO_ROUND(normal.z, minNormalSpeed);
    }
    VEC_Add(&normalPart, result, result);
}

void BounceVelocityOffUnnormalizedSurface(Vec3 *velocity, Vec3 *surfaceNormal, s32 tangentScale, s32 bounceScale,
                                          s32 minNormalSpeed, Vec3 *result) {
    Vec3 normal;
    s32 length;

    if (surfaceNormal->y <= 0) {
        normal = *surfaceNormal;
        length = 0;
        if (LENGTH_SQUARED(normal) >= 16) {
            length = Vec3NormalizeAndGetLengthUnchecked(&normal, &normal);
        }
        if (length == 0) {
            *result = *velocity;
            return;
        }
        BounceVelocityOffSurface(velocity, &normal, tangentScale, bounceScale, minNormalSpeed, result);
    } else {
        BounceVelocityOffSurface(velocity, surfaceNormal, tangentScale, bounceScale, minNormalSpeed, result);
    }
}

void DrawNsbmdWithMatrixAndMaxAlpha(Nsbmd *model, void *matrix, void *scale, s32 maxAlpha) {
    void *resMdl;
    s32 modelAlpha;
    s32 polygonId;

    resMdl = model->mResMdl;
    modelAlpha = NNS_G3dMdlGetMdlAlpha(resMdl, 0);
    if (maxAlpha < modelAlpha) {
        polygonId = NNS_G3dMdlGetMdlPolygonID(resMdl, 0);
        NNS_G3dMdlSetMdlPolygonIDAll(resMdl, AllocPolygonIdWrapping());
        NNS_G3dMdlSetMdlAlphaAll(resMdl, maxAlpha);
        DrawNsbmdWithMatrix(model, matrix, scale);
        NNS_G3dMdlSetMdlPolygonIDAll(resMdl, polygonId);
        NNS_G3dMdlSetMdlAlphaAll(resMdl, modelAlpha);
    } else {
        DrawNsbmdWithMatrix(model, matrix, scale);
    }
}

void DrawShadowWithMaxAlpha(ShadowModel *shadow, void *matrix, Vec3 *scale, u32 maxAlpha) {
    u16 savedAlpha;

    savedAlpha = shadow->mAlpha;
    if (maxAlpha < savedAlpha) {
        shadow->mAlpha = maxAlpha;
        DrawShadowWithMatrix(shadow, matrix, scale);
        shadow->mAlpha = savedAlpha;
    } else {
        DrawShadowWithMatrix(shadow, matrix, scale);
    }
}

void SendMaterialPolygonAttributes(void) {
    NNS_G3dGeBufferOP_N(0x29, &gWoodbox1PolyAttr, 1);
}

void DrawNsbmdWithMaxAlpha(Nsbmd *model, s32 maxAlpha) {
    void *resMdl;
    s32 modelAlpha;
    s32 savedAlpha;

    resMdl = model->mResMdl;
    modelAlpha = NNS_G3dMdlGetMdlAlpha(resMdl, 0);
    gSavedModelAlpha = modelAlpha;
    if (maxAlpha < modelAlpha) {
        NNS_G3dMdlSetMdlPolygonIDAll(resMdl, AllocPolygonIdWrapping());
        NNS_G3dMdlSetMdlAlphaAll(resMdl, maxAlpha);
    }
    DrawNsbmd(model);
    savedAlpha = gSavedModelAlpha;
    if (maxAlpha < savedAlpha) {
        NNS_G3dMdlSetMdlAlphaAll(resMdl, savedAlpha);
    }
    gSavedModelAlpha = -1;
}

void DrawNsbmd1Mat1ShpWithMaxAlpha(Nsbmd *model, s32 maxAlpha) {
    void *resMdl;
    s32 modelAlpha;
    s32 savedAlpha;

    resMdl = model->mResMdl;
    modelAlpha = NNS_G3dMdlGetMdlAlpha(resMdl, 0);
    gSavedModelAlpha = modelAlpha;
    if (maxAlpha < modelAlpha) {
        NNS_G3dMdlSetMdlPolygonIDAll(resMdl, AllocPolygonIdWrapping());
        NNS_G3dMdlSetMdlAlphaAll(resMdl, maxAlpha);
    }
    NNS_G3dDraw1Mat1Shp(model->mResMdl, 0, 0, 1);
    savedAlpha = gSavedModelAlpha;
    if (maxAlpha < savedAlpha) {
        NNS_G3dMdlSetMdlAlphaAll(resMdl, savedAlpha);
    }
    gSavedModelAlpha = -1;
}

void DrawNsbmdWithMaxAlphaAndMaterial(Nsbmd *model, s32 maxAlpha) {
    NNSG3dResMdl *resMdl;
    NNSG3dResMat *resMat;
    NNSG3dResMatData *matData;
    s32 modelAlpha;
    s32 savedAlpha;

    resMdl = model->mResMdl;
    modelAlpha = NNS_G3dMdlGetMdlAlpha(resMdl, 0);
    gSavedModelAlpha = modelAlpha;
    if (maxAlpha < modelAlpha) {
        NNS_G3dMdlSetMdlPolygonIDAll(resMdl, AllocPolygonIdWrapping());
        NNS_G3dMdlSetMdlAlphaAll(resMdl, maxAlpha);
    }
    resMat = OFFSET_PTR(NNSG3dResMat, resMdl, resMdl->mOfsMat);
    matData = OFFSET_PTR(NNSG3dResMatData, resMat, ((u32 *) OFFSET_PTR(u8, resMat, resMat->mDict.mOfsEntry))[2]);
    gWoodbox1PolyAttr = matData->mPolyAttr;
    NNS_G3dRenderObjSetCallBack(&model->mRenderObj, (NNSG3dSbcCallBackFunc) SendMaterialPolygonAttributes, 0, 4, 3);
    DrawNsbmd(model);
    savedAlpha = gSavedModelAlpha;
    if (maxAlpha < savedAlpha) {
        NNS_G3dMdlSetMdlAlphaAll(resMdl, savedAlpha);
    }
    gSavedModelAlpha = -1;
}

