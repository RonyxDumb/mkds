#include "Main/Unknown/code_020cb2d4.h"

#pragma thumb on

// non-matching: 14 instructions differ; first at +0x0: original `push {r4, lr}`, ours `push {r4, r5, lr}`
void func_020cb2d4(void) {
    int iVar1;
    func_020cb340();
    iVar1 = *((int *) ((u32) (&data_0217b43c)));
    func_02124c30((void *) (*(u32 *) (iVar1 + ((int) 0x00000940u))), (void *) (*(u32 *) (iVar1 + ((int) 0x00000918u))),
                  (void *) (0), (void *) (iVar1 + ((int) 0x00000108u)),
                  (void *) (*(u32 *) (iVar1 + ((int) 0x0000093cu))));
    iVar1 = *((int *) ((u32) (&data_0217b43c)));
    func_02124c30((void *) (*(u32 *) (iVar1 + ((int) 0x0000094cu))), (void *) (*(u32 *) (iVar1 + ((int) 0x00000928u))),
                  (void *) (0), (void *) (iVar1 + ((int) 0x0000050cu)),
                  (void *) (*(u32 *) (iVar1 + ((int) 0x00000948u))));
    return;
}

#pragma thumb off
