/* Decompiled C draft; module arm9; ROM address 02061f90. No matching claim. */
#include "types.h"
#include "deps/02061f90_func_02061f90.h"

uint func_02061f90(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam02061fa0 & 0xfffffffc) >> (uRam02061fa0 & 3) * 8 |
          *(uint *)(uRam02061fa0 & 0xfffffffc) << (uRam02061fa0 & 3) * -8 + 0x20) + 0xc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

