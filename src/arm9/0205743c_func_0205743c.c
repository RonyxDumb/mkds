/* Decompiled C draft; module arm9; ROM address 0205743c. No matching claim. */
#include "types.h"
#include "deps/0205743c_func_0205743c.h"

bool func_0205743c(undefined4 param_1)

{
  byte *pbVar1;
  uint extraout_r1;
  
  pbVar1 = (byte *)GetGhostDataByteByCourse_from_thumb();
  _s32_div_f(param_1,8);
  return ((uint)*pbVar1 & 1 << (extraout_r1 & 0xff)) != 0;
}

