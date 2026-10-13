/* Decompiled C draft; module arm9_ov003; ROM address 021b82e0. No matching claim. */
#include "types.h"
#include "deps/021b82e0_func_ov003_021b82e0.h"

void func_ov003_021b82e0(undefined2 *param_1,undefined2 param_2,undefined2 param_3,
                        undefined2 param_4,undefined1 param_5,undefined1 param_6,undefined4 param_7)

{
  undefined2 uVar1;
  
  uVar1 = func_ov003_021b7c94(1);
  *param_1 = uVar1;
  param_1[1] = 0;
  param_1[2] = 0;
  uVar1 = func_ov003_021b7c94(param_2);
  param_1[3] = uVar1;
  param_1[4] = 0;
  uVar1 = func_ov003_021b7c94(param_3);
  param_1[5] = uVar1;
  uVar1 = func_ov003_021b7c94(param_4);
  param_1[6] = uVar1;
  *(undefined1 *)(param_1 + 7) = param_5;
  *(undefined1 *)((int)param_1 + 0xf) = param_6;
  func_ov003_021b7d90(param_1 + 8,param_7,8);
  return;
}

