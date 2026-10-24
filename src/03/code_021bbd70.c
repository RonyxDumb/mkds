#include "03/code_021bbd70.h"

void func_ov003_021bbd70(u32 *param_1) {
    param_1[5] = 0;
    param_1[4] = param_1[5];
    *param_1 = ((u32) 0x67452301u);
    param_1[1] = ((u32) 0xefcdab89u);
    param_1[2] = ((u32) 0x98badcfeu);
    param_1[3] = ((u32) 0x10325476u);
    return;
}
