#include "01/MapObjects/map_object_animation.h"
#include "01/code_02188e24.h"
#include "01/Race/race_hud_king_cells.h"
#include "01/code_02188de0.h"
#include "01/code_0218c000.h"
#include "01/unk_021a9000.h"
#include "01/code_02188da4.h"
#include "01/code_02188cd8.h"
#include "01/MapObjects/map_object_model_load.h"
#include "01/code_02188950.h"
#include "01/code_02188484.h"
#include "01/code_021882b8.h"
#include "01/code_0218d520.h"
#include "01/Race/mission_run_state.h"
#include "Main/Race/standings_balloons.h"
#include "Main/MapObjects/balloon_draw.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Item/item_koura_w.h"
#include "01/code_02188260.h"
#include "01/code_02188230.h"
#include "01/code_02188218.h"
#include "01/code_0218820c.h"
#include "01/unk_021a7000.h"
#include "code_02012b30.h"
#include "01/code_02188158.h"
#include "Main/Item/item_bomb.h"
#include "01/code_02187eb0.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Course/code_02042044.h"
#include "01/code_02187e78.h"
#include "01/code_02187d14.h"
#include "Main/MapObjects/shine_balloon.h"
#include "Main/MapObjects/kuribo.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "01/MapObjects/periodic_effect.h"
#include "fx_mtx43.h"
#include "code_02147cd8.h"
#include "Main/MapObjects/item_box.h"
#include "Main/MapObjects/earthen_pipe_create.h"
#include "01/code_02187cd4.h"
#include "01/code_0219b250.h"
#include "code_020109c4.h"
#include "01/code_02187c60.h"
#include "01/code_02187c4c.h"
#include "01/code_02187bfc.h"
#include "Main/Graphics/effects.h"
#include "Main/Graphics/emitters.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "01/code_0219e000.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/code_020e66e4.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_kinoko.h"
#include "fx_mtx33.h"
#include "code_0201c528.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "code_0212d214.h"
#include "01/code_0219b240.h"
#include "ITCM/code_01ffd000.h"
#include "01/code_02186000.h"
#include "01/code_02187000.h"
#include "01/unk_021a6000.h"
#include "01/callees_0219b000.h"
#include "Main/Graphics/model_effects.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/bound.h"
#include "01/code_0218b9b4.h"
#include "Main/System/init_after_startup.h"

Vec3 gItemKinokoUpNormal = {0, 0x1000, 0};
Vec3 gItemBombUpNormal = {0, 0x1000, 0};
MapObjectKindDescriptor gEmptyMapObjectKindDescriptor = {0,
                                                         {0, 0},
                                                         0xa0,
                                                         NULL,
                                                         CreateEmptyMapObjectKindData,
                                                         NULL,
                                                         NULL,
                                                         NULL,
                                                         CreateEmptyMapObjectUpdateList,
                                                         NULL,
                                                         {NULL, NULL, NULL, NULL}};
u16 gShadowScaleToggle;

void SetAnimationFrameCallback(MissionRunMapObject *mapObject, s32 frameIndex, UnkFunc *callback) {
    mapObject->mAnimationFrameCallbackFrameIndex = frameIndex;
    mapObject->mAnimationFrameCallback = callback;
}

void SetTwoAnimationFrameCallbacks(MissionRunMapObject *mapObject, s32 firstFrameIndex,
                                   void (*firstCallback)(MissionRunMapObject *), s32 secondFrameIndex,
                                   void (*secondCallback)(MissionRunMapObject *)) {
    mapObject->mUnk_1e0 = firstFrameIndex;
    mapObject->mUnk_1e4 = firstCallback;
    mapObject->mUnk_1e8 = secondFrameIndex;
    mapObject->mUnk_1ec = secondCallback;
}

void StartStateFrameCountCallback(MissionRunMapObject *mapObject, s32 frameCount,
                                  void (*callback)(MissionRunMapObject *)) {
    mapObject->mStateFrameCount = frameCount;
    mapObject->mStateFrames = 0;
    if (callback == NULL) {
        callback = StopMapObjectState;
    }
    mapObject->mStateFrameCountCallback = callback;
}

void SetPointInRangeCallback(MissionRunMapObject *mapObject, s32 pointRadius, s32 pointHalfAngle, Vec3 *point,
                             UnkFunc *callback) {
    UnkFunc *storedCallback;

    mapObject->mPointRadius = pointRadius;
    mapObject->mPointHalfAngle = pointHalfAngle;
    if (point != NULL) {
        mapObject->mPoint = *point;
    }
    storedCallback = callback;
    if (storedCallback == NULL) {
        storedCallback = StopMapObjectState;
    }
    mapObject->mPointInRangeCallback = storedCallback;
}

void SetStoppedCallback(MissionRunMapObject *mapObject, UnkFunc *callback) {
    if (callback == NULL) {
        callback = (UnkFunc *) StopMapObjectState;
    }
    mapObject->mStoppedCallback = callback;
}

void SetCourseCollisionCallback(MissionRunMapObject *mapObject, void (*callback)(MissionRunMapObject *)) {
    if (callback == NULL) {
        callback = (UnkFunc *) StopMapObjectState;
    }
    mapObject->mCourseCollisionCallback = callback;
}

void SetUnusedCallback(MissionRunMapObject *mapObject, UnkFunc *callback) {
    if (callback == NULL) {
        callback = (UnkFunc *) StopMapObjectState;
    }
    mapObject->mUnk_230 = callback;
}

void SetPointInRangePoint(MissionRunMapObject *mapObject, Vec3 *point) {
    if (point != NULL) {
        mapObject->mPoint = *point;
    }
}

void StartAnimationNoEndCallback(MissionRunMapObject *mapObject, s32 animationEntry, s32 frameStep) {
    StartMapObjectModelNsbcaAnimation(mapObject->mNsbmd, (u16) animationEntry, frameStep, 0);
    mapObject->mAnimationEndCallback = NULL;
}

void StartAnimationWithEndCallback(MissionRunMapObject *mapObject, s32 animationEntry, s32 frameStep,
                                   void (*endCallback)(MissionRunMapObject *)) {
    StartMapObjectModelNsbcaAnimation(mapObject->mNsbmd, (u16) animationEntry, frameStep, 1);
    if (endCallback == NULL) {
        endCallback = StopMapObjectState;
    }
    mapObject->mAnimationEndCallback = endCallback;
}

void SetAlphaLimitTargetAndPerCall(MissionRunMapObject *mapObject, s32 alphaLimitTarget, s32 alphaLimitPerCall) {
    mapObject->mAlphaLimitTarget = alphaLimitTarget;
    mapObject->mAlphaLimitPerCall = alphaLimitPerCall;
}

void SetScaleTargetAndPerCall(MissionRunMapObject *mapObject, s32 scaleTarget, s32 scalePerCall) {
    mapObject->mScaleTarget = scaleTarget;
    mapObject->mScalePerCall = scalePerCall;
}

void SetSpeedAndClearTarget(MissionRunMapObject *mapObject, s32 speed) {
    mapObject->mSpeed = speed;
    mapObject->mSpeedTarget = 0;
    mapObject->mSpeedPerCall = 0;
}

void SetSpeedTargetAndPerCall(MissionRunMapObject *mapObject, s32 speedTarget, s32 speedPerCall) {
    mapObject->mSpeedTarget = speedTarget;
    mapObject->mSpeedPerCall = speedPerCall;
}

void StopTurningMoveFollowsAngle(MissionRunMapObject *mapObject) {
    mapObject->mAngleState = MAP_OBJECT_ANGLE_NONE;
    mapObject->mAnglePerCall = 0;
    mapObject->mAnglePerCallTarget = 0;
    mapObject->mAnglePerCallIncrement = 0;
    mapObject->mMoveAngleMode = 1;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = 0;
    mapObject->mMoveAnglePerCallIncrement = 0;
}

void TurnToPointMoveFollowsAngle(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement) {
    mapObject->mAngleState = MAP_OBJECT_ANGLE_TURN_TO_POINT;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mMoveAngleMode = 1;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = 0;
    mapObject->mMoveAnglePerCallIncrement = 0;
}

void TurnAndMoveToPointSameRate(MissionRunMapObject *mapObject, s32 perCallTarget, s32 perCallIncrement) {
    mapObject->mAngleState = MAP_OBJECT_ANGLE_TURN_TO_POINT;
    mapObject->mAnglePerCallTarget = perCallTarget;
    mapObject->mAnglePerCallIncrement = perCallIncrement;
    mapObject->mMoveAngleMode = 2;
    mapObject->mMoveAnglePerCallTarget = perCallTarget;
    mapObject->mMoveAnglePerCallIncrement = perCallIncrement;
}

void TurnFromPointMoveFollowsAngle(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement) {
    mapObject->mAngleState = MAP_OBJECT_ANGLE_TURN_FROM_POINT;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mMoveAngleMode = 1;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = 0;
    mapObject->mMoveAnglePerCallIncrement = 0;
}

void StopTurningMoveFromPoint(MissionRunMapObject *mapObject, s32 moveAnglePerCallTarget,
                              s32 moveAnglePerCallIncrement) {
    mapObject->mAngleState = MAP_OBJECT_ANGLE_NONE;
    mapObject->mAnglePerCall = 0;
    mapObject->mAnglePerCallTarget = 0;
    mapObject->mAnglePerCallIncrement = 0;
    mapObject->mMoveAngleMode = 3;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = moveAnglePerCallTarget;
    mapObject->mMoveAnglePerCallIncrement = moveAnglePerCallIncrement;
}

void TurnSidewaysMoveFollowsAngle(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement,
                                  s32 angleOffset) {
    mapObject->mAngleState = MAP_OBJECT_ANGLE_TURN_SIDEWAYS;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mUnk_1a0 = angleOffset;
    mapObject->mMoveAngleMode = 1;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = 0;
    mapObject->mMoveAnglePerCallIncrement = 0;
}

void TurnToPointMoveSideways(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement,
                             s32 moveAnglePerCallTarget, s32 moveAnglePerCallIncrement, s32 moveAngleOffset) {
    mapObject->mAngleState = MAP_OBJECT_ANGLE_TURN_TO_POINT;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mMoveAngleMode = 4;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = moveAnglePerCallTarget;
    mapObject->mMoveAnglePerCallIncrement = moveAnglePerCallIncrement;
    mapObject->mUnk_1c4 = moveAngleOffset;
}

void SpinAngleStopMoveAngle(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement) {
    mapObject->mAngleState = MAP_OBJECT_ANGLE_SPIN;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mUnk_1a0 = 0;
    mapObject->mMoveAngleMode = 0;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = 0;
    mapObject->mMoveAnglePerCallIncrement = 0;
}

