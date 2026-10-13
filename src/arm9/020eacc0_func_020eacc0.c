/* Decompiled C draft; module arm9; ROM address 020eacc0. No matching claim. */
#include "types.h"
#include "deps/020eacc0_func_020eacc0.h"

void func_020eacc0(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint local_20;
  uint local_1c;
  uint local_18;
  
  iVar3 = VecFx32_CrossProduct_0(param_1,param_3);
  lVar2 = (longlong)(iVar3 + 0x1000) * (longlong)param_2;
  uVar6 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  if (0x1000 < (int)uVar6) {
    uVar6 = 0x1000;
  }
  lVar2 = (longlong)(int)uVar6 * (longlong)(int)(0x1000 - uVar6);
  lVar2 = (longlong)(0x1000 - iVar3) *
          (longlong)((int)((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14) >> 1);
  uVar5 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  iVar3 = (0x1000 - uVar6) + uVar5;
  lVar2 = (longlong)
          (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) * (longlong)iVar3;
  local_20 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = param_1 + 4 & 3;
  uVar4 = *(uint *)(param_1 + 4 & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) * (longlong)iVar3;
  local_1c = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = param_1 + 8 & 3;
  uVar4 = *(uint *)(param_1 + 8 & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) * (longlong)iVar3;
  local_18 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  VecFx32_AddScale1(uVar6 + uVar5,param_3,(uint)(uintptr_t)(&local_20),(int *)(uintptr_t)(param_4));
  return;
}

