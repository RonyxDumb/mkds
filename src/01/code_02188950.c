#include "01/code_02188950.h"

void StopTurningMoveFollowsAngle(MissionRunMapObject *mapObject) {
    mapObject->mAngleState = 0;
    mapObject->mAnglePerCall = 0;
    mapObject->mAnglePerCallTarget = 0;
    mapObject->mAnglePerCallIncrement = 0;
    mapObject->mMoveAngleMode = 1;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = 0;
    mapObject->mMoveAnglePerCallIncrement = 0;
}

void TurnToPointMoveFollowsAngle(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement) {
    mapObject->mAngleState = 2;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mMoveAngleMode = 1;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = 0;
    mapObject->mMoveAnglePerCallIncrement = 0;
}

void TurnAndMoveToPointSameRate(MissionRunMapObject *mapObject, s32 perCallTarget, s32 perCallIncrement) {
    mapObject->mAngleState = 2;
    mapObject->mAnglePerCallTarget = perCallTarget;
    mapObject->mAnglePerCallIncrement = perCallIncrement;
    mapObject->mMoveAngleMode = 2;
    mapObject->mMoveAnglePerCallTarget = perCallTarget;
    mapObject->mMoveAnglePerCallIncrement = perCallIncrement;
}

void TurnFromPointMoveFollowsAngle(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement) {
    mapObject->mAngleState = 3;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mMoveAngleMode = 1;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = 0;
    mapObject->mMoveAnglePerCallIncrement = 0;
}

void StopTurningMoveFromPoint(MissionRunMapObject *mapObject, s32 moveAnglePerCallTarget,
                              s32 moveAnglePerCallIncrement) {
    mapObject->mAngleState = 0;
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
    mapObject->mAngleState = 4;
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
    mapObject->mAngleState = 2;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mMoveAngleMode = 4;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = moveAnglePerCallTarget;
    mapObject->mMoveAnglePerCallIncrement = moveAnglePerCallIncrement;
    mapObject->mUnk_1c4 = moveAngleOffset;
}

void SpinAngleStopMoveAngle(MissionRunMapObject *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement) {
    mapObject->mAngleState = 5;
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

    if (mapObject->mAngleState == 7) {
        angleState = 7;
    } else if (mapObject->mAngleState == 8) {
        angleState = 8;
    } else {
        angleState = 6;
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
    mapObject->mAngleState = 2;
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
