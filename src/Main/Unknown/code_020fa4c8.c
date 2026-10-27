#include "Main/Unknown/code_020fa4c8.h"

#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_01fff000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020fc000.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_01ffc000.h"
#include "Main/Unknown/code_01ffd000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_0208e000.h"
#include "Main/Unknown/code_0208eb10.h"
#include "Main/Unknown/code_0208ec64.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_020f81c0.h"
#include "Main/Unknown/code_020f830c.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020f9334.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020fc2c0.h"
#include "Main/Unknown/code_020fcb9c.h"
#include "Main/Unknown/code_020fcedc.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_020ff000.h"
#include "Main/Unknown/code_02103890.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210e000.h"
#include "code_0212c6ac.h"
#include "code_0212df7c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020f2000.h"
#include "Main/Unknown/code_020fa000.h"

#pragma thumb off

void func_020fc268(Unk020fc2e8 *param_1) {
    func_020f2228((Unk0206bcb0 *) param_1, 0xd000);
    if (param_1->mUnk_000.mUnk_74 & 1) {
        return;
    }
    func_0210b7ec((u32) &param_1->mUnk_300, param_1->mUnk_000.mUnk_d4 & ~0xc000001f);
    if (param_1->mUnk_270 == 1) {
        return;
    }
    func_02109078(&param_1->mUnk_000.mUnk_00, param_1->mUnk_270, 0x7f, 0);
}

// non-matching: the whole body is laid out differently; left as a translation of the
// disassembly.
void func_020fbd98(Unk020fc2e8 *param_1) {
    s32 i;
    s32 r;
    s32 v;
    void *q;

    if (param_1->mUnk_2ec == 8) {
        param_1->mUnk_26c = func_0208ec64((u32) param_1->mUnk_000.mUnk_d0);
    }
    func_020ec918((Unk020ec8bc *) param_1, param_1->mUnk_27c, 0x21, param_1->mUnk_276, 1);
    if (!(param_1->mUnk_000.mUnk_74 & 1)) {
        func_0210b7ec((u32) &param_1->mUnk_300, param_1->mUnk_000.mUnk_d4 & ~0xc000001f);
        if (param_1->mUnk_270 != 1) {
            func_02109078(&param_1->mUnk_000.mUnk_00, param_1->mUnk_270, 0x7f, 0);
        }
    }
    param_1->mUnk_000.mUnk_5c.y -= (s32) (((s64) * (s32 *) param_1->mUnk_12c * 0x66) >> 12);
    if (param_1->mUnk_000.mUnk_74 & 1) {
        return;
    }
    func_020fc654(param_1);
    q = 0;
    if (param_1->mUnk_2f6 >= 3) {
        if (param_1->mUnk_228->mUnk_1fc->mUnk_48 & 1) {
            q = &param_1->mUnk_228->mUnk_1fc->mUnk_244;
        }
    } else if (param_1->mUnk_000.mUnk_74 & 0x40000000) {
        q = &param_1->mUnk_000.mUnk_f0;
    }
    func_020fc2e8(param_1, &param_1->mUnk_000.mUnk_5c, 1, q);
    if (param_1->mUnk_278 == 0) {
        if (data_0217561c->mUnk_4cc != 0) {
            param_1->mUnk_274 = 1;
            param_1->mUnk_276 = data_0217561c->mUnk_474[(u8) param_1->mUnk_274 - 1];
        } else {
            param_1->mUnk_276 = data_0217561c->mUnk_474[(u8) param_1->mUnk_274 - 1];
            while (func_0203c880(param_1->mUnk_276) != 0 && param_1->mUnk_274 < (u8) data_021759c0->mUnk_3d0) {
                (param_1->mUnk_274)++;
                param_1->mUnk_276 = data_0217561c->mUnk_474[(u8) param_1->mUnk_274 - 1];
            }
        }
        if (param_1->mUnk_276 == (u16) ((param_1->mUnk_000.mUnk_78 & 0x8000) ? 8 : (u8) param_1->mUnk_000.mUnk_78) ||
            func_02068eac((s32) func_0207a974(param_1->mUnk_276)) != 0) {
            param_1->mUnk_278 = 1;
        } else {
            param_1->mUnk_280 |= 1 << param_1->mUnk_276;
        }
    }
    if (param_1->mUnk_278 != 0) {
        u16 n;
        n = (u8) data_021759c0->mUnk_3d0;
        for (i = 1; i < n; i++) {
            param_1->mUnk_276 = data_0217561c->mUnk_474[(u8) i - 1];
            if (func_02068eac((s32) func_0207a974(param_1->mUnk_276)) == 0) {
                break;
            }
        }
        param_1->mUnk_280 |= 1 << param_1->mUnk_276;
    }
    if (func_020fcbb8(param_1, param_1->mUnk_276) != 0) {
        r = ((param_1->mUnk_000.mUnk_74 & 0x40000000) || (param_1->mUnk_228->mUnk_1fc->mUnk_48 & 1)) ? 2 : 3;
        param_1->mUnk_2f8 = r;
        param_1->mUnk_2fa = 1;
        if (param_1->mUnk_000.mUnk_74 & 0x8000000) {
            func_020fe71c(5, param_1->mUnk_228->mUnk_1f8, param_1->mUnk_000.mUnk_4e);
        }
        return;
    }
    r = (u16) func_02061f90();
    if ((param_1->mUnk_280 & (1 << r)) != 0 && param_1->mUnk_276 != r && func_0203c880(r) != 0 &&
        func_020fcbb8(param_1, r) != 0) {
        v = ((param_1->mUnk_000.mUnk_74 & 0x40000000) || (param_1->mUnk_228->mUnk_1fc->mUnk_48 & 1)) ? 2 : 3;
        param_1->mUnk_2f8 = v;
        param_1->mUnk_2fa = 1;
        if (param_1->mUnk_000.mUnk_74 & 0x8000000) {
            func_020fe71c(5, param_1->mUnk_228->mUnk_1f8, param_1->mUnk_000.mUnk_4e);
        }
        return;
    }
    if (param_1->mUnk_2ec <= 0xa8c) {
        return;
    }
    v = (u16) data_0217561c->mUnk_474[0];
    if (param_1->mUnk_228 != 0) {
        return;
    }
    if (v >= 8) {
        v = 0;
    }
    func_020fcb9c((int) param_1, v);
    r = ((param_1->mUnk_000.mUnk_74 & 0x40000000) || (param_1->mUnk_228->mUnk_1fc->mUnk_48 & 1)) ? 2 : 3;
    param_1->mUnk_2f8 = r;
    param_1->mUnk_2fa = 1;
}

