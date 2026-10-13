/* Decompiled C draft; module arm9; ROM address 020dd0d8. No matching claim. */
#include "types.h"
#include "deps/020dd0d8_func_020dd0d8.h"

void func_020dd0d8(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  int *piVar14;
  uint uVar15;
  undefined4 *puVar10;
  
  uVar5 = uRam020dd1ec;
  *(undefined4 *)(param_1 + 0xe8) = uRam020dd1e8;
  *(undefined4 *)(param_1 + 0xec) = uVar5;
  uVar12 = param_1 + 0x1d8U & 3;
  uVar2 = *(uint *)(param_1 + 0x1d8U & 0xfffffffc);
  *(undefined4 *)((uVar2 >> uVar12 * 8 | uVar2 << uVar12 * -8 + 0x20) + 0xa8) = uRam020dd1f0;
  uVar2 = param_1 + 0x160U & 3;
  uVar13 = *(uint *)(param_1 + 0x160U & 0xfffffffc);
  *(undefined4 *)(param_1 + 0x160) = 0;
  uVar12 = param_1 + 0x164U & 3;
  uVar9 = *(uint *)(param_1 + 0x164U & 0xfffffffc);
  puVar10 = (undefined4 *)(uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20);
  uVar5 = *(undefined4 *)(param_1 + 8);
  uVar8 = *(undefined4 *)(param_1 + 0xc);
  *puVar10 = *(undefined4 *)(param_1 + 4);
  puVar10[1] = uVar5;
  puVar10[2] = uVar8;
  uVar12 = param_1 + 0x164U & 3;
  uVar9 = *(uint *)(param_1 + 0x164U & 0xfffffffc);
  puVar10 = (undefined4 *)(uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20);
  uVar12 = param_1 + 0x168U & 3;
  uVar9 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
  puVar11 = (undefined4 *)(uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20);
  uVar5 = puVar10[1];
  uVar8 = puVar10[2];
  *puVar11 = *puVar10;
  puVar11[1] = uVar5;
  puVar11[2] = uVar8;
  uVar12 = param_1 + 0x168U & 3;
  uVar9 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
  piVar14 = (int *)(uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20);
  uVar12 = param_1 + 0x40U & 3;
  uVar6 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar9 = param_1 + 0xf0U & 3;
  uVar3 = *(uint *)(param_1 + 0xf0U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20) *
          (longlong)(int)(uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20);
  *piVar14 = (*(uint *)((uint)piVar14 & 0xfffffffc) >> ((uint)piVar14 & 3) * 8 |
             *(uint *)((uint)piVar14 & 0xfffffffc) << ((uint)piVar14 & 3) * -8 + 0x20) +
             ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  uVar12 = param_1 + 0x168U & 3;
  uVar9 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
  uVar15 = uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20;
  uVar9 = param_1 + 0x48U & 3;
  uVar7 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  uVar3 = param_1 + 0xf0U & 3;
  uVar4 = *(uint *)(param_1 + 0xf0U & 0xfffffffc);
  uVar12 = uVar15 + 8;
  uVar6 = uVar12 & 3;
  uVar12 = *(uint *)(uVar12 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) *
          (longlong)(int)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
  *(uint *)(uVar15 + 8) =
       (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) +
       ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  uVar12 = param_1 + 0x168U & 3;
  uVar9 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
  puVar10 = (undefined4 *)(uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20);
  uVar12 = param_1 + 0x16cU & 3;
  uVar9 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
  puVar11 = (undefined4 *)(uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20);
  uVar5 = puVar10[1];
  uVar8 = puVar10[2];
  *puVar11 = *puVar10;
  puVar11[1] = uVar5;
  puVar11[2] = uVar8;
  uVar12 = param_1 + 0x16cU & 3;
  uVar9 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
  piVar14 = (int *)(uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20);
  uVar12 = param_1 + 0x28U & 3;
  uVar6 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  uVar9 = param_1 + 0xf0U & 3;
  uVar3 = *(uint *)(param_1 + 0xf0U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20) *
          (longlong)(int)(uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20);
  *piVar14 = (*(uint *)((uint)piVar14 & 0xfffffffc) >> ((uint)piVar14 & 3) * 8 |
             *(uint *)((uint)piVar14 & 0xfffffffc) << ((uint)piVar14 & 3) * -8 + 0x20) +
             ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  uVar12 = param_1 + 0x16cU & 3;
  uVar9 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
  uVar7 = uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20;
  uVar9 = param_1 + 0x30U & 3;
  uVar4 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
  uVar12 = uVar7 + 8;
  uVar3 = uVar12 & 3;
  uVar15 = *(uint *)(uVar12 & 0xfffffffc);
  uVar12 = param_1 + 0xf0U & 3;
  uVar6 = *(uint *)(param_1 + 0xf0U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) *
          (longlong)(int)(uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20);
  *(uint *)(uVar7 + 8) =
       (uVar15 >> uVar3 * 8 | uVar15 << uVar3 * -8 + 0x20) +
       ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  func_020d7d18(param_1 + 0x100,1,param_1 + 0x160,0x1000);
  *(uint *)(param_1 + 0x160) = uVar13 >> uVar2 * 8 | uVar13 << uVar2 * -8 + 0x20;
  return;
}

