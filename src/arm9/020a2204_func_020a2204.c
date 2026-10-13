/* Decompiled C draft; module arm9; ROM address 020a2204. No matching claim. */
#include "types.h"
#include "deps/020a2204_func_020a2204.h"

uint func_020a2204(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 * 0x70 +
          (*(uint *)(uRam020a221c & 0xfffffffc) >> (uRam020a221c & 3) * 8 |
          *(uint *)(uRam020a221c & 0xfffffffc) << (uRam020a221c & 3) * -8 + 0x20) + 0x6c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

