#include "Main/Kart/KartAiCallbacks.h"
#include "Main/Unknown/code_0208bd20.h"
#include "Main/Unknown/code_0208bd40.h"
#include "Main/Unknown/code_0208bd44.h"
#include "Main/Unknown/code_0208bf6c.h"
#include "Main/Unknown/code_0208bfd8.h"
#include "Main/Unknown/unk_0217b000.h"

// Stores the CPU kart callbacks for Award and Mission Run, Staff Roll, Battle, or else the race ones.
void enmy_setupFunctions(void) {
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_AWARD || gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        enmy_sInitFunc = enmy_initAwardEnemy;
        gKartAiResetCallback = sub_208BDE0;
        enmy_sUpdateFunc = enmy_updateAwardEnemy;
        enmy_sRecalculateRouteFunc = enmy_recalculateEpoiRoute;
        enmy_sGetIsAreaPointNotNullFunc = enmy_getIsAreaEpoiNotNull;
        enmy_sGetTargetPosDirFunc = enmy_getTargetEpoiPosDir;
        enmy_sNotifySlotItemChangedFunc = enmy_notifySlotItemChangedForRace;
        enmy_sNotifyDragItemChangedFunc = enmy_notifyDragItemChangedForRace;
    } else if (gRaceMultiConfig->mRaceKind == RACE_KIND_STAFF_ROLL) {
        enmy_sInitFunc = enmy_initStaffRollEnemy;
        gKartAiResetCallback = func_0208bd40;
        enmy_sUpdateFunc = enmy_updateStaffRollEnemy;
        enmy_sRecalculateRouteFunc = enmy_recalculateEpoiRoute;
        enmy_sGetIsAreaPointNotNullFunc = enmy_getIsAreaEpoiNotNull;
        enmy_sGetTargetPosDirFunc = enmy_getTargetEpoiPosDir;
        enmy_sNotifySlotItemChangedFunc = enmy_notifySlotItemChangedForRace;
        enmy_sNotifyDragItemChangedFunc = enmy_notifyDragItemChangedForRace;
    } else if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        enmy_sInitFunc = enmy_initMgEnemy;
        gKartAiResetCallback = ResetKartAiForBattle;
        enmy_sUpdateFunc = enmy_updateMgEnemy;
        enmy_sRecalculateRouteFunc = enmy_recalculateMepoRoute;
        enmy_sGetIsAreaPointNotNullFunc = enmy_getIsAreaMepoNotNull;
        enmy_sGetTargetPosDirFunc = enmy_getTargetMepoPosDir;
        enmy_sNotifySlotItemChangedFunc = enmy_notifySlotItemChangedForMg;
        enmy_sNotifyDragItemChangedFunc = enmy_notifyDragItemChangedForMg;
    } else {
        enmy_sInitFunc = enmy_initRaceEnemy;
        gKartAiResetCallback = ResetKartAiForRace;
        enmy_sUpdateFunc = enmy_updateRaceEnemy;
        enmy_sRecalculateRouteFunc = enmy_recalculateEpoiRoute;
        enmy_sGetIsAreaPointNotNullFunc = enmy_getIsAreaEpoiNotNull;
        enmy_sGetTargetPosDirFunc = enmy_getTargetEpoiPosDir;
        enmy_sNotifySlotItemChangedFunc = enmy_notifySlotItemChangedForRace;
        enmy_sNotifyDragItemChangedFunc = enmy_notifyDragItemChangedForRace;
    }
}

void enmy_init(KartAi *kartAi, s32 kartIndex) {
    enmy_sInitFunc(kartAi, kartIndex);
}

void enmy_208C23C(KartAi *kartAi, PointLink *link) {
    gKartAiResetCallback(kartAi, link);
}

void enmy_update(KartAi *kartAi) {
    enmy_sUpdateFunc(kartAi);
}

void enmy_recalculateRoute(KartAi *kartAi) {
    enmy_sRecalculateRouteFunc(kartAi);
}

void enmy_getTargetPosDir(Vec3 *position, Vec3 *direction, KartAi *kartAi) {
    enmy_sGetTargetPosDirFunc(position, direction, kartAi);
}

void enmy_notifySlotItemChanged(KartAi *kartAi) {
    enmy_sNotifySlotItemChangedFunc(kartAi);
}

void enmy_notifyDragItemChanged(KartAi *kartAi) {
    enmy_sNotifyDragItemChangedFunc(kartAi);
}
