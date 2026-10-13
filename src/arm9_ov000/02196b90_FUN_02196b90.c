/* Decompiled C draft; module arm9_ov000; ROM address 02196b90. No matching claim. */
#include "types.h"
#include "deps/02196b90_FUN_02196b90.h"

void FUN_02196b90(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  FUN_021970e4(param_1,DAT_02196bf0);
  uVar1 = func_0x0213bf90();
  FUN_021970e4(param_1,DAT_02196bf4);
  uVar2 = func_0x0213bf90();
  FUN_021970e4(param_1,DAT_02196bf8);
  uVar3 = func_0x0213bf90();
  FUN_021970e4(param_1,DAT_02196bfc);
  uVar4 = func_0x0213bf90();
  iVar5 = FUN_02196d84(2,uVar3,uVar2);
  if (iVar5 != -1) {
    FUN_021969d8(iVar5,uVar1,uVar4,0,0);
  }
  return;
}

