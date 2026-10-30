#include "Main/Unknown/code_0207a790.h"
#include "Main/Unknown/code_02040de0.h"

void func_0207a790(s32 a) {
    u16 i;

    data_0217ad28 = 0;
    for (i = 0; i < 8; i++) {
        if (func_02040de0(a, i) != 0) {
            data_0217ad28 |= 1 << i;
        }
    }
}
