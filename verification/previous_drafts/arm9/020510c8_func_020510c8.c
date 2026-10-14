/* Decompiled C draft; module arm9; ROM address 020510c8. No matching claim. */
#include "types.h"
#include "deps/020510c8_func_020510c8.h"

uint func_020510c8(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(uRam020510e0 & 0xfffffffc) >> (uRam020510e0 & 3) * 8 |
          *(uint *)(uRam020510e0 & 0xfffffffc) << (uRam020510e0 & 3) * -8 + 0x20;
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  }
  return uVar1;
}

