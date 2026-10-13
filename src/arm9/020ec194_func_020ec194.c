/* Decompiled C draft; module arm9; ROM address 020ec194. No matching claim. */
#include "types.h"
#include "deps/020ec194_func_020ec194.h"

void func_020ec194(int param_1)

{
  undefined1 auStack_18 [16];
  
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0xb4);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0xb8);
  func_020d7a3c(param_1 + 0xbc,*(undefined2 *)(param_1 + 200),(int *)(void *)(auStack_18));
  func_01ffccd0((int *)(uintptr_t)(param_1 + 0x28),(uint)(uintptr_t)(auStack_18));
  return;
}

