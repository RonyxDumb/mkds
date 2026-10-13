/* Decompiled C draft; module arm9; ROM address 020224a4. No matching claim. */
#include "types.h"
#include "deps/020224a4_func_020224a4.h"

void func_020224a4(uint param_1,undefined2 param_2)

{
  if ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) == 1) {
    *(ushort *)(param_1 + 0x12) = *(ushort *)(param_1 + 0x12) | 4;
    *(undefined2 *)(param_1 + 0x10) = param_2;
  }
  return;
}