void SpinTowardPointMoveToPoint(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement,
                                s32 moveAnglePerCallTarget, s32 moveAnglePerCallIncrement) {
    s32 angleState;

    if (mapObject->mAngleState == MAP_OBJECT_ANGLE_SPIN_NEGATIVE) {
        angleState = MAP_OBJECT_ANGLE_SPIN_NEGATIVE;
    } else if (mapObject->mAngleState == MAP_OBJECT_ANGLE_SPIN_POSITIVE) {
        angleState = MAP_OBJECT_ANGLE_SPIN_POSITIVE;
    } else {
        angleState = MAP_OBJECT_ANGLE_SPIN_CHOOSE_DIRECTION;
    }
    mapObject->mAngleState = angleState;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mUnk_1a0 = 0;
    mapObject->mMoveAngleMode = 2;
    mapObject->mMoveAnglePerCallTarget = moveAnglePerCallTarget;
    mapObject->mMoveAnglePerCallIncrement = moveAnglePerCallIncrement;
}

void TurnAndMoveToPointOwnRates(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement,
                                s32 moveAnglePerCallTarget, s32 moveAnglePerCallIncrement) {
    mapObject->mAngleState = MAP_OBJECT_ANGLE_TURN_TO_POINT;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mUnk_1a0 = 0;
    mapObject->mMoveAngleMode = 2;
    mapObject->mMoveAnglePerCallTarget = moveAnglePerCallTarget;
    mapObject->mMoveAnglePerCallIncrement = moveAnglePerCallIncrement;
}

void StopMoveAngleTurning(MissionRunMapObject *mapObject) {
    mapObject->mMoveAngleMode = 0;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = 0;
    mapObject->mMoveAnglePerCallIncrement = 0;
}

void SetAnglePointAndMoveAnglePoint(MissionRunMapObject *mapObject, Vec3 *point) {
    if (point != NULL) {
        mapObject->mMoveAnglePoint = *point;
        mapObject->mAnglePoint = *point;
    }
}

void SetMoveAnglePoint(MissionRunMapObject *mapObject, Vec3 *point) {
    if (point != NULL) {
        mapObject->mMoveAnglePoint = *point;
    }
}

void SetAnglePoint(MissionRunMapObject *mapObject, Vec3 *point) {
    if (point != NULL) {
        mapObject->mAnglePoint = *point;
    }
}

void SetVelocity(MissionRunMapObject *mapObject, Vec3 *velocity) {
    if (velocity != NULL) {
        mapObject->mVelocity = *velocity;
    }
}

void SetShadowOffsetYAndScale(MissionRunMapObject *mapObject, s32 offsetY, s32 scaleXZ) {
    if (offsetY == 0) {
        mapObject->mShadowMode = 1;
    } else {
        mapObject->mShadowMode = 2;
    }
    mapObject->mShadowOffsetX = mapObject->mShadowOffsetTargetX = 0;
    mapObject->mShadowOffsetY = mapObject->mShadowOffsetTargetY = offsetY;
    mapObject->mShadowOffsetZ = mapObject->mShadowOffsetTargetZ = 0;
    mapObject->mShadowOffsetPerCall = 0;
    mapObject->mShadowScaleX = mapObject->mShadowScaleTargetX = scaleXZ;
    mapObject->mShadowScaleY = mapObject->mShadowScaleTargetY = 0xa000;
    mapObject->mShadowScaleZ = mapObject->mShadowScaleTargetZ = scaleXZ;
    mapObject->mShadowScalePerCall = 0;
}

void SetShadowOffsetYAndScaleTarget(MissionRunMapObject *mapObject, int offsetY, u32 offsetPerCall, u32 scaleXZ,
                                    u32 scalePerCall) {
    if (offsetY == 0) {
        mapObject->mShadowMode = 1;
    } else {
        mapObject->mShadowMode = 2;
    }
    mapObject->mShadowOffsetTargetX = 0;
    mapObject->mShadowOffsetTargetY = offsetY;
    mapObject->mShadowOffsetTargetZ = 0;
    mapObject->mShadowOffsetPerCall = offsetPerCall;
    mapObject->mShadowScaleTargetX = scaleXZ;
    mapObject->mShadowScaleTargetY = (0x0000a000u);
    mapObject->mShadowScaleTargetZ = scaleXZ;
    mapObject->mShadowScalePerCall = scalePerCall;
}

void SetCollisionOffsetAndExtent(MissionRunMapObject *mapObject, s32 offsetY, s32 extentXZ, s32 extentY) {
    if (extentY == 0) {
        mapObject->mCollisionShape = 0;
    } else {
        mapObject->mCollisionShape = 2;
    }
    mapObject->mOffset.x = mapObject->mOffsetTargetX = 0;
    mapObject->mOffset.y = mapObject->mOffsetTargetY = offsetY;
    mapObject->mOffset.z = mapObject->mOffsetTargetZ = 0;
    mapObject->mOffsetPerCall = 0;
    mapObject->mCollisionExtent.x = mapObject->mCollisionExtentTargetX = extentXZ;
    mapObject->mCollisionExtent.y = mapObject->mCollisionExtentTargetY = extentY;
    mapObject->mCollisionExtent.z = mapObject->mCollisionExtentTargetZ = extentXZ;
    mapObject->mCollisionExtentPerCall = 0;
    mapObject->mPosWithOffset.x = mapObject->mUnk_000.mPos.x + mapObject->mOffset.x;
    mapObject->mPosWithOffset.y = mapObject->mUnk_000.mPos.y + mapObject->mOffset.y;
    mapObject->mPosWithOffset.z = mapObject->mUnk_000.mPos.z + mapObject->mOffset.z;
}

void SetCollisionOffsetAndExtentTarget(MissionRunMapObject *mapObject, u32 offsetY, u32 offsetPerCall, u32 extentXZ,
                                       int extentY, u32 extentPerCall) {
    if (extentY == 0) {
        mapObject->mCollisionShape = 0;
    } else {
        mapObject->mCollisionShape = 2;
    }
    mapObject->mOffsetTargetX = 0;
    mapObject->mOffsetTargetY = offsetY;
    mapObject->mOffsetTargetZ = 0;
    mapObject->mOffsetPerCall = offsetPerCall;
    mapObject->mCollisionExtentTargetX = extentXZ;
    mapObject->mCollisionExtentTargetY = extentY;
    mapObject->mCollisionExtentTargetZ = extentXZ;
    mapObject->mCollisionExtentPerCall = extentPerCall;
}

void SetShadowOffsetAndScale(MissionRunMapObject *mapObject, int offsetX, u32 offsetY, u32 offsetZ, u32 scaleX,
                             u32 unusedScaleY, u32 scaleZ) {
    int *v1;
    int *v2;
    mapObject->mShadowMode = 0;
    if ((mapObject->mUnk_000.mFlags & (0x00000400u)) != 0) {
        offsetX = -offsetX;
    }
    v2 = &mapObject->mShadowOffsetTargetX;
    *v2 = offsetX;
    mapObject->mShadowOffsetX = *v2;
    v1 = &mapObject->mShadowOffsetTargetY;
    *v1 = offsetY;
    mapObject->mShadowOffsetY = *v1;
    v1 = &mapObject->mShadowOffsetTargetZ;
    *v1 = offsetZ;
    mapObject->mShadowOffsetZ = *v1;
    mapObject->mShadowOffsetPerCall = 0;
    v1 = &mapObject->mShadowScaleTargetX;
    *v1 = scaleX;
    mapObject->mShadowScaleX = *v1;
    v1 = &mapObject->mShadowScaleTargetY;
    *v1 = (0x0000a000u);
    mapObject->mShadowScaleY = *v1;
    v1 = &mapObject->mShadowScaleTargetZ;
    *v1 = scaleZ;
    mapObject->mShadowScaleZ = *v1;
    mapObject->mShadowScalePerCall = 0;
}

void SetShadowOffsetAndScaleTarget(MissionRunMapObject *mapObject, int offsetX, u32 offsetY, u32 offsetZ,
                                   u32 offsetPerCall, u32 scaleX, u32 unusedScaleY, u32 scaleZ, u32 scalePerCall) {
    mapObject->mShadowMode = 0;
    if ((mapObject->mUnk_000.mFlags & (0x00000400u)) != 0) {
        offsetX = -offsetX;
    }
    mapObject->mShadowOffsetTargetX = offsetX;
    mapObject->mShadowOffsetTargetY = offsetY;
    mapObject->mShadowOffsetTargetZ = offsetZ;
    mapObject->mShadowOffsetPerCall = offsetPerCall;
    mapObject->mShadowScaleTargetX = scaleX;
    mapObject->mShadowScaleTargetY = (0x0000a000u);
    mapObject->mShadowScaleTargetZ = scaleZ;
    mapObject->mShadowScalePerCall = scalePerCall;
}

void SetCollisionBoxOffsetAndExtent(MissionRunMapObject *mapObject, int offsetX, int offsetY, int offsetZ, u32 extentX,
                                    u32 extentY, u32 extentZ) {
    int *v1;
    int *v2;
    int *v3;
    int *v4;
    int *v5;
    mapObject->mCollisionShape = 1;
    if ((mapObject->mUnk_000.mFlags & (0x00000400u)) != 0) {
        offsetX = -offsetX;
    }
    v2 = &mapObject->mOffsetTargetX;
    *v2 = offsetX;
    v1 = &mapObject->mOffset.x;
    *v1 = *v2;
    v3 = &mapObject->mOffsetTargetY;
    *v3 = offsetY;
    v2 = &mapObject->mOffset.y;
    *v2 = *v3;
    v4 = &mapObject->mOffsetTargetZ;
    *v4 = offsetZ;
    v3 = &mapObject->mOffset.z;
    *v3 = *v4;
    mapObject->mOffsetPerCall = 0;
    v5 = &mapObject->mCollisionExtentTargetX;
    *v5 = extentX;
    mapObject->mCollisionExtent.x = *v5;
    v5 = &mapObject->mCollisionExtentTargetY;
    *v5 = extentY;
    mapObject->mCollisionExtent.y = *v5;
    v5 = &mapObject->mCollisionExtentTargetZ;
    *v5 = extentZ;
    mapObject->mCollisionExtent.z = *v5;
    mapObject->mCollisionExtentPerCall = 0;
    mapObject->mPosWithOffset.x = mapObject->mUnk_000.mPos.x + *v1;
    mapObject->mPosWithOffset.y = mapObject->mUnk_000.mPos.y + *v2;
    mapObject->mPosWithOffset.z = mapObject->mUnk_000.mPos.z + *v3;
}

void SetCollisionBoxOffsetAndExtentTarget(MissionRunMapObject *mapObject, int offsetX, u32 offsetY, u32 offsetZ,
                                          u32 offsetPerCall, u32 extentX, u32 extentY, u32 extentZ, u32 extentPerCall) {
    mapObject->mCollisionShape = 1;
    if ((mapObject->mUnk_000.mFlags & (0x00000400u)) != 0) {
        offsetX = -offsetX;
    }
    mapObject->mOffsetTargetX = offsetX;
    mapObject->mOffsetTargetY = offsetY;
    mapObject->mOffsetTargetZ = offsetZ;
    mapObject->mOffsetPerCall = offsetPerCall;
    mapObject->mCollisionExtentTargetX = extentX;
    mapObject->mCollisionExtentTargetY = extentY;
    mapObject->mCollisionExtentTargetZ = extentZ;
    mapObject->mCollisionExtentPerCall = extentPerCall;
}

