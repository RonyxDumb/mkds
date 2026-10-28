#include "Main/Unknown/code_02036438.h"

#pragma thumb on

void func_02036438(void *heap) {
    u32 uVar1;
    int iVar2;
    int iVar3;
    uVar1 = (u32) func_02036948(heap);
    iVar2 = ((u32) func_02036bec((void *) (uVar1), (u32) (((u32) 0x00000654u))));
    *(int *) &data_02174e6c = iVar2;
    func_02036264((u32) (iVar2), (u32) (((u32) 0x00000654u)));
    *(u32 *) ((*(int *) &data_02174e6c) + ((int) 0x00000650u)) = uVar1;
    func_020364a8((int) (0), (int) (0), (int) (0x10), (int) (0), (int) (0));
    iVar2 = ((u32) func_020d1630());
    iVar3 = *(int *) (iVar2 + 0x24);
    iVar2 = ((u32) func_020d1630());
    iVar2 = *(int *) (iVar2 + 0x28);
    func_0214b9c4((const void *) (*(u32 *) (iVar3 + 0x14)), (int) (0), (u32) (*(u32 *) (iVar3 + 0x10)));
    func_0214b824((const void *) (*(u32 *) (iVar3 + 0x14)), (int) (0), (u32) (*(u32 *) (iVar3 + 0x10)));
    func_0214c0f8((const void *) (*(u32 *) (iVar2 + 0xc)), (int) (0), (u32) (*(u32 *) (iVar2 + 8)));
    return;
}

#pragma thumb off
