#include "Main/Unknown/code_020e55b4.h"

// non-matching: 0x74 bytes, original 0x80; 19 instructions differ; first at +0x0: original `stmdb sp!, {lr}`, ours
// `stmdb sp!, {r4, lr}`
void func_020e55b4(void) {
    u32 local_8[1];
    local_8[0] = (u32) * (u16 *) ((*(u32 *) (((u32) ((u32) (&data_0217b814))))) + 0x1c);
    func_01ff9048((u32) (0x2b), (void *) ((u32) (u32) (local_8)), (int) (1));
    func_01ff9048((u32) (0x2a), (void *) ((*(u32 *) (((u32) ((u32) (&data_0217b814))))) + 0x14), (int) (1));
    func_01ff9048((u32) (0x30), (void *) ((*(u32 *) (((u32) ((u32) (&data_0217b814))))) + 4), (int) (1));
    func_01ff9048((u32) (0x31), (void *) ((*(u32 *) (((u32) ((u32) (&data_0217b814))))) + 8), (int) (1));
    return;
}
