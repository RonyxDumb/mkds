/* Decompiled C draft; module arm9; ROM address 020fcac0. No matching claim. */
#include "types.h"
#include "deps/020fcac0_func_020fcac0.h"

void func_020fcac0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  StateDualHandler_Create(param_1 + 0x2e8,uRam020fcb28,8,param_1);
  Matrix4x3_Identity(param_1 + 0x2b4);
  uVar2 = uRam020fcb2c;
  *(undefined2 *)(param_1 + 0x274) = 1;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(short *)(param_1 + 0x276) =
       (short)*(char *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x474);
  *(undefined4 *)(param_1 + 0x278) = 0;
  *(undefined4 *)(param_1 + 0x26c) = 0;
  *(undefined4 *)(param_1 + 0x270) = 0xdc;
  *(undefined2 *)(param_1 + 0x280) = 0;
  *(undefined4 *)(param_1 + 0x2e4) = 0;
  return;
}

