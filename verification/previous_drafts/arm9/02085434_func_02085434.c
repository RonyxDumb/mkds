/* Decompiled C draft; module arm9; ROM address 02085434. No matching claim. */
#include "types.h"
#include "deps/02085434_func_02085434.h"

uint func_02085434(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam02085454 & 0xfffffffc) >> (uRam02085454 & 3) * 8 |
          *(uint *)(uRam02085454 & 0xfffffffc) << (uRam02085454 & 3) * -8 + 0x20;
  uVar2 = uVar2 + (*(short *)(uVar2 + 0x124) + -1) * 4 + 0x60;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

