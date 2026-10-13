/* Decompiled C draft; module arm9_ov003; ROM address 021bf048. No matching claim. */
#include "types.h"
#include "deps/021bf048_FUN_021bf048.h"

void FUN_021bf048(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  FUN_021d34c8(0,param_1);
  if (*(int *)(*DAT_021bf094 + 0x10) != 0) {
    FUN_021d34c8(0);
  }
  piVar1 = DAT_021bf094;
  iVar3 = 0;
  iVar2 = 0;
  do {
    if (*(int *)(*piVar1 + iVar2) != 0) {
      FUN_021d197c();
    }
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  FUN_021d197c(*(undefined4 *)(*DAT_021bf094 + 8));
  FUN_021d2808(DAT_021bf094);
  return;
}

