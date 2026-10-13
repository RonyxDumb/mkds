/* Decompiled C draft; module arm9; ROM address 02057410. No matching claim. */
#include "types.h"
#include "deps/02057410_func_02057410.h"

void func_02057410(undefined4 param_1)

{
  byte *pbVar1;
  uint extraout_r1;
  
  pbVar1 = (byte *)GetGhostDataByteByCourse_from_thumb();
  _s32_div_f(param_1,8);
  *pbVar1 = *pbVar1 & ~(byte)(1 << (extraout_r1 & 0xff));
  return;
}

