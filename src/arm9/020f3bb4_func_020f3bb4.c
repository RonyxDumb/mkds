/* Decompiled C draft; module arm9; ROM address 020f3bb4. No matching claim. */
#include "types.h"
#include "deps/020f3bb4_func_020f3bb4.h"

bool func_020f3bb4(uint param_1,uint param_2,uint *param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar13;
  uint uVar14;
  uint uVar12;
  uint uVar15;
  
  uVar13 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
           *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  uVar14 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x18;
  uVar11 = uVar14 & 3;
  uVar14 = *(uint *)(uVar14 & 0xfffffffc);
  uVar15 = uVar14 >> uVar11 * 8 | uVar14 << uVar11 * -8 + 0x20;
  uVar14 = uVar13 + 0x18;
  uVar11 = uVar14 & 3;
  uVar14 = *(uint *)(uVar14 & 0xfffffffc);
  uVar8 = uVar14 >> uVar11 * 8 | uVar14 << uVar11 * -8 + 0x20;
  uVar14 = param_4 + 4 & 3;
  uVar11 = *(uint *)(param_4 + 4 & 0xfffffffc);
  uVar12 = uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20;
  uVar14 = uVar15 + 4 & 3;
  uVar10 = *(uint *)(uVar15 + 4 & 0xfffffffc);
  uVar11 = uVar8 + 4 & 3;
  uVar9 = *(uint *)(uVar8 + 4 & 0xfffffffc);
  iVar2 = (int)((uVar10 >> uVar14 * 8 | uVar10 << uVar14 * -8 + 0x20) - uVar12) >> 0xc;
  iVar3 = (int)((uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) - uVar12) >> 0xc;
  uVar14 = *(uint *)(param_4 & 0xfffffffc) >> (param_4 & 3) * 8 |
           *(uint *)(param_4 & 0xfffffffc) << (param_4 & 3) * -8 + 0x20;
  iVar4 = (int)((*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
                *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) - uVar14) >> 0xc;
  iVar5 = (int)((*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) - uVar14) >> 0xc;
  uVar14 = param_4 + 8 & 3;
  uVar11 = *(uint *)(param_4 + 8 & 0xfffffffc);
  uVar10 = uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20;
  uVar14 = uVar15 + 8 & 3;
  uVar9 = *(uint *)(uVar15 + 8 & 0xfffffffc);
  uVar11 = uVar8 + 8 & 3;
  uVar8 = *(uint *)(uVar8 + 8 & 0xfffffffc);
  iVar6 = (int)((uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20) - uVar10) >> 0xc;
  iVar7 = (int)((uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) - uVar10) >> 0xc;
  bVar1 = iVar7 * iVar7 + iVar5 * iVar5 + iVar3 * iVar3 <
          iVar6 * iVar6 + iVar4 * iVar4 + iVar2 * iVar2;
  if (bVar1) {
    uVar14 = param_2 + 4 & 3;
    uVar11 = *(uint *)(param_2 + 4 & 0xfffffffc);
    *param_3 = uVar13;
    param_3[1] = uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20;
  }
  return bVar1;
}

