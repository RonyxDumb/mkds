/* Decompiled C draft; module arm9; ROM address 0202efe8. No matching claim. */
#include "types.h"
#include "deps/0202efe8_func_0202efe8.h"

undefined4 func_0202efe8(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Maybe_helper_02f028();
  if ((iVar1 == 0) && (iVar1 = func_0202f020(param_1), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

