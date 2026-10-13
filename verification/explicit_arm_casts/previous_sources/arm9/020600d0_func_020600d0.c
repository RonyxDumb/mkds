/* Decompiled C draft; module arm9; ROM address 020600d0. No matching claim. */
#include "types.h"
#include "deps/020600d0_func_020600d0.h"

undefined4 func_020600d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [20];
  char local_10;
  
  iVar2 = TimeTrialRecord_CopyFrom_from_thumb(param_1,param_2,auStack_28);
  if ((iVar2 == 0) || (local_10 == '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    Mem_CpuCopy8(auStack_24,param_3,0x14);
    return 1;
  }
  return 0;
}

