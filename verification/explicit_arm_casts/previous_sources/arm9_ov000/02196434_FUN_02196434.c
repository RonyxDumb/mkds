/* Decompiled C draft; module arm9_ov000; ROM address 02196434. No matching claim. */
#include "types.h"
#include "deps/02196434_FUN_02196434.h"

void FUN_02196434(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 auStack_5c [64];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [8];
  
  iVar1 = FUN_021967b4(param_4,DAT_02196478,auStack_5c,0x40);
  if (iVar1 != 0) {
    iVar1 = func_0x02138510(auStack_5c,DAT_0219647c,auStack_1c,auStack_18,auStack_14);
    if (iVar1 == 3) {
      FUN_02196480(param_1,auStack_1c,param_2,2,0);
    }
  }
  return;
}

