#include "Main/Save/nvram_first_three.h"
#include "overlay_section_symbols.h"
#include "dwc_backup.h"

#pragma thumb on

u32 ReadNvramFirstThreeEntries(void *buffer) {
    int readResult;
    readResult = readNvram(gNvramEntriesOffset, 0x300, buffer);
    if (readResult != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off
