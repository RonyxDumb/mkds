/* Decompiled C draft; module arm9_ov003; ROM address 021bfb7c. No matching claim. */
#include "types.h"
#include "deps/021bfb7c_FUN_021bfb7c.h"

void FUN_021bfb7c(undefined4 param_1)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(*DAT_021bfbc0 + 0x60);
  uVar1 = (*puVar2 & 0xff) + 0xc;
  FUN_021c0154(*(undefined1 *)(*DAT_021bfbc0 + DAT_021bfbc8),1,uVar1,puVar2,
               (*puVar2 & DAT_021bfbc4) >> 0x10);
  if (0xbf < uVar1) {
    FUN_021d34e0(param_1,DAT_021bfbcc);
  }
  return;
}

