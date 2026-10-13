/* Decompiled C draft; module arm9; ROM address 020b1d20. No matching claim. */
#include "types.h"
#include "deps/020b1d20_func_020b1d20.h"

uint func_020b1d20(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020b1d30 & 0xfffffffc) >> (uRam020b1d30 & 3) * 8 |
          *(uint *)(uRam020b1d30 & 0xfffffffc) << (uRam020b1d30 & 3) * -8 + 0x20) + 0x848;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

