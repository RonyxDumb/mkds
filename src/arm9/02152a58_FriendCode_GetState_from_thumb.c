/* Decompiled C draft; module arm9; ROM address 02152a58. No matching claim. */
#include "types.h"
#include "deps/02152a58_FriendCode_GetState_from_thumb.h"

uint FriendCode_GetState_from_thumb(void)

{
  uint uVar1;
  
  uVar1 = FriendCode_GetFlags_from_thumb();
  return uVar1 & 3;
}