void ResetMissionRunMapObjects(void) {
    u16 objectIndex;
    MissionRunMapObject *obj;
    MissionRunMapObject *tableObj;
    MapObjectList *table;

    if (!(gRaceSetup->mMode == MODE_MISSION_RUN ? IsKartEliminated((u16) gRaceSetup->mEntryIndex) : 0)) {
        for (objectIndex = gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : (u8) 0;
             objectIndex <= (gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunMapObjectLastIndex() : (u16) 0);
             objectIndex++) {
            obj = gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunMapObject(objectIndex) : 0;
            table = FindMapObjectKindUpdateList(0x1ff);
            StopMapObjectState(obj);
            obj->mGravityEnabled = FALSE;
            obj->mCourseCollisionMode = 3;
            obj->mSpeed = obj->mSpeedTarget = obj->mSpeedPerCall = 0;
            obj->mAngleState = MAP_OBJECT_ANGLE_NONE;
            obj->mAnglePerCall = obj->mAnglePerCallTarget = obj->mAnglePerCallIncrement = 0;
            obj->mMoveAngleMode = 0;
            obj->mMoveAnglePerCall = obj->mMoveAnglePerCallTarget = obj->mMoveAnglePerCallIncrement = 0;
            obj->mVelocity.x = obj->mVelocity.y = obj->mVelocity.z = 0;
            obj->mAlphaLimit = obj->mAlphaLimitTarget = 0x1f000;
            obj->mAlphaLimitPerCall = 0;
            if (objectIndex - (gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0) <
                table->mMapObjectCount) {
                tableObj =
                    table->mMapObjects[objectIndex -
                                       (gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0)];
                obj->mUnk_000.mPos = tableObj->mUnk_000.mCourseMapRow->mPosition;
                tableObj =
                    table->mMapObjects[objectIndex -
                                       (gRaceSetup->mMode == MODE_MISSION_RUN ? MissionRunGetCurrentKartCount() : 0)];
                obj->mAngle = DEG_TO_ANGLE(tableObj->mUnk_000.mCourseMapRow->mRotationDegrees.y);
            }
        }
    }
    ResetBalloons();
}

u32 IncrementHitCountAndCheckLimit(MissionRunMapObject *mapObject) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunCountForKind7();
    }
    mapObject->mUnk_0ac++;
    if (mapObject->mUnk_0ac >= mapObject->mPrm->mCounterLimit) {
        mapObject->mUnk_0ac = mapObject->mPrm->mCounterLimit;
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            EliminateKartsUntilWinnerDecided();
        }
        return 1;
    }
    return 0;
}

BOOL DecrementCounterToNegativeLimit(MissionRunMapObject *mapObject) {
    s32 limit;

    mapObject->mUnk_0ac--;
    limit = -mapObject->mPrm->mCounterLimit;
    if (mapObject->mUnk_0ac <= limit) {
        mapObject->mUnk_0ac = limit;
        return TRUE;
    }
    return FALSE;
}

u16 GetAbsoluteCounter(MissionRunMapObject *mapObject) {
    s32 counter;
    counter = mapObject->mUnk_0ac;
    if (counter < 0) {
        counter = -counter;
    }
    return counter & 0xffff;
}

void SetRepeatsRemaining(MissionRunMapObject *mapObject, s32 repeatsRemaining) {
    mapObject->mRepeatsRemaining = repeatsRemaining;
}

u16 GetRepeatsRemaining(MissionRunMapObject *mapObject) {
    return mapObject->mRepeatsRemaining;
}

void SetKartCollisionCallback(MissionRunMapObject *mapObject, UnkFunc *kartCollisionCallback) {
    mapObject->mKartCollisionCallback = kartCollisionCallback;
}

void SetItemCollisionCallback(MissionRunMapObject *mapObject, UnkFunc *itemCollisionCallback) {
    mapObject->mItemCollisionCallback = itemCollisionCallback;
}

BOOL IsPointInRange(MissionRunMapObject *mapObject, Vec3 *point, s32 radius, s32 halfAngle) {
    if ((radius != 0 || halfAngle != 0) && (radius == 0 || IsWithinXzDistanceOfPoint(mapObject, point, radius) != 0) &&
        (halfAngle == 0 || IsDirectionToPointWithinAngle(mapObject, mapObject->mMoveAngle, point, halfAngle) != 0)) {
        return TRUE;
    }
    return FALSE;
}

ItemBomb *FindItemBombInRange(MissionRunMapObject *mapObject, u32 radius, u32 halfAngle) {
    int bombCount;
    ItemBomb *bomb;
    int inRange;
    int index;
    bombCount = GetItemBombActiveCount();
    index = 0;
    if (0 < bombCount) {
        do {
            bomb = GetRestingItemBomb(index);
            if ((bomb != NULL) &&
                (inRange = IsPointInRange(mapObject, &bomb->mBouncingItemObject.mItemObject.mPos, radius, halfAngle),
                 inRange != 0)) {
                return bomb;
            }
            index = index + 1;
        } while (index < bombCount);
    }
    return NULL;
}

Kart *GetEntryKartInRange(MissionRunMapObject *mapObject, s32 radius, s32 halfAngle) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if (kart != NULL && IsPointInRange(mapObject, &kart->mPos, radius, halfAngle) != FALSE &&
        (kart->mDriveFlags & KART_DRIVE_SINKING) == 0) {
        return kart;
    }
    return NULL;
}

Kart *GetEntryKartInAngleRange(MissionRunMapObject *mapObject, s32 angleOffset, s32 radius, s32 halfAngle) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if (kart != NULL && (kart->mDriveFlags & KART_DRIVE_SINKING) == 0 && (radius != 0 || halfAngle != 0)) {
        if (radius == 0 || IsWithinXzDistanceOfPoint(mapObject, &kart->mPos, radius) != 0) {
            if (halfAngle == 0 || IsDirectionToPointWithinAngle(mapObject, mapObject->mAngle + angleOffset, &kart->mPos,
                                                                halfAngle) != 0) {
                return kart;
            }
        }
    }
    return NULL;
}

Kart *GetEntryKartFacingObject(MissionRunMapObject *mapObject, s32 radius, s32 halfAngle) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if (kart != NULL && (kart->mDriveFlags & KART_DRIVE_SINKING) == 0 && (radius != 0 || halfAngle != 0)) {
        if (radius == 0 || IsWithinXzDistanceOfPoint(mapObject, &kart->mPos, radius) != 0) {
            if (halfAngle == 0 ||
                IsDirectionToPointWithinAngle(mapObject, kart->mHeadingAngle + 0x8000, &kart->mPos, halfAngle) != 0) {
                return kart;
            }
        }
    }
    return NULL;
}

CourseMapGroupEntry *GetCurrentGroupEntry(MissionRunMapObject *mapObject) {
    if (mapObject->mEntryGroupIndex < gCourseMap->mEntryGroupCount) {
        return GetCourseMapGroupEntry(mapObject->mEntryGroupIndex, mapObject->mEntryIndex);
    }
    return NULL;
}

s32 GetCurrentGroupEntryValue(MissionRunMapObject *mapObject) {
    if (mapObject->mEntryGroupIndex < gCourseMap->mEntryGroupCount) {
        return GetCourseMapGroupEntry(mapObject->mEntryGroupIndex, mapObject->mEntryIndex)->mValue;
    }
    return 0;
}

s32 GetCurrentGroupEntryPercent(MissionRunMapObject *mapObject) {
    if (mapObject->mEntryGroupIndex < gCourseMap->mEntryGroupCount) {
        return GetCourseMapGroupEntry(mapObject->mEntryGroupIndex, mapObject->mEntryIndex)->mExtraValue;
    }
    return 0;
}

CourseMapGroupEntry *GetNextGroupEntry(MissionRunMapObject *mapObject) {
    CourseMap *courseMap = gCourseMap;
    s32 nextEntryIndex;

    if (mapObject->mEntryGroupIndex < courseMap->mEntryGroupCount) {
        nextEntryIndex = mapObject->mEntryIndex + 1;
        if (nextEntryIndex >= GetCourseMapEntryGroup(mapObject->mEntryGroupIndex)->mEntryCount) {
            nextEntryIndex = 0;
        }
        return GetCourseMapGroupEntry(mapObject->mEntryGroupIndex, nextEntryIndex);
    }
    return NULL;
}

void DecrementEntryIndexSkipZero(MissionRunMapObject *mapObject) {
    CourseMap *courseMap;
    CourseMapEntryGroup *entryGroup;
    s32 groupIndex;
    s32 entryIndex;

    courseMap = gCourseMap;
    groupIndex = mapObject->mEntryGroupIndex;
    if (groupIndex < courseMap->mEntryGroupCount) {
        entryGroup = &courseMap->mEntryGroups[(u16) groupIndex];
        entryIndex = mapObject->mEntryIndex - 1;
        if (entryIndex <= 0) {
            entryIndex = entryGroup->mEntryCount - 1;
        }
        mapObject->mEntryIndex = entryIndex;
    }
}

void IncrementEntryIndex(MissionRunMapObject *mapObject) {
    int nextEntryIndex;

    if (mapObject->mEntryGroupIndex < gCourseMap->mEntryGroupCount) {
        nextEntryIndex = mapObject->mEntryIndex + 1;
        if (nextEntryIndex >= GetCourseMapEntryGroup(mapObject->mEntryGroupIndex)->mEntryCount) {
            nextEntryIndex = 0;
        }
        mapObject->mEntryIndex = nextEntryIndex;
    }
}

void IncrementEntryGroupIndex(MissionRunMapObject *mapObject, s32 groupSpan) {
    s32 firstGroupIndex;
    s32 nextGroupIndex;

    firstGroupIndex = mapObject->mUnk_000.mCourseMapRow->mGroupIndex;
    nextGroupIndex = mapObject->mEntryGroupIndex + 1;
    if (nextGroupIndex >= firstGroupIndex + groupSpan) {
        nextGroupIndex = firstGroupIndex;
    }
    mapObject->mEntryGroupIndex = (u16) nextGroupIndex;
    mapObject->mEntryIndex = 0;
}

void *StartItemBombWithParkedItemBox(u16 forcedRow) {
    ItemBox *parkedMapObject;

    parkedMapObject = FindParkedMapObject(0xc9);
    if (parkedMapObject != NULL) {
        SetItemBoxFramesSinceHitMax(parkedMapObject);
        parkedMapObject->mForcedRowHumanGhostPeer = forcedRow;
        parkedMapObject->mForcedRowCpu = forcedRow;
        parkedMapObject->mShortSpin = 1;
        return StartItemBombWithMapObject(parkedMapObject, 0xa000);
    }
    return NULL;
}

void *StartItemBombWithParkedKuribo(void) {
    void *parkedMapObject;

    parkedMapObject = FindParkedMapObject(MAP_OBJECT_KIND_KURIBO);
    if (parkedMapObject != NULL) {
        ResetKuriboForItemBomb(parkedMapObject);
        return StartItemBombWithMapObject(parkedMapObject, 0);
    }
    return NULL;
}

