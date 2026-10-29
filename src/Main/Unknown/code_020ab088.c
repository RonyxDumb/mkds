#include "Main/Unknown/code_020ab088.h"
#include "Main/Unknown/code_020ab1a8.h"
#include "Main/Unknown/code_020ab5e4.h"
#include "Main/Unknown/code_020ab714.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02167000.h"

#pragma thumb on

void func_020ab11c(s32 *a, s32 *b, s32 *c, s32 *d) {
    if (data_0217b278.mUnk_44 != 0 && a != 0 && b != 0 && c != 0 && d != 0) {
        *a = data_0217b278.mUnk_44->mUnk_00;
        *b = data_0217b278.mUnk_44->mUnk_01;
        *c = data_0217b278.mUnk_44->mUnk_00 + data_0217b278.mUnk_44->mUnk_02;
        *d = data_0217b278.mUnk_44->mUnk_01 + data_0217b278.mUnk_44->mUnk_03;
        if (data_0217b278.mUnk_44->mUnk_06 <= 0xff) {
            *a = *a + data_0217b234;
            *b = *b + data_0217b238;
            *c = *c + data_0217b234;
            *d = *d + data_0217b238;
        }
    }
}

void func_020ab088(struct Unk02022aa8 *a, void *b, u16 *c, s32 d, s32 e, s32 f) {
    func_0214d168(&data_0217b278, 0, 0x54);
    data_0217b254.mUnk_00 = a;
    data_0217b254.mUnk_04 = b;
    data_0217b254.mUnk_08 = b;
    data_0217b254.mUnk_0c = c;
    data_0217b254.mUnk_10 = d;
    data_0217b254.mUnk_14 = e;
    data_0217b254.mUnk_1c = f;
    func_020ab714();
    func_020ab5e4(&data_0217b2ac, 0x28, 5);
    func_020ab580(data_021679fc[2] | (data_021679fc[0] | 0xf0 | data_021679fc[1]));
    data_0217b24c[0] = data_0217b244[0] = data_0217b23c[0] = data_02167a04[0];
    data_0217b24c[1] = data_02167a04[1];
    data_0217b244[1] = data_02167a04[2];
    data_0217b23c[1] = data_02167a04[3];
}

#pragma thumb off
