#include "Main/Item/mission_run_koura_effects.h"
#include "Main/Graphics/effects.h"
#include "Main/Race/data_020f36d8.h"

#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Item/code_020f6be8.h"

void StartMissionRunKouraEffects(ItemObject *itemParam) {
    ItemObject *item = itemParam;

    if (item == NULL) {
        return;
    }
    if (gRaceSetup->mMode != MODE_MISSION_RUN) {
        return;
    }
    if ((u32) item->mKind > ITEM_OBJECT_KIND_KOURA_R) {
        return;
    }
    StartEffect(0x441, &item->mPos);
    StartEffect(0x440, &item->mPos);
}
