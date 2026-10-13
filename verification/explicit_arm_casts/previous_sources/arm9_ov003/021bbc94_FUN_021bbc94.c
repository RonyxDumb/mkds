/* Decompiled C draft; module arm9_ov003; ROM address 021bbc94. No matching claim. */
#include "types.h"
#include "deps/021bbc94_FUN_021bbc94.h"

void FUN_021bbc94(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined1 auStack_18 [12];
  
  FUN_021bb408(auStack_18,param_2 + 0x10,8);
  uVar1 = *(uint *)(param_2 + 0x10) >> 3 & 0x3f;
  if (uVar1 < 0x38) {
    iVar2 = 0x38 - uVar1;
  }
  else {
    iVar2 = 0x78 - uVar1;
  }
  FUN_021bbcf0(param_2,DAT_021bbcec,iVar2);
  FUN_021bbcf0(param_2,auStack_18,8);
  FUN_021bb408(param_1,param_2,0x10);
  FUN_021bb3a4(param_2,0,0x58);
  return;
}

