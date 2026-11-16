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

    kartAi->field154 = (gRaceMultiConfig->mCurrentEntries[kartIndex].mPlayer.field14 & 1) != 0;
    SetupRaceKartAi(kartAi, kart, kartAi->field154);
    enrb_initForRace(&kartAi->fieldE8, kartAi);
    enit_init(&kartAi->mItemUse);
    PickKartAiRaceStart(&kartAi->fieldE8, kartAi);
}

void ResetKartAiForRace(KartAi *kartAi) {
    ResetRaceKartAiAtPointLink(kartAi);
    ResetRaceKartAiSpeedLimit(&kartAi->fieldE8, kartAi);
    enit_init(&kartAi->mItemUse);
}

void enmy_updateRaceEnemy(KartAi *kartAi) {
    AdvanceRaceKartAi(kartAi);
    enrb_updateForRace(&kartAi->fieldE8, kartAi);
    enit_updateForRace(&kartAi->mItemUse, kartAi);
}

void enmy_recalculateEpoiRoute(KartAi *kartAi) {
    if (kartAi->field8.mLinkCursor.mRequestedLink != NULL) {
        if (kartAi->field8.mLinkCursor.field18 != FALSE) {
            return;
        }
    }
    kartAi->field8.mLinkCursor.mRequestedLink = mdat_findEnemyPoint(&kartAi->mKart->mPos);
    if (kartAi->field8.mLinkCursor.mRequestedLink != NULL) {
        kartAi->field8.mLinkCursor.field18 = TRUE;
    }
}

BOOL enmy_getIsAreaEpoiNotNull(KartAi *kartAi) {
    return kartAi->field8.mLinkCursor.mRequestedLink != NULL;
}

void enmy_getTargetEpoiPosDir(Vec3 *position, Vec3 *direction, KartAi *kartAi) {
    LinkCursor *cursor = &kartAi->field8.mLinkCursor;

    *position = *cursor->mLink->field18;
    *direction = cursor->mDirection;
}

void enmy_notifySlotItemChangedForRace(KartAi *kartAi) {
    enit_notifySlotItemChanged(&kartAi->mItemUse, kartAi);
}

void enmy_notifyDragItemChangedForRace(KartAi *kartAi) {
    enit_notifyDragItemChanged(&kartAi->mItemUse, kartAi);
}
