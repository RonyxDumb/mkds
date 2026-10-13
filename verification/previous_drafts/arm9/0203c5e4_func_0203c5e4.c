/* Decompiled C draft; module arm9; ROM address 0203c5e4. No matching claim. */
#include "types.h"
#include "deps/0203c5e4_func_0203c5e4.h"

uint func_0203c5e4(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0203c5f4 & 0xfffffffc) >> (uRam0203c5f4 & 3) * 8 |
          *(uint *)(uRam0203c5f4 & 0xfffffffc) << (uRam0203c5f4 & 3) * -8 + 0x20) + 0x4f0;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

