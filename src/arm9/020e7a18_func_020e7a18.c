/* Decompiled C draft; module arm9; ROM address 020e7a18. No matching claim. */
#include "types.h"
#include "deps/020e7a18_func_020e7a18.h"

void func_020e7a18(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020e7a38 & 0xfffffffc) >> (uRam020e7a38 & 3) * 8 |
          *(uint *)(uRam020e7a38 & 0xfffffffc) << (uRam020e7a38 & 3) * -8 + 0x20) + 0xc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) != 6) {
    *puRam020e7a3c = 0x14;
  }
  return;
}

