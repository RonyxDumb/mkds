/* Decompiled C draft; module arm9; ROM address 020d91dc. No matching claim. */
#include "types.h"
#include "deps/020d91dc_func_020d91dc.h"

void func_020d91dc(int param_1,int param_2,int param_3)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  func_020d9810(param_2,&local_20,&local_1c,&local_18,&local_14);
  func_020d94dc(param_1,(uint *)(uintptr_t)(param_3),local_20,local_1c,local_18,local_14);
  uVar1 = param_1 + 4U & 3;
  uVar4 = *(uint *)(param_1 + 4U & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) *
          (longlong)(0x1000000 - param_2);
  *(uint *)(param_3 + 4) = (uint)lVar2 >> 0x18 | (int)((ulonglong)lVar2 >> 0x20) << 8;
  uVar1 = param_1 + 0x28U & 3;
  uVar3 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  uVar4 = param_3 + 4U & 3;
  uVar5 = *(uint *)(param_3 + 4U & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * (longlong)param_2;
  *(uint *)(param_3 + 4) =
       (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
       ((uint)lVar2 >> 0x18 | (int)((ulonglong)lVar2 >> 0x20) << 8);
  return;
}

