#include "Main/MapObjects/rotary.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/data_02158000.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/nsbmd_model_draw.h"

#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/bridge.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/System/heap_call.h"
#include "Main/System/state_machine_init.h"
#include "Main/MapObjects/data_0217b000.h"
#include "code_02147cd8.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/pukupuku_init.h"
#include "Main/MapObjects/rotary_state.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/bridge_animation_frame.h"

#pragma thumb off

StateCallbacks gRotaryStateTable[4] = {{EnterRotaryState0, UpdateRotaryState0},
                                       {RotaryState1Nop, UpdateRotaryState1},
                                       {EnterRotaryState2, UpdateRotaryState2},
                                       {RotaryState3Nop, UpdateRotaryState3}};
const RotaryKindInfo gRotaryTestCylinderKindInfo = {0, 0x12b000, 0x32000, 0, 0x165, 1, 0x177};
const RotaryKindInfo gRotaryRoomKindInfo = {1, 0x1d8000, 0x19000, 3, 0x800, 1, 0x16a};
const RotaryKindInfo gRotaryGearBlackKindInfo = {1, 0x12c000, 0x32000, 1, 0x800, 1, 0x177};
const MapObjectKindDescriptor gRotaryGearBlackKindDescriptor = {0,
                                                   {0, 0},
                                                   0x160,
                                                   InitRotary,
                                                   CreateRotaryGearTestCylinderKindData,
                                                   (MapObjectList * (*) (void) ) CreateRotaryDrawList,
                                                   0,
                                                   0,
                                                   CreateRotaryUpdateList};
const MapObjectKindDescriptor gRotaryRoomKindDescriptor = {0,
                                                   {0, 0},
                                                   0x160,
                                                   InitRotary,
                                                   CreateRotaryRoomKindData,
                                                   (MapObjectList * (*) (void) ) CreateRotaryDrawList,
                                                   0,
                                                   0,
                                                   CreateRotaryUpdateList};
const RotaryKindInfo gRotaryBridgeKindInfo = {0, 0x50000, 0x866000, 4, 0x800, 1, -1};
const MapObjectKindDescriptor gRotaryTestCylinderKindDescriptor = {0,
                                                   {0, 0},
                                                   0x160,
                                                   InitRotary,
                                                   CreateRotaryGearTestCylinderKindData,
                                                   (MapObjectList * (*) (void) ) CreateRotaryDrawList,
                                                   0,
                                                   0,
                                                   CreateRotaryUpdateList};
const MapObjectKindDescriptor gRotaryBridgeKindDescriptor = {0,
                                                   {0, 0},
                                                   0x160,
                                                   InitRotary,
                                                   CreateRotaryBridgeKindData,
                                                   (MapObjectList * (*) (void) ) CreateRotaryDrawList,
                                                   0,
                                                   0,
                                                   CreateRotaryUpdateList};

