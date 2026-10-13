/* Decompiled C draft; module arm9; ROM address 020b2b70. No matching claim. */
#include "types.h"
#include "deps/020b2b70_func_020b2b70.h"

undefined4 func_020b2b70(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = IsRaceCountdownEnded();
  if ((((((iVar1 == 0) || (iVar1 = func_020b2bc8(), iVar1 == 0)) ||
        (iVar1 = GetB3F0_Beb0(), iVar1 == 0)) ||
       ((iVar1 = func_020c3da0(), iVar1 != 0 || (iVar1 = IsSavingTimeTrialRecord(), iVar1 != 0))))
      || ((iVar1 = func_020c70a0(), iVar1 != 0 || (iVar1 = func_020b1a20(), iVar1 != 0)))) ||
     ((iVar1 = IsRaceOptionMenuOn_from_thumb(), iVar1 == 0 && (iVar1 = func_02055b1c(), iVar1 != 0))
     )) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

