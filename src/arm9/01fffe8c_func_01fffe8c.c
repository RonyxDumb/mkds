/* Decompiled C draft; module arm9; ROM address 01fffe8c. No matching claim. */
#include "types.h"
#include "deps/01fffe8c_func_01fffe8c.h"

void func_01fffe8c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = iRam01fffec0;
  *(undefined4 *)(&DAT_040000b0 + param_1 * 0xc) = param_2;
  iVar1 = param_1 * 0xc + iVar1;
  *(undefined4 *)(iVar1 + 4) = param_3;
  *(undefined4 *)(iVar1 + 8) = param_4;
  return;
}

