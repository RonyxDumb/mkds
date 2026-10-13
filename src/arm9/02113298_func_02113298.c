/* Decompiled C draft; module arm9; ROM address 02113298. No matching claim. */
#include "types.h"
#include "deps/02113298_func_02113298.h"

void func_02113298(void)

{
  int *piVar1;
  
  piVar1 = piRam021132ac;
  *(undefined4 *)(*piRam021132ac + 0x50) = 10;
  *(undefined4 *)(*piVar1 + 0x54) = 0;
                    /* WARNING: Could not recover jumptable at 0x021132a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam021132b0)();
  return;
}

