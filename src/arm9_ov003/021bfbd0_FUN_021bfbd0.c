/* Decompiled C draft; module arm9_ov003; ROM address 021bfbd0. No matching claim. */
#include "types.h"
#include "deps/021bfbd0_FUN_021bfbd0.h"

void FUN_021bfbd0(undefined4 param_1)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(*DAT_021bfc18 + 0x90);
  uVar1 = (*puVar2 & 0xff) + 0xc;
  FUN_021c0154(*(undefined1 *)(*DAT_021bfc18 + DAT_021bfc20),2,uVar1,puVar2,
               (*puVar2 & DAT_021bfc1c) >> 0x10);
  if (0xbf < uVar1) {
    FUN_021d34e0(param_1,DAT_021bfc24);
  }
  return;
}

