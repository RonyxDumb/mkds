/* Decompiled C draft; module arm9_ov000; ROM address 021ab594. No matching claim. */
#include "types.h"
#include "deps/021ab594_FUN_021ab594.h"

void FUN_021ab594(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(DAT_021ab5b0 + 4) + 0xa4);
  if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0xc), iVar1 != 0)) {
    *(undefined4 *)(iVar1 + DAT_021ab5b4) = param_1;
    *(undefined4 *)(iVar1 + DAT_021ab5b8) = param_2;
  }
  return;
}

