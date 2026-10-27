#include "Main/Unknown/code_0210f744.h"

#include "Main/Unknown/unk_0217d000.h"
#include "code_0212bcac.h"

void func_0210f808(void) {
    u8 i;

    for (i = 0; i < 2; i++) {
        data_0217d254[i].mUnk_00 = -1;
        data_0217d254[i].mUnk_02 = -1;
        data_0217d254[i].mUnk_04 = -1;
        data_0217d254[i].mUnk_08[0] = i;
    }
}

void func_0210f780(Unk0212c400 **a) {
    Unk0217d254 *p;
    s32 i;

    for (i = 0; i < 2; i++) {
        p = &data_0217d254[i];
        if (data_0217d23c[i] == 0) {
            continue;
        }
        if (func_0212c400(a, p->mUnk_08[0], (s16 *) p) == 0) {
            continue;
        }
        if (p->mUnk_02 != p->mUnk_00) {
            p->mUnk_04 = 0;
        } else {
            if (p->mUnk_04 >= 0) {
                p->mUnk_04++;
            }
        }
        p->mUnk_02 = p->mUnk_00;
    }
}

u32 func_0210f75c(u32 a) {
    return data_0217d254[a].mUnk_04 == 0;
}

u32 func_0210f744(u32 a) {
    return data_0217d254[a].mUnk_04;
}
