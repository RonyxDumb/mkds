/* Decompiled C draft; module arm9; ROM address 020c31c0. No matching claim. */
#include "types.h"
#include "deps/020c31c0_func_020c31c0.h"

void func_020c31c0(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020c31e8 & 0xfffffffc) >> (uRam020c31e8 & 3) * 8 |
          *(uint *)(uRam020c31e8 & 0xfffffffc) << (uRam020c31e8 & 3) * -8 + 0x20) + 0xac;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  (*(code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))();
  func_020c3654();
  return;
}

