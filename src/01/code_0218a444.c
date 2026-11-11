#include "01/code_0218a444.h"
#include "01/code_02185ef4.h"
#include "01/code_02188cd8.h"
#include "01/code_02189da4.h"
#include "01/code_0218a568.h"

void StartBombKingStoppedState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_174, mapObject->mPrm->mUnk_178, NULL);
    SetItemCollisionCallback(mapObject, (UnkFunc *) &BombKingItemHitCallback);
}

void StartBombKingBounceState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, &SwitchToBounceEffectsOnCollision);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_164, mapObject->mPrm->mUnk_168);
    SetStoppedCallback(mapObject, &StartBombKingStoppedState);
    SetSpeedAndClearTarget(mapObject, 0);
    mapObject->mBounceEnabled = TRUE;
    SetItemCollisionCallback(mapObject, (UnkFunc *) &BombKingItemBounceCallback);
}

void StartBombKingStoppedStateAfterHits(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, NULL);
    StartAnimationWithEndCallback(mapObject, mapObject->mPrm->mUnk_070, mapObject->mPrm->mUnk_074, NULL);
    SetItemCollisionCallback(mapObject, (UnkFunc *) &BombKingItemHitCallback);
}

void StartBombKingBounceStateAfterHits(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 7, &SwitchToBounceEffectsOnCollision);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_164, mapObject->mPrm->mUnk_168);
    SetStoppedCallback(mapObject, &StartBombKingStoppedStateAfterHits);
    SetSpeedAndClearTarget(mapObject, 0);
    mapObject->mBounceEnabled = TRUE;
    SetItemCollisionCallback(mapObject, (UnkFunc *) &BombKingItemBounceCallback);
}
