#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0212c6ac.h"
#include "code_0212df7c.h"

static inline u16 func_020a12b8_inline(s32 i) {
    s32 j;

    for (j = 0; j < 8; j++) {
        if ((u16) i == data_0217b1fc->mUnk_000[j].mUnk_48) {
            return (u16) j;
        }
    }
    return 0;
}

void func_020a16d0(u16 a) {
    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return;
    }
    if (data_0217b1fc->mUnk_000[a].mUnk_08 != 0) {
        return;
    }
    func_020a1904(a);
    func_020a1790();
}

u16 func_020a1520(void) {
    Unk0212c400 **h;
    s32 v;
    u16 k;
    s32 i;
    s32 m;
    s32 n;
    s32 a;

    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return 0;
    }
    v = data_0217b1fc->mUnk_3a4 + 1;
    if (v >= 3) {
        v = 3;
    }
    data_0217b1fc->mUnk_3a4 = v;
    data_0217b1fc->mUnk_3a2 = data_021565f0[data_0217b1fc->mUnk_3a4];
    a = data_0217b1fc->mUnk_3b0;
    if (a != data_0217b1fc->mUnk_3ac) {
        n = data_021759c0->mUnk_3d0;
        for (m = 0; m <= a; m++) {
            for (i = n - 1; i >= 0; i--) {
                k = func_020a12b8_inline(i);
                if (m == data_0217b1fc->mUnk_000[k].mUnk_4c) {
                    func_020a1904(k);
                }
            }
            func_020a1790();
            if (data_0217b1fc->mUnk_3b4 >= 0) {
                return 0;
            }
        }
    }
    if (data_0217c780 & 1) {
        h = (Unk0212c400 **) func_0210e128((void *) func_02108ea0(0));
        if (data_0217d084.mUnk_0c != 0) {
            if (h[0] != 0) {
                func_0212c6f0(h, 0);
            }
            if (h[0] != 0) {
                func_0212c6f0(h, 0);
            }
            func_0212ecc0(h, 0, 0x4b);
        }
    }
    return data_0217b1fc->mUnk_3a2;
}

void func_020a12b8(void) {
    s32 n;
    s32 i;
    u16 k;
    s32 m;
    u16 s;
    Unk020f41c4_B *r;

    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return;
    }
    if (data_021759c0->mUnk_08 == 2) {
        n = data_021759c0->mUnk_3d0;
        if (data_021759c0->mUnk_18 == 0) {
            if (data_0217b1fc->mUnk_3b4 >= 0) {
                return;
            }
            s = (u16) n;
            do {
                r = &data_0217561c->mUnk_47c;
                if ((u16) n == 0) {
                    m = 0;
                } else {
                    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
                    if (s == 0) {
                        m = (u32) (r->mUnk_00 >> 32);
                    } else {
                        m = (u32) (((u64) (u32) (r->mUnk_00 >> 32) * (u64) s) >> 32);
                    }
                }
                k = (u16) m;
                if (data_0217b1fc->mUnk_000[k].mUnk_08 == 0) {
                    func_020a16d0(k);
                    data_0217b1fc->mUnk_000[k].mUnk_08 = 2;
                }
            } while (data_0217b1fc->mUnk_3b4 < 0);
        } else if (data_021759c0->mUnk_18 == 1) {
            for (i = n - 1; i >= 0; i--) {
                if (data_0217b1fc->mUnk_3b4 < 0) {
                    k = func_020a12b8_inline(i);
                    if (data_0217b1fc->mUnk_000[k].mUnk_08 == 0) {
                        func_020a16d0(k);
                        data_0217b1fc->mUnk_000[k].mUnk_08 = 2;
                    }
                }
            }
        }
    } else if (data_021759c0->mUnk_08 == 4) {
        for (i = 7; i >= 0; i--) {
            k = func_020a12b8_inline(i);
            if (k != data_021759c0->mUnk_62 && data_0217b1fc->mUnk_3b4 < 0) {
                func_020a16d0(k);
            }
        }
    }
}
