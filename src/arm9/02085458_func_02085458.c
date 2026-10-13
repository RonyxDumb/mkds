/* Decompiled C draft; module arm9; ROM address 02085458. No matching claim. */
#include "types.h"
#include "deps/02085458_func_02085458.h"

uint func_02085458(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0xffffffff;
  if (-1 < param_1 + -2) {
    uVar2 = (*(uint *)(uRam02085474 & 0xfffffffc) >> (uRam02085474 & 3) * 8 |
            *(uint *)(uRam02085474 & 0xfffffffc) << (uRam02085474 & 3) * -8 + 0x20) +
            (param_1 + -2) * 4 + 0x40;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  return uVar2;
}

