/* Decompiled C draft; module arm9; ROM address 02028ec0. No matching claim. */
#include "types.h"
#include "deps/02028ec0_func_02028ec0.h"

void func_02028ec0(int param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined2 uVar1;
  short *psVar2;
  short *psVar3;
  
  psVar2 = (short *)func_02028f08(param_1,*(undefined4 *)(param_4 + 0xc));
  psVar3 = (short *)func_02028f08(param_2,*(undefined4 *)(param_4 + 0xc));
  uVar1 = _s32_div_f(((((int)*psVar3 << 0x14) >> 0x14) - (((int)*psVar2 << 0x14) >> 0x14)) *
                     (100 - param_3));
  *(undefined2 *)(*(int *)(param_4 + 0x18) + param_1 * 0x40 + 4) = uVar1;
  return;
}

