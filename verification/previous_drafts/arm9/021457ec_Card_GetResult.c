/* Decompiled C draft; module arm9; ROM address 021457ec. No matching claim. */
#include "types.h"
#include "deps/021457ec_Card_GetResult.h"

uint Card_GetResult(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam021457fc & 0xfffffffc) >> (uRam021457fc & 3) * 8 |
          *(uint *)(uRam021457fc & 0xfffffffc) << (uRam021457fc & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