void StoreNodePositionAndPlaceItemBomb(NNSG3dRS *renderState) {
    MtxFx43 currentMatrix;
    MtxFx43 inverseViewMatrix;
    Vec3 bombPosition;
    MissionRunMapObject *mapObject;
    Camera *currentCamera;

    mapObject = renderState->mRenderObj->mPtrUser;
    if (renderState->mC[1] == mapObject->mNodeMatchValue) {
        currentCamera = GetCurrentCamera();
        NNS_G3dGetCurrentMtx(&currentMatrix, NULL);
        MTX_Inverse43(&currentCamera->mViewMatrix, &inverseViewMatrix);
        MTX_Concat43(&currentMatrix, &inverseViewMatrix, &currentMatrix);
        mapObject->mNodePosition.x = currentMatrix.mRows[3].x << 4;
        mapObject->mNodePosition.y = currentMatrix.mRows[3].y << 4;
        mapObject->mNodePosition.z = currentMatrix.mRows[3].z << 4;
        if (mapObject->mItemBomb != NULL) {
            bombPosition = mapObject->mNodePosition;
            VEC_MultAdd(mapObject->mBombOffset.x, &currentMatrix.mRows[0], &bombPosition, &bombPosition);
            VEC_MultAdd(mapObject->mBombOffset.y, &currentMatrix.mRows[1], &bombPosition, &bombPosition);
            VEC_MultAdd(mapObject->mBombOffset.z, &currentMatrix.mRows[2], &bombPosition, &bombPosition);
            PlaceItemBomb(mapObject->mItemBomb, &currentMatrix.mRows[0], &bombPosition);
        }
    }
}

void SetNodePositionSource(MissionRunMapObject *mapObject, u32 matchValue) {
    MapObjectModel **nsbmdPointer;
    mapObject->mNodeMatchValue = matchValue;
    mapObject->mShadowMode = 3;
    nsbmdPointer = &mapObject->mNsbmd;
    (*nsbmdPointer)->mAnimatedModel->mRenderObj.mPtrUser = mapObject;
    NNS_G3dRenderObjSetCallBack(&(*nsbmdPointer)->mAnimatedModel->mRenderObj, StoreNodePositionAndPlaceItemBomb, 0, 6,
                                (u8) 3);
}

void SetNodePositionSourceAndBombOffset(MissionRunMapObject *mapObject, s32 matchValue, const Vec3 *offset) {
    mapObject->mNodeMatchValue = matchValue;
    mapObject->mBombOffset = *offset;
    mapObject->mNsbmd->mAnimatedModel->mRenderObj.mPtrUser = mapObject;
    NNS_G3dRenderObjSetCallBack(&mapObject->mNsbmd->mAnimatedModel->mRenderObj, StoreNodePositionAndPlaceItemBomb, 0, 6,
                                3);
}

void ReleaseAndSetItemBomb(MissionRunMapObject *mapObject, void *itemBomb) {
    if (mapObject->mItemBomb != NULL) {
        ReleaseItemBomb(&mapObject->mItemBomb);
    }
    mapObject->mItemBomb = itemBomb;
}

u32 IsItemBombStored(MissionRunMapObject *mapObject) {
    if (mapObject->mItemBomb != NULL) {
        return 1;
    }
    return 0;
}

void ThrowOrReleaseStoredItemBomb(MissionRunMapObject *mapObject, Vec3 *velocity, s32 timer) {
    Vec3 zeroVelocity;
    s32 *zeroWords;

    if (mapObject->mItemBomb != NULL) {
        if (((ItemBomb *) mapObject->mItemBomb)->mBouncingItemObject.mItemObject.mPos.y < 0x64000) {
            ReleaseItemBomb(&mapObject->mItemBomb);
        } else if (velocity != NULL) {
            ThrowItemBombFromSlot(&mapObject->mItemBomb, velocity, timer);
        } else {
            zeroWords = (s32 *) &zeroVelocity;
            zeroWords[0] = 0;
            zeroWords[1] = 0;
            zeroWords[2] = 0;
            ThrowItemBombFromSlot(&mapObject->mItemBomb, &zeroVelocity, timer);
        }
    }
}

void ThrowItemBombFromPosition(void *bomb, Vec3 *position, Vec3 *velocity, s32 timer) {
    Vec3 upNormal;
    Vec3 zeroVelocity;
    Vec3 *normalPointer;
    s32 *zeroWords;

    if (bomb != NULL && position != NULL) {
        upNormal = gItemBombUpNormal;
        normalPointer = &upNormal;
        PlaceItemBomb(bomb, normalPointer, position);
        if (velocity != NULL) {
            ThrowItemBombFromSlot(&bomb, velocity, timer);
        } else {
            zeroWords = (s32 *) &zeroVelocity;
            zeroWords[0] = 0;
            zeroWords[1] = 0;
            zeroWords[2] = 0;
            ThrowItemBombFromSlot(&bomb, &zeroVelocity, timer);
        }
    }
}

void ThrowItemKinokoFromPosition(void *kinoko, Vec3 *position, Vec3 *velocity, s32 timer) {
    Vec3 upNormal;
    Vec3 zeroVelocity;
    Vec3 *normalPointer;
    s32 *zeroWords;

    if (kinoko != NULL && position != NULL) {
        upNormal = gItemKinokoUpNormal;
        normalPointer = &upNormal;
        ShowItemKinokoAt(kinoko, normalPointer, position);
        if (velocity != NULL) {
            StartBouncingItemKinoko(&kinoko, velocity, timer);
        } else {
            zeroWords = (s32 *) &zeroVelocity;
            zeroWords[0] = 0;
            zeroWords[1] = 0;
            zeroWords[2] = 0;
            StartBouncingItemKinoko(&kinoko, &zeroVelocity, timer);
        }
    }
}

void ReleaseEffects(MissionRunMapObject *mapObject) {
    s32 effectIndex;

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        if (mapObject->mEffects[effectIndex].mEffect != NULL) {
            StopEffectAndClearPointer(&mapObject->mEffects[effectIndex].mEffect);
        }
    }
    mapObject->mUnk_0b8 = 0;
}

// Writes a point for one entry of the object's table; the entry's type (1-5) picks how, others write nothing.
void ComputeEffectPosition(MissionRunMapObject *mapObject, int effectIndex, Vec3 *position) {
    Camera *camera;
    s32 scaledX;
    s32 scaledY;
    s32 scaledZ;
    s32 offsetComponent;

    switch (mapObject->mEffects[effectIndex].mKind) {
        case 1:
            position->x = mapObject->mUnk_000.mPos.x +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.z,
                                                      FX_SinIdx((u16) mapObject->mAngle))) +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.x,
                                                      FX_CosIdx((u16) mapObject->mAngle)));
            position->y = mapObject->mUnk_000.mPos.y + mapObject->mEffects[effectIndex].mOffset.y;
            position->z = mapObject->mUnk_000.mPos.z +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.z,
                                                      FX_CosIdx((u16) mapObject->mAngle))) -
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.x,
                                                      FX_SinIdx((u16) mapObject->mAngle)));
            break;
        case 3:
            // As case 1 with mUnk_024 of the object from GetCurrentCamera added, then halved.
            camera = GetCurrentCamera();
            position->x = mapObject->mUnk_000.mPos.x + camera->mPos.x +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.z,
                                                      FX_SinIdx((u16) mapObject->mAngle))) +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.x,
                                                      FX_CosIdx((u16) mapObject->mAngle)));
            position->y = mapObject->mUnk_000.mPos.y + camera->mPos.y + mapObject->mEffects[effectIndex].mOffset.y;
            position->z = mapObject->mUnk_000.mPos.z + camera->mPos.z +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.z,
                                                      FX_CosIdx((u16) mapObject->mAngle))) -
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.x,
                                                      FX_SinIdx((u16) mapObject->mAngle)));
            position->x >>= 1;
            position->y >>= 1;
            position->z >>= 1;
            break;
        case 2:
            // The entry's mUnk_08 is first multiplied per component by param_1.mUnk_01c, mBounceScale and
// mKartPushPosStep.
            offsetComponent = mapObject->mEffects[effectIndex].mOffset.y;
            scaledY = MUL_FIXED12_NO_ROUND(offsetComponent, mapObject->mUnk_000.mScale.y);
            offsetComponent = mapObject->mEffects[effectIndex].mOffset.x;
            scaledX = MUL_FIXED12_NO_ROUND(offsetComponent, mapObject->mUnk_000.mScale.x);
            offsetComponent = mapObject->mEffects[effectIndex].mOffset.z;
            scaledZ = MUL_FIXED12_NO_ROUND(offsetComponent, mapObject->mUnk_000.mScale.z);
            position->x = mapObject->mUnk_000.mPos.x +
                          (s32) (MUL_FIXED12_NO_ROUND(scaledZ, FX_SinIdx((u16) mapObject->mAngle))) +
                          (s32) (MUL_FIXED12_NO_ROUND(scaledX, FX_CosIdx((u16) mapObject->mAngle)));
            position->y = mapObject->mUnk_000.mPos.y + scaledY;
            position->z = mapObject->mUnk_000.mPos.z +
                          (s32) (MUL_FIXED12_NO_ROUND(scaledZ, FX_CosIdx((u16) mapObject->mAngle))) -
                          (s32) (MUL_FIXED12_NO_ROUND(scaledX, FX_SinIdx((u16) mapObject->mAngle)));
            break;
        case 4:
            position->x = mapObject->mUnk_000.mPos.x +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.z,
                                                      FX_SinIdx((u16) mapObject->mAngle))) +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.x,
                                                      FX_CosIdx((u16) mapObject->mAngle)));
            position->y = mapObject->mUnk_000.mCourseMapRow->mPosition.y + mapObject->mEffects[effectIndex].mOffset.y;
            position->z = mapObject->mUnk_000.mPos.z +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.z,
                                                      FX_CosIdx((u16) mapObject->mAngle))) -
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.x,
                                                      FX_SinIdx((u16) mapObject->mAngle)));
            break;
        case 5:
            position->x = mapObject->mUnk_000.mPos.x +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.z,
                                                      FX_SinIdx((u16) mapObject->mAngle))) +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.x,
                                                      FX_CosIdx((u16) mapObject->mAngle)));
            position->y = mapObject->mEffects[effectIndex].mOffset.y - GetHeightAboveWaterOrEfct(0);
            position->z = mapObject->mUnk_000.mPos.z +
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.z,
                                                      FX_CosIdx((u16) mapObject->mAngle))) -
                          (s32) (MUL_FIXED12_NO_ROUND(mapObject->mEffects[effectIndex].mOffset.x,
                                                      FX_SinIdx((u16) mapObject->mAngle)));
            break;
    }
}

