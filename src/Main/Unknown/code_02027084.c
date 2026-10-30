#include "Main/Unknown/code_02027084.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

void func_02027084(void) {
    Unk02174e14_00 *p = &data_02174e14->mUnk_01c;
    s32 i;
    s32 n;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        n = p->mUnk_0c->mUnk_06;
        for (i = 0; i < n; i++) {
            func_02124b1c(&p->mUnk_18[i], data_02174e14->mUnk_074, data_02174e14->mUnk_070);
        }
    }
}

#pragma thumb off
