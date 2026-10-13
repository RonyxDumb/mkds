/* Decompiled C draft; module arm9; ROM address 02063b30. No matching claim. */
#include "types.h"
#include "deps/02063b30_StructMQRacerEntry_GetVec555.h"

void StructMQRacerEntry_GetVec555(int param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 300U & 3;
  uVar2 = *(uint *)(param_1 + 300U & 0xfffffffc);
  *param_2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x130U & 3;
  uVar2 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
  param_2[1] = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x134U & 3;
  uVar2 = *(uint *)(param_1 + 0x134U & 0xfffffffc);
  param_2[2] = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  return;
}

