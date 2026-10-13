/* Decompiled C draft; module arm9; ROM address 02152a80. No matching claim. */
#include "types.h"
#include "deps/02152a80_FriendCode_SetFriendCodeValues_from_thumb.h"

void FriendCode_SetFriendCodeValues_from_thumb(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_3;
  return;
}

