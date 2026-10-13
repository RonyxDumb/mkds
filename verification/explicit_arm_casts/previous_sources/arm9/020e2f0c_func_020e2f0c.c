/* Decompiled C draft; module arm9; ROM address 020e2f0c. No matching claim. */
#include "types.h"
#include "deps/020e2f0c_func_020e2f0c.h"

void func_020e2f0c(int param_1,int param_2)

{
  undefined8 uVar1;
  
  StateDualHandler_Create(param_1 + 0x80,uRam020e2f98,8,param_1);
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 8);
  *(int *)(param_1 + 0xac) = *(int *)(param_1 + 8) - iRam020e2f9c;
  *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 8) - iRam020e2fa0;
  *(int *)(param_1 + 0xa4) = (int)*(short *)(param_2 + 0x28);
  *(int *)(param_1 + 0xa0) = (int)*(short *)(param_2 + 0x2a);
  *(undefined2 *)(param_1 + 0x90) = 0;
  *(undefined2 *)(param_1 + 0x92) = 1;
  uVar1 = Multiply64(*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x1c) >> 0x1f,uRam020e2fa4);
  func_020e516c(param_1 + 0xbc,param_1 + 4,
                (uint)uVar1 >> 0xc | (int)((ulonglong)uVar1 >> 0x20) << 0x14,0x1e);
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020e2fa8;
  return;
}

