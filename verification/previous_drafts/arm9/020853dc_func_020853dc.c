/* Decompiled C draft; module arm9; ROM address 020853dc. No matching claim. */
#include "types.h"
#include "deps/020853dc_func_020853dc.h"

uint func_020853dc(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020853ec & 0xfffffffc) >> (uRam020853ec & 3) * 8 |
          *(uint *)(uRam020853ec & 0xfffffffc) << (uRam020853ec & 3) * -8 + 0x20) + 0x138;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

