#include "Main/Net/scan_selected_entry.h"
#include "Main/Net/scan_slot.h"
#include "Main/MapObjects/data_0217a000.h"

#pragma thumb on

void SetSelectedScanEntry(u16 entryIndex) {
    int result;
    result = TrySelectScanSlot(entryIndex);
    if (result != 0) {
        gConnectionWork->mSelectedScanEntry = entryIndex;
    }
}

#pragma thumb off
