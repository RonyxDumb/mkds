#include "Main/Kart/kart_ai_staff_roll_advance.h"
#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_0208bd40.h"
#include "Main/Unknown/code_0208bd44.h"
#include "Main/Unknown/code_0208bf6c.h"
#include "Main/Unknown/code_0208bfd8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_0208c16c.h"
#include "Main/Kart/kart_ai_battle.h"
#include "Main/Unknown/code_0207d814.h"
#include "Main/Unknown/code_0207e654.h"
#include "Main/Course/course_map_shapes.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_0207c000.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Unknown/code_0207d000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0207e000.h"
#include "Main/Unknown/code_0207f000.h"
#include "Main/Kart/karts.h"
#include "Main/Kart/kart_ai_item_clear.h"
#include "Main/Unknown/code_02089ce4.h"
#include "Main/Kart/use_item.h"
#include "Main/Unknown/code_0207d7e4.h"
#include "Main/Unknown/code_02090000.h"

// Stores the CPU kart callbacks for Award and Mission Run, Staff Roll, Battle, or else the race ones.
void RegisterKartAiCallbacks(void) {
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD || gRaceSetup->mMode == MODE_MISSION_RUN) {
        gKartAiSetupCallback = SetupKartAiForAwardMissionRun;
        gKartAiResetCallback = ResetKartAiForAwardMissionRun;
        gKartAiAdvanceCallback = AdvanceKartAiForAwardMissionRun;
        gKartAiRequestLinkCallback = RequestKartAiPointLink;
        gKartAiIsLinkRequestedCallback = IsKartAiLinkRequested;
        gKartAiLinkPosAndDirectionCallback = CopyKartAiLinkPosAndDirection;
        gKartAiSetupHeldItemEntryCallback = SetupNonBattleKartAiHeldItemEntry;
        gKartAiSetupItemInUseEntryCallback = SetupNonBattleKartAiItemInUseEntry;
    } else if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        gKartAiSetupCallback = SetupKartAiForStaffRoll;
        gKartAiResetCallback = ResetKartAiForStaffRollNop;
        gKartAiAdvanceCallback = AdvanceKartAiForStaffRoll;
        gKartAiRequestLinkCallback = RequestKartAiPointLink;
        gKartAiIsLinkRequestedCallback = IsKartAiLinkRequested;
        gKartAiLinkPosAndDirectionCallback = CopyKartAiLinkPosAndDirection;
        gKartAiSetupHeldItemEntryCallback = SetupNonBattleKartAiHeldItemEntry;
        gKartAiSetupItemInUseEntryCallback = SetupNonBattleKartAiItemInUseEntry;
    } else if (gRaceSetup->mMode == MODE_BATTLE) {
        gKartAiSetupCallback = SetupKartAiForBattle;
        gKartAiResetCallback = ResetKartAiForBattle;
        gKartAiAdvanceCallback = AdvanceKartAiForBattle;
        gKartAiRequestLinkCallback = RequestBattleKartAiPointLink;
        gKartAiIsLinkRequestedCallback = IsBattleKartAiLinkRequested;
        gKartAiLinkPosAndDirectionCallback = CopyBattleKartAiLinkPosAndDirection;
        gKartAiSetupHeldItemEntryCallback = SetupBattleKartAiHeldItemEntry;
        gKartAiSetupItemInUseEntryCallback = SetupBattleKartAiItemInUseEntry;
    } else {
        gKartAiSetupCallback = SetupKartAiForRace;
        gKartAiResetCallback = ResetKartAiForRace;
        gKartAiAdvanceCallback = AdvanceKartAiForRace;
        gKartAiRequestLinkCallback = RequestKartAiPointLink;
        gKartAiIsLinkRequestedCallback = IsKartAiLinkRequested;
        gKartAiLinkPosAndDirectionCallback = CopyKartAiLinkPosAndDirection;
        gKartAiSetupHeldItemEntryCallback = SetupNonBattleKartAiHeldItemEntry;
        gKartAiSetupItemInUseEntryCallback = SetupNonBattleKartAiItemInUseEntry;
    }
}

void CallKartAiSetup(KartAi *kartAi, s32 kartIndex) {
    gKartAiSetupCallback(kartAi, kartIndex);
}

void CallKartAiReset(KartAi *kartAi, PointLink *link) {
    gKartAiResetCallback(kartAi, link);
}

void CallKartAiAdvance(KartAi *kartAi) {
    gKartAiAdvanceCallback(kartAi);
}

void CallKartAiRequestLink(KartAi *kartAi) {
    gKartAiRequestLinkCallback(kartAi);
}

void CallKartAiLinkPosAndDirection(Vec3 *position, Vec3 *direction, KartAi *kartAi) {
    gKartAiLinkPosAndDirectionCallback(position, direction, kartAi);
}

void CallKartAiSetupHeldItemEntry(KartAi *kartAi) {
    gKartAiSetupHeldItemEntryCallback(kartAi);
}

void CallKartAiSetupItemInUseEntry(KartAi *kartAi) {
    gKartAiSetupItemInUseEntryCallback(kartAi);
}

u32 GetKartAiHeadingSwingAtRaceStart(KartAi *kartAi) {
    return kartAi->mRaceSpeedLimit.mHeadingSwingAtRaceStart;
}

