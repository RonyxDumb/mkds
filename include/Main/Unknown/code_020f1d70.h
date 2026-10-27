#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"

typedef struct Unk020edb8c {
    u8 mUnk_00[0xc];
    Unk020f40dc_Owner *mUnk_0c;
    Unk0206bcb0 *mUnk_10;
    u8 mUnk_14[0x18];
    Vec3 mUnk_2c;
    Vec3 mUnk_38;
    Vec3 mUnk_44;
    u8 mUnk_50[0x18];
    s32 mUnk_68;
    Vec3 mUnk_6c;
    u8 mUnk_78[4];
    s32 mUnk_7c;
    s32 mUnk_80;
    u8 mUnk_84[8];
    s32 mUnk_8c;
} Unk020edb8c;

void func_020f1d70(void *a0, const Vec3 *b);
void func_020f1ea4(void *a0, s32 b, s32 c, s32 d);
void func_020f1f98(Unk0206bcb0 *a, Vec3 *b, Vec3 *c);
void func_020f2028(Unk0206bcb0 *a);
void func_020f2150(void *a0);
void func_020f2228(Unk0206bcb0 *a, s32 b);
void func_020f2768(Unk0206bcb0 *a, Vec3 *b, Vec3 *c);
void func_020f288c(Unk0206bcb0 *a, Vec3 *b);
void func_020f29e8(u32 a);
void func_020f2a6c(Vec3 *a, Vec3 *b, Vec3 *c);
void func_020f2b94(void *a0, void *b0, s32 c, s32 d, s32 e, s32 f);
