/* Decompiled C draft; module arm9; ROM address 020c3da0. No matching claim. */
#include "types.h"
#include "deps/020c3da0_func_020c3da0.h"

uint func_020c3da0(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020c3db0 & 0xfffffffc) >> (uRam020c3db0 & 3) * 8 |
          *(uint *)(uRam020c3db0 & 0xfffffffc) << (uRam020c3db0 & 3) * -8 + 0x20) + 0xa4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

