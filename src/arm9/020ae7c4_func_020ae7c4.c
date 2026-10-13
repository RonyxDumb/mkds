/* Decompiled C draft; module arm9; ROM address 020ae7c4. No matching claim. */
#include "types.h"
#include "deps/020ae7c4_func_020ae7c4.h"

void func_020ae7c4(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  
  uVar1 = _s32_div_f(param_1,10);
  *param_4 = uVar1;
  _s32_div_f(param_1,10);
  param_4[1] = extraout_r1;
  uVar1 = _s32_div_f(param_2,10);
  param_4[2] = uVar1;
  _s32_div_f(param_2,10);
  param_4[3] = extraout_r1_00;
  uVar1 = _s32_div_f(param_3,100);
  param_4[4] = uVar1;
  uVar1 = _s32_div_f(param_3 + param_4[4] * -100,10);
  param_4[5] = uVar1;
  _s32_div_f(param_3,10);
  param_4[6] = extraout_r1_01;
  return;
}

