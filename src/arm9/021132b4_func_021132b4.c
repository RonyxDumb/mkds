/* Decompiled C draft; module arm9; ROM address 021132b4. No matching claim. */
#include "types.h"
#include "deps/021132b4_func_021132b4.h"

void func_021132b4(void)

{
  int *piVar1;
  
  piVar1 = piRam021132d4;
  *(undefined4 *)(*piRam021132d4 + 0x50) = 9;
  *(undefined4 *)(*piVar1 + 0x54) = 0;
  *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + iRam021132d8) = 1;
                    /* WARNING: Could not recover jumptable at 0x021132d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam021132e0)(uRam021132dc,0,4);
  return;
}

