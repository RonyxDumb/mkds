/* Decompiled C draft; module arm9; ROM address 0200edc0. No matching claim. */
#include "types.h"
#include "deps/0200edc0_Os_Mutex_Initialize.h"

void Os_Mutex_Initialize(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  param_1[1] = 0;
  uVar1 = (uint)(param_1 + 1) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  *param_1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}

