/* Decompiled C draft; module arm9; ROM address 01ffff38. No matching claim. */
#include "types.h"
#include "deps/01ffff38_func_01ffff38.h"

void func_01ffff38(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  Os_DisableIrq();
  iVar1 = iRam01ffff84;
  *(undefined4 *)(&DAT_040000b0 + param_1 * 0xc) = param_2;
  iVar1 = param_1 * 0xc + iVar1;
  *(undefined4 *)(iVar1 + 4) = param_3;
  *(undefined4 *)(iVar1 + 8) = param_4;
  Os_RestoreIrq();
  return;
}

