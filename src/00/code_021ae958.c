#include "00/code_021ae958.h"

void func_ov000_021ae958(void) {
    u32 *puVar1;
    puVar1 = (u32 *) func_ov000_021af090();
    if (puVar1 != (u32 *) 0x0) {
        func_0200dd94();
        *(u8 *) (puVar1 + 2) = 0;
        if (puVar1[1] - 1 <= 1) {
            puVar1[1] = 0;
            func_0200df68((int) (*puVar1));
        }
    }
    return;
}
