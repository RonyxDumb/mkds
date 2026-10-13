/* Decompiled C draft; module arm9; ROM address 020a9de4. No matching claim. */
#include "types.h"
#include "deps/020a9de4_func_020a9de4.h"

undefined1 func_020a9de4(int param_1,undefined4 param_2,char *param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  
  uVar1 = *param_4;
  if (*param_3 == '\x01') {
    *(undefined4 *)(param_1 + 0xc0) = 0xa000;
    uVar1 = 0;
  }
  return uVar1;
}

