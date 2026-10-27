#include "Main/Unknown/code_021285b0.h"
#include "Main/Unknown/code_02128244.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_02016468.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0217d000.h"

#pragma thumb on
void func_02128778(void) {
    u32 t;
    t = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | ((t | 4) << 8);
    *(vu16 *) 0x400100c = (*(vu16 *) 0x400100c & ~3);
    *(vu16 *) 0x400100c = (*(vu16 *) 0x400100c & 0x43) | 0xe00;
}

s32 func_021286a0(s32 a) {
    Unk020b4934 *x;
    Unk020b47d8 *y;
    Unk020b4a44 *z;
    s32 i;
    s32 j;
    s32 k;
    func_020b4934(&x, func_02047a28("select_return_s_b_00.ncgr"));
    func_020b47d8(&y, func_02047a28("select_return_s_bg_00.nscr"));
    func_020b4a44(&z, func_02047a28("select_return_s_b_00.nclr"));
    a -= x->mUnk_10;
    func_0200ee74((u32) x->mUnk_14, x->mUnk_10);
    func_0214b8f4(x->mUnk_14, a, x->mUnk_10);
    for (i = 0; i < 0x20; i++) {
        for (j = 0; j < 0x20; j++) {
            *(data_0217d3f8->mUnk_10 + i * 0x20 + j) = (a >> 5) + *((u16 *) y->mUnk_0c + i * 0x20 + j);
        }
    }
    func_0200ee74((u32) data_0217d3f8->mUnk_10, y->mUnk_08);
    func_0214bc34(data_0217d3f8->mUnk_10, 0, y->mUnk_08);
    func_0200ee74((u32) z->mUnk_0c, 0x180);
    func_0214c0f8(z->mUnk_0c + 0xc0, 0x180, 0x40);
    return a;
}

void func_02128624(s32 a) {
    s32 i;
    u16 v;
    v = 0xc000;
    if (a == 0) {
        v = 0xd000;
    }
    for (i = 0x260; i < 0x360; i++) {
        data_0217d3f8->mUnk_10[i] &= ~0xf000;
        data_0217d3f8->mUnk_10[i] |= v;
    }
    if (*(vu16 *) 0x27ffc40 != 2) {
        func_02016468(0x1a, 0x4c0, &data_0217d3f8->mUnk_10[0x260], 0x200);
    }
}

void func_021285f8(void) {
    if (data_0217d3f8->mUnk_810 != 0) {
        data_0217d3f8->mUnk_08 = 1;
        data_0217d3f8->mUnk_0c = 0;
        func_02128624(1);
    }
}

void func_021285b0(void) {
    Unk0217d3f8 *p;
    data_0217d3f8->mUnk_81c = func_0212825c(data_0217d3f8->mUnk_0c);
    data_0217d3f8->mUnk_0c++;
    p = data_0217d3f8;
    if (p->mUnk_0c >= 10) {
        p->mUnk_08 = 2;
        data_0217d3f8->mUnk_0c = 0;
        data_0217d3f8->mUnk_810 = 0;
    }
}
#pragma thumb off