u32 GetKartAiBoostsAtRaceStart(KartAi *kartAi) {
    return kartAi->mRaceSpeedLimit.mBoostsAtRaceStart;
}

u32 GetKartAiRaceStartBoostChoice(KartAi *kartAi) {
    return kartAi->mRaceSpeedLimit.mRaceStartBoostChoice;
}

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

void SetupKartAiForBattle(KartAi *kartAi, s32 kartIndex) {
    Kart *kart;
    kart = GetKart(kartIndex);
    SetupBattleKartAi(kartAi, kart);
    SetupBattleKartAiSpeedLimit(&kartAi->mAiSpeedLimit, kartAi);
    ClearKartAiItemUseWrapper(&kartAi->mItemUse);
    PickBattleKartAiRaceStart(kartAi, &kartAi->mRaceSpeedLimit);
}

void ResetKartAiForBattle(KartAi *kartAi, PointLink *link) {
    ResetBattleKartAiAtPointLink(kartAi, link);
    SetupBattleKartAiSpeedLimit(&kartAi->mAiSpeedLimit, kartAi);
    ClearKartAiItemUseWrapper(&kartAi->mItemUse);
}

void AdvanceKartAiForBattle(KartAi *kartAi) {
    AdvanceBattleKartAi(kartAi);
    AdvanceBattleKartAiSpeedLimit(&kartAi->mAiSpeedLimit, kartAi);
    AdvanceBattleItemBitRequests(&kartAi->mItemUse, kartAi);
}

void RequestBattleKartAiPointLink(KartAi *kartAi) {
    if (kartAi->mBattleLinkCursor.mRequestedLink != NULL) {
        if (kartAi->mBattleLinkCursor.mUnk_18 != FALSE) {
            return;
        }
    }
    kartAi->mBattleLinkCursor.mRequestedLink = FindCourseMapKind4ShapeBattlePointLink(&kartAi->mKart->mPos);
    if (kartAi->mBattleLinkCursor.mRequestedLink != NULL) {
        kartAi->mBattleLinkCursor.mUnk_18 = TRUE;
    }
}

BOOL IsBattleKartAiLinkRequested(KartAi *kartAi) {
    return kartAi->mBattleLinkCursor.mRequestedLink != NULL;
}

void CopyBattleKartAiLinkPosAndDirection(Vec3 *position, Vec3 *direction, KartAi *kartAi) {
    LinkCursor *cursor = &kartAi->mBattleLinkCursor;

    *position = *cursor->mLink->mPoint;
    *direction = cursor->mDirection;
}

void SetupBattleKartAiHeldItemEntry(KartAi *kartAi) {
    SetupBattleHeldItemEntry(&kartAi->mItemUse, kartAi);
}

void SetupBattleKartAiItemInUseEntry(KartAi *kartAi) {
    SetupBattleItemInUseEntry(&kartAi->mItemUse, kartAi);
}

void SetupKartAiForAwardMissionRun(KartAi *kartAi, s32 kartIndex) {
    Kart *kart = GetKart(kartIndex);

    kartAi->mListedCpu = 0;
    SetupAwardMissionRunKartAi(kartAi, kart, kartAi->mListedCpu);
    InitKartAiRaceSpeedLimit(&kartAi->mRaceSpeedLimit, kartAi);
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        kartAi->mRaceSpeedLimit.mBoostsAtRaceStart = 1;
        kartAi->mRaceSpeedLimit.mRaceStartBoostChoice = 4;
    } else {
        kartAi->mRaceSpeedLimit.mBoostsAtRaceStart = 0;
        kartAi->mRaceSpeedLimit.mRaceStartBoostChoice = 0;
    }
}

void ResetKartAiForAwardMissionRun(KartAi *kartAi, RacePointLink *pointLink) {
    ResetAwardMissionRunKartAi(kartAi, pointLink);
    ResetAwardMissionRunKartAiSpeedLimit(&kartAi->mRaceSpeedLimit, kartAi);
}

void AdvanceKartAiForAwardMissionRun(KartAi *kartAi) {
    AdvanceAwardMissionRunKartAi(kartAi);
    AdvanceKartAiTurnSpeedLimit(&kartAi->mRaceSpeedLimit, kartAi);
}

void SetupKartAiForStaffRoll(KartAi *kartAi, s32 kartIndex) {
    Kart *kart = GetKart(kartIndex);

    kartAi->mListedCpu = 0;
    SetupStaffRollKartAi(kartAi, kart, kartAi->mListedCpu);
    InitKartAiRaceSpeedLimit(&kartAi->mRaceSpeedLimit, kartAi);
    kartAi->mRaceSpeedLimit.mBoostsAtRaceStart = 0;
    kartAi->mRaceSpeedLimit.mRaceStartBoostChoice = 0;
    if (kart->mIndex != gRaceSetup->mEntryIndex) {
        kart->mEntryFlags |= KART_ENTRY_HIDDEN;
    }
}

void ResetKartAiForStaffRollNop(u32 kartAi) {}

void AdvanceKartAiForStaffRoll(KartAi *kartAi) {
    AdvanceStaffRollKartAi(kartAi);
    AdvanceKartAiTurnSpeedLimit(&kartAi->mRaceSpeedLimit, kartAi);
}
