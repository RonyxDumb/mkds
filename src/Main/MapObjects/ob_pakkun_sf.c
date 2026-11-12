#include "Main/MapObjects/ob_pakkun_sf.h"

#include "Main/MapObjects/data_02159000.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/System/state_machine_init.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "Main/Item/item_koura_w.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/code_020d6dc0.h"
#include "Main/MapObjects/pushed_motion.h"
#include "ITCM/kart_motion.h"
#include "ITCM/code_01ffc000.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/MapObjects/pushed_object_states_init.h"
#include "Main/MapObjects/code_020e66e4.h"
#include "Main/MapObjects/code_020e6a74.h"
#include "Main/MapObjects/code_020ec1fc.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/MapObjects/choropu_state.h"
#include "Main/MapObjects/pendulum.h"

const MapObjectList gSecondHandUpdateListData = {NULL, 0, {0, 0}, NULL, NULL, UpdateSecondHand, NULL, 0, NULL, 0, NULL};
const MapObjectDrawList gSecondHandDrawListData = {{NULL, 0, {0, 0}, (void (*)(MapObjectList *)) CreateSecondHand, NULL, (UnkFunc *) DrawSecondHand, NULL, 1, NULL, 0, NULL}, 0};
const MapObjectKindData gSecondHandKindData = {(s32 (*)(MapObject *, void *, s32 *, s32 *)) CollideKartWithSecondHand, (s32 (*)(MapObject *, void *, void *, void *)) CollideItemObjectWithSecondHand, 5, 0xf000, 0x4b000, 0x320000, (s32 (*)(MapObject *, Vec3 *, s32, Vec3 *)) ComputeSphereHitOnSecondHand, 0, 0, 0x178, 0, 0, 0, 0, 0, 0};
StateCallbacks gSecondHandStateTable[4] = {{EnterSecondHandState0, UpdateSecondHandState0}, {(UnkFunc *) SecondHandState1ReturnArgument, UpdateSecondHandState1}, {EnterSecondHandState2, UpdateSecondHandState2}, {(UnkFunc *) SecondHandState3ReturnArgument, UpdateSecondHandState3}};
MapObjectDrawList *gSecondHandDrawList;
struct Nsbmd *gSecondHand;
MapObjectList *gSecondHandUpdateList;

void DrawObPakkunSf(u32 unused, ObPakkunSf *obPakkunSf, u32 unusedArg, u16 alpha) {
    MtxFx43 *matrix;
    gObPakkunSf->mFrameIndex = ((obPakkunSf->mFramesSinceInit & 0x10) >> 4);
    if (obPakkunSf->mPushedObject.mMapObject.mStateMachine.mState == 0) {
        matrix = SetViewRotatedMatrixPos(&obPakkunSf->mPushedObject.mMapObject.mPos);
        DrawNsbmdModelWithMatrixAndMaxAlpha(gObPakkunSf, matrix, &obPakkunSf->mPushedObject.mMapObject.mScale, 0,
                                            alpha);
        return;
    }
    matrix = SetViewRotatedMatrixPos(&obPakkunSf->mPushedObject.mMapObject.mPos);
    DrawNsbmdModelWithMatrixAndAngle(gObPakkunSf, matrix, obPakkunSf->mPushedObject.mMotion.mAngle,
                                     &obPakkunSf->mPushedObject.mMapObject.mScale, 0, alpha);
}

void UpdateObPakkunSf(u32 unused, ObPakkunSf *obPakkunSf) {
    SoundStartParams soundRequest;
    s32 falloffIndex;

    obPakkunSf->mFramesSinceInit = obPakkunSf->mFramesSinceInit + 1;
    if ((obPakkunSf->mFramesSinceInit & 0x1f) == 0 &&
        (obPakkunSf->mPushedObject.mMapObject.mDistanceSquaredAndFlags & 4) == 0) {
        if (obPakkunSf->mPushedObject.mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
            falloffIndex = 2;
        } else if (obPakkunSf->mPushedObject.mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
            falloffIndex = 3;
        } else {
            falloffIndex = 4;
        }
        soundRequest.mSoundId = 0x163;
        soundRequest.mPositionSource = &obPakkunSf->mPushedObject.mMapObject.mPos;
        soundRequest.mFalloffIndex = falloffIndex;
        soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&obPakkunSf->mPushedObject.mMapObject.mPos);
        StartSoundFromParams(&soundRequest);
    }
    AdvanceStateMachine(&obPakkunSf->mPushedObject.mMapObject.mStateMachine);
}

