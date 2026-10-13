/* Decompiled C draft; module arm9_ov003; ROM address 021d1cb0. No matching claim. */
#include "types.h"
#include "deps/021d1cb0_FUN_021d1cb0.h"

void FUN_021d1cb0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 auStack_10 [8];
  
  uVar1 = FUN_021d14b8(param_2,(uint *)(void *)(auStack_10),4);
  *(undefined4 *)(DAT_021d1cd0 + param_1 * 4) = uVar1;
  return;
}

