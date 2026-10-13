/* Decompiled C draft; module arm9; ROM address 020e4934. No matching claim. */
#include "types.h"
#include "deps/020e4934_func_020e4934.h"

undefined1 func_020e4934(int param_1,undefined4 param_2,char *param_3,undefined1 *param_4)

{
  if (*param_3 == '\x01') {
    func_020ec6e4();
    *(undefined2 *)(param_1 + 0x90) = 1;
    *(undefined2 *)(param_1 + 0x92) = 1;
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020e498c;
    func_020d26f8(param_1,param_2);
  }
  return *param_4;
}

