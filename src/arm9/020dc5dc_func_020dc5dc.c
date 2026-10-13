/* Decompiled C draft; module arm9; ROM address 020dc5dc. No matching claim. */
#include "types.h"
#include "deps/020dc5dc_func_020dc5dc.h"

void func_020dc5dc(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = uRam020dc600;
  *(undefined4 *)(param_1 + 0xe8) = uRam020dc5fc;
  *(undefined4 *)(param_1 + 0xec) = uVar2;
  uVar1 = param_1 + 0x1d8U & 3;
  uVar3 = *(uint *)(param_1 + 0x1d8U & 0xfffffffc);
  *(undefined4 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0xa8) = uRam020dc604;
  return;
}

