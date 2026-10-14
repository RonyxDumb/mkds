/* Decompiled C draft; module arm9; ROM address 02028794. No matching claim. */
#include "types.h"
#include "deps/02028794_Maybe_helper_028794.h"

undefined4 Maybe_helper_028794(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Maybe_helper_0287ec();
  if ((iVar1 == 0) && (iVar1 = Maybe_check_0287c8(param_1), iVar1 != 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

