/* Decompiled C draft; module arm9_ov003; ROM address 021bfc28. No matching claim. */
#include "types.h"
#include "deps/021bfc28_FUN_021bfc28.h"

void FUN_021bfc28(undefined4 param_1)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(*DAT_021bfc70 + 0xc0);
  uVar1 = (*puVar2 & 0xff) + 0xc;
  FUN_021c0154(*(undefined1 *)(*DAT_021bfc70 + DAT_021bfc78),3,uVar1,puVar2,
               (*puVar2 & DAT_021bfc74) >> 0x10);
  if (0xbf < uVar1) {
    FUN_021d34e0(param_1,DAT_021bfc7c);
  }
  return;
}

