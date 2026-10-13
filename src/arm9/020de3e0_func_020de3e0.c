/* Decompiled C draft; module arm9; ROM address 020de3e0. No matching claim. */
#include "types.h"
#include "deps/020de3e0_func_020de3e0.h"

void func_020de3e0(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = Multiply64(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x20) >> 0x1f,uRam020de424,0);
  *(uint *)(param_1 + 8) =
       *(int *)(param_1 + 8) + ((uint)uVar1 >> 0xc | (int)((ulonglong)uVar1 >> 0x20) << 0x14);
  func_020ec854(param_1,*(int *)(param_1 + 8) - iRam020de430,uRam020de434,uRam020de434,uRam020de428,
                uRam020de42c);
  func_020ec884(param_1);
  return;
}

