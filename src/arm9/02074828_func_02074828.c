/* Decompiled C draft; module arm9; ROM address 02074828. No matching claim. */
#include "types.h"
#include "deps/02074828_func_02074828.h"

void func_02074828(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = uRam02074850;
  uVar1 = *puRam0207484c;
  *(uint *)((*(uint *)(uRam02074850 & 0xfffffffc) >> (uRam02074850 & 3) * 8 |
            *(uint *)(uRam02074850 & 0xfffffffc) << (uRam02074850 & 3) * -8 + 0x20) + 100) =
       (uint)uVar1;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 0x60) = uVar1 + 5;
  return;
}

