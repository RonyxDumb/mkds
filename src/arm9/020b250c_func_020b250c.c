/* Decompiled C draft; module arm9; ROM address 020b250c. No matching claim. */
#include "types.h"
#include "deps/020b250c_func_020b250c.h"

undefined4 func_020b250c(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = GetRaceMode();
  if ((iVar1 == 0) && (iVar1 = func_020b24f8(), iVar1 == 4)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