void func_020fbd4c(Unk020fc2e8 *param_1) {
    param_1->mUnk_27c = func_021482cc(&param_1->mUnk_000.mUnk_5c);
    param_1->mUnk_284 = 0x1e000;
    if (param_1->mUnk_228->mUnk_1f8 == data_021759c0->mUnk_62) {
        param_1->mUnk_270 = 0xdd;
    }
}

// non-matching: 0x12c vs 0x134 bytes. The original loads param_1->mUnk_228 (`ldr r1, [r4, #0x228]`)
// before the test of mUnk_74 and `ldr r2, [r1, #0x1fc]` right after it; here both loads are
// inside the taken branch. At the end of the selection of the fourth argument the original
// reaches one `mov r3, #0` from both failed tests (`beq` / `bne`); here `mov r3, #0` comes first
// and the two selections are predicated (`addne`).
void func_020fbc18(Unk020fc2e8 *param_1) {
    s32 r;
    void *q;

    r = 0x800;
    if ((param_1->mUnk_000.mUnk_74 & 0x10000000) && (param_1->mUnk_228->mUnk_1fc->mUnk_7c & 1)) {
        r += 0x19a;
    }
    if (param_1->mUnk_27c > 0xd000) {
        param_1->mUnk_27c -= 0xccd;
    } else {
        param_1->mUnk_27c += 0xccd;
    }
    func_020fcedc((u32) param_1, r, param_1->mUnk_27c, param_1->mUnk_284);
    if (!(param_1->mUnk_000.mUnk_74 & 1)) {
        func_0210b7ec((u32) &param_1->mUnk_300, param_1->mUnk_000.mUnk_d4 & ~0xc000001f);
        if (param_1->mUnk_270 != 1) {
            func_02109078(&param_1->mUnk_000.mUnk_00, param_1->mUnk_270, 0x7f, 0);
        }
    }
    if ((s64) param_1->mUnk_238.x * param_1->mUnk_238.x + (s64) param_1->mUnk_238.z * param_1->mUnk_238.z < 0x19) {
        param_1->mUnk_2f8 = 4;
        param_1->mUnk_2fa = 1;
    }
    func_020fc654(param_1);
    q = 0;
    if (param_1->mUnk_2f6 >= 3) {
        if (param_1->mUnk_228->mUnk_1fc->mUnk_48 & 1) {
            q = &param_1->mUnk_228->mUnk_1fc->mUnk_244;
        }
    } else if (param_1->mUnk_000.mUnk_74 & 0x40000000) {
        q = &param_1->mUnk_000.mUnk_f0;
    }
    func_020fc2e8(param_1, &param_1->mUnk_000.mUnk_5c, 1, q);
}

