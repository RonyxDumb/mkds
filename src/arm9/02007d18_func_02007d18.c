/* Decompiled C draft; module arm9; ROM address 02007d18. No matching claim. */
#include "types.h"
#include "deps/02007d18_func_02007d18.h"

void func_02007d18(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = func_02007138();
  if (iVar1 != 0) {
    *(undefined4 *)(*piRam02007d48 + (param_1 + -1) * 4 + iRam02007d4c) = param_2;
  }
  func_02007cf8(param_1,param_2,param_3);
  return;
}

