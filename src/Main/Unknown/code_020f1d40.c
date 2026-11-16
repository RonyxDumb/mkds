#include "Main/Unknown/code_020f1d40.h"
#include "Main/Unknown/code_020f36d8.h"

#pragma thumb on

u32 GetItemKindCopyDataSize(int kind) {
    u32 size;
    UnkWordFunc *copyData;
    copyData = (UnkWordFunc *) it_sItemParams[kind].mCopyData;
    if (copyData != NULL) {
        size = (*copyData)(0, 0, 1);
        return size;
    }
    return 0;
}

#pragma thumb off
