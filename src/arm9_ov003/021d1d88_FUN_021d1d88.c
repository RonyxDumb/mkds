/* Decompiled C draft; module arm9_ov003; ROM address 021d1d88. No matching claim. */
#include "types.h"
#include "deps/021d1d88_FUN_021d1d88.h"

void FUN_021d1d88(int param_1)

{
  short *psVar1;
  
  psVar1 = (short *)FUN_021d285c((param_1 + 1) * 4 + 8,4);
  *psVar1 = (short)param_1 + 1;
  *(undefined1 *)(psVar1 + 1) = 0;
  *(undefined1 *)((int)psVar1 + 3) = 0;
  return;
}

