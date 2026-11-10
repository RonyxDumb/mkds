#include "Main/Unknown/code_0204ece0.h"
#include "Main/Unknown/code_02050080.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void SetSelectedScanEntry(u16 entryIndex) {
    int result;
    result = func_020501b0(entryIndex);
    if (result != 0) {
        gConnectionWork->mSelectedScanEntry = entryIndex;
    }
}

#pragma thumb off
