#include "Main/Unknown/code_020d0efc.h"
#include "Main/Unknown/code_020d0e3c.h"
#include "Main/Unknown/code_020d0f60.h"
#include "Main/Unknown/code_020d0f78.h"
#include "Main/Unknown/unk_0216a000.h"
#include "Main/Unknown/code_02057000.h"

#pragma thumb on
u32 func_020d0efc(int param_1) {
    u32 r;

    r = 1;
    if (data_0216aeac[param_1 * 2] == 0) {
        r = 0;
    } else if (func_020d0ec4() != 0) {
        if (data_0217b4a4->mUnk_0c != param_1) {
            data_0217b4a4->mUnk_0c = param_1;
            func_02057df0(func_020d1080);
            func_02057df0(func_020d0ffc);
            func_02057df0(func_020d0f78);
            func_020d0f60();
        }
    } else {
        r = 0;
    }
    return r;
}
#pragma thumb off
