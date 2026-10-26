#include "01/code_02181844.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_0210b000.h"

void func_ov001_021819f4(void) {
    Unk0206bcb0 *c;
    Unk021a9b90 *o;

    data_ov001_021a9b90 = func_02036bec((void *) func_020364e0(func_020364e8()), 0x68);
    c = func_0207a974((u16) data_021759c0->mUnk_62);
    o = data_ov001_021a9b90;
    o->mUnk_34 = c->mUnk_80;
    o->mUnk_28 = o->mUnk_34;
    o->mUnk_42 = c->mUnk_236;
    o = data_ov001_021a9b90;
    o->mUnk_40 = o->mUnk_42;
}

void func_ov001_02181860(void) {
    Unk0206bcb0 *c;
    Unk021a9b90 *o;

    c = func_0207a974((u16) data_021759c0->mUnk_62);
    if ((c->mUnk_48 & 0x200) == 0) {
        o = data_ov001_021a9b90;
        o->mUnk_34 = o->mUnk_28;
        o->mUnk_42 = o->mUnk_40;
        o = data_ov001_021a9b90;
        o->mUnk_28 = c->mUnk_80;
        o->mUnk_40 = c->mUnk_236;
    }
    if (data_021759c0->mUnk_08 == 4 ? func_020a126c() : 0) {
        if (data_021759c0->mUnk_08 == 4 ? func_020a1084((u16) data_021759c0->mUnk_62) : 0) {
            if (func_020a1154((u16) data_021759c0->mUnk_62)) {
                data_ov001_021a9b90->mUnk_00 += 1;
                if (data_ov001_021a9b90->mUnk_00 > 0xf) {
                    data_ov001_021a9b90->mUnk_00 = 0;
                    func_020a1748((u16) data_021759c0->mUnk_62);
                    return;
                }
            }
        }
        return;
    }
    {
        u32 m = data_021759c0->mUnk_2f;
        if (m == 1 || m == 5) {
            if (func_02061f90() == 0) {
                o = data_ov001_021a9b90;
                if (o->mUnk_0c != 0) {
                    o->mUnk_0c -= 1;
                    o = data_ov001_021a9b90;
                    if (o->mUnk_04 != 0) {
                        o->mUnk_04 -= 1;
                        data_ov001_021a9b90->mUnk_06 += 1;
                    }
                    if (data_ov001_021a9b90->mUnk_20 != 0) {
                        data_ov001_021a9b90->mUnk_20();
                    }
                    data_ov001_021a9b90->mUnk_0e = 0;
                } else if (o->mUnk_0a != 0) {
                    o->mUnk_0a -= 1;
                    o = data_ov001_021a9b90;
                    if (o->mUnk_04 != 0) {
                        o->mUnk_04 -= 1;
                    }
                    if (data_ov001_021a9b90->mUnk_1c != 0) {
                        data_ov001_021a9b90->mUnk_1c();
                    }
                    data_ov001_021a9b90->mUnk_0e = 0;
                } else if (o->mUnk_08 != 0) {
                    o->mUnk_08 -= 1;
                    func_ov001_02181aa0();
                    if (data_ov001_021a9b90->mUnk_18 != 0) {
                        data_ov001_021a9b90->mUnk_18();
                    }
                }
            }
            o = data_ov001_021a9b90;
            if (o->mUnk_0e != 0) {
                o->mUnk_0e -= 1;
                o = data_ov001_021a9b90;
                if (o->mUnk_0e == 0) {
                    if (o->mUnk_24 != 0) {
                        o->mUnk_24();
                    }
                }
            }
        }
    }
}

void func_ov001_02181844(u16 param_1, u16 param_2, u16 param_3, u16 param_4) {
    data_ov001_021a9b90->mUnk_10 = param_1;
    data_ov001_021a9b90->mUnk_12 = param_2;
    data_ov001_021a9b90->mUnk_14 = param_3;
    data_ov001_021a9b90->mUnk_16 = param_4;
}
