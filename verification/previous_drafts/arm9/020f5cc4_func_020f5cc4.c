/* Decompiled C draft; module arm9; ROM address 020f5cc4. No matching claim. */
#include "types.h"
#include "deps/020f5cc4_func_020f5cc4.h"

void func_020f5cc4(int param_1)

{
  if (*(short *)(param_1 + 0xda) != -1) {
    func_020f1150();
    *(undefined2 *)(param_1 + 0x24c) = 4;
    *(undefined2 *)(param_1 + 0x24e) = 1;
    return;
  }
  return;
}

