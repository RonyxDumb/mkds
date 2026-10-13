/* Decompiled C draft; module arm9; ROM address 02028850. No matching claim. */
#include "types.h"
#include "deps/02028850_func_02028850.h"

uint func_02028850(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam02028860 & 0xfffffffc) >> (uRam02028860 & 3) * 8 |
          *(uint *)(uRam02028860 & 0xfffffffc) << (uRam02028860 & 3) * -8 + 0x20) + 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

