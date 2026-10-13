/* Decompiled C draft; module arm9; ROM address 0207e1d4. No matching claim. */
#include "types.h"
#include "deps/0207e1d4_func_0207e1d4.h"

void func_0207e1d4(uint param_1)

{
  *(uint *)(param_1 + 4) =
       *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
       *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(uint *)(param_1 + 0x10) =
       *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
       *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}

