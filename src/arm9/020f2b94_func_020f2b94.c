/* Decompiled C draft; module arm9; ROM address 020f2b94. No matching claim. */
#include "types.h"
#include "deps/020f2b94_func_020f2b94.h"

void func_020f2b94(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                  undefined4 param_6)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  
  if (param_4 == 0) {
    uVar4 = func_020edb8c(param_2,0x3000,0x1000,0x4000,param_1 + 0x130);
    *(undefined4 *)(param_1 + 300) = uVar4;
  }
  else {
    uVar4 = func_020edc9c(param_2,param_6,0x1000,0x3800,param_1 + 0x130);
    *(undefined4 *)(param_1 + 300) = uVar4;
  }
  *(undefined4 *)(param_1 + 0x13c) = *(undefined4 *)(param_1 + 0x130);
  *(undefined4 *)(param_1 + 0x140) = *(undefined4 *)(param_1 + 0x134);
  *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(param_1 + 0x138);
  uVar6 = param_1 + 0x138U & 3;
  uVar8 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
  uVar9 = param_1 + 0x130U & 3;
  uVar5 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
  *(uint *)(param_1 + 0x150) = uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20;
  *(uint *)(param_1 + 0x148) = -(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20);
  *(undefined4 *)(param_1 + 0x14c) = 0;
  uVar6 = param_1 + 0x130U & 3;
  uVar8 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
  uVar9 = param_1 + 300U & 3;
  uVar5 = *(uint *)(param_1 + 300U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) *
          (longlong)(int)(uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20);
  *(uint *)(param_1 + 0x5c) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar6 = param_1 + 0x138U & 3;
  uVar8 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
  uVar9 = param_1 + 300U & 3;
  uVar5 = *(uint *)(param_1 + 300U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) *
          (longlong)(int)(uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20);
  *(uint *)(param_1 + 100) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  if (param_4 == 0) {
    uVar6 = param_2 + 0x10U & 3;
    uVar9 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
    VecFx32_Add(param_1 + 0x5c,(uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) + 0x1fc,
                (int *)(uintptr_t)(param_1 + 0x5c));
  }
  uVar6 = param_2 + 0x10U & 3;
  uVar9 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
  uVar6 = (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) + 0x48;
  uVar9 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if (((uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) & 1) != 0) {
    iVar7 = Vector3_DotProduct(param_2 + 0x38,param_1 + 0x5c);
    uVar6 = param_2 + 0x38U & 3;
    uVar5 = *(uint *)(param_2 + 0x38U & 0xfffffffc);
    uVar9 = param_2 + 0x3cU & 3;
    uVar8 = *(uint *)(param_2 + 0x3cU & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) * (longlong)iVar7;
    lVar2 = (longlong)(int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) * (longlong)iVar7;
    uVar6 = param_2 + 0x40U & 3;
    uVar9 = *(uint *)(param_2 + 0x40U & 0xfffffffc);
    lVar3 = (longlong)(int)(uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) * (longlong)iVar7;
    uVar6 = param_1 + 0x5cU & 3;
    uVar9 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
    *(uint *)(param_1 + 0x5c) =
         (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) -
         ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    uVar6 = param_1 + 0x60U & 3;
    uVar9 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
    *(uint *)(param_1 + 0x60) =
         (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) -
         ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
    uVar6 = param_1 + 100U & 3;
    uVar9 = *(uint *)(param_1 + 100U & 0xfffffffc);
    *(uint *)(param_1 + 100) =
         (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) -
         ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14);
    VecFx32_AddScale1(0xfffff000,param_2 + 0x38,param_1 + 0x5c,(int *)(uintptr_t)(param_1 + 0x5c));
  }
  iVar7 = iRam020f2d90;
  uVar6 = param_1 + 0x70U & 3;
  uVar9 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
  if ((int)(uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) < iRam020f2d90) {
    *(int *)(param_1 + 0x68) = iRam020f2d90;
    *(int *)(param_1 + 0x6c) = iVar7;
    *(int *)(param_1 + 0x70) = iVar7;
    if (param_4 != 0) {
      uVar6 = param_2 + 0x10U & 3;
      uVar9 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
      uVar6 = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
      uVar4 = *(undefined4 *)(uVar6 + 0x1bc);
      uVar10 = *(undefined4 *)(uVar6 + 0x1c0);
      *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(uVar6 + 0x1b8);
      *(undefined4 *)(param_1 + 0x54) = uVar4;
      *(undefined4 *)(param_1 + 0x58) = uVar10;
      uVar6 = param_1 + 0x70U & 3;
      uVar9 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
      VecFx32_AddScale1((uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) * 10,param_2 + 0x44,
                        (undefined4 *)(param_1 + 0x50));
    }
  }
  if (param_3 < 0) {
    *(undefined4 *)(param_1 + 0x154) = 0;
    *(undefined4 *)(param_1 + 0x15c) = 0;
  }
  else {
    *(int *)(param_1 + 0x154) = param_3;
    *(undefined4 *)(param_1 + 0x15c) = 1;
  }
  *(undefined4 *)(param_1 + 0x124) = uRam020f2d94;
  *(undefined4 *)(param_1 + 0x160) = 1;
  *(undefined4 *)(param_1 + 0x158) = param_5;
  *(undefined2 *)(param_1 + 0x164) = 4;
  return;
}

