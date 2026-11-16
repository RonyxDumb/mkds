#include "Main/Race/entry_race_ended.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/System/init_after_startup.h"

u32 GetEntryRaceEnded(void) {
    return gRaceProgress->mEntryRaceEnded;
}
