#include "Main/Unknown/code_020fcb4c.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020ee684.h"

void itkinop_activate(ItemInUse *inUse, HeldItem *heldItem) {
    it_setSlotTimeout(heldItem, 0x1c2);
    driver_startShroomBoost(heldItem->mKartItems->mKart);
    inUse->mKartItems->mKinokoBoostStarted = TRUE;
    it_20F4188(heldItem, 0xc);
}
