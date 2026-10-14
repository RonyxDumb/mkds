/* Decompiled C draft; module arm9; ROM address 020b2a94. No matching claim. */
#include "types.h"
#include "deps/020b2a94_Maybe_helper_0b2a94.h"

undefined4 Maybe_helper_0b2a94(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Maybe_helper_0b2aec();
  if ((iVar1 == 0) && (iVar1 = Maybe_check_0b2ac8(param_1), iVar1 != 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

