/* Decompiled C draft; module arm9; ROM address 020e5684. No matching claim. */
#include "types.h"
#include "deps/020e5684_func_020e5684.h"

void func_020e5684(int param_1,int param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = Multiply64(*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x1c) >> 0x1f,uRam020e575c,0);
  *(uint *)(param_1 + 0x5c) = (uint)uVar3 >> 0xc | (int)((ulonglong)uVar3 >> 0x20) << 0x14;
  StateDualHandler_Create(param_1 + 0x80,uRam020e5760,4,param_1);
  func_020d720c(param_2 + 0xc,param_1 + 0xa0);
  *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 0xa8);
  *(undefined4 *)(param_1 + 0xbc) = *(undefined4 *)(param_1 + 0xac);
  *(undefined2 *)(param_1 + 0xc0) = *(undefined2 *)(param_2 + 0x2c);
  *(undefined2 *)(param_1 + 0xc2) = *(undefined2 *)(param_2 + 0x2a);
  *(undefined2 *)(param_1 + 0xc4) = *(undefined2 *)(param_2 + 0x2e);
  uVar1 = _s32_div_f((int)*(short *)(param_2 + 0x28) << 7,100,param_1 + 0xc0,param_1 + 0xb0);
  *(undefined2 *)(param_1 + 0xc6) = uVar1;
  if (*(short *)(param_2 + 0x30) != 0) {
    *(short *)(param_1 + 0xc6) = -*(short *)(param_1 + 0xc6);
  }
  *(undefined2 *)(param_1 + 0x7e) = 0;
  if (*(short *)(param_1 + 0xc0) == 0) {
    *(undefined4 *)(param_1 + 0xcc) = 0;
  }
  else {
    uVar2 = _s32_div_f(uRam020e5764);
    *(undefined4 *)(param_1 + 0xcc) = uVar2;
  }
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined2 *)(param_1 + 0x90) = 0;
  *(undefined2 *)(param_1 + 0x92) = 1;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020e5768;
  return;
}

