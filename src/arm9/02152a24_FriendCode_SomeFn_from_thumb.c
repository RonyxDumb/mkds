/* Decompiled C draft; module arm9; ROM address 02152a24. No matching claim. */
#include "types.h"
#include "deps/02152a24_FriendCode_SomeFn_from_thumb.h"

undefined4 FriendCode_SomeFn_from_thumb(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FriendCode_GetState_from_thumb();
  if (iVar1 != 3) {
    return 0;
  }
  uVar2 = FriendCode_GetFlags_from_thumb((uint *)(uintptr_t)(param_1));
  if ((uVar2 & 4) == 4) {
    return 1;
  }
  return 0;
}

