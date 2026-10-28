#include "00/code_021868a4.h"

s32 func_ov000_021868a4(Unk021868a4 *list, void *first, void *second) {
    if (list->mCount > list->mCapacity) {
        return 0;
    }
    list->mEntries[list->mCount].mFirst = first;
    list->mEntries[list->mCount].mSecond = second;
    list->mCount++;
    return 1;
}
