/* Decompiled C draft; module arm9; ROM address 020db430. No matching claim. */
#include "types.h"
#include "deps/020db430_func_020db430.h"

void func_020db430(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  
  func_020d90a8(param_1 + 200,*(undefined2 *)(param_1 + 0xec),1);
  func_020d8a5c(param_1 + 200,(uint *)(uintptr_t)(param_1 + 4));
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + *(int *)(param_1 + 0xf8);
  sVar1 = *(short *)(*(int *)(param_1 + 0xe4) + 0x10);
  if (sVar1 == 0) {
    uVar2 = 0;
  }
  else if (sVar1 == 1) {
    uVar2 = 2;
  }
  else if (sVar1 == 2) {
    uVar2 = 5;
  }
  else {
    uVar2 = 0;
  }
  *(undefined4 *)(param_1 + 0xa0) = uVar2;
  *(int *)(param_1 + 0xa4) = (int)*(short *)(*(int *)(param_1 + 0xe4) + 0xe);
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined2 *)(param_1 + 0xba) = 0;
  *(undefined2 *)(param_1 + 0xb8) = *(undefined2 *)(param_1 + 0xba);
  *(undefined2 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0xb0) = 0;
  return;
}

