/* Decompiled C draft; module arm9; ROM address 020eb3f0. No matching claim. */
#include "types.h"
#include "deps/020eb3f0_func_020eb3f0.h"

void func_020eb3f0(undefined4 param_1,undefined4 param_2,int param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  uint uVar4;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint uVar3;
  uint uVar5;
  
  VecFx32_Subtract(param_1,param_2,(int *)(uintptr_t)(param_4));
  uVar5 = param_4 + 4 & 3;
  uVar2 = *(uint *)(param_4 + 4 & 0xfffffffc);
  uVar3 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
  uVar2 = *(uint *)(param_4 & 0xfffffffc) >> (param_4 & 3) * 8 |
          *(uint *)(param_4 & 0xfffffffc) << (param_4 & 3) * -8 + 0x20;
  uVar5 = param_4 + 8 & 3;
  uVar4 = *(uint *)(param_4 + 8 & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar5 * (longlong)(int)uVar5 +
          (longlong)(int)uVar2 * (longlong)(int)uVar2 + (longlong)(int)uVar3 * (longlong)(int)uVar3;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize(param_4,&local_20);
  }
  local_20 = (uint)((longlong)(int)local_20 * (longlong)param_3) >> 0xc |
             (int)((ulonglong)((longlong)(int)local_20 * (longlong)param_3) >> 0x20) << 0x14;
  local_18 = (uint)((longlong)(int)local_18 * (longlong)param_3) >> 0xc |
             (int)((ulonglong)((longlong)(int)local_18 * (longlong)param_3) >> 0x20) << 0x14;
  local_1c = (uint)((longlong)(int)local_1c * (longlong)param_3) >> 0xc |
             (int)((ulonglong)((longlong)(int)local_1c * (longlong)param_3) >> 0x20) << 0x14;
  VecFx32_Subtract((uint)(uintptr_t)(&local_20),param_4,(int *)(uintptr_t)(param_4));
  return;
}

