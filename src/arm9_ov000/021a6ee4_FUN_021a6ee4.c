/* Decompiled C draft; module arm9_ov000; ROM address 021a6ee4. No matching claim. */
#include "types.h"
#include "deps/021a6ee4_FUN_021a6ee4.h"

undefined4 FUN_021a6ee4(int param_1)

{
  undefined4 uVar1;
  
  func_0x02000b44(DAT_021a6f10);
  if (*DAT_021a6f14 != 0) {
    return 0;
  }
  *DAT_021a6f14 = param_1;
  FUN_021a6db0();
  uVar1 = FUN_021a6eb4();
  return uVar1;
}