// non-matching: 0x130 vs 0x138 bytes. The selection of the fourth argument of func_020fc2e8 is laid
// out as in func_020fbc18: the original reaches one shared `mov r3, #0` with `beq` / `bne`, this
// build starts with `mov r3, #0` and predicates the two selections. The loop after the call
// matches instruction for instruction.
void func_020fbae0(Unk020fc2e8 *param_1) {
    s32 i;
    void *q;
    Unk020f371c *p;

    if (param_1->mUnk_27c > 0xd000) {
        param_1->mUnk_27c -= 0xccd;
    } else {
        param_1->mUnk_27c += 0xccd;
    }
    func_020ec918((Unk020ec8bc *) param_1, param_1->mUnk_27c, 0x21, param_1->mUnk_276, 1);
    if (!(param_1->mUnk_000.mUnk_74 & 1)) {
        func_0210b7ec((u32) &param_1->mUnk_300, param_1->mUnk_000.mUnk_d4 & ~0xc000001f);
        if (param_1->mUnk_270 != 1) {
            func_02109078(&param_1->mUnk_000.mUnk_00, param_1->mUnk_270, 0x7f, 0);
        }
    }
    if (param_1->mUnk_000.mUnk_74 & 1) {
        return;
    }
    func_020fc654(param_1);
    q = 0;
    if (param_1->mUnk_2f6 >= 3) {
        if (param_1->mUnk_228->mUnk_1fc->mUnk_48 & 1) {
            q = &param_1->mUnk_228->mUnk_1fc->mUnk_244;
        }
    } else if (param_1->mUnk_000.mUnk_74 & 0x40000000) {
        q = &param_1->mUnk_000.mUnk_f0;
    }
    func_020fc2e8(param_1, &param_1->mUnk_000.mUnk_5c, 1, q);
    p = param_1->mUnk_228->mUnk_1f0;
    for (i = 0; i < 4; i++) {
        if (p == param_1->mUnk_168) {
            param_1->mUnk_2f8 = 3;
            param_1->mUnk_2fa = 1;
        }
        p = p->mUnk_00[0];
    }
}

void func_020fba6c(Unk020fc2e8 *param_1) {
    param_1->mUnk_264 = 0x5000;
    param_1->mUnk_288 = 0x3e8;
    func_021484d0(&param_1->mUnk_238, &param_1->mUnk_298, &param_1->mUnk_28c);
    if (param_1->mUnk_26c != 0) {
        func_0208eb10(param_1->mUnk_26c);
        param_1->mUnk_26c = 0;
    }
    if (param_1->mUnk_000.mUnk_74 & 0x8000000) {
        func_020fe71c(5, param_1->mUnk_228->mUnk_1f8, param_1->mUnk_000.mUnk_4e);
    }
}

// non-matching: 0x26c vs 0x274 bytes. The selection of q is laid out as in func_020fbc18: the
// original reaches one shared `mov r4, #0` with `beq` / `bne`, this build starts with
// `mov r4, #0` and predicates the two selections.
void func_020fb7f8(Unk020fc2e8 *param_1) {
    Vec3 v;
    void *q;

    if (param_1->mUnk_27c > 0xd000) {
        param_1->mUnk_27c -= 0xccd;
    } else {
        param_1->mUnk_27c += 0xccd;
    }
    param_1->mUnk_260 -= 0xccd;
    param_1->mUnk_288 += 0x2d;
    if ((u32) param_1->mUnk_25c < 0x8000) {
        param_1->mUnk_284 -= 0x666;
    } else {
        param_1->mUnk_284 -= 0xccd;
    }
    func_020fce94(param_1, 0x4cd, param_1->mUnk_27c, param_1->mUnk_284, param_1->mUnk_288);
    if (!(param_1->mUnk_000.mUnk_74 & 1)) {
        func_0210b7ec((u32) &param_1->mUnk_300, param_1->mUnk_000.mUnk_d4 & ~0xc000001f);
        if (param_1->mUnk_270 != 1) {
            func_02109078(&param_1->mUnk_000.mUnk_00, param_1->mUnk_270, 0x7f, 0);
        }
    }
    func_020fc654(param_1);
    if ((u32) param_1->mUnk_25c < 0x11f40) {
        q = 0;
        if (param_1->mUnk_2f6 >= 3) {
            if (param_1->mUnk_228->mUnk_1fc->mUnk_48 & 1) {
                q = &param_1->mUnk_228->mUnk_1fc->mUnk_244;
            }
        } else if (param_1->mUnk_000.mUnk_74 & 0x40000000) {
            q = &param_1->mUnk_000.mUnk_f0;
        }
        if (q != 0) {
            v.x = param_1->mUnk_250.x * 2;
            v.y = param_1->mUnk_250.y * 2;
            v.z = param_1->mUnk_250.z * 2;
            func_020397a8(q, &v, &v);
            func_02147fd8((s32) (((s64) (param_1->mUnk_25c - 0x10000) * 0xccd) >> 12), q, &v, &v);
        } else {
            v.x = (s32) (((s64) param_1->mUnk_250.z * 0x2000) >> 12);
            v.y = (s32) (((s64) (param_1->mUnk_25c - 0x10000) * 0xccd) >> 12);
            v.z = -(s32) (((s64) param_1->mUnk_250.x * 0x2000) >> 12);
        }
        if (param_1->mUnk_2ec == 0) {
            func_021484d0(&v, &param_1->mUnk_298, &param_1->mUnk_28c);
        }
        func_020fc2e8(param_1, &v, 1, q);
        return;
    }
    param_1->mUnk_2f8 = 5;
    param_1->mUnk_2fa = 1;
}

