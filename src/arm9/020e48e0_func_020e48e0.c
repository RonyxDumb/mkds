/* Decompiled C draft; module arm9; ROM address 020e48e0. No matching claim. */
#include "types.h"
#include "deps/020e48e0_func_020e48e0.h"

undefined1 func_020e48e0(int param_1,undefined4 param_2,char *param_3,undefined1 *param_4)

{
  if (*param_3 == '\x01') {
    func_020ec538();
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020e4930;
    *(undefined2 *)(param_1 + 0x90) = 1;
    *(undefined2 *)(param_1 + 0x92) = 1;
  }
  return *param_4;
}

