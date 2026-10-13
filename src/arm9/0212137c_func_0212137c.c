/* Decompiled C draft; module arm9; ROM address 0212137c. No matching claim. */
#include "types.h"
#include "deps/0212137c_func_0212137c.h"

bool func_0212137c(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0212139c & 0xfffffffc) >> (uRam0212139c & 3) * 8 |
          *(uint *)(uRam0212139c & 0xfffffffc) << (uRam0212139c & 3) * -8 + 0x20) + 0x18e8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 2;
}

