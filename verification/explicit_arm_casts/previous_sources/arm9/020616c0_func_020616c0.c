/* Decompiled C draft; module arm9; ROM address 020616c0. No matching claim. */
#include "types.h"
#include "deps/020616c0_func_020616c0.h"

undefined4 func_020616c0(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  if ((int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x1f) < 0) {
    Mem_CpuCopy8(param_1 + 0xc,param_2,0x14);
    return 1;
  }
  return 0;
}

