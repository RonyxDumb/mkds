/* Decompiled C draft; module arm9_ov003; ROM address 021d35c0. No matching claim. */
#include "types.h"
#include "deps/021d35c0_FUN_021d35c0.h"

void FUN_021d35c0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_021d35f0;
  iVar3 = 0;
  iVar2 = 0;
  do {
    FUN_021d2eb8(*(undefined4 *)(*piVar1 + iVar2 + 8));
    FUN_021d1d4c(*(undefined4 *)(*piVar1 + iVar2));
    iVar2 = iVar2 + 0x3c;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  FUN_021d2808(DAT_021d35f0);
  return;
}

