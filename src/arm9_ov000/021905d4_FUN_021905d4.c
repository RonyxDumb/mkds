/* Decompiled C draft; module arm9_ov000; ROM address 021905d4. No matching claim. */
#include "types.h"
#include "deps/021905d4_FUN_021905d4.h"

undefined4 FUN_021905d4(undefined4 param_1,int *param_2)

{
  if (((param_2 != (int *)0x0) && (*param_2 != 0)) && (param_2[3] != 0)) {
    param_2[2] = param_2[2] - param_2[3];
    if (param_2[2] != 0) {
      func_0x02134df8(*param_2,*param_2 + param_2[3]);
    }
    *(undefined1 *)(*param_2 + param_2[2]) = 0;
    param_2[3] = 0;
    return 0;
  }
  return 0;
}

