#include "Main/Unknown/code_0210d740.h"
#include "Main/Unknown/code_0210d73c.h"
#include "Main/Unknown/code_0210dc60.h"
#include "Main/Unknown/code_0212c668.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_0212c6a0.h"
#include "Main/Unknown/unk_0216c000.h"
#include "code_0212df7c.h"
#include "code_0212d254.h"
#include "code_0212f1ac.h"
#include "code_0212ba68.h"
#include "code_0212c6ac.h"

void func_0210d854(u32 a) {
    func_0212f730((void *) (((u32) data_0217d06c + 0x1f) & ~0x1f), 0x1000, a);
    data_0216cb24 = a;
}

void func_0210d834(s32 a) {
    func_0212f638(a);
    data_0216cb24 = a;
}

void func_0210d7dc(u32 a, u32 b, Unk0212c400 **c) {
    if (*c != 0) {
        func_0212c6f0(c, 0);
    }
    func_0212d254(((Unk0212ea28 *) func_0212d51c(a))->mUnk_00);
    func_0212ed58(c, a);
    func_0212c678(c, b);
}

void func_0210d7ac(void) {
    if (data_0217d070.mUnk_00 != 0) {
        func_0210d73c(&data_0217d070);
    }
    func_0212ba74();
}

void func_0210d740(Unk0217d070 *a, Unk0217c814 *b, u32 c, Unk021073ec d) {
    func_0210dc60(&data_0217d084, a, 0);
    *(Unk021073ec *) &a->mUnk_09 = d;
    a->mUnk_04 = b;
    a->mUnk_08 = c;
    func_0212c6a0(&a->mUnk_0c);
    func_0212c6a0(&a->mUnk_10);
    a->mUnk_00 = 1;
}
