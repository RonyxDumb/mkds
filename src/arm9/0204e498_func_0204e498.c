/* Decompiled C draft; module arm9; ROM address 0204e498. No matching claim. */
#include "types.h"
#include "deps/0204e498_func_0204e498.h"

void func_0204e498(void)

{
  int *piVar1;
  
  piVar1 = piRam0204e4b0;
  *(undefined4 *)(*piRam0204e4b0 + 0xc) = 0x1d;
  *(undefined4 *)(*piVar1 + 0x10) = 1;
                    /* WARNING: Could not recover jumptable at 0x0204e4ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0204e4b8)(uRam0204e4b4,0x25);
  return;
}

