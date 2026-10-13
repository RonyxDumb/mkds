/* Decompiled C draft; module arm9_ov000; ROM address 021ae214. No matching claim. */
#include "types.h"
#include "deps/021ae214_FUN_021ae214.h"

void FUN_021ae214(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(DAT_021ae224 + 4) + 0xa4);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x38) = param_1;
  }
  return;
}

