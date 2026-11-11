#include "01/code_02184cc8.h"
#include "01/code_02188218.h"
#include "01/code_0218820c.h"
#include "01/code_02185ef4.h"
#include "01/code_02188cd8.h"
#include "01/code_02188da4.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02021000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020e6000.h"

void StartDonketuRepeatJumpAfterHitState(Unk02188950 *mapObject) {
    if (GetRepeatsRemaining(mapObject) != 0) {
        Vec3 velocity = {0, 0, 0};

        velocity.y = mapObject->mPrm->mUnk_1f4;
        StartMapObjectState(mapObject, 5, NULL);
        StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_1ec, mapObject->mPrm->mUnk_1f0);
        SetVelocity(mapObject, &velocity);
        SetCourseCollisionCallback(mapObject, StartDonketuRepeatJumpAfterHitState);
    } else {
        StartMapObjectState(mapObject, 0, NULL);
    }
}

void StartDonketuRepeatJumpsAfterHit(Unk02188950 *mapObject) {
    SetRepeatsRemaining(mapObject, (u16) mapObject->mPrm->mUnk_1f8);
    StopTurningMoveFollowsAngle(mapObject);
    StartDonketuRepeatJumpAfterHitState(mapObject);
}

void StartDonketuRepeatJumpState(Unk02188950 *mapObject) {
    if (GetRepeatsRemaining(mapObject) != 0) {
        Vec3 velocity = {0, 0, 0};

        velocity.y = mapObject->mPrm->mUnk_124;
        StartMapObjectState(mapObject, 5, NULL);
        StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_11c, mapObject->mPrm->mUnk_120);
        SetVelocity(mapObject, &velocity);
        SetCourseCollisionCallback(mapObject, StartDonketuRepeatJumpState);
    } else {
        StartMapObjectState(mapObject, 0, NULL);
    }
}

void StartDonketuRepeatJumps(Unk02188950 *mapObject) {
    SetRepeatsRemaining(mapObject, (u16) mapObject->mPrm->mUnk_128);
    StopTurningMoveFollowsAngle(mapObject);
    StartDonketuRepeatJumpState(mapObject);
}
