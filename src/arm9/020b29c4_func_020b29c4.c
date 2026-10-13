/* Decompiled C draft; module arm9; ROM address 020b29c4. No matching claim. */
#include "types.h"
#include "deps/020b29c4_func_020b29c4.h"

undefined4 func_020b29c4(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  bVar3 = false;
  bVar2 = false;
  iVar4 = IsRaceCountdownEnded();
  if ((((iVar4 != 0) && (iVar4 = GetRaceStartCountdown(), 0xf0 < iVar4)) &&
      (iVar4 = IsRaceEnded(), iVar4 == 0)) &&
     ((iVar4 = GetRaceMode(), iVar4 != 2 || (iVar4 = func_020a126c(), iVar4 == 0)))) {
    bVar1 = true;
    iVar4 = GetRaceMode();
    if (iVar4 == 4) {
      iVar4 = GetRaceMode();
      if (iVar4 == 4) {
        iVar4 = func_020a126c();
      }
      else {
        iVar4 = 0;
      }
      if (iVar4 != 0) {
        bVar1 = false;
      }
    }
    if (bVar1) {
      bVar2 = true;
    }
  }
  if ((bVar2) && (iVar4 = GetRaceMode(), iVar4 != 5)) {
    bVar3 = true;
  }
  if ((bVar3) &&
     ((iVar4 = IsRaceOptionMenuOn_from_thumb(), iVar4 != 0 || (iVar4 = func_02055b1c(), iVar4 == 0))
     )) {
    uVar5 = 1;
  }
  return uVar5;
}

