#include "Main/Unknown/code_020f81c0.h"

#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020bb5cc.h"

void func_020f82a4(s32 param_1) {
    data_0217bc58 = 0x384;
    if (param_1 != 0) {
        data_0217bc58 += 0x12c;
    }
}

void func_020f8258(void) {
    if (data_0217bc60 > 0) {
        data_0217bc60 = data_0217bc60 - 1;
    }
    if (data_0217bc5c > 0) {
        data_0217bc5c = data_0217bc5c - 1;
    }
    if (data_0217bc58 > 0) {
        data_0217bc58 = data_0217bc58 - 1;
    }
}

// non-matching: the two table lookups (6 words from +0x34): the original loads the word at
// [r4, #0x10] before the table pointer value and multiplies with it in the higher register
// (`ldr r3, [r4, #0x10]; ldr r2, [r0]; mla ip, r3, r0, r2`, then `ldr r2, [ip, #8];
// ldr r1, [r1]; mla r3, r2, r0, r1`); here the pointer value is loaded first and the word from
// [r4, #0x10] is in the lower of the two registers (`ldr r3, [r0]; ldr r2, [r4, #0x10];
// mla ip, r2, r0, r3`, then `ldr r2, [r1]; ldr r1, [ip, #8]; mla r3, r1, r0, r2`).
// Every other instruction matches.
void func_020f81c0(Unk020ee684 *param_1) {
    Unk0217bc48 *e;
    Unk027e00cc *v;

    if (param_1->mUnk_018->mUnk_1f8 == data_021759c0->mUnk_62) {
        func_020bb5cc();
    }
    e = &data_0217bc48[param_1->mUnk_010];
    v = &data_027e00cc[e->mUnk_08];
    v->mUnk_1c -= e->mUnk_0c;
    param_1->mUnk_000 = 0;
    param_1->mUnk_004 = 0;
    param_1->mUnk_00c = 0x13;
    param_1->mUnk_010 = 0x13;
    param_1->mUnk_014 = 0x13;
    param_1->mUnk_020 = 0;
}
