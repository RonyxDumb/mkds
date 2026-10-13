/* Decompiled C draft; module arm9; ROM address 0211349c. No matching claim. */
#include "types.h"
#include "deps/0211349c_func_0211349c.h"

void func_0211349c(void)

{
  int *piVar1;
  
  piVar1 = piRam021134b0;
  *(undefined4 *)(*piRam021134b0 + 0x50) = 2;
  *(undefined4 *)(*piVar1 + 0x54) = 0;
                    /* WARNING: Could not recover jumptable at 0x021134ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam021134b4)();
  return;
}

