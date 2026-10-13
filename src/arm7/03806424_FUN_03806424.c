/* Decompiled C draft; module arm7; ROM address 03806424. No matching claim. */
#include "types.h"
#include "deps/03806424_FUN_03806424.h"

undefined4 FUN_03806424(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_037faf70();
  iVar2 = FUN_03806650(DAT_038064cc);
  if (iVar2 == 0) {
    if (*DAT_038064d0 == '\x03') {
      *DAT_038064d0 = '\x04';
      FUN_037faf84(uVar1);
      FUN_037fb6c0(10,DAT_038064d4);
      FUN_037f92d0(DAT_038064cc,DAT_038064d8,0,DAT_038064dc,0x400,2);
      FUN_037f9054(DAT_038064cc);
      uVar1 = 1;
    }
    else {
      FUN_037faf84(uVar1);
      uVar1 = 0;
    }
  }
  else {
    FUN_037faf84(uVar1);
    uVar1 = 0;
  }
  return uVar1;
}

