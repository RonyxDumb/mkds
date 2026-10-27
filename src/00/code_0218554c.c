#include "00/code_0218554c.h"

void func_ov000_0218554c(void) {
    u32 uVar1;
    uVar1 = ((int) func_0204799c((const char *) (((u32) &data_ov000_021b0f28))));
    *(u32 *) ((*(int *) &data_ov000_021b4c88) + 0x40) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (((u32) &data_ov000_021b0f44))));
    *(u32 *) ((*(int *) &data_ov000_021b4c88) + 0x48) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) (((u32) &data_ov000_021b0f60))));
    func_020b49bc((Unk020b4934 **) ((int *) (u32) ((*(int *) &data_ov000_021b4c88) + 0x38)), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (((u32) &data_ov000_021b0f80))));
    func_020b48b4((void **) ((int *) (u32) ((*(int *) &data_ov000_021b4c88) + 0x34)), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (((u32) &data_ov000_021b0fa0))));
    func_020b4a44((Unk020b4a44 **) ((int *) (u32) ((*(int *) &data_ov000_021b4c88) + 0x3c)), (void *) (uVar1));
    func_0214bf04((const void *) (*(u32 *) (*(int *) ((*(int *) &data_ov000_021b4c88) + 0x38) + 0x14)), (int) (0),
                  (u32) (*(u32 *) (*(int *) ((*(int *) &data_ov000_021b4c88) + 0x38) + 0x10)));
    func_0214c090((const void *) (*(u32 *) (*(int *) ((*(int *) &data_ov000_021b4c88) + 0x3c) + 0xc)), (int) (0),
                  (u32) (((u32) 0x000001a0u)));
    func_0214c090(
        (const void *) (*(int *) (*(int *) ((*(int *) &data_ov000_021b4c88) + 0x3c) + 0xc) + ((int) 0x000001c0u)),
        (int) (((int) 0x000001c0u)), (u32) (0x40));
    return;
}
