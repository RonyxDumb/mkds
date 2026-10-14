/* Decompiled C draft; module arm9; ROM address 020224c0. No matching claim. */
#include "types.h"
#include "deps/020224c0_func_020224c0.h"

void func_020224c0(uint param_1,undefined2 param_2,undefined2 param_3)

{
  if ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) == 1) {
    *(ushort *)(param_1 + 0x12) = *(ushort *)(param_1 + 0x12) | 8;
    *(undefined2 *)(param_1 + 0xc) = param_2;
    *(undefined2 *)(param_1 + 0xe) = param_3;
  }
  return;
}