void StartEffectInSlot(MissionRunMapObject *mapObject, s32 effectIndex, s32 offsetX, s32 offsetY, s32 offsetZ,
                       u32 effectId, s32 timer) {
    Vec3 position;

    mapObject->mEffects[effectIndex].mTimer = timer;
    if ((mapObject->mUnk_000.mFlags & 0x400) != 0) {
        offsetX = -offsetX;
    }
    mapObject->mEffects[effectIndex].mOffset.x = offsetX << 4;
    mapObject->mEffects[effectIndex].mOffset.y = offsetY << 4;
    mapObject->mEffects[effectIndex].mOffset.z = offsetZ << 4;
    ComputeEffectPosition(mapObject, effectIndex, &position);
    if (effectId != 0) {
        if (mapObject->mEffects[effectIndex].mEffect != NULL) {
            StopEffectAndClearPointer(&mapObject->mEffects[effectIndex].mEffect);
        }
        mapObject->mEffects[effectIndex].mEffect = StartEffect(effectId, &position);
    }
}

void StartEffectAtOffset(MissionRunMapObject *mapObject, u32 offsetX, u32 offsetY, u32 offsetZ, u32 effectId,
                         u32 timer) {
    int effectIndex;

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        if (mapObject->mEffects[effectIndex].mEffect == NULL) {
            mapObject->mEffects[effectIndex].mKind = 1;
            StartEffectInSlot(mapObject, effectIndex, offsetX, offsetY, offsetZ, effectId, timer);
            return;
        }
    }
}

void StartEffectAtScaledOffset(MissionRunMapObject *mapObject, u32 offsetX, u32 offsetY, u32 offsetZ, u32 effectId,
                               u32 timer) {
    int effectIndex;

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        if (mapObject->mEffects[effectIndex].mEffect == NULL) {
            mapObject->mEffects[effectIndex].mKind = 2;
            StartEffectInSlot(mapObject, effectIndex, offsetX, offsetY, offsetZ, effectId, timer);
            return;
        }
    }
}

void StartEffectAtRowHeight(MissionRunMapObject *mapObject, u32 offsetX, u32 offsetY, u32 offsetZ, u32 effectId,
                            u32 timer) {
    int effectIndex;

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        if (mapObject->mEffects[effectIndex].mEffect == NULL) {
            mapObject->mEffects[effectIndex].mKind = 4;
            StartEffectInSlot(mapObject, effectIndex, offsetX, offsetY, offsetZ, effectId, timer);
            return;
        }
    }
}

void StartEffectAtWaterHeight(MissionRunMapObject *mapObject, u32 offsetX, u32 offsetY, u32 offsetZ, u32 effectId,
                              u32 timer) {
    int effectIndex;

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        if (mapObject->mEffects[effectIndex].mEffect == NULL) {
            mapObject->mEffects[effectIndex].mKind = 5;
            StartEffectInSlot(mapObject, effectIndex, offsetX, offsetY, offsetZ, effectId, timer);
            return;
        }
    }
}

void StartModelEffectAtWaterHeight(MissionRunMapObject *mapObject, u32 modelEffectKind, int timer) {
    int effectIndex;

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        if (mapObject->mEffects[effectIndex].mEffect == NULL) {
            mapObject->mEffects[effectIndex].mOffset.x = mapObject->mUnk_000.mPos.x;
            mapObject->mEffects[effectIndex].mOffset.y = -GetHeightAboveWaterOrEfct(0);
            mapObject->mEffects[effectIndex].mOffset.z = mapObject->mUnk_000.mPos.z;
            if (mapObject->mEffects[effectIndex].mEffect != NULL) {
                StopEffectAndClearPointer(&mapObject->mEffects[effectIndex].mEffect);
            }
            StartModelEffect(modelEffectKind, &mapObject->mEffects[effectIndex].mOffset, 1);
            mapObject->mEffects[effectIndex].mKind = 0;
            mapObject->mEffects[effectIndex].mTimer = timer;
            return;
        }
    }
}

void SetEffectDirection(ParticleEmitter *emitter, const Vec3s16 *direction) {
    emitter->mDirection = *direction;
}

void StartEffectWithRotatedDirection(MissionRunMapObject *mapObject, int offsetX, int offsetY, int offsetZ,
                                     int emitterParamX, int emitterParamY, int emitterParamZ, int effectId, u32 timer) {
    int effectIndex;
    Vec3 position;
    Vec3s16 emitterParams;

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        if (mapObject->mEffects[effectIndex].mEffect == NULL) {
            mapObject->mEffects[effectIndex].mKind = 1;
            mapObject->mEffects[effectIndex].mTimer = timer;
            mapObject->mEffects[effectIndex].mOffset.x = offsetX << 4;
            mapObject->mEffects[effectIndex].mOffset.y = offsetY << 4;
            mapObject->mEffects[effectIndex].mOffset.z = offsetZ << 4;
            ComputeEffectPosition(mapObject, effectIndex, &position);
            if (effectId != 0) {
                if (mapObject->mEffects[effectIndex].mEffect != NULL) {
                    StopEffectAndClearPointer(&mapObject->mEffects[effectIndex].mEffect);
                }
                emitterParams.x = (MUL_FIXED12_NO_ROUND(emitterParamZ, FX_SinIdx((u16) mapObject->mAngle))) +
                                  (MUL_FIXED12_NO_ROUND(emitterParamX, FX_CosIdx((u16) mapObject->mAngle)));
                emitterParams.y = emitterParamY;
                emitterParams.z = (MUL_FIXED12_NO_ROUND(emitterParamZ, FX_CosIdx((u16) mapObject->mAngle))) -
                                  (MUL_FIXED12_NO_ROUND(emitterParamX, FX_SinIdx((u16) mapObject->mAngle)));
                StartEffectWithCallback(effectId, &position, &emitterParams, SetEffectDirection);
            }
        }
    }
}

void StartMapObjectState(MissionRunMapObject *mapObject, int stateNumber, s32 (*nextFunc)(MissionRunMapObject *)) {
    mapObject->mStateFunction = NULL;
    mapObject->mNextStateFunction = nextFunc;
    mapObject->mStateNumber = stateNumber;
    mapObject->mStateFrames = 0;
    mapObject->mRepeatsRemaining = mapObject->mRepeatsRemaining > 0 ? mapObject->mRepeatsRemaining - 1 : 0;
    mapObject->mBounceEnabled = FALSE;
    mapObject->mGravityEnabled = TRUE;
    if (mapObject->mUnk_2c4 == FALSE) {
        mapObject->mAnimationFrameCallbackFrameIndex = 0;
        mapObject->mAnimationEndCallback = NULL;
        mapObject->mAnimationFrameCallback = NULL;
        mapObject->mUnk_1e0 = 0;
        mapObject->mUnk_1e4 = NULL;
        mapObject->mUnk_1e8 = 0;
        mapObject->mUnk_1ec = NULL;
        mapObject->mStateFrameCount = 0;
        mapObject->mStateFrameCountCallback = NULL;
        mapObject->mPointInRangeCallback = NULL;
        mapObject->mUnk_224 = NULL;
        mapObject->mStoppedCallback = NULL;
        mapObject->mCourseCollisionCallback = NULL;
        ReleaseEffects(mapObject);
    }
}

void DisableMissionRunMapObjectGravity(MissionRunMapObject *mapObject) {
    mapObject->mGravityEnabled = FALSE;
}

u32 IsStateNumberBelow(MissionRunMapObject *mapObject, int stateNumberLimit) {
    if (mapObject->mStateNumber < stateNumberLimit) {
        return 1;
    }
    return 0;
}

BOOL IsNotRisingWithBelowZeroBit(MissionRunMapObject *mapObject) {
    if ((mapObject->mCollisionBits & 0x800) != 0 && mapObject->mVelocity.y <= 0) {
        return TRUE;
    }
    return FALSE;
}

void InitMissionRunMapObject(void *mapObjectList, MissionRunMapObject *mapObject, const char *nsbmdName,
                             const char *nsbcaName, const char *prmName) {
    if (mapObjectList != NULL && nsbmdName != NULL) {
        mapObject->mNsbmd = LoadMapObjectModelAnimated(mapObjectList, nsbmdName);
        if (nsbcaName != NULL) {
            LoadMapObjectModelNsbcaAnimation(mapObject->mNsbmd, nsbcaName);
        }
    }
    if (prmName != NULL) {
        mapObject->mPrm = LoadMissionRunFile(prmName);
    }
    mapObject->mAngle = DEG_TO_ANGLE(mapObject->mUnk_000.mCourseMapRow->mRotationDegrees.y);
    mapObject->mAlphaLimit = 0x1f000;
    if (mapObject->mPrm != NULL) {
        SetMapObjectExtentX(&mapObject->mUnk_000, mapObject->mPrm->mCollisionExtentXZ << 2);
        mapObject->mUnk_000.mScale.x = mapObject->mPrm->mScale;
        mapObject->mUnk_000.mScale.y = mapObject->mPrm->mScale;
        mapObject->mUnk_000.mScale.z = mapObject->mPrm->mScale;
    }
    mapObject->mPosWithOffset = mapObject->mUnk_000.mPos;
    mapObject->mBounceEnabled = FALSE;
    mapObject->mGravityEnabled = TRUE;
    mapObject->mEntryGroupIndex = mapObject->mUnk_000.mCourseMapRow->mGroupIndex;
}

void LoadMissionRunMapObjectShadow(void *mapObjectList, MissionRunMapObject *mapObject, const char *shadowNsbmdName) {
    if (mapObjectList != NULL && shadowNsbmdName != NULL) {
        mapObject->mShadowNsbmd = LoadMapObjectModelShadow(mapObjectList, shadowNsbmdName);
        SetMapObjectModelPolygonId(mapObject->mShadowNsbmd, 0x3f);
        gShadowScaleToggle = 0;
    }
}

void ToggleShadowScale(void) {
    if (gShadowScaleToggle == 0) {
        gShadowScaleToggle++;
    } else {
        gShadowScaleToggle = 0;
    }
}

int StepIntTowardTarget(int target, int step, int current) {
    int next;
    if (current < target) {
        next = current + step;
        if (current + step >= target) {
            next = target;
        }
        return next;
    }
    if (current > target) {
        next = current - step;
        if (current - step <= target) {
            next = target;
        }
        return next;
    }
    return current;
}

u16 StepAngleTowardDirection(Vec3 *target, Vec3 *origin, s32 maxStep, s32 angle) {
    s32 angleDifference = (u16) (FX_Atan2Idx(target->x - origin->x, target->z - origin->z) - angle);
    s32 turn;

    if (maxStep < 0) {
        maxStep = -maxStep;
    }
    if (angleDifference > 0x8000) {
        angleDifference -= 0x10000;
    }
    turn = -maxStep;
    if (angleDifference >= turn) {
        if (angleDifference <= maxStep) {
            maxStep = angleDifference;
        }
        turn = maxStep;
    }
    return angle + turn;
}

