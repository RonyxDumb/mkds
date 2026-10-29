#include "Main/Unknown/code_0200704c.h"
#include "Main/Unknown/code_020070b0.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0216f000.h"

#pragma thumb on

u32 func_0200704c(const Unk0216f3dc_9c *a) {
    u32 v1;
    s32 *v2;
    v1 = func_0200fca0();
    if (data_0216f3c8 != 1) {
        func_0200fcb4(v1);
        return 0;
    }
    v2 = (s32 *) func_020070b0();
    if (v2 == 0 || *v2 != 0) {
        func_0200fcb4(v1);
        return 0;
    }
    func_0214d02c(a, data_0216f478, 0x9c);
    func_0200fcb4(v1);
    return 1;
}

#pragma thumb off
