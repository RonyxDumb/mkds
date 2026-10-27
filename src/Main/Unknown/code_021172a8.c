#include "Main/Unknown/code_021172a8.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/unk_0217d000.h"

#pragma thumb on

void func_021172a8(void *param_1) {
    int i;

    data_0217d35c = func_02036bec(param_1, 0x18);
    func_020b49bc(&data_0217d35c->mUnk_00, func_0204799c(data_0216d534));
    func_020b48b4(&data_0217d35c->mUnk_04, func_0204799c(data_0216d538));
    for (i = 0; i < 3; i++) {
        func_020b4a44(&data_0217d35c->mUnk_08[i], func_0204799c(data_0216d53c[i]));
    }
    data_0217d35c->mUnk_14 = func_0204799c(data_0216d52c);
}

#pragma thumb off
