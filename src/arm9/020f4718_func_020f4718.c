/* Decompiled C draft; module arm9; ROM address 020f4718. No matching claim. */
#include "types.h"
#include "deps/020f4718_func_020f4718.h"

void func_020f4718(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  *param_1 = 0x13;
  param_1[2] = 0;
  param_1[8] = 0;
  param_1[3] = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  *(undefined2 *)((int)param_1 + 0x12) = 0;
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 1;
    param_1[iVar1 + 5] = 0;
    iVar1 = iVar2;
  } while (iVar2 < 3);
  return;
}

