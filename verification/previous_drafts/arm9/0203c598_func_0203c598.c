/* Decompiled C draft; module arm9; ROM address 0203c598. No matching claim. */
#include "types.h"
#include "deps/0203c598_func_0203c598.h"

uint func_0203c598(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam0203c5a8 & 0xfffffffc) >> (uRam0203c5a8 & 3) * 8 |
          *(uint *)(uRam0203c5a8 & 0xfffffffc) << (uRam0203c5a8 & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

