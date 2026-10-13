/* Decompiled C draft; module arm9; ROM address 02023bcc. No matching claim. */
#include "types.h"
#include "deps/02023bcc_G2d_Sprite_DrawGlyph.h"

void G2d_Sprite_DrawGlyph
               (uint param_1,uint param_2,uint param_3,uint param_4,undefined4 param_5,uint param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint unaff_r11;
  int iVar10;
  uint in_r12;
  int *piVar11;
  undefined1 auStack_50 [44];
  uint uVar9;
  
  uVar4 = (uint)*(byte *)((*(uint *)(param_6 & 0xfffffffc) >> (param_6 & 3) * 8 |
                          *(uint *)(param_6 & 0xfffffffc) << (param_6 & 3) * -8 + 0x20) + 1);
  uVar7 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 8;
  uVar3 = uVar7 & 3;
  uVar5 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = param_1 + 4 & 3;
  uVar8 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar9 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
  uVar7 = param_1 + 8 & 3;
  uVar8 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
  uVar8 = *(uint *)(param_1 & 0xfffffffc);
  iVar1 = (int)((uint)*(byte *)(param_1 + 0xc) * 0x40) >> 3;
  piVar11 = (int *)auStack_50;
  if (uVar4 == 0) {
    piVar11 = (int *)&stack0xffffffdc;
  }
  uVar3 = (uint)*(byte *)((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 1);
  if (uVar4 == 0) {
    return;
  }
  if ((int)(param_3 + uVar4) < 0) {
    return;
  }
  iVar2 = param_4 + uVar3;
  if (iVar2 < 0) {
    return;
  }
  if ((int)param_3 < 1) {
    unaff_r11 = 0;
  }
  if (0 < (int)param_3) {
    unaff_r11 = param_3 >> 3;
  }
  if ((int)param_4 < 1) {
    in_r12 = 0;
  }
  uVar5 = param_3 + uVar4 + 7 >> 3;
  if (0 < (int)param_4) {
    in_r12 = param_4 >> 3;
  }
  if (uVar9 <= uVar5) {
    uVar5 = uVar9;
  }
  uVar9 = iVar2 + 7U >> 3;
  if (uVar7 <= uVar9) {
    uVar9 = uVar7;
  }
  iVar2 = uVar5 - unaff_r11;
  if (iVar2 < 0) {
    piVar11 = (int *)((int)piVar11 + 0x2c);
  }
  if (iVar2 < 0) {
    return;
  }
  if ((int)(uVar9 - in_r12) < 0) {
    return;
  }
  uVar7 = param_1 + 0x10 & 3;
  uVar5 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  uVar7 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
  if (-1 < (int)param_3) {
    param_3 = param_3 & 7;
  }
  *piVar11 = iVar1 * (uVar7 - iVar2);
  iVar6 = iVar1 * (uVar7 * in_r12 + unaff_r11) +
          (uVar8 >> (param_1 & 3) * 8 | uVar8 << (param_1 & 3) * -8 + 0x20);
  uVar7 = piVar11[0x15] + 4U & 3;
  uVar5 = *(uint *)(piVar11[0x15] + 4U & 0xfffffffc);
  if (-1 < (int)param_4) {
    param_4 = param_4 & 7;
  }
  iVar10 = param_4 + (uVar9 - in_r12) * -8;
  piVar11[2] = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
  piVar11[5] = uVar4;
  piVar11[10] = piVar11[0x14] + -1;
  piVar11[6] = uVar3;
  uVar7 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 8;
  uVar3 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar4 = (uint)*(byte *)((uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + 6);
  piVar11[8] = uVar4;
  piVar11[9] = (uint)*(byte *)(param_1 + 0xc);
  uVar7 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 8;
  uVar3 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  piVar11[7] = uVar4 * *(byte *)(uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20);
  if ((int)param_4 <= iVar10) {
    return;
  }
  do {
    piVar11[4] = param_4;
    for (uVar7 = param_3; (int)(param_3 + iVar2 * -8) < (int)uVar7; uVar7 = uVar7 - 8) {
      piVar11[1] = iVar6;
      piVar11[3] = uVar7;
      StructCL_SomeFn((uint)(uintptr_t)(piVar11 + 1));
      iVar6 = iVar6 + iVar1;
    }
    param_4 = param_4 - 8;
    iVar6 = iVar6 + *piVar11;
  } while (iVar10 < (int)param_4);
  return;
}

