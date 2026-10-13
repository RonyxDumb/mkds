/* Decompiled C draft; module arm9; ROM address 020edc9c. No matching claim. */
#include "types.h"
#include "deps/020edc9c_func_020edc9c.h"

int func_020edc9c(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar7;
  int local_28;
  int local_24;
  int local_20;
  uint uVar6;
  
  iVar2 = VecFx32_Norm(param_1 + 0x6c);
  uVar3 = param_1 + 0x80U & 3;
  uVar4 = *(uint *)(param_1 + 0x80U & 0xfffffffc);
  if (uVar4 >> uVar3 * 8 == 0 && uVar4 << uVar3 * -8 + 0x20 == 0) {
    uVar3 = param_1 + 0x10U & 3;
    uVar4 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
    uVar3 = uVar4 + 0x200 & 3;
    uVar5 = *(uint *)(uVar4 + 0x200 & 0xfffffffc);
    uVar6 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    uVar3 = uVar4 + 0x1fc & 3;
    uVar5 = *(uint *)(uVar4 + 0x1fc & 0xfffffffc);
    uVar5 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    uVar3 = uVar4 + 0x204 & 3;
    uVar7 = *(uint *)(uVar4 + 0x204 & 0xfffffffc);
    uVar3 = uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20;
    lVar1 = (longlong)(int)uVar3 * (longlong)(int)uVar3 +
            (longlong)(int)uVar5 * (longlong)(int)uVar5 +
            (longlong)(int)uVar6 * (longlong)(int)uVar6;
    if ((int)((ulonglong)lVar1 >> 0x20) < (int)(uint)((uint)lVar1 < 0x10)) {
      param_2 = param_2 - iVar2;
      local_28 = *(int *)(param_1 + 0x44);
      local_24 = *(int *)(param_1 + 0x48);
      local_20 = *(int *)(param_1 + 0x4c);
    }
    else {
      param_2 = param_2 + ((uint)((longlong)iVar2 * (longlong)param_3) >> 0xc |
                          (int)((ulonglong)((longlong)iVar2 * (longlong)param_3) >> 0x20) << 0x14);
      VecFx32_AddScale1(param_4,param_1 + 0x44,uVar4 + 0x1fc,&local_28);
    }
  }
  else {
    param_2 = param_2 + ((uint)((longlong)iVar2 * (longlong)param_3) >> 0xc |
                        (int)((ulonglong)((longlong)iVar2 * (longlong)param_3) >> 0x20) << 0x14);
    VecFx32_AddScale1(param_4,param_1 + 0x44,param_1 + 0x6c,&local_28);
  }
  uVar3 = param_1 + 0x10U & 3;
  uVar4 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar3 = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0x48;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 1) == 0) {
    local_24 = 0;
  }
  lVar1 = (longlong)local_20 * (longlong)local_20 +
          (longlong)local_28 * (longlong)local_28 + (longlong)local_24 * (longlong)local_24;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize((uint)(uintptr_t)(&local_28),(int *)(uintptr_t)(param_5));
  }
  return param_2;
}

