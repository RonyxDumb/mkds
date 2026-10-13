/* Decompiled C draft; module arm9; ROM address 020244f4. No matching claim. */
#include "types.h"
#include "deps/020244f4_G2d_Text_PutChars.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void G2d_Text_PutChars(uint param_1,int param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 *param_6)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar5;
  uint uVar7;
  undefined4 local_28;
  code *pcVar4;
  uint uVar6;
  
  uVar1 = param_1 + 8 & 3;
  uVar7 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar3 = param_1 + 4 & 3;
  uVar5 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar6 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  local_28 = param_5;
  uVar3 = uVar6 + 4;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  pcVar4 = (code *)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
  iVar2 = (*pcVar4)(&local_28);
  if (iVar2 != 0) {
    do {
      if (iVar2 == 10) break;
      iVar2 = G2d_Sprite_PutChar(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                                 *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,uVar6,
                                 param_2,param_3,param_4,iVar2);
      param_2 = param_2 + iVar2 + (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20);
      iVar2 = (*pcVar4)(&local_28);
    } while (iVar2 != 0);
  }
  if (param_6 != (undefined4 *)0x0) {
    if (iVar2 != 10) {
      local_28 = 0;
    }
    *param_6 = local_28;
    return;
  }
  return;
}

