#include "Main/Kart/use_item.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/kart_items_collision_hits.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Race/gp_records_killer.h"

void AdvanceBattleItemBitRequests(KartAiItemUse *itemUse, KartAi *kartAi) {
    AdvanceItemBitRequests(itemUse, kartAi);
}

void SetupBattleHeldItemEntry(KartAiItemUse *itemUse, KartAi *kartAi) {
    enum { HELD_ITEM_INDEX_FIRST } heldItemIndex;

    heldItemIndex = gKartItems[kartAi->mIndex].mHeldItem.mItemInfoIndex;
    itemUse->mHeldItemEntry = gBattleHeldItemEntries + heldItemIndex;
    ResetHeldItemTimer(itemUse);
}

void UseItemWhenHasTarget(KartAiItemUse *itemUse, KartAi *kartAi) {
    if (kartAi->mTargetKart == NULL) {
        return;
    }
    UseItemAndResetInUseTimer(itemUse, kartAi);
}

void UseItemAfterHeldOrOnTarget(KartAiItemUse *itemUse, KartAi *kartAi) {
    if (DecrementHeldItemTimer(itemUse) == 0 && kartAi->mTargetKart == NULL) {
        return;
    }
    UseItemAndResetInUseTimer(itemUse, kartAi);
}

void EasyUseItemAfterHeld(KartAiItemUse *itemUse, KartAi *kartAi) {
    if (DecrementHeldItemTimer(itemUse) == 0) {
        return;
    }
    UseItemAndResetInUseTimer(itemUse, kartAi);
}

void UseItemAfterHeldOrOnTargetIfTurnUnder10(KartAiItemUse *itemUse, KartAi *kartAi) {
    if (DecrementHeldItemTimer(itemUse) == 0 && kartAi->mTargetKart == NULL) {
        return;
    }
    if (kartAi->mTurnAngleDegrees >= KART_AI_ITEM_TURN_ANGLE_LIMIT) {
        return;
    }
    UseItemAndResetInUseTimer(itemUse, kartAi);
}

void UseItemAfterHeldIfTurnUnder10(KartAiItemUse *itemUse, KartAi *kartAi) {
    if (DecrementHeldItemTimer(itemUse) == 0) {
        return;
    }
    if (kartAi->mTurnAngleDegrees >= KART_AI_ITEM_TURN_ANGLE_LIMIT) {
        return;
    }
    UseItemAndResetInUseTimer(itemUse, kartAi);
}
