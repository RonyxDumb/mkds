/* Decompiled C draft; module arm9_ov000; ROM address 02182c60. No matching claim. */
#include "types.h"
#include "deps/02182c60_FUN_02182c60.h"

void FUN_02182c60(void)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = DAT_02182cb4;
  *(int *)(*DAT_02182cb4 + 0x10) = *(int *)(*DAT_02182cb4 + 0x10) + 1;
  if (*(int *)(*piVar1 + 0x10) < 3) {
    sVar2 = func_0x0212825c(0);
  }
  else {
    sVar2 = func_0x0212825c(*(int *)(*piVar1 + 0x10) + -3);
  }
  piVar1 = DAT_02182cb4;
  *(short *)(*DAT_02182cb4 + 0x1e) = -sVar2;
  iVar4 = *piVar1;
  iVar3 = *(int *)(iVar4 + 0x10);
  if ((9 < iVar3) && (0xc < iVar3)) {
    *(undefined4 *)(iVar4 + 4) = 4;
    *(undefined4 *)(*piVar1 + 0x10) = 0;
  }
  return;
}

