/* Decompiled C draft; module arm9; ROM address 020e5aec. No matching claim. */
#include "types.h"
#include "deps/020e5aec_func_020e5aec.h"

void func_020e5aec(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = Multiply64(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x20) >> 0x1f,uRam020e5b38,0);
  *(uint *)(param_1 + 8) =
       *(int *)(param_1 + 8) + ((uint)uVar1 >> 0xc | (int)((ulonglong)uVar1 >> 0x20) << 0x14);
  *(undefined2 *)(param_1 + 0xb8) = 0;
  func_020ec854(param_1,*(int *)(param_1 + 8) - iRam020e5b44,uRam020e5b48,uRam020e5b4c,uRam020e5b3c,
                uRam020e5b40);
  func_020ec884(param_1);
  return;
}

