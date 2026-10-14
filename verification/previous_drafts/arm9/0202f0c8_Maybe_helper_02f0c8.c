/* Decompiled C draft; module arm9; ROM address 0202f0c8. No matching claim. */
#include "types.h"
#include "deps/0202f0c8_Maybe_helper_02f0c8.h"

undefined4 Maybe_helper_02f0c8(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Maybe_helper_02f028();
  if ((iVar1 == 0) && (iVar1 = Maybe_check_02f0fc(param_1), iVar1 != 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

