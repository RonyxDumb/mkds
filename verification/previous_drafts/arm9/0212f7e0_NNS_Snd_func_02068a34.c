/* Decompiled C draft; module arm9; ROM address 0212f7e0. No matching claim. */
#include "types.h"
#include "deps/0212f7e0_NNS_Snd_func_02068a34.h"

void NNS_Snd_func_02068a34(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  if ((int)uVar3 < (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) {
    *(uint *)(param_1 + 8) = uVar3 + 1;
  }
  return;
}

