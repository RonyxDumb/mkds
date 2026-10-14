/* Decompiled C draft; module arm9; ROM address 020cb194. No matching claim. */
#include "types.h"
#include "deps/020cb194_Maybe_helper_0cb194.h"

undefined4 Maybe_helper_0cb194(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = func_020cb1c4();
  if ((iVar1 == 0) && (*(ushort *)(param_1 + 0x10) < 5)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

