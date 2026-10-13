/* Decompiled C draft; module arm9_ov000; ROM address 021a9c5c. No matching claim. */
#include "types.h"
#include "deps/021a9c5c_FUN_021a9c5c.h"

void FUN_021a9c5c(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 auStack_70 [96];
  
  FUN_021abd2c(auStack_70);
  uVar1 = func_0x0200fca0();
  FUN_021abca0(auStack_70,DAT_021a9ca0,0x14);
  FUN_021abca0(auStack_70,param_1,param_2);
  FUN_021abc4c(auStack_70,DAT_021a9ca0);
  func_0x0200fcb4(uVar1);
  *DAT_021a9ca4 = 1;
  return;
}

