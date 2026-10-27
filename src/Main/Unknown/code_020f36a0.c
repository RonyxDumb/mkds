#include "Main/Unknown/code_020f36a0.h"

#include "Main/Unknown/code_020b502c.h"

s32 func_020f36a0(u32 a, u32 *b) {
    if (a >= 0xff) {
        *b = 0;
    } else {
        *b = data_02175620->mUnk_b0 + a * 0x28;
    }
    b[1] = 1;
    return 1;
}
