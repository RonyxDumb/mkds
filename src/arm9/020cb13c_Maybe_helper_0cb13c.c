/* Decompiled C draft; module arm9; ROM address 020cb13c. No matching claim. */
#include "types.h"
#include "deps/020cb13c_Maybe_helper_0cb13c.h"

undefined4 Maybe_helper_0cb13c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Maybe_helper_0cb194();
  if ((iVar1 == 0) && (iVar1 = Maybe_check_0cb170(param_1), iVar1 != 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

