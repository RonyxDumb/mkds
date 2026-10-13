/* Decompiled C draft; module arm9_ov003; ROM address 021bfa80. No matching claim. */
#include "types.h"
#include "deps/021bfa80_FUN_021bfa80.h"

void FUN_021bfa80(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_18;
  
  FUN_021d34c8(0,param_1);
  iVar5 = 0;
  iVar6 = 0;
  local_18 = 0;
  iVar3 = local_18;
  iVar4 = local_18;
  do {
    do {
      FUN_021d2388(*(undefined4 *)(iVar3 + iVar6 + *DAT_021bfb20));
      if (iVar5 == 0) {
        FUN_021d197c(*(undefined4 *)(*DAT_021bfb20 + iVar3 + DAT_021bfb24));
      }
      piVar1 = DAT_021bfb20;
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar4 < 4);
    iVar6 = iVar6 + 0x10;
    iVar5 = iVar5 + 1;
    iVar3 = local_18;
    iVar4 = local_18;
  } while (iVar5 < 3);
  iVar3 = 0;
  iVar4 = 0;
  do {
    FUN_021d197c(*(undefined4 *)(*piVar1 + iVar4 + 0xfc));
    piVar2 = DAT_021bfb20;
    iVar4 = iVar4 + 4;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  iVar3 = 0;
  iVar4 = 0;
  do {
    FUN_021d2f00(*(undefined4 *)(*piVar2 + iVar4 + 0xec));
    piVar1 = DAT_021bfb20;
    iVar4 = iVar4 + 4;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  iVar3 = 0;
  iVar4 = 0;
  do {
    FUN_021d2f00(*(undefined4 *)(*piVar1 + iVar4 + 0x30));
    iVar4 = iVar4 + 4;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x2f);
  FUN_021d2808(DAT_021bfb20);
  return;
}

