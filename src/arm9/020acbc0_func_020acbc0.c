/* Decompiled C draft; module arm9; ROM address 020acbc0. No matching claim. */
#include "types.h"
#include "deps/020acbc0_func_020acbc0.h"

bool func_020acbc0(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam020acbe4 & 0xfffffffc) >> (uRam020acbe4 & 3) * 8 |
          *(uint *)(uRam020acbe4 & 0xfffffffc) << (uRam020acbe4 & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return (int)((uint)*(byte *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x31) << 0x1f) <
         0;
}