u16 StepAngleSidewaysToPoint(Vec3 *targetPoint, Vec3 *origin, s32 signedMaxStep, s32 angleOffset, s32 angle) {
    s32 angleDifference = (u16) (FX_Atan2Idx(targetPoint->x - origin->x, targetPoint->z - origin->z) - angle);
    s32 maxTurn;
    s32 turn;
    s32 targetDifference;

    if (signedMaxStep < 0) {
        maxTurn = -signedMaxStep;
    } else {
        maxTurn = signedMaxStep;
    }
    if (angleDifference > 0x8000) {
        angleDifference -= 0x10000;
    }
    if (signedMaxStep < 0) {
        angleDifference += angleOffset;
        targetDifference = angleDifference - 0x4000;
    } else {
        angleDifference -= angleOffset;
        targetDifference = angleDifference + 0x4000;
    }
    turn = -maxTurn;
    if (targetDifference >= turn) {
        if (targetDifference <= maxTurn) {
            maxTurn = targetDifference;
        }
        turn = maxTurn;
    }
    return angle + turn;
}

void AdvanceMissionRunMapObject(u32 unused, MissionRunMapObject *mapObject) {
    Vec3 probePosition;
    Vec3 pushOut;
    Vec3 v50;
    Vec3 v5c;
    Vec3 pushDirection;
    Vec3 effectPosition;
    s32 velocityScale;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 currentFrame;
    s32 previousFrame;
    s32 effectIndex;
    s32 pairWordIndex;
    s64 speed;

    if (mapObject->mStateFunction == NULL && mapObject->mNextStateFunction != NULL) {
        mapObject->mStateFunction = mapObject->mNextStateFunction;
        mapObject->mNextStateFunction = NULL;
    }
    if (mapObject->mStateFunction != NULL && mapObject->mStateFunction(mapObject)) {
        mapObject->mStateFunction = NULL;
        mapObject->mUnk_154 = 0;
        mapObject->mStateFrames = 0;
        mapObject->mStateNumber = 0;
    }

    switch (mapObject->mAngleState) {
        case MAP_OBJECT_ANGLE_FOLLOW_MOVE_ANGLE:
            mapObject->mAngle = mapObject->mMoveAngle;
            break;
        case MAP_OBJECT_ANGLE_TURN_TO_POINT:
            if (mapObject->mAnglePerCallIncrement > 0) {
                mapObject->mAnglePerCall = StepIntTowardTarget(
                    mapObject->mAnglePerCallTarget, mapObject->mAnglePerCallIncrement, mapObject->mAnglePerCall);
            }
            if (mapObject->mAnglePerCall > 0) {
                mapObject->mAngle = StepAngleTowardDirection(&mapObject->mAnglePoint, &mapObject->mUnk_000.mPos,
                                                             mapObject->mAnglePerCall, mapObject->mAngle);
            }
            break;
        case MAP_OBJECT_ANGLE_TURN_FROM_POINT:
            if (mapObject->mAnglePerCallIncrement > 0) {
                mapObject->mAnglePerCall = StepIntTowardTarget(
                    mapObject->mAnglePerCallTarget, mapObject->mAnglePerCallIncrement, mapObject->mAnglePerCall);
            }
            if (mapObject->mAnglePerCall > 0) {
                mapObject->mAngle = StepAngleTowardDirection(&mapObject->mUnk_000.mPos, &mapObject->mAnglePoint,
                                                             mapObject->mAnglePerCall, mapObject->mAngle);
            }
            break;
        case MAP_OBJECT_ANGLE_TURN_SIDEWAYS:
            if (mapObject->mAnglePerCallIncrement > 0) {
                mapObject->mAnglePerCall = StepIntTowardTarget(
                    mapObject->mAnglePerCallTarget, mapObject->mAnglePerCallIncrement, mapObject->mAnglePerCall);
            }
            if (mapObject->mAnglePerCall > 0) {
                mapObject->mAngle =
                    StepAngleSidewaysToPoint(&mapObject->mAnglePoint, &mapObject->mUnk_000.mPos,
                                             mapObject->mAnglePerCall, mapObject->mUnk_1a0, mapObject->mAngle);
            }
            break;
        case MAP_OBJECT_ANGLE_SPIN:
            if (mapObject->mAnglePerCallIncrement > 0) {
                mapObject->mAnglePerCall = StepIntTowardTarget(
                    mapObject->mAnglePerCallTarget, mapObject->mAnglePerCallIncrement, mapObject->mAnglePerCall);
            }
            if (mapObject->mAnglePerCall > 0) {
                mapObject->mAngle += mapObject->mAnglePerCall;
            }
            break;
        case MAP_OBJECT_ANGLE_SPIN_CHOOSE_DIRECTION:
        case MAP_OBJECT_ANGLE_SPIN_NEGATIVE:
        case MAP_OBJECT_ANGLE_SPIN_POSITIVE:
            if (mapObject->mAnglePerCallIncrement > 0) {
                mapObject->mAnglePerCall = StepIntTowardTarget(
                    mapObject->mAnglePerCallTarget, mapObject->mAnglePerCallIncrement, mapObject->mAnglePerCall);
            }
            if (mapObject->mAngleState == MAP_OBJECT_ANGLE_SPIN_CHOOSE_DIRECTION) {
                if (StepAngleTowardDirection(&mapObject->mAnglePoint, &mapObject->mUnk_000.mPos,
                                             mapObject->mAnglePerCall, mapObject->mAngle) -
                        mapObject->mAngle >=
                    0) {
                    mapObject->mAngleState = MAP_OBJECT_ANGLE_SPIN_POSITIVE;
                } else {
                    mapObject->mAngleState = MAP_OBJECT_ANGLE_SPIN_NEGATIVE;
                }
            }
            if (mapObject->mAngleState == MAP_OBJECT_ANGLE_SPIN_POSITIVE) {
                mapObject->mAngle += mapObject->mAnglePerCall;
            } else if (mapObject->mAngleState == MAP_OBJECT_ANGLE_SPIN_NEGATIVE) {
                mapObject->mAngle -= mapObject->mAnglePerCall;
            }
            break;
    }

    switch (mapObject->mMoveAngleMode) {
        case 1:
            mapObject->mMoveAngle = mapObject->mAngle;
            break;
        case 2:
            if (mapObject->mMoveAnglePerCallIncrement > 0) {
                mapObject->mMoveAnglePerCall =
                    StepIntTowardTarget(mapObject->mMoveAnglePerCallTarget, mapObject->mMoveAnglePerCallIncrement,
                                        mapObject->mMoveAnglePerCall);
            }
            if (mapObject->mMoveAnglePerCall > 0) {
                mapObject->mMoveAngle = StepAngleTowardDirection(&mapObject->mMoveAnglePoint, &mapObject->mUnk_000.mPos,
                                                                 mapObject->mMoveAnglePerCall, mapObject->mMoveAngle);
            }
            break;
        case 3:
            if (mapObject->mMoveAnglePerCallIncrement > 0) {
                mapObject->mMoveAnglePerCall =
                    StepIntTowardTarget(mapObject->mMoveAnglePerCallTarget, mapObject->mMoveAnglePerCallIncrement,
                                        mapObject->mMoveAnglePerCall);
            }
            if (mapObject->mMoveAnglePerCall > 0) {
                mapObject->mMoveAngle = StepAngleTowardDirection(&mapObject->mUnk_000.mPos, &mapObject->mMoveAnglePoint,
                                                                 mapObject->mMoveAnglePerCall, mapObject->mMoveAngle);
            }
            break;
        case 4:
            if (mapObject->mMoveAnglePerCallIncrement > 0) {
                mapObject->mMoveAnglePerCall =
                    StepIntTowardTarget(mapObject->mMoveAnglePerCallTarget, mapObject->mMoveAnglePerCallIncrement,
                                        mapObject->mMoveAnglePerCall);
            }
            if (mapObject->mMoveAnglePerCall > 0) {
                mapObject->mMoveAngle =
                    StepAngleSidewaysToPoint(&mapObject->mMoveAnglePoint, &mapObject->mUnk_000.mPos,
                                             mapObject->mMoveAnglePerCall, mapObject->mUnk_1c4, mapObject->mMoveAngle);
            }
            break;
    }

    if (mapObject->mSpeedPerCall > 0) {
        mapObject->mSpeed = StepIntTowardTarget(mapObject->mSpeedTarget, mapObject->mSpeedPerCall, mapObject->mSpeed);
    }
    if (mapObject->mOffsetPerCall > 0) {
        mapObject->mOffset.x =
            StepIntTowardTarget(mapObject->mOffsetTargetX, mapObject->mOffsetPerCall, mapObject->mOffset.x);
        mapObject->mOffset.y =
            StepIntTowardTarget(mapObject->mOffsetTargetY, mapObject->mOffsetPerCall, mapObject->mOffset.y);
        mapObject->mOffset.z =
            StepIntTowardTarget(mapObject->mOffsetTargetZ, mapObject->mOffsetPerCall, mapObject->mOffset.z);
    }
    if (mapObject->mCollisionExtentPerCall > 0) {
        mapObject->mCollisionExtent.x = StepIntTowardTarget(
            mapObject->mCollisionExtentTargetX, mapObject->mCollisionExtentPerCall, mapObject->mCollisionExtent.x);
        mapObject->mCollisionExtent.y = StepIntTowardTarget(
            mapObject->mCollisionExtentTargetY, mapObject->mCollisionExtentPerCall, mapObject->mCollisionExtent.y);
        mapObject->mCollisionExtent.z = StepIntTowardTarget(
            mapObject->mCollisionExtentTargetZ, mapObject->mCollisionExtentPerCall, mapObject->mCollisionExtent.z);
    }
    if (mapObject->mShadowOffsetPerCall > 0) {
        mapObject->mShadowOffsetX = StepIntTowardTarget(mapObject->mShadowOffsetTargetX,
                                                        mapObject->mShadowOffsetPerCall, mapObject->mShadowOffsetX);
        mapObject->mShadowOffsetY = StepIntTowardTarget(mapObject->mShadowOffsetTargetY,
                                                        mapObject->mShadowOffsetPerCall, mapObject->mShadowOffsetY);
        mapObject->mShadowOffsetZ = StepIntTowardTarget(mapObject->mShadowOffsetTargetZ,
                                                        mapObject->mShadowOffsetPerCall, mapObject->mShadowOffsetZ);
    }
    if (mapObject->mShadowScalePerCall > 0) {
        mapObject->mShadowScaleX = StepIntTowardTarget(mapObject->mShadowScaleTargetX, mapObject->mShadowScalePerCall,
                                                       mapObject->mShadowScaleX);
        mapObject->mShadowScaleY = StepIntTowardTarget(mapObject->mShadowScaleTargetY, mapObject->mShadowScalePerCall,
                                                       mapObject->mShadowScaleY);
        mapObject->mShadowScaleZ = StepIntTowardTarget(mapObject->mShadowScaleTargetZ, mapObject->mShadowScalePerCall,
                                                       mapObject->mShadowScaleZ);
    }

    if (mapObject->mGravityEnabled != FALSE) {
        mapObject->mVelocity.y -= mapObject->mPrm->mGravity;
    }
    if (-mapObject->mPrm->mStopSpeedLimit < *(s32 *) &mapObject->mVelocity &&
        *(s32 *) &mapObject->mVelocity < mapObject->mPrm->mStopSpeedLimit &&
        -mapObject->mPrm->mStopSpeedLimit < mapObject->mVelocity.z &&
        mapObject->mVelocity.z < mapObject->mPrm->mStopSpeedLimit) {
        mapObject->mVelocity.x = 0;
        mapObject->mVelocity.z = 0;
    } else if (mapObject->mCollisionBits & 0x1e34ef) {
        velocityScale = mapObject->mPrm->mCourseHitVelocityScale;
        mapObject->mVelocity.x = MUL_FIXED12_NO_ROUND(mapObject->mVelocity.x, velocityScale);
        mapObject->mVelocity.y = MUL_FIXED12_NO_ROUND(mapObject->mVelocity.y, velocityScale);
        mapObject->mVelocity.z = MUL_FIXED12_NO_ROUND(mapObject->mVelocity.z, velocityScale);
    } else {
        velocityScale = mapObject->mPrm->mFreeVelocityScale;
        mapObject->mVelocity.x = MUL_FIXED12_NO_ROUND(mapObject->mVelocity.x, velocityScale);
        mapObject->mVelocity.y = MUL_FIXED12_NO_ROUND(mapObject->mVelocity.y, velocityScale);
        mapObject->mVelocity.z = MUL_FIXED12_NO_ROUND(mapObject->mVelocity.z, velocityScale);
    }

    pairWordIndex = ((u16) mapObject->mMoveAngle >> 4) * 2;
    speed = mapObject->mSpeed;
    dy = mapObject->mVelocity.y;
    dz = mapObject->mVelocity.z + (s32) ((speed * FX_SinCosTable_[pairWordIndex + 1]) >> 12);
    dx = mapObject->mVelocity.x + (s32) ((speed * FX_SinCosTable_[pairWordIndex]) >> 12);
    mapObject->mUnk_000.mPos.x += dx;
    mapObject->mUnk_000.mPos.y += dy;
    mapObject->mUnk_000.mPos.z += dz;

    probePosition.x = mapObject->mUnk_000.mPos.x;
    probePosition.y = mapObject->mUnk_000.mPos.y + 0x14000;
    probePosition.z = mapObject->mUnk_000.mPos.z;
    mapObject->mCollisionBits = 0;
    if (CollideSphereWithCourse(&probePosition, NULL, 0, 0x14000,
                                mapObject->mCourseCollisionMode == 1 ? (u16) 4 : (u16) 1, -2, &pushOut, &v50, &v5c,
                                &mapObject->mCollisionBits, NULL, NULL, NULL, NULL)) {
        if (mapObject->mCourseCollisionMode == 2 || mapObject->mCourseCollisionMode == 3) {
            mapObject->mUnk_000.mPos.y += pushOut.y;
        } else {
            mapObject->mUnk_000.mPos.x += pushOut.x;
            mapObject->mUnk_000.mPos.y += pushOut.y;
            mapObject->mUnk_000.mPos.z += pushOut.z;
        }
    }
    if (mapObject->mCourseCollisionMode != 2 && (mapObject->mCollisionBits & 0x214300)) {
        if (LENGTH_SQUARED(v5c) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&v5c, &pushDirection);
        }
        pushDirection.y = 0;
        VEC_MultAdd(mapObject->mPrm->mWallPushVelocity, &pushDirection, &mapObject->mVelocity, &mapObject->mVelocity);
    }

    if (mapObject->mCollisionBits & 0x1e34ef) {
        if (mapObject->mVelocity.y > 0) {
            mapObject->mCollisionBits &= ~0x1e34ef;
        } else if (mapObject->mBounceEnabled != FALSE) {
            mapObject->mVelocity.y = MUL_FIXED12_NO_ROUND(mapObject->mVelocity.y, -mapObject->mPrm->mBounceScale);
            if (mapObject->mVelocity.y < mapObject->mPrm->mStopSpeedLimit) {
                mapObject->mBounceEnabled = FALSE;
                mapObject->mVelocity.y = 0;
            }
        } else {
            mapObject->mVelocity.y = 0;
        }
    }
    if (mapObject->mUnk_000.mPos.y < 0) {
        mapObject->mUnk_000.mPos.y = 0;
        mapObject->mCollisionBits |= gMapObjectBelowZeroCollisionBit;
    }
    if (mapObject->mAlphaLimitPerCall > 0) {
        mapObject->mAlphaLimit =
            StepIntTowardTarget(mapObject->mAlphaLimitTarget, mapObject->mAlphaLimitPerCall, mapObject->mAlphaLimit);
        if (mapObject->mAlphaLimit == mapObject->mAlphaLimitTarget) {
            mapObject->mAlphaLimitPerCall = 0;
        }
    }
    if (mapObject->mScalePerCall > 0) {
        mapObject->mUnk_000.mScale.x = mapObject->mUnk_000.mScale.y = mapObject->mUnk_000.mScale.z =
            StepIntTowardTarget(mapObject->mScaleTarget, mapObject->mScalePerCall, mapObject->mUnk_000.mScale.x);
    }
    if (mapObject->mCollisionShape == 1) {
        MTX_RotY33_(&mapObject->mUnk_000.mMatrix.mAxes, FX_SinIdx((u16) mapObject->mAngle),
                    FX_CosIdx((u16) mapObject->mAngle));
        MTX_MultVec33(&mapObject->mOffset, &mapObject->mUnk_000.mMatrix.mAxes, &mapObject->mPosWithOffset);
        VEC_Add(&mapObject->mPosWithOffset, &mapObject->mUnk_000.mPos, &mapObject->mPosWithOffset);
    } else {
        mapObject->mPosWithOffset.x = mapObject->mUnk_000.mPos.x + mapObject->mOffset.x;
        mapObject->mPosWithOffset.y = mapObject->mUnk_000.mPos.y + mapObject->mOffset.y;
        mapObject->mPosWithOffset.z = mapObject->mUnk_000.mPos.z + mapObject->mOffset.z;
    }
    mapObject->mUnk_000.mAngle = mapObject->mAngle;

    if (mapObject->mNsbmd != NULL) {
        previousFrame = GetMapObjectModelNsbcaFrameIndex(mapObject->mNsbmd);
        AdvanceMapObjectModelNsbcaAnimation(mapObject->mNsbmd);
        currentFrame = GetMapObjectModelNsbcaFrameIndex(mapObject->mNsbmd);
        if (mapObject->mAnimationFrameCallbackFrameIndex != 0) {
            if (previousFrame < mapObject->mAnimationFrameCallbackFrameIndex &&
                mapObject->mAnimationFrameCallbackFrameIndex <= currentFrame) {
                ClearAndRunCallback(mapObject, &mapObject->mAnimationFrameCallback);
            } else if (currentFrame < (u32) previousFrame &&
                       (mapObject->mAnimationFrameCallbackFrameIndex <= currentFrame ||
                        previousFrame < mapObject->mAnimationFrameCallbackFrameIndex)) {
                ClearAndRunCallback(mapObject, &mapObject->mAnimationFrameCallback);
            }
        }
        if (mapObject->mUnk_1e0 != 0) {
            if (previousFrame < mapObject->mUnk_1e0 && mapObject->mUnk_1e0 <= currentFrame) {
                mapObject->mUnk_1e4(mapObject);
            } else if (currentFrame < (u32) previousFrame &&
                       (mapObject->mUnk_1e0 <= currentFrame || previousFrame < mapObject->mUnk_1e0)) {
                mapObject->mUnk_1e4(mapObject);
            }
        }
        if (mapObject->mUnk_1e8 != 0) {
            if (previousFrame < mapObject->mUnk_1e8 && mapObject->mUnk_1e8 <= currentFrame) {
                mapObject->mUnk_1ec(mapObject);
            } else if (currentFrame < (u32) previousFrame &&
                       (mapObject->mUnk_1e8 <= currentFrame || previousFrame < mapObject->mUnk_1e8)) {
                mapObject->mUnk_1ec(mapObject);
            }
        }
        if (!IsMapObjectModelNsbcaPlaying(mapObject->mNsbmd)) {
            ClearAndRunCallback(mapObject, &mapObject->mAnimationEndCallback);
        }
    }

    mapObject->mStateFrames++;
    if (mapObject->mStateFrameCount != 0 && mapObject->mStateFrames == mapObject->mStateFrameCount) {
        mapObject->mStateFrameCount = 0;
        mapObject->mStateFrames = 0;
        ClearAndRunCallback(mapObject, &mapObject->mStateFrameCountCallback);
    }
    if (mapObject->mPointInRangeCallback != NULL &&
        IsPointInRange(mapObject, &mapObject->mPoint, mapObject->mPointRadius, mapObject->mPointHalfAngle)) {
        ClearAndRunCallback(mapObject, &mapObject->mPointInRangeCallback);
    }
    if (mapObject->mUnk_224 != NULL &&
        !IsPointInRange(mapObject, &mapObject->mUnk_218, mapObject->mUnk_210, mapObject->mUnk_214)) {
        ClearAndRunCallback(mapObject, &mapObject->mUnk_224);
    }
    if (mapObject->mStoppedCallback != NULL && mapObject->mVelocity.y == 0 &&
        -mapObject->mPrm->mStopSpeedLimit < mapObject->mSpeed && mapObject->mPrm->mStopSpeedLimit > mapObject->mSpeed &&
        -mapObject->mPrm->mStopSpeedLimit < mapObject->mVelocity.x &&
        mapObject->mPrm->mStopSpeedLimit > mapObject->mVelocity.x &&
        -mapObject->mPrm->mStopSpeedLimit < mapObject->mVelocity.z &&
        mapObject->mPrm->mStopSpeedLimit > mapObject->mVelocity.z && (mapObject->mCollisionBits & 0x1e34ef)) {
        ClearAndRunCallback(mapObject, &mapObject->mStoppedCallback);
    }
    if (mapObject->mCourseCollisionCallback != NULL && mapObject->mVelocity.y <= 0 &&
        (mapObject->mCollisionBits & 0x1e34ef)) {
        ClearAndRunCallback(mapObject, &mapObject->mCourseCollisionCallback);
    }

    for (effectIndex = 0; effectIndex < 5; effectIndex++) {
        ComputeEffectPosition(mapObject, effectIndex, &effectPosition);
        if (mapObject->mEffects[effectIndex].mEffect != NULL) {
            if (mapObject->mEffects[effectIndex].mTimer > 0 && --mapObject->mEffects[effectIndex].mTimer == 0) {
                StopEffectAndClearPointer(&mapObject->mEffects[effectIndex].mEffect);
            } else {
                PlaceEffect(mapObject->mEffects[effectIndex].mEffect, &effectPosition);
            }
        }
    }
    if (mapObject->mTimer > 0) {
        mapObject->mTimer--;
    }
}

