/* Decompiled C draft; module arm9; ROM address 020ec450. No matching claim. */
#include "types.h"
#include "deps/020ec450_func_020ec450.h"

void func_020ec450(int param_1,undefined4 param_2,char *param_3)

{
  if (*param_3 == '\x01') {
    func_020ec6e4(param_1);
    *(undefined2 *)(param_1 + 0x90) = 1;
    *(undefined2 *)(param_1 + 0x92) = 1;
    return;
  }
  return;
}

