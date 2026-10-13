/* Decompiled C draft; module arm9_ov000; ROM address 021ae228. No matching claim. */
#include "types.h"
#include "deps/021ae228_FUN_021ae228.h"

void FUN_021ae228(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_021ae314();
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  *(undefined1 *)(param_1 + 8) = 1;
  *(undefined4 *)(param_1 + 4) = 1;
  func_0x0200e01c(0);
  return;
}