void DrawMissionRunMapObject(void *mapObjectList, MissionRunMapObject *mapObject) {
    s32 materialIndex;
    s32 alphaLimit;
    NNSG3dResMdl *resMdl;
    s32 alpha;
    s32 value;
    Vec3 shiftedPosition;
    MtxFx33 rotationMatrix;

    alphaLimit = FROM_FIXED12(mapObject->mAlphaLimit);
    shiftedPosition.x = mapObject->mUnk_000.mPos.x >> 4;
    shiftedPosition.y = mapObject->mUnk_000.mPos.y >> 4;
    shiftedPosition.z = mapObject->mUnk_000.mPos.z >> 4;
    alpha = ComputeViewDepthAlpha(&shiftedPosition);
    if (alpha >= alphaLimit) {
        alpha = alphaLimit;
    }
    if (alpha > 0) {
        if (alpha >= 0x1f) {
            alpha = 0x1f;
        }
        if (alpha >= 0x1f) {
            NNS_G3dMdlSetMdlXLDepthUpdateAll(mapObject->mNsbmd->mAnimatedModel->mResMdl, 1);
            SetMapObjectModelPolygonId(mapObject->mNsbmd, 3);
        } else if (mapObject->mShadowMode <= 1) {
            NNS_G3dMdlSetMdlXLDepthUpdateAll(mapObject->mNsbmd->mAnimatedModel->mResMdl, 1);
            SetMapObjectModelPolygonId(mapObject->mNsbmd, 3);
        } else {
            resMdl = mapObject->mNsbmd->mAnimatedModel->mResMdl;
            NNS_G3dMdlSetMdlXLDepthUpdateAll(resMdl, 1);
            for (materialIndex = 0; materialIndex < resMdl->mInfo.mNumMat; materialIndex++) {
                SetMapObjectModelMaterialPolygonId(mapObject->mNsbmd, AllocPolygonIdWrapping(), materialIndex);
            }
        }
        value = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, &value, 1);
        NNS_G3dGeBufferOP_N(0x19, SetTranslationMatrixPos(&mapObject->mUnk_000.mPos), 0xc);
        if (mapObject->mUnk_000.mAngle != 0) {
            MTX_RotY33_(&rotationMatrix, SIN_OF_ANGLE(mapObject->mUnk_000.mAngle),
                        COS_OF_ANGLE(mapObject->mUnk_000.mAngle));
            NNS_G3dGeBufferOP_N(0x1a, &rotationMatrix, 9);
        }
        NNS_G3dGeBufferOP_N(0x1b, &mapObject->mUnk_000.mScale.x, 3);
        SetMapObjectModelAlpha(mapObject->mNsbmd, alpha);
        SetMapObjectModelMirror(mapObject->mNsbmd, mapObject->mUnk_000.mFlags & 0x400, 0);
        DrawMapObjectModel(mapObjectList, mapObject->mNsbmd, mapObject);
    }
}

