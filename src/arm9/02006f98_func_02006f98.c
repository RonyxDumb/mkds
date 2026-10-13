/* Decompiled C draft; module arm9; ROM address 02006f98. No matching claim. */
#include "types.h"
#include "deps/02006f98_func_02006f98.h"

int func_02006f98(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_r1;
  uint uVar3;
  
  uVar1 = func_020070e4();
  _s32_div_f(param_1,uVar1);
  iVar2 = _s32_div_f(param_1,uVar1);
  uVar3 = iVar2 + (uint)(extraout_r1 != 0);
  return (((int)uVar3 >> 5) + (uint)((uVar3 & 0x1f) != 0)) * 4;
}

