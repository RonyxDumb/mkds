/* Decompiled C draft; module arm9; ROM address 020d7d4c. No matching claim. */
#include "types.h"
#include "deps/020d7d4c_func_020d7d4c.h"

void func_020d7d4c(int param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  func_020d7da8();
  uVar1 = _s32_div_f(param_3,100);
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = _s32_div_f(param_4 * param_3,100);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  func_020d859c(param_1,0,1);
  return;
}

