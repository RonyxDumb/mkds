#include "Main/Net/slot_result_sync_halfword.h"
#include "Main/Unknown/unk_0217a000.h"

SlotResultSyncHalfword *GetEntrySlotResultSyncHalfword(u32 entryIndex, u32 halfwordIndex) {
    WiFiRaceSyncEntry *entry = &gWiFiRaceSync->mEntries[entryIndex];
    return &entry->mSlotResultSyncs[halfwordIndex];
}
