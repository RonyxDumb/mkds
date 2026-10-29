#include "Main/Unknown/code_0204236c.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020423fc.h"

#pragma thumb on
void func_0204236c(void) {
    void *h;
    Unk02175620_74 *e;
    Unk02175620_d8 **q;
    u16 i;
    u16 j;

    h = func_020364e0(func_020364e8());
    i = 0;
    for (j = 0; j < 8; j++) {
        data_02175620->mUnk_d8[j] = 0;
    }
    for (i = 0; i < data_02175620->mUnk_78; i++) {
        e = func_020423fc(i);
        if (e->mUnk_44 == 3) {
            q = &data_02175620->mUnk_d8[(s16) e->mUnk_3c];
            while (*q != 0) {
                q = &(*q)->mUnk_04;
            }
            *q = func_02036bec(h, 8);
            (*q)->mUnk_00 = e;
            (*q)->mUnk_04 = 0;
        }
    }
}
#pragma thumb off
