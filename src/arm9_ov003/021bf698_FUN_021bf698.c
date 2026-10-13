/* Decompiled C draft; module arm9_ov003; ROM address 021bf698. No matching claim. */
#include "types.h"
#include "deps/021bf698_FUN_021bf698.h"

void FUN_021bf698(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_021bf6c4;
  iVar3 = 0;
  iVar2 = 0;
  do {
    if (*(int *)(*piVar1 + iVar2) != 0) {
      FUN_021d197c();
      *(undefined4 *)(*piVar1 + iVar2) = 0;
    }
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  return;
}

