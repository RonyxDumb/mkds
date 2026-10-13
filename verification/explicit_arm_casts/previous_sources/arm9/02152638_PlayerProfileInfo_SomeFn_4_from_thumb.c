/* Decompiled C draft; module arm9; ROM address 02152638. No matching claim. */
#include "types.h"
#include "deps/02152638_PlayerProfileInfo_SomeFn_4_from_thumb.h"

undefined4 PlayerProfileInfo_SomeFn_4_from_thumb(int param_1)

{
  int iVar1;
  longlong lVar2;
  int local_20;
  undefined4 local_1c;
  int local_10;
  
  iVar1 = FriendCode_GetState_from_thumb(param_1 + 0x10);
  if (iVar1 == 0) {
    return 1;
  }
  StructDW_SomeFn_GetSomething_from_thumb(&local_20);
  if (local_10 == 0) {
    return 0;
  }
  lVar2 = FriendCode_GetSomePackedValue_from_thumb(param_1 + 0x10);
  if (lVar2 == CONCAT44(local_1c,local_20)) {
    return 1;
  }
  return 0;
}

