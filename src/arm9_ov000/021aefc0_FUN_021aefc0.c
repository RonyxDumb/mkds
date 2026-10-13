/* Decompiled C draft; module arm9_ov000; ROM address 021aefc0. No matching claim. */
#include "types.h"
#include "deps/021aefc0_FUN_021aefc0.h"

void FUN_021aefc0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_021af010(*(undefined4 *)(param_1 + 0x1c));
  if ((iVar1 == 0) && (*(int *)(DAT_021af008 + 4) == DAT_021af00c)) {
    FUN_021b00e0(*(undefined4 *)(param_1 + 0x1c));
    FUN_021afc5c();
    return;
  }
  FUN_021af550(0,0,param_1,param_2,param_3);
  return;
}

