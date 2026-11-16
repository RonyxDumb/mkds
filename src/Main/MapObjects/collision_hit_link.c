#include "Main/MapObjects/collision_hit_link.h"
#include "Main/System/heap.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"

#include "Main/MapObjects/segment_group_collision.h"
#include "Main/MapObjects/koopa_block_hit_link.h"
#include "Main/MapObjects/map_object_draw_list_flags.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "matrix_3x3_basic.h"
#include "fixed_vector_math.h"
#include "Main/System/heap_call.h"
#include "Main/Kart/kart_drift.h"
#include "Main/MapObjects/choropu_state.h"
#include "Main/MapObjects/bridge.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "Main/MapObjects/koopa_block.h"

const MapObjectList gKoopaBlockUpdateListData = {NULL, 0, {0, 0}, NULL, NULL, UpdateKoopaBlock, NULL, 0, NULL, 0, NULL};
const MapObjectDrawList gKoopaBlockDrawListData = {
    {NULL, 0, {0, 0}, (void (*)(MapObjectList *)) CreateKoopaBlock, NULL, NULL, NULL, 1, NULL, 0, NULL}, 0};
const MapObjectKindData gKoopaBlockKindData = {NULL, NULL, 5, 0x190000, 0x64000, 0xaf000, NULL, 1,
                                               1,    0,    0, 0,        0,       0,       0,    0};
MapObjectDrawList *gKoopaBlockDrawList;
struct MapObjectList *gKoopaBlockUpdateList;

void SetCollisionHitLink(CollisionMapObject *object, Vec3 *position, Vec3 *normal, CollisionHitLink *link) {
    Vec3 offset;
    s32 localZ;
    s32 localY;

    VEC_Subtract(position, &object->mMapObject.mPos, &offset);
    localZ = Vec3DotUnrounded(&offset, &object->mMapObject.mMatrix.mRows[2]);
    localY = Vec3DotUnrounded(&offset, &object->mMapObject.mMatrix.mRows[1]);
    link->mLocalPosition.x = Vec3DotUnrounded(&offset, &object->mMapObject.mMatrix.mRows[0]);
    link->mLocalPosition.y = localY;
    link->mLocalPosition.z = localZ;
    if (normal != NULL && object->mCollisionData.mTracksNormal != FALSE) {
        localZ = Vec3DotUnrounded(normal, &object->mMapObject.mMatrix.mRows[2]);
        localY = Vec3DotUnrounded(normal, &object->mMapObject.mMatrix.mRows[1]);
        link->mLocalNormal.x = Vec3DotUnrounded(normal, &object->mMapObject.mMatrix.mRows[0]);
        link->mLocalNormal.y = localY;
        link->mLocalNormal.z = localZ;
    } else {
        link->mLocalNormal.x = 0;
        link->mLocalNormal.y = 0;
        link->mLocalNormal.z = 0;
    }
    link->mObject = object;
}

void GetCollisionHitLinkPosition(CollisionHitLink *link, Vec3 *outPosition) {
    CollisionMapObject *object = link->mObject;

    if (object == NULL) {
        return;
    }
    MTX_MultVec33(&link->mLocalPosition, &object->mMapObject.mMatrix.mAxes, outPosition);
    VEC_Add(&object->mMapObject.mPos, outPosition, outPosition);
}

