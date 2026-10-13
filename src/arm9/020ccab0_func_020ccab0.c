/* Decompiled C draft; module arm9; ROM address 020ccab0. No matching claim. */
#include "types.h"
#include "deps/020ccab0_func_020ccab0.h"

void func_020ccab0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  
  uVar6 = 0;
  do {
    iVar1 = GetGlobalCA_from_thumb();
    if ((*(int *)(iVar1 + 0xc0) == 0) &&
       (iVar1 = GetGlobalCA_from_thumb(), *(int *)(iVar1 + uVar6 * 0x18 + 8) == 1)) {
      func_020ccb48(uVar6);
    }
    else {
      iVar1 = GetGlobalCA_from_thumb();
      uVar7 = 0xffffffff;
      if (*(int *)(iVar1 + 0xdc) != 0) {
        iVar1 = GetGlobalCA_from_thumb();
        uVar7 = *(undefined4 *)(iVar1 + uVar6 * 0x18 + 0xc);
      }
      iVar5 = uVar6 * 0x18;
      iVar1 = GetGlobalCA_from_thumb();
      iVar2 = GetGlobalCA_from_thumb();
      iVar3 = GetGlobalCA_from_thumb();
      iVar4 = GetGlobalCA_from_thumb();
      StructCO_ConfigureRacerDefault
                (uVar6,*(undefined4 *)(iVar1 + iVar5),*(undefined4 *)(iVar2 + iVar5 + 4),
                 *(undefined4 *)(iVar3 + iVar5 + 8),uVar7,*(undefined4 *)(iVar4 + iVar5 + 0x10));
    }
    uVar6 = uVar6 + 1 & 0xff;
  } while (uVar6 < 8);
  return;
}

