/* Decompiled C draft; module arm9; ROM address 02080cc0. No matching claim. */
#include "types.h"
#include "deps/02080cc0_func_02080cc0.h"

int func_02080cc0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return (int)*(short *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
}

