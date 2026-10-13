/* Decompiled C draft; module arm9; ROM address 01ffccd0. No matching claim. */
#include "types.h"
#include "deps/01ffccd0_func_01ffccd0.h"

void func_01ffccd0(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar12;
  uint uVar13;
  uint uVar11;
  
  uVar9 = param_2 + 4 & 3;
  uVar10 = *(uint *)(param_2 + 4 & 0xfffffffc);
  uVar11 = uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20;
  uVar9 = param_2 + 8 & 3;
  uVar10 = *(uint *)(param_2 + 8 & 0xfffffffc);
  uVar13 = uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20;
  uVar12 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
           *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  uVar9 = param_2 + 0xc & 3;
  uVar10 = *(uint *)(param_2 + 0xc & 0xfffffffc);
  uVar9 = uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20;
  iVar1 = (int)(uVar11 * uVar11) >> 0xb;
  iVar2 = (int)(uVar13 * uVar13) >> 0xb;
  iVar3 = (int)(uVar12 * uVar12) >> 0xb;
  iVar4 = (int)(uVar12 * uVar11) >> 0xb;
  iVar5 = (int)(uVar12 * uVar13) >> 0xb;
  iVar6 = (int)(uVar11 * uVar13) >> 0xb;
  *param_1 = 0x1000 - (iVar1 + iVar2);
  iVar7 = (int)(uVar9 * uVar13) >> 0xb;
  param_1[1] = iVar4 + iVar7;
  iVar8 = (int)(uVar9 * uVar11) >> 0xb;
  param_1[2] = iVar5 - iVar8;
  param_1[3] = iVar4 - iVar7;
  param_1[4] = 0x1000 - (iVar2 + iVar3);
  iVar2 = (int)(uVar9 * uVar12) >> 0xb;
  param_1[5] = iVar6 + iVar2;
  param_1[6] = iVar5 + iVar8;
  param_1[7] = iVar6 - iVar2;
  param_1[8] = 0x1000 - (iVar3 + iVar1);
  return;
}

