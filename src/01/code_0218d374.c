#include "01/code_0218d374.h"
#include "01/code_02187eb0.h"
#include "01/code_02188cd8.h"

#include "01/code_02185ef4.h"
#include "01/code_02188000.h"
#include "01/code_02188da4.h"
#include "01/code_02187000.h"
#include "01/code_0218d520.h"
#include "01/code_0218dce4.h"
#include "01/code_0218ddb4.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_0210b708.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_0218d000.h"
#include "01/code_0218e000.h"
#include "01/unk_021a7000.h"

void StartHanachanMoveStateByBalloons(Unk02188950 *mapObject) {
    s32 speedPercent;
    s32 scaleFactor;
    s32 entryPercent;

    if (GetBalloonOrShineCount(gRaceSetup->mEntryIndex) <= 1) {
        scaleFactor = 0x1000 - mapObject->mPrm->mUnk_0ac;
        entryPercent = GetCurrentGroupEntryPercent(mapObject);
        speedPercent = MUL_FIXED12_NO_ROUND(entryPercent, scaleFactor);
    } else if (GetBalloonOrShineCount(gRaceSetup->mEntryIndex) <= 2) {
        scaleFactor = 0x1000 - mapObject->mPrm->mUnk_0a8;
        entryPercent = GetCurrentGroupEntryPercent(mapObject);
        speedPercent = MUL_FIXED12_NO_ROUND(entryPercent, scaleFactor);
    } else {
        speedPercent = GetCurrentGroupEntryPercent(mapObject);
    }
    StartMapObjectState(mapObject, 1, UpdateHanachanMoveState);
    SetStoppedCallback(mapObject, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_088, mapObject->mPrm->mUnk_08c);
    SetHanachanSpeedAndTurnToNextEntry(mapObject, speedPercent);
    SetHanachanFollowersTurnTiming(mapObject, speedPercent);
    StartHanachanAnimationScaled(mapObject, speedPercent);
    SetHanachanSoundCallbacks(mapObject);
}

void StartHanachanKartEliminatedState(Unk02188950 *mapObject) {
    int i;
    MapObjectList *list;
    Unk02188950 *follower;

    StartMapObjectState(mapObject, 8, NULL);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_078, mapObject->mPrm->mUnk_07c);
    StopTurningMoveFollowsAngle(mapObject);
    SetSpeedAndClearTarget(mapObject, 0);
    list = FindMapObjectKindUpdateList(0x1fe);
    if (list != NULL) {
        for (i = 0; i < list->mMapObjectCount && (follower = list->mMapObjects[i]) != NULL; i++) {
            StartMapObjectState(follower, 1, NULL);
            StartAnimationNoEndCallback(follower, follower->mPrm->mUnk_078, follower->mPrm->mUnk_07c);
        }
    }
}
