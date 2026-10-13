/* Decompiled C draft; module arm9_ov003; ROM address 021d0a88. No matching claim. */
#include "types.h"
#include "deps/021d0a88_FUN_021d0a88.h"

undefined4 FUN_021d0a88(void)

{
  int iVar1;
  
  iVar1 = FUN_021d010c();
  if (iVar1 == 1) {
    FUN_021cfa68();
    *(undefined1 *)(*DAT_021d0ab0 + DAT_021d0ab4) = 1;
    return 1;
  }
  return 0;
}

