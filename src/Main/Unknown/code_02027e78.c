#include "Main/Unknown/code_02027e78.h"
#include "Main/Unknown/code_02027f68.h"
#include "Main/Unknown/code_02027fb8.h"
#include "Main/Unknown/code_02027fd4.h"
#include "Main/Unknown/code_02028010.h"
#include "Main/Unknown/code_02028058.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

void func_02027e78(void) {
    u32 a = 0x16;
    s32 b = func_02025ebc(&(*(Unk02174e18 **) &data_02174e18)->mUnk_ec);
    if ((*(Unk02174e18 **) &data_02174e18)->mUnk_94 != 8) {
        a |= 8;
    }
    func_02028074(0x19);
    func_02028058(a);
    func_0202802c(0, -b);
    func_02028010(2);
    func_02027fd4(0, 0x3f, 6, 10);
    if (b != 0 && (*(Unk02174e18 **) &data_02174e18)->mUnk_94 != 8) {
        func_02027fb8(1);
        func_02027f90(0x1f, 1);
        func_02027f68(7, 1);
        func_02027f1c(0, 0, 0xff, b + 0xc0);
    } else {
        func_02027fb8(0);
    }
    if ((*(Unk02174e18 **) &data_02174e18)->mUnk_104 != 0) {
        func_0202ba14();
    }
}

#pragma thumb off

void func_02027f1c(u32 a, u32 b, u32 c, u32 d) {
    *(vu16 *) 0x04001040 = ((a << 8) & 0xff00) | (c & 0xff);
    *(vu16 *) 0x04001044 = ((b << 8) & 0xff00) | (d & 0xff);
}
