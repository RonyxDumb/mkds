/* Decompiled C draft; module arm9; ROM address 02056dac. No matching claim. */
#include "types.h"
#include "deps/02056dac_CheckExtraKartUnlockFlagsWith_from_thumb.h"

undefined4 CheckExtraKartUnlockFlagsWith_from_thumb(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  iVar1 = CheckSecretFlagWith_from_thumb(0x13,param_1);
  if (iVar1 == 0) {
    iVar1 = CheckSecretFlagWith_from_thumb(0x12,param_1);
    if (iVar1 == 0) {
      iVar1 = CheckSecretFlagWith_from_thumb(0x11,param_1);
      if (iVar1 != 0) {
        uVar2 = 2;
      }
    }
    else {
      uVar2 = 3;
    }
  }
  else {
    uVar2 = 4;
  }
  return uVar2;
}

