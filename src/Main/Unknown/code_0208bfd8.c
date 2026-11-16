#include "Main/Unknown/code_0208bfd8.h"
#include "Main/Unknown/code_0207d814.h"
#include "Main/Unknown/code_0207e654.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_0207c000.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_0207d000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0207e000.h"
#include "Main/Unknown/code_0207f000.h"
#include "Main/Unknown/code_02077bc0.h"

void enmy_initRaceEnemy(KartAi *kartAi, s32 kartIndex) {
    Kart *kart = driver_getById(kartIndex);

    kartAi->mUnk_154 = (gRaceMultiConfig->mCurrentEntries[kartIndex].mPlayer.mUnk_14 & 1) != 0;
    SetupRaceKartAi(kartAi, kart, kartAi->mUnk_154);
    enrb_initForRace(&kartAi->mUnk_e8, kartAi);
    enit_init(&kartAi->mItemUse);
    PickKartAiRaceStart(&kartAi->mUnk_e8, kartAi);
}

void ResetKartAiForRace(KartAi *kartAi) {
    ResetRaceKartAiAtPointLink(kartAi);
    ResetRaceKartAiSpeedLimit(&kartAi->mUnk_e8, kartAi);
    enit_init(&kartAi->mItemUse);
}

void enmy_updateRaceEnemy(KartAi *kartAi) {
    AdvanceRaceKartAi(kartAi);
    enrb_updateForRace(&kartAi->mUnk_e8, kartAi);
    enit_updateForRace(&kartAi->mItemUse, kartAi);
}

void enmy_recalculateEpoiRoute(KartAi *kartAi) {
    if (kartAi->mUnk_08.mLinkCursor.mRequestedLink != NULL) {
        if (kartAi->mUnk_08.mLinkCursor.mUnk_18 != FALSE) {
            return;
        }
    }
    kartAi->mUnk_08.mLinkCursor.mRequestedLink = mdat_findEnemyPoint(&kartAi->mKart->mPos);
    if (kartAi->mUnk_08.mLinkCursor.mRequestedLink != NULL) {
        kartAi->mUnk_08.mLinkCursor.mUnk_18 = TRUE;
    }
}

BOOL enmy_getIsAreaEpoiNotNull(KartAi *kartAi) {
    return kartAi->mUnk_08.mLinkCursor.mRequestedLink != NULL;
}

void enmy_getTargetEpoiPosDir(Vec3 *position, Vec3 *direction, KartAi *kartAi) {
    LinkCursor *cursor = &kartAi->mUnk_08.mLinkCursor;

    *position = *cursor->mLink->mUnk_18;
    *direction = cursor->mDirection;
}

void enmy_notifySlotItemChangedForRace(KartAi *kartAi) {
    enit_notifySlotItemChanged(&kartAi->mItemUse, kartAi);
}

void enmy_notifyDragItemChangedForRace(KartAi *kartAi) {
    enit_notifyDragItemChanged(&kartAi->mItemUse, kartAi);
}
