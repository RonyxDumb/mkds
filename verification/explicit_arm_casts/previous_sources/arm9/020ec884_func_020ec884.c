/* Decompiled C draft; module arm9; ROM address 020ec884. No matching claim. */
#include "types.h"
#include "deps/020ec884_func_020ec884.h"

void func_020ec884(int param_1)

{
  StateDualHandler_Create(param_1 + 0x80,uRam020ec8b8,3,param_1);
  *(undefined2 *)(param_1 + 0x90) = 0;
  *(undefined2 *)(param_1 + 0x92) = 1;
  return;
}

