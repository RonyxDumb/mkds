/* Decompiled C draft; module arm9; ROM address 020b2d04. No matching claim. */
#include "types.h"
#include "deps/020b2d04_GetCurrentOptionMenuKind_from_thumb.h"

undefined4 GetCurrentOptionMenuKind_from_thumb(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = GetDisplayMode_0();
  if ((iVar1 == 2) && (iVar1 = IsRaceEnded(), iVar1 == 0)) {
    uVar2 = 3;
  }
  else {
    iVar1 = IsRaceEnded();
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      iVar1 = GetRaceMode();
      if (iVar1 == 4) {
        iVar1 = func_020b2d54();
        if (iVar1 == 0) {
          uVar2 = 2;
        }
        else {
          uVar2 = 1;
        }
      }
      else {
        iVar1 = func_020c3db4();
        if (iVar1 == 0) {
          uVar2 = 1;
        }
        else {
          uVar2 = 2;
        }
      }
    }
  }
  return uVar2;
}