// non-matching: 3 words from +0x34: the original emits `ldr r2, [r3, #0x44]; ldr r1, [r0];
// mla r0, r2, r0, r1`, this build `ldr r1, [r3, #0x44]; ldr r2, [r0]; mla r0, r1, r0, r2`.
void func_020fb770(Unk020fc2e8 *param_1) {
    if (param_1->mUnk_000.mUnk_d0 == &param_1->mUnk_000.mUnk_0c4) {
        param_1->mUnk_000.mUnk_50 = param_1->mUnk_000.mUnk_0c4;
        param_1->mUnk_000.mUnk_d0 = &param_1->mUnk_000.mUnk_50;
    }
    param_1->mUnk_260 = 0x28000;
    param_1->mUnk_264 = 0x333;
    param_1->mUnk_000.mUnk_100 = data_0217bc34[param_1->mUnk_000.mUnk_44].mUnk_74;
    param_1->mUnk_000.mUnk_74 |= 0x800000;
    param_1->mUnk_2a4 = param_1->mUnk_28c;
    param_1->mUnk_27c = 0x3000;
    param_1->mUnk_284 = 0x59a;
}

// non-matching: 0x14c vs 0x154 bytes. The original keeps param_1 in r4 (here r5); the selection
// of q is laid out as in func_020fbc18 (one shared `mov rN, #0` reached by `beq` / `bne` in the
// original, `mov r4, #0` first and predicated selections here).
void func_020fb61c(Unk020fc2e8 *param_1) {
    Vec3 v;
    Vec3 *q;

    param_1->mUnk_260 += 0x4cd;
    func_020fcce4(param_1, param_1->mUnk_264, param_1->mUnk_260);
    if ((s32) param_1->mUnk_264 < 0xb33) {
        param_1->mUnk_264 += 0x52;
    }
    if (param_1->mUnk_260 > 0x2d000) {
        param_1->mUnk_2f8 = 6;
        param_1->mUnk_2fa = 1;
    }
    param_1->mUnk_27c -= 0xa14;
    param_1->mUnk_284 -= 0x102;
    if (param_1->mUnk_284 < 0x7b) {
        param_1->mUnk_284 = 0x7b;
    }
    q = 0;
    if (param_1->mUnk_2f6 >= 3) {
        if (param_1->mUnk_228->mUnk_1fc->mUnk_48 & 1) {
            q = &param_1->mUnk_228->mUnk_1fc->mUnk_244;
        }
    } else if (param_1->mUnk_000.mUnk_74 & 0x40000000) {
        q = &param_1->mUnk_000.mUnk_f0;
    }
    if (q != 0) {
        func_02147fd8(param_1->mUnk_27c, q, &param_1->mUnk_22c, &v);
    } else {
        v.x = param_1->mUnk_22c.x;
        v.y = param_1->mUnk_27c;
        v.z = param_1->mUnk_22c.z;
    }
    func_021484d0(&v, &param_1->mUnk_2a4, &v);
    func_02147fd8(param_1->mUnk_284, &v, &param_1->mUnk_2a4, &param_1->mUnk_2a4);
    func_020fc2e8(param_1, &param_1->mUnk_2a4, 0, q);
}

// non-matching: 3 words from +0xc: the original emits `ldr r3, [r0, #0x44]; ldr r2, [r1];
// mla r1, r3, r1, r2`, this build `ldr r2, [r0, #0x44]; ldr r3, [r1]; mla r1, r2, r1, r3`.
void func_020fb5dc(Unk020fc2e8 *param_1) {
    param_1->mUnk_260 = 0x28000;
    param_1->mUnk_000.mUnk_100 = data_0217bc34[param_1->mUnk_000.mUnk_44].mUnk_74;
    param_1->mUnk_000.mUnk_100 += 0x800;
    func_020f9c6c(&param_1->mUnk_000);
}

void func_020fb46c(Unk020fc2e8 *param_1) {
    s32 r;
    Vec3 v;

    param_1->mUnk_260 -= 0x7000;
    func_020fcce4(param_1, 0xb33, param_1->mUnk_260);
    if (param_1->mUnk_260 < -0x32000) {
        func_020f7104(&param_1->mUnk_000, 0);
        if (param_1->mUnk_000.mUnk_74 & 0x8000000) {
            func_020fe71c(5, param_1->mUnk_228->mUnk_1f8, param_1->mUnk_000.mUnk_4e);
        }
    } else {
        Vec3 *pv;

        pv = &param_1->mUnk_000.mUnk_50;
        if (func_01ffdee4((int *) pv, (u32 *) &param_1->mUnk_000.mUnk_0e4, 0, param_1->mUnk_000.mUnk_dc, 4,
                          param_1->mUnk_000.mUnk_da, (int *) &v, 0, 0, (u32 *) &param_1->mUnk_000.mUnk_fc, 0, 0, 0,
                          0) != 0) {
            func_02148504(&v, pv, pv);
            func_020f7104(&param_1->mUnk_000, 0);
            if (param_1->mUnk_000.mUnk_74 & 0x8000000) {
                func_020fe71c(5, param_1->mUnk_228->mUnk_1f8, param_1->mUnk_000.mUnk_4e);
            }
        }
    }
    r = func_020fa0b8(param_1, data_0217bc34[param_1->mUnk_000.mUnk_44].mUnk_74,
                      data_0217bc34[param_1->mUnk_000.mUnk_44].mUnk_78);
    if (func_020f9ce8(&param_1->mUnk_000) != 0) {
        return;
    }
    if (r) {
        func_020fa030(&param_1->mUnk_000);
    }
}

