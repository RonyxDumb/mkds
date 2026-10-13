/* Decompiled C draft; module arm9; ROM address 020d655c. No matching claim. */
#include "types.h"
#include "deps/020d655c_func_020d655c.h"

void func_020d655c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_40 [3];
  undefined1 auStack_34 [12];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int local_1c;
  int local_18;
  int local_14;
  
  iVar3 = IsRaceOptionMenuOn_from_thumb();
  if (iVar3 == 0) {
    local_28 = *(undefined4 *)(param_2 + 0x28);
    uStack_24 = *(undefined4 *)(param_2 + 0x2c);
    uStack_20 = *(undefined4 *)(param_2 + 0x30);
    local_1c = *(int *)(param_2 + 0x34);
    local_18 = *(int *)(param_2 + 0x38);
    local_14 = *(int *)(param_2 + 0x3c);
    uVar1 = param_2 + 0x18U & 3;
    uVar6 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
    uVar5 = param_2 + 0x118U & 3;
    uVar4 = *(uint *)(param_2 + 0x118U & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) *
            (longlong)(int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
    local_40[0] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    uVar1 = param_2 + 0x10U & 3;
    uVar6 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
    uVar5 = param_2 + 0x118U & 3;
    uVar4 = *(uint *)(param_2 + 0x118U & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) *
            (longlong)(int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
    local_40[1] = 0;
    local_40[2] = -((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
    Vector3_Cross((uint)(uintptr_t)(local_40),(uint)(uintptr_t)(&local_28),(uint *)(void *)(auStack_34));
    VecFx32_Add((uint)(uintptr_t)(&local_28),(uint)(uintptr_t)(auStack_34),&local_28);
    Vector3_MaybeNormalize((uint)(uintptr_t)(&local_28),(int *)(uintptr_t)(param_2 + 0x28));
    Vector3_Cross((uint)(uintptr_t)(local_40),(uint)(uintptr_t)(&local_1c),(uint *)(void *)(auStack_34));
    VecFx32_Add((uint)(uintptr_t)(&local_1c),(uint)(uintptr_t)(auStack_34),&local_1c);
    iVar3 = Vector3_DotProduct(param_2 + 0x28,(uint)(uintptr_t)(&local_1c));
    uVar1 = param_2 + 0x28U & 3;
    uVar5 = *(uint *)(param_2 + 0x28U & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) * (longlong)iVar3;
    local_1c = local_1c - ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
    uVar1 = param_2 + 0x2cU & 3;
    uVar5 = *(uint *)(param_2 + 0x2cU & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) * (longlong)iVar3;
    local_18 = local_18 - ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
    uVar1 = param_2 + 0x30U & 3;
    uVar5 = *(uint *)(param_2 + 0x30U & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) * (longlong)iVar3;
    local_14 = local_14 - ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
    Vector3_MaybeNormalize((uint)(uintptr_t)(&local_1c),(int *)(uintptr_t)(param_2 + 0x34));
    Vector3_Cross(param_2 + 0x28,param_2 + 0x34,(uint *)(uintptr_t)(param_2 + 0x40));
  }
  uVar5 = uRam020d6730;
  uVar1 = param_2 + 4U & 3;
  uVar4 = *(uint *)(param_2 + 4U & 0xfffffffc);
  *(int *)(param_2 + 0x4c) = (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 8U & 3;
  uVar4 = *(uint *)(param_2 + 8U & 0xfffffffc);
  *(int *)(param_2 + 0x50) = (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 0xcU & 3;
  uVar4 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  *(int *)(param_2 + 0x54) = (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  func_020ea8a8(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20,param_2 + 0x28,param_2 + 0x1c,
                param_4);
  uVar5 = uRam020d6734;
  uVar1 = param_2 + 4U & 3;
  uVar4 = *(uint *)(param_2 + 4U & 0xfffffffc);
  uVar6 = *(uint *)(uRam020d6734 & 0xfffffffc) >> (uRam020d6734 & 3) * 8 |
          *(uint *)(uRam020d6734 & 0xfffffffc) << (uRam020d6734 & 3) * -8 + 0x20;
  *(int *)(uVar6 + 0x50) = (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) >> 4;
  uVar4 = uRam020d6738;
  uVar1 = param_2 + 8U & 3;
  uVar7 = *(uint *)(param_2 + 8U & 0xfffffffc);
  *(int *)(uVar6 + 0x54) = (int)(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 0xcU & 3;
  uVar7 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  *(int *)(uVar6 + 0x58) = (int)(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = uVar5 & 3;
  uVar6 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  func_020ea868(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20,
                (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 0x2c,param_2 + 0x1c,param_4);
  return;
}

