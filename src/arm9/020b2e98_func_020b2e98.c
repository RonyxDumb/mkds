/* Decompiled C draft; module arm9; ROM address 020b2e98. No matching claim. */
#include "types.h"
#include "deps/020b2e98_func_020b2e98.h"

undefined4 func_020b2e98(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = IsRaceOptionMenuOn_from_thumb();
  if ((iVar1 == 0) && (*(int *)(*piRam020b2ebc + 8) == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

