/* Decompiled C draft; module arm9_ov003; ROM address 021bfc80. No matching claim. */
#include "types.h"
#include "deps/021bfc80_FUN_021bfc80.h"

void FUN_021bfc80(undefined4 param_1)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)FUN_021d1974(*(undefined4 *)(*DAT_021bfcd0 + 0xfc),0);
  uVar2 = *puVar1;
  FUN_021c0154(*(undefined1 *)(*DAT_021bfcd0 + DAT_021bfcd8),4);
  if (0xbf < (uVar2 & 0xff) + 0xc) {
    FUN_021d34e0(param_1,DAT_021bfcdc);
  }
  return;
}

