#include "Main/Item/mission_run_koura_effects.h"
#include "Main/Graphics/effects.h"
#include "Main/Item/item_objects_and_race_progress.h"

#include "Main/Race/race_setup_block.h"
#include "tp.h"
#include "Main/Item/item_object_fade_out.h"

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
