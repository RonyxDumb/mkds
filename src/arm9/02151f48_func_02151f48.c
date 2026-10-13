/* Decompiled C draft; module arm9; ROM address 02151f48. No matching claim. */
#include "types.h"
#include "deps/02151f48_func_02151f48.h"

undefined4 func_02151f48(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_20 [8];
  undefined4 local_18;
  undefined4 uStack_14;
  
  StructDW_MaybeCreate_from_thumb((undefined4 *)(void *)(auStack_20));
  *param_1 = param_1[2];
  param_1[1] = param_1[3];
  param_1[2] = local_18;
  param_1[3] = uStack_14;
  iVar1 = StructDW_SomeFn_0_from_thumb((undefined4)(uintptr_t)(param_1),param_2);
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
}

