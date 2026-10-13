/* Decompiled C draft; module arm9; ROM address 020b1d50. No matching claim. */
#include "types.h"
#include "deps/020b1d50_func_020b1d50.h"

uint func_020b1d50(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020b1d60 & 0xfffffffc) >> (uRam020b1d60 & 3) * 8 |
          *(uint *)(uRam020b1d60 & 0xfffffffc) << (uRam020b1d60 & 3) * -8 + 0x20) + 0x854;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