// non-matching: 0x11c vs 0x110 bytes. After storing the value of func_0208e490 at 0x2b0 the
// original reloads it into r1, tests it and writes the three words with predicated stores
// (`strne r0, [r1, #0x9c]; addne r1, r1, #0x9c; strne r0, [r1, #4]; strne r0, [r1, #8]`); this
// build branches on the test and reloads the pointer before each of the three stores.
void func_020fb35c(Unk020fc2e8 *param_1) {
    Unk0212c400 **p;

    param_1->mUnk_000.mUnk_74 |= 0x800000;
    param_1->mUnk_000.mUnk_100 = 0;
    *(Vec3 *) &param_1->mUnk_000.mUnk_68 = data_02159d84;
    param_1->mUnk_2b0 = func_0208e490(1, &param_1->mUnk_000.mUnk_50, func_020f9160(&param_1->mUnk_000) == 0 ? 1 : 0);
    if (param_1->mUnk_2b0 != 0) {
        param_1->mUnk_2b0->mUnk_9c[0] = 0x1000;
        param_1->mUnk_2b0->mUnk_9c[1] = 0x1000;
        param_1->mUnk_2b0->mUnk_9c[2] = 0x1000;
    }
    func_020f91fc(param_1, 0xdf);
    if (*(u32 *) data_0217c780 & 1) {
        p = func_0210e128((void *) func_02108ea0(0));
        if (data_0217d084.mUnk_0c != 0) {
            if (*p != 0) {
                func_0212c6f0(p, 0);
            }
            if (*p != 0) {
                func_0212c6f0(p, 0);
            }
            func_0212ecc0(p, 0, 0xe0);
        }
    }
    func_02073fb0(param_1->mUnk_000.mUnk_d4 & ~0xc000001f, 0x1000);
}

void func_020fb2b4(Unk020fc2e8 *param_1) {
    u32 v;

    v = param_1->mUnk_2ec;
    if (func_020fa0b8(param_1, data_0217bd3c, data_0217bd44)) {
        func_020f9fa8(&param_1->mUnk_000);
    }
    if (v < 0x16) {
        return;
    }
    if (v == 0x16) {
        param_1->mUnk_2e4 = 1;
    } else if (v == 0x2a) {
        func_020f9c40((int) param_1);
    }
    if (v <= 0x55) {
        return;
    }
    func_020f0f70(&data_027e00cc[param_1->mUnk_000.mUnk_44], &param_1->mUnk_000);
}

void *func_020fb208(void *param_1, Unk020fc2e8 *param_2, void *param_3) {
    void *r;
    void *t;

    if (param_2 != 0 && param_3 != 0) {
        func_020ff1b8(func_02039828(&param_2->mUnk_000.mUnk_5c, (Vec3 *) &param_2->mUnk_130) < 0 ? 1 : 0,
                      (u32 *) &param_2->mUnk_000.mUnk_5c.y);
    }
    t = func_020fecdc(param_1, param_2, param_3);
    r = func_020ff040(t, param_2 != 0 ? (void *) &param_2->mUnk_21c : 0, param_3);
    if (param_2 != 0 && param_3 == 0) {
        func_020ff1a0(param_2->mUnk_000.mUnk_5c.y, (u32 *) &param_2->mUnk_2fc);
    }
    if (param_2 != 0 && param_3 != 0) {
        return func_020fe8ac(param_2->mUnk_000.mUnk_44);
    }
    return r;
}

void func_020fb038(Unk020fc2e8 *param_1) {
    s32 v;
    Unk020fb038 s;
    Unk0206bcb0 *q;
    s32 r;

    func_020f8e78(param_1);
    if (param_1->mUnk_21c != 0) {
        func_020ec8bc((Unk020ec8bc *) param_1, 0x14, 0xcc, 1, 0, param_1->mUnk_2fc, (u16) data_0217561c->mUnk_474[0],
                      1);
        func_02046bcc(&param_1->mUnk_2e8, 1);
    } else if (param_1->mUnk_000.mUnk_74 & 0x8000000) {
        v = (u16) data_0217561c->mUnk_474[0];
        if (param_1->mUnk_228 == 0) {
            func_020fcb9c((int) param_1, v);
            q = param_1->mUnk_228->mUnk_1fc;
            r = ((param_1->mUnk_000.mUnk_74 & 0x40000000) || (q->mUnk_48 & 1)) ? 2 : 3;
            param_1->mUnk_2f8 = r;
            param_1->mUnk_2fa = 1;
        }
    } else {
        v = (u16) data_0217561c->mUnk_474[0];
        func_020fcb9c((int) param_1, v);
        q = param_1->mUnk_228->mUnk_1fc;
        r = ((param_1->mUnk_000.mUnk_74 & 0x40000000) || (q->mUnk_48 & 1)) ? 2 : 3;
        param_1->mUnk_2f8 = r;
        param_1->mUnk_2fa = 1;
        if (param_1->mUnk_000.mUnk_74 & 0x8000000) {
            func_020fe71c(5, param_1->mUnk_228->mUnk_1f8, param_1->mUnk_000.mUnk_4e);
        }
    }
    func_020fc94c(param_1);
    if ((s64) param_1->mUnk_000.mUnk_5c.x * param_1->mUnk_000.mUnk_5c.x +
            (s64) param_1->mUnk_000.mUnk_5c.y * param_1->mUnk_000.mUnk_5c.y +
            (s64) param_1->mUnk_000.mUnk_5c.z * param_1->mUnk_000.mUnk_5c.z >=
        0x10) {
        func_02039860(&param_1->mUnk_000.mUnk_5c, &s.mUnk_00);
    }
    func_020d7b88((u32) &s.mUnk_00, (u32 *) &s.mUnk_0c);
    func_01ffccd0((int *) &param_1->mUnk_000.mUnk_94, (u32) &s.mUnk_0c);
}

