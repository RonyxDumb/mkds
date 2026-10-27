#include "03/code_021d1d60.h"
#include "03/code_021d1d88.h"

Unk021d1d88 *func_ov003_021d1d60(s32 count, void *buffer, s32 stride) {
    u8 *entry = buffer;
    Unk021d1d88 *list = func_ov003_021d1d88(count);
    s32 i;

    for (i = 0; i < count; i++) {
        list->mUnk_04[i] = entry;
        entry += stride;
    }
    list->mUnk_03 = count;
    return list;
}
