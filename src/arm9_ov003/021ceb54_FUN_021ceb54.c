/* Decompiled C draft; module arm9_ov003; ROM address 021ceb54. No matching claim. */
#include "types.h"
#include "deps/021ceb54_FUN_021ceb54.h"

void FUN_021ceb54(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = DAT_021ceb78;
  *(char *)(*DAT_021ceb78 + 0x1d) = *(char *)(*DAT_021ceb78 + 0x1d) + '\x01';
  if (7 < *(byte *)(*piVar1 + 0x1d)) {
    FUN_021d34e0(param_1,DAT_021ceb7c);
  }
  return;
}

