/* Decompiled C draft; module arm9; ROM address 0200c46c. No matching claim. */
#include "types.h"
#include "deps/0200c46c_func_0200c46c.h"

void func_0200c46c(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = Fifo_SendWord(0xd,param_1,0);
  while (iVar1 != 0) {
    WaitByLoop(1);
    iVar1 = Fifo_SendWord(0xd,param_1,0);
  }
  return;
}

