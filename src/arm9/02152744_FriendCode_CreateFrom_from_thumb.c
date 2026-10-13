/* Decompiled C draft; module arm9; ROM address 02152744. No matching claim. */
#include "types.h"
#include "deps/02152744_FriendCode_CreateFrom_from_thumb.h"

void FriendCode_CreateFrom_from_thumb(undefined4 param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  
  uVar1 = Os_GetTick();
  StructDW_SomeFn_GetSomething_from_thumb(&local_28);
  if (local_18 == 0) {
    FriendCode_SetProfileIdAndFlags_from_thumb(param_1,local_20,local_1c);
  }
  else {
    FriendCode_SetProfileIdAndFlags_from_thumb(param_1,local_28,local_24);
  }
  lVar2 = Multiply64((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),uRam021527a0,uRam021527a4);
  FriendCode_SetCrcChecksum_from_thumb
            (param_1,(int)(lVar2 + (ulonglong)uRam021527a8 >> 0x20),
             (int)(lVar2 + (ulonglong)uRam021527a8));
  FriendCode_SetState_from_thumb(param_1,1);
  return;
}

