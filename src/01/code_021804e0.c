#include "01/code_021804e0.h"
#include "01/code_021805ec.h"
#include "01/code_021805f4.h"
#include "01/code_02180610.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_020ae718.h"
#include "01/code_0219e89c.h"
#include "01/code_02180000.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_020ca000.h"

#pragma optimize_for_size on
#pragma thumb off

u16 func_ov001_021805d8(Unk02175628 *p0, unsigned int p1) {
    return p0->mUnk_00 & p1;
}

unsigned int func_ov001_021805bc(unsigned int p0, unsigned int p1) {
    return func_ov001_021805d8(&data_02175628[p0], p1);
}

#pragma thumb on

void func_ov001_0218052c(Unk0218052c *p0) {
    unsigned int v;
    Unk021a99e4 *g;

    func_ov001_021805ec();
    func_020ae718();
    if (p0 != 0) {
        v = func_ov001_021805ec();
        if (func_ov001_021805bc(v, 1) != 0) {
            p0->mUnk_04 = 0;
        }
        if (func_ov001_021805bc(v, 0x400) != 0) {
            g = data_ov001_021a99e4;
            g->mUnk_0004 = (g->mUnk_0004 + 1) % 4;
            data_ov001_021a99e4->mUnk_0008 = 1;
            if (data_ov001_021a99e4->mUnk_0004 == 1) {
                func_020ca688(0);
            }
        }
    }
    switch (data_ov001_021a99e4->mUnk_0004) {
    case 0:
        func_020ca844();
        func_020ca83c();
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
}

void func_ov001_02180524(void) {
    func_ov001_02180610();
}

void func_ov001_0218051c(void) {
    func_ov001_021805f4();
}

void func_ov001_02180514(void) {
    func_ov001_02180800();
}

void func_ov001_0218050c(Unk0218052c *p0) {
    func_ov001_0218052c(p0);
}

int func_ov001_021804e0(void *p0) {
    Unk021a9034 v = {func_ov001_02180524, func_ov001_0218050c, func_ov001_0218051c, func_ov001_02180514, 0, 0, 0x1e, 0x1e, 0};

    func_020487fc(p0, &v);
    return 0;
}
