/* Decompiled C draft; module arm9; ROM address 021524d8. No matching claim. */
#include "types.h"
#include "deps/021524d8_FriendCode_SetProfileIdAndChecksum_from_thumb.h"

void FriendCode_SetProfileIdAndChecksum_from_thumb
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  Mem_CpuFill8(param_1,0,0xc);
  FriendCode_SetFriendCodeValues_from_thumb(param_1,param_2,param_3);
  FriendCode_SetState_from_thumb(param_1,2);
  return;
}

