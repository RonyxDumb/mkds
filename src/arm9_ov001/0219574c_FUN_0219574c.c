/* Decompiled C draft; module arm9_ov001; ROM address 0219574c. No matching claim. */
#include "types.h"
#include "deps/0219574c_FUN_0219574c.h"

void FUN_0219574c(void)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = DAT_02195794;
  piVar1 = DAT_02195790;
  *DAT_02195798 = *(int *)(*DAT_02195790 + 0x5c) * -0x10000 & DAT_02195794;
  uVar3 = DAT_0219579c;
  iVar4 = *piVar1;
  *DAT_021957a0 = -*(int *)(iVar4 + 0x60) & DAT_0219579c | *(int *)(iVar4 + 100) * -0x10000 & uVar2;
  *DAT_021957a4 = -*(int *)(*piVar1 + 0x68) & uVar3;
  func_0x02111428();
  return;
}

