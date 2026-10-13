/* Decompiled C draft; module arm9_ov003; ROM address 021b7da0. No matching claim. */
#include "types.h"
#include "deps/021b7da0_func_ov003_021b7da0.h"

int func_ov003_021b7da0(byte *param_1,byte *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 0;
  for (; (0 < param_3 && (iVar1 = (uint)*param_1 - (uint)*param_2, iVar1 == 0));
      param_1 = param_1 + 1) {
    param_2 = param_2 + 1;
    param_3 = param_3 + -1;
  }
  return iVar1;
}

