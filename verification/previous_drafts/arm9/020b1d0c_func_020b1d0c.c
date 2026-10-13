/* Decompiled C draft; module arm9; ROM address 020b1d0c. No matching claim. */
#include "types.h"
#include "deps/020b1d0c_func_020b1d0c.h"

uint func_020b1d0c(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020b1d1c & 0xfffffffc) >> (uRam020b1d1c & 3) * 8 |
          *(uint *)(uRam020b1d1c & 0xfffffffc) << (uRam020b1d1c & 3) * -8 + 0x20) + 0x84c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

