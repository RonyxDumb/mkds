/* Decompiled C draft; module arm9_ov003; ROM address 021cfd88. No matching claim. */
#include "types.h"
#include "deps/021cfd88_FUN_021cfd88.h"

undefined4 FUN_021cfd88(void)

{
  int iVar1;
  
  FUN_021d07b0(3);
  iVar1 = func_0x02143e10(*DAT_021cfdc0 + 0x80,DAT_021cfdc4,2);
  if (iVar1 != 2) {
    FUN_021d079c();
    FUN_021d07b0(10);
    return 0;
  }
  return 1;
}

