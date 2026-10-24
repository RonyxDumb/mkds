#include "01/code_0219e5a0.h"

// non-matching: 0x84 bytes, original 0x8c; 17 instructions differ; first at +0x0: original `push {r4, lr}`, ours `push
// {r4, r5, lr}`
void func_ov001_0219e5d4(int param_1) {
    int iVar1;
    param_1 = param_1 * 4;
    iVar1 = *(int *) (*((int *) ((u32) (&data_ov001_021ca400))) + param_1 + 0x38);
    ((u32) func_02016468((u32) (4), (u32) (0), (void *) (*(u32 *) (iVar1 + 0x14)), (u32) (*(u32 *) (iVar1 + 0x10))));
    iVar1 = *(int *) (*((int *) ((u32) (&data_ov001_021ca400))) + param_1 + 0x40);
    ((u32) func_02016468((u32) (8), (u32) (0), (void *) (iVar1 + 0xc), (u32) (*(u32 *) (iVar1 + 8))));
    iVar1 = *(int *) (*((int *) ((u32) (&data_ov001_021ca400))) + param_1 + 0x48);
    ((u32) func_02016468((u32) (0xf), (u32) (0), (void *) (*(u32 *) (iVar1 + 0xc)), (u32) (*(u32 *) (iVar1 + 8))));
    iVar1 = *(int *) (*((int *) ((u32) (&data_ov001_021ca400))) + param_1 + 0x50);
    ((u32) func_02016468((u32) (0x14), (u32) (0), (void *) (*(u32 *) (iVar1 + 0x14)), (u32) (*(u32 *) (iVar1 + 0x10))));
    iVar1 = *(int *) (*((int *) ((u32) (&data_ov001_021ca400))) + param_1 + 0x58);
    ((u32) func_02016468((u32) (0x18), (u32) (0), (void *) (iVar1 + 0xc), (u32) (*(u32 *) (iVar1 + 8))));
    iVar1 = *(int *) (*((int *) ((u32) (&data_ov001_021ca400))) + param_1 + 0x60);
    ((u32) func_02016468((u32) (0x1f), (u32) (0), (void *) (*(u32 *) (iVar1 + 0xc)), (u32) (*(u32 *) (iVar1 + 8))));
    return;
}

void func_ov001_0219e5a0(void) {
    *((u16 *) 0x04000008u) = *((u16 *) 0x04000008u) & 0x43 | (u16) ((u32) 0x00001f80u);
    func_ov001_0219e5d4((int) (1));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021ca400))) + 0x18) = 1;
    return;
}
