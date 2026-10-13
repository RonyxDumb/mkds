/* Decompiled C draft; module arm9; ROM address 020601a0. No matching claim. */
#include "types.h"
#include "deps/020601a0_func_020601a0.h"

uint func_020601a0(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_28 [24];
  char local_10;
  byte local_e;
  
  iVar2 = TimeTrialRecord_CopyFrom_from_thumb(param_1,param_2,(int)(uintptr_t)(auStack_28));
  if ((iVar2 == 0) || (local_10 == '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    uVar3 = (uint)local_e;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

