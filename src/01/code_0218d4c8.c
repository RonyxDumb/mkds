#include "01/code_0218d4c8.h"
#include "01/code_02185ef4.h"
#include "01/code_02187eb0.h"
#include "01/code_02188cd8.h"
#include "01/code_0218d520.h"
#include "01/code_0218dce4.h"

void StartHanachanMoveState(Unk02188950 *mapObject) {
    u32 entryPercent;
    StartMapObjectState(mapObject, 1, &UpdateHanachanMoveState);
    SetStoppedCallback(mapObject, 0);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_088, mapObject->mPrm->mUnk_08c);
    entryPercent = GetCurrentGroupEntryPercent(mapObject);
    SetHanachanSpeedAndTurnToNextEntry(mapObject, entryPercent);
    entryPercent = GetCurrentGroupEntryPercent(mapObject);
    SetHanachanFollowersTurnTiming(mapObject, entryPercent);
    SetHanachanSoundCallbacks(mapObject);
}
