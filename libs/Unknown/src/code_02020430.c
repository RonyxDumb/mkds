#include "code_02020430.h"
#include "Main/Unknown/unk_02173000.h"

s32 func_02020498(s32 a) {
    if (a > 0x7f && a <= 0xfe) {
        return a - 0x7f;
    }
    return 0x7f - a;
}

void func_02020430(Unk02173290 *a) {
    s32 i;

    data_02173290 = a;
    data_02173294 = 1;
    data_02173288 = 0;
    data_02173298 = 0;
    for (i = 0; i < 4; i++) {
        data_021732a0[i] = 0;
    }
}
