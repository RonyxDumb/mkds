#include "Main/Unknown/code_0202b618.h"
#include "Main/Unknown/code_0202cb2c.h"
#include "Main/Unknown/code_0202cbf4.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

void func_0202b618(s32 a) {
    s32 i;
    s32 b;
    if (data_02174e3c->mUnk_208 != a) {
        if (a != 0) {
            for (i = data_02174e3c->mUnk_048; i < 8; i++) {
                if (data_02174e3c->mUnk_204 != 0) {
                    if (data_02174e3c->mUnk_04c[i].mUnk_00 == 1) {
                        b = 3;
                    } else {
                        b = 0;
                    }
                } else {
                    b = 0;
                }
                func_0202cc44(i, b);
                func_0202cb68(i);
            }
        } else {
            for (i = data_02174e3c->mUnk_048; i < 8; i++) {
                func_0202cb2c(i);
            }
        }
    }
    data_02174e3c->mUnk_208 = a;
}

#pragma thumb off
