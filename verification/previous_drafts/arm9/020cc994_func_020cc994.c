/* Decompiled C draft; module arm9; ROM address 020cc994. No matching claim. */
#include "types.h"
#include "deps/020cc994_func_020cc994.h"

uint func_020cc994(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020cc9a4 & 0xfffffffc) >> (uRam020cc9a4 & 3) * 8 |
          *(uint *)(uRam020cc9a4 & 0xfffffffc) << (uRam020cc9a4 & 3) * -8 + 0x20) + 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

