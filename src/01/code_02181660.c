#include "01/code_02181660.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_0210b000.h"

void func_ov001_02181678(u32 param_1) {
    Unk021a9b90 *p = data_ov001_021a9b90;
    u16 lim = p->mUnk_04;
    if (param_1 >= lim) {
        param_1 = lim;
    }
    p->mUnk_0a += param_1;
}

void func_ov001_02181660(u16 param_1) {
    Unk021a9b90 *p = data_ov001_021a9b90;
    u16 lim = p->mUnk_04;
    if (param_1 >= lim) {
        param_1 = lim;
    }
    p->mUnk_0c += param_1;
}
