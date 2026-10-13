/* Decompiled C draft; module arm9_ov000; ROM address 021a7bc8. No matching claim. */
#include "types.h"
#include "deps/021a7bc8_FUN_021a7bc8.h"

void FUN_021a7bc8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  
  iVar1 = FUN_021a7064(DAT_021a7bf8,param_1,1);
  *(undefined4 *)(iVar1 + 0x10) = param_2;
  *(undefined4 *)(iVar1 + 0x14) = param_3;
  *(undefined4 *)(iVar1 + 0x18) = param_4;
  *(undefined4 *)(iVar1 + 0x1c) = param_5;
  FUN_021a6fb4(param_1);
  return;
}

