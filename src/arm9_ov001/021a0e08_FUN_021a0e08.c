/* Decompiled C draft; module arm9_ov001; ROM address 021a0e08. No matching claim. */
#include "types.h"
#include "deps/021a0e08_FUN_021a0e08.h"

void FUN_021a0e08(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = func_0x02029608();
  func_0x02124fac(uVar1,param_2);
  *(undefined2 *)(param_2 + 2) = 0x2d;
  func_0x02124fac(param_1 + 1,param_2 + 4);
  *(undefined2 *)(param_2 + 6) = 0;
  return;
}

