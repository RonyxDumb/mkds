/* Decompiled C draft; module arm9; ROM address 02120240. No matching claim. */
#include "types.h"
#include "deps/02120240_func_02120240.h"

uint func_02120240(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 * 0x244 +
          (*(uint *)(uRam02120258 & 0xfffffffc) >> (uRam02120258 & 3) * 8 |
          *(uint *)(uRam02120258 & 0xfffffffc) << (uRam02120258 & 3) * -8 + 0x20) + 0x458;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

