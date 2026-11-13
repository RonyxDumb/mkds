#include "Main/Net/slot_result_sync_halfword.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Save/ghost_record_file.h"

SlotResultSyncHalfword *GetEntrySlotResultSyncHalfword(u32 entryIndex, u32 halfwordIndex) {
    WiFiRaceSyncEntry *entry = &gWiFiRaceSync->mEntries[entryIndex];
    return &entry->mSlotResultSyncs[halfwordIndex];
}
