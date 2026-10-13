/* Decompiled C draft; module arm9; ROM address 0210543c. No matching claim. */
#include "types.h"
#include "deps/0210543c_func_0210543c.h"

uint func_0210543c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)((uint)piRam0210545c & 0xfffffffc) >> ((uint)piRam0210545c & 3) * 8 |
          *(uint *)((uint)piRam0210545c & 0xfffffffc) << ((uint)piRam0210545c & 3) * -8 + 0x20;
  uVar2 = uRam02105460 & 3;
  uVar1 = *(uint *)(uRam02105460 & 0xfffffffc);
  *piRam0210545c = uVar3 + 1;
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + uVar3 * 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

