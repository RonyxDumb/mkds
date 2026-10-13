/* Decompiled C draft; module arm9_ov000; ROM address 0219cb00. No matching claim. */
#include "types.h"
#include "deps/0219cb00_FUN_0219cb00.h"

void FUN_0219cb00(void)

{
  int iVar1;
  
  iVar1 = *(int *)(*DAT_0219cb28 + 0x20);
  if (iVar1 == 0) {
    FUN_0219d734(0xb,DAT_0219cb2c);
    return;
  }
  *(int *)(*DAT_0219cb28 + 0x20) = iVar1 + -1;
  return;
}

