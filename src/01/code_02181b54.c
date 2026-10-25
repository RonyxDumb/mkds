#include "01/code_02181b54.h"

// non-matching: 0x40 bytes, original 0x44; 20 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov001_02181b8c(u32 param_1) {
    u16 uVar1;
    uVar1 = *(int *) (*((int *) ((u32) (&data_ov001_021a9b90))) + 0x44) +
                (u32) * (u8 *) (*((int *) ((u32) (&data_021759c0))) + ((int) 0x000003d0u)) &
            0xffff;
    *(u32 *) (*((int *) ((u32) (&data_ov001_021a9b90))) +
              (uVar1 - *(u8 *) (*((int *) ((u32) (&data_021759c0))) + ((int) 0x000003d0u))) * 4 + 0x48) = param_1;
    func_020a1728((int) (uVar1));
    *(int *) (*((int *) ((u32) (&data_ov001_021a9b90))) + 0x44) =
        *(int *) (*((int *) ((u32) (&data_ov001_021a9b90))) + 0x44) + 1;
    return;
}

Unk02188950 *func_ov001_02181b68(int param_1) {
    return data_ov001_021a9b90->mUnk_48[param_1 - data_021759c0->mUnk_3d0];
}

u8 func_ov001_02181b54(void) {
    return *(u8 *) (*((int *) ((u32) (&data_021759c0))) + ((int) 0x000003d0u));
}
