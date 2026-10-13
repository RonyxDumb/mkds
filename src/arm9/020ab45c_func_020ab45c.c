/* Decompiled C draft; module arm9; ROM address 020ab45c. No matching claim. */
#include "types.h"
#include "deps/020ab45c_func_020ab45c.h"

void func_020ab45c(int param_1)

{
  short sVar1;
  undefined2 uVar2;
  
  if (*(short *)(param_1 + 0x3c) == 4) {
    if (*(short *)(param_1 + 0x42) == 4) {
      uVar2 = 0;
    }
    else {
      uVar2 = 4;
    }
    *(undefined2 *)(param_1 + 0x42) = uVar2;
  }
  else if (*(short *)(param_1 + 0x3c) == 5) {
    if (*(short *)(param_1 + 0x42) == 5) {
      uVar2 = 0;
    }
    else {
      uVar2 = 5;
    }
    *(undefined2 *)(param_1 + 0x42) = uVar2;
  }
  sVar1 = *(short *)(param_1 + 0x42);
  if (sVar1 == 0) {
    *(int *)(param_1 + 0x30) = *piRam020ab4c8 + 2;
    return;
  }
  if (sVar1 == 4) {
    *(int *)(param_1 + 0x30) = *piRam020ab4cc + 2;
    return;
  }
  if (sVar1 == 5) {
    *(int *)(param_1 + 0x30) = *piRam020ab4d0 + 2;
    return;
  }
  return;
}

