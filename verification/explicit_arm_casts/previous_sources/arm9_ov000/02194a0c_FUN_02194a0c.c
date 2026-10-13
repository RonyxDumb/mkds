/* Decompiled C draft; module arm9_ov000; ROM address 02194a0c. No matching claim. */
#include "types.h"
#include "deps/02194a0c_FUN_02194a0c.h"

int FUN_02194a0c(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 auStack_20 [16];
  
  iVar1 = FUN_02196870(param_1,param_3,1);
  if (iVar1 != 0) {
    return 4;
  }
  iVar1 = func_0x0213a038(param_3,DAT_02194ae4,5);
  if (iVar1 != 0) {
    FUN_021965a0(param_1,1,DAT_02194ae8);
    FUN_02190f4c(param_1,3,1);
    return 3;
  }
  iVar1 = FUN_021967b4(param_3,DAT_02194aec,auStack_20,0x10);
  if (iVar1 == 0) {
    FUN_021965a0(param_1,1,DAT_02194ae8);
    FUN_02190f4c(param_1,3,1);
    return 3;
  }
  uVar2 = func_0x0213bf90(auStack_20);
  iVar1 = *(int *)(param_2 + 0xc);
  uVar3 = *(undefined4 *)(param_2 + 0x10);
  if (iVar1 != 0) {
    puVar4 = (undefined4 *)FUN_021a3690(8);
    if (puVar4 == (undefined4 *)0x0) {
      FUN_02196590(param_1,DAT_02194af0);
      return 1;
    }
    puVar4[1] = uVar2;
    *puVar4 = 0;
    iVar1 = FUN_02190ed4(param_1,iVar1,uVar3,puVar4,param_2,0);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  FUN_02193818(param_1,param_2);
  return 0;
}

