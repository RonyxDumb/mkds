/* Decompiled C draft; module arm9_ov003; ROM address 021c0fd8. No matching claim. */
#include "types.h"
#include "deps/021c0fd8_FUN_021c0fd8.h"

void FUN_021c0fd8(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  FUN_021d34c8(0,param_1);
  piVar1 = DAT_021c1058;
  iVar4 = 0;
  iVar3 = 0;
  do {
    FUN_021d197c(*(undefined4 *)(*piVar1 + iVar3 + 0x48));
    FUN_021d2388(*(undefined4 *)(*piVar1 + iVar3));
    piVar2 = DAT_021c1058;
    iVar3 = iVar3 + 4;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 4);
  iVar3 = 0;
  iVar4 = 0;
  do {
    FUN_021d197c(*(undefined4 *)(*piVar2 + iVar4 + 0x40));
    piVar1 = DAT_021c1058;
    iVar4 = iVar4 + 4;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  iVar3 = 0;
  iVar4 = 0;
  do {
    FUN_021d2f00(*(undefined4 *)(*piVar1 + iVar4 + 0x38));
    piVar2 = DAT_021c1058;
    iVar4 = iVar4 + 4;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  iVar3 = 0;
  iVar4 = 0;
  do {
    FUN_021d2f00(*(undefined4 *)(*piVar2 + iVar4 + 0x10));
    iVar4 = iVar4 + 4;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 10);
  FUN_021d2808(DAT_021c1058);
  return;
}

