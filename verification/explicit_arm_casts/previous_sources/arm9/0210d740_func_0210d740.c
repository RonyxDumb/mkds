/* Decompiled C draft; module arm9; ROM address 0210d740. No matching claim. */
#include "types.h"
#include "deps/0210d740_func_0210d740.h"

void func_0210d740(undefined4 *param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4)

{
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  
  func_0210dc60(uRam0210d7a8,param_1,0);
  local_4 = (undefined1)param_4;
  local_3 = (undefined1)((uint)param_4 >> 8);
  *(undefined1 *)((int)param_1 + 9) = local_4;
  *(undefined1 *)((int)param_1 + 10) = local_3;
  local_2 = (undefined1)((uint)param_4 >> 0x10);
  *(undefined1 *)((int)param_1 + 0xb) = local_2;
  param_1[1] = param_2;
  *(undefined1 *)(param_1 + 2) = param_3;
  func_0212c6a0(param_1 + 3);
  func_0212c6a0(param_1 + 4);
  *param_1 = 1;
  return;
}

