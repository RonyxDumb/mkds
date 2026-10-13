/* Decompiled C draft; module arm9; ROM address 02085390. No matching claim. */
#include "types.h"
#include "deps/02085390_func_02085390.h"

uint func_02085390(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020853a0 & 0xfffffffc) >> (uRam020853a0 & 3) * 8 |
          *(uint *)(uRam020853a0 & 0xfffffffc) << (uRam020853a0 & 3) * -8 + 0x20) + 0x120;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

