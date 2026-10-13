/* Decompiled C draft; module arm9; ROM address 020c0f0c. No matching claim. */
#include "types.h"
#include "deps/020c0f0c_func_020c0f0c.h"

void func_020c0f0c(void)

{
  uint uVar1;
  uint uVar2;
  
  func_020c1060();
  uVar2 = uRam020c0f40;
  *(undefined4 *)
   ((*(uint *)(uRam020c0f40 & 0xfffffffc) >> (uRam020c0f40 & 3) * 8 |
    *(uint *)(uRam020c0f40 & 0xfffffffc) << (uRam020c0f40 & 3) * -8 + 0x20) + 0xac) = uRam020c0f44;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(undefined4 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0xb0) = 0;
  return;
}

