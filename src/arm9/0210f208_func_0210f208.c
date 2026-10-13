/* Decompiled C draft; module arm9; ROM address 0210f208. No matching claim. */
#include "types.h"
#include "deps/0210f208_func_0210f208.h"

void func_0210f208(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  param_1[1] = param_2;
  *param_1 = param_2;
  param_1[2] = param_3;
  *(undefined1 *)(param_1 + 3) = 0x28;
  *(undefined1 *)((int)param_1 + 0xd) = 0x50;
  *(undefined1 *)((int)param_1 + 0xe) = 0x7f;
  return;
}

