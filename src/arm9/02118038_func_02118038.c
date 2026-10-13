/* Decompiled C draft; module arm9; ROM address 02118038. No matching claim. */
#include "types.h"
#include "deps/02118038_func_02118038.h"

void func_02118038(void)

{
  int *piVar1;
  
  piVar1 = piRam0211804c;
  *(undefined4 *)(*piRam0211804c + 0x34) = 10;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
                    /* WARNING: Could not recover jumptable at 0x02118048. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02118050)();
  return;
}

