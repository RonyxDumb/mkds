/* Decompiled C draft; module arm9; ROM address 020dc11c. No matching claim. */
#include "types.h"
#include "deps/020dc11c_func_020dc11c.h"

void func_020dc11c(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar1 = param_2[1];
  *(undefined4 *)(param_1 + 0xa0) = *param_2;
  *(undefined4 *)(param_1 + 0xa4) = uVar1;
  *(undefined4 *)(param_1 + 0xa8) = param_2[2];
  uVar2 = Multiply64(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x20) >> 0x1f,uRam020dc1c4,0);
  *(uint *)(param_1 + 0xf0) = (uint)uVar2 >> 0xc | (int)((ulonglong)uVar2 >> 0x20) << 0x14;
  *(int *)(param_1 + 0xf4) = iRam020dc1c8 - *(int *)(param_1 + 0xf0);
  *(undefined4 *)(param_1 + 0xfc) = 1;
  *(int *)(param_1 + 0xb0) = (int)*(short *)((int)param_2 + 0x2a);
  *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_1 + 0xa4);
  *(int *)(param_1 + 0xa4) = *(int *)(param_1 + 0xa4) + *(int *)(param_1 + 0xf0);
  StateDualHandler_Create(param_1 + 0x80,uRam020dc1cc,6,param_1);
  StateDualHandler_SetState(param_1 + 0x80,5);
  func_020d7d4c(param_1 + iRam020dc1d0,param_2,*puRam020dc1d4,(int)*(short *)(param_2 + 10));
  func_020dbf7c(param_1);
  return;
}

