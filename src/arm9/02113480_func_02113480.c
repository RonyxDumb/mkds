/* Decompiled C draft; module arm9; ROM address 02113480. No matching claim. */
#include "types.h"
#include "deps/02113480_func_02113480.h"

void func_02113480(void)

{
  int *piVar1;
  
  piVar1 = piRam02113494;
  *(undefined4 *)(*piRam02113494 + 0x50) = 3;
  *(undefined4 *)(*piVar1 + 0x54) = 0;
                    /* WARNING: Could not recover jumptable at 0x02113490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02113498)();
  return;
}

