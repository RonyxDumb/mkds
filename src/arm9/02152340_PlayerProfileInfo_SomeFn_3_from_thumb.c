/* Decompiled C draft; module arm9; ROM address 02152340. No matching claim. */
#include "types.h"
#include "deps/02152340_PlayerProfileInfo_SomeFn_3_from_thumb.h"

void PlayerProfileInfo_SomeFn_3_from_thumb(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_30 [13];
  undefined1 auStack_23 [23];
  
  iVar1 = FriendCode_GetState_from_thumb(param_2);
  if (iVar1 != 3) {
    iVar1 = FriendCode_GetState_from_thumb(param_2);
    if (iVar1 == 2) {
      uVar2 = FriendCode_GetFriendCodePacked_from_thumb(param_2);
      PrintfUll_from_thumb((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(undefined4)(uintptr_t)(auStack_30));
      return;
    }
    iVar1 = FriendCode_GetState_from_thumb(param_2);
    if (iVar1 == 1) {
      FriendCode_SomeFn_7_from_thumb(param_2,*(undefined4 *)(param_1 + 0x24),(undefined4)(uintptr_t)(auStack_23));
    }
  }
  return;
}

