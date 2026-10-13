/* Decompiled C draft; module arm9_ov001; ROM address 02199b6c. No matching claim. */
#include "types.h"
#include "deps/02199b6c_FUN_02199b6c.h"

void FUN_02199b6c(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_02199bac;
  *(int *)(*DAT_02199bac + 0xc) = *(int *)(*DAT_02199bac + 0xc) + 1;
  iVar2 = *piVar1;
  if (*(int *)(iVar2 + 0xc) < 10) {
    if (4 < *(int *)(iVar2 + 0xc)) {
      *(undefined4 *)(iVar2 + 0x14) = 1;
    }
  }
  else {
    *(undefined4 *)(iVar2 + 4) = 5;
    *(undefined4 *)(*piVar1 + 0xc) = 0;
    if (*(int *)(*piVar1 + 0x10) == 5) {
      func_0x021282c8();
      return;
    }
  }
  return;
}

