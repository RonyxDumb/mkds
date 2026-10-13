/* Decompiled C draft; module arm9; ROM address 020ab580. No matching claim. */
#include "types.h"
#include "deps/020ab580_func_020ab580.h"

void func_020ab580(undefined2 param_1)

{
  int iVar1;
  
  func_020ab5f4(iRam020ab598);
  iVar1 = iRam020ab598;
  *(undefined2 *)(iRam020ab598 + 8) = param_1;
  *(undefined2 *)(iVar1 + 10) = 0;
  return;
}

