/* Decompiled C draft; module arm9_ov003; ROM address 021bda78. No matching claim. */
#include "types.h"
#include "deps/021bda78_FUN_021bda78.h"

void FUN_021bda78(short *param_1)

{
  short sVar1;
  
  *(undefined1 *)param_1 = 0;
  *(undefined1 *)((int)param_1 + 1) = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 3) = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 5) = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)((int)param_1 + 7) = 0;
  sVar1 = FUN_021bdaa4(param_1 + 4);
  *param_1 = (sVar1 - (short)param_1) + -8;
  return;
}

