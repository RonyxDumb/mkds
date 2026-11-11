#include "01/code_0218f900.h"
#include "01/code_02188cd8.h"

#include "01/code_02185ef4.h"
#include "01/code_02188000.h"
#include "01/code_02188158.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "01/code_0218f000.h"
#include "Main/Unknown/code_0209bef0.h"

u16 IsIwanteWalkB(MissionRunMapObject *mapObject) {
    return mapObject->mUnk_0a8 == 2;
}

void KingTeresaKartCollisionCallback(MissionRunMapObject *mapObject) {
    mapObject->mUnk_2d8 = 0;
    SetKartCollisionCallback(mapObject, KingTeresaKartCollisionCallback);
}

void ShowKingTeresaWithEffects(MissionRunMapObject *mapObject) {
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_198, mapObject->mPrm->mUnk_19c);
    SetAlphaLimitTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_1ac, mapObject->mPrm->mUnk_1b0);
    SetSpeedAndClearTarget(mapObject, 0);
    StopTurningMoveFollowsAngle(mapObject);
    StartEffectAtOffset(mapObject, 0, 0, 0, 0x41b, 0);
    StartEffectAtOffset(mapObject, 0, 0, 0, 0x41c, 0);
    StartEffectAtOffset(mapObject, 0, 0, 0, 0x41d, 0);
    StartMapObjectSound(&mapObject->mUnk_000, 0x22e);
    mapObject->mUnk_000.mFlags &= ~1;
}
