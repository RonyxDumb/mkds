/* Decompiled C draft; module arm9; ROM address 0200c12c. No matching claim. */
#include "types.h"
#include "deps/0200c12c_func_0200c12c.h"

byte func_0200c12c(undefined4 param_1,int param_2)

{
  byte *pbVar1;
  byte extraout_r1;
  
  _s32_div_f(*pbRam0200c164 + 1,piRam0200c168[1]);
  pbVar1 = pbRam0200c164;
  *pbRam0200c164 = extraout_r1;
  Mem_CpuCopy8(param_2 + *piRam0200c168 * (uint)*pbVar1,param_1);
  return *pbRam0200c164;
}