// non-matching: registers only (0x168 bytes both): the original keeps param_1 in r6, param_2 in r5 and the
// value of mUnk_d8 passed to func_02013468 in r4; this compile uses r5, r4 and r6.
void func_020faed0(Unk020fc2e8 *param_1, s32 param_2, s32 param_3) {
    Vec3 v;
    void *q;

    if (param_1->mUnk_000.mUnk_74 & 0x2000) {
        if (func_020f91c4(&param_1->mUnk_000, 0x6a4) != 0) {
            return;
        }
    }
    v.x = v.z = param_1->mUnk_000.mUnk_68;
    v.y = param_1->mUnk_000.mUnk_6c;
    if (param_1->mUnk_000.mUnk_d8 != 0x1f) {
        u32 i;
        Unk0201290c *o;
        u16 n;

        n = (u16) param_1->mUnk_000.mUnk_d8;
        o = data_0217bd38->mUnk_004;
        for (i = 0; i < o->mUnk_18; i++) {
            func_02013468(o, i, n);
        }
    }
    if (param_1->mUnk_000.mUnk_74 & 0x80000) {
        q = func_020ed98c(&param_1->mUnk_000, (Vec3 *) param_2);
    } else {
        Vec3 *pv;

        pv = param_1->mUnk_000.mUnk_d0;
        param_1->mUnk_000.mUnk_94.mUnk_24.x = pv->x >> 4;
        param_1->mUnk_000.mUnk_94.mUnk_24.y = pv->y >> 4;
        param_1->mUnk_000.mUnk_94.mUnk_24.z = pv->z >> 4;
        q = &param_1->mUnk_000.mUnk_94;
    }
    func_020ea8a8(data_0217bd38, q, &v, 0x1f);
    if (param_1->mUnk_000.mUnk_d8 == 0x1f) {
        return;
    }
    {
        u32 i;
        Unk0201290c *o;

        o = data_0217bd38->mUnk_004;
        for (i = 0; i < o->mUnk_18; i++) {
            func_02013468(o, i, 0x1f);
        }
    }
}

void func_020fae74(Unk020fc2e8 *param_1, s32 param_2, s32 param_3) {
    Unk0208e490 *q;

    if (param_1->mUnk_2f6 != 7) {
        func_020faed0(param_1, param_2, param_3);
        return;
    }
    q = param_1->mUnk_2b0;
    if (q == 0) {
        return;
    }
    q->mUnk_b4 = (param_1->mUnk_000.mUnk_74 & 0x10000) == 0;
}

s32 func_020fade4(Unk020fc2e8 *param_1) {
    if (param_1->mUnk_2f6 != 7) {
        func_02046be8(&param_1->mUnk_2e8, (UnkFunc *const *) data_0216c6b4, 8, param_1);
        param_1->mUnk_2f8 = 7;
        param_1->mUnk_2fa = 1;
        if ((param_1->mUnk_000.mUnk_74 & 0x180000) == 0) {
            param_1->mUnk_000.mUnk_120 = (void (*)(struct Unk020f41c4_A *)) func_020fc2c0;
        }
        param_1->mUnk_000.mUnk_74 &= ~0x8000;
        param_1->mUnk_000.mUnk_74 |= 0x80000;
        func_020f9c6c(&param_1->mUnk_000);
        param_1->mUnk_000.mUnk_78 &= ~0x4000;
    }
    return 1;
}

s32 func_020fadcc(Unk020fc2e8 *param_1) {
    return param_1->mUnk_2f6 == 7;
}

Vec3 *func_020fad9c(Unk020fc2e8 *param_1, s32 *param_2, s32 *param_3) {
    *param_2 = param_1->mUnk_2ec;
    *param_3 = (s32) (((s64) param_1->mUnk_000.mUnk_70 * data_0217bd40) >> 12);
    return &param_1->mUnk_000.mUnk_50;
}

#pragma thumb on

void func_020fad00(void) {
    s32 a;
    s32 b;
    s32 v;

    data_0217bd3c = 0x1e000;
    data_0217bd40 = func_02147f34(0x1000, data_0217bd3c);
    data_0217bd44 = 0x299a;
    a = data_0217bd3c;
    b = data_0217bc34[5].mUnk_6c;
    v = (s32) (((s64) a * b) >> 12);
    data_0217bd34 = v;
    v >>= 12;
    data_0217bd34 = v;
    data_0217bd34 = v * v;
    data_0217bd38 = func_020ed490(data_0216c6f4, data_0216c704);
    if (data_021759c0->mUnk_00 == 0x1d) {
        func_02013044(data_0217bd38->mUnk_004, 0);
    }
}

