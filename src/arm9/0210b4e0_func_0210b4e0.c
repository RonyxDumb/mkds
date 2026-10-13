/* Decompiled C draft; module arm9; ROM address 0210b4e0. No matching claim. */
#include "types.h"
#include "deps/0210b4e0_func_0210b4e0.h"

void func_0210b4e0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar3;
  undefined4 unaff_r4;
  uint uVar2;
  
  uVar2 = param_1 + 0x490U & 3;
  uVar1 = *(uint *)(param_1 + 0x490U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 == 0) {
    unaff_r4 = 0xb2;
  }
  else if (uVar2 == 1) {
    unaff_r4 = 0xb9;
  }
  else if (uVar2 == 2) {
    unaff_r4 = 0xc0;
  }
  if (param_2 != 0) {
    uVar3 = func_0210bb74(1,param_3,param_4);
    func_02109078(param_1,uVar3,0x5f,0xfffffcbb);
  }
  func_02109078(param_1,unaff_r4,0x7f,0);
  return;
}

