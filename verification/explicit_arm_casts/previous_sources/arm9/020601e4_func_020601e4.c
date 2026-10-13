/* Decompiled C draft; module arm9; ROM address 020601e4. No matching claim. */
#include "types.h"
#include "deps/020601e4_func_020601e4.h"

uint func_020601e4(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_28 [24];
  char local_10;
  byte local_f;
  
  iVar2 = TimeTrialRecord_CopyFrom_from_thumb(param_1,param_2,auStack_28);
  if ((iVar2 == 0) || (local_10 == '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    uVar3 = (uint)local_f;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

