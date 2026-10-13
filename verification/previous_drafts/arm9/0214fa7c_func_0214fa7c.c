/* Decompiled C draft; module arm9; ROM address 0214fa7c. No matching claim. */
#include "types.h"
#include "deps/0214fa7c_func_0214fa7c.h"

void func_0214fa7c(undefined4 param_1)

{
  int iVar1;
  
  do {
    iVar1 = Fifo_SendWord(8,param_1,0);
  } while (iVar1 != 0);
  return;
}

