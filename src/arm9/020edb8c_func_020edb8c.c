/* Decompiled C draft; module arm9; ROM address 020edb8c. No matching claim. */
#include "types.h"
#include "deps/020edb8c_func_020edb8c.h"

int func_020edb8c(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_20;
  uint local_1c;
  uint local_18;
  
  iVar2 = VecFx32_Norm(param_1 + 0x6c);
  uVar5 = param_1 + 0x80U & 3;
  uVar3 = *(uint *)(param_1 + 0x80U & 0xfffffffc);
  if (uVar3 >> uVar5 * 8 == 0 && uVar3 << uVar5 * -8 + 0x20 == 0) {
    uVar5 = param_1 + 0x44U & 3;
    uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    local_20 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
    uVar5 = param_1 + 0x48U & 3;
    uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    local_1c = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
    uVar5 = param_1 + 0x4cU & 3;
    uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    local_18 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
    uVar5 = (uint)((longlong)iVar2 * (longlong)param_3) >> 0xc |
            (int)((ulonglong)((longlong)iVar2 * (longlong)param_3) >> 0x20) << 0x14;
  }
  else {
    uVar3 = param_1 + 0x10U & 3;
    uVar4 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    uVar5 = -iVar2;
    VecFx32_Subtract(param_1 + 0x6c,(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0x1fc,
                     &local_20);
    VecFx32_AddScale1(param_4,param_1 + 0x44,(uint)(uintptr_t)(&local_20),&local_20);
  }
  local_18 = -local_18;
  local_1c = -local_1c;
  local_20 = -local_20;
  uVar3 = param_1 + 0x10U & 3;
  uVar4 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar3 = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0x48;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 1) == 0) {
    local_1c = 0;
  }
  lVar1 = (longlong)(int)local_18 * (longlong)(int)local_18 +
          (longlong)(int)local_20 * (longlong)(int)local_20 +
          (longlong)(int)local_1c * (longlong)(int)local_1c;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize((uint)(uintptr_t)(&local_20),(int *)(uintptr_t)(param_5));
  }
  return param_2 + uVar5;
}

