#include "Main/Item/item_kind_copy_size.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Item/item_pool.h"

#pragma thumb on

u32 GetItemKindCopyDataSize(int kind) {
    u32 size;
    u32 (*copyData)(void *, void *, s32);
    copyData = (u32(*)(void *, void *, s32)) gItemKinds[kind].mCopyData;
    if (copyData != NULL) {
        size = (*copyData)(0, 0, 1);
        return size;
    }
    return 0;
}

#pragma thumb off
