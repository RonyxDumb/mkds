/* Decompiled C draft; module arm9; ROM address 0202f498. No matching claim. */
#include "types.h"
#include "deps/0202f498_GetB488SomeMode.h"

uint GetB488SomeMode(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0202f4a8 & 0xfffffffc) >> (uRam0202f4a8 & 3) * 8 |
          *(uint *)(uRam0202f4a8 & 0xfffffffc) << (uRam0202f4a8 & 3) * -8 + 0x20) + 0x74;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

