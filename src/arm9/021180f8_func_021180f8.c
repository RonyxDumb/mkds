/* Decompiled C draft; module arm9; ROM address 021180f8. No matching claim. */
#include "types.h"
#include "deps/021180f8_func_021180f8.h"

void func_021180f8(void)

{
  int *piVar1;
  
  piVar1 = piRam0211810c;
  *(undefined4 *)(*piRam0211810c + 0x34) = 7;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
                    /* WARNING: Could not recover jumptable at 0x02118108. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02118110)();
  return;
}

