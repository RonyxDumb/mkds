/* Decompiled C draft; module arm9; ROM address 02152390. No matching claim. */
#include "types.h"
#include "deps/02152390_FriendCode_SameAs_from_thumb.h"

undefined4 FriendCode_SameAs_from_thumb(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  
  iVar1 = FriendCode_GetState_from_thumb();
  iVar2 = FriendCode_GetState_from_thumb(param_2);
  if (iVar1 != iVar2) {
    return 0;
  }
  if (iVar1 == 3) {
    iVar1 = FriendCode_GetProfileId_from_thumb(param_1);
    iVar2 = FriendCode_GetProfileId_from_thumb(param_2);
    if (iVar1 == iVar2) {
      return 1;
    }
    return 0;
  }
  if (iVar1 == 1) {
    lVar3 = FriendCode_GetSomePackedValue_from_thumb((uint *)(uintptr_t)(param_1));
    lVar4 = FriendCode_GetSomePackedValue_from_thumb((uint *)(uintptr_t)(param_2));
    if (lVar3 == lVar4) {
      iVar1 = FriendCode_GetCrcChecksum_from_thumb(param_1);
      iVar2 = FriendCode_GetCrcChecksum_from_thumb(param_2);
      if (iVar1 == iVar2) {
        return 1;
      }
    }
    return 0;
  }
  if (iVar1 != 2) {
    return 0;
  }
  lVar3 = FriendCode_GetFriendCodePacked_from_thumb(param_1);
  lVar4 = FriendCode_GetFriendCodePacked_from_thumb(param_2);
  if (lVar3 == lVar4) {
    return 1;
  }
  return 0;
}

