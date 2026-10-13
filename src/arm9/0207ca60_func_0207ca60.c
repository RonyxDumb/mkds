/* Decompiled C draft; module arm9; ROM address 0207ca60. No matching claim. */
#include "types.h"
#include "deps/0207ca60_func_0207ca60.h"

void func_0207ca60(int param_1)

{
  *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + -1;
  if (0 < *(short *)(param_1 + 2)) {
    return;
  }
  *(undefined2 *)(param_1 + 2) = 0;
  func_0207d194();
  return;
}

