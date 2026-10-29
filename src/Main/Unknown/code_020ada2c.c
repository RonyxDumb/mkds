#include "Main/Unknown/code_020ada2c.h"
#include "Main/Unknown/code_020ada7c.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on

// non-matching: the original loads the table index (mUnk_0c) before it copies the argument into r0; here the argument
// copy comes first (two instructions swapped).
void func_020ada2c(s32 a) {
    func_020ae6ac(&data_0217b340->mUnk_b0, &data_0217b340->mUnk_4b4);
    data_0217b340->mUnk_14[data_0217b340->mUnk_0c].mUnk_04(a);
    func_020ada7c((int *) data_0217b340);
    func_02125928();
    func_020ae630(&data_0217b340->mUnk_b0, &data_0217b340->mUnk_4b4);
}

#pragma thumb off
