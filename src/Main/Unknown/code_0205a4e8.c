#include "Main/Unknown/code_0205a4e8.h"
#include "Main/Unknown/unk_0217a000.h"

SlotResultSyncHalfword *GetEntrySlotResultSyncHalfword(u32 entryIndex, u32 halfwordIndex) {
    WiFiRaceSyncEntry *entry = &gWiFiRaceSync->mEntries[entryIndex];
    return &entry->mSlotResultSyncs[halfwordIndex];
}
