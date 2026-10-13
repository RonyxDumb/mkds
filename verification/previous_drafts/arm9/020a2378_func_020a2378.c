/* Decompiled C draft; module arm9; ROM address 020a2378. No matching claim. */
#include "types.h"
#include "deps/020a2378_func_020a2378.h"

uint func_020a2378(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020a2388 & 0xfffffffc) >> (uRam020a2388 & 3) * 8 |
          *(uint *)(uRam020a2388 & 0xfffffffc) << (uRam020a2388 & 3) * -8 + 0x20) + 0x3bc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

