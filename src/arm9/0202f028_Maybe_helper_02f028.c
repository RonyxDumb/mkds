/* Decompiled C draft; module arm9; ROM address 0202f028. No matching claim. */
#include "types.h"
#include "deps/0202f028_Maybe_helper_02f028.h"

undefined4 Maybe_helper_02f028(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = func_0202f020();
  if ((iVar1 == 0) && (*(ushort *)(param_1 + 0x10) < 5)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

