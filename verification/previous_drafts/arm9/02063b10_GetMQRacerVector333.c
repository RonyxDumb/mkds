/* Decompiled C draft; module arm9; ROM address 02063b10. No matching claim. */
#include "types.h"
#include "deps/02063b10_GetMQRacerVector333.h"

void GetMQRacerVector333(int param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x138U & 3;
  uVar2 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
  *param_2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x13cU & 3;
  uVar2 = *(uint *)(param_1 + 0x13cU & 0xfffffffc);
  param_2[1] = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x140U & 3;
  uVar2 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
  param_2[2] = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  return;
}

