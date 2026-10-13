/* Decompiled C draft; module arm9_ov000; ROM address 021a3bbc. No matching claim. */
#include "types.h"
#include "deps/021a3bbc_FUN_021a3bbc.h"

void FUN_021a3bbc(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *local_818 [2];
  undefined1 auStack_810 [2056];
  
  *(undefined4 *)((int)local_818 + DAT_021a3c10) = 0;
  FUN_021a4480(auStack_810,8,param_1 + 0x21);
  local_818[0] = param_1 + 0x33;
  local_818[1] = (undefined4 *)0x8;
  FUN_0218e3e4(*param_1,auStack_810,*(undefined4 *)((int)local_818 + DAT_021a3c10),0);
  uVar1 = FUN_0218e8c4();
  param_1[0x2c] = uVar1;
  return;
}

