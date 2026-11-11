#include "Main/Unknown/code_0204f5e4.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void ResetPendingFiles(void) {
    int entryIndex;
    BlockTransferView *view;
    BlockEntry *entry;
    u32 flagBitsMask;
    u32 clearPendingMask;
    flagBitsMask = (0xe0000000u);
    clearPendingMask = (0xdfffffffu);
    view = &gConnectionWork->mUnk_16a0_view;
    entryIndex = 0;
    entry = view->mBlockEntries;
    do {
        entry->mPath = 0;
        entry->mBuffer = NULL;
        entry->mUncompressedBuffer = NULL;
        entry->mUnk_84 = entry->mUnk_84 & clearPendingMask;
        entry->mUnk_84 = entry->mUnk_84 & flagBitsMask;
        entry = entry + 1;
        entryIndex = entryIndex + 1;
    } while (entryIndex < 0xc);
    view->mNextLoadIndex = 0xc;
}

#pragma thumb off
