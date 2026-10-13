/* Decompiled C draft; module arm9_ov003; ROM address 021c118c. No matching claim. */
#include "types.h"
#include "deps/021c118c_FUN_021c118c.h"

void FUN_021c118c(undefined4 param_1)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)FUN_021d1974(*(undefined4 *)(*DAT_021c11d0 + 0x40),0);
  uVar2 = *puVar1;
  FUN_021c1364(4);
  if (0xbf < (uVar2 & 0xff) + 0xc) {
    FUN_021d34e0(param_1,DAT_021c11d8);
  }
  return;
}

