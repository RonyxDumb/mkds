/* Decompiled C draft; module arm9; ROM address 02061818. No matching claim. */
#include "types.h"
#include "deps/02061818_func_02061818.h"

uint func_02061818(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam02061828 & 0xfffffffc) >> (uRam02061828 & 3) * 8 |
          *(uint *)(uRam02061828 & 0xfffffffc) << (uRam02061828 & 3) * -8 + 0x20) + 0x250;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

