/* Decompiled C draft; module arm9; ROM address 02115cec. No matching claim. */
#include "types.h"
#include "deps/02115cec_func_02115cec.h"

void func_02115cec(void)

{
  int *piVar1;
  
  piVar1 = piRam02115d00;
  *(undefined4 *)(*piRam02115d00 + 0x58) = 9;
  *(undefined4 *)(*piVar1 + 0x5c) = 0;
                    /* WARNING: Could not recover jumptable at 0x02115cfe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02115d04)(0,0xb);
  return;
}

