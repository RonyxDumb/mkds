#include "Main/Item/item_kind_copy_size.h"
#include "Main/Race/data_020f36d8.h"

#pragma thumb on

u32 GetItemKindCopyDataSize(int kind) {
    u32 size;
    UnkWordFunc *copyData;
    copyData = (UnkWordFunc *) gItemKinds[kind].mCopyData;
    if (copyData != NULL) {
        size = (*copyData)(0, 0, 1);
        return size;
    }
    return 0;
}

#pragma thumb off
