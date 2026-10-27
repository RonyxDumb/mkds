#include "Main/Unknown/code_021113ac.h"

#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_021115b0.h"
#include "Main/Unknown/unk_0217d000.h"

#pragma thumb on

void func_021113ac(s16 *a) {
    void *p;
    p = func_020364e0(func_020364e8());
    data_0217d33c = func_02036bec(p, 0x404);
    data_0217d340 = func_02036bec(p, 0x404);
    func_021115b0(p, *a);
}

#pragma thumb off
