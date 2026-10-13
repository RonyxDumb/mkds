/* Decompiled C draft; module arm9; ROM address 0204e474. No matching claim. */
#include "types.h"
#include "deps/0204e474_func_0204e474.h"

void func_0204e474(void)

{
  int *piVar1;
  
  piVar1 = piRam0204e48c;
  *(undefined4 *)(*piRam0204e48c + 0xc) = 0x1e;
  *(undefined4 *)(*piVar1 + 0x10) = 1;
                    /* WARNING: Could not recover jumptable at 0x0204e488. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0204e494)(uRam0204e490,0x25);
  return;
}

