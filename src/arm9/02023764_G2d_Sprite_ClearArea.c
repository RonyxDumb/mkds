/* Decompiled C draft; module arm9; ROM address 02023764. No matching claim. */
#include "types.h"
#include "deps/02023764_G2d_Sprite_ClearArea.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void G2d_Sprite_ClearArea
               (uint param_1,undefined4 param_2,uint param_3,uint param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int extraout_r1;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint local_4c;
  int local_3c;
  
  param_6 = param_4 + param_6;
  local_4c = param_4 & 0xfffffff8;
  uVar4 = param_1 + 0x10 & 3;
  uVar7 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  uVar7 = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
  uVar8 = param_3 & 0xfffffff8;
  iVar1 = (int)((uint)*(byte *)(param_1 + 0xc) * 0x40) >> 3;
  local_3c = iVar1 * (((int)(local_4c + ((uint)((int)local_4c >> 2) >> 0x1d)) >> 3) * uVar7 +
                     ((int)(uVar8 + ((uint)((int)uVar8 >> 2) >> 0x1d)) >> 3)) +
             (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
             *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20);
  uVar4 = param_6 + 7U & 0xfffffff8;
  if ((int)uVar4 <= (int)local_4c) {
    return;
  }
  do {
    iVar2 = local_3c;
    iVar6 = param_6;
    uVar3 = uVar8;
    if ((int)local_4c < (int)param_4) {
      iVar9 = param_4 - local_4c;
    }
    else {
      iVar9 = 0;
    }
    for (; (int)uVar3 < (int)(param_3 + param_5 + 7 & 0xfffffff8); uVar3 = uVar3 + 8) {
      if ((int)uVar3 < (int)param_3) {
        iVar6 = param_3 - uVar3;
      }
      iVar5 = (param_3 + param_5) - uVar3;
      if ((int)param_3 <= (int)uVar3) {
        iVar6 = 0;
      }
      if (8 < iVar5) {
        iVar5 = 8;
      }
      func_02024000(iVar2,iVar6,iVar9,iVar5 - iVar6);
      iVar2 = iVar2 + iVar1;
      iVar6 = extraout_r1;
    }
    local_3c = local_3c + uVar7 * iVar1;
    local_4c = local_4c + 8;
  } while ((int)local_4c < (int)uVar4);
  return;
}

