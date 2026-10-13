/* Decompiled C draft; module arm9; ROM address 0211e2f8. No matching claim. */
#include "types.h"
#include "deps/0211e2f8_func_0211e2f8.h"

void func_0211e2f8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_20 [20];
  
  switch(param_1) {
  case 0:
    iVar2 = *(int *)*DAT_0211e384;
    iVar1 = GetCourseIdFromInternalId(((int *)*DAT_0211e384)[3]);
    func_020616c0(iVar2 + iVar1 * 0x30,(undefined4)(uintptr_t)(auStack_20));
    break;
  case 1:
    func_020616c0(*(int *)(*DAT_0211e384 + 4) +
                  DAT_0211e388 * ((int)*(short *)(*DAT_0211e384 + 0x10) & 0xffU),(undefined4)(uintptr_t)(auStack_20));
    break;
  case 2:
    iVar2 = *(int *)(*DAT_0211e384 + 8);
    iVar1 = GetCourseIdFromInternalId(*(undefined4 *)(*DAT_0211e384 + 0xc));
    func_020616c0(iVar2 + DAT_0211e388 * iVar1,(undefined4)(uintptr_t)(auStack_20));
  }
  Mem_CpuFill8((uint *)(uintptr_t)(param_2),0,0x20);
  CopyMemory16((int)(uintptr_t)(auStack_20),param_2,0x14);
  return;
}

