#include "01/code_021811c8.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0214d000.h"

u8 *func_ov001_02181200(s32 p0, s32 p1) {
    if (p0 >= 0 && p0 < data_ov001_021a9b88->mUnk_00 && p1 >= 0 && p1 < data_ov001_021a9b88->mUnk_00) {
        return data_ov001_021a9b88->mUnk_20 +
               ((p1 & 7) * 8 + ((p0 & 7) + p0 / 8 * 64) + data_ov001_021a9b88->mUnk_00 / 8 * (p1 / 8 * 64));
    }
    return 0;
}

void func_ov001_021811c8(void) {
    if (data_ov001_021a9b88->mUnk_0c == 0) {
        data_ov001_021a9b88->mUnk_10 = 1;
        data_ov001_021a9b88->mUnk_0c = 1;
        data_ov001_021a9b88->mUnk_14 = 0;
        func_0214d0a8(data_ov001_021a9b88->mUnk_20, data_ov001_021a9b88->mUnk_24,
                      data_ov001_021a9b88->mUnk_00 * data_ov001_021a9b88->mUnk_00);
    }
}
