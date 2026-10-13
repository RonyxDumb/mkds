/* Decompiled C draft; module arm7; ROM address 0380146c. No matching claim. */
#include "types.h"
#include "deps/0380146c_FUN_0380146c.h"

void FUN_0380146c(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_r4;
  
  uVar2 = param_1 & 0x70;
  if (0x30 < uVar2) {
    if (uVar2 < 0x51) {
      if ((0x4f < uVar2) || (uVar2 == 0x40)) {
        unaff_r4 = 9;
      }
    }
    else {
      if (uVar2 < 0x61) {
        if (uVar2 != 0x60) goto LAB_03801504;
      }
      else if (uVar2 != 0x70) goto LAB_03801504;
      unaff_r4 = 8;
    }
    goto LAB_03801504;
  }
  if (uVar2 < 0x30) {
    if (uVar2 < 0x11) {
      if ((0xf < uVar2) || (uVar2 == 0)) {
        unaff_r4 = 6;
      }
      goto LAB_03801504;
    }
    if (uVar2 != 0x20) goto LAB_03801504;
  }
  unaff_r4 = 4;
LAB_03801504:
  do {
    iVar1 = FUN_037fb5f4(unaff_r4,(param_1 & 0xff | 0x80) << 8 | 0x3000000 | param_2 & 0xff,0);
  } while (iVar1 < 0);
  return;
}

