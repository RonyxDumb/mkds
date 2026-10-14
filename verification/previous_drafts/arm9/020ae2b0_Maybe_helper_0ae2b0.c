/* Decompiled C draft; module arm9; ROM address 020ae2b0. No matching claim. */
#include "types.h"
#include "deps/020ae2b0_Maybe_helper_0ae2b0.h"

undefined4 Maybe_helper_0ae2b0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Maybe_helper_0ae308();
  if ((iVar1 == 0) && (iVar1 = Maybe_check_0ae2e4(param_1), iVar1 != 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

