/* Decompiled C draft; module arm9; ROM address 020df6c8. No matching claim. */
#include "types.h"
#include "deps/020df6c8_func_020df6c8.h"

void func_020df6c8(int param_1,int param_2)

{
  undefined8 uVar1;
  
  StateDualHandler_Create(param_1 + 0x80,uRam020df748,2,param_1);
  *(int *)(param_1 + 0xa0) = (int)*(short *)(param_2 + 0x28);
  *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_1 + 8);
  *(int *)(param_1 + 0xa4) = *(int *)(param_1 + 8) - iRam020df74c;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined2 *)(param_1 + 0xa8) = 0;
  *(undefined2 *)(param_1 + 0x90) = 0;
  *(undefined2 *)(param_1 + 0x92) = 1;
  uVar1 = Multiply64(*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x1c) >> 0x1f,uRam020df750);
  func_020e516c(param_1 + 0xb0,param_1 + 4,
                (uint)uVar1 >> 0xc | (int)((ulonglong)uVar1 >> 0x20) << 0x14,0xd);
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020df754;
  return;
}

