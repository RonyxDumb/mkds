/* Decompiled C draft; module arm9; ROM address 0200628c. No matching claim. */
#include "types.h"
#include "deps/0200628c_func_0200628c.h"

undefined4 func_0200628c(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int extraout_r1;
  int iVar2;
  
  iVar1 = func_020070e4();
  iVar2 = param_1[6];
  if (param_2 < (int)param_1[1]) {
    if (param_2 == param_1[1] + -1) {
      _s32_div_f(*param_1,iVar1);
      if (extraout_r1 == 0) {
        Mem_CpuCopy8(param_3,iVar2 + iVar1 * param_2,iVar1);
      }
      else {
        Mem_CpuCopy8(param_3,iVar2 + iVar1 * param_2);
      }
    }
    else {
      Mem_CpuCopy8(param_3,iVar2 + iVar1 * param_2,iVar1);
    }
    return 1;
  }
  return 0;
}

