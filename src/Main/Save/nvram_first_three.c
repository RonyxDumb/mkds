#include "Main/Save/nvram_first_three.h"
#include "Main/Unknown/unk_02180000.h"
#include "code_021510a4.h"

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
