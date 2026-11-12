#include "Main/Item/item_kinoko_p_boost.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Item/item_pool.h"

void StartItemKinokoPBoost(ItemInUse *inUse, HeldItem *heldItem) {
    StartHeldItemTimer(heldItem, 0x1c2);
    StartKartKinokoBoost(heldItem->mKartItems->mKart);
    inUse->mKartItems->mKinokoBoostStarted = TRUE;
    SetHeldItemUseDelay(heldItem, 0xc);
}
