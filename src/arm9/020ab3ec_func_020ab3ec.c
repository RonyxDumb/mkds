/* Decompiled C draft; module arm9; ROM address 020ab3ec. No matching claim. */
#include "types.h"
#include "deps/020ab3ec_func_020ab3ec.h"

void func_020ab3ec(int param_1)

{
  if (*(short *)(param_1 + 0x3c) == 4) {
    *(undefined2 *)(param_1 + 0x40) = 4;
    *(undefined2 *)(param_1 + 0x42) = 0;
  }
  else if (*(short *)(param_1 + 0x3c) == 5) {
    *(undefined2 *)(param_1 + 0x40) = 5;
    *(undefined2 *)(param_1 + 0x42) = 0;
  }
  if (*(short *)(param_1 + 0x40) == 4) {
    if (*(short *)(param_1 + 0x42) == 0) {
      *(int *)(param_1 + 0x30) = *piRam020ab454 + 2;
      return;
    }
  }
  else {
    if (*(short *)(param_1 + 0x40) != 5) {
      return;
    }
    if (*(short *)(param_1 + 0x42) == 0) {
      *(int *)(param_1 + 0x30) = *piRam020ab458 + 2;
    }
  }
  return;
}

