/* Decompiled C draft; module arm9; ROM address 02147288. No matching claim. */
#include "types.h"
#include "deps/02147288_func_02147288.h"

void func_02147288(uint param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar4;
  uint uVar10;
  
  uVar1 = param_1 + 4 & 3;
  uVar9 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar10 = uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 0xc & 3;
  uVar6 = *(uint *)(param_2 + 0xc & 0xfffffffc);
  uVar5 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar9 = param_1 + 8 & 3;
  uVar3 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar4 = uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20;
  uVar9 = param_2 + 0x18 & 3;
  uVar3 = *(uint *)(param_2 + 0x18 & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20) * (longlong)(int)uVar4 +
          (longlong)
          (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
               *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) * (longlong)(int)uVar5
          + (longlong)(int)uVar10 * (longlong)(int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20)
  ;
  *param_3 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = param_2 + 0x24 & 3;
  uVar9 = *(uint *)(param_2 + 0x24 & 0xfffffffc);
  *param_3 = (*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
             *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20) +
             (uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20);
  uVar1 = param_2 + 0x10 & 3;
  uVar6 = *(uint *)(param_2 + 0x10 & 0xfffffffc);
  uVar9 = param_2 + 4 & 3;
  uVar8 = *(uint *)(param_2 + 4 & 0xfffffffc);
  uVar3 = param_2 + 0x1c & 3;
  uVar7 = *(uint *)(param_2 + 0x1c & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) * (longlong)(int)uVar4 +
          (longlong)(int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) * (longlong)(int)uVar5 +
          (longlong)(int)uVar10 * (longlong)(int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
  param_3[1] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = (uint)(param_3 + 1) & 3;
  uVar6 = *(uint *)((uint)(param_3 + 1) & 0xfffffffc);
  uVar9 = param_2 + 0x28 & 3;
  uVar3 = *(uint *)(param_2 + 0x28 & 0xfffffffc);
  param_3[1] = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) +
               (uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20);
  uVar1 = param_2 + 0x14 & 3;
  uVar8 = *(uint *)(param_2 + 0x14 & 0xfffffffc);
  uVar9 = param_2 + 8 & 3;
  uVar7 = *(uint *)(param_2 + 8 & 0xfffffffc);
  uVar3 = param_2 + 0x20 & 3;
  uVar6 = *(uint *)(param_2 + 0x20 & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) * (longlong)(int)uVar4 +
          (longlong)(int)(uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) * (longlong)(int)uVar5 +
          (longlong)(int)uVar10 * (longlong)(int)(uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20);
  param_3[2] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = (uint)(param_3 + 2) & 3;
  uVar4 = *(uint *)((uint)(param_3 + 2) & 0xfffffffc);
  uVar9 = param_2 + 0x2c & 3;
  uVar3 = *(uint *)(param_2 + 0x2c & 0xfffffffc);
  param_3[2] = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) +
               (uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20);
  return;
}

