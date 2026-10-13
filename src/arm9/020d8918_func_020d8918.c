/* Decompiled C draft; module arm9; ROM address 020d8918. No matching claim. */
#include "types.h"
#include "deps/020d8918_func_020d8918.h"

void func_020d8918(uint param_1,uint *param_2,uint *param_3)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar2 = param_1 + 0xc & 3;
  uVar3 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  iVar5 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) * 0x54;
  uVar3 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar2 = param_1 + 0x14 & 3;
  uVar7 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  uVar8 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar7 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  iVar4 = 0x1000000 - uVar8;
  uVar2 = uVar7 + iVar5;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  iVar5 = uVar7 + iVar5;
  lVar1 = (longlong)(int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * (longlong)iVar4;
  *param_2 = (uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8;
  uVar2 = iVar5 + 4U & 3;
  uVar3 = *(uint *)(iVar5 + 4U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) * (longlong)iVar4;
  param_2[1] = (uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8;
  uVar2 = iVar5 + 8U & 3;
  uVar3 = *(uint *)(iVar5 + 8U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) * (longlong)iVar4;
  param_2[2] = (uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8;
  uVar2 = iVar5 + 0x24U & 3;
  uVar3 = *(uint *)(iVar5 + 0x24U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) * (longlong)(int)uVar8;
  *param_2 = (*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
             *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) +
             ((uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8);
  uVar2 = iVar5 + 0x28U & 3;
  uVar7 = *(uint *)(iVar5 + 0x28U & 0xfffffffc);
  uVar3 = (uint)(param_2 + 1) & 3;
  uVar6 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) * (longlong)(int)uVar8;
  param_2[1] = (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) +
               ((uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8);
  uVar2 = iVar5 + 0x2cU & 3;
  uVar7 = *(uint *)(iVar5 + 0x2cU & 0xfffffffc);
  uVar3 = (uint)(param_2 + 2) & 3;
  uVar6 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) * (longlong)(int)uVar8;
  param_2[2] = (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) +
               ((uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8);
  VecFx32_Subtract(iVar5 + 0x24,iVar5);
  uVar2 = param_1 + 0x10 & 3;
  uVar3 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  uVar7 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  lVar1 = (longlong)
          (int)(*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
               *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20) *
          (longlong)(int)uVar7;
  *param_3 = (uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8;
  uVar2 = (uint)(param_3 + 1) & 3;
  uVar3 = *(uint *)((uint)(param_3 + 1) & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) * (longlong)(int)uVar7;
  param_3[1] = (uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8;
  uVar2 = (uint)(param_3 + 2) & 3;
  uVar3 = *(uint *)((uint)(param_3 + 2) & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) * (longlong)(int)uVar7;
  param_3[2] = (uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8;
  uVar2 = param_1 + 0x18 & 3;
  uVar3 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
  if (uVar3 >> uVar2 * 8 == 0 && uVar3 << uVar2 * -8 + 0x20 == 0) {
    *param_3 = -(*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
                *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20);
    uVar2 = (uint)(param_3 + 1) & 3;
    uVar3 = *(uint *)((uint)(param_3 + 1) & 0xfffffffc);
    param_3[1] = -(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    uVar2 = (uint)(param_3 + 2) & 3;
    uVar3 = *(uint *)((uint)(param_3 + 2) & 0xfffffffc);
    param_3[2] = -(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    return;
  }
  return;
}

