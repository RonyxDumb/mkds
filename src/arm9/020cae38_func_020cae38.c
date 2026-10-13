/* Decompiled C draft; module arm9; ROM address 020cae38. No matching claim. */
#include "types.h"
#include "deps/020cae38_func_020cae38.h"

int func_020cae38(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020cae50 & 0xfffffffc) >> (uRam020cae50 & 3) * 8 |
          *(uint *)(uRam020cae50 & 0xfffffffc) << (uRam020cae50 & 3) * -8 + 0x20) + 0x1c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return (int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x1d) >> 0x1f;
}

