#include "Main/Item/mission_run_koura_effects.h"
#include "Main/Graphics/effects.h"
#include "Main/Unknown/code_020f36d8.h"

#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020f6be8.h"

void StartMissionRunKouraEffects(ItemObject *itemParam) {
    ItemObject *item = itemParam;

    if (item == NULL) {
        return;
    }
    if (gRaceSetup->mMode != MODE_MISSION_RUN) {
        return;
    }
    if ((u32) item->mKind > 1) {
        return;
    }
    StartEffect(0x441, &item->mPos);
    StartEffect(0x440, &item->mPos);
}
