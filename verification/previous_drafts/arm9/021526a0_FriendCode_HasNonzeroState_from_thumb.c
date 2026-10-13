/* Decompiled C draft; module arm9; ROM address 021526a0. No matching claim. */
#include "types.h"
#include "deps/021526a0_FriendCode_HasNonzeroState_from_thumb.h"

undefined4 FriendCode_HasNonzeroState_from_thumb(void)

{
  int iVar1;
  
  iVar1 = FriendCode_GetState_from_thumb();
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
}

