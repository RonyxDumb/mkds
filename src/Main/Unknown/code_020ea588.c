#include "Main/Unknown/code_020ea588.h"

#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020e6000.h"

void func_020ea5b0(u32 param_1, u32 param_2, Vec3 *param_3) {
    Vec3 v;

    if (param_3 != 0) {
        v.x = param_3->x >> 4;
        v.y = param_3->y >> 4;
        v.z = param_3->z >> 4;
        func_020e6854(param_1, (u32) &v, 1, param_2);
    } else {
        func_020e6854(param_1, 0, 0, param_2);
    }
}

#pragma thumb on

void func_020ea588(void **param_1, void *param_2, void *param_3) {
    *param_1 = func_02036bec(func_020364e0(func_020364e8()), 0x6c);
    func_02084e28(*param_1, param_2);
}

#pragma thumb off
