/* Decompiled C draft; module arm9; ROM address 020ba620. No matching claim. */
#include "types.h"
#include "deps/020ba620_func_020ba620.h"

uint func_020ba620(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam020ba638 & 0xfffffffc) >> (uRam020ba638 & 3) * 8 |
          *(uint *)(uRam020ba638 & 0xfffffffc) << (uRam020ba638 & 3) * -8 + 0x20;
  if (uVar2 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = uVar2 + 8;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  return uVar2;
}

