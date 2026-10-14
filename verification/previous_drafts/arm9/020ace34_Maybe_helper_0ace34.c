/* Decompiled C draft; module arm9; ROM address 020ace34. No matching claim. */
#include "types.h"
#include "deps/020ace34_Maybe_helper_0ace34.h"

undefined4 Maybe_helper_0ace34(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Maybe_helper_0ace8c();
  if ((iVar1 == 0) && (iVar1 = Maybe_check_0ace68(param_1), iVar1 != 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

