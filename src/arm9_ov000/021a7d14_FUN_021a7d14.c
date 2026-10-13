/* Decompiled C draft; module arm9_ov000; ROM address 021a7d14. No matching claim. */
#include "types.h"
#include "deps/021a7d14_FUN_021a7d14.h"

void FUN_021a7d14(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x73) == '\x04') {
    FUN_021a7bc8();
    return;
  }
  iVar1 = FUN_021a7c4c();
  if ((iVar1 == -6) && (param_6 == 1)) {
    FUN_021a7bc8(param_1,param_2,param_3,param_4,param_5);
  }
  return;
}

