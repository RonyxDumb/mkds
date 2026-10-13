/* Decompiled C draft; module arm9; ROM address 02152a8c. No matching claim. */
#include "types.h"
#include "deps/02152a8c_FriendCode_SetProfileIdAndFlags_from_thumb.h"

void FriendCode_SetProfileIdAndFlags_from_thumb(int param_1,undefined4 param_2,undefined4 param_3)

{
  FriendCode_SetFlagsImpl_from_thumb(param_1,param_3,0,uRam02152aac);
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}

