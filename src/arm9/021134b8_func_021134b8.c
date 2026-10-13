/* Decompiled C draft; module arm9; ROM address 021134b8. No matching claim. */
#include "types.h"
#include "deps/021134b8_func_021134b8.h"

void func_021134b8(void)

{
  int *piVar1;
  
  piVar1 = piRam021134cc;
  *(undefined4 *)(*piRam021134cc + 0x50) = 1;
  *(undefined4 *)(*piVar1 + 0x54) = 0;
                    /* WARNING: Could not recover jumptable at 0x021134c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam021134d0)();
  return;
}