u8 CollideKartWithObPakkunSf(ObPakkunSf *obPakkunSf, void *kart, u8 *firstResponse, u8 *response) {
    if (HitPushedObjectByKart(&obPakkunSf->mPushedObject, kart, firstResponse) != FALSE) {
        StartSoundIfKartStarOrKiller(&obPakkunSf->mPushedObject.mMapObject, kart);
    }
    return *response;
}

u8 CollideItemObjectWithObPakkunSf(ObPakkunSf *obPakkunSf, void *itemObject, u8 *firstResponse, u8 *response) {
    HitPushedObjectByItemObject(&obPakkunSf->mPushedObject, itemObject, firstResponse);
    return *response;
}

#pragma thumb on

void CreateObPakkunSf(void) {
    void *nsbmdFile;
    void *nsbtpFile;
    nsbmdFile = FindCourseMapObjFile("ob_pakkun_sf.nsbmd");
    nsbtpFile = FindCourseMapObjFile("ob_pakkun_sf.nsbtp");
    CreateNsbmdModel(&gObPakkunSf, nsbmdFile, nsbtpFile, 0);
    SetNsbmdModelFixedAttributes(gObPakkunSf);
}

#pragma thumb off

#pragma thumb on

void InitObPakkunSf(ObPakkunSf *obPakkunSf) {
    obPakkunSf->mPushedObject.mMapObject.mPos.y =
        obPakkunSf->mPushedObject.mMapObject.mPos.y +
        MUL_FIXED12_NO_ROUND(obPakkunSf->mPushedObject.mMapObject.mScale.y, 0xa000);
    obPakkunSf->mFramesSinceInit = 0;
    InitPushedMotion(&obPakkunSf->mPushedObject, obPakkunSf->mPushedObject.mMapObject.mPos.y - 0x18000, 0x400, 0x800,
                     0x4000, 0x1800);
    InitPushedObjectStates(&obPakkunSf->mPushedObject);
}

#pragma thumb off

MapObjectKindData *CreateSecondHandKindData(void) {
    MapObjectKindData *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = gSecondHandKindData;
    return kindData;
}

MapObjectDrawList *CreateSecondHandDrawList(void) {
    MapObjectDrawList *drawList;
    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gSecondHandDrawList = drawList;
    *drawList = gSecondHandDrawListData;
    SetDrawListSlot(&gSecondHandDrawList);
    return gSecondHandDrawList;
}

MapObjectList *CreateSecondHandUpdateList(void) {
    MapObjectList *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gSecondHandUpdateList = updateList;
    *updateList = gSecondHandUpdateListData;
    SetUpdateListSlot(&gSecondHandUpdateList);
    return gSecondHandUpdateList;
}

void DrawSecondHand(u32 unused, SecondHand *secondHand, u32 unusedArg, u32 alpha) {
    secondHand->mMapObject.mMatrix.mRows[3].x = secondHand->mMapObject.mPos.x >> 4;
    secondHand->mMapObject.mMatrix.mRows[3].y = secondHand->mMapObject.mPos.y >> 4;
    secondHand->mMapObject.mMatrix.mRows[3].z = secondHand->mMapObject.mPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(gSecondHand, &secondHand->mMapObject.mMatrix, &secondHand->mMapObject.mScale, alpha);
}

void UpdateSecondHand(u32 unused, SecondHand *secondHand) {
    AdvanceStateMachine(&secondHand->mMapObject.mStateMachine);
    QuaternionMultiplyAngleAroundY(&secondHand->mInitialRotationQuaternion, secondHand->mMapObject.mAngle,
                                   &secondHand->mRotationQuaternion);
    Matrix3x3FromQuaternion(&secondHand->mMapObject.mMatrix.mAxes, &secondHand->mRotationQuaternion);
}

void EnterSecondHandState0(SecondHand *secondHand) {
    secondHand->mSpeedFraction = 0x0u;
}

