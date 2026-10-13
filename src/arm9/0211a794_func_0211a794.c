/* Decompiled C draft; module arm9; ROM address 0211a794. No matching claim. */
#include "types.h"
#include "deps/0211a794_func_0211a794.h"

void func_0211a794(void)

{
  *puRam0211a7b4 = *(int *)(*piRam0211a7ac + 0x5c) * -0x10000 & uRam0211a7b0;
                    /* WARNING: Could not recover jumptable at 0x0211a7a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0211a7b8)();
  return;
}

