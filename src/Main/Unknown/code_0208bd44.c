#include "Main/Unknown/code_0208bd44.h"
#include "Main/Unknown/code_0207d814.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_02089ce4.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_0207d000.h"
#include "Main/Unknown/code_020901a0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0207d7e4.h"
#include "Main/Unknown/code_0207e000.h"
#include "Main/Unknown/code_02090000.h"
#include "Main/Unknown/code_02077bc0.h"

void enmy_updateMgEnemy(KartAi *kartAi) {
    mgen_update(kartAi);
    mgenrb_update(&kartAi->mAiSpeedLimit, kartAi);
    mgenit_update(&kartAi->mItemUse, kartAi);
}

void enmy_recalculateMepoRoute(KartAi *kartAi) {
    if (kartAi->mBattleLinkCursor.mRequestedLink != NULL) {
        if (kartAi->mBattleLinkCursor.mUnk_18 != FALSE) {
            return;
        }
    }
    kartAi->mBattleLinkCursor.mRequestedLink = mdat_findMgEnemyPoint(&kartAi->mKart->mPos);
    if (kartAi->mBattleLinkCursor.mRequestedLink != NULL) {
        kartAi->mBattleLinkCursor.mUnk_18 = TRUE;
    }
}

BOOL enmy_getIsAreaMepoNotNull(KartAi *kartAi) {
    return kartAi->mBattleLinkCursor.mRequestedLink != NULL;
}

void enmy_getTargetMepoPosDir(Vec3 *position, Vec3 *direction, KartAi *kartAi) {
    LinkCursor *cursor = &kartAi->mBattleLinkCursor;

    *position = *cursor->mLink->mUnk_20;
    *direction = cursor->mDirection;
}

void enmy_notifySlotItemChangedForMg(KartAi *kartAi) {
    mgenit_notifySlotItemChanged(&kartAi->mItemUse, kartAi);
}

void enmy_notifyDragItemChangedForMg(KartAi *kartAi) {
    mgenit_notifyDragItemChanged(&kartAi->mItemUse, kartAi);
}

void enmy_initAwardEnemy(KartAi *kartAi, s32 kartIndex) {
    Kart *kart = driver_getById(kartIndex);

    kartAi->mUnk_154 = 0;
    SetupAwardMissionRunKartAi(kartAi, kart, kartAi->mUnk_154);
    enrb_initForAwardStaffRoll(&kartAi->mUnk_e8, kartAi);
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        kartAi->mUnk_e8.mBoostsAtRaceStart = 1;
        kartAi->mUnk_e8.mRaceStartBoostChoice = 4;
    } else {
        kartAi->mUnk_e8.mBoostsAtRaceStart = 0;
        kartAi->mUnk_e8.mRaceStartBoostChoice = 0;
    }
}

void func_0208bde0(KartAi *kartAi, PointLink *pointLink) {
    ResetAwardMissionRunKartAi(kartAi, pointLink);
    enrb_207D7E4(&kartAi->mUnk_e8, kartAi);
}

void enmy_updateAwardEnemy(KartAi *kartAi) {
    AdvanceAwardMissionRunKartAi(kartAi);
    enrb_updateForAwardStaffRoll(&kartAi->mUnk_e8, kartAi);
}

void enmy_initStaffRollEnemy(KartAi *kartAi, s32 kartIndex) {
    Kart *kart = driver_getById(kartIndex);

    kartAi->mUnk_154 = 0;
    SetupStaffRollKartAi(kartAi, kart, kartAi->mUnk_154);
    enrb_initForAwardStaffRoll(&kartAi->mUnk_e8, kartAi);
    kartAi->mUnk_e8.mBoostsAtRaceStart = 0;
    kartAi->mUnk_e8.mRaceStartBoostChoice = 0;
    if (kart->mIndex != gRaceMultiConfig->mEntryIndex) {
        kart->mUnk_7c |= 0x40;
    }
}