void DrawMissionRunMapObjectShadow(void *mapObjectList, MissionRunMapObject *mapObject, s32 invertDepth) {
    s32 depth;
    s32 value;
    Vec3 shadowPosition;

    depth = FROM_FIXED12(mapObject->mAlphaLimit);
    if (mapObject->mShadowMode == 2) {
        shadowPosition.x = mapObject->mUnk_000.mPos.x;
        shadowPosition.y = mapObject->mUnk_000.mPos.y;
        shadowPosition.z = mapObject->mUnk_000.mPos.z;
    } else if (mapObject->mShadowMode == 3) {
        shadowPosition.x = mapObject->mNodePosition.x;
        shadowPosition.y = mapObject->mUnk_000.mCourseMapRow->mPosition.y;
        shadowPosition.z = mapObject->mNodePosition.z;
    } else {
        if (depth >= 4) {
            s32 adjustedDepth =
                depth - ((mapObject->mUnk_000.mPos.y - mapObject->mUnk_000.mCourseMapRow->mPosition.y) >> 15);

            if (adjustedDepth <= 4) {
                adjustedDepth = 4;
            }
            depth = (u16) adjustedDepth;
        }
        shadowPosition.x = mapObject->mUnk_000.mPos.x;
        shadowPosition.y = mapObject->mUnk_000.mCourseMapRow->mPosition.y;
        shadowPosition.z = mapObject->mUnk_000.mPos.z;
    }
    if (depth > 0x10) {
        depth = 0x10;
    }
    if (invertDepth != 0) {
        depth = 0x14 - depth;
    }
    if (depth > 0) {
        MtxFx33 rotationMatrix;
        Vec3 shadowOffset;
        Vec3 shadowScale;
        s32 offsetX;
        s32 offsetY;
        s32 offsetZ;

        value = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, &value, 1);
        NNS_G3dGeBufferOP_N(0x19, SetTranslationMatrixPos(&shadowPosition), 0xc);
        MTX_RotY33_(&rotationMatrix, SIN_OF_ANGLE((u16) mapObject->mAngle), COS_OF_ANGLE((u16) mapObject->mAngle));
        NNS_G3dGeBufferOP_N(0x1a, &rotationMatrix, 9);
        offsetZ = mapObject->mShadowOffsetZ >> 4;
        offsetY = mapObject->mShadowOffsetY >> 4;
        offsetX = mapObject->mShadowOffsetX >> 4;
        shadowOffset.x = offsetX;
        shadowOffset.y = offsetY;
        shadowOffset.z = offsetZ;
        NNS_G3dGeBufferOP_N(0x1c, &shadowOffset, 3);
        NNS_G3dGeBufferOP_N(0x1b, &mapObject->mShadowScaleX, 3);
        if (gShadowScaleToggle == 0) {
            shadowScale.x = 0x1333;
            shadowScale.y = 0x1000;
            shadowScale.z = 0x1333;
            NNS_G3dGeBufferOP_N(0x1b, &shadowScale, 3);
        }
        SetMapObjectModelPolygonId(mapObject->mShadowNsbmd, 3);
        SetMapObjectModelAlpha(mapObject->mShadowNsbmd, depth);
        DrawMapObjectModel(mapObjectList, mapObject->mShadowNsbmd, mapObject);
    }
}

s32 ComputeSphereHitOnMissionRunMapObject(MissionRunMapObject *mapObject, Vec3 *sphereCenter, s32 sphereRadius,
                                          Vec3 *overlapOffset) {
    s32 diffX;
    s32 diffY;
    s32 diffZ;

    switch (mapObject->mCollisionShape) {
        case 0:
            sphereRadius += mapObject->mCollisionExtent.x;
            diffX = sphereCenter->x - mapObject->mPosWithOffset.x;
            diffY = sphereCenter->y - mapObject->mPosWithOffset.y;
            diffZ = sphereCenter->z - mapObject->mPosWithOffset.z;
            if ((s64) diffZ * diffZ + ((s64) diffX * diffX + (s64) diffY * diffY) < (s64) sphereRadius * sphereRadius) {
                ComputeSphereOverlapOffset(sphereCenter, &mapObject->mPosWithOffset, sphereRadius, overlapOffset);
                return 1;
            }
            return 0;
        case 2:
            return ComputeSphereHitOnRotatedCylinder(sphereCenter, &mapObject->mPosWithOffset,
                                                     &mapObject->mUnk_000.mMatrix.mRows[0],
                                                     mapObject->mCollisionExtent.x, mapObject->mCollisionExtent.y,
                                                     mapObject->mCollisionExtent.y, sphereRadius, overlapOffset);
        case 1:
            return ComputeSphereHitOnRotatedBox(sphereCenter, &mapObject->mPosWithOffset,
                                                &mapObject->mUnk_000.mMatrix.mRows[0], &mapObject->mCollisionExtent,
                                                &mapObject->mCollisionExtent, sphereRadius, overlapOffset);
        default:
            return 0;
    }
}

s32 CollideKartWithMissionRunMapObject(MissionRunMapObject *mapObject, Kart *kart, u8 *firstResponsePointer,
                                       u8 *responsePointer) {
    Vec3 awayDirection;
    s64 pushStrength;
    u32 mode;
    UnkFunc *collisionCallback;

    mode = *firstResponsePointer;
    mapObject->mKartResponse = *responsePointer;
    mapObject->mUnk_000.mPosStep.x = 0;
    mapObject->mUnk_000.mPosStep.y = 0;
    mapObject->mUnk_000.mPosStep.z = 0;
    if (mode == 1) {
        awayDirection.x = mapObject->mUnk_000.mPos.x - kart->mPos.x;
        awayDirection.y = 0;
        awayDirection.z = mapObject->mUnk_000.mPos.z - kart->mPos.z;
        if ((s64) awayDirection.z * awayDirection.z +
                ((s64) awayDirection.x * awayDirection.x + (s64) awayDirection.y * awayDirection.y) >=
            16) {
            Vec3NormalizeAndGetLengthUnchecked(&awayDirection, &awayDirection);
            pushStrength = -mapObject->mPrm->mKartPushPosStep;
            mapObject->mUnk_000.mPosStep.x = MUL_FIXED12_NO_ROUND(awayDirection.x, pushStrength);
            mapObject->mUnk_000.mPosStep.y = MUL_FIXED12_NO_ROUND(awayDirection.y, pushStrength);
            mapObject->mUnk_000.mPosStep.z = MUL_FIXED12_NO_ROUND(awayDirection.z, pushStrength);
            VEC_MultAdd(mapObject->mPrm->mKartPushVelocity, &awayDirection, &mapObject->mVelocity,
                        &mapObject->mVelocity);
        }
        collisionCallback = mapObject->mKartCollisionCallback;
        mapObject->mKartCollisionCallback = NULL;
        if (collisionCallback) {
            collisionCallback(mapObject, kart);
        }
    }
    if (mapObject->mTimer == 0) {
        mapObject->mTimer = 0x1f;
    }
    return mapObject->mKartResponse;
}

s32 CollideItemWithMissionRunMapObject(MissionRunMapObject *mapObject, ItemObject *itemObject, u8 *firstResponsePointer,
                                       u8 *responsePointer) {
    Vec3 awayDirection;
    UnkFunc *collisionCallback;

    mapObject->mItemResponse = *responsePointer;
    awayDirection.x = mapObject->mUnk_000.mPos.x - itemObject->mPos.x;
    awayDirection.y = 0;
    awayDirection.z = mapObject->mUnk_000.mPos.z - itemObject->mPos.z;
    if ((s64) awayDirection.z * awayDirection.z +
            ((s64) awayDirection.x * awayDirection.x + (s64) awayDirection.y * awayDirection.y) >=
        16) {
        Vec3NormalizeAndGetLengthUnchecked(&awayDirection, &awayDirection);
        VEC_MultAdd(mapObject->mPrm->mItemPushVelocity, &awayDirection, &mapObject->mVelocity, &mapObject->mVelocity);
    }
    collisionCallback = mapObject->mItemCollisionCallback;
    mapObject->mItemCollisionCallback = NULL;
    if (collisionCallback) {
        collisionCallback(mapObject, itemObject);
    }
    return mapObject->mItemResponse;
}

MapObjectList *CreateEmptyMapObjectUpdateList(void) {
    return CreateMapObjectUpdateList(NULL, NULL, NULL);
}

const u32 gMapObjectBelowZeroCollisionBit = 0x800;
