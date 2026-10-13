/* Decompiled C draft; module arm9_ov000; ROM address 021a8ad0. No matching claim. */
#include "types.h"
#include "deps/021a8ad0_FUN_021a8ad0.h"

void FUN_021a8ad0(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_021a8ab8();
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *(undefined4 *)(param_2 + 0x7c);
  }
  return;
}

