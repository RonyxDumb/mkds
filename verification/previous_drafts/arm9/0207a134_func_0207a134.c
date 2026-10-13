/* Decompiled C draft; module arm9; ROM address 0207a134. No matching claim. */
#include "types.h"
#include "deps/0207a134_func_0207a134.h"

undefined2 func_0207a134(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0207a148 & 0xfffffffc) >> (uRam0207a148 & 3) * 8 |
          *(uint *)(uRam0207a148 & 0xfffffffc) << (uRam0207a148 & 3) * -8 + 0x20) + 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return *(undefined2 *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
}

