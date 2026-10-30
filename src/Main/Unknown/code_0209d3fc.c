#include "Main/Unknown/code_0209d3fc.h"
#include "Main/Unknown/code_01ff9000.h"
#include "Main/Unknown/code_02061808.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"

void func_0209d3fc(void *a, Unk0209d3fc *b) {
    s32 s;
    s32 t;
    s32 k;
    Vec3 v;

    s = 0x1e;
    func_01ff9048(0x14, &s, 1);
    func_01ff9048(0x19, func_020e6cf8(&b->mUnk_00.mUnk_04), 0xc);
    if (b->mUnk_dc == 3 || b->mUnk_dc == 4) {
        t = (s32) (((s64) data_0215d4b4[((u16) b->mUnk_ac >> 4) * 2 + 1] * -0x14000) >> 12) + 0x14000;
        k = (b->mUnk_b0 >> 4) * 2;
        v.x = (s32) (((s64) t * data_0215d4b4[k + 1]) >> 12) >> 4;
        v.y = (s32) (((s64) t * data_0215d4b4[k]) >> 12) >> 4;
        v.z = 0;
        func_01ff9048(0x1c, &v, 3);
    }
    func_01ff9048(0x1b, &b->mUnk_00.mUnk_1c, 3);
    if (func_02061818() == 2) {
        func_0209bbd0(a, data_usa_0217b16c);
        func_0209b77c(data_usa_0217b16c, b->mUnk_b2);
        func_0209bb2c(a, data_usa_0217b16c, b);
    } else if ((s32) (b->mUnk_00.mUnk_78 & 0x3fffffe0) < 0x3d0900) {
        func_0209bbd0(a, data_usa_0217b16c);
        func_0209b77c(data_usa_0217b16c, b->mUnk_b2);
        func_0209bb2c(a, data_usa_0217b16c, b);
    } else {
        func_0209bbd0(a, data_usa_0217b168);
        func_0209ba58(a, data_usa_0217b168, b);
    }
}
