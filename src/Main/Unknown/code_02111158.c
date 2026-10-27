#include "Main/Unknown/code_02111158.h"

#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212da38.h"
#include "code_0212df7c.h"

void func_02111250(void *a, u32 b) {
    data_0217d32c.mUnk_04 = func_0212dcc8(a, b);
    data_0217d32c.mUnk_08 = 0;
}

u32 func_02111158(s32 a) {
    Unk0217d32c *p;
    u32 *b;
    Unk0212d9dc *n;
    s32 i;
    n = data_0217d130;
    p = &data_0217d32c;
    if (a == 4 && (data_021759c0->mUnk_08 == 4 ? data_021759c0->mUnk_55 : -1) == 9) {
        b = data_0216cbc0;
    } else {
        b = data_0216cbd8[a];
    }
    if (p->mUnk_08 == b) {
        return 1;
    }
    data_0217d130 = data_0217d32c.mUnk_04;
    func_0212dbec(p->mUnk_04);
    for (i = 0; i < 6; i++) {
        if (b[i] != 0xff) {
            if (func_0212e9cc(b[i], data_0217d130) == 0) {
                data_0217d130 = n;
                return 0;
            }
        }
    }
    p->mUnk_00 = a;
    p->mUnk_08 = b;
    data_0217d130 = n;
    return 1;
}
