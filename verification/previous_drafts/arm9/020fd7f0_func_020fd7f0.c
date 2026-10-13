/* Decompiled C draft; module arm9; ROM address 020fd7f0. No matching claim. */
#include "types.h"
#include "deps/020fd7f0_func_020fd7f0.h"

uint func_020fd7f0(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020fd800 & 0xfffffffc) >> (uRam020fd800 & 3) * 8 |
          *(uint *)(uRam020fd800 & 0xfffffffc) << (uRam020fd800 & 3) * -8 + 0x20) + 0x278;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

