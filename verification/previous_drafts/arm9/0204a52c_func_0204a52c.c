/* Decompiled C draft; module arm9; ROM address 0204a52c. No matching claim. */
#include "types.h"
#include "deps/0204a52c_func_0204a52c.h"

uint func_0204a52c(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0204a53c & 0xfffffffc) >> (uRam0204a53c & 3) * 8 |
          *(uint *)(uRam0204a53c & 0xfffffffc) << (uRam0204a53c & 3) * -8 + 0x20) + 0xe4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

