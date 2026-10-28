#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/unk_0217b000.h"

void func_020a21bc(s32 a, s32 b) {
    if (b == 0) {
        return;
    }
    if (data_0217b1fc->mUnk_39c != 0) {
        data_0217b1fc->mUnk_39c(a, b);
    }
}

s32 func_020a1ee4(s32 a, s32 b) {
    Unk0206bcb0 *v1;
    Unk0206bcb0 *v2;
    Unk0217b1fc_000 *v3;
    Unk0217b1fc_000 *v4;
    s32 f5;
    s32 f4;
    s32 f11;
    s32 t;

    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return 0;
    }
    v1 = func_0207a974(a);
    v2 = func_0207a974(b);
    v4 = &data_0217b1fc->mUnk_000[b];
    v3 = &data_0217b1fc->mUnk_000[a];
    f5 = 0;
    if (v4->mUnk_24[a] == 0) {
        if ((v1->mUnk_48 & 0x100000) != 0) {
            f5 = 1;
        }
    }
    f4 = 0;
    if (v3->mUnk_24[b] == 0) {
        if ((v2->mUnk_48 & 0x100000) != 0) {
            f4 = 1;
        }
    }
    f11 = 1;
    if ((v1->mUnk_4c & 0x400000) == 0) {
        if (func_0207a8a4(a) != 1) {
            f11 = 0;
        }
    }
    t = 1;
    if ((v2->mUnk_4c & 0x400000) == 0) {
        if (func_0207a8a4(b) != 1) {
            t = 0;
        }
    }
    if (f4 != 0) {
        v3->mUnk_24[b] = 1;
    }
    if (f5 != 0) {
        v4->mUnk_24[a] = 1;
    }
    if (f11 == 0 && t == 0 && f5 != 0 && f4 != 0) {
        if (data_0217b1fc->mUnk_384 != 0) {
            data_0217b1fc->mUnk_384(a, b);
            return 1;
        }
    } else if (f11 == 0 && f4 != 0) {
        f4 = 0;
        if (func_0207a8a4(b) == 1) {
            v3->mUnk_20 = 1;
            if (data_0217b1fc->mUnk_380 != 0) {
                f4 = data_0217b1fc->mUnk_380(a, b);
                if ((v1->mUnk_4c & 0x400000) == 0) {
                    func_0206c17c(v1);
                }
            }
        } else if (data_0217b1fc->mUnk_380 != 0) {
            f4 = data_0217b1fc->mUnk_380(a, b);
            if ((v1->mUnk_4c & 0x400000) == 0) {
                func_0206c17c(v1);
            }
        }
        return f4;
    } else if (t == 0 && f5 != 0) {
        f4 = 0;
        if (func_0207a8a4(a) == 1) {
            v4->mUnk_20 = 1;
            if (data_0217b1fc->mUnk_380 != 0) {
                f4 = data_0217b1fc->mUnk_380(b, a);
                if ((v2->mUnk_4c & 0x400000) == 0) {
                    func_0206c17c(v2);
                }
            }
        } else if (data_0217b1fc->mUnk_380 != 0) {
            f4 = data_0217b1fc->mUnk_380(b, a);
            if ((v2->mUnk_4c & 0x400000) == 0) {
                func_0206c17c(v2);
            }
        }
        return f4;
    }
    return 0;
}

void func_020a1e40(s32 a, Unk020f41c4_A *p) {
    u16 v;

    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return;
    }
    if (func_0207a974(a)->mUnk_180 == 0) {
        return;
    }
    if (p->mUnk_44 != 0 && p->mUnk_44 != 1 && p->mUnk_44 != 9) {
        return;
    }
    v = p->mUnk_78;
    if ((v & 0x8000) != 0) {
        return;
    }
    data_0217b1fc->mUnk_000[a].mUnk_44 = v & ~0xff00;
}
