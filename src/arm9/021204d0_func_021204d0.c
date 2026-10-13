/* Decompiled C draft; module arm9; ROM address 021204d0. No matching claim. */
#include "types.h"
#include "deps/021204d0_func_021204d0.h"

void func_021204d0(void)

{
  uint uVar1;
  uint uVar2;
  
  func_02120714();
  uVar1 = uRam02120510;
  *(undefined4 *)
   ((*(uint *)(uRam02120510 & 0xfffffffc) >> (uRam02120510 & 3) * 8 |
    *(uint *)(uRam02120510 & 0xfffffffc) << (uRam02120510 & 3) * -8 + 0x20) + 0x1f34) = 1;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  *(undefined2 *)(uVar2 + 0x18) = 0;
  *(undefined2 *)(uVar2 + 0x1a) = 1;
  return;
}

