/* Decompiled C draft; module arm9; ROM address 020b2bc8. No matching claim. */
#include "types.h"
#include "deps/020b2bc8_func_020b2bc8.h"

undefined4 func_020b2bc8(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = IsRaceEnded();
  if ((iVar1 == 0) &&
     ((iVar1 = GetDisplayMode_0(), iVar1 != 2 || (iVar1 = GetRaceStartCountdown(), iVar1 < 0xf1))))
  {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

