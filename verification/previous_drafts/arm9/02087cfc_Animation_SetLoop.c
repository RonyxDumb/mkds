/* Decompiled C draft; module arm9; ROM address 02087cfc. No matching claim. */
#include "types.h"
#include "deps/02087cfc_Animation_SetLoop.h"

void Animation_SetLoop(undefined2 *param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)(param_1 + 0x10) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 0x10) & 0xfffffffc);
  *(undefined4 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_2 * 4) = param_3;
  *param_1 = (short)param_3;
  return;
}

