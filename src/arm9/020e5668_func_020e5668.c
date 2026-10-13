/* Decompiled C draft; module arm9; ROM address 020e5668. No matching claim. */
#include "types.h"
#include "deps/020e5668_func_020e5668.h"

void func_020e5668(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  *(int *)(param_1 + 0x24) =
       (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
            *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) >> 4;
  uVar1 = param_2 + 8 & 3;
  uVar2 = *(uint *)(param_2 + 8 & 0xfffffffc);
  *(int *)(param_1 + 0x2c) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
  return;
}