BOOL GetCollisionHitLinkPosAndNormal(CollisionHitLink *link, Vec3 *outPosition, Vec3 *outNormal) {
    CollisionMapObject *object = link->mObject;

    if (object != NULL) {
        MTX_MultVec33(&link->mLocalPosition, &object->mMapObject.mMatrix.mAxes, outPosition);
        VEC_Add(&object->mMapObject.mPos, outPosition, outPosition);
        if (object->mCollisionData.mTracksNormal != FALSE) {
            MTX_MultVec33(&link->mLocalNormal, &object->mMapObject.mMatrix.mAxes, outNormal);
            if (outNormal->y < object->mCollisionData.mFloorThreshold) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

// Any map object: the clock gears compare against their radius, every other object returns its collision flag.
s32 IsHitLinkOutsideGearRadiusOrFlagged(CollisionHitLink *link) {
    Rotary *object = (Rotary *) link->mObject;
    s64 horizontalDistanceSquared;
    s64 limitSquared;

    if (object->mCollisionMapObject.mCollisionData.mCollisionFlag != 0 &&
        object->mCollisionMapObject.mMapObject.mKind == MAP_OBJECT_KIND_ROTARY_GEAR) {
        horizontalDistanceSquared = HORIZONTAL_LENGTH_SQUARED(link->mLocalPosition);
        limitSquared = (s64) object->mGearRadius * object->mGearRadius;
        return horizontalDistanceSquared >= limitSquared;
    }
    return object->mCollisionMapObject.mCollisionData.mCollisionFlag;
}

MapObjectKindData *CreateKoopaBlockKindData(void) {
    MapObjectKindData *kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectKindData));

    *kindData = gKoopaBlockKindData;
    return kindData;
}

MapObjectList *CreateKoopaBlockDrawList(void) {
    MapObjectDrawList *drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectDrawList));

    gKoopaBlockDrawList = drawList;
    *drawList = gKoopaBlockDrawListData;
    SetDrawListSlot(&gKoopaBlockDrawList);
    return &gKoopaBlockDrawList->mList;
}

MapObjectList *CreateKoopaBlockUpdateList(void) {
    MapObjectList *updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectList));

    gKoopaBlockUpdateList = updateList;
    *updateList = gKoopaBlockUpdateListData;
    SetUpdateListSlot(&gKoopaBlockUpdateList);
    return gKoopaBlockUpdateList;
}

void UpdateKoopaBlock(void *unused, KoopaBlock *koopaBlock) {
    GroupFollower *follower = &koopaBlock->mFollower;

    if (koopaBlock->mPauseTimer != 0) {
        SoundStartParams soundRequest;
        s32 falloffIndex;

        koopaBlock->mPauseTimer--;
        koopaBlock->mCollisionMapObject.mMapObject.mPosStep.x = 0;
        koopaBlock->mCollisionMapObject.mMapObject.mPosStep.y = 0;
        koopaBlock->mCollisionMapObject.mMapObject.mPosStep.z = 0;
        if (koopaBlock->mPauseTimer != 0) {
            return;
        }
        if ((koopaBlock->mCollisionMapObject.mMapObject.mDistanceSquaredAndFlags &
             MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE) != 0) {
            return;
        }
        falloffIndex = koopaBlock->mCollisionMapObject.mMapObject.mFarDistanceSquared ==
                               gSoundFalloffs[SOUND_FALLOFF_SHORT_RANGE].mFarDistanceSquared
                           ? SOUND_FALLOFF_SHORT_RANGE
                           : (koopaBlock->mCollisionMapObject.mMapObject.mFarDistanceSquared ==
                                      gSoundFalloffs[SOUND_FALLOFF_MEDIUM_RANGE].mFarDistanceSquared
                                  ? SOUND_FALLOFF_MEDIUM_RANGE
                                  : SOUND_FALLOFF_LONG_RANGE);
        soundRequest.mSoundId = KOOPA_BLOCK_SOUND_ID;
        soundRequest.mPositionSource = &koopaBlock->mCollisionMapObject.mMapObject.mPos;
        soundRequest.mFalloffIndex = falloffIndex;
        soundRequest.mDistanceSquared =
            GetHorizontalCameraDistanceSquared(&koopaBlock->mCollisionMapObject.mMapObject.mPos);
        StartSoundFromParams(&soundRequest);
        return;
    }
    if (AdvanceGroupFollower(follower) != FALSE) {
        if (koopaBlock->mCollisionMapObject.mMapObject.mStateMachine.mState == KOOPA_BLOCK_STATE_DECELERATE) {
            koopaBlock->mCollisionMapObject.mMapObject.mStateMachine.mNextState = KOOPA_BLOCK_STATE_ACCELERATE;
            koopaBlock->mCollisionMapObject.mMapObject.mStateMachine.mNextStateRequested = 1;
        }
        koopaBlock->mPauseTimer = follower->mFromEntry->mValue;
    }
    koopaBlock->mCollisionMapObject.mCollisionData.mPreviousPos = koopaBlock->mCollisionMapObject.mMapObject.mPos;
    GetGroupFollowerLinearPosition(follower, &koopaBlock->mCollisionMapObject.mMapObject.mPos);
    AdvanceStateMachine(&koopaBlock->mCollisionMapObject.mMapObject.mStateMachine);
    VEC_Subtract(&koopaBlock->mCollisionMapObject.mMapObject.mPos,
                 &koopaBlock->mCollisionMapObject.mCollisionData.mPreviousPos,
                 &koopaBlock->mCollisionMapObject.mMapObject.mPosStep);
    VEC_MultAdd(-koopaBlock->mCollisionMapObject.mCollisionData.mHalfSizeY,
                &koopaBlock->mCollisionMapObject.mMapObject.mMatrix.mRows[1],
                &koopaBlock->mCollisionMapObject.mMapObject.mPos,
                &koopaBlock->mCollisionMapObject.mCollisionData.mCenterPos);
}

