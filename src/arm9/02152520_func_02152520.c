/* Decompiled C draft; module arm9; ROM address 02152520. No matching claim. */
#include "types.h"
#include "deps/02152520_func_02152520.h"

undefined4 func_02152520(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  iVar1 = FriendCode_GetState_from_thumb(param_2);
  if (iVar1 == 1) {
    return 0xffffffff;
  }
  if (iVar1 != 2) {
    if (iVar1 != 3) {
      return 0;
    }
    uVar2 = FriendCode_GetProfileId_from_thumb(param_2);
    return uVar2;
  }
  uVar3 = FriendCode_GetFriendCodePacked_from_thumb(param_2);
  uVar2 = (undefined4)((ulonglong)uVar3 >> 0x20);
  iVar1 = Friend_VerifyChecksum_from_thumb((int)uVar3,uVar2,*(undefined4 *)(param_1 + 0x24));
  if (iVar1 != 0) {
    uVar2 = func_02152934((int)uVar3,uVar2,*(undefined4 *)(param_1 + 0x24));
    return uVar2;
  }
  return 0;
}

