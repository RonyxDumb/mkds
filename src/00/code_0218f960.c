#include "00/code_0218f960.h"

u32 func_ov000_0218f960(Unk0218f960 *p, u32 b) {
    Unk0218f960_00 *o;
    Unk02194934 *e;
    s32 n;

    o = p->mUnk_00;
    if (func_ov000_02194934(p, b, &e) == 0) {
        func_ov000_02196590(p, data_ov000_021b273c);
        return 2;
    }
    func_ov000_02190b80(p, o->mUnk_1f4, data_ov000_021b2750);
    func_ov000_02190b80(p, o->mUnk_1f4, data_ov000_021b275c);
    func_ov000_02190b58(p, o->mUnk_1f4, o->mUnk_198);
    func_ov000_02190b80(p, o->mUnk_1f4, data_ov000_021b2768);
    func_ov000_02190b58(p, o->mUnk_1f4, e->mUnk_00);
    func_ov000_02190b80(p, o->mUnk_1f4, data_ov000_021b2778);
    if (e->mUnk_08 != 0) {
        n = e->mUnk_08->mUnk_00;
        if (n < 0) {
            func_0213442c(data_ov000_021b2780, data_ov000_021b278c, 0, 0x1fd);
        }
        func_ov000_021a3668(e->mUnk_08->mUnk_08);
        e->mUnk_08->mUnk_08 = 0;
        func_ov000_021a3668(e->mUnk_08->mUnk_0c);
        e->mUnk_08->mUnk_0c = 0;
        func_ov000_021a3668(e->mUnk_08);
        e->mUnk_08 = 0;
        if (func_ov000_021947e4(e) != 0) {
            func_ov000_021948f8(p, e);
        }
        o->mUnk_430--;
        if (o->mUnk_430 < 0) {
            func_0213442c(data_ov000_021b2798, data_ov000_021b278c, 0, 0x204);
        }
        func_ov000_02194840(p, func_ov000_0218fa98, n);
    }
    return 0;
}
