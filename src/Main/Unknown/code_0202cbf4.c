#include "Main/Unknown/code_0202cbf4.h"

#pragma thumb on

void func_0202cc44(s32 param_1, s32 param_2) {
    data_02174e3c->mUnk_04c[param_1].mUnk_04.mUnk_00 = 10;
    data_02174e3c->mUnk_04c[param_1].mUnk_04.mUnk_0c = param_2;
    data_02174e3c->mUnk_04c[param_1].mUnk_04.mUnk_04 = data_02174e3c->mUnk_04c[param_1].mUnk_04.mUnk_0c;
    data_02174e3c->mUnk_04c[param_1].mUnk_04.mUnk_08 = data_02174e3c->mUnk_04c[param_1].mUnk_04.mUnk_04;
}

void func_0202cc18(s32 param_1, s32 param_2) {
    Unk02174e3c_4c_04 *entry;
    entry = &data_02174e3c->mUnk_04c[param_1].mUnk_04;
    entry->mUnk_04 = param_2;
    if (entry->mUnk_04 == entry->mUnk_08) {
        entry->mUnk_08 = entry->mUnk_0c;
        entry->mUnk_0c = entry->mUnk_04;
        entry->mUnk_00 = 10 - entry->mUnk_00;
    }
}

void func_0202cbf4(void) {
    s32 i;
    i = 0;
    do {
        func_0202cc44(i, 0);
        func_0202cc18(i, 1);
        i++;
    } while (i < 8);
}

#pragma thumb off
