#include "01/code_0218b35c.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b4000.h"

void func_ov001_0218b5d8(Unk0218d87c *param_1) {
    s32 i;
    Unk02188950 *obj;

    if (param_1 != 0) {
        for (i = 0; i < param_1->mUnk_04 && (obj = param_1->mUnk_00[i]) != 0; i++) {
            func_ov001_0219b1c4(obj->mUnk_304, obj->mUnk_0a0->mUnk_080, obj->mUnk_0a0->mUnk_050, 0);
            if (func_02062ec4()) {
                func_ov001_0218b770((int)obj);
            } else {
                func_ov001_0218b7c8((int)obj);
            }
        }
    }
    func_020a2314((void (*)(void)) func_ov001_0218b8f0);
}

void func_ov001_0218b404(u32 param_1, Unk02188950 *param_2) {
    s32 var;

    if (data_021759c0->mUnk_08 == 4 ? func_020a126c() : 0) {
        if (func_ov001_021871f8(param_2, 1)) {
            if (data_021759c0->mUnk_08 == 4 ? func_020a1084((u16)data_021759c0->mUnk_62) : 0) {
                func_ov001_0218b9b4(param_2);
            } else {
                func_ov001_0218b8f8((int)param_2);
            }
        }
    } else {
        if (func_ov001_021881a8((Unk02188950 *) param_2, (Vec3 *) func_ov001_02187fc0(param_2), (s32) (param_2->mUnk_0a0->mUnk_0b4), (s32) (0))) {
            var = func_ov001_02187f7c(param_2);
            if (var >= 200) {
                if (func_ov001_021871f8(param_2, 8)) {
                    func_ov001_0218ba34(param_2);
                    func_ov001_02188200((Unk02188950 *) (param_2), (UnkFunc *) (func_ov001_0218b6f8));
                }
            } else if (var >= 100) {
                if (func_ov001_021871f8(param_2, 7)) {
                    func_ov001_0218bbac(param_2);
                    func_ov001_02188200((Unk02188950 *) (param_2), (UnkFunc *) (func_ov001_0218b6f8));
                }
            } else if (var >= 1) {
                if (func_ov001_021871f8(param_2, 1)) {
                    func_ov001_0218bde8(param_2);
                    func_ov001_02188200((Unk02188950 *) (param_2), (UnkFunc *) (func_ov001_0218b6f8));
                }
            }
            func_ov001_02187e78((Unk02188950 *) param_2);
            if (param_2->mUnk_14c == 0) {
                func_ov001_02187e48(param_2, 3);
            }
        }
        if (func_ov001_021871f8(param_2, 2)) {
            if (func_ov001_02188104(param_2, param_2->mUnk_0a0->mUnk_124, param_2->mUnk_0a0->mUnk_128)) {
                func_ov001_0218c490(param_2);
                func_ov001_02188200((Unk02188950 *) (param_2), (UnkFunc *) (func_ov001_0218b640));
            }
        }
        if (func_ov001_021871f8(param_2, 1)) {
            func_ov001_0218c354(param_2);
            func_ov001_02188200((Unk02188950 *) (param_2), (UnkFunc *) (func_ov001_0218b640));
        }
        param_2->mUnk_2b8 = 1;
    }
    func_ov001_021864ac(param_1, param_2);
    func_ov001_0219b1fc(param_2->mUnk_304);
    var = param_2->mUnk_134 + 1;
    if (var >= func_ov001_02188220(param_2) * 30) {
        var = func_ov001_02188220(param_2) * 30;
    }
    param_2->mUnk_134 = var;
    var = param_2->mUnk_134;
    if (var >= func_0209b710(param_2->mUnk_304) - 1) {
        var = func_0209b710(param_2->mUnk_304) - 1;
    }
    param_2->mUnk_134 = var;
    func_0209b734(param_2->mUnk_304, (u16)param_2->mUnk_134);
}

void func_ov001_0218b35c(Unk0218d87c *param_1) {
    s32 i;
    Unk02188950 *obj;

    if (param_1 != 0) {
        for (i = 0; i < param_1->mUnk_04 && (obj = param_1->mUnk_00[i]) != 0; i++) {
            if (data_021759c0->mUnk_08 == 4) {
                func_ov001_02181b8c((u32)obj);
            }
            func_ov001_021870e4((void *) (param_1), (Unk02188950 *) (obj), (const char *) ("kuriking.nsbmd"), (const char *) ("kuriking.nsbca"), (const char *) ("kuriking.prm"));
            func_ov001_021870b0((void *) (param_1), (Unk02188950 *) (obj), (const char *) ("sh_circle.nsbmd"));
            func_ov001_0219b31c(obj->mUnk_304, "kuriking.nsbta");
            func_ov001_0219b2e8(obj->mUnk_304, "kuriking.nsbtp");
            func_ov001_0219b380(obj->mUnk_304, "kuriking.nsbma");
            func_ov001_0218c728((int)obj);
            func_ov001_02188200((Unk02188950 *) (obj), (UnkFunc *) (func_ov001_0218b6f8));
        }
    }
}
