/* Decompiled C draft; module arm9; ROM address 020ee6a8. No matching claim. */
#include "types.h"
#include "deps/020ee6a8_func_020ee6a8.h"

void func_020ee6a8(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  *param_1 = 0xf;
  param_1[2] = 5;
  param_1[1] = 0x13;
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 1;
    param_1[iVar1 + 5] = 0;
    iVar1 = iVar2;
  } while (iVar2 < 3);
  param_1[8] = 0;
  param_1[9] = 0;
  return;
}

