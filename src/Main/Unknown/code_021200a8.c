#include "Main/Unknown/code_021200a8.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_02120610.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_0205c000.h"

void func_02120150(void) {
    Unk0217d384 *d;
    s32 a = 0;

    d = data_0217d384;
    if (d != 0) {
        if (d->mUnk_1f30 != 0) {
            a = 1;
        }
    }
    if (a == 0) {
        return;
    }
    d->mUnk_1f3c++;
    if (data_0217d384->mUnk_0008.mUnk_0e != 5) {
        return;
    }
    if (data_0217d384->mUnk_1f38 == 0) {
        return;
    }
    func_0205ccec();
}

void func_02120144(void) {
    func_0211fb44();
}

void func_021200fc(void) {
    Unk0217d384_08 *p;

    if (func_0211f91c() == 0) {
        return;
    }
    p = &data_0217d384->mUnk_0008;
    p->mUnk_10 = 2;
    p->mUnk_12 = 1;
}

void func_021200f0(void) {
    func_02120d50();
}

void func_021200a8(void) {
    Unk0217d384_08 *p;

    if (func_02120d14() == 0) {
        return;
    }
    p = &data_0217d384->mUnk_0008;
    p->mUnk_10 = 4;
    p->mUnk_12 = 1;
}
