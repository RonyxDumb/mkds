#include "Main/Unknown/code_0203a3cc.h"

u32 func_0203a3cc(u32 a) {
    u32 r;
    u32 f;
    r = 0;
    f = 0;
    if (data_02175628[a].mUnk_4c == 0 && data_02175628[a].mUnk_58 < 5) {
        f = 1;
    }
    if (f == 0 && data_02175628[a].mUnk_54 == 0 && data_02175628[a].mUnk_4c != 0) {
        r = 1;
    }
    return r;
}
