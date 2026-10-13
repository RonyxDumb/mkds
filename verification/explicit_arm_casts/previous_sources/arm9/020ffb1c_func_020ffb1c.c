/* Decompiled C draft; module arm9; ROM address 020ffb1c. No matching claim. */
#include "types.h"
#include "deps/020ffb1c_func_020ffb1c.h"

void func_020ffb1c(int param_1,int param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  StateDualHandler_Create(param_1 + 0x80,uRam020ffbcc,6,param_1);
  uVar1 = _s32_div_f((int)*(short *)(param_2 + 0x28) << 7,100);
  *(undefined2 *)(param_1 + 0xb4) = uVar1;
  uVar1 = _s32_div_f((int)*(short *)(param_2 + 0x30) << 7,100);
  *(undefined2 *)(param_1 + 0xb8) = uVar1;
  uVar1 = _s32_div_f((int)*(short *)(param_1 + 0xb4) + (int)*(short *)(param_1 + 0xb8),2);
  *(undefined2 *)(param_1 + 0xb6) = uVar1;
  *(undefined2 *)(param_1 + 0xa2) = *(undefined2 *)(param_2 + 0x2a);
  *(undefined2 *)(param_1 + 0xa0) = *(undefined2 *)(param_2 + 0x2c);
  *(undefined2 *)(param_1 + 0xa4) = *(undefined2 *)(param_2 + 0x2e);
  *(undefined2 *)(param_1 + 0xa6) = 0;
  if (*(short *)(param_1 + 0xa0) == 0) {
    *(undefined4 *)(param_1 + 0xb0) = 0;
  }
  else {
    uVar2 = _s32_div_f(uRam020ffbd0);
    *(undefined4 *)(param_1 + 0xb0) = uVar2;
  }
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined2 *)(param_1 + 0x90) = 1;
  *(undefined2 *)(param_1 + 0x92) = 1;
  return;
}

