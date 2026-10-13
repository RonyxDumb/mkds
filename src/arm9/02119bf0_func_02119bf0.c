/* Decompiled C draft; module arm9; ROM address 02119bf0. No matching claim. */
#include "types.h"
#include "deps/02119bf0_func_02119bf0.h"

void func_02119bf0(void)

{
  int *piVar1;
  
  piVar1 = piRam02119c04;
  *(undefined4 *)(*piRam02119c04 + 0x38) = 2;
  *(undefined4 *)(*piVar1 + 0x3c) = 0;
                    /* WARNING: Could not recover jumptable at 0x02119c00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02119c08)();
  return;
}

