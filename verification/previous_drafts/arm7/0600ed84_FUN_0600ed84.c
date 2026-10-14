/* Decompiled C draft; module arm7; ROM address 0600ed84. No matching claim. */
#include "types.h"
#include "deps/0600ed84_FUN_0600ed84.h"

void FUN_0600ed84(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = *(uint *)(DAT_0600ede4 & 0xfffffffc) >> (DAT_0600ede4 & 3) * 8 |
          *(uint *)(DAT_0600ede4 & 0xfffffffc) << (DAT_0600ede4 & 3) * -8 + 0x20;
  uVar2 = thunk_FUN_037f8850(0x1000000);
  if (*(short *)(uVar1 + 0x1b4) == 0) {
    FUN_0600e748(0);
  }
  FUN_06009040(param_1,uVar1 + 0x1ac,param_2);
  thunk_FUN_037f888c(uVar2);
  return;
}

