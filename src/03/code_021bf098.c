#include "03/code_021bf098.h"

// non-matching: 5 instructions differ; first at +0xe: original `add r2, sp, #0x0`, ours `add r2, sp, #0x4`
void func_ov003_021bf098(int param_1) {
    int local_c;
    u8 auStack_10[4];
    func_ov003_021d1770((int) (*(u32 *) (*((int *) ((u32) (&data_ov003_021da108))) + 8)), (int) (0),
                        (u32 *) ((u32 *) (void *) (auStack_10)), (u32 *) (&local_c));
    local_c = local_c + 4;
    func_ov003_021bf258();
    if (192 <= local_c) {
        func_ov003_021d34e0((int) (param_1), (u32) (((u32) ((u32) (&func_ov003_021bf048)))));
    }
    return;
}