void UpdateRotaryState3(void *stateObject) {
    Rotary *object = stateObject;
    if (object->mCollisionMapObject.mMapObject.mStateMachine.mStateFrames > object->mPauseFrameCount) {
        object->mCollisionMapObject.mMapObject.mStateMachine.mNextState = ROTARY_STATE_RAMP_UP;
        object->mCollisionMapObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void DrawAllRotaries(void *viewMatrix) {
    DrawVisibleMapObjects(gRotaryDrawList, viewMatrix, DrawMapObjectModelAtPos);
}

BOOL IsRotaryKind(s32 kind) {
    switch (kind) {
        case MAP_OBJECT_KIND_ROTARY_GEAR:
        case 0xce:
        case 0xd0:
        case 0xd1:
            return TRUE;
        default:
            return FALSE;
    }
}

#pragma thumb on

void CreateRotary(BridgeDrawList *list) {
    Rotary *object;
    s32 objectIndex;
    s32 modelIndex;
    s32 objectCount;
    s32 assignIndex;
    s32 assignCount;
    u32 *loadedFlagSlot;
    u32 modelLoaded[ROTARY_MODEL_COUNT];

    for (modelIndex = 0; modelIndex < ROTARY_MODEL_COUNT; modelIndex++) {
        modelLoaded[modelIndex] = 0;
    }
    objectCount = list->mMapObjectList.mMapObjectCount;
    for (objectIndex = 0; objectIndex < objectCount; objectIndex++) {
        object = list->mMapObjectList.mMapObjects[objectIndex];
        loadedFlagSlot = &modelLoaded[object->mModelIndex];
        if (modelLoaded[object->mModelIndex] == 0) {
            switch (object->mModelIndex) {
                case ROTARY_MODEL_TEST_CYLINDER:
                    CreateNsbmd(&gTestCylinder, FindCourseMapObjFile("test_cylinder.nsbmd"), NULL);
                    SetNsbmdPolygonIdLightEmiAll(gTestCylinder, 0x3f, 2, 0x294a);
                    break;
                case ROTARY_MODEL_GEAR_BLACK:
                    CreateNsbmd(&gGearBlack, FindCourseMapObjFile("gear_black.nsbmd"), NULL);
                    SetNsbmdPolygonIdLightEmiAll(gGearBlack, 0x3f, 2, 0x294a);
                    break;
                case ROTARY_MODEL_GEAR_WHITE:
                    CreateNsbmd(&gGearWhite, FindCourseMapObjFile("gear_white.nsbmd"), NULL);
                    SetNsbmdPolygonIdLightEmiAll(gGearWhite, 0x3f, 2, 0x294a);
                    break;
                case ROTARY_MODEL_ROOM:
                    CreateNsbmd(&gRotaryRoom, FindCourseMapObjFile("rotary_room.nsbmd"), NULL);
                    SetNsbmdPolygonIdLightEmiAll(gRotaryRoom, 0x3f, 2, 0x294a);
                    break;
                case ROTARY_MODEL_BRIDGE:
                    CreateNsbmd(&gRotaryBridge, FindCourseMapObjFile("rotary_bridge.nsbmd"), NULL);
                    SetNsbmdPolygonIdLightEmiAll(gRotaryBridge, 0x3f, 2, 0x294a);
                    break;
            }
            *loadedFlagSlot = 1;
        }
    }
    assignCount = list->mMapObjectList.mMapObjectCount;
    for (assignIndex = 0; assignIndex < assignCount; assignIndex++) {
        object = list->mMapObjectList.mMapObjects[assignIndex];
        switch (object->mModelIndex) {
            case ROTARY_MODEL_TEST_CYLINDER:
                object->mCollisionMapObject.mModel = gTestCylinder;
                break;
            case ROTARY_MODEL_GEAR_BLACK:
                object->mCollisionMapObject.mModel = gGearBlack;
                break;
            case ROTARY_MODEL_GEAR_WHITE:
                object->mCollisionMapObject.mModel = gGearWhite;
                break;
            case ROTARY_MODEL_ROOM:
                object->mCollisionMapObject.mModel = gRotaryRoom;
                break;
            case ROTARY_MODEL_BRIDGE:
                object->mCollisionMapObject.mModel = gRotaryBridge;
                break;
        }
    }
}

void InitRotaryObjects(BridgeDrawList *list) {
    Rotary *object;
    s32 index;
    s32 previousIndex;
    s32 count;
    u32 zeroFlag;
    u32 zeroHeight;
    Vec3 offset;
    void **objects;
    Rotary *previousObject;

    objects = list->mMapObjectList.mMapObjects;
    previousIndex = -1;
    zeroFlag = 0;
    zeroHeight = 0;
    count = list->mMapObjectList.mMapObjectCount;
    for (index = 0; index < count; index++) {
        object = objects[index];
        if (object->mCollisionMapObject.mMapObject.mKind == MAP_OBJECT_KIND_ROTARY_GEAR) {
            if (previousIndex < 0) {
                object->mCollisionMapObject.mCollisionData.mCollisionFlag = zeroFlag;
            } else {
                previousObject = objects[previousIndex];
                VEC_Subtract(&previousObject->mCollisionMapObject.mMapObject.mPos,
                             &object->mCollisionMapObject.mMapObject.mPos, &offset);
                offset.y = zeroHeight;
                object->mGearRadius = VEC_Mag(&offset);
                previousObject = objects[previousIndex];
                object->mGearRadius -= previousObject->mCollisionMapObject.mMapObject.mExtent.x;
            }
            previousIndex = index;
        }
    }
}

// Rotary: turns up to full speed, keeps that speed, slows down, pauses, then turns the other way; the course row sets
// the timings.
void InitRotary(Rotary *object, struct CourseMapRow *courseRow, RotaryKindInfo *kindInfo) {
    InitStateMachine(&object->mCollisionMapObject.mMapObject.mStateMachine, gRotaryStateTable, 4, object);
    object->mCollisionMapObject.mCollisionData.mPreviousPos = object->mCollisionMapObject.mMapObject.mPos;
    object->mCollisionMapObject.mCollisionData.mPrevMatrix = object->mCollisionMapObject.mMapObject.mMatrix.mAxes;
    object->mCollisionMapObject.mCollisionData.mInitialMatrix = object->mCollisionMapObject.mMapObject.mMatrix.mAxes;
    object->mCollisionMapObject.mCollisionData.mAngleChangeVector.x = 0;
    object->mCollisionMapObject.mCollisionData.mAngleChangeVector.y = 0;
    object->mCollisionMapObject.mCollisionData.mAngleChangeVector.z = 0;
    object->mCollisionMapObject.mCollisionData.mTracksNormal = kindInfo->mUsesAxis1 != 0 ? 0 : 1;
    object->mRampFrameCount = courseRow->mSettings[2];
    object->mSteadyFrameCount = courseRow->mSettings[1];
    object->mPauseFrameCount = courseRow->mSettings[3];
    object->mAnglePerFrame = courseRow->mSettings[0] * 0x80 / 100;
    if (courseRow->mSettings[4] != 0) {
        object->mAnglePerFrame = -object->mAnglePerFrame;
    }
    object->mCollisionMapObject.mMapObject.mAngle = 0;
    if (object->mRampFrameCount != 0) {
        object->mSpeedFractionPerFrame = 0x1000 / object->mRampFrameCount;
    } else {
        object->mSpeedFractionPerFrame = 0;
    }
    object->mSpeedFraction = 0;
    object->mCollisionMapObject.mCollisionData.mHalfSizeX =
        MUL_FIXED12_NO_ROUND(kindInfo->mRadius, object->mCollisionMapObject.mMapObject.mScale.x);
    object->mCollisionMapObject.mCollisionData.mHalfSizeY =
        MUL_FIXED12_NO_ROUND(kindInfo->mHeight, object->mCollisionMapObject.mMapObject.mScale.y) >> 1;
    if (kindInfo->mUsesAxis1 != 0) {
        object->mCollisionMapObject.mCollisionData.mAxis0Flag = FALSE;
        object->mCollisionMapObject.mCollisionData.mHitFlagWords.x = 1;
    } else {
        object->mCollisionMapObject.mCollisionData.mAxis0Flag = TRUE;
        object->mCollisionMapObject.mCollisionData.mHitFlagWords.x = 0;
    }
    object->mCollisionMapObject.mCollisionData.mHitFlagWords.z = 0;
    object->mCollisionMapObject.mCollisionData.mFloorThreshold = kindInfo->mSignedNormalYLimit;
    object->mCollisionMapObject.mCollisionData.mShape = COLLISION_SHAPE_CYLINDER;
    object->mCollisionMapObject.mCollisionData.mCollisionFlag = kindInfo->mCollisionFlag;
    object->mCollisionMapObject.mMapObject.mFlags |= gRotaryFlag;
    object->mCollisionMapObject.mMapObject.mStateMachine.mNextState = ROTARY_STATE_RAMP_UP;
    object->mCollisionMapObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    object->mModelIndex = kindInfo->mModelIndex;
    if (object->mModelIndex == ROTARY_MODEL_GEAR_BLACK && courseRow->mSettings[5] == 0) {
        object->mModelIndex = ROTARY_MODEL_GEAR_WHITE;
    }
    object->mCollisionMapObject.mMapObject.mFlags &= ~2;
    object->mCollisionMapObject.mMapObject.mFlags &= ~8;
    object->mCollisionMapObject.mMapObject.mAlpha = MAP_OBJECT_ALPHA_MAX;
    if (kindInfo->mModelIndex == 0) {
        object->mSoundId = courseRow->mRotationDegrees.x > 0 ? 0x175 : 0x176;
    } else {
        object->mSoundId = kindInfo->mSoundId;
    }
    if (object->mSoundId != -1) {
        CreateMapObjectSoundSourceFalloff3(&object->mCollisionMapObject.mMapObject);
    }
}

#pragma thumb off

const u16 gRotaryFlag = 1;

