/* Decompiled C draft; module arm9; ROM address 02081e3c. No matching claim. */
#include "types.h"
#include "deps/02081e3c_func_02081e3c.h"

void func_02081e3c(int param_1,undefined1 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_1 + 0x9a) = 0;
  *(undefined1 *)(param_1 + 0x99) = param_3;
  uVar1 = uRam02081e58;
  *(undefined1 *)(param_1 + 0x9b) = param_2;
  *(undefined4 *)(param_1 + 0x90) = uVar1;
  return;
}

