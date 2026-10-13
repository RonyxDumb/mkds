/* Decompiled C draft; module arm9; ROM address 021285b0. No matching claim. */
#include "types.h"
#include "deps/021285b0_func_021285b0.h"

void func_021285b0(void)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = func_0212825c(*(undefined4 *)(*piRam021285ec + 0xc));
  piVar1 = piRam021285ec;
  *(undefined4 *)(*piRam021285ec + iRam021285f0) = uVar2;
  *(int *)(*piVar1 + 0xc) = *(int *)(*piVar1 + 0xc) + 1;
  if (9 < *(int *)(*piVar1 + 0xc)) {
    *(undefined4 *)(*piVar1 + 8) = 2;
    *(undefined4 *)(*piVar1 + 0xc) = 0;
    *(undefined4 *)(*piVar1 + iRam021285f4) = 0;
  }
  return;
}

