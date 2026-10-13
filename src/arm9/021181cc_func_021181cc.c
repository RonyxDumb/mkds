/* Decompiled C draft; module arm9; ROM address 021181cc. No matching claim. */
#include "types.h"
#include "deps/021181cc_func_021181cc.h"

void func_021181cc(void)

{
  int *piVar1;
  
  piVar1 = piRam021181e0;
  *(undefined4 *)(*piRam021181e0 + 0x34) = 2;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
                    /* WARNING: Could not recover jumptable at 0x021181dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam021181e4)();
  return;
}

