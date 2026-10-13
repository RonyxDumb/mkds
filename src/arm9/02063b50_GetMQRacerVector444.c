/* Decompiled C draft; module arm9; ROM address 02063b50. No matching claim. */
#include "types.h"
#include "deps/02063b50_GetMQRacerVector444.h"

void GetMQRacerVector444(int param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x120U & 3;
  uVar2 = *(uint *)(param_1 + 0x120U & 0xfffffffc);
  *param_2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x124U & 3;
  uVar2 = *(uint *)(param_1 + 0x124U & 0xfffffffc);
  param_2[1] = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x128U & 3;
  uVar2 = *(uint *)(param_1 + 0x128U & 0xfffffffc);
  param_2[2] = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  return;
}

