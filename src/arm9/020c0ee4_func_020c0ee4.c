/* Decompiled C draft; module arm9; ROM address 020c0ee4. No matching claim. */
#include "types.h"
#include "deps/020c0ee4_func_020c0ee4.h"

void func_020c0ee4(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = uRam020c0f04;
  *(undefined4 *)
   ((*(uint *)(uRam020c0f04 & 0xfffffffc) >> (uRam020c0f04 & 3) * 8 |
    *(uint *)(uRam020c0f04 & 0xfffffffc) << (uRam020c0f04 & 3) * -8 + 0x20) + 0xac) = uRam020c0f08;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(undefined4 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0xb0) = 0;
  return;
}

