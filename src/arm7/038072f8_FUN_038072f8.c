/* Decompiled C draft; module arm7; ROM address 038072f8. No matching claim. */
#include "types.h"
#include "deps/038072f8_FUN_038072f8.h"

uint FUN_038072f8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int extraout_r1;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = param_1 & DAT_03807420 & 0xffff;
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    for (uVar4 = 0; ((int)uVar4 < 0x10 && ((uVar1 & 1 << (uVar4 & 0xff)) == 0)); uVar4 = uVar4 + 1)
    {
    }
    for (uVar5 = 0xf; (uVar5 != 0 && ((uVar1 & 1 << (uVar5 & 0xff)) == 0)); uVar5 = uVar5 - 1) {
    }
    if ((int)(uVar5 - uVar4) < 5) {
      uVar1 = 1 << (uVar4 & 0xff) & 0xffff;
    }
    else {
      uVar2 = FUN_03806b2c(uVar5 + uVar4,2);
      for (iVar3 = 0; iVar3 < (int)(uVar5 - uVar4); iVar3 = iVar3 + 1) {
        FUN_03806b2c(iVar3,2);
        uVar2 = iVar3 * (extraout_r1 * 2 + -1) + uVar2;
        if ((uVar1 & 1 << (uVar2 & 0xff)) != 0) break;
      }
      if (((int)(uVar5 - uVar2) < 5) || ((int)(uVar2 - uVar4) < 5)) {
        uVar1 = (1 << (uVar4 & 0xff) | 1 << (uVar5 & 0xff)) & 0xffff;
      }
      else {
        uVar1 = (1 << (uVar5 & 0xff) | 1 << (uVar2 & 0xff) | 1 << (uVar4 & 0xff)) & 0xffff;
      }
    }
  }
  return uVar1;
}

