/* Decompiled C draft; module arm9; ROM address 02081f10. No matching claim. */
#include "types.h"
#include "deps/02081f10_func_02081f10.h"

void func_02081f10(int param_1,undefined1 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_1 + 0x9a) = 0;
  *(undefined1 *)(param_1 + 0x99) = param_3;
  uVar1 = uRam02081f2c;
  *(undefined1 *)(param_1 + 0x9b) = param_2;
  *(undefined4 *)(param_1 + 0x90) = uVar1;
  return;
}

