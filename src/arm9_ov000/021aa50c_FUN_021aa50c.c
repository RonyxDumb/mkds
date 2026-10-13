/* Decompiled C draft; module arm9_ov000; ROM address 021aa50c. No matching claim. */
#include "types.h"
#include "deps/021aa50c_FUN_021aa50c.h"

void FUN_021aa50c(int *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined1 auStack_40 [48];
  
  iVar1 = (int)param_1 + DAT_021aa5a0;
  if (*(byte *)((int)param_1 + DAT_021aa5a4) == param_3) {
    FUN_021ab728(iVar1,DAT_021aa5ac,4);
  }
  else {
    FUN_021ab728(iVar1,DAT_021aa5a8,4);
  }
  FUN_021ab728(iVar1,*param_1 + 0x20,0x30);
  func_0x0214d168((uint *)(void *)(auStack_40),0x36,0x30);
  FUN_021ab728(iVar1,(int)(uintptr_t)(auStack_40),0x30);
  FUN_021ab6d4(iVar1,param_2);
  FUN_021ab7b4((undefined4 *)(uintptr_t)(iVar1));
  FUN_021ab728(iVar1,*param_1 + 0x20,0x30);
  func_0x0214d168((uint *)(void *)(auStack_40),0x5c,0x30);
  FUN_021ab728(iVar1,(int)(uintptr_t)(auStack_40),0x30);
  FUN_021ab728(iVar1,param_2,0x10);
  FUN_021ab6d4(iVar1,param_2);
  return;
}

