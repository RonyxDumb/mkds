/* Decompiled C draft; module arm9; ROM address 021529e0. No matching claim. */
#include "types.h"
#include "deps/021529e0_FriendCode_SetState_from_thumb.h"

void FriendCode_SetState_from_thumb(undefined4 param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FriendCode_GetFlags_from_thumb();
  FriendCode_SetFlags_from_thumb(param_1,uVar1 & 0xfffffffc | param_2);
  return;
}

