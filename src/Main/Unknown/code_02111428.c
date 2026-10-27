#include "Main/Unknown/code_02111428.h"

#include "Main/Unknown/code_021114cc.h"
#include "Main/Unknown/unk_0217d000.h"

#pragma thumb on

void func_02111428(void) {
    if (data_0217d344->mUnk_2c > 0) {
        data_0217d344->mUnk_2c = data_0217d344->mUnk_2c - 1;
        if (data_0217d344->mUnk_2c == 0) {
            data_0217d344->mUnk_18.mUnk_10();
        }
    }
}

#pragma thumb off
