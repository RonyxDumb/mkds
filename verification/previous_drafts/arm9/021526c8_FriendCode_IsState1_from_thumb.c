/* Decompiled C draft; module arm9; ROM address 021526c8. No matching claim. */
#include "types.h"
#include "deps/021526c8_FriendCode_IsState1_from_thumb.h"

undefined4 FriendCode_IsState1_from_thumb(void)

{
  int iVar1;
  
  iVar1 = FriendCode_GetState_from_thumb();
  if (iVar1 == 1) {
    return 1;
  }
  return 0;
}

