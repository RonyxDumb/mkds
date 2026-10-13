/* Decompiled C draft; module arm9; ROM address 020fa4b4. No matching claim. */
#include "types.h"
#include "deps/020fa4b4_func_020fa4b4.h"

uint func_020fa4b4(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020fa4c4 & 0xfffffffc) >> (uRam020fa4c4 & 3) * 8 |
          *(uint *)(uRam020fa4c4 & 0xfffffffc) << (uRam020fa4c4 & 3) * -8 + 0x20) + param_1 * 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