#pragma thumb off

s32 func_020faca4(s32 param_1) {
    if (param_1 != 0x13) {
        return data_027e00cc[data_0217bc48[param_1].mUnk_08].mUnk_0c -
                   data_027e00cc[data_0217bc48[param_1].mUnk_08].mUnk_1c >=
               data_0217bc48[param_1].mUnk_0c;
    }
    return 0;
}

// non-matching: 0x128 vs 0x170 bytes. The original saves r7 and reserves a stack word
// (`push {r4, r5, r6, r7, lr}; sub sp, sp, #4`); the body of the first branch loads
// `ldr r7, [r0, #12]` before the func_020fa0e8 call and multiplies with it afterwards
// (`mul r0, r7, r0`); this build is laid out differently from the first instruction.
s32 func_020fab34(s32 *param_1) {
    s32 i;
    s32 v;
    Unk0217bc48 *e;

    i = *param_1;
    if (i == 0x13) {
        goto done;
    }
    if (data_021759c0->mUnk_08 == 5) {
        e = &data_0217bc48[i];
        v = e->mUnk_0c * func_020fa0e8(e->mUnk_08, 0);
        e = &data_0217bc48[i];
        if (data_027e00cc[e->mUnk_08].mUnk_0c - data_027e00cc[e->mUnk_08].mUnk_1c < e->mUnk_0c) {
            goto done;
        }
        if (data_0217aa14->mUnk_724 >= v) {
            return 0;
        }
    } else {
        e = &data_0217bc48[i];
        if (data_027e00cc[e->mUnk_08].mUnk_0c - data_027e00cc[e->mUnk_08].mUnk_1c < e->mUnk_0c) {
            return 0;
        }
    }
done:
    *param_1 = data_021759c0->mUnk_08 == 5 ? 4 : 2;
    return 1;
}

// non-matching: 0xc0 vs 0xbc bytes. The original saves r4-r7 (`push {r4, r5, r6, r7, lr}`) and
// forms the second table address with `mul` and `add`; this build saves r4-r9 and uses `mla`
// for both table addresses.
s32 func_020faa78(s32 param_1) {
    Unk0217bc48 *e;
    Unk027e00cc *r;
    s32 n;

    e = &data_0217bc48[param_1];
    r = &data_027e00cc[e->mUnk_08];
    n = e->mUnk_0c;
    while (r->mUnk_0c - r->mUnk_1c < n) {
        if (data_0217bc34[e->mUnk_08].mUnk_04 == 1) {
            return 0;
        }
        if (func_020f03bc(r) == 0) {
            return 0;
        }
        r = &data_027e00cc[e->mUnk_08];
    }
    return 1;
}

// non-matching: 0x9c vs 0x94 bytes. The original tests the counter before the first pass of both
// loops (`cmp r6, #14; bge`) and recomputes the address with `mla` each pass; this build enters
// the loops without the first test and steps a pointer.
void func_020fa9e4(void) {
    s32 i;
    u16 j;

    for (i = 0; i < 0xe; i++) {
        func_020f03bc(&data_027e00cc[(u32) i]);
    }
    if (data_027e00c4 == 0) {
        return;
    }
    for (j = 0; j < data_027e00c4; j++) {
        func_020f0044(&((Unk020ee684 *) *(void **) data_027e00c8)[j]);
    }
}

// non-matching: 0xbc vs 0xc4 bytes. The loops differ as in func_020fa9e4: the original tests the
// counter before the first pass and recomputes the address with `mla` each pass; this build
// steps a byte offset (`add r5, r5, #0x44`).
void func_020fa920(void) {
    s32 i;

    if (data_021759c0->mUnk_08 == 5) {
        func_020fec30();
        func_020feb44();
    }
    for (i = 0; i < 0xe; i++) {
        if (data_027e00cc[i].mUnk_14 != 0) {
            func_020f03f8(&data_027e00cc[i]);
        }
    }
    for (i = 0; i < data_027e00c4; i++) {
        func_01fff694(&((Unk020ee684 *) *(void **) data_027e00c8)[i]);
    }
    func_020f8258();
    func_02104368();
    func_02104ff8();
}

// non-matching: 0x68 vs 0x74 bytes. The loop differs as in func_020fa9e4: the original tests the
// counter before the first pass (`cmp r7, #14`) and recomputes the address with `mla` each pass;
// this build steps a byte offset (`add r5, r5, #0x44`).
void func_020fa8ac(void) {
    s32 i;
    void *q;

    q = &((Unk020e6b38 *) func_020e6b38())->mUnk_18;
    func_020e6a74();
    for (i = 0; i < 0xe; i++) {
        if (data_027e00cc[i].mUnk_10 > 0 && data_027e00cc[i].mUnk_40 == 0) {
            func_020f0df8(&data_027e00cc[i], q);
        }
    }
}

