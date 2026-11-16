#include "Main/Net/scan_selected_entry.h"
#include "Main/Net/scan_slot.h"
#include "Main/System/backup_net_camera_work.h"

#pragma thumb on

void SetSelectedScanEntry(u16 entryIndex) {
    int result;
    result = TrySelectScanSlot(entryIndex);
    if (result != 0) {
        g_GlobalZE->mSelectedScanEntry = entryIndex;
    }
}

#pragma thumb off
