#include "01/code_0218a3ec.h"
#include "01/code_02185ef4.h"
#include "01/code_02188cd8.h"

void StartBombKingKartEliminatedState(MissionRunMapObject *mapObject) {
    StartMapObjectState(mapObject, 8, (s32(*)(MissionRunMapObject *))(0));
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_078, mapObject->mPrm->mUnk_07c);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
}
