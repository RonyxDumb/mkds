/* Decompiled C draft; module arm7; ROM address 0380653c. No matching claim. */
#include "types.h"
#include "deps/0380653c_FUN_0380653c.h"

undefined4 FUN_0380653c(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_037faf70();
  iVar2 = FUN_03806650(DAT_038065d8);
  if (iVar2 == 0) {
    if (*DAT_038065dc == '\x01') {
      *DAT_038065dc = '\x02';
      FUN_037faf84(uVar1);
      FUN_037f92d0(DAT_038065d8,DAT_038065e0,0,DAT_038065e4,0x400,10);
      FUN_037f9054(DAT_038065d8);
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

