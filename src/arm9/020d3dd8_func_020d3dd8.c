/* Decompiled C draft; module arm9; ROM address 020d3dd8. No matching claim. */
#include "types.h"
#include "deps/020d3dd8_func_020d3dd8.h"

uint func_020d3dd8(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam020d3df0 & 0xfffffffc) >> (uRam020d3df0 & 3) * 8 |
          *(uint *)(uRam020d3df0 & 0xfffffffc) << (uRam020d3df0 & 3) * -8 + 0x20;
  if (uVar2 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = uVar2 + 0x30;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  return uVar2;
}

