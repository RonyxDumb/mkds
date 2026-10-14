/* Decompiled C draft; module arm9; ROM address 02022484. No matching claim. */
#include "types.h"
#include "deps/02022484_func_02022484.h"

void func_02022484(uint param_1,undefined4 param_2,undefined4 param_3)

{
  if ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) == 1) {
    *(ushort *)(param_1 + 0x12) = *(ushort *)(param_1 + 0x12) | 2;
    *(undefined4 *)(param_1 + 4) = param_2;
    *(undefined4 *)(param_1 + 8) = param_3;
  }
  return;
}

