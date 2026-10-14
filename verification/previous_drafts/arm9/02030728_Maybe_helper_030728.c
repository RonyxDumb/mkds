/* Decompiled C draft; module arm9; ROM address 02030728. No matching claim. */
#include "types.h"
#include "deps/02030728_Maybe_helper_030728.h"

undefined4 Maybe_helper_030728(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Maybe_helper_030780();
  if ((iVar1 == 0) && (iVar1 = Maybe_check_03075c(param_1), iVar1 != 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

