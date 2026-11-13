#include "Main/Race/entry_race_ended.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/System/init_after_startup.h"

u32 GetEntryRaceEnded(void) {
    return gRaceProgress->mEntryRaceEnded;
}
