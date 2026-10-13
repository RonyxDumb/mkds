/* Decompiled C draft; module arm9_ov000; ROM address 02196ca4. No matching claim. */
#include "types.h"
#include "deps/02196ca4_FUN_02196ca4.h"

void FUN_02196ca4(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  FUN_021970e4(param_1,DAT_02196d00);
  iVar1 = func_0x0213bf90();
  FUN_021970e4(param_1,DAT_02196d04);
  uVar2 = func_0x0213bf90();
  iVar3 = FUN_02196d84(3,uVar2,0);
  if (iVar3 != -1) {
    iVar4 = FUN_0218dbf8((int *)(uintptr_t)(*DAT_02196d08),iVar3);
    *(int *)(iVar4 + 8) = iVar1;
    FUN_021969d8(iVar3,0 < iVar1,0,0,0);
  }
  return;
}

