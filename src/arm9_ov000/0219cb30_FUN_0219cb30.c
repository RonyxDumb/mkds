/* Decompiled C draft; module arm9_ov000; ROM address 0219cb30. No matching claim. */
#include "types.h"
#include "deps/0219cb30_FUN_0219cb30.h"

void FUN_0219cb30(void)

{
  int iVar1;
  
  iVar1 = *(int *)(*DAT_0219cb5c + 0x20);
  if (iVar1 == -1) {
    FUN_0219d734(0xb,DAT_0219cb60);
    return;
  }
  *(int *)(*DAT_0219cb5c + 0x20) = iVar1 + 1;
  return;
}

