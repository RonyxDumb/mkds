#include "01/code_0218175c.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_0210b000.h"

void func_ov001_0218175c(s32 param_1) {
    Unk021759c0 *p = data_021759c0;
    u32 m = p->mUnk_2f;
    if (m == 3 || m == 7 || m == 0) {
        u32 a = p->mUnk_3c;
        if (a == 0 && p->mUnk_3e == 0 && p->mUnk_40 == 0 && p->mUnk_42 == 0 && param_1 > 400 && param_1 < 500) {
            func_ov001_02181aa0();
            return;
        }
        if (param_1 == a || param_1 == p->mUnk_3e || param_1 == p->mUnk_40 || param_1 == p->mUnk_42) {
            func_ov001_02181aa0();
        }
    }
}
