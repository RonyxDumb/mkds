/* Decompiled C draft; module arm9; ROM address 020272c0. No matching claim. */
#include "types.h"
#include "deps/020272c0_func_020272c0.h"

void func_020272c0(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  
  if ((*psRam020272e0 != 2) && (iVar1 = *piRam020272e4, *(int *)(iVar1 + iRam020272e8) == 0)) {
    *(undefined2 *)(*(int *)(iVar1 + 0x18) + 6) = param_1;
    *(undefined2 *)(*(int *)(iVar1 + 0x18) + 0xc6) = param_2;
  }
  return;
}

