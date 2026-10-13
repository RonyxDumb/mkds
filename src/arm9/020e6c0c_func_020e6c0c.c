/* Decompiled C draft; module arm9; ROM address 020e6c0c. No matching claim. */
#include "types.h"
#include "deps/020e6c0c_func_020e6c0c.h"

void func_020e6c0c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = uRam020e6c38;
  *(undefined4 *)
   ((*(uint *)(uRam020e6c38 & 0xfffffffc) >> (uRam020e6c38 & 3) * 8 |
    *(uint *)(uRam020e6c38 & 0xfffffffc) << (uRam020e6c38 & 3) * -8 + 0x20) + 0x14) = 0;
  uVar4 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
  uVar3 = uVar4 + 0x14;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(uVar4 + 0xc) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10) = 0x1000;
  return;
}