void KoopaBlockAccelerateNop(void *stateObject) {}

void UpdateKoopaBlockAccelerate(void *stateObject) {
    KoopaBlock *koopaBlock = stateObject;
    GroupFollower *follower = &koopaBlock->mFollower;
    s32 progress = GetGroupFollowerProgress(follower);
    s32 angle = (u16) SHIFT_LEFT_FROM_FIXED12(progress, 18);
    s16 sine = FX_SinIdx(angle);
    s32 speed = MUL_FIXED12_NO_ROUND(sine, koopaBlock->mFollowSpeed);
    s32 inverseProgressLength;

    follower->mSpeed = speed > 0x200 ? speed : 0x200;
    inverseProgressLength = follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength;
    if (speed <= 0x200) {
        speed = 0x200;
    }
    follower->mProgressStep = MUL_FIXED12_NO_ROUND(speed, inverseProgressLength);
    if (GetGroupFollowerProgress(follower) >= 0x100) {
        koopaBlock->mCollisionMapObject.mMapObject.mStateMachine.mNextState = KOOPA_BLOCK_STATE_CRUISE;
        koopaBlock->mCollisionMapObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterKoopaBlockCruise(void *stateObject) {
    KoopaBlock *koopaBlock = stateObject;
    s32 speed = koopaBlock->mFollowSpeed;

    koopaBlock->mFollower.mSpeed = speed;
    koopaBlock->mFollower.mProgressStep = MUL_FIXED12_NO_ROUND(
        speed, koopaBlock->mFollower.mPath->mSegments[koopaBlock->mFollower.mSegmentIndex].mInverseProgressLength);
}

void UpdateKoopaBlockCruise(void *stateObject) {
    KoopaBlock *koopaBlock = stateObject;
    GroupFollower *follower = &koopaBlock->mFollower;

    if (follower->mToEntry->mValue == 0) {
        GroupPath *path = follower->mPath;
        BOOL onEndSegment;
        BOOL onEndSegmentOfOpenPath = FALSE;

        if (path->mWraps == 0) {
            if (follower->mForward != 0) {
                onEndSegment = follower->mSegmentIndex == path->mSegmentCount - 1;
            } else {
                onEndSegment = follower->mSegmentIndex == 0;
            }
            if (onEndSegment) {
                onEndSegmentOfOpenPath = TRUE;
            }
        }
        if (onEndSegmentOfOpenPath == FALSE) {
            return;
        }
    }
    if (GetGroupFollowerProgress(follower) >= 0xf00) {
        koopaBlock->mCollisionMapObject.mMapObject.mStateMachine.mNextState = KOOPA_BLOCK_STATE_DECELERATE;
        koopaBlock->mCollisionMapObject.mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void KoopaBlockDecelerateNop(void *stateObject) {}
