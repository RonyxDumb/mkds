/* Decompiled C draft; module arm9; ROM address 02061f7c. No matching claim. */
#include "types.h"
#include "deps/02061f7c_func_02061f7c.h"

uint func_02061f7c(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam02061f8c & 0xfffffffc) >> (uRam02061f8c & 3) * 8 |
          *(uint *)(uRam02061f8c & 0xfffffffc) << (uRam02061f8c & 3) * -8 + 0x20) + 0x10;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

