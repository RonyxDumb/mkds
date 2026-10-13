/* Decompiled C draft; module arm9; ROM address 020fe3d8. No matching claim. */
#include "types.h"
#include "deps/020fe3d8_func_020fe3d8.h"

void func_020fe3d8(int param_1)

{
  undefined4 uVar1;
  
  Matrix4x3_Identity(param_1 + 0x13c);
  StateDualHandler_Create(param_1 + 0x184,uRam020fe448,4,param_1);
  StateDualHandler_SetState(param_1 + 0x184,0);
  *(undefined4 *)(param_1 + 0x170) = 300;
  *(undefined4 *)(param_1 + 0x174) = 0;
  uVar1 = uRam020fe44c;
  *(undefined2 *)(param_1 + 0x178) = 8;
  *(undefined4 *)(param_1 + 0x17c) = uVar1;
  *(undefined4 *)(param_1 + 0x180) = 0;
  *(undefined4 *)(param_1 + 0x16c) = 0;
  *(undefined4 *)(param_1 + 0x1a0) = 1;
  *(undefined4 *)(param_1 + 0x198) = 0;
  return;
}

