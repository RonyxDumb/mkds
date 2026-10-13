/* Decompiled C draft; module arm9_ov003; ROM address 021bfb28. No matching claim. */
#include "types.h"
#include "deps/021bfb28_FUN_021bfb28.h"

void FUN_021bfb28(undefined4 param_1)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(*DAT_021bfb6c + 0x30);
  uVar1 = (*puVar2 & 0xff) + 0xc;
  FUN_021c0154(*(undefined1 *)(*DAT_021bfb6c + DAT_021bfb74),0,uVar1,puVar2,
               (*puVar2 & DAT_021bfb70) >> 0x10);
  if (0xbf < uVar1) {
    FUN_021d34e0(param_1,DAT_021bfb78);
  }
  return;
}

