/* Decompiled C draft; module arm9; ROM address 020e3b08. No matching claim. */
#include "types.h"
#include "deps/020e3b08_func_020e3b08.h"

int func_020e3b08(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(uRam020e3b24 & 0xfffffffc) >> (uRam020e3b24 & 3) * 8 |
          *(uint *)(uRam020e3b24 & 0xfffffffc) << (uRam020e3b24 & 3) * -8 + 0x20;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x154;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 0xc;
}

