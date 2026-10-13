/* Decompiled C draft; module arm9; ROM address 0200eb90. No matching claim. */
#include "types.h"
#include "deps/0200eb90_Os_MessageQueue_Initialize.h"

void Os_MessageQueue_Initialize(uint *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  param_1[1] = 0;
  uVar1 = (uint)(param_1 + 1) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  *param_1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  param_1[3] = 0;
  uVar1 = (uint)(param_1 + 3) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
  param_1[2] = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  param_1[4] = param_2;
  param_1[5] = param_3;
  param_1[6] = 0;
  param_1[7] = 0;
  return;
}

