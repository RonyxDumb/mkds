/* Decompiled C draft; module arm9; ROM address 0211b9ec. No matching claim. */
#include "types.h"
#include "deps/0211b9ec_func_0211b9ec.h"

void func_0211b9ec(void)

{
  int *piVar1;
  
  piVar1 = piRam0211ba00;
  *(undefined4 *)(*piRam0211ba00 + 0x34) = 7;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
                    /* WARNING: Could not recover jumptable at 0x0211b9fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0211ba04)();
  return;
}

