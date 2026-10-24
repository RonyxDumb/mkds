#include "Main/Unknown/code_02129cbc.h"

#pragma thumb on

void func_02129e78(void) {
    int iVar1;
    iVar1 =
        *(int *) (*((int *) ((u32) (&data_0217d400))) + *(int *) (*((int *) ((u32) (&data_0217d400))) + 4) * 4 + 0xb4);
    ((u32) func_02016468((u32) (0x1b), (u32) (0), (void *) (iVar1 + 0xc), (u32) (*(u32 *) (iVar1 + 8))));
    return;
}

// non-matching: 0x19c bytes, original 0x1bc; 54 instructions differ; first at +0x0: original `push {lr}`, ours `push
// {r4, lr}`
void func_02129cbc(void) {
    u32 uVar1;
    int local_10;
    int local_c[1];
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_0216e940))))));
    *(u32 *) (*((int *) ((u32) (&data_0217d400))) + 0xa4) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_0216e958))))));
    *(u32 *) (*((int *) ((u32) (&data_0217d400))) + 0x9c) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_0216e970))))));
    *(u32 *) (*((int *) ((u32) (&data_0217d400))) + 0xac) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_0216e988))))));
    *(u32 *) (*((int *) ((u32) (&data_0217d400))) + 0xa8) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_0216e998))))));
    *(u32 *) (*((int *) ((u32) (&data_0217d400))) + 0xa0) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_0216e9a8))))));
    *(u32 *) (*((int *) ((u32) (&data_0217d400))) + 0xb0) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_0216e9b8))))));
    func_020b49f4((int *) (u32) (*((int *) ((u32) (&data_0217d400))) + 0x94), uVar1);
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_0216e9d0))))));
    func_020b48ec((int *) (u32) (*((int *) ((u32) (&data_0217d400))) + 0x90), uVar1);
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_0216e9e8))))));
    func_020b4a7c((int *) (u32) (*((int *) ((u32) (&data_0217d400))) + 0x98), uVar1);
    func_0200ee74((u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_0217d400))) + 0x94) + 0x14)),
                  (int) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_0217d400))) + 0x94) + 0x10)));
    func_0214bf04((u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_0217d400))) + 0x94) + 0x14)), (int) (0),
                  (u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_0217d400))) + 0x94) + 0x10)));
    func_0214bea4((u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_0217d400))) + 0x94) + 0x14)), (int) (0),
                  (u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_0217d400))) + 0x94) + 0x10)));
    func_0200ee74((u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_0217d400))) + 0x98) + 0xc)),
                  (int) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_0217d400))) + 0x98) + 8)));
    func_0214c090((u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_0217d400))) + 0x98) + 0xc)), (int) (0),
                  (u32) (((u32) 0x000001a0u)));
    func_0214c090((u32) (*(int *) (*(int *) (*((int *) ((u32) (&data_0217d400))) + 0x98) + 0xc) + ((int) 0x000001c0u)),
                  (int) (((int) 0x000001c0u)), (u32) (0x40));
    func_0214c028((u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_0217d400))) + 0x98) + 0xc)), (int) (0),
                  (u32) (*(u32 *) (*(int *) (*((int *) ((u32) (&data_0217d400))) + 0x98) + 8)));
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_0216e9fc))))));
    func_020b496c(&local_10, uVar1);
    func_0200ee74((u32) (*(u32 *) (local_10 + 0x14)), (int) (*(u32 *) (local_10 + 0x10)));
    func_0214b824((u32) (*(u32 *) (local_10 + 0x14)), (int) (0), (u32) (*(u32 *) (local_10 + 0x10)));
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_0216ea14))))));
    func_020b4810((int *) (u32) (*((int *) ((u32) (&data_0217d400))) + 0xb4), uVar1);
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_0216ea30))))));
    func_020b4810((int *) (u32) (*((int *) ((u32) (&data_0217d400))) + 0xb8), uVar1);
    uVar1 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_0216ea4c))))));
    func_020b4a7c(local_c, uVar1);
    func_0200ee74((u32) (*(u32 *) (local_c[0] + 0xc)), (int) (0x80));
    func_0214c0f8((u32) (*(u32 *) (local_c[0] + 0xc)), (int) (0), (u32) (0x80));
    return;
}

#pragma thumb off
