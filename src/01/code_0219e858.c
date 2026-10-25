#include "01/code_0219e858.h"

// non-matching: 0x48 bytes, original 0x44; 14 instructions differ; first at +0x0: original `push {r4, lr}`, ours `push
// {r4, r5, lr}`
void func_ov001_0219e858(int param_1) {
    u16 uVar1;
    int iVar2;
    func_020ae6ac((void *) (*((int *) ((u32) (&data_ov001_021ca404)))), (void *) (*((int *) ((u32) (&data_ov001_021ca404))) + ((int) 0x00000404u)));
    func_ov001_02198554();
    func_020ae630((void *) (*((int *) ((u32) (&data_ov001_021ca404)))), (void *) (*((int *) ((u32) (&data_ov001_021ca404))) + ((int) 0x00000404u)));
    if ((param_1 != 0) && (iVar2 = func_ov001_0219853c(), iVar2 != -1)) {
        uVar1 = func_ov001_0219853c();
        *(u16 *) (param_1 + 4) = uVar1;
    }
    return;
}
