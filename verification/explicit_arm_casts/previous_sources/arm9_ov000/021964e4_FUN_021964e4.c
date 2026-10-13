/* Decompiled C draft; module arm9_ov000; ROM address 021964e4. No matching claim. */
#include "types.h"
#include "deps/021964e4_FUN_021964e4.h"

int FUN_021964e4(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_02196870(param_1,param_3,1);
  if (iVar1 != 0) {
    return 4;
  }
  iVar1 = func_0x0213a038(param_3,DAT_02196584,4);
  if (iVar1 != 0) {
    FUN_021965a0(param_1,1,DAT_02196588);
    FUN_02190f4c(param_1,3,1);
    return 3;
  }
  iVar1 = *(int *)(param_2 + 0xc);
  uVar2 = *(undefined4 *)(param_2 + 0x10);
  if (iVar1 != 0) {
    puVar3 = (undefined4 *)FUN_021a3690(4);
    if (puVar3 == (undefined4 *)0x0) {
      FUN_02196590(param_1,DAT_0219658c);
      return 1;
    }
    *puVar3 = 0;
    iVar1 = FUN_02190ed4(param_1,iVar1,uVar2,puVar3,param_2,0);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  FUN_02193818(param_1,param_2);
  return 0;
}

