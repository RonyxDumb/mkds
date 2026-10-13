/* Decompiled C draft; module arm9_ov003; ROM address 021d244c. No matching claim. */
#include "types.h"
#include "deps/021d244c_FUN_021d244c.h"

void FUN_021d244c(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = DAT_021d2488;
  piVar1 = DAT_021d2484;
  iVar4 = 0;
  iVar3 = 0;
  do {
    FUN_021d1490(*(undefined4 *)(*piVar1 + iVar3 + iVar2));
    iVar3 = iVar3 + 4;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  FUN_021d1d4c(*(undefined4 *)(*DAT_021d2484 + DAT_021d248c));
  FUN_021d2808(DAT_021d2484);
  return;
}

