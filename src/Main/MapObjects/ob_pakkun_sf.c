#include "Main/MapObjects/ob_pakkun_sf.h"

#include "Main/MapObjects/attractor_distance_flag.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/System/state_machine_init.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "Main/Item/item_koura_w.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/map_object_response_and_quaternion_math.h"
#include "Main/MapObjects/pushed_motion.h"
#include "ITCM/kart_motion.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/MapObjects/pushed_object_states_init.h"
#include "Main/MapObjects/nsbmd_model_draw_variants.h"
#include "Main/MapObjects/view_matrix_queue.h"
#include "Main/MapObjects/woodbox1_kind_data.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "Main/MapObjects/choropu_state.h"
#include "Main/MapObjects/pendulum.h"
#include "Main/Course/course_triangle_flag.h"
#include "Main/MapObjects/second_hand_kind_descriptor.h"

const MapObjectList gSecondHandUpdateListData = {NULL, 0, {0, 0}, NULL, NULL, UpdateSecondHand, NULL, 0, NULL, 0, NULL};
const MapObjectDrawList gSecondHandDrawListData = {{NULL,
                                                    0,
                                                    {0, 0},
                                                    (void (*)(MapObjectList *)) CreateSecondHand,
                                                    NULL,
                                                    DrawSecondHand,
                                                    NULL,
                                                    1,
                                                    NULL,
                                                    0,
                                                    NULL},
                                                   0};
const MapObjectKindData gSecondHandKindData = {
    (s32(*)(MapObject *, void *, s32 *, s32 *)) CollideKartWithSecondHand,
    (s32(*)(MapObject *, void *, void *, void *)) CollideItemObjectWithSecondHand,
    5,
    0xf000,
    0x4b000,
    0x320000,
    (s32(*)(MapObject *, Vec3 *, s32, Vec3 *)) ComputeSphereHitOnSecondHand,
    0,
    0,
    0x178,
    0,
    0,
    0,
    0,
    0,
    0};
const u32 gSecondHandHitFlag = 0x40000000;
MapObjectList *gSecondHandUpdateList;
MapObjectDrawList *gSecondHandDrawList;
struct Nsbmd *gSecondHand;

void DrawObPakkunSf(u32 unused, ObPakkunSf *obPakkunSf, u32 unusedArg, u16 alpha) {
    MtxFx43 *matrix;
    gObPakkunSf->mFrameIndex = ((obPakkunSf->mFramesSinceInit & OB_PAKKUN_SF_FRAME_TOGGLE_BIT) >> 4);
    if (obPakkunSf->mPushedObject.mMapObject.mStateMachine.mState == PUSHED_OBJECT_STATE_IDLE) {
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
    if ((obPakkunSf->mFramesSinceInit & OB_PAKKUN_SF_SOUND_FRAME_MASK) == 0 &&
        (obPakkunSf->mPushedObject.mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE) == 0) {
        if (obPakkunSf->mPushedObject.mMapObject.mFarDistanceSquared ==
            gSoundFalloffs[SOUND_FALLOFF_SHORT_RANGE].mFarDistanceSquared) {
            falloffIndex = SOUND_FALLOFF_SHORT_RANGE;
        } else if (obPakkunSf->mPushedObject.mMapObject.mFarDistanceSquared ==
                   gSoundFalloffs[SOUND_FALLOFF_MEDIUM_RANGE].mFarDistanceSquared) {
            falloffIndex = SOUND_FALLOFF_MEDIUM_RANGE;
        } else {
            falloffIndex = SOUND_FALLOFF_LONG_RANGE;
        }
        soundRequest.mSoundId = OB_PAKKUN_SF_SOUND_ID;
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
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectKindData));
    *kindData = gSecondHandKindData;
    return kindData;
}

MapObjectList *CreateSecondHandDrawList(void) {
    MapObjectDrawList *drawList;
    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectDrawList));
    gSecondHandDrawList = drawList;
    *drawList = gSecondHandDrawListData;
    SetDrawListSlot(&gSecondHandDrawList);
    return &gSecondHandDrawList->mList;
}

MapObjectList *CreateSecondHandUpdateList(void) {
    MapObjectList *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectList));
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

void EnterSecondHandSpeedUp(void *stateObject) {
    SecondHand *secondHand = stateObject;
    secondHand->mSpeedFraction = 0x0u;
}

void UpdateSecondHandSpeedUp(void *stateObject) {
    SecondHand *secondHand = stateObject;
    secondHand->mSpeedFraction = secondHand->mSpeedFraction + secondHand->mSpeedFractionPerFrame;
    secondHand->mMapObject.mAngle = secondHand->mMapObject.mAngle +
                                    (s16) MUL_FIXED12_NO_ROUND(secondHand->mSpeedFraction, secondHand->mAnglePerFrame);
    if (secondHand->mMapObject.mStateMachine.mStateFrames > secondHand->mRampFrameCount) {
        secondHand->mMapObject.mStateMachine.mNextState = SECOND_HAND_STATE_STEADY;
        secondHand->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void SecondHandSteadyNop(void *stateObject) {}

void UpdateSecondHandSteady(void *stateObject) {
    SecondHand *secondHand = stateObject;
    secondHand->mMapObject.mAngle = secondHand->mMapObject.mAngle + secondHand->mAnglePerFrame;
    if (secondHand->mSteadyFrameCount == 0) {
        return;
    }
    if (secondHand->mMapObject.mStateMachine.mStateFrames > secondHand->mSteadyFrameCount) {
        secondHand->mMapObject.mStateMachine.mNextState = SECOND_HAND_STATE_SLOW_DOWN;
        secondHand->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterSecondHandSlowDown(void *stateObject) {
    SecondHand *secondHand = stateObject;
    secondHand->mSpeedFraction = 0x4000u;
}

void UpdateSecondHandSlowDown(void *stateObject) {
    SecondHand *secondHand = stateObject;
    secondHand->mSpeedFraction = secondHand->mSpeedFraction - secondHand->mSpeedFractionPerFrame;
    secondHand->mMapObject.mAngle = secondHand->mMapObject.mAngle +
                                    (s16) MUL_FIXED12_NO_ROUND(secondHand->mSpeedFraction, secondHand->mAnglePerFrame);
    if (secondHand->mMapObject.mStateMachine.mStateFrames > secondHand->mRampFrameCount) {
        secondHand->mAnglePerFrame = -secondHand->mAnglePerFrame;
        secondHand->mMapObject.mStateMachine.mNextState = SECOND_HAND_STATE_PAUSE;
        secondHand->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void SecondHandPauseNop(void *stateObject) {}

void UpdateSecondHandPause(void *stateObject) {
    SecondHand *secondHand = stateObject;
    if (secondHand->mMapObject.mStateMachine.mStateFrames > secondHand->mPauseFrameCount) {
        secondHand->mMapObject.mStateMachine.mNextState = SECOND_HAND_STATE_SPEED_UP;
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

u32 CollideItemObjectWithSecondHand(u32 secondHand, u32 itemObject, u32 firstResponse, const u8 *response) {
    return *response;
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

#pragma thumb off
