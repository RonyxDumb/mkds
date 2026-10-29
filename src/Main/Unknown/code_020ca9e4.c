#include "Main/Unknown/code_020ca9e4.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020caae8.h"
#include "Main/Unknown/code_020caaac.h"
#include "Main/Unknown/code_020cab58.h"
#include "Main/Unknown/code_020cab74.h"
#include "Main/Unknown/code_020b4000.h"
#include "code_0214b824.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void func_020ca9e4(void) {
    if (data_0217b438->mUnk_08 != 0) {
        func_0214c0f8(data_0217b438->mUnk_60->mUnk_0c + 0xe0, 0x1c0, 0x40);
        func_0214ba94(data_0217b438->mUnk_64->mUnk_14, 0, 0x3000);
        data_0217b438->mUnk_08 = 0;
    }
    if (data_0217b438->mUnk_00 != 0) {
        func_0214bdd4(data_0217b438->mUnk_68->mUnk_0c, 0, 0x600);
    }
    if (data_0217b438->mUnk_00 != data_0217b438->mUnk_04) {
        if (data_0217b438->mUnk_00 != 0) {
            func_020cab58(func_020cab74() | 1);
            func_020cab2c(0, 0);
            func_020caae8(0x3e, 0x3f, 8, 8, -7);
        } else {
            func_020cab58(func_020cab74() & ~1);
            if (data_0217b438->mUnk_0c != 0) {
                data_0217b438->mUnk_0c();
            } else {
                func_020caaac(0, 0, 6, 10);
            }
        }
    }
    data_0217b438->mUnk_04 = data_0217b438->mUnk_00;
}
#pragma thumb off
