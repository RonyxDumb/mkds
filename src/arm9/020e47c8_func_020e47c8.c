/* Decompiled C draft; module arm9; ROM address 020e47c8. No matching claim. */
#include "types.h"
#include "deps/020e47c8_func_020e47c8.h"

void func_020e47c8(int param_1,int param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  StateDualHandler_Create((undefined4 *)(uintptr_t)(param_1 + 0x80),uRam020e4890,4,param_1);
  uVar2 = Multiply64(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x20) >> 0x1f,uRam020e4894,0);
  *(uint *)(param_1 + 8) =
       *(int *)(param_1 + 8) + ((uint)uVar2 >> 0xc | (int)((ulonglong)uVar2 >> 0x20) << 0x14);
  *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0xbc) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0xc0) = *(undefined4 *)(param_1 + 0xc);
  *(undefined2 *)(param_1 + 0xc4) = 4;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  func_020ec854(param_1,*(int *)(param_1 + 8) - iRam020e48a0,uRam020e48a4,uRam020e48a4,uRam020e4898,
                uRam020e489c);
  *(undefined2 *)(param_1 + 0x90) = 0;
  *(undefined2 *)(param_1 + 0x92) = 1;
  uVar2 = Multiply64(*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x1c) >> 0x1f,uRam020e48a8);
  func_020e516c((uint *)(uintptr_t)(param_1 + 200),(int *)(uintptr_t)(param_2),(uint)uVar2 >> 0xc | (int)((ulonglong)uVar2 >> 0x20) << 0x14,
                0xd);
  *(undefined4 *)(param_1 + 0xfc) = *(undefined4 *)(param_2 + 4);
  iVar1 = FX_Div(*(undefined4 *)(param_1 + 0xd4),*(undefined4 *)(param_1 + 0xd8));
  *(int *)(param_1 + iRam020e48ac) = -iVar1;
  iVar1 = FX_Div(*(undefined4 *)(param_1 + 0xdc),*(undefined4 *)(param_1 + 0xd8));
  *(int *)(param_1 + iRam020e48b0) = -iVar1;
  return;
}

