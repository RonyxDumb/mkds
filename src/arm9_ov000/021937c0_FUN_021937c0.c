/* Decompiled C draft; module arm9_ov000; ROM address 021937c0. No matching claim. */
#include "types.h"
#include "deps/021937c0_FUN_021937c0.h"

undefined4 FUN_021937c0(int *param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(*param_1 + DAT_021937e4);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    if ((piVar1[2] != 0) && (*piVar1 != 3)) break;
    piVar1 = (int *)piVar1[8];
  }
  return 1;
}

