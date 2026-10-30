#include "Main/Unknown/code_0203a440.h"

u32 func_0203a440(u32 a) {
    u32 r;
    u32 f;
    u16 x;
    r = 1;
    f = 0;
    x = data_02175628[a].mUnk_4c;
    if (x == 0 && data_02175628[a].mUnk_58 < 5) {
        f = 1;
    }
    if (f == 0 && x == 0) {
        r = 0;
    }
    return r;
}
