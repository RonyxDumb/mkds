#include "Main/Unknown/code_0211f2b8.h"

#pragma thumb on

void func_0211f328(void) {
    u32 uVar1;
    u32 local_10;
    u32 local_c;
    u32 local_8[1];
    local_10 = 0;
    local_c = 0;
    local_8[0] = 0;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216e0a8))))));
    func_020b496c((void **) (&local_10), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216e0ac))))));
    func_020b48ec((void **) (&local_c), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216e0b4))))));
    func_020b4a7c((void **) (local_8), (void *) (uVar1));
    return;
}

// non-matching: 0x68 bytes, original 0x70; 18 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_0211f2b8(u32 param_1) {
    int iVar1;
    u32 uVar2;
    iVar1 = ((u32) func_02036bec((void *) (param_1), (u32) (0x10)));
    *((int *) ((u32) (&data_0217d37c))) = iVar1;
    uVar2 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216e0a8))))));
    func_020b49bc((Unk020b4934 **) ((int *) (u32) (*((int *) ((u32) (&data_0217d37c))))), (void *) (uVar2));
    uVar2 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216e0ac))))));
    func_020b48b4((void **) ((int *) (u32) (*((int *) ((u32) (&data_0217d37c))) + 4)), (void *) (uVar2));
    uVar2 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216e0b4))))));
    func_020b4a44((Unk020b4a44 **) ((int *) (u32) (*((int *) ((u32) (&data_0217d37c))) + 8)), (void *) (uVar2));
    uVar2 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216e0b0))))));
    *(u32 *) (*((int *) ((u32) (&data_0217d37c))) + 0xc) = uVar2;
    return;
}

#pragma thumb off
