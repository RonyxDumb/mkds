#include "Main/Race/entry_race_ended.h"
#include "Main/Unknown/code_020f36d8.h"

u32 GetEntryRaceEnded(void) {
    return gRaceProgress->mEntryRaceEnded;
}
