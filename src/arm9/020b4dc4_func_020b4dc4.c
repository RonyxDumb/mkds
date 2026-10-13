/* Decompiled C draft; module arm9; ROM address 020b4dc4. No matching claim. */
#include "types.h"
#include "deps/020b4dc4_func_020b4dc4.h"

undefined4 func_020b4dc4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = GetCurrentRaceMode_2();
  if ((iVar1 == 1) && (param_1 != 0)) {
    return 1;
  }
  uVar2 = func_0207a68c(param_1);
  return uVar2;
}

