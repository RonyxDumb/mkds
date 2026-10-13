/* Decompiled C draft; module arm9; ROM address 020c3e14. No matching claim. */
#include "types.h"
#include "deps/020c3e14_func_020c3e14.h"

uint func_020c3e14(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020c3e28 & 0xfffffffc) >> (uRam020c3e28 & 3) * 8 |
          *(uint *)(uRam020c3e28 & 0xfffffffc) << (uRam020c3e28 & 3) * -8 + 0x20) + param_1 * 4 +
          0xc0;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

