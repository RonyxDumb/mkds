/* Decompiled C draft; module arm9; ROM address 02049838. No matching claim. */
#include "types.h"
#include "deps/02049838_func_02049838.h"

uint func_02049838(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam02049848 & 0xfffffffc) >> (uRam02049848 & 3) * 8 |
          *(uint *)(uRam02049848 & 0xfffffffc) << (uRam02049848 & 3) * -8 + 0x20) + 0x10c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

