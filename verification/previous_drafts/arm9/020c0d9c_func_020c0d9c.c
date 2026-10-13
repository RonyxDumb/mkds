/* Decompiled C draft; module arm9; ROM address 020c0d9c. No matching claim. */
#include "types.h"
#include "deps/020c0d9c_func_020c0d9c.h"

uint func_020c0d9c(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020c0dac & 0xfffffffc) >> (uRam020c0dac & 3) * 8 |
          *(uint *)(uRam020c0dac & 0xfffffffc) << (uRam020c0dac & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

