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

void SetupKartAiForRace(KartAi *kartAi, s32 kartIndex) {
    Kart *kart = GetKart(kartIndex);

    kartAi->mListedCpu =
        (gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mListedCpuFlags & KART_ENTRY_LISTED_CPU_FLAG) != 0;
    SetupRaceKartAi(kartAi, kart, kartAi->mListedCpu);
    SetupRaceKartAiSpeedLimit(&kartAi->mRaceSpeedLimit, kartAi);
    ClearKartAiItemUse(&kartAi->mItemUse);
    PickKartAiRaceStart(&kartAi->mRaceSpeedLimit, kartAi);
}

void ResetKartAiForRace(KartAi *kartAi) {
    ResetRaceKartAiAtPointLink(kartAi);
    ResetRaceKartAiSpeedLimit(&kartAi->mRaceSpeedLimit, kartAi);
    ClearKartAiItemUse(&kartAi->mItemUse);
}

void AdvanceKartAiForRace(KartAi *kartAi) {
    AdvanceRaceKartAi(kartAi);
    AdvanceRaceKartAiSpeedLimit(&kartAi->mRaceSpeedLimit, kartAi);
    AdvanceRaceItemBitRequests(&kartAi->mItemUse, kartAi);
}

void RequestKartAiPointLink(KartAi *kartAi) {
    if (kartAi->mPointLinkCursor.mRequestedLink != NULL) {
        if (kartAi->mPointLinkCursor.mUnk_18 != FALSE) {
            return;
        }
    }
    kartAi->mPointLinkCursor.mRequestedLink = FindCourseMapKind4ShapeRacePointLink(&kartAi->mKart->mPos);
    if (kartAi->mPointLinkCursor.mRequestedLink != NULL) {
        kartAi->mPointLinkCursor.mUnk_18 = TRUE;
    }
}

BOOL IsKartAiLinkRequested(KartAi *kartAi) {
    return kartAi->mPointLinkCursor.mRequestedLink != NULL;
}

void CopyKartAiLinkPosAndDirection(Vec3 *position, Vec3 *direction, KartAi *kartAi) {
    PointLinkCursor *cursor = &kartAi->mPointLinkCursor;

    *position = *cursor->mLink->mPoint;
    *direction = cursor->mDirection;
}

void SetupNonBattleKartAiHeldItemEntry(KartAi *kartAi) {
    SetupHeldItemEntry(&kartAi->mItemUse, kartAi);
}

void SetupNonBattleKartAiItemInUseEntry(KartAi *kartAi) {
    SetupItemInUseEntry(&kartAi->mItemUse, kartAi);
}
