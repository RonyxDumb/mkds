/* Decompiled C draft; module arm9; ROM address 0200639c. No matching claim. */
#include "types.h"
#include "deps/0200639c_func_0200639c.h"

void func_0200639c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_r1;
  
  uVar1 = func_020070e4();
  *param_1 = param_2;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  _s32_div_f(param_2,uVar1);
  iVar2 = _s32_div_f(param_2,uVar1);
  param_1[1] = iVar2 + (uint)(extraout_r1 != 0);
  param_1[5] = param_3;
  param_1[6] = param_4;
  uVar1 = func_02006f98(param_2);
  Mem_CpuFill8(param_3,0,uVar1);
  return;
}

