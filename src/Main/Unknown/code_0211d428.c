#include "Main/Unknown/code_0211d428.h"

#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/code_0202b6a0.h"

#pragma thumb on

void func_0211d428(u32 a, u32 b) {
    data_0217d368->mUnk_8c[a] = b;
    func_0202b6a0(a, data_0215cca4[b]);
}

#pragma thumb off
