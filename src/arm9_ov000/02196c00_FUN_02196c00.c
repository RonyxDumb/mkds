/* Decompiled C draft; module arm9_ov000; ROM address 02196c00. No matching claim. */
#include "types.h"
#include "deps/02196c00_FUN_02196c00.h"

void FUN_02196c00(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  FUN_021970e4(param_1,DAT_02196c88);
  uVar1 = func_0x0213bf90();
  FUN_021970e4(param_1,DAT_02196c8c);
  uVar2 = func_0x0213bf90();
  FUN_021970e4(param_1,DAT_02196c90);
  uVar3 = func_0x0213bf90();
  FUN_021970e4(param_1,DAT_02196c94);
  uVar4 = func_0x0213bf90();
  iVar5 = FUN_02196d84(1,uVar2,uVar3);
  if (iVar5 != -1) {
    FUN_021970e4(param_1,DAT_02196c98);
    uVar2 = func_0x0213bf90();
    iVar6 = func_0x02139f70(param_1,DAT_02196c9c);
    if (iVar6 == 0) {
      uVar2 = 0;
      iVar6 = DAT_02196ca0;
    }
    else {
      iVar6 = iVar6 + 6;
    }
    FUN_021969d8(iVar5,uVar1,uVar4,iVar6,uVar2);
  }
  return;
}

