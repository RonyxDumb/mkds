#include "01/code_0218add0.h"
#include "01/code_02185ef4.h"
#include "01/code_02187d14.h"
#include "01/code_02188158.h"
#include "01/code_02188cd8.h"
#include "01/code_02188da4.h"
#include "01/code_0218b298.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020fd264.h"
#include "code_02147cd8.h"

void ThrowItemBombsInRingAndCenter(MissionRunMapObject *mapObject) {
    RandomState64 *rng;
    s32 angle;
    s32 i;
    Vec3 pos;

    rng = GetMapObjectRandom();
    rng->mValue = (s64) rng->mMultiplier * (s64) rng->mValue + rng->mIncrement;
    angle = (u16) (((rng->mValue >> 32) << 16) >> 32);
    for (i = 0; i < 3; i++) {
        Vec3 vel = {0, 0, 0};
        angle += 0x5555;
        pos.x = mapObject->mUnk_000.mPos.x + MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_1e4, SIN_OF_ANGLE((u16) angle));
        pos.y = mapObject->mUnk_000.mPos.y;
        pos.z = mapObject->mUnk_000.mPos.z + MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_1e4, COS_OF_ANGLE((u16) angle));
        ThrowItemBombFromPosition(StartItemBomb(), &pos, &vel, mapObject->mPrm->mUnk_1e8);
    }
    {
        Vec3 pos2;
        Vec3 vel2 = {0, 0, 0};
        pos2.x = mapObject->mUnk_000.mPos.x;
        pos2.y = mapObject->mUnk_000.mPos.y;
        pos2.z = mapObject->mUnk_000.mPos.z;
        ThrowItemBombFromPosition(StartItemBombWithParkedItemBox(9), &pos2, &vel2, mapObject->mPrm->mUnk_1ec);
    }
    SetSpeedAndClearTarget(mapObject, 0);
}

void StartBombKingJumpLandState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_200, mapObject->mPrm->mUnk_204, NULL);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    StartEffectAtRowHeight(mapObject, 0, 0, 0, 0x411, 0);
    StartEffectAtRowHeight(mapObject, 0, 0, 0, 0x412, 0);
    StartCameraWobbleAtDistance(mapObject->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0, 0x1000);
    mapObject->mUnk_000.mFlags &= ~0x20;
    SetKartCollisionCallback(mapObject, NULL);
}

void StartBombKingJumpFallState(MissionRunMapObject *mapObject) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = mapObject->mPrm->mUnk_1fc;
    StartMapObjectState(mapObject, 3, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_1f4, mapObject->mPrm->mUnk_1f8);
    SetVelocity(mapObject, &velocity);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    SetCourseCollisionCallback(mapObject, StartBombKingJumpLandState);
    mapObject->mGravityEnabled = TRUE;
    StartMapObjectSound(&mapObject->mUnk_000, 0x23a);
    SetKartCollisionCallback(mapObject, BombKingJumpKartCollisionCallback);
}
