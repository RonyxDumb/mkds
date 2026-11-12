#include "Main/Item/item_kinoko_p_boost.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Item/item_pool.h"

void StartItemKinokoPBoost(ItemInUse *inUse, HeldItem *heldItem) {
    StartHeldItemTimer(heldItem, 0x1c2);
    StartKartKinokoBoost(heldItem->mKartItems->mKart);
    inUse->mKartItems->mKinokoBoostStarted = TRUE;
    SetHeldItemUseDelay(heldItem, 0xc);
}
