/* Decompiled C draft; module arm9; ROM address 0212f7c8. No matching claim. */
#include "types.h"
#include "deps/0212f7c8_NNS_Snd_func_02068a4c.h"

bool NNS_Snd_func_02068a4c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar2 = param_1 + 0xcU & 3;
  uVar3 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  return (int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) <=
         (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
}

