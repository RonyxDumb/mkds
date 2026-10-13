/* Decompiled C draft; module arm9_ov000; ROM address 021acec8. No matching claim. */
#include "types.h"
#include "deps/021acec8_thunk_FUN_021acecc.h"

int thunk_FUN_021acecc(int param_1,int param_2)

{
  while ((param_2 != 0 && (*(short *)(param_1 + (param_2 + -1) * 2) == 0))) {
    param_2 = param_2 + -1;
  }
  return param_2;
}

