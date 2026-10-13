/* Decompiled C draft; module arm9_ov001; ROM address 02193730. No matching claim. */
#include "types.h"
#include "deps/02193730_FUN_02193730.h"

void FUN_02193730(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_02193770;
  *(int *)(*DAT_02193770 + 0xc) = *(int *)(*DAT_02193770 + 0xc) + 1;
  iVar2 = *piVar1;
  if (*(int *)(iVar2 + 0xc) < 10) {
    if (4 < *(int *)(iVar2 + 0xc)) {
      *(undefined4 *)(iVar2 + 0x14) = 1;
    }
  }
  else {
    *(undefined4 *)(iVar2 + 4) = 5;
    *(undefined4 *)(*piVar1 + 0xc) = 0;
    if (*(int *)(*piVar1 + 8) == 2) {
      func_0x021282c8();
      return;
    }
  }
  return;
}

