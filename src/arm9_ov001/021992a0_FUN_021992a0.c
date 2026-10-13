/* Decompiled C draft; module arm9_ov001; ROM address 021992a0. No matching claim. */
#include "types.h"
#include "deps/021992a0_FUN_021992a0.h"

void FUN_021992a0(void)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  
  piVar1 = DAT_021992d8;
  *(int *)(*DAT_021992d8 + 0x20) = *(int *)(*DAT_021992d8 + 0x20) + 1;
  sVar2 = func_0x0212825c(*(undefined4 *)(*piVar1 + 0x20));
  piVar1 = DAT_021992d8;
  *(short *)(*DAT_021992d8 + 0x30) = -sVar2;
  iVar3 = *piVar1;
  if (9 < *(int *)(iVar3 + 0x20)) {
    *(undefined4 *)(iVar3 + 4) = 2;
    *(undefined4 *)(*piVar1 + 0x20) = 0;
  }
  return;
}

