#include "Main/Item/item_kinoko_p_boost.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Item/item_pool.h"
#include "ITCM/collision_slots.h"

const Vec3 gKouraWBurstStartScale = {0x1000, 0x1000, 0x1000};
const ItemInfo gItemInfoKinokoP = {1, 1, 0xc, 1, 1, 0, StartItemKinokoPBoost};
const ItemKind gItemKindKinokoP = {
    0x130, 2,    1,      -1,     -1,    NULL,  NULL, NULL, NULL, NULL,         NULL,     NULL, ComputeViewTest,
    NULL,  NULL, NULL,   0,      0,     NULL,  0,    NULL, 1,    NULL,         0x4b0000, 2,    0x319a,
    0,     0,    0x1000, 0x1b33, 0x19a, 0x23d, 0,    0,    1,    {0, 0, 0, 0}, 0,        1,    1,
    1,     1,    0};

void StartItemKinokoPBoost(ItemInUse *inUse, HeldItem *heldItem) {
    StartHeldItemTimer(heldItem, 0x1c2);
    StartKartKinokoBoost(heldItem->mKartItems->mKart);
    inUse->mKartItems->mKinokoBoostStarted = TRUE;
    SetHeldItemUseDelay(heldItem, 0xc);
}
