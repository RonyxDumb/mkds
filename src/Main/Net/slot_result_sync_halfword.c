#include "Main/Net/slot_result_sync_halfword.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"

SlotResultSyncHalfword *GetEntrySlotResultSyncHalfword(u32 entryIndex, u32 halfwordIndex) {
    WiFiRaceSyncEntry *entry = &g_GlobalAA->mEntries[entryIndex];
    return &entry->mSlotResultSyncs[halfwordIndex];
}
