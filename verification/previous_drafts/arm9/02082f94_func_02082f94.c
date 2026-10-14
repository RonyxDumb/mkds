/* Decompiled C draft; module arm9; ROM address 02082f94. No matching claim. */
#include "types.h"
#include "deps/02082f94_func_02082f94.h"

void func_02082f94(int param_1,int param_2)

{
  if (param_2 != 0) {
    return;
  }
  func_02082d64();
  *(char *)(param_1 + 0x9b) = *(char *)(param_1 + 0x9b) + '\x01';
  if (1 < *(byte *)(param_1 + 0x9b)) {
    *(bool *)(param_1 + 0x9a) = *(char *)(param_1 + 0x9a) == '\0';
    *(undefined1 *)(param_1 + 0x9b) = 0;
    return;
  }
  return;
}

