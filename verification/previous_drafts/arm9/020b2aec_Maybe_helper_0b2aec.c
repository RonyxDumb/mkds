/* Decompiled C draft; module arm9; ROM address 020b2aec. No matching claim. */
#include "types.h"
#include "deps/020b2aec_Maybe_helper_0b2aec.h"

undefined4 Maybe_helper_0b2aec(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = func_020b2b1c();
  if ((iVar1 == 0) && (*(ushort *)(param_1 + 0x10) < 5)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

