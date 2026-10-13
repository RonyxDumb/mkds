/* Decompiled C draft; module arm9; ROM address 02115e44. No matching claim. */
#include "types.h"
#include "deps/02115e44_func_02115e44.h"

void func_02115e44(void)

{
  int *piVar1;
  
  piVar1 = piRam02115e58;
  *(undefined4 *)(*piRam02115e58 + 0x58) = 2;
  *(undefined4 *)(*piVar1 + 0x5c) = 0;
                    /* WARNING: Could not recover jumptable at 0x02115e54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02115e5c)();
  return;
}

