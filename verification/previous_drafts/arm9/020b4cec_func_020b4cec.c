/* Decompiled C draft; module arm9; ROM address 020b4cec. No matching claim. */
#include "types.h"
#include "deps/020b4cec_func_020b4cec.h"

void func_020b4cec(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    uVar1 = 0x1000;
  }
  else {
    uVar1 = FX_Div(0x1000);
  }
  param_1[3] = uVar1;
  uVar1 = (uint)(param_1 + 3) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
  *param_1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  param_1[2] = 0;
  uVar1 = (uint)(param_1 + 2) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  param_1[1] = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  return;
}

