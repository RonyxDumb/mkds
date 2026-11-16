#include "Main/Unknown/code_020901a0.h"
#include "Main/Unknown/code_0207c000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217b000.h"

void mgenit_update(KartAiItemUse *itemUse, KartAi *kartAi) {
    enit_update(itemUse, kartAi);
}

void mgenit_notifySlotItemChanged(KartAiItemUse *itemUse, KartAi *kartAi) {
    enum { K0 } heldItemIndex;

    heldItemIndex = *(s32 *) &it_sDriverItemStatus[kartAi->mIndex].mHeldItem;
    itemUse->mHeldItemEntry = gBattleHeldItemEntries + heldItemIndex;
    enit_beginSlotItemTimeout(itemUse);
}

void UseItemWhenHasTarget(KartAiItemUse *itemUse, KartAi *kartAi) {
    if (kartAi->mTargetKart == NULL) {
        return;
    }
    enit_deployDragItem(itemUse, kartAi);
}

void UseItemAfterHeldOrOnTarget(KartAiItemUse *itemUse, KartAi *kartAi) {
    if (enit_updateSlotItemTimeout(itemUse) == 0 && kartAi->mTargetKart == NULL) {
        return;
    }
    enit_deployDragItem(itemUse, kartAi);
}

void func_0209024c(KartAiItemUse *itemUse, KartAi *kartAi) {
    if (enit_updateSlotItemTimeout(itemUse) == 0) {
        return;
    }
    enit_deployDragItem(itemUse, kartAi);
}

void func_020901f0(KartAiItemUse *itemUse, KartAi *kartAi) {
    if (enit_updateSlotItemTimeout(itemUse) == 0 && kartAi->mTargetKart == NULL) {
        return;
    }
    if (kartAi->mTurnAngleDegrees >= 0xa000) {
        return;
    }
    enit_deployDragItem(itemUse, kartAi);
}

void UseItemAfterHeldIfTurnUnder10(KartAiItemUse *itemUse, KartAi *kartAi) {
    if (enit_updateSlotItemTimeout(itemUse) == 0) {
        return;
    }
    if (kartAi->mTurnAngleDegrees >= 0xa000) {
        return;
    }
    enit_deployDragItem(itemUse, kartAi);
}
