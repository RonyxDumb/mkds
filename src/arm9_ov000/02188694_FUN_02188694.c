/* Decompiled C draft; module arm9_ov000; ROM address 02188694. No matching claim. */
#include "types.h"
#include "deps/02188694_FUN_02188694.h"

void FUN_02188694(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_02188584(1);
  if ((*(byte *)(iVar1 + 8) & param_1) != 0) {
    *(byte *)(iVar1 + 8) = *(byte *)(iVar1 + 8) & ~(byte)param_1;
    (**(code **)(iVar1 + 4))(param_1,param_2,param_3);
  }
  return;
}

