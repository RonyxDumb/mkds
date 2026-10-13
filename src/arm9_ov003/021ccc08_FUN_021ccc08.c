/* Decompiled C draft; module arm9_ov003; ROM address 021ccc08. No matching claim. */
#include "types.h"
#include "deps/021ccc08_FUN_021ccc08.h"

void FUN_021ccc08(int param_1)

{
  undefined1 uVar1;
  
  *(char *)(*DAT_021ccc20 + 0x1c) = (char)param_1;
  if (param_1 == 2) {
    uVar1 = 4;
  }
  else {
    uVar1 = 6;
  }
  *(undefined1 *)(*DAT_021ccc20 + 0x1d) = uVar1;
  return;
}

