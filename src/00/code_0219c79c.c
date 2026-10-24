#include "00/code_0219c79c.h"

void func_ov000_0219c80c(u32 param_1, u32 param_2) {
    func_ov000_0219c79c((u32) (param_1), (u32) (param_2), (u32) (((u32) ((u32) (&func_ov000_0219c824)))), (u32) (2));
    return;
}

// non-matching: 0x68 bytes, original 0x70; 27 instructions differ; first at +0x2: original `sub sp, #0xc`, ours `sub
// sp, #0x14`
void func_ov000_0219c79c(u32 param_1, u32 param_2, u32 param_3, u32 param_4) {
    u32 *puVar1;
    u32 iVar2;
    u64 uVar3;
    func_0213a2d0((u32 *) ((u32 *) (u32) (*((int *) ((u32) (&data_ov000_021b565c))) + 0x4c)), (u32) (param_1));
    func_0213a2d0((u32 *) ((u32 *) (u32) (*((int *) ((u32) (&data_ov000_021b565c))) + ((int) 0x0000014cu))),
                  (u32) (param_2));
    iVar2 = *((int *) ((u32) (&data_ov000_021b565c)));
    uVar3 = func_0200f5ac();
    *(u64 *) (iVar2 + 0x38) = uVar3;
    *(u32 *) (iVar2 + 0x34) = 1;
    puVar1 = (u32 *) *((int *) ((u32) (&data_ov000_021b565c)));
    func_ov000_0218f15c((int *) (u32) (*puVar1), (s8 *) (void *) (puVar1 + 0x13),
                        (s8 *) (u32) ((int) puVar1 + ((int) 0x0000014cu)), 1, 0, param_3, 0);
    iVar2 = func_ov000_0219c8dc();
    if (iVar2 == 0) {
        *(u32 *) (*((int *) ((u32) (&data_ov000_021b565c))) + 4) = param_4;
    }
    return;
}
