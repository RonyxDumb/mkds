/* Decompiled C draft; module arm9; ROM address 0205108c. No matching claim. */
#include "types.h"
#include "deps/0205108c_func_0205108c.h"

void func_0205108c(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = uRam020510a8;
  *(undefined4 *)
   ((*(uint *)(uRam020510a8 & 0xfffffffc) >> (uRam020510a8 & 3) * 8 |
    *(uint *)(uRam020510a8 & 0xfffffffc) << (uRam020510a8 & 3) * -8 + 0x20) + 0xc) = param_1;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(undefined4 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x10) = 1;
  return;
}

