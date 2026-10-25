#include "01/code_02181098.h"
#include "01/code_021811c8.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0214d000.h"

s32 func_ov001_021810bc(u8 *p0, u16 *p1) {
    s32 i;
    s32 changed;

    changed = 0;
    for (i = 0; i < data_ov001_021a9b88->mUnk_00 * data_ov001_021a9b88->mUnk_00; i++) {
        if (p0[i] < data_ov001_021a9b88->mUnk_08 && data_ov001_021a9b88->mUnk_20[i] != (u8) p1[p0[i]]) {
            changed = 1;
            func_ov001_021811c8();
            data_ov001_021a9b88->mUnk_20[i] = p1[p0[i]];
        }
    }
    return changed;
}

void func_ov001_02181098(void) {
    u8 *tmp;

    tmp = data_ov001_021a9b88->mUnk_20;
    data_ov001_021a9b88->mUnk_20 = data_ov001_021a9b88->mUnk_24;
    data_ov001_021a9b88->mUnk_24 = tmp;
    data_ov001_021a9b88->mUnk_14 = data_ov001_021a9b88->mUnk_14 == 0 ? 1 : 0;
}
