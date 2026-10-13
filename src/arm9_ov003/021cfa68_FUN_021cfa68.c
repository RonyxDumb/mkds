/* Decompiled C draft; module arm9_ov003; ROM address 021cfa68. No matching claim. */
#include "types.h"
#include "deps/021cfa68_FUN_021cfa68.h"

undefined4 FUN_021cfa68(void)

{
  int iVar1;
  
  if (*(int *)(*DAT_021cfaa0 + 0x40) != 1) {
    func_0x0200fd1c();
  }
  FUN_021d07b0(3);
  iVar1 = func_0x02143d88(DAT_021cfaa4);
  if (iVar1 != 2) {
    FUN_021d07b0(9);
    return 0;
  }
  return 1;
}

