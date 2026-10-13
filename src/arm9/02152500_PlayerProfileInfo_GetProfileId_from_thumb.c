/* Decompiled C draft; module arm9; ROM address 02152500. No matching claim. */
#include "types.h"
#include "deps/02152500_PlayerProfileInfo_GetProfileId_from_thumb.h"

undefined4 PlayerProfileInfo_GetProfileId_from_thumb(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x1c) != 0) {
    uVar1 = VerifyChecksumGetProfileId_from_thumb
                      (*(int *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24));
  }
  return uVar1;
}

