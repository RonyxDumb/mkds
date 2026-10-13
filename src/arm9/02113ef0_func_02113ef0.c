/* Decompiled C draft; module arm9; ROM address 02113ef0. No matching claim. */
#include "types.h"
#include "deps/02113ef0_func_02113ef0.h"

undefined4 func_02113ef0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_02113f1c();
  iVar2 = func_021143b4();
  if (iVar1 + param_1 < iVar2) {
    return 1;
  }
  return 0;
}

