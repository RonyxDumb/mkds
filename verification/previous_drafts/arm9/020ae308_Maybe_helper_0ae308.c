/* Decompiled C draft; module arm9; ROM address 020ae308. No matching claim. */
#include "types.h"
#include "deps/020ae308_Maybe_helper_0ae308.h"

undefined4 Maybe_helper_0ae308(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = func_020ae338();
  if ((iVar1 == 0) && (*(ushort *)(param_1 + 0x10) < 5)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

