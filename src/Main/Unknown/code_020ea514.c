#include "Main/Unknown/code_020ea514.h"

#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"

#pragma thumb on

void func_020ea514(u32 param_1, void *param_2, void *param_3, void *param_4, void *param_5) {
    void *p;

    p = func_020364e0(func_020364e8());
    func_0208823c(param_1, param_3, param_2, 1, p, param_4);
    func_0208805c(param_3, param_5, func_020364e0(func_020364e8()));
    func_02087f84(param_3, 0);
}

#pragma thumb off
