/* Decompiled C draft; module arm9_ov003; ROM address 021bf620. No matching claim. */
#include "types.h"
#include "deps/021bf620_FUN_021bf620.h"

void FUN_021bf620(undefined4 param_1,code *param_2)

{
  undefined4 uVar1;
  undefined4 local_10;
  
  uVar1 = FUN_021bf650();
  uVar1 = FUN_021d14b8(uVar1,&local_10,4);
  func_0x0200ee74(uVar1,local_10);
  (*param_2)(uVar1,0,local_10);
  FUN_021d1490(uVar1);
  return;
}

