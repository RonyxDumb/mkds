/* Decompiled C draft; module arm9; ROM address 020287ec. No matching claim. */
#include "types.h"
#include "deps/020287ec_Maybe_helper_0287ec.h"

undefined4 Maybe_helper_0287ec(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = func_0202881c();
  if ((iVar1 == 0) && (*(ushort *)(param_1 + 0x10) < 5)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

