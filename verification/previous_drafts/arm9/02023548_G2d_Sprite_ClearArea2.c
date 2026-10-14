/* Decompiled C draft; module arm9; ROM address 02023548. No matching claim. */
#include "types.h"
#include "deps/02023548_G2d_Sprite_ClearArea2.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void G2d_Sprite_ClearArea2
               (uint param_1,undefined4 param_2,uint param_3,uint param_4,int param_5,int param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined8 uVar16;
  uint local_64;
  
  bVar4 = *(byte *)(param_1 + 0xc);
  uVar8 = param_3 & 0xfffffff8;
  local_64 = param_4 & 0xfffffff8;
  uVar12 = param_4 + param_6 + 7 & 0xfffffff8;
  iVar1 = (int)(uVar8 + ((uint)((int)uVar8 >> 2) >> 0x1d)) >> 3;
  iVar14 = (int)(local_64 + ((uint)((int)local_64 >> 2) >> 0x1d)) >> 3;
  uVar2 = param_1 + 4 & 3;
  uVar9 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar3 = param_1 + 8 & 3;
  uVar10 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar7 = *(uint *)(param_1 & 0xfffffffc);
  if ((int)uVar12 <= (int)local_64) {
    return;
  }
  do {
    iVar5 = iVar1;
    uVar6 = uVar8;
    if ((int)local_64 < (int)param_4) {
      iVar15 = param_4 - local_64;
    }
    else {
      iVar15 = 0;
    }
    for (; (int)uVar6 < (int)(param_3 + param_5 + 7 & 0xfffffff8); uVar6 = uVar6 + 8) {
      uVar16 = func_02024184(iVar5,iVar14,uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20,
                             uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20);
      iVar11 = (int)((ulonglong)uVar16 >> 0x20);
      if ((int)uVar6 < (int)param_3) {
        iVar11 = param_3 - uVar6;
      }
      iVar13 = (param_3 + param_5) - uVar6;
      if ((int)param_3 <= (int)uVar6) {
        iVar11 = 0;
      }
      if (8 < iVar13) {
        iVar13 = 8;
      }
      func_02024000(((int)((uint)bVar4 * 0x40) >> 3) * (int)uVar16 +
                    (uVar7 >> (param_1 & 3) * 8 | uVar7 << (param_1 & 3) * -8 + 0x20),iVar11,iVar15,
                    iVar13 - iVar11);
      iVar5 = iVar5 + 1;
    }
    iVar14 = iVar14 + 1;
    local_64 = local_64 + 8;
  } while ((int)local_64 < (int)uVar12);
  return;
}