// non-matching: 0x118 vs 0x120 bytes. The original loads the base of the second table into r3
// and the word it reads from the element into r2 (`ldr r3, [r2]; mla r1, r0, r1, r3; ldr r2,
// [r1, #0x70]`); this build keeps the base in r2 and reads into r1.
void func_020fa78c(s32 param_1, s32 param_2, s32 param_3) {
    s32 v;
    s32 c;

    if (((Unk020ee684 *) *(void **) data_027e00c8)[param_1].mUnk_030.mUnk_00 != 0x13) {
        return;
    }
    v = data_021759c0->mUnk_70[param_1].mUnk_00;
    if (v == 3) {
        return;
    }
    if (data_021759c0->mUnk_08 == 2) {
        c = 0;
        if ((u32) v <= 3) {
            if ((1 << v) & 0xd) {
                c = 1;
            }
        }
        func_020f87a8(&((Unk020ee684 *) *(void **) data_027e00c8)[param_1], param_2, func_020a1cd8(param_1), c != 0,
                      param_3);
    } else {
        c = 0;
        if ((u32) v <= 3) {
            if ((1 << v) & 0xd) {
                c = 1;
            }
        }
        func_020f87a8(&((Unk020ee684 *) *(void **) data_027e00c8)[param_1], param_2, func_0203c8dc(param_1), c != 0,
                      param_3);
    }
}

// non-matching: 0x2dc vs 0x2c4 bytes. The original reserves 0x2c bytes of stack (here 0x34) and
// keeps param_1 in r9 (here sl); the bit 0x8000000 value is formed with `movne r8, #1` /
// `moveq r8, r6` (here `movne r0, #1; strne r0, [sp]; streq r8, [sp]`), so the rest of the
// register assignment differs.
s32 func_020fa4c8(Unk0206bcb0 *param_1) {
    s32 n;
    s32 i;
    s32 fl;
    s32 v;
    s32 t;
    s32 u0;
    s32 u1;
    s32 u2;
    s32 lim;
    s32 d1;
    s32 d2;
    Unk020f41c4_A *e;
    Vec3 va;
    Vec3 vb;

    n = 0;
    fl = (param_1->mUnk_48 & 0x8000000) != 0;
    u0 = 0;
    u2 = 0;
    u1 = 0;
    lim = 0xf;
    for (i = 0; i < data_0217b5a8; i++) {
        if (!(data_0217b5bc[i] & 0x4000)) {
            continue;
        }
        e = data_0217b5c4[i];
        if (fl && !(e->mUnk_74 & 0x200000)) {
            continue;
        }
        if (!func_020f97e0(e, param_1)) {
            continue;
        }
        v = 1;
        if (e->mUnk_74 & 0x8000) {
            if ((u16) param_1->mUnk_74 != (u16) ((e->mUnk_78 & 0x8000) ? 8 : (u8) e->mUnk_78)) {
                v = 1;
            } else {
                t = 1;
                if (e->mUnk_5c.x != 0 || e->mUnk_5c.y != 0 || e->mUnk_5c.z != 0 || param_1->mUnk_2a8 != 0) {
                    func_021484d0(&e->mUnk_0e4, &param_1->mUnk_1e4, &va);
                    va.y = u0;
                    func_021484d0(&e->mUnk_50, &param_1->mUnk_1d8, &vb);
                    vb.y = u1;
                    d1 = func_02039828(&va, &va);
                    d2 = func_02039828(&vb, &vb);
                    if (d1 - 0x1000 > d2) {
                        v = 1;
                        t = 0;
                    }
                }
                if (t) {
                    s64 dd;
                    dd = (s64) (e->mUnk_50.x - param_1->mUnk_1d8.x) * (e->mUnk_50.x - param_1->mUnk_1d8.x) +
                         (s64) (e->mUnk_50.y - param_1->mUnk_1d8.y) * (e->mUnk_50.y - param_1->mUnk_1d8.y) +
                         (s64) (e->mUnk_50.z - param_1->mUnk_1d8.z) * (e->mUnk_50.z - param_1->mUnk_1d8.z);
                    v = dd - (s64) e->mUnk_e0 * e->mUnk_e0 < 0 ? 1 : u2;
                }
            }
        }
        if (v == 0) {
            continue;
        }
        if ((param_1->mUnk_7c & 0x2000) && func_020f9880(e) != 0) {
            continue;
        }
        data_0217bd30[n++] = e;
        if (e->mUnk_74 & 0x1000) {
            func_020eda5c(&((Unk020ee684 *) *(void **) data_027e00c8)[(u8) e->mUnk_78].mUnk_058, e);
        }
        if (data_0217bc34[e->mUnk_44].mUnk_88 != 0) {
            if (func_020f9880(e) == 0) {
                func_020f7430(e, 1);
            } else {
                func_020f6be8(e, &param_1->mUnk_1b8, &param_1->mUnk_a4, &param_1->mUnk_05c);
                func_020f6f10(e, 1, (u16) param_1->mUnk_74);
            }
        }
        if (n >= 0x10) {
            n = lim;
        }
    }
    return n;
}

#pragma thumb on
