/* Decompiled C draft; module arm9; ROM address 0204e074. No matching claim. */
#include "types.h"
#include "deps/0204e074_func_0204e074.h"

void func_0204e074(void)

{
  int *piVar1;
  
  piVar1 = piRam0204e088;
  *(undefined4 *)(*piRam0204e088 + 0xc) = 0x21;
  *(undefined4 *)(*piVar1 + 0x10) = 1;
                    /* WARNING: Could not recover jumptable at 0x0204e084. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0204e08c)();
  return;
}

