/* Decompiled C draft; module arm9_ov003; ROM address 021bd894. No matching claim. */
#include "types.h"
#include "deps/021bd894_FUN_021bd894.h"

void FUN_021bd894(undefined4 param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined2 local_14;
  undefined1 local_12 [10];
  
  local_14 = (undefined2)DAT_021bd920;
  puVar4 = local_12;
  iVar3 = 7;
  puVar5 = DAT_021bd924;
  do {
    uVar1 = *puVar5;
    puVar5 = puVar5 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar2 = FUN_021bdaa4(*DAT_021bd928,1,&local_14,2);
  uVar2 = FUN_021bdaa4(uVar2,2,&local_14,2);
  if (*DAT_021bd92c != 0) {
    uVar2 = FUN_021bdaa4(uVar2,5,&local_14,2);
  }
  iVar3 = FUN_021bdaa4(uVar2,3,local_12,7);
  if (*DAT_021bd92c != 0) {
    iVar3 = FUN_021bdaa4(iVar3,4,DAT_021bd930,6);
  }
  FUN_021bdb0c(param_1,2,DAT_021bd934,(iVar3 - *DAT_021bd928) + 8,0);
  return;
}

