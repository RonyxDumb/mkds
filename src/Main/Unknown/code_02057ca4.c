#include "Main/Unknown/code_02057ca4.h"

#pragma thumb on

// non-matching: 2 instructions differ: the original loads 0x53444b4d and 0x30315653 into r1 and r0 before storing
// either (ldr r1; ldr r0; str r1, [r4]; str r0, [r4, #4]); here each constant is loaded just before its store.
void func_02057ca4(void *a) {
    u32 *v = data_021759d4->mUnk_60;
    if (data_021759d4->mUnk_0c != 0) {
        func_0214d1fc(a, v, 0x100);
        v[0] = 0x53444b4d;
        v[1] = 0x30315653;
        v[2] = 0x59534b4e;
        func_0204b430(0, 0x30f00, (u32) v, 0x100, 0, 1);
    }
}

#pragma thumb off
