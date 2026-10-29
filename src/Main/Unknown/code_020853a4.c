#include "Main/Unknown/code_020853a4.h"

s32 func_020853a4(u32 a) {
    s32 m;
    s32 v;
    m = data_02175620->mUnk_108;
    v = func_0203c5c8(a);
    return ((s64) v * m + 0x800) >> 12;
}
