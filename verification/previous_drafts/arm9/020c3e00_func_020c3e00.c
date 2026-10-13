/* Decompiled C draft; module arm9; ROM address 020c3e00. No matching claim. */
#include "types.h"
#include "deps/020c3e00_func_020c3e00.h"

uint func_020c3e00(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020c3e10 & 0xfffffffc) >> (uRam020c3e10 & 3) * 8 |
          *(uint *)(uRam020c3e10 & 0xfffffffc) << (uRam020c3e10 & 3) * -8 + 0x20) + 0xa0;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

