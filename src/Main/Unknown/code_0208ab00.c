#include "Main/Unknown/code_0208ab00.h"

void func_0208ab4c(u16 *param_1) {
    u32 local_10;
    u32 local_c;
    local_10 = (u32) *param_1;
    func_01ff9048((u32) 0x33, (void *) ((u32) (u32) (&local_10)), (int) 1);
    local_c = *param_1 | 0x40000000;
    func_01ff9048((u32) 0x33, (void *) ((u32) (u32) (&local_c)), (int) 1);
}

void func_0208ab00(void) {
    u32 local_10;
    u32 local_c[1];
    local_10 = ((u32) 0x00007fffu);
    func_01ff9048((u32) 0x33, (void *) ((u32) (u32) (&local_10)), (int) 1);
    local_c[0] = ((u32) 0x40007fffu);
    func_01ff9048((u32) 0x33, (void *) ((u32) (u32) local_c), (int) 1);
}
