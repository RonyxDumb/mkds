/* Decompiled C draft; module arm9_ov000; ROM address 021868a4. No matching claim. */
#include "types.h"
#include "deps/021868a4_FUN_021868a4.h"

undefined4 FUN_021868a4(int *param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1[1] < param_1[2]) {
    return 0;
  }
  *(undefined4 *)(*param_1 + param_1[2] * 8) = param_2;
  *(undefined4 *)(*param_1 + param_1[2] * 8 + 4) = param_3;
  param_1[2] = param_1[2] + 1;
  return 1;
}

