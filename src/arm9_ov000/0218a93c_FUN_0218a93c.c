/* Decompiled C draft; module arm9_ov000; ROM address 0218a93c. No matching claim. */
#include "types.h"
#include "deps/0218a93c_FUN_0218a93c.h"

void FUN_0218a93c(int param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  if (iVar1 < 0x14) {
    *(int *)(param_1 + 0x40) = iVar1 + 1;
    *(undefined1 *)(param_1 + iVar1 + 0x2c) = param_2;
  }
  return;
}

