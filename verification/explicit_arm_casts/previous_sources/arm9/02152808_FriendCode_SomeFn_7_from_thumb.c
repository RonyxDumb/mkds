/* Decompiled C draft; module arm9; ROM address 02152808. No matching claim. */
#include "types.h"
#include "deps/02152808_FriendCode_SomeFn_7_from_thumb.h"

void FriendCode_SomeFn_7_from_thumb(undefined4 param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined1 auStack_3c [21];
  undefined1 auStack_27 [23];
  
  uVar2 = FriendCode_GetSomePackedValue_from_thumb();
  func_0215286c((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0x2b,auStack_3c);
  uVar1 = FriendCode_GetCrcChecksum_from_thumb(param_1);
  func_0215286c(uVar1,0,0x20,auStack_27);
  Util_SNPrintF(param_3,0x15,uRam02152868,auStack_3c,param_2 >> 0x18,param_2 >> 0x10 & 0xff,
                param_2 >> 8 & 0xff,param_2 & 0xff,auStack_27);
  return;
}

