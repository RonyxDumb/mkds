/* Decompiled C draft; module arm9; ROM address 02060cb4. No matching claim. */
#include "types.h"
#include "deps/02060cb4_func_02060cb4.h"

void func_02060cb4(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined1 auStack_18 [16];
  
  uVar3 = ConvertFriendCodeTo64_from_thumb();
  FriendCode_SetProfileIdAndChecksum_from_thumb
            (auStack_18,(int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
  uVar2 = (*(uint *)(uRam02060d14 & 0xfffffffc) >> (uRam02060d14 & 3) * 8 |
          *(uint *)(uRam02060d14 & 0xfffffffc) << (uRam02060d14 & 3) * -8 + 0x20) + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  func_02060d1c((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + iRam02060d18,param_2,auStack_18,
                1,0,1);
  return;
}

