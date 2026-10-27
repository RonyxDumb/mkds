#include "Main/Unknown/code_02108e38.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_0212c6ac.h"

// non-matching: the original keeps the base address in a register and forms each argument as base + 4 * i
// (add r0, r5, r6, lsl #2); this compiles to a pointer that advances by 4 each pass (mov r0, r5 ... add r5, r5, #4)
void func_02108e38(void)
{
    s32 i;

    for (i = 7; i < 12; i++) {
        func_0212c6f0(&data_0217c838[i], 0);
    }
}
