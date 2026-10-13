/* Decompiled C draft; module arm9; ROM address 02085478. No matching claim. */
#include "types.h"
#include "deps/02085478_func_02085478.h"

uint func_02085478(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam02085488 & 0xfffffffc) >> (uRam02085488 & 3) * 8 |
          *(uint *)(uRam02085488 & 0xfffffffc) << (uRam02085488 & 3) * -8 + 0x20) + 0x40;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

