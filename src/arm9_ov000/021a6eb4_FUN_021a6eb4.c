/* Decompiled C draft; module arm9_ov000; ROM address 021a6eb4. No matching claim. */
#include "types.h"
#include "deps/021a6eb4_FUN_021a6eb4.h"

int FUN_021a6eb4(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_021a70ec(*(undefined4 *)(*DAT_021a6ed8 + 0x20));
  if (-1 < iVar1) {
    uVar2 = FUN_021a73d8(DAT_021a6edc);
    *DAT_021a6ee0 = uVar2;
  }
  return iVar1;
}

