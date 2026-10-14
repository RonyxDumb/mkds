/* Decompiled C draft; module arm9; ROM address 020239a8. No matching claim. */
#include "types.h"
#include "deps/020239a8_G2d_Sprite_DrawGlyph2.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void G2d_Sprite_DrawGlyph2
               (uint param_1,uint param_2,uint param_3,uint param_4,undefined4 param_5,uint param_6)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  undefined1 auStack_70 [8];
  uint local_68;
  uint local_64;
  uint uStack_60;
  byte abStack_50 [44];
  uint uVar10;
  
  puVar13 = (uint *)auStack_70;
  bVar1 = *(byte *)(param_1 + 0xc);
  uVar11 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
           *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 8;
  uVar9 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  uVar8 = (uint)*(byte *)((*(uint *)(param_6 & 0xfffffffc) >> (param_6 & 3) * 8 |
                          *(uint *)(param_6 & 0xfffffffc) << (param_6 & 3) * -8 + 0x20) + 1);
  uVar12 = (uint)*(byte *)((uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20) + 1);
  uVar11 = param_1 + 4 & 3;
  uVar9 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar10 = uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20;
  uVar11 = param_1 + 8 & 3;
  uVar9 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar11 = uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20;
  local_68 = param_3;
  local_64 = param_4;
  if (uVar8 == 0) {
    return;
  }
  if ((int)(param_3 + uVar8) < 0) {
    return;
  }
  iVar5 = param_4 + uVar12;
  if (iVar5 < 0) {
    return;
  }
  if ((int)param_3 < 1) {
    uStack_60 = 0;
  }
  else {
    uStack_60 = param_3 >> 3;
  }
  uVar9 = local_64;
  if ((int)param_4 < 1) {
    uVar9 = 0;
  }
  uVar7 = iVar5 + 7U >> 3;
  uVar6 = param_3 + uVar8 + 7 >> 3;
  if (0 < (int)param_4) {
    uVar9 = uVar9 >> 3;
  }
  if (uVar10 <= uVar6) {
    uVar6 = uVar10;
  }
  if (uVar11 <= uVar7) {
    uVar7 = uVar11;
  }
  iVar5 = uVar6 - uStack_60;
  if (iVar5 < 0) {
    puVar13 = (uint *)&stack0xffffffdc;
  }
  if (iVar5 < 0) {
    return;
  }
  if ((int)(uVar7 - uVar9) < 0) {
    return;
  }
  uVar11 = *(uint *)(param_1 & 0xfffffffc);
  if (-1 < (int)puVar13[2]) {
    puVar13[2] = puVar13[2] & 7;
  }
  uVar10 = puVar13[2];
  if (-1 < (int)puVar13[3]) {
    puVar13[3] = puVar13[3] & 7;
  }
  puVar13[5] = puVar13[3] + (uVar7 - uVar9) * -8;
  uVar7 = param_6 + 4 & 3;
  uVar6 = *(uint *)(param_6 + 4 & 0xfffffffc);
  puVar13[10] = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  puVar13[0x12] = puVar13[0x1c] - 1;
  puVar13[0xe] = uVar12;
  puVar13[0xd] = uVar8;
  uVar8 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 8;
  uVar12 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar7 = (uint)*(byte *)((uVar8 >> uVar12 * 8 | uVar8 << uVar12 * -8 + 0x20) + 6);
  puVar13[0x10] = uVar7;
  puVar13[0x11] = (uint)*(byte *)(param_1 + 0xc);
  uVar8 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 8;
  uVar12 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  puVar13[0xf] = uVar7 * *(byte *)(uVar8 >> uVar12 * 8 | uVar8 << uVar12 * -8 + 0x20);
  uVar8 = param_1 + 0x10 & 3;
  uVar12 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  puVar13[8] = uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20;
  uVar8 = param_1 + 4 & 3;
  uVar4 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar12 = param_1 + 8 & 3;
  uVar6 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar7 = puVar13[8];
  bVar2 = *(byte *)((int)puVar13 + 0x21);
  puVar13[7] = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
  puVar13[6] = uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20;
  if ((int)puVar13[3] <= (int)puVar13[5]) {
    return;
  }
  do {
    uVar8 = puVar13[4];
    puVar13[0xc] = puVar13[3];
    for (uVar12 = puVar13[2]; (int)(uVar10 + iVar5 * -8) < (int)uVar12; uVar12 = uVar12 - 8) {
      *puVar13 = (uint)(byte)uVar7;
      puVar13[1] = (uint)bVar2;
      iVar3 = func_02024184(uVar8,uVar9,puVar13[7],puVar13[6]);
      puVar13[0xb] = uVar12;
      puVar13[9] = iVar3 * ((int)((uint)bVar1 * 0x40) >> 3) +
                   (uVar11 >> (param_1 & 3) * 8 | uVar11 << (param_1 & 3) * -8 + 0x20);
      StructCL_SomeFn((uint)(uintptr_t)(puVar13 + 9));
      uVar8 = uVar8 + 1;
    }
    uVar8 = puVar13[3];
    uVar9 = uVar9 + 1;
    puVar13[3] = uVar8 - 8;
  } while ((int)puVar13[5] < (int)(uVar8 - 8));
  return;
}

