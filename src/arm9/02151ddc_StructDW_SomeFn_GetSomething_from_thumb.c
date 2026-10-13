/* Decompiled C draft; module arm9; ROM address 02151ddc. No matching claim. */
#include "types.h"
#include "deps/02151ddc_StructDW_SomeFn_GetSomething_from_thumb.h"

void StructDW_SomeFn_GetSomething_from_thumb(int *param_1)

{
  int local_20;
  int local_1c;
  int local_18;
  int iStack_14;
  
  StructDW_MaybeCreate_from_thumb(&local_20);
  *param_1 = local_20;
  param_1[1] = local_1c;
  param_1[2] = local_18;
  param_1[3] = iStack_14;
  if (local_1c == 0 && local_20 == 0) {
    param_1[4] = 0;
    return;
  }
  param_1[4] = 1;
  return;
}

