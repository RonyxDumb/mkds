/* Decompiled C draft; module arm9; ROM address 02050e60. No matching claim. */
#include "types.h"
#include "deps/02050e60_func_02050e60.h"

void func_02050e60(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = uRam02050e7c;
  *(undefined4 *)
   ((*(uint *)(uRam02050e7c & 0xfffffffc) >> (uRam02050e7c & 3) * 8 |
    *(uint *)(uRam02050e7c & 0xfffffffc) << (uRam02050e7c & 3) * -8 + 0x20) + 8) = param_1;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(undefined4 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x10) = 0;
  return;
}

