/* Decompiled C draft; module arm9_ov000; ROM address 021ad2b8. No matching claim. */
#include "types.h"
#include "deps/021ad2b8_FUN_021ad2b8.h"

undefined4 FUN_021ad2b8(uint *param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  FUN_021ae270();
  FUN_021ae2d8();
  if (param_2 == 1) {
    FUN_021ae290(0x44,0x43,*DAT_021ad360);
  }
  else {
    FUN_021ae290(0x44,0x43,0xffffffff);
  }
  iVar6 = 0;
  do {
    uVar3 = FUN_021ad620(param_2);
    iVar4 = FUN_021ad3b8(uVar3,iVar6);
    if (iVar4 != 0) break;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 4);
  FUN_021ae258();
  puVar2 = DAT_021ad368;
  puVar1 = DAT_021ad364;
  if (iVar4 != 2) {
    uVar5 = *DAT_021ad368 >> 1;
    *DAT_021ad368 = uVar5;
    *param_1 = uVar5;
    if (param_2 == 1) {
      if (uVar5 < 0x3c) {
        *param_1 = 1;
        *puVar2 = *DAT_021ad364 >> 3;
      }
    }
    else if ((param_2 == 2) && (uVar5 < 0x3c)) {
      *param_1 = 1;
    }
    return 0;
  }
  *param_1 = *DAT_021ad364 >> 1;
  *DAT_021ad368 = *puVar1 * 3 >> 3;
  return 1;
}

