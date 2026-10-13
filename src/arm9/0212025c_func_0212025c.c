/* Decompiled C draft; module arm9; ROM address 0212025c. No matching claim. */
#include "types.h"
#include "deps/0212025c_func_0212025c.h"

uint func_0212025c(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 * 0x244 +
          (*(uint *)(uRam02120274 & 0xfffffffc) >> (uRam02120274 & 3) * 8 |
          *(uint *)(uRam02120274 & 0xfffffffc) << (uRam02120274 & 3) * -8 + 0x20) + 0x454;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

