/* Decompiled C draft; module arm9; ROM address 02152584. No matching claim. */
#include "types.h"
#include "deps/02152584_FriendCode_GetFriendCodePacked_0_from_thumb.h"

void FriendCode_GetFriendCodePacked_0_from_thumb(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FriendCode_GetState_from_thumb();
  if (iVar1 == 2) {
    FriendCode_GetFriendCodePacked_from_thumb(param_1);
    return;
  }
  return;
}

