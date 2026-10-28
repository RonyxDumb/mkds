#include "00/code_02194828.h"

s32 func_ov000_02194828(void *unused, Unk02194828 *entry, Unk02194828Search *search) {
    if (entry->mValue != 0 && search->mKey == *entry->mValue) {
        search->mEntry = entry;
        return 0;
    }
    return 1;
}