void UpdateSecondHandState0(SecondHand *secondHand) {
    secondHand->mSpeedFraction = secondHand->mSpeedFraction + secondHand->mSpeedFractionPerFrame;
    secondHand->mMapObject.mAngle = secondHand->mMapObject.mAngle +
                                    (s16) MUL_FIXED12_NO_ROUND(secondHand->mSpeedFraction, secondHand->mAnglePerFrame);
    if (secondHand->mMapObject.mStateMachine.mStateFrames > secondHand->mRampFrameCount) {
        secondHand->mMapObject.mStateMachine.mNextState = 1;
        secondHand->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

u32 SecondHandState1ReturnArgument(u32 value) {
    return value;
}

void UpdateSecondHandState1(SecondHand *secondHand) {
    secondHand->mMapObject.mAngle = secondHand->mMapObject.mAngle + secondHand->mAnglePerFrame;
    if (secondHand->mSteadyFrameCount == 0) {
        return;
    }
    if (secondHand->mMapObject.mStateMachine.mStateFrames > secondHand->mSteadyFrameCount) {
        secondHand->mMapObject.mStateMachine.mNextState = 2;
        secondHand->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterSecondHandState2(SecondHand *secondHand) {
    secondHand->mSpeedFraction = 0x4000u;
}

void UpdateSecondHandState2(SecondHand *secondHand) {
    secondHand->mSpeedFraction = secondHand->mSpeedFraction - secondHand->mSpeedFractionPerFrame;
    secondHand->mMapObject.mAngle = secondHand->mMapObject.mAngle +
                                    (s16) MUL_FIXED12_NO_ROUND(secondHand->mSpeedFraction, secondHand->mAnglePerFrame);
    if (secondHand->mMapObject.mStateMachine.mStateFrames > secondHand->mRampFrameCount) {
        secondHand->mAnglePerFrame = -secondHand->mAnglePerFrame;
        secondHand->mMapObject.mStateMachine.mNextState = 3;
        secondHand->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

u32 SecondHandState3ReturnArgument(u32 value) {
    return value;
}

void UpdateSecondHandState3(SecondHand *secondHand) {
    if (secondHand->mMapObject.mStateMachine.mStateFrames > secondHand->mPauseFrameCount) {
        secondHand->mMapObject.mStateMachine.mNextState = 0;
        secondHand->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

s32 CollideKartWithSecondHand(SecondHand *secondHand, Kart *kart, s32 unused, u8 *response) {
    u32 itemEffect;

    itemEffect = kart->mItemEffect;
    if (itemEffect == 1 || itemEffect == 3) {
        secondHand->mMapObject.mDistanceSquaredAndFlags |= gSecondHandHitFlag;
    }
    return *response;
}

u32 CollideItemObjectWithSecondHand(u32 secondHand, u32 itemObject, u32 firstResponse, u32 response) {
    return (*OFFSET_PTR(const u8, response, 0));
}

void ComputeSphereHitOnSecondHand(SecondHand *secondHand, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *overlapOffset) {
    Vec3 halfSizesNegative;
    s32 extentY;

    extentY = secondHand->mMapObject.mExtent.y;
    halfSizesNegative.x = secondHand->mMapObject.mExtent.x;
    halfSizesNegative.y = extentY;
    halfSizesNegative.z = 0;
    ComputeSphereHitOnRotatedBox(sphereCenter, &secondHand->mMapObject.mPos, &secondHand->mMapObject.mMatrix.mRows[0],
                                 &secondHand->mMapObject.mExtent, &halfSizesNegative, sphereRadius, overlapOffset);
}

#pragma thumb on

void CreateSecondHand(void) {
    CreateNsbmd(&gSecondHand, FindCourseMapObjFile("second_hand.nsbmd"), NULL);
    SetNsbmdPolygonIdLightEmiAll(gSecondHand, 0x3f, 2, 0x294a);
}

void InitSecondHand(SecondHand *secondHand, CourseMapRow *courseRow) {
    secondHand->mMapObject.mExtent.y = MUL_FIXED12_NO_ROUND(secondHand->mMapObject.mScale.x, 0x4b000);
    InitStateMachine(&secondHand->mMapObject.mStateMachine, gSecondHandStateTable, 4, secondHand);
    QuaternionFromVec3Degrees(&courseRow->mRotationDegrees, &secondHand->mRotationQuaternion);
    secondHand->mInitialRotationQuaternion = secondHand->mRotationQuaternion;
    secondHand->mRampFrameCount = courseRow->mSettings[2];
    secondHand->mSteadyFrameCount = courseRow->mSettings[1];
    secondHand->mPauseFrameCount = courseRow->mSettings[3];
    secondHand->mAnglePerFrame = (courseRow->mSettings[0] << 7) / 0x64;
    if (courseRow->mSettings[4] != 0) {
        secondHand->mAnglePerFrame = -secondHand->mAnglePerFrame;
    }
    secondHand->mMapObject.mAngle = 0;
    if (secondHand->mRampFrameCount != 0) {
        secondHand->mSpeedFractionPerFrame = 0x1000 / secondHand->mRampFrameCount;
    } else {
        secondHand->mSpeedFractionPerFrame = 0;
    }
    secondHand->mSpeedFraction = 0;
    secondHand->mMapObject.mStateMachine.mNextState = 0;
    secondHand->mMapObject.mStateMachine.mNextStateRequested = 1;
    secondHand->mMapObject.mFlags |= gSecondHandFlag;
}

const u32 gSecondHandHitFlag = 0x40000000;

#pragma thumb off
