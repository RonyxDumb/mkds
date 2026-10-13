/* Decompiled C draft; module arm9_ov000; ROM address 02196d0c. No matching claim. */
#include "types.h"
#include "deps/02196d0c_FUN_02196d0c.h"

void FUN_02196d0c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  FUN_021970e4(param_1,DAT_02196d74);
  iVar1 = func_0x0213bf90();
  FUN_021970e4(param_1,DAT_02196d78);
  uVar2 = func_0x0213bf90();
  uVar3 = FUN_021970e4(param_1,DAT_02196d7c);
  iVar4 = FUN_02196d84(0,uVar2,0);
  if (iVar4 != -1) {
    iVar5 = FUN_0218dbf8(*DAT_02196d80,iVar4);
    *(int *)(iVar5 + 8) = iVar1;
    FUN_021969d8(iVar4,0 < iVar1,0,uVar3,0);
  }
  return;
}

