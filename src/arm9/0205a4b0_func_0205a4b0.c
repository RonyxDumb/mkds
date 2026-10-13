/* Decompiled C draft; module arm9; ROM address 0205a4b0. No matching claim. */
#include "types.h"
#include "deps/0205a4b0_func_0205a4b0.h"

void func_0205a4b0(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = uRam0205a4e4;
  *(undefined2 *)((int)param_1 + 0xe) = 0;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x728;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(undefined2 *)(param_1 + 3) = 2;
  *param_1 = param_2;
  param_1[2] = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x78;
  param_1[1] = 0x13;
  return;
}

