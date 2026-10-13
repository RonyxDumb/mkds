/* Decompiled C draft; module arm9; ROM address 020c6f84. No matching claim. */
#include "types.h"
#include "deps/020c6f84_ResetGlobalE8.h"

void ResetGlobalE8(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020c6fa4 & 0xfffffffc) >> (uRam020c6fa4 & 3) * 8 |
          *(uint *)(uRam020c6fa4 & 0xfffffffc) << (uRam020c6fa4 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 1) {
    *puRam020c6fa8 = 0;
  }
  return;
}

