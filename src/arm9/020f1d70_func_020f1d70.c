/* Decompiled C draft; module arm9; ROM address 020f1d70. No matching claim. */
#include "types.h"
#include "deps/020f1d70_func_020f1d70.h"

void func_020f1d70(int param_1,uint param_2)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int local_20;
  int local_1c;
  int local_18;
  
  *(uint *)(param_1 + 0x130) =
       *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
       *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  uVar5 = param_2 + 8 & 3;
  uVar3 = *(uint *)(param_2 + 8 & 0xfffffffc);
  *(uint *)(param_1 + 0x138) = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  iVar2 = Vector3_DotProduct(param_1 + 0xf0);
  uVar5 = param_1 + 0xf0U & 3;
  uVar3 = *(uint *)(param_1 + 0xf0U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) * (longlong)iVar2;
  local_20 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
             *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) -
             ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  uVar5 = param_1 + 0xf4U & 3;
  uVar4 = *(uint *)(param_1 + 0xf4U & 0xfffffffc);
  uVar3 = param_2 + 4 & 3;
  uVar6 = *(uint *)(param_2 + 4 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) * (longlong)iVar2;
  local_1c = (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) -
             ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  uVar5 = param_1 + 0xf8U & 3;
  uVar4 = *(uint *)(param_1 + 0xf8U & 0xfffffffc);
  uVar3 = param_2 + 8 & 3;
  uVar6 = *(uint *)(param_2 + 8 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) * (longlong)iVar2;
  local_18 = (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) -
             ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  uVar5 = param_1 + 0xf0U & 3;
  uVar3 = *(uint *)(param_1 + 0xf0U & 0xfffffffc);
  *(int *)(param_1 + 0x13c) = (int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) >> 2;
  uVar5 = param_1 + 0xf4U & 3;
  uVar3 = *(uint *)(param_1 + 0xf4U & 0xfffffffc);
  *(int *)(param_1 + 0x140) = (int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) >> 2;
  uVar5 = param_1 + 0xf8U & 3;
  uVar3 = *(uint *)(param_1 + 0xf8U & 0xfffffffc);
  *(int *)(param_1 + 0x144) = (int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) >> 2;
  VecFx32_Subtract((uint)(uintptr_t)(&local_20),param_1 + 0x13c,(int *)(uintptr_t)(param_1 + 0x13c));
  uVar5 = param_1 + 0x140U & 3;
  uVar3 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
  uVar4 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + 0x13cU & 3;
  uVar3 = *(uint *)(param_1 + 0x13cU & 0xfffffffc);
  uVar3 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + 0x144U & 3;
  uVar6 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
  uVar5 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar5 * (longlong)(int)uVar5 +
          (longlong)(int)uVar3 * (longlong)(int)uVar3 + (longlong)(int)uVar4 * (longlong)(int)uVar4;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize(param_1 + 0x13c,(int *)(uintptr_t)(param_1 + 0x13c));
  }
  uVar5 = param_1 + 300U & 3;
  uVar3 = *(uint *)(param_1 + 300U & 0xfffffffc);
  uVar4 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + 0x13cU & 3;
  uVar3 = *(uint *)(param_1 + 0x13cU & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) * (longlong)(int)uVar4;
  *(uint *)(param_1 + 0x5c) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar5 = param_1 + 0x144U & 3;
  uVar3 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) * (longlong)(int)uVar4;
  *(uint *)(param_1 + 100) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  Vector3_Cross(param_2,param_1 + 0xf0,(uint *)(uintptr_t)(param_1 + 0x148));
  return;
}

