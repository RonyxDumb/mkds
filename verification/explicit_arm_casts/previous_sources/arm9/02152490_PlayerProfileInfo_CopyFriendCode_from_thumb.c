/* Decompiled C draft; module arm9; ROM address 02152490. No matching claim. */
#include "types.h"
#include "deps/02152490_PlayerProfileInfo_CopyFriendCode_from_thumb.h"

void PlayerProfileInfo_CopyFriendCode_from_thumb(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  Mem_CpuFill8(param_2,0,0xc);
  iVar1 = PlayerProfileInfo_FriendCode2_HasState1_from_thumb(param_1);
  if (iVar1 != 0) {
    FriendCode_SetProfileId_from_thumb(param_2,*(undefined4 *)(param_1 + 0x1c));
    FriendCode_SetState_from_thumb(param_2,3);
    return;
  }
  uVar2 = *(undefined4 *)(param_1 + 8);
  *param_2 = *(undefined4 *)(param_1 + 4);
  param_2[1] = uVar2;
  param_2[2] = *(undefined4 *)(param_1 + 0xc);
  return;
}

