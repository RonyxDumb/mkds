#include "Main/Unknown/code_02118088.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/unk_0217d000.h"

#pragma thumb on

void func_021180f8(void) {
    data_0217d360->mUnk_34 = 7;
    data_0217d360->mUnk_38 = 0;
    func_021277e4();
}

void func_02118088(void) {
    void *a;

    data_0217d360->mUnk_34 = 8;
    data_0217d360->mUnk_38 = 0;
    if (*(vu16 *) 0x027ffc40 == 2) {
        a = func_020b3f7c(data_0217d360->mUnk_24, 0x5d);
        func_021277f8(a, func_020b3f7c(data_0217d360->mUnk_24, 0x5f), 0);
    } else {
        a = func_020b3f7c(data_0217d360->mUnk_28, 0x14);
        func_021277f8(a, func_020b3f7c(data_0217d360->mUnk_28, 0x15), 0);
    }
}

#pragma thumb off
