/* Decompiled C draft; module arm9_ov000; ROM address 021aa468. No matching claim. */
#include "types.h"
#include "deps/021aa468_FUN_021aa468.h"

void FUN_021aa468(int *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined1 auStack_38 [40];
  
  iVar1 = (int)param_1 + DAT_021aa4fc;
  if (*(byte *)((int)param_1 + DAT_021aa500) == param_3) {
    FUN_021abca0(iVar1,DAT_021aa508,4);
  }
  else {
    FUN_021abca0(iVar1,DAT_021aa504,4);
  }
  FUN_021abca0(iVar1,*param_1 + 0x20,0x30);
  func_0x0214d168(auStack_38,0x36,0x28);
  FUN_021abca0(iVar1,auStack_38,0x28);
  FUN_021abc4c(iVar1,param_2);
  FUN_021abd2c(iVar1);
  FUN_021abca0(iVar1,*param_1 + 0x20,0x30);
  func_0x0214d168(auStack_38,0x5c,0x28);
  FUN_021abca0(iVar1,auStack_38,0x28);
  FUN_021abca0(iVar1,param_2,0x14);
  FUN_021abc4c(iVar1,param_2);
  return;
}

