/* Decompiled C draft; module arm9; ROM address 020ec41c. No matching claim. */
#include "types.h"
#include "deps/020ec41c_func_020ec41c.h"

void func_020ec41c(int param_1,undefined4 param_2,char *param_3)

{
  if (*param_3 == '\x01') {
    func_020ec538(param_1);
    *(undefined2 *)(param_1 + 0x90) = 1;
    *(undefined2 *)(param_1 + 0x92) = 1;
    return;
  }
  return;
}

