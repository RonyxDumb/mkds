/* Decompiled C draft; module arm9; ROM address 02061fa4. No matching claim. */
#include "types.h"
#include "deps/02061fa4_func_02061fa4.h"

uint func_02061fa4(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam02061fb4 & 0xfffffffc) >> (uRam02061fb4 & 3) * 8 |
          *(uint *)(uRam02061fb4 & 0xfffffffc) << (uRam02061fb4 & 3) * -8 + 0x20) + 0x14;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

