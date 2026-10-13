/* Decompiled C draft; module arm9_ov003; ROM address 021d1af0. No matching claim. */
#include "types.h"
#include "deps/021d1af0_FUN_021d1af0.h"

void FUN_021d1af0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = DAT_021d1b30;
  piVar1 = DAT_021d1b2c;
  iVar4 = 0;
  iVar3 = 0;
  do {
    FUN_021d2eb8(*(undefined4 *)(*piVar1 + iVar3 + DAT_021d1b34));
    FUN_021d1d4c(*(undefined4 *)(*piVar1 + iVar3 + DAT_021d1b38));
    iVar3 = iVar3 + iVar2;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  FUN_021d2808(DAT_021d1b2c);
  return;
}

