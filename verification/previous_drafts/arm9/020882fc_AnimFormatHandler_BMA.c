/* Decompiled C draft; module arm9; ROM address 020882fc. No matching claim. */
#include "types.h"
#include "deps/020882fc_AnimFormatHandler_BMA.h"

undefined2 AnimFormatHandler_BMA(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  return *(undefined2 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 4);
}

