/* Decompiled C draft; module arm9; ROM address 02082d64. No matching claim. */
#include "types.h"
#include "deps/02082d64_func_02082d64.h"

void func_02082d64(int param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  uint uVar14;
  bool bVar15;
  int iVar4;
  uint uVar6;
  uint uVar13;
  
  bVar2 = *(byte *)(param_1 + 0x9a);
  uVar13 = param_1 + 0x94U & 3;
  uVar12 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  uVar13 = uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20;
  bVar15 = bVar2 == 0;
  if (bVar15) {
    bVar2 = *(byte *)(param_1 + 0x98);
  }
  bVar1 = true;
  if (!bVar15) {
    bVar2 = *(byte *)(param_1 + 0x99);
  }
  bVar3 = bVar2;
  if ((8 < *(byte *)(param_1 + 0x99)) && (bVar3 = *(byte *)(param_1 + 0x98), 8 < bVar2)) {
    bVar1 = false;
  }
  iVar4 = GetDriverEntry(bVar3);
  uVar12 = param_1 + 0x20U & 3;
  uVar5 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar6 = uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20;
  uVar5 = iVar4 + 0x1d8U & 3;
  uVar11 = *(uint *)(iVar4 + 0x1d8U & 0xfffffffc);
  uVar12 = uVar6 & 3;
  uVar7 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = iVar4 + 0x1dcU & 3;
  uVar14 = *(uint *)(iVar4 + 0x1dcU & 0xfffffffc);
  uVar12 = (uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) + 4;
  uVar7 = uVar12 & 3;
  uVar12 = *(uint *)(uVar12 & 0xfffffffc);
  uVar9 = iVar4 + 0x1e0U & 3;
  uVar8 = *(uint *)(iVar4 + 0x1e0U & 0xfffffffc);
  *(uint *)(param_1 + 0x28) =
       (uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20) +
       ((int)(uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20) >> 4);
  uVar7 = uRam02082e48;
  uVar12 = param_1 + 0x20U & 3;
  uVar5 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar5 = uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20;
  uVar12 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar12 = (uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20) + 8;
  uVar5 = uVar12 & 3;
  uVar12 = *(uint *)(uVar12 & 0xfffffffc);
  *(uint *)(param_1 + 0x2c) =
       (uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20) +
       ((int)(uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20) >> 4);
  uVar12 = param_1 + 0x20U & 3;
  uVar5 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar5 = uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20;
  uVar12 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar12 = (uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20) + 0xc;
  uVar5 = uVar12 & 3;
  uVar12 = *(uint *)(uVar12 & 0xfffffffc);
  *(uint *)(param_1 + 0x30) =
       (uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20) +
       ((int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) >> 4);
  uVar12 = iVar4 + 0x7cU & 3;
  uVar6 = *(uint *)(iVar4 + 0x7cU & 0xfffffffc);
  uVar5 = param_1 + 0x24U & 3;
  uVar9 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  if (((uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20) & uVar7) != 0) {
    bVar1 = false;
  }
  *(uint *)(param_1 + 0x24) =
       (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) & 0xfffffff7 | (uint)!bVar1 << 3;
  puVar10 = (uint *)(param_1 + 0x24);
  if (0x31 < uVar13 + 1) {
    *puVar10 = (*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
               *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) &
               0xfffffffe | 1;
  }
  *(uint *)(param_1 + 0x94) = uVar13 + 1;
  return;
}

